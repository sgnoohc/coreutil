#ifndef jec_h
#define jec_h

#include <vector>
#include <string>
#include <iostream>

#include "TString.h"

#include "Tools/jetcorr/FactorizedJetCorrector.h"
#include "Tools/JetCorrector.h"
#include "Tools/jetcorr/JetCorrectionUncertainty.h"

namespace CoreUtil
{
    class jec
    {
        public:
            // Nominal correction
            std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
            FactorizedJetCorrector   * jet_corrector_pfL1FastJetL2L3;
            JetCorrectionUncertainty * jecUnc;

            // corrections for later runs in 2016F
            std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3_postrun278802;
            FactorizedJetCorrector   * jet_corrector_pfL1FastJetL2L3_postrun278802;
            JetCorrectionUncertainty * jecUnc_postrun278802;

            TString current_filename;

            jec();
            ~jec();
            void resetObjects();
            FactorizedJetCorrector* getJEC(bool = false, int = -999);
            JetCorrectionUncertainty* getJECUnc(bool = false, int = -999);
            void setJECFor(TString, bool = false);
    };
}

#endif
