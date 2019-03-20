#include "trigger.h"

void CoreUtil::trigger::process()
{

    HLT_DoubleMu_2017 = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v");
    HLT_DoubleEl_2017 = passHLTTriggerPattern("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
    HLT_MuEG_2017     = passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v") || passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");

    HLT_DoubleMu_2018 = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");
    HLT_DoubleEl_2018 = passHLTTriggerPattern("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
    HLT_MuEG_2018     = passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v") || passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");

//    HLT_DoubleMu = (passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") ||
//                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") ||
//                    passHLTTriggerPattern("HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") ||
//                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v") ||
//                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"));

    HLT_DoubleMu = (passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") ||
                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") ||
                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v") ||
                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"));

//    HLT_MuEG = (passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v") ||
//                passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v") ||
//                passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v") ||
//                passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v") ||
//                passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v") ||
//                passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v") ||
//                passHLTTriggerPattern("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v") ||
//                passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_v") ||
//                passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"));

    HLT_MuEG = (passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v") ||
                passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v") ||
                passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v") ||
                passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_v"));

    HLT_DoubleEl = (passHLTTriggerPattern("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v") ||
                    passHLTTriggerPattern("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v")); // prescaled - turned off

    HLT_DoubleEl_DZ = passHLTTriggerPattern("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"); // prescaled

    HLT_DoubleEl_DZ_2 = passHLTTriggerPattern("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");  // new

    setHLTBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v" ,  true, HLT_SingleIsoEl8 );
    setHLTBranch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v",  true, HLT_SingleIsoEl17 );
    setHLTBranch("HLT_Ele23_CaloIdM_TrackIdM_PFJet30_v",  true, HLT_SingleIsoEl23 );
    setHLTBranch("HLT_Mu8_TrkIsoVVL_v",  true, HLT_SingleIsoMu8 );
    setHLTBranch("HLT_Mu17_TrkIsoVVL_v",  true, HLT_SingleIsoMu17 );

    setHLTBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v" ,  true, HLT_SingleEl8_2017 );
    setHLTBranch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v",  true, HLT_SingleEl17_2017 );
    setHLTBranch("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v" ,  true, HLT_SingleIsoEl8_2017 );
    setHLTBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  true, HLT_SingleIsoEl23_2017 );
    setHLTBranch("HLT_Mu8_TrkIsoVVL_v",  true, HLT_SingleIsoMu8_2017 );
    setHLTBranch("HLT_Mu17_TrkIsoVVL_v",  true, HLT_SingleIsoMu17_2017 );

    // TODO for fake rate baby for 2018
    setHLTBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v" ,  true, HLT_SingleEl8_2018 );
    setHLTBranch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v",  true, HLT_SingleEl17_2018 );
    setHLTBranch("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v" ,  true, HLT_SingleIsoEl8_2018 );
    setHLTBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  true, HLT_SingleIsoEl23_2018 );
    setHLTBranch("HLT_Mu8_TrkIsoVVL_v",  true, HLT_SingleIsoMu8_2018 );
    setHLTBranch("HLT_Mu17_TrkIsoVVL_v",  true, HLT_SingleIsoMu17_2018 );

    // https://github.com/cmstas/FTAnalysis/blob/run2/analysis/fakes/derivation/ScanChain_fast.C#L831-L840
    // //trigger selection
    // if (abs(id())==11) {
    //     if (useIsoTrigs) {
    //         if (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30()<=0 && HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30()<=0) continue;
    //     } else {
    //         if (HLT_Ele8_CaloIdM_TrackIdM_PFJet30()<=0 && HLT_Ele17_CaloIdM_TrackIdM_PFJet30()<=0) continue;
    //     }
    // }
    // if (abs(id())==13) {
    //     if (useIsoTrigs) {
    //         if (HLT_Mu8_TrkIsoVVL()<=0 && HLT_Mu17_TrkIsoVVL()<=0) continue;
    //     } else {
    //         if (HLT_Mu8()<=0 && HLT_Mu17()<=0) continue;
    //     }
    // }

    HLT_PFMET140_PFMHT140_IDTight = passHLTTriggerPattern("HLT_PFMET140_PFMHT140_IDTight_v");
}
