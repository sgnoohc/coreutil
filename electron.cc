#include "electron.h"

//########################################################################################
void CoreUtil::electron::setup()
{

    cout << "Creating electron MVA instance" << endl;
    createAndInitMVA("coreutil/data/MVAinput", true, false, 80); // for electrons

}

//########################################################################################
void CoreUtil::electron::process(std::function<bool(int)> pass, std::function<bool(int, int)> tagpass)
{

    // Clear the saved indices
    index.clear();
    if (tagpass) tagindex.clear();

    for (unsigned int iEl = 0; iEl < cms3.els_p4().size(); iEl++)
    {

        // Basic cuts
        if (!pass(iEl))
            continue;

        // Save the indices
        index.push_back(iEl);

        if (tagpass)
        {
            int tagel = -1;
            for (unsigned int jEl = 0; jEl < cms3.els_p4().size(); jEl++)
            {
                // Skip if the considered lepton is identical
                if (iEl == jEl)
                    continue;

                // If it did not pass tag electron defn skip
                // iEl = probe, jEl = tag
                if (!tagpass(iEl, jEl))
                    continue;

                // If a tag electron found set the index and break
                tagel = jEl;
                break;
            }
            tagindex.push_back(tagel);
        }
    }

}

////########################################################################################
//bool CoreUtil::electron::pass(int i)
//{
//    if (!( cms3.els_p4()[idx].pt()            >  10.   )) return false;
//    if (!( fabs(cms3.els_etaSC().at(idx))     <= 2.5   )) return false;
//    if (!( cms3.els_exp_innerlayers().at(idx) <= 1     )) return false;
//    if (!( fabs(cms3.els_dxyPV().at(idx))     <  0.05  )) return false;
//    if (!( fabs(cms3.els_dzPV().at(idx))      <  0.1   )) return false;
//    if (!( isTriggerSafenoIso_v1(idx)                  )) return false;
//    return true;
//}
