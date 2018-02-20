#ifndef muon_h
#define muon_h

#include <vector>
#include <iostream>

#include "MuonSelections.h"
#include "VVVSelections.h"
#include "Base.h"

namespace CoreUtil
{
    class muon
    {

        public:

            std::vector<int> index;

            muon() {}
            ~muon() {}

            void setup();
            void process();
            bool pass(int i);

    };
}

#endif
