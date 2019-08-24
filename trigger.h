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

            trigger() {}
            ~trigger() {}

            void process(triggerSet=kAll);

    };
}

#endif
