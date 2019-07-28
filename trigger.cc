#include "trigger.h"

void CoreUtil::trigger::process(CoreUtil::trigger::triggerSet trigSet)
{

    if (trigSet == kAll or trigSet == kDilepton)
    {

        bool HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v          = passHLTTriggerPattern("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
        bool HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v             = passHLTTriggerPattern("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v");
        bool HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v          = passHLTTriggerPattern("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
        bool HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v             = passHLTTriggerPattern("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
        bool HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v        = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");
        bool HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v          = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v");
        bool HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v                = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
        bool HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v                   = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v");
        bool HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v              = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v");
        bool HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v                 = passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v");
        bool HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v = passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
        bool HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_v  = passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_v");
        bool HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v     = passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v");
        bool HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v  = passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");
        bool HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v     = passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v");

        // =====

        HLT_DoubleMu_2017 = HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v;
        HLT_DoubleEl_2017 = HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;
        HLT_MuEG_2017     = HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v || HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v;

        HLT_DoubleMu_2018 = HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v;
        HLT_DoubleEl_2018 = HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v;
        HLT_MuEG_2018     = HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v || HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v;

        HLT_DoubleMu = HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v ||
            HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v ||
            HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v ||
            HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v;

        HLT_MuEG = HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v ||
            HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v ||
            HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v ||
            HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_v;

        HLT_DoubleEl = HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v ||
            HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v; // prescaled - turned off

        HLT_DoubleEl_DZ = HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v; // prescaled

        HLT_DoubleEl_DZ_2 = HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v;  // new

    }

    if (trigSet == kAll or trigSet == kSinglelepton)
    {

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

        // for fake rate baby for 2018 (cf. 2017 is identical to 2018)
        setHLTBranch("HLT_Ele8_CaloIdM_TrackIdM_PFJet30_v" ,  true, HLT_SingleEl8_2018 );
        setHLTBranch("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v",  true, HLT_SingleEl17_2018 );
        setHLTBranch("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v" ,  true, HLT_SingleIsoEl8_2018 );
        setHLTBranch("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v",  true, HLT_SingleIsoEl23_2018 );
        setHLTBranch("HLT_Mu8_TrkIsoVVL_v",  true, HLT_SingleIsoMu8_2018 );
        setHLTBranch("HLT_Mu17_TrkIsoVVL_v",  true, HLT_SingleIsoMu17_2018 );
    }

    if (trigSet == kMET)
    {
        HLT_PFMET140_PFMHT140_IDTight = passHLTTriggerPattern("HLT_PFMET140_PFMHT140_IDTight_v");
    }

}
