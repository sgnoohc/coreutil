#ifndef trigger_h
#define trigger_h

#include "TriggerSelections.h"

namespace CoreUtil
{
    class trigger
    {

        public:
            bool HLT_DoubleMu;
            bool HLT_DoubleMu_2017;
            bool HLT_MuEG;
            bool HLT_MuEG_2017;
            bool HLT_DoubleEl;
            bool HLT_DoubleEl_DZ;
            bool HLT_DoubleEl_DZ_2;
            bool HLT_DoubleEl_2017;
            int HLT_SingleIsoEl8;
            int HLT_SingleIsoEl17;
            int HLT_SingleIsoEl23;
            int HLT_SingleIsoMu8;
            int HLT_SingleIsoMu17;

            trigger() {}
            ~trigger() {}

            void process();

    };
}

#endif
