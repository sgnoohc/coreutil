#ifndef sample_h
#define sample_h

#include <vector>
#include <string>
#include <iostream>

#include "TString.h"

// C/C++
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdarg.h>
#include <functional>
#include <cmath>


namespace CoreUtil
{
    class sample
    {
        public:

            enum CMS4Type {
                k2016MC,
                k2016Data,
                k2017MC,
                k2017Data,
            };

            sample() {}
            ~sample() {}
            TString nicename(TString filepath);
            CMS4Type CMS4Version(TString filepath);
            bool is2016(TString filepath);
            bool is2017(TString filepath);
            bool is2016Data(TString filepath);
            bool is2017Data(TString filepath);
            bool is2016MC(TString filepath);
            bool is2017MC(TString filepath);
    };
}

#endif
