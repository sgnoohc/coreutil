#ifndef datasetinfo_h
#define datasetinfo_h

#include "TString.h"
#include "TSystem.h"

#include "Tools/datasetinfo/getDatasetInfo.h"
#include "CMS3.h"

#include <fstream>

namespace CoreUtil
{
    class datasetinfo
    {
        public:
            DatasetInfoFromFile df;
            DatasetInfoFromFile dfcustom;

            datasetinfo();
            ~datasetinfo();

            float getScale1fb();
            float getXsec();
    };
}

#endif
