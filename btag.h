#ifndef btag_h
#define btag_h

#include "Tools/btagsf/BTagCalibrationStandalone.h"

#include "CMS3.h"

#include "TH2.h"
#include "TFile.h"
#include "TSystem.h"

#include <iostream>

#define JET_PT_MIN 20
#define JET_ETA_MAX 5

#define BJET_PT_MIN 20
#define BJET_ETA_MAX 2.4

#define BJET_CSV_TIGHT 0.9535
#define BJET_CSV_MED 0.8484
#define BJET_CSV_LOOSE 0.5426

class BTagCalibration;
class BTagCalibrationReader;

namespace CoreUtil
{
    class btag
    {
        public:
            // for btag SFs
            BTagCalibration* calib;
            BTagCalibrationReader* reader_fullsim;
            BTagCalibrationReader* reader_heavy;
            BTagCalibrationReader* reader_heavy_UP;
            BTagCalibrationReader* reader_heavy_DN;
            BTagCalibrationReader* reader_light;
            BTagCalibrationReader* reader_light_UP;
            BTagCalibrationReader* reader_light_DN;


            BTagCalibration* calib_fastsim;
            BTagCalibrationReader* reader_fastsim;
            BTagCalibrationReader* reader_fastsim_UP;
            BTagCalibrationReader* reader_fastsim_DN;

            BTagCalibrationReader* reader_medium;
            BTagCalibrationReader* reader_loose;
            BTagCalibrationReader* reader_tight;
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

            TH2D* h_btag_eff_b_fastsim;
            TH2D* h_btag_eff_c_fastsim;
            TH2D* h_btag_eff_udsg_fastsim;

            float btagprob_data;
            float btagprob_heavy_UP;
            float btagprob_heavy_DN;
            float btagprob_light_UP;
            float btagprob_light_DN;
            float btagprob_mc;

            bool isfastsim;
            bool isdeepcsv;
            int year;

            btag(bool fsim=false, bool isdpcsv=false, int yr=2016) { setup(fsim, isdpcsv, yr); }
            ~btag() {}
            void setup(bool=false, bool=false, int=2016);
            void clearSF();
            void accumulateSF(int iJet, float pt, float eta);
            void accumulateSF2016CSVv2(int iJet, float pt, float eta);
            void accumulateSFDeepRun2(int iJet, float pt, float eta);
            float getBtagEffFromFile(float pt, float eta, int mcFlavour, bool isFastsim);

    };
}


#endif
