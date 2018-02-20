#include "electron.h"

//########################################################################################
void CoreUtil::electron::setup()
{

    cout << "Creating electron MVA instance" << endl;
    createAndInitMVA("MVAinput", true, false, 80); // for electrons

}

//########################################################################################
void CoreUtil::electron::process()
{

    // Clear the saved indices
    index.clear();

    for (unsigned int iEl = 0; iEl < cms3.els_p4().size(); iEl++)
    {

        // Basic cuts
        if (!pass(iEl))
            continue;

        // Save the indices
        index.push_back(iEl);

    }

}

//########################################################################################
bool CoreUtil::electron::pass(int i)
{
    return (isVetoElectronPOGspring16noIso_v1(i) || passElectronSelection_VVV(i, VVV_MVAbased_tight_noiso) && cms3.els_p4()[i].pt() > 10.);
}
