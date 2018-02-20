#include "muon.h"

//########################################################################################
void CoreUtil::muon::setup()
{
}

//########################################################################################
void CoreUtil::muon::process()
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

//########################################################################################
bool CoreUtil::muon::pass(int i)
{
    return (isLooseMuonPOG(i) && cms3.mus_p4()[i].pt() > 10.);
}
