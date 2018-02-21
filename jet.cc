#include "jet.h"

//########################################################################################
void CoreUtil::jet::process(jec& jec_)
{
    index.clear();
    corrs.clear();
    shifts.clear();

    for (unsigned int iJet = 0; iJet < cms3.pfjets_p4().size(); iJet++)
    {
        // note this uses the eta of the jet as stored in CMS3
        //  chance for small discrepancies if JEC changes direction slightly..
        if (!isLoosePFJet_Summer16_v1(iJet)) { continue; }

        // get uncorrected jet p4 to use as input for corrections
        LorentzVector pfjet_p4_uncor = cms3.pfjets_p4()[iJet] * cms3.pfjets_undoJEC()[iJet];

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
    }
}
