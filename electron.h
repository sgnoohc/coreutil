#ifndef electron_h
#define electron_h

#include <vector>
#include <iostream>
#include <functional>

#include "IsolationTools.h"
#include "ElectronSelections.h"
#include "VVVSelections.h"
#include "Base.h"

using namespace std;

namespace CoreUtil
{
    class electron
    {

        public:

            std::vector<int> index;
            std::vector<int> tagindex;

            electron() { setup(); }
            ~electron() {}

            void setup();
            void process(std::function<bool(int)> pass, std::function<bool(int, int)> tagpass=nullptr);

    };
}

#endif
