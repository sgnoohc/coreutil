#ifndef btagdeepcsv_H
#define btagdeepcsv_H

// SNT CORE
#include "Tools/btagsf/BTagCalibrationStandalone.h"

// ROOT
#include "TFile.h"
#include "TH2.h"
#include "TSystem.h"

// C++
#include <string>
#include <vector>

//
// CLASS
//

class BTagCalibration;
class BTagCalibrationReader;

namespace CoreUtil
{

    class btagdeepcsv
    {

        public:

            // Sample info 
            bool sampleIsFastsim;

            // bTag SF machinery
            float BTAG_LSE;
            float BTAG_MED;
            float BTAG_TGT;

            BTagCalibration* calib;
            BTagCalibrationReader* reader_medium;
            BTagCalibrationReader* reader_loose;
            BTagCalibrationReader* reader_tight;
            BTagCalibration* calib_fastsim;
            BTagCalibrationReader* reader_medium_FS;
            BTagCalibrationReader* reader_loose_FS;
            BTagCalibrationReader* reader_tight_FS;
            TFile *feff;
            TH2D* h_btag_eff_b;
            TH2D* h_btag_eff_c;
            TH2D* h_btag_eff_udsg;
            TH2D* h_loose_btag_eff_b;
            TH2D* h_loose_btag_eff_c;
            TH2D* h_loose_btag_eff_udsg;
            TH2D* h_tight_btag_eff_b;
            TH2D* h_tight_btag_eff_c;
            TH2D* h_tight_btag_eff_udsg;


            btagdeepcsv();
            ~btagdeepcsv();

            void setup( bool isFastsim, int year, std::string fn_btagSF = "", std::string fn_btagSF_FS = "" );
            void getBTagWeight( int WP, std::vector< double > jet_pt, std::vector< double > jet_eta, std::vector< double > jet_CSV, std::vector< int > jet_flavour, double &weight_btagsf, double &weight_btagsf_heavy_UP, double &weight_btagsf_heavy_DN, double &weight_btagsf_light_UP, double &weight_btagsf_light_DN, double &weight_btagsf_fastsim_UP, double &weight_btagsf_fastsim_DN );

    }; // end class def
}

#endif
