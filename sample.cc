#include "sample.h"

//_________________________________________________________________________________________________
CoreUtil::sample::CMS4Type CoreUtil::sample::CMS4Version(TString fname)
{
    if (fname.Contains("CMS4_V00-00-02_data2016"  )) return k2016Data;
    if (fname.Contains("CMS4_V00-00-02_2017Sep27" )) return k2016MC;
    if (fname.Contains("CMS4_V00-00-03_2017Sep27" )) return k2016MC;
    if (fname.Contains("CMS4_V00-00-02_AllPF"     )) return k2016MC;
    if (fname.Contains("CMS4_V08-00-06_826p1"     )) return k2016MC;
    if (fname.Contains("CMS4_V08-00-06"           )) return k2016MC;
    if (fname.Contains("CMS4_V09-04-17"           ) and fname.Contains("Run2016")) return k2016Data;
    if (fname.Contains("CMS4_V09-04-12"           )) return k2017Data;
    if (fname.Contains("CMS4_V09-04-13"           )) return k2017MC;
    if (fname.Contains("CMS4_V09-04-19"           )) return k2017MC;
    if (fname.Contains("CMS4_V09-04-17"           )) return k2017MC;
    if (fname.Contains("CMS4_V00-00-02"           )) return k2016MC;
    if (fname.Contains("RunIISummer16MiniAODv3"   )) return k2016MC;
    if (fname.Contains("RunIIFall17MiniAODv2"     )) return k2017MC;
    if (fname.Contains("RunIIFall17MiniAOD"       )) return k2017MC;
    if (fname.Contains("RunIIAutumn18MiniAOD"       )) return k2018MC;
    if (fname.Contains("Run2016") and fname.Contains("CMS4_V10-02-05")) return k2016Data;
    if (fname.Contains("Run2016") and fname.Contains("CMS4_V10-02-04")) return k2016Data;
    if (fname.Contains("Run2017") and fname.Contains("CMS4_V10-02-05")) return k2017Data;
    if (fname.Contains("Run2018") and fname.Contains("CMS4_V10-02-04")) return k2018Data;

    std::cout << TString::Format("[CoreUtil::sample] Can't parse which CMS4 version it is from sample = %s", fname.Data()) << std::endl;
    abort();
}

//_________________________________________________________________________________________________
bool CoreUtil::sample::is201680X (TString fname) { return (is2016Data(fname) || is2016MC(fname)) and fname.Contains("80X"); }
bool CoreUtil::sample::is2016    (TString fname) { return is2016Data(fname) || is2016MC(fname); }
bool CoreUtil::sample::is2017    (TString fname) { return is2017Data(fname) || is2017MC(fname); }
bool CoreUtil::sample::is2018    (TString fname) { return is2018Data(fname) || is2018MC(fname); }
bool CoreUtil::sample::is2016Data(TString fname) { return CMS4Version(fname) == k2016Data; }
bool CoreUtil::sample::is2016MC  (TString fname) { return CMS4Version(fname) == k2016MC; }
bool CoreUtil::sample::is2017Data(TString fname) { return CMS4Version(fname) == k2017Data; }
bool CoreUtil::sample::is2017MC  (TString fname) { return CMS4Version(fname) == k2017MC; }
bool CoreUtil::sample::is2018Data(TString fname) { return CMS4Version(fname) == k2018Data; }
bool CoreUtil::sample::is2018MC  (TString fname) { return CMS4Version(fname) == k2018MC; }

//_________________________________________________________________________________________________
TString CoreUtil::sample::nicename(TString fname)
{
    if (fname.Contains("PrivateWWW")) return "www";
    if (fname.Contains("WWW_4F_")) return "www";
    if (fname.Contains("VHToNonbb")) return "vh";
    if (fname.Contains("VHToWW")) return "vh";
    if (fname.Contains("VH_PRIVATE")) return "vh";
    return "UNKNOWN";
}

// eof
