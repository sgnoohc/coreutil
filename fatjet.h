#ifndef fatjet_h
#define fatjet_h


#include <vector>
#include <iostream>

#include "Base.h"
#include "jec.h"
#include "JetSelections.h"

namespace CoreUtil
{
    class fatjet
    {

        public:

            std::vector<int> index;
            std::vector<float> corrs;
            std::vector<float> shifts;

            fatjet() {}
            ~fatjet() {}

            void process(jec&);

    };
}

#endif
