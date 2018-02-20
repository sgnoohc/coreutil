#ifndef trigger_h
#define trigger_h

#include "TriggerSelections.h"

namespace CoreUtil
{
    class trigger
    {

        public:
            bool HLT_DoubleMu;
            bool HLT_MuEG;
            bool HLT_DoubleEl;
            bool HLT_DoubleEl_DZ;
            bool HLT_DoubleEl_DZ_2;

            trigger() {}
            ~trigger() {}

            void process();

    };
}

#endif
