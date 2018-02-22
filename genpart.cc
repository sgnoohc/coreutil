#include "genpart.h"

//##########################################################################################
void CoreUtil::genpart::process()
{

    // If data event quit
    if (cms3.evt_isRealData())
        return;

    clear();

    for (unsigned int iGen = 0; iGen < cms3.genps_p4().size(); iGen++)
    {

        addGenParticleToVectors(iGen);

        calcGenHT(iGen);

    }
}

//##########################################################################################
void CoreUtil::genpart::clear()
{

    genPart_p4.clear();
    genPart_pt.clear();
    genPart_eta.clear();
    genPart_phi.clear();
    //genPart_mass.clear();
    genPart_pdgId.clear();
    genPart_status.clear();
    genPart_isp6status3.clear();
    genPart_charge.clear();
    genPart_motherId.clear();
    genPart_grandmaId.clear();
    ngenPart = 0;
    ngen_p6s3Part = 0;

    gen_ht = 0;

}

//##########################################################################################
void CoreUtil::genpart::addGenParticleToVectors(int iGen)
{

    genPart_p4.push_back(cms3.genps_p4()[iGen]);
    genPart_pt.push_back(cms3.genps_p4()[iGen].pt());
    genPart_eta.push_back(cms3.genps_p4()[iGen].eta());
    genPart_phi.push_back(cms3.genps_p4()[iGen].phi());
    //genPart_mass.push_back(cms3.genps_mass()[iGen]);
    genPart_pdgId.push_back(cms3.genps_id()[iGen]);
    genPart_status.push_back(cms3.genps_status()[iGen]);
    genPart_isp6status3.push_back(cms3.genps_isMostlyLikePythia6Status3()[iGen]);
    genPart_charge.push_back(cms3.genps_charge()[iGen]);
    genPart_motherId.push_back(cms3.genps_id_simplemother()[iGen]);
    genPart_grandmaId.push_back(cms3.genps_id_simplegrandma()[iGen]);
    ngenPart++;
    if (cms3.genps_isMostlyLikePythia6Status3()[iGen])
        ngen_p6s3Part++;

}

//##########################################################################################
void CoreUtil::genpart::calcGenHT(int iGen)
{

    // calculate gen_ht for stitching purposes
    if ((abs(cms3.genps_id()[iGen]) <  6 || // quarks
                abs(cms3.genps_id()[iGen]) == 21)  // gluons
            && (cms3.genps_status()[iGen] == 22 || // something to do with "status 3"
                cms3.genps_status()[iGen] == 23))
    {
        gen_ht += cms3.genps_p4()[iGen].pt();
    }

}
