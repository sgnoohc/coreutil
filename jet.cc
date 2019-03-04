#include "jet.h"

//########################################################################################
void CoreUtil::jet::process(jec& jec_)
{
    process(jec_, nullptr);
}

//########################################################################################
void CoreUtil::jet::process(jec& jec_, jer& jer_)
{
    process(jec_, &jer_);
}

//########################################################################################
void CoreUtil::jet::process(jec& jec_, jer* jer_)
{
    index.clear();
    corrs.clear();
    shifts.clear();
    smears.clear();
    smears_up.clear();
    smears_dn.clear();

    for (unsigned int iJet = 0; iJet < cms3.pfjets_p4().size(); iJet++)
    {
        // note this uses the eta of the jet as stored in CMS3
        //  chance for small discrepancies if JEC changes direction slightly..
//        if (!isLoosePFJet_Summer16_v1(iJet)) { continue; }

        // get uncorrected jet p4 to use as input for corrections
        LorentzVector pfjet_p4_uncor = cms3.pfjets_p4()[iJet] * cms3.pfjets_undoJEC()[iJet];

        //=====================
        // JEC
        //=====================

        // Configure the JEC based on pt/eta/pileup
        jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run())->setRho(cms3.evt_fixgridfastjet_all_rho());
        jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run())->setJetA(cms3.pfjets_area()[iJet]);
        jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run())->setJetPt(pfjet_p4_uncor.pt());
        jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run())->setJetEta(pfjet_p4_uncor.eta());

        //get actual corrections
        vector<float> corr_vals = jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run())->getSubCorrections();
        double corr = corr_vals.at(corr_vals.size() - 1); // All corrections

        // Configure the JEC Uncertainty based on pt/eta
        jec_.getJECUnc(cms3.evt_isRealData(), cms3.evt_run())->setJetEta(pfjet_p4_uncor.eta());
        jec_.getJECUnc(cms3.evt_isRealData(), cms3.evt_run())->setJetPt(pfjet_p4_uncor.pt()*corr);

        double shift = 0.0;
        double unc = jec_.getJECUnc(cms3.evt_isRealData(), cms3.evt_run())->getUncertainty(true);

        // note that this always checks the "default" filename vector size, not the run-dependent for late 2016F
        if (cms3.evt_isRealData() && jec_.jetcorr_filenames_pfL1FastJetL2L3.size() == 4)
        {
            shift = sqrt(unc * unc + pow((corr_vals.at(corr_vals.size() - 1) / corr_vals.at(corr_vals.size() - 2) - 1.), 2));
        }
        else
        {
            shift = unc;
        }

        index.push_back(iJet);
        corrs.push_back(corr);
        shifts.push_back(shift);

        //=====================
        // JER
        //=====================
        if (jer_ and not cms3.evt_isRealData())
        {

            // Gen Jet Pt
            vector<Double_t> GenJetPt;
            for (auto& genjet : cms3.genjets_p4NoMuNoNu()) { GenJetPt.push_back(genjet.pt()); }

            jer_->res.resetSeed(cms3.evt_event());
            jer_->res.loadVariable("JetEta", cms3.pfjets_p4().at(iJet).eta());
            jer_->res.loadVariable("Rho", cms3.evt_fixgridfastjet_all_rho());
            jer_->res.loadVariable("JetPt", cms3.pfjets_p4().at(iJet).pt()); // should be the corrected energy. Not taken into account here.

            auto smearing = jer_->res.smear(cms3.pfjets_p4().at(iJet), cms3.genjets_p4NoMuNoNu(), GenJetPt, 0);
            auto smearing_up = jer_->res.smear(cms3.pfjets_p4().at(iJet), cms3.genjets_p4NoMuNoNu(), GenJetPt, 1);
            auto smearing_dn = jer_->res.smear(cms3.pfjets_p4().at(iJet), cms3.genjets_p4NoMuNoNu(), GenJetPt,-1);
            auto matching = jer_->res.match();

            // The returned smearing is a vector since if matched it has 2 elements
            smears.push_back(smearing[0] / cms3.pfjets_p4().at(iJet).pt());
            smears_up.push_back(smearing_up[0] / cms3.pfjets_p4().at(iJet).pt());
            smears_dn.push_back(smearing_dn[0] / cms3.pfjets_p4().at(iJet).pt());
        }
        else if (jer_ and cms3.evt_isRealData())
        {
            smears.push_back(1);
            smears_up.push_back(1);
            smears_dn.push_back(1);
        }
    }
}
