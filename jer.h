#ifndef jer_h
#define jer_h

#include "Tools/JetResolution/JetResolution.h"

namespace CoreUtil
{
    class jer
    {
        public:

            JetResolution res;

            jer();
            ~jer();

            void setJERFor(int year);
    };
}

#endif
