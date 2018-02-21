#ifndef met_h
#define met_h

#include <vector>
#include <iostream>

#include "MetSelections.h"
#include "Base.h"
#include "jec.h"

using namespace std;

namespace CoreUtil
{
    class met
    {

        public:

            float met_pt;
            float met_phi;

            float met_up_pt;
            float met_up_phi;

            float met_dn_pt;
            float met_dn_phi;

            met() {}
            ~met() {}

            void process(jec&);
    };
}

#endif
