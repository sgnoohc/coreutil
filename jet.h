#ifndef jet_h
#define jet_h

#include <vector>
#include <iostream>

#include "JetSelections.h"
#include "Base.h"
#include "jec.h"

using namespace std;

namespace CoreUtil
{
    class jet
    {

        public:

            std::vector<int> index;
            std::vector<float> corrs;
            std::vector<float> shifts;

            jet() {}
            ~jet() {}

            void process(jec&);
    };
}

#endif
