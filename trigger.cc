#include "trigger.h"

void CoreUtil::trigger::process()
{

//    HLT_DoubleMu = (passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") ||
//                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") ||
//                    passHLTTriggerPattern("HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") ||
//                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v") ||
//                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"));

    HLT_DoubleMu = (passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") ||
                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") ||
                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v") ||
                    passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"));

    HLT_DoubleMu_2017 = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v");

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

    HLT_SingleIsoEl8 = passHLTTriggerPattern("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v");
    HLT_SingleIsoEl17 = passHLTTriggerPattern("HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v");
    HLT_SingleIsoMu8 = passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_v");
    HLT_SingleIsoMu17 = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_v");
}
