#ifndef puwgt_h
#define puwgt_h

#include "TH1.h"
#include "TFile.h"

namespace CoreUtil
{
    class puwgt
    {
        public:
            TH1F* h_vtxweight;
            TFile* f_vtx;
            puwgt() { setup(); }
            ~puwgt() {}
            void setup();
            float getPUWgt(int nTrueInt);
    };
}

#endif
