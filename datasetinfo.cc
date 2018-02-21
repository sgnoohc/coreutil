#include "datasetinfo.h"

//########################################################################################
CoreUtil::datasetinfo::datasetinfo()
{
    // $COREDIR must be set
    TString path = gSystem->Getenv("COREDIR");

    // If path is null
    if (path.IsNull())
    {
        printf("CoreUtil::datasetinfo::datasetinfo() Must set COREDIR=/path/to/CORE\n");
        abort();
    }

    // Append the fullpath via hardcode
    path += "/Tools/datasetinfo/scale1fbs.txt";

    printf("CoreUtil::datasetinfo::datasetinfo() Loading %s\n", path.Data());

    // Load scale1fbs/xsecs from file once
    df.loadFromFile(path.Data());
}

//########################################################################################
CoreUtil::datasetinfo::~datasetinfo()
{
}


//########################################################################################
float CoreUtil::datasetinfo::getScale1fb()
{
    if (cms3.evt_CMS3tag()[0].Contains("CMS3"))
        return cms3.evt_scale1fb();
    // Each event, get the sign of the MC weight and multiply it by the magnitude of the scale1fb in the text file. A scale1fb is uniquely specified by a pair of (dataset name, cms3tag), which are both embedded in the ntuples already
    float sgnMCweight = ((cms3.genps_weight() > 0) - (cms3.genps_weight() < 0));
    float scale1fb = sgnMCweight*df.getScale1fbFromFile(cms3.evt_dataset()[0].Data(),cms3.evt_CMS3tag()[0].Data());
    return scale1fb;
}
 
//########################################################################################
float CoreUtil::datasetinfo::getXsec()
{
    if (cms3.evt_CMS3tag()[0].Contains("CMS3"))
        return cms3.evt_xsec_incl();
    // Each event, get the sign of the MC weight and multiply it by the magnitude of the scale1fb in the text file. A scale1fb is uniquely specified by a pair of (dataset name, cms3tag), which are both embedded in the ntuples already
    float sgnMCweight = ((cms3.genps_weight() > 0) - (cms3.genps_weight() < 0));
    float xsec = sgnMCweight*df.getXsecFromFile(cms3.evt_dataset()[0].Data(),cms3.evt_CMS3tag()[0].Data());
    return xsec;
}
