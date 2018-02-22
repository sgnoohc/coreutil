#ifndef track_h
#define track_h

#include <vector>
#include <iostream>

#include "CMS3.h"
#include "Base.h"
#include "Math/VectorUtil.h"

using namespace std;

namespace CoreUtil
{
    class track
    {

        public:

            std::vector<int> index;

            track() {}
            ~track() {}

            void process();

            // The following function exists only because as a temporary hack until migrating completely to CMS4
            float TrackIso(int thisPf, float coneR, float deltaZCut, bool useFromPV, bool useLeptons);
    };
}

#endif
