#include "genpart.h"

//##########################################################################################
void CoreUtil::genpart::process(std::function<bool(int)> pass)
{

    // If data event quit
    if (cms3.evt_isRealData())
        return;

    clear();

    for (unsigned int iGen = 0; iGen < cms3.genps_p4().size(); iGen++)
    {

        calcGenHT(iGen);

        // Basic cuts
        if (pass)
            if (!pass(iGen))
                continue;

        addGenParticleToVectors(iGen);

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
    genPart_mother_idx.clear();
    genPart_idx.clear();
    ngenPart = 0;
    ngenLep = 0;
    ngenLepFromTau = 0;
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
    genPart_charge.push_back(int(cms3.genps_charge()[iGen]));
    genPart_motherId.push_back(cms3.genps_id_simplemother()[iGen]);
    genPart_grandmaId.push_back(cms3.genps_id_simplegrandma()[iGen]);
    genPart_mother_idx.push_back(cms3.genps_idx_simplemother()[iGen]);
    genPart_idx.push_back(iGen);
    ngenPart++;
    if (cms3.genps_isMostlyLikePythia6Status3()[iGen])
        ngen_p6s3Part++;

    int pdgId = abs(cms3.genps_id()[iGen]);
    int status = cms3.genps_status()[iGen];
    int motherId = abs(cms3.genps_id_simplemother()[iGen]);
    int grandmaId = abs(cms3.genps_id_simplegrandma()[iGen]);

    // electrons, muons: status 1 or 23 and mother W/Z/H or tau from W/Z/H
    if ((pdgId == 11 || pdgId == 13) && (status == 1 || status == 23))
    {
        // save leptons pre-FSR: prefer status 23 over status 1
        if (status == 1 && motherId == pdgId && (cms3.genps_status().at(cms3.genps_idx_simplemother().at(iGen)) == 23))
        {
            // don't save
        }
        // leptons from taus
        else if (motherId == 15 && (grandmaId == 25 || grandmaId == 24 || grandmaId == 23 || grandmaId == 15))
        {
            ngenLepFromTau++;
        }
        // leptons from W/Z/H
        else if (motherId == 25 || motherId == 24 || motherId == 23)
        {
            ngenLep++;
        }
    } // status 1 e or mu
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
