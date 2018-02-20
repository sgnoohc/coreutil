#ifndef btag_h
#define btag_h

#include "Tools/btagsf/BTagCalibrationStandalone.h"

#include "TH2.h"
#include "TFile.h"

class BTagCalibration;
class BTagCalibrationReader;

namespace CoreUtil
{
    class btag
    {
        public:
            // for btag SFs
            BTagCalibration* calib;
            BTagCalibrationReader* reader_heavy;
            BTagCalibrationReader* reader_heavy_UP;
            BTagCalibrationReader* reader_heavy_DN;
            BTagCalibrationReader* reader_light;
            BTagCalibrationReader* reader_light_UP;
            BTagCalibrationReader* reader_light_DN;

            TH2D* h_btag_eff_b;
            TH2D* h_btag_eff_c;
            TH2D* h_btag_eff_udsg;

            BTagCalibration* calib_fastsim;
            BTagCalibrationReader* reader_fastsim;
            BTagCalibrationReader* reader_fastsim_UP;
            BTagCalibrationReader* reader_fastsim_DN;

            TH2D* h_btag_eff_b_fastsim;
            TH2D* h_btag_eff_c_fastsim;
            TH2D* h_btag_eff_udsg_fastsim;

            btag(bool fastsim=false) { setup(fastsim); }
            ~btag() {}
            void setup(bool=false);

    };
}


#endif
