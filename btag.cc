#include "btag.h"

//########################################################################################
void CoreUtil::btag::setup(bool fastsim)
{
    // setup btag calibration readers
    calib           = new BTagCalibration("csvv2", "coreutil/data/btagsf/CSVv2_Moriond17_B_H.csv"); // Moriond17 version of SFs
    reader_fullsim = new BTagCalibrationReader(BTagEntry::OP_LOOSE, "central",{"up","down"});
    reader_fullsim->load(*calib, BTagEntry::JetFlavor::FLAV_B, "comb");
    reader_fullsim->load(*calib, BTagEntry::JetFlavor::FLAV_C, "comb");
    reader_fullsim->load(*calib, BTagEntry::JetFlavor::FLAV_UDSG, "incl");
    // get btag efficiencies
    TFile * f_btag_eff           = new TFile("coreutil/data/btagsf/btageff__ttbar_powheg_pythia8_25ns_Moriond17.root");
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
        calib_fastsim     = new BTagCalibration("CSV", "coreutil/data/btagsf/fastsim_csvv2_ttbar_26_1_2017.csv"); // Moriond 17 25ns fastsim version of SFs
        reader_fastsim = new BTagCalibrationReader(BTagEntry::OP_LOOSE, "central",{"up","down"});
        reader_fastsim->load(*calib_fastsim, BTagEntry::JetFlavor::FLAV_UDSG, "fastsim");
        reader_fastsim->load(*calib_fastsim, BTagEntry::JetFlavor::FLAV_B, "fastsim");
        reader_fastsim->load(*calib_fastsim, BTagEntry::JetFlavor::FLAV_C, "fastsim");
        // get btag efficiencies
        TFile * f_btag_eff_fastsim           = new TFile("coreutil/data/btagsf/btageff__SMS-T1bbbb-T1qqqq_25ns_Moriond17.root");
        TH2D  * h_btag_eff_b_fastsim_temp    = (TH2D*) f_btag_eff_fastsim->Get("h2_BTaggingEff_csv_loose_Eff_b");
        TH2D  * h_btag_eff_c_fastsim_temp    = (TH2D*) f_btag_eff_fastsim->Get("h2_BTaggingEff_csv_loose_Eff_c");
        TH2D  * h_btag_eff_udsg_fastsim_temp = (TH2D*) f_btag_eff_fastsim->Get("h2_BTaggingEff_csv_loose_Eff_udsg");
        h_btag_eff_b_fastsim    = (TH2D*) h_btag_eff_b_fastsim_temp    -> Clone("h_btag_eff_b_fastsim");
        h_btag_eff_c_fastsim    = (TH2D*) h_btag_eff_c_fastsim_temp    -> Clone("h_btag_eff_c_fastsim");
        h_btag_eff_udsg_fastsim = (TH2D*) h_btag_eff_udsg_fastsim_temp -> Clone("h_btag_eff_udsg_fastsim");
        std::cout << "loaded fastsim btag SFs" << std::endl;
    } // if (isFastsim)
}

//########################################################################################
void CoreUtil::btag::clearSF()
{
    btagprob_data = 1.;
    btagprob_heavy_UP = 1.;
    btagprob_heavy_DN = 1.;
    btagprob_light_UP = 1.;
    btagprob_light_DN = 1.;
    btagprob_mc = 1.;
}

//########################################################################################
void CoreUtil::btag::accumulateSF(int iJet, float pt, float eta)
{
    float current_csv_val = cms3.getbtagvalue("pfCombinedInclusiveSecondaryVertexV2BJetTags", iJet);
    bool isData = cms3.evt_isRealData();
    bool isSMSScan = false;

    float eff = getBtagEffFromFile(pt, eta, cms3.pfjets_hadronFlavour().at(iJet), isSMSScan);
    BTagEntry::JetFlavor flavor = BTagEntry::FLAV_UDSG;
    if (abs(cms3.pfjets_hadronFlavour().at(iJet)) == 5) { flavor = BTagEntry::FLAV_B; }
    else if (abs(cms3.pfjets_hadronFlavour().at(iJet)) == 4) { flavor = BTagEntry::FLAV_C; }
    float weight_cent(1.), weight_UP(1.), weight_DN(1.);
    weight_cent = reader_fullsim->eval_auto_bounds("central",flavor,eta,pt);
    weight_UP = reader_fullsim->eval_auto_bounds("up",flavor,eta,pt);
    weight_DN = reader_fullsim->eval_auto_bounds("down",flavor,eta,pt);
    // extra SF for fastsim
    if (isSMSScan)
    {
        weight_cent *= reader_fastsim->eval_auto_bounds("central", flavor, eta, pt);
        weight_UP *= reader_fastsim->eval_auto_bounds("up", flavor, eta, pt);
        weight_DN *= reader_fastsim->eval_auto_bounds("down", flavor, eta, pt);
    }

    if (current_csv_val >= BJET_CSV_LOOSE && (fabs(eta) < BJET_ETA_MAX) && (pt > BJET_PT_MIN))
    {
        // for applying btagging SFs
        if (!isData)
        {
            btagprob_data *= weight_cent * eff;
            btagprob_mc *= eff;
            if (flavor == BTagEntry::FLAV_UDSG)
            {
                btagprob_light_UP *= weight_UP * eff;
                btagprob_light_DN *= weight_DN * eff;
                btagprob_heavy_UP *= weight_cent * eff;
                btagprob_heavy_DN *= weight_cent * eff;
            }
            else
            {
                btagprob_light_UP *= weight_cent * eff;
                btagprob_light_DN *= weight_cent * eff;
                btagprob_heavy_UP *= weight_UP * eff;
                btagprob_heavy_DN *= weight_DN * eff;
            }
        }
    }
    else  // fail btag
    {
        if (!isData)   // fail med btag -- needed for SF event weights
        {
            btagprob_data *= (1. - weight_cent * eff);
            btagprob_mc *= (1. - eff);
            if (flavor == BTagEntry::FLAV_UDSG)
            {
                btagprob_light_UP *= (1. - weight_UP * eff);
                btagprob_light_DN *= (1. - weight_DN * eff);
                btagprob_heavy_UP *= (1. - weight_cent * eff);
                btagprob_heavy_DN *= (1. - weight_cent * eff);
            }
            else
            {
                btagprob_light_UP *= (1. - weight_cent * eff);
                btagprob_light_DN *= (1. - weight_cent * eff);
                btagprob_heavy_UP *= (1. - weight_UP * eff);
                btagprob_heavy_DN *= (1. - weight_DN * eff);
            }
        }
    }
}

//########################################################################################
float CoreUtil::btag::getBtagEffFromFile(float pt, float eta, int mcFlavour, bool isFastsim)
{
    if (!h_btag_eff_b || !h_btag_eff_c || !h_btag_eff_udsg)
    {
        std::cout << "babyMaker::getBtagEffFromFile: ERROR: missing input hists" << std::endl;
        return 1.;
    }
    if (isFastsim && (!h_btag_eff_b_fastsim || !h_btag_eff_c_fastsim || !h_btag_eff_udsg_fastsim))
    {
        std::cout << "babyMaker::getBtagEffFromFile: ERROR: missing input hists" << std::endl;
        return 1.;
    }
    // only use pt bins up to 400 GeV for charm and udsg
    float pt_cutoff = std::max(20., std::min(399., double(pt)));
    TH2D* h(0);
    if (abs(mcFlavour) == 5)
    {
        h = isFastsim ? h_btag_eff_b_fastsim : h_btag_eff_b;
        // use pt bins up to 600 GeV for b
        pt_cutoff = std::max(20., std::min(599., double(pt)));
    }
    else if (abs(mcFlavour) == 4)
    {
        h = isFastsim ? h_btag_eff_c_fastsim : h_btag_eff_c;
    }
    else
    {
        h = isFastsim ? h_btag_eff_udsg_fastsim : h_btag_eff_udsg;
    }
    int binx = h->GetXaxis()->FindBin(pt_cutoff);
    int biny = h->GetYaxis()->FindBin(fabs(eta));
    return h->GetBinContent(binx, biny);
}

