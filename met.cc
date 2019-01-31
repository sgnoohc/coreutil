#include "met.h"

//########################################################################################
void CoreUtil::met::process(jec& jec_)
{
    process(jec_, nullptr);
}

//########################################################################################
void CoreUtil::met::process(jec& jec_, jer& jer_)
{
    process(jec_, &jer_);
}

//########################################################################################
void CoreUtil::met::process(jec& jec_, jer* jer_)
{
    // met with no unc
    pair <float, float> met_T1CHS_miniAOD_CORE_p2 = getT1CHSMET_fromMINIAOD(jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run()));
    met_pt  = met_T1CHS_miniAOD_CORE_p2.first;
    met_phi = met_T1CHS_miniAOD_CORE_p2.second;

    // up variation
    pair <float, float> met_T1CHS_miniAOD_CORE_up_p2 = getT1CHSMET_fromMINIAOD(jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run()), jec_.getJECUnc(cms3.evt_isRealData(), cms3.evt_run()), 1);
    met_up_pt  = met_T1CHS_miniAOD_CORE_up_p2.first;
    met_up_phi = met_T1CHS_miniAOD_CORE_up_p2.second;

    // dn variation
    pair <float, float> met_T1CHS_miniAOD_CORE_dn_p2 = getT1CHSMET_fromMINIAOD(jec_.getJEC(cms3.evt_isRealData(), cms3.evt_run()), jec_.getJECUnc(cms3.evt_isRealData(), cms3.evt_run()), 0);
    met_dn_pt  = met_T1CHS_miniAOD_CORE_dn_p2.first;
    met_dn_phi = met_T1CHS_miniAOD_CORE_dn_p2.second;

    //============
    // JER
    //============

    if (jer_ and not cms3.evt_isRealData())
    {

        vector <Double_t> GenJetPt;
        jer_->res.resetSeed(cms3.evt_event()); // reset seed for JER smearing
        jer_->res.loadVariable("Rho", cms3.evt_fixgridfastjet_all_rho());
        for (auto& genjet : cms3.genjets_p4NoMuNoNu()) { GenJetPt.push_back(genjet.pt()); }

        LorentzVector jetp4_jer(0,0,0,0);
        LorentzVector jetp4_jerup(0,0,0,0);
        LorentzVector jetp4_jerdn(0,0,0,0);
        for(unsigned int iJet = 0; iJet < cms3.pfjets_p4().size(); iJet++)
        {
            jer_->res.loadVariable("JetEta", cms3.pfjets_p4().at(iJet).eta());
            jer_->res.loadVariable("JetPt", cms3.pfjets_p4().at(iJet).pt());
            auto smearing = jer_->res.smear(cms3.pfjets_p4().at(iJet), cms3.genjets_p4NoMuNoNu(), GenJetPt, 0);
            float ptJER = smearing[0]; // these are the actual pTs, not scale factors
            float ptJERup = smearing[0]; // these are the actual pTs, not scale factors
            float ptJERdn = smearing[0]; // these are the actual pTs, not scale factors
            float JER = ptJER/cms3.pfjets_p4().at(iJet).pt();
            float JERup = ptJER/cms3.pfjets_p4().at(iJet).pt();
            float JERdn = ptJER/cms3.pfjets_p4().at(iJet).pt();
            jetp4_jer += cms3.pfjets_p4().at(iJet) * (1.-JER);
            jetp4_jerup += cms3.pfjets_p4().at(iJet) * (1.-JERup);
            jetp4_jerdn += cms3.pfjets_p4().at(iJet) * (1.-JERdn);
        }

        float metx = met_pt*cos(met_phi);
        float mety = met_pt*sin(met_phi);
        float metx_jer = metx + jetp4_jer.px();
        float mety_jer = mety + jetp4_jer.py();
        float metx_jerup = metx + jetp4_jerup.px();
        float mety_jerup = mety + jetp4_jerup.py();
        float metx_jerdn = metx + jetp4_jerdn.px();
        float mety_jerdn = mety + jetp4_jerdn.py();
        met_jer_pt = sqrt(metx_jer*metx_jer+mety_jer*mety_jer);
        met_jer_phi = atan2(mety_jer,metx_jer);
        met_jerup_pt = sqrt(metx_jerup*metx_jerup+mety_jerup*mety_jerup);
        met_jerup_phi = atan2(mety_jerup,metx_jerup);
        met_jerdn_pt = sqrt(metx_jerdn*metx_jerdn+mety_jerdn*mety_jerdn);
        met_jerdn_phi = atan2(mety_jerdn,metx_jerdn);

    }
    else if (jer_ and cms3.evt_isRealData())
    {
        met_jer_pt = met_pt;
        met_jer_phi = met_phi;
        met_jerup_pt = met_pt;
        met_jerup_phi = met_phi;
        met_jerdn_pt = met_pt;
        met_jerdn_phi = met_phi;
    }
}
