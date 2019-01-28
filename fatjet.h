#ifndef fatjet_h
#define fatjet_h


#include <vector>
#include <iostream>

#include "Base.h"
#include "jec.h"
#include "jer.h"
#include "JetSelections.h"

namespace CoreUtil
{
    class fatjet
    {

        public:

            std::vector<int> index;
            std::vector<float> corrs;
            std::vector<float> shifts;
            std::vector<float> smears;
            std::vector<float> smears_up;
            std::vector<float> smears_dn;

            bool isJERwarningPrinted;

            fatjet() { isJERwarningPrinted = false;}
            ~fatjet() {}

            void process(jec&);
            void process(jec&, jer&);
            void process(jec&, jer*);

            void printJERWarning();

    };
}

#endif
