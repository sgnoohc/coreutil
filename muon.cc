#include "muon.h"

//########################################################################################
void CoreUtil::muon::setup()
{
}

//########################################################################################
void CoreUtil::muon::process(std::function<bool(int)> pass)
{

    // Clear the saved indices
    index.clear();

    for (unsigned int iMu = 0; iMu < cms3.mus_p4().size(); iMu++)
    {

        // Basic cuts
        if (!pass(iMu))
            continue;

        // Save the indices
        index.push_back(iMu);

    }

}

////########################################################################################
//bool CoreUtil::muon::pass(int i)
//{
//    if (!( cms3.mus_p4()[idx].pt()            > 10.    )) return false;
//    if (!( cms3.mus_p4()[idx].eta()           < 2.4    )) return false;
//    if (!( fabs(cms3.mus_dxyPV().at(idx))     <  0.05  )) return false;
//    if (!( fabs(cms3.mus_dzPV().at(idx))      <  0.1   )) return false;
//    if (!( isLooseMuonPOG(idx)                         )) return false;
//    return true;
//}
