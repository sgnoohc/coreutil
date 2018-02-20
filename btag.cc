#include "btag.h"

void CoreUtil::btag::setup(bool fastsim)
{
    // setup btag calibration readers
    calib           = new BTagCalibration("csvv2", "btagsf/CSVv2_Moriond17_B_H.csv"); // Moriond17 version of SFs
    reader_heavy    = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "comb", "central"); // central
    reader_heavy_UP = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "comb", "up");      // sys up
    reader_heavy_DN = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "comb", "down");    // sys down
    reader_light    = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "incl", "central"); // central
    reader_light_UP = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "incl", "up");      // sys up
    reader_light_DN = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "incl", "down");    // sys down
    // get btag efficiencies
    TFile * f_btag_eff           = new TFile("btagsf/btageff__ttbar_powheg_pythia8_25ns_Moriond17.root");
    TH2D  * h_btag_eff_b_temp    = (TH2D*) f_btag_eff->Get("h2_BTaggingEff_csv_loose_Eff_b");
    TH2D  * h_btag_eff_c_temp    = (TH2D*) f_btag_eff->Get("h2_BTaggingEff_csv_loose_Eff_c");
    TH2D  * h_btag_eff_udsg_temp = (TH2D*) f_btag_eff->Get("h2_BTaggingEff_csv_loose_Eff_udsg");
    h_btag_eff_b    = (TH2D*) h_btag_eff_b_temp    -> Clone("h_btag_eff_b");
    h_btag_eff_c    = (TH2D*) h_btag_eff_c_temp    -> Clone("h_btag_eff_c");
    h_btag_eff_udsg = (TH2D*) h_btag_eff_udsg_temp -> Clone("h_btag_eff_udsg");
    std::cout << "loaded fullsim btag SFs" << std::endl;
    // extra copy for fastsim -> fullsim SFs
    if (fastsim)
    {
        // setup btag calibration readers
        calib_fastsim     = new BTagCalibration("CSV", "btagsf/fastsim_csvv2_ttbar_26_1_2017.csv"); // Moriond 17 25ns fastsim version of SFs
        reader_fastsim    = new BTagCalibrationReader(calib_fastsim, BTagEntry::OP_LOOSE, "fastsim", "central"); // central
        reader_fastsim_UP = new BTagCalibrationReader(calib_fastsim, BTagEntry::OP_LOOSE, "fastsim", "up");      // sys up
        reader_fastsim_DN = new BTagCalibrationReader(calib_fastsim, BTagEntry::OP_LOOSE, "fastsim", "down");    // sys down
        // get btag efficiencies
        TFile * f_btag_eff_fastsim           = new TFile("btagsf/btageff__SMS-T1bbbb-T1qqqq_25ns_Moriond17.root");
        TH2D  * h_btag_eff_b_fastsim_temp    = (TH2D*) f_btag_eff_fastsim->Get("h2_BTaggingEff_csv_loose_Eff_b");
        TH2D  * h_btag_eff_c_fastsim_temp    = (TH2D*) f_btag_eff_fastsim->Get("h2_BTaggingEff_csv_loose_Eff_c");
        TH2D  * h_btag_eff_udsg_fastsim_temp = (TH2D*) f_btag_eff_fastsim->Get("h2_BTaggingEff_csv_loose_Eff_udsg");
        h_btag_eff_b_fastsim    = (TH2D*) h_btag_eff_b_fastsim_temp    -> Clone("h_btag_eff_b_fastsim");
        h_btag_eff_c_fastsim    = (TH2D*) h_btag_eff_c_fastsim_temp    -> Clone("h_btag_eff_c_fastsim");
        h_btag_eff_udsg_fastsim = (TH2D*) h_btag_eff_udsg_fastsim_temp -> Clone("h_btag_eff_udsg_fastsim");
        std::cout << "loaded fastsim btag SFs" << std::endl;
    } // if (isFastsim)
}
