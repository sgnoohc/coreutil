#include "met.h"

//########################################################################################
void CoreUtil::met::process(jec& jec_)
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
}
