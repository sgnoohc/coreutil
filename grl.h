#ifndef grl_h
#define grl_h

#include <iostream>

#include "Tools/goodrun.h"

using namespace std;

namespace CoreUtil
{
    class grl
    {
        public:
            const char* json_file;
            grl() { setup(); }
            ~grl() {}
            void setup();
            void process();
    };
}

#endif
