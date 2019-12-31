#ifndef trigger_h
#define trigger_h

#include "TriggerSelections.h"

namespace CoreUtil
{
    class trigger
    {

        public:
            enum triggerSet
            {
                kAll = 0,
                kDilepton,
                kSinglelepton,
                kMET,
                kOneLep,
            };
            bool HLT_DoubleMu;
            bool HLT_DoubleMu_2017;
            bool HLT_DoubleMu_2018;
            bool HLT_MuEG;
            bool HLT_MuEG_2017;
            bool HLT_MuEG_2018;
            bool HLT_DoubleEl;
            bool HLT_DoubleEl_DZ;
            bool HLT_DoubleEl_DZ_2;
            bool HLT_DoubleEl_2017;
            bool HLT_DoubleEl_2018;
            int HLT_SingleEl8;
            int HLT_SingleEl17;
            int HLT_SingleIsoEl8;
            int HLT_SingleIsoEl12;
            int HLT_SingleIsoEl17;
            int HLT_SingleIsoEl23;
            int HLT_SingleIsoMu8;
            int HLT_SingleIsoMu17;
            int HLT_SingleEl8_2017;
            int HLT_SingleEl17_2017;
            int HLT_SingleIsoEl8_2017;
            int HLT_SingleIsoEl12_2017;
            int HLT_SingleIsoEl23_2017;
            int HLT_SingleIsoMu8_2017;
            int HLT_SingleIsoMu17_2017;
            int HLT_SingleEl8_2018;
            int HLT_SingleEl17_2018;
            int HLT_SingleIsoEl8_2018;
            int HLT_SingleIsoEl12_2018;
            int HLT_SingleIsoEl23_2018;
            int HLT_SingleIsoMu8_2018;
            int HLT_SingleIsoMu17_2018;
            bool HLT_PFMET140_PFMHT140_IDTight;

	    // For one lepton
	    // 2016 
	    int HLT_IsoMu24; 
	    int HLT_IsoTkMu24; 
	    int HLT_Mu50; 
	    int HLT_TkMu50; 
	    int HLT_Ele27_WPTight_Gsf; 
	    int HLT_Ele115_CaloIdVT_GsfTrkIdT;
	    int HLT_Photon175;

	    // 2017 - also needs
	    int HLT_IsoMu27; 
	    int HLT_OldMu100; 
	    int HLT_TkMu100; 
	    int HLT_Ele32_WPTight_Gsf;
	    int HLT_Ele35_WPTight_Gsf; 
	    int HLT_Ele32_WPTight_Gsf_L1DoubleEG; 
	    int HLT_Photon200;
	
	    // 2018 - also needs
	    int HLT_Ele28_WPTight_Gsf; 
	    int HLT_Ele38_WPTight_Gsf;
	    int HLT_Ele40_WPTight_Gsf; 
	    bool HLT_SingleMu2016;
	    bool HLT_SingleMu2017;
	    bool HLT_SingleMu2018;
	    bool HLT_SingleEl2016;
	    bool HLT_SingleEl2017;
	    bool HLT_SingleEl2018;
	    bool HLT_SingleMu;
	    bool HLT_SingleEl;


            trigger() {}
            ~trigger() {}

            void process(triggerSet=kAll);

    };
}

#endif
