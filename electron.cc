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
    if (!isTriggerSafenoIso_v1(i))            return false;
    if (fabs(cms3.els_etaSC().at(i)) > 2.5)   return false;
    if (cms3.els_exp_innerlayers().at(i) > 1) return false;
    if (fabs(cms3.els_ip3d().at(i)) >= 0.015) return false;
    float reliso = 0;
    std::cout.setstate(std::ios_base::failbit); // To suppress warning about CMS4 not having PF candidates
    if (cms3.evt_CMS3tag()[0].Contains("CMS3"))
        reliso = elRelIsoCustomCone(i, 0.4, false, 0.0, /*useDBCorr=*/false, /*useEACorr=*/true, /*mindr=*/ -1, /*eaversion=*/2);
    else
        reliso = eleRelIso03EA(i, 2);
    std::cout.clear();
    if (reliso >= 0.40) return false;
    return (cms3.els_p4()[i].pt() > 10.);
}
