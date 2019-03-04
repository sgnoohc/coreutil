#ifndef jet_h
#define jet_h

#include <vector>
#include <iostream>

#include "JetSelections.h"
#include "Base.h"
#include "jec.h"
#include "jer.h"

using namespace std;

namespace CoreUtil
{
    class jet
    {

        public:

            std::vector<int> index;
            std::vector<float> corrs;
            std::vector<float> shifts;
            std::vector<float> smears;
            std::vector<float> smears_up;
            std::vector<float> smears_dn;

            jet() {}
            ~jet() {}

            void process(jec&);
            void process(jec&, jer&);
            void process(jec&, jer*);
    };
}

#endif
