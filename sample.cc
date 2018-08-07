#include "sample.h"

//_________________________________________________________________________________________________
CoreUtil::sample::CMS4Type CoreUtil::sample::CMS4Version(TString fname)
{
    if (fname.Contains("CMS4_V00-00-02_data2016"  )) return k2016Data;
    if (fname.Contains("CMS4_V00-00-02_2017Sep27" )) return k2016MC;
    if (fname.Contains("CMS4_V09-04-12"           )) return k2017Data;
    if (fname.Contains("CMS4_V09-04-13"           )) return k2017MC;
    if (fname.Contains("CMS4_V09-04-17"           )) return k2017MC;

    std::cout << TString::Format("[CoreUtil::sample] Can't parse which CMS4 version it is from sample = %s", fname.Data()) << std::endl;
    abort();
}

//_________________________________________________________________________________________________
bool CoreUtil::sample::is2016(TString fname) { return is2016Data(fname) || is2016MC(fname); }
bool CoreUtil::sample::is2017(TString fname) { return is2017Data(fname) || is2017MC(fname); }
bool CoreUtil::sample::is2016Data(TString fname) { return CMS4Version(fname) == k2016Data; }
bool CoreUtil::sample::is2016MC(TString fname) { return CMS4Version(fname) == k2016MC; }
bool CoreUtil::sample::is2017Data(TString fname) { return CMS4Version(fname) == k2017Data; }
bool CoreUtil::sample::is2017MC(TString fname) { return CMS4Version(fname) == k2017MC; }

//_________________________________________________________________________________________________
TString CoreUtil::sample::nicename(TString fname)
{
    // 2016
    if (fname.Contains("DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                      )) return "dy_m1050_mgmlm";
    if (fname.Contains("DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                         )) return "dy_m50_mgmlm_ht100_ext1";
    if (fname.Contains("DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                            )) return "dy_m50_mgmlm_ht1200_nonext";
    if (fname.Contains("DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                         )) return "dy_m50_mgmlm_ht200_ext1";
    if (fname.Contains("DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                             )) return "dy_m50_mgmlm_ht2500_nonext";
    if (fname.Contains("DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                         )) return "dy_m50_mgmlm_ht400_ext1";
    if (fname.Contains("DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v2"                                                              )) return "dy_m50_mgmlm_ht600_nonext";
    if (fname.Contains("DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                             )) return "dy_m50_mgmlm_ht800_nonext";
    if (fname.Contains("DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v2"                                                                     )) return "dy_m50_mgmlm_ext1";
    if (fname.Contains("EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                               )) return "Wmjj_lnu_madgraph";
    if (fname.Contains("EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                )) return "Wpjj_lnu_madgraph";
    if (fname.Contains("EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                     )) return "Zjj_m50_madgraph";
    if (fname.Contains("ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                )) return "sts_4f_leptonic_amcnlo";
    if (fname.Contains("ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                             )) return "stt_antitop_incdec_powheg";
    if (fname.Contains("ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                 )) return "stt_top_incdec_powheg";
    if (fname.Contains("ST_tW_antitop_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                )) return "sttw_antitop_nofullhaddecay_powheg";
    if (fname.Contains("ST_tW_top_5f_NoFullyHadronicDecays_13TeV-powheg_TuneCUETP8M1_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                    )) return "sttw_top_nofullhaddecay_powheg";
    if (fname.Contains("ST_tWll_5f_LO_13TeV-MadGraph-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                            )) return "sttwll_madgraph";
    if (fname.Contains("TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                         )) return "ttg_incl_amcnlo";
    if (fname.Contains("TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                          )) return "ttbar_incl_powheg";
    if (fname.Contains("TTJets_DiLept_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                       )) return "ttbar_dilep_mgmlm_ext1";
    if (fname.Contains("TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                              )) return "ttbar_1ltop_mgmlm_ext1";
    if (fname.Contains("TTJets_SingleLeptFromTbar_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                           )) return "ttbar_1ltbr_mgmlm_ext1";
    if (fname.Contains("VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                               )) return "vh_nonbb_amcnlo";
    if (fname.Contains("WGToLNuG_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                 )) return "wgjets_incl_mgmlm";
    if (fname.Contains("WGstarToLNuEE_012Jets_13TeV-madgraph_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                            )) return "wgstar_lnee_012jets_madgraph";
    if (fname.Contains("WGstarToLNuMuMu_012Jets_13TeV-madgraph_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                          )) return "wgstar_lnmm_012jets_madgraph";
    if (fname.Contains("WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                              )) return "wjets_ht100_mgmlm_ext1";
    if (fname.Contains("WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                 )) return "wjets_ht1200_mgmlm_nonext";
    if (fname.Contains("WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                              )) return "wjets_ht200_mgmlm_ext1";
    if (fname.Contains("WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                             )) return "wjets_ht2500_mgmlm_ext1";
    if (fname.Contains("WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                              )) return "wjets_ht400_mgmlm_ext1";
    if (fname.Contains("WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                              )) return "wjets_ht600_mgmlm_ext1";
    if (fname.Contains("WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                             )) return "wjets_ht800_mgmlm_ext1";
    if (fname.Contains("WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                               )) return "wjets_incl_mgmlm";
    if (fname.Contains("WWG_TuneCUETP8M1_13TeV-amcatnlo-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                                    )) return "wwg_incl_amcnlo";
    if (fname.Contains("WWTo2L2Nu_13TeV-powheg_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                                          )) return "ww_2l2nu_powheg";
    if (fname.Contains("WWTo2L2Nu_DoubleScattering_13TeV-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                        )) return "ww_2l2nu_dbl_scat";
    if (fname.Contains("WWToLNuQQ_13TeV-powheg_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                                          )) return "ww_lnuqq_powheg";
    if (fname.Contains("WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                         )) return "wwz_incl_amcnlo";
    if (fname.Contains("WZG_TuneCUETP8M1_13TeV-amcatnlo-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                         )) return "wzg_incl_amcnlo";
    if (fname.Contains("WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v3"                                                                                  )) return "wz_lnqq_amcnlo";
    if (fname.Contains("WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                    )) return "wz_1l3n_amcnlo";
    if (fname.Contains("WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                      )) return "wz_3lnu_powheg";
    if (fname.Contains("WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                         )) return "wzz_incl_amcnlo";
    if (fname.Contains("WpWpJJ_EWK-QCD_TuneCUETP8M1_13TeV-madgraph-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                              )) return "wpwpjj_ewk-qcd_madgraph";
    if (fname.Contains("ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                            )) return "zgamma_2lG_amc";
    if (fname.Contains("ZZTo2L2Nu_13TeV_powheg_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                                  )) return "zz_2l2n_powheg";
    if (fname.Contains("ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                     )) return "zz_2l2q_powheg";
    if (fname.Contains("ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                    )) return "zz_2q2n_amcnlo";
    if (fname.Contains("ZZTo4L_13TeV_powheg_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                                     )) return "zz_4l_powheg";
    if (fname.Contains("ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                         )) return "zzz_incl_amcnlo";
    if (fname.Contains("tZq_ll_4f_13TeV-amcatnlo-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                                           )) return "tzq_ll_amcnlo";
    if (fname.Contains("ttHToNonbb_M125_TuneCUETP8M2_ttHtranche3_13TeV-powheg-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                   )) return "tth_nonbb_powheg";
    if (fname.Contains("ttHTobb_M125_13TeV_powheg_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                               )) return "tth_bb_powheg";
    if (fname.Contains("ttWJets_13TeV_madgraphMLM_RunIISummer16MiniAODv2-80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                                                   )) return "ttw_incl_mgmlm";
    if (fname.Contains("ttZJets_13TeV_madgraphMLM_RunIISummer16MiniAODv2-80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                                                   )) return "ttz_incl_mgmlm";
    if (fname.Contains("QCD_Pt-15to20_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                          )) return "qcd_mu_pt15";
    if (fname.Contains("QCD_Pt-20to30_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                          )) return "qcd_mu_pt20";
    if (fname.Contains("QCD_Pt-30to50_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                          )) return "qcd_mu_pt30";
    if (fname.Contains("QCD_Pt-50to80_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                          )) return "qcd_mu_pt50";
    if (fname.Contains("QCD_Pt-80to120_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v3"                                                                    )) return "qcd_mu_pt80";
    if (fname.Contains("QCD_Pt-120to170_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                        )) return "qcd_mu_pt120";
    if (fname.Contains("QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                   )) return "qcd_mu_pt170";
    if (fname.Contains("QCD_Pt-300to470_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext2-v1"                                                                   )) return "qcd_mu_pt300";
    if (fname.Contains("QCD_Pt-470to600_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                   )) return "qcd_mu_pt470";
    if (fname.Contains("QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                        )) return "qcd_mu_pt600";
    if (fname.Contains("QCD_Pt-800to1000_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                       )) return "qcd_mu_pt800";
    if (fname.Contains("QCD_Pt-1000toInf_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v3"                                                                  )) return "qcd_mu_pt1000";
    if (fname.Contains("QCD_Pt-20to30_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                             )) return "qcd_em_pt20";
    if (fname.Contains("QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                        )) return "qcd_em_pt30";
    if (fname.Contains("QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                        )) return "qcd_em_pt50";
    if (fname.Contains("QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                       )) return "qcd_em_pt80";
    if (fname.Contains("QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1"                                                                      )) return "qcd_em_pt120";
    if (fname.Contains("QCD_Pt-170to300_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                           )) return "qcd_em_pt170";
    if (fname.Contains("QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                           )) return "qcd_em_pt300";
    if (fname.Contains("QCD_Pt_15to20_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                  )) return "qcd_bctoe_pt15";
    if (fname.Contains("QCD_Pt_20to30_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                  )) return "qcd_bctoe_pt20";
    if (fname.Contains("QCD_Pt_30to80_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                  )) return "qcd_bctoe_pt30";
    if (fname.Contains("QCD_Pt_80to170_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_backup_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                          )) return "qcd_bctoe_pt80";
    if (fname.Contains("QCD_Pt_170to250_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                )) return "qcd_bctoe_pt170";
    if (fname.Contains("QCD_Pt_250toInf_bcToE_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1"                                                                                )) return "qcd_bctoe_pt250";

    // Signal sample 2016
    if (fname.Contains("TEST-www_www-Private80X-v1"                                                                                                                                                                                    )) return "www_2l_mia_cms3";
    if (fname.Contains("TEST-www_wwwext-Private80X-v1"                                                                                                                                                                                 )) return "www_2l_ext1_mia_cms3";
    if (fname.Contains("PrivateWWW_www-cms4"                                                                                                                                                                                           )) return "www_2l_"; // the mia or ext1_mia is not needed. If you add this it actually screws it up
    if (fname.Contains("PrivateWWW_wwwext-cms4"                                                                                                                                                                                        )) return "www_2l_"; // the mia or ext1_mia is not needed. If you add this it actually screws it up

    // BSM models 2016
    if (fname.Contains("DoublyChargedHiggsGMmodel_HWW"                                                                                                                                                                                 )) return "hpmpm_hww";
    if (fname.Contains("WprimeToWH"                                                                                                                                                                                                    )) return "wprime";
    if (fname.Contains("TChiHH"                                                                                                                                                                                                        )) return "whsusy";
    if (fname.Contains("TChiWH"                                                                                                                                                                                                        )) return "whsusy";
    // The dataset name is a misnomer. it's actually WH->W(VVtautau)->2lep filter
    if (fname.Contains("TChiWH_HToVVTauTau_HToBB"                                                                                                                                                                                      )) return "whsusy-2l";

    // ALP model from N. Craig (UCSB)
    if (fname.Contains("PhotophobicALP")) return "alp";

    // 2017
    if (fname.Contains("DYJetsToLL_M-10to50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2_MINIAODSIM"                                      )) return "dy_m1050_madgraph";
    if (fname.Contains("DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIFall17MiniAODv2-PU2017RECOSIMstep_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"            )) return "dy_m50_madgraph";
    if (fname.Contains("DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIFall17MiniAODv2-PU2017RECOSIMstep_12Apr2018_94X_mc2017_realistic_v14_ext1-v1_MINIAODSIM"       )) return "dy_m50_madgraph_ext1";
    if (fname.Contains("ST_tW_antitop_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM" )) return "sttw_incltop_powheg";
    if (fname.Contains("ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"     )) return "sttw_incltbr_powheg";
    if (fname.Contains("TTGamma_SingleLeptFromT_TuneCP5_PSweights_13TeV_madgraph_pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"        )) return "ttg_1ltop_madgraph";
    if (fname.Contains("TTGamma_SingleLeptFromTbar_TuneCP5_PSweights_13TeV_madgraph_pythia8_RunIIFall17MiniAOD-PU2017_94X_mc2017_realistic_v11-v1_MINIAODSIM"                 )) return "ttg_1ltbr_madgraph";
    if (fname.Contains("TTHH_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                     )) return "tthh_madgraph";
    if (fname.Contains("TTJets_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                               )) return "ttbar_incl_amcnlo";
    if (fname.Contains("TTTJ_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                     )) return "tttj_incl_madgraph";
    if (fname.Contains("TTTT_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_pilot_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                         )) return "tttt_incl_amcnlo";
    if (fname.Contains("TTTW_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                     )) return "tttw_incl_madgraph";
    if (fname.Contains("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                 )) return "ttbar_1l_powheg";
    if (fname.Contains("TTWH_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                     )) return "ttwh_incl_madgraph";
    if (fname.Contains("TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                 )) return "ttw_ln_amcnlo";
    if (fname.Contains("TTWW_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14_ext1-v1_MINIAODSIM"                                )) return "ttww_incl_madgraph_ext1";
    if (fname.Contains("TTWZ_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                     )) return "ttwz_incl_madgraph";
    if (fname.Contains("TTZH_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                     )) return "ttzh_incl_madgraph";
    if (fname.Contains("TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                         )) return "ttz_m10llnn_amcnlo";
    if (fname.Contains("TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                          )) return "ttz_m1to10ll_amcnlo";
    if (fname.Contains("TTZZ_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                     )) return "ttzz_incl_madgraph";
    if (fname.Contains("WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14_ext1-v2_MINIAODSIM"                       )) return "wjets_ln_madgraph_ext1";
    if (fname.Contains("WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                   )) return "www_incl_amcnlo";
    if (fname.Contains("WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                   )) return "wwz_incl_amcnlo";
    if (fname.Contains("WW_DoubleScattering_13TeV-pythia8_TuneCP5_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                               )) return "ww_dblsctincl_pythia";
    if (fname.Contains("WW_TuneCP5_13TeV-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"                                                                   )) return "ww_incl_pythia";
    if (fname.Contains("WZG_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                      )) return "wzg_incl_amcnlo";
    if (fname.Contains("WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                             )) return "wz_3lnu_amcnlo";
    if (fname.Contains("WZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                      )) return "wzz_incl_amcnlo";
    if (fname.Contains("WZ_TuneCP5_13TeV-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                                )) return "wz_incl_pythia";
    if (fname.Contains("ZZTo4L_13TeV_powheg_pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                             )) return "zz_4l_powheg";
    if (fname.Contains("ZZZ_TuneCP5_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                                      )) return "zzz_incl_amcnlo";
    if (fname.Contains("tZq_ll_4f_ckm_NLO_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"              )) return "tzq_ll_amcnlo";
    if (fname.Contains("ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"                                               )) return "tth_nonbb_powheg";
    if (fname.Contains("WpWpJJ_EWK-QCD_TuneCP5_13TeV-madgraph-pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v1_MINIAODSIM"                           )) return "vbsww_madgraph";
    if (fname.Contains("VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_RunIIFall17MiniAODv2-PU2017_12Apr2018_94X_mc2017_realistic_v14-v2_MINIAODSIM"                       )) return "vh_nonbb_amcnlo";

    if (fname.Contains("QCD_Pt_15to20_bcToE_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM"           )) return "qcd_bctoe_pt15";
    if (fname.Contains("QCD_Pt_20to30_bcToE_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM"           )) return "qcd_bctoe_pt20";
    if (fname.Contains("QCD_Pt_30to80_bcToE_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM"           )) return "qcd_bctoe_pt30";
    if (fname.Contains("QCD_Pt_80to170_bcToE_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM"          )) return "qcd_bctoe_pt80";
    if (fname.Contains("QCD_Pt_170to250_bcToE_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM"         )) return "qcd_bctoe_pt170";
    if (fname.Contains("QCD_Pt_250toInf_bcToE_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1_MINIAODSIM"         )) return "qcd_bctoe_pt250";
    if (fname.Contains("QCD_Pt-15to20_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"   )) return "qcd_mu_pt15";
    if (fname.Contains("QCD_Pt-20to30_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"   )) return "qcd_mu_pt20";
    if (fname.Contains("QCD_Pt-30to50_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"   )) return "qcd_mu_pt30";
    if (fname.Contains("QCD_Pt-50to80_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"   )) return "qcd_mu_pt50";
    if (fname.Contains("QCD_Pt-80to120_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"  )) return "qcd_mu_pt80";
    if (fname.Contains("QCD_Pt-120to170_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM" )) return "qcd_mu_pt120";
    if (fname.Contains("QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM" )) return "qcd_mu_pt170";
    if (fname.Contains("QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM" )) return "qcd_mu_pt300";
    if (fname.Contains("QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM" )) return "qcd_mu_pt600";
    if (fname.Contains("QCD_Pt-15to20_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"      )) return "qcd_em_pt15";
    if (fname.Contains("QCD_Pt-20to30_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"      )) return "qcd_em_pt20";
    if (fname.Contains("QCD_Pt-30to50_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"      )) return "qcd_em_pt30";
    if (fname.Contains("QCD_Pt-50to80_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"      )) return "qcd_em_pt50";
    if (fname.Contains("QCD_Pt-80to120_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"     )) return "qcd_em_pt80";
    if (fname.Contains("QCD_Pt-120to170_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"    )) return "qcd_em_pt120";
    if (fname.Contains("QCD_Pt-170to300_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"    )) return "qcd_em_pt170";
    if (fname.Contains("QCD_Pt-300toInf_EMEnriched_TuneCP5_13TeV_pythia8_RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1_MINIAODSIM"    )) return "qcd_em_pt300";

    // Data 2016
    if (fname.Contains("DoubleEG_Run2016"   )) return "data_ee";
    if (fname.Contains("MuonEG_Run2016"     )) return "data_em";
    if (fname.Contains("DoubleMuon_Run2016" )) return "data_mm";

    // Data 2017
    if (fname.Contains("DoubleEG_Run2017B-31Mar2018-v1_MINIAOD"    )) return "data_ee_Run2017B";
    if (fname.Contains("DoubleEG_Run2017C-31Mar2018-v1_MINIAOD"    )) return "data_ee_Run2017C";
    if (fname.Contains("DoubleEG_Run2017D-31Mar2018-v1_MINIAOD"    )) return "data_ee_Run2017D";
    if (fname.Contains("DoubleEG_Run2017E-31Mar2018-v1_MINIAOD"    )) return "data_ee_Run2017E";
    if (fname.Contains("DoubleEG_Run2017F-31Mar2018-v1_MINIAOD"    )) return "data_ee_Run2017F";
    if (fname.Contains("DoubleMuon_Run2017B-31Mar2018-v1_MINIAOD"  )) return "data_mm_Run2017B";
    if (fname.Contains("DoubleMuon_Run2017C-31Mar2018-v1_MINIAOD"  )) return "data_mm_Run2017C";
    if (fname.Contains("DoubleMuon_Run2017D-31Mar2018-v1_MINIAOD"  )) return "data_mm_Run2017D";
    if (fname.Contains("DoubleMuon_Run2017E-31Mar2018-v1_MINIAOD"  )) return "data_mm_Run2017E";
    if (fname.Contains("DoubleMuon_Run2017F-31Mar2018-v1_MINIAOD"  )) return "data_mm_Run2017F";
    if (fname.Contains("MuonEG_Run2017B-31Mar2018-v1_MINIAOD"      )) return "data_em_Run2017B";
    if (fname.Contains("MuonEG_Run2017C-31Mar2018-v1_MINIAOD"      )) return "data_em_Run2017C";
    if (fname.Contains("MuonEG_Run2017D-31Mar2018-v1_MINIAOD"      )) return "data_em_Run2017D";
    if (fname.Contains("MuonEG_Run2017E-31Mar2018-v1_MINIAOD"      )) return "data_em_Run2017E";
    if (fname.Contains("MuonEG_Run2017F-31Mar2018-v1_MINIAOD"      )) return "data_em_Run2017F";

    if (fname.Contains("SingleElectron_Run2017B-31Mar2018-v1_MINIAOD"  )) return "data_se_Run2017B";
    if (fname.Contains("SingleElectron_Run2017C-31Mar2018-v1_MINIAOD"  )) return "data_se_Run2017C";
    if (fname.Contains("SingleElectron_Run2017D-31Mar2018-v1_MINIAOD"  )) return "data_se_Run2017D";
    if (fname.Contains("SingleElectron_Run2017E-31Mar2018-v1_MINIAOD"  )) return "data_se_Run2017E";
    if (fname.Contains("SingleElectron_Run2017F-31Mar2018-v1_MINIAOD"  )) return "data_se_Run2017F";
    if (fname.Contains("SingleMuon_Run2017B-31Mar2018-v1_MINIAOD"      )) return "data_sm_Run2017B";
    if (fname.Contains("SingleMuon_Run2017C-31Mar2018-v1_MINIAOD"      )) return "data_sm_Run2017C";
    if (fname.Contains("SingleMuon_Run2017D-31Mar2018-v1_MINIAOD"      )) return "data_sm_Run2017D";
    if (fname.Contains("SingleMuon_Run2017E-31Mar2018-v1_MINIAOD"      )) return "data_sm_Run2017E";
    if (fname.Contains("SingleMuon_Run2017F-31Mar2018-v1_MINIAOD"      )) return "data_sm_Run2017F";

    if (fname.Contains("MET_Run2017B-31Mar2018-v1_MINIAOD"  )) return "data_met_Run2017B";
    if (fname.Contains("MET_Run2017C-31Mar2018-v1_MINIAOD"  )) return "data_met_Run2017C";
    if (fname.Contains("MET_Run2017D-31Mar2018-v1_MINIAOD"  )) return "data_met_Run2017D";
    if (fname.Contains("MET_Run2017E-31Mar2018-v1_MINIAOD"  )) return "data_met_Run2017E";
    if (fname.Contains("MET_Run2017F-31Mar2018-v1_MINIAOD"  )) return "data_met_Run2017F";

    if (fname.Contains("JetHT_Run2017B-31Mar2018-v1_MINIAOD"  )) return "data_jet_Run2017B";
    if (fname.Contains("JetHT_Run2017C-31Mar2018-v1_MINIAOD"  )) return "data_jet_Run2017C";
    if (fname.Contains("JetHT_Run2017D-31Mar2018-v1_MINIAOD"  )) return "data_jet_Run2017D";
    if (fname.Contains("JetHT_Run2017E-31Mar2018-v1_MINIAOD"  )) return "data_jet_Run2017E";
    if (fname.Contains("JetHT_Run2017F-31Mar2018-v1_MINIAOD"  )) return "data_jet_Run2017F";

    std::cout << TString::Format("[CoreUtil::sample] Unrecognized sample = %s", fname.Data()) << std::endl;
    abort();

}

// eof
