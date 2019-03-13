#include "btag.h"
#include "Config.h"
//########################################################################################
void CoreUtil::btag::setup(bool fastsim, bool deepcsv, int yr)
{
    isfastsim = fastsim;
    isdeepcsv = deepcsv;
    year = yr;

    TString path = gSystem->Getenv("COREDIR");

    if (isdeepcsv)
    {
        calib = new BTagCalibration("DeepCSV", (TString::Format("%s/Tools/btagsf/run2_25ns/", path.Data()) + gconf.fn_btagSF_DeepCSV).Data());
        reader_medium = new BTagCalibrationReader(BTagEntry::OP_MEDIUM, "central", {"up", "down"});
        reader_medium->load(*calib, BTagEntry::FLAV_B, "comb");
        reader_medium->load(*calib, BTagEntry::FLAV_C, "comb");
        reader_medium->load(*calib, BTagEntry::FLAV_UDSG, "incl");
        reader_tight = new BTagCalibrationReader(BTagEntry::OP_TIGHT, "central", {"up", "down"});
        reader_tight->load(*calib, BTagEntry::FLAV_B, "comb");
        reader_tight->load(*calib, BTagEntry::FLAV_C, "comb");
        reader_tight->load(*calib, BTagEntry::FLAV_UDSG, "incl");
        reader_loose = new BTagCalibrationReader(BTagEntry::OP_LOOSE, "central", {"up", "down"});
        reader_loose->load(*calib, BTagEntry::FLAV_B, "comb");
        reader_loose->load(*calib, BTagEntry::FLAV_C, "comb");
        reader_loose->load(*calib, BTagEntry::FLAV_UDSG, "incl");
        // DeepCSV fastsim version of SFs
        calib_fastsim = new BTagCalibration("deepcsv", (TString::Format("%s/Tools/btagsf/run2_fastsim/", path.Data()) + gconf.fn_btagSF_FS_DeepCSV).Data());
        reader_medium_FS = new BTagCalibrationReader(BTagEntry::OP_MEDIUM, "central", {"up", "down"});
        reader_medium_FS->load(*calib_fastsim, BTagEntry::FLAV_B, "fastsim");
        reader_medium_FS->load(*calib_fastsim, BTagEntry::FLAV_C, "fastsim");
        reader_medium_FS->load(*calib_fastsim, BTagEntry::FLAV_UDSG, "fastsim");
        reader_tight_FS = new BTagCalibrationReader(BTagEntry::OP_TIGHT, "central", {"up", "down"});
        reader_tight_FS->load(*calib_fastsim, BTagEntry::FLAV_B, "fastsim");
        reader_tight_FS->load(*calib_fastsim, BTagEntry::FLAV_C, "fastsim");
        reader_tight_FS->load(*calib_fastsim, BTagEntry::FLAV_UDSG, "fastsim");
        reader_loose_FS = new BTagCalibrationReader(BTagEntry::OP_LOOSE, "central", {"up", "down"});
        reader_loose_FS->load(*calib_fastsim, BTagEntry::FLAV_B, "fastsim");
        reader_loose_FS->load(*calib_fastsim, BTagEntry::FLAV_C, "fastsim");
        reader_loose_FS->load(*calib_fastsim, BTagEntry::FLAV_UDSG, "fastsim");
        TH2D* h_btag_eff_b_temp = NULL;
        TH2D* h_btag_eff_c_temp = NULL;
        TH2D* h_btag_eff_udsg_temp = NULL;
        TH2D* h_tight_btag_eff_b_temp = NULL;
        TH2D* h_tight_btag_eff_c_temp = NULL;
        TH2D* h_tight_btag_eff_udsg_temp = NULL;
        TH2D* h_loose_btag_eff_b_temp = NULL;
        TH2D* h_loose_btag_eff_c_temp = NULL;
        TH2D* h_loose_btag_eff_udsg_temp = NULL;
        if (isfastsim)
        {
            // Created using https://github.com/cmstas/bTagEfficiencyTools. TODO: change to deepCSV version
            feff =  new TFile(TString::Format("%s/Tools/btagsf/run2_fastsim/btageff__SMS-T1bbbb-T1qqqq_25ns_Moriond17.root", path.Data()));
        }
        else
        {
            // TODO: create efficiency in the phase space of the stop analysis
            if (year == 2018)
                feff =  new TFile(TString::Format("%s/Tools/btagsf/run2_25ns/btageff__ttbar_amc_102X_deepCSV.root", path.Data()));
            else if (year == 2017)
                feff =  new TFile(TString::Format("%s/Tools/btagsf/run2_25ns/btageff__ttbar_amc_94X_deepCSV.root", path.Data()));
            else if (year == 2016)
                feff =  new TFile(TString::Format("%s/Tools/btagsf/run2_25ns/btageff__ttbar_powheg_pythia8_25ns_Moriond17_deepCSV.root", path.Data()));
        }
        if (!feff) throw std::invalid_argument("coreutil::btag.cc: btagsf file does not exist!");
        h_btag_eff_b_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_med_Eff_b");
        h_btag_eff_c_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_med_Eff_c");
        h_btag_eff_udsg_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_med_Eff_udsg");
        h_tight_btag_eff_b_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_tight_Eff_b");
        h_tight_btag_eff_c_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_tight_Eff_c");
        h_tight_btag_eff_udsg_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_tight_Eff_udsg");
        h_loose_btag_eff_b_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_loose_Eff_b");
        h_loose_btag_eff_c_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_loose_Eff_c");
        h_loose_btag_eff_udsg_temp = (TH2D*) feff->Get("h2_BTaggingEff_csv_loose_Eff_udsg");
        if (!h_btag_eff_b_temp) throw std::invalid_argument("coreutil::btag.cc: can't find the btagging efficiency histogram!");
        h_btag_eff_b = (TH2D*) h_btag_eff_b_temp->Clone("h_btag_eff_b");
        h_btag_eff_c = (TH2D*) h_btag_eff_c_temp->Clone("h_btag_eff_c");
        h_btag_eff_udsg = (TH2D*) h_btag_eff_udsg_temp->Clone("h_btag_eff_udsg");
        h_tight_btag_eff_b = (TH2D*) h_tight_btag_eff_b_temp->Clone("h_tight_btag_eff_b");
        h_tight_btag_eff_c = (TH2D*) h_tight_btag_eff_c_temp->Clone("h_tight_btag_eff_c");
        h_tight_btag_eff_udsg = (TH2D*) h_tight_btag_eff_udsg_temp->Clone("h_tight_btag_eff_udsg");
        h_loose_btag_eff_b = (TH2D*) h_loose_btag_eff_b_temp->Clone("h_loose_btag_eff_b");
        h_loose_btag_eff_c = (TH2D*) h_loose_btag_eff_c_temp->Clone("h_loose_btag_eff_c");
        h_loose_btag_eff_udsg = (TH2D*) h_loose_btag_eff_udsg_temp->Clone("h_loose_btag_eff_udsg");
        std::cout << "loaded fullsim btag SFs" << std::endl;
    }
    else if (year == 2016)
    {
        // setup btag calibration readers
        string corepath = TString::Format("%s/Tools/btagsf/data/run2_25ns/", path.Data()).Data();
        calib           = new BTagCalibration("csvv2", Form("%s/CSVv2_Moriond17_B_H.csv", corepath.c_str())); // Moriond17 version of SFs
        reader_fullsim = new BTagCalibrationReader(BTagEntry::OP_LOOSE, "central", {"up", "down"});
        reader_fullsim->load(*calib, BTagEntry::JetFlavor::FLAV_B, "comb");
        reader_fullsim->load(*calib, BTagEntry::JetFlavor::FLAV_C, "comb");
        reader_fullsim->load(*calib, BTagEntry::JetFlavor::FLAV_UDSG, "incl");
        // get btag efficiencies
        TFile * f_btag_eff           = new TFile("${COREDIR}/Tools/btagsf/data/run2_25ns/btageff__ttbar_powheg_pythia8_25ns_Moriond17.root");
        TH2D  * h_btag_eff_b_temp    = (TH2D*) f_btag_eff->Get("h2_BTaggingEff_csv_loose_Eff_b");
        TH2D  * h_btag_eff_c_temp    = (TH2D*) f_btag_eff->Get("h2_BTaggingEff_csv_loose_Eff_c");
        TH2D  * h_btag_eff_udsg_temp = (TH2D*) f_btag_eff->Get("h2_BTaggingEff_csv_loose_Eff_udsg");
        h_btag_eff_b    = (TH2D*) h_btag_eff_b_temp    -> Clone("h_btag_eff_b");
        h_btag_eff_c    = (TH2D*) h_btag_eff_c_temp    -> Clone("h_btag_eff_c");
        h_btag_eff_udsg = (TH2D*) h_btag_eff_udsg_temp -> Clone("h_btag_eff_udsg");
        // extra copy for fastsim -> fullsim SFs
        if (isfastsim)
        {
            // setup btag calibration readers
            calib_fastsim     = new BTagCalibration("CSV", "coreutil/data/btagsf/fastsim_csvv2_ttbar_26_1_2017.csv"); // Moriond 17 25ns fastsim version of SFs
            reader_fastsim = new BTagCalibrationReader(BTagEntry::OP_LOOSE, "central", {"up", "down"});
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
            std::cout << "loaded fullsim and fastsim btag SFs" << std::endl;
        }
        else
            std::cout << "loaded fullsim btag SFs" << std::endl;
    }

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
    if (year == 2016)
    {
        if (isdeepcsv)
        {
            accumulateSFDeepRun2(iJet, pt, eta);
        }
        else
        {
            accumulateSF2016CSVv2(iJet, pt, eta);
        }
    }
    else if(year == 2017 or year == 2018)
    {
            accumulateSFDeepRun2(iJet, pt, eta); 
    }
}

//########################################################################################
void CoreUtil::btag::accumulateSF2016CSVv2(int iJet, float pt, float eta)
{

    float current_csv_val = cms3.getbtagvalue("pfCombinedInclusiveSecondaryVertexV2BJetTags", iJet);
    bool isData = cms3.evt_isRealData();

    float eff = getBtagEffFromFile(pt, eta, cms3.pfjets_hadronFlavour().at(iJet), isfastsim);
    BTagEntry::JetFlavor flavor = BTagEntry::FLAV_UDSG;
    if (abs(cms3.pfjets_hadronFlavour().at(iJet)) == 5) { flavor = BTagEntry::FLAV_B; }
    else if (abs(cms3.pfjets_hadronFlavour().at(iJet)) == 4) { flavor = BTagEntry::FLAV_C; }
    float weight_cent(1.), weight_UP(1.), weight_DN(1.);
    weight_cent = reader_fullsim->eval_auto_bounds("central",flavor,eta,pt);
    weight_UP = reader_fullsim->eval_auto_bounds("up",flavor,eta,pt);
    weight_DN = reader_fullsim->eval_auto_bounds("down",flavor,eta,pt);
    // extra SF for fastsim
    if (isfastsim)
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
void CoreUtil::btag::accumulateSFDeepRun2(int iJet, float pt, float eta)
{
   static TString deepCSV_prefix = "NULL";
    if( deepCSV_prefix == "NULL" ) {
      for( TString discName : cms3.pfjets_bDiscriminatorNames() ) {
        if( discName.Contains("pfDeepCSV") ) { // 2017 convention
          deepCSV_prefix = "pfDeepCSV";
          break;
        }
        else if( discName.Contains("deepFlavour") ) { // 2016 convention
          deepCSV_prefix = "deepFlavour";
          break;
        }
      } // end loop over b discriminator names

      if( deepCSV_prefix == "NULL" ) {
        cout << "Error in JetTree.cc: Can't find DeepCSV discriminator names!" << endl;
        exit(1);
      }
    } // end if prefix == "NULL"
    float current_csv_val = cms3.getbtagvalue(deepCSV_prefix+"JetTags:probb",iJet) + cms3.getbtagvalue(deepCSV_prefix+"JetTags:probbb",iJet);
    bool isData = cms3.evt_isRealData();

    float eff = getBtagEffFromFile(pt, eta, cms3.pfjets_hadronFlavour().at(iJet), isfastsim);
    BTagEntry::JetFlavor flavor = BTagEntry::FLAV_UDSG;
    if (abs(cms3.pfjets_hadronFlavour().at(iJet)) == 5) { flavor = BTagEntry::FLAV_B; }
    else if (abs(cms3.pfjets_hadronFlavour().at(iJet)) == 4) { flavor = BTagEntry::FLAV_C; }
    float weight_cent(1.), weight_UP(1.), weight_DN(1.);
    weight_cent = reader_fullsim->eval_auto_bounds("central",flavor,eta,pt);
    weight_UP = reader_fullsim->eval_auto_bounds("up",flavor,eta,pt);
    weight_DN = reader_fullsim->eval_auto_bounds("down",flavor,eta,pt);
    // extra SF for fastsim
    if (isfastsim)
    {
        weight_cent *= reader_fastsim->eval_auto_bounds("central", flavor, eta, pt);
        weight_UP *= reader_fastsim->eval_auto_bounds("up", flavor, eta, pt);
        weight_DN *= reader_fastsim->eval_auto_bounds("down", flavor, eta, pt);
    }

    if (current_csv_val >= gconf.WP_DEEPCSV_LOOSE && (fabs(eta) < BJET_ETA_MAX) && (pt > BJET_PT_MIN))
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

