#ifndef met_h
#define met_h

#include <vector>
#include <iostream>

#include "MetSelections.h"
#include "Base.h"
#include "jec.h"
#include "jer.h"

using namespace std;

namespace CoreUtil
{
    class met
    {

        public:

            float met_pt;
            float met_phi;

            float met_up_pt;
            float met_up_phi;

            float met_dn_pt;
            float met_dn_phi;

            float met_jer_pt;
            float met_jer_phi;

            float met_jerup_pt;
            float met_jerup_phi;

            float met_jerdn_pt;
            float met_jerdn_phi;

            float met_puppi_pt;
            float met_puppi_phi;

            float met_muonegcleaned_pt;
            float met_muonegcleaned_phi;

            float met_muonegcleaned_up_pt;
            float met_muonegcleaned_up_phi;

            float met_muonegcleaned_dn_pt;
            float met_muonegcleaned_dn_phi;

            met() {}
            ~met() {}

            void process(jec&);
            void process(jec&, jer& jer);
            void process(jec&, jer* jer);
    };
}

#endif
