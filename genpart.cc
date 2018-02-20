#include "genpart.h"

//##########################################################################################
void CoreUtil::genpart::process()
{

    // If data event quit
    if (tas::evt_isRealData())
        return;

    for (iGen = 0; iGen < tas::genps_p4().size(); iGen++)
    {

        clearVectors();

        addGenParticleToVectors();

        calcGenHT();

    }
}

//##########################################################################################
void CoreUtil::genpart::clearVectors()
{

    genPart_p4.clear();
    genPart_pt.clear();
    genPart_eta.clear();
    genPart_phi.clear();
    genPart_mass.clear();
    genPart_pdgId.clear();
    genPart_status.clear();
    genPart_isp6status3.clear();
    genPart_charge.clear();
    genPart_motherId.clear();
    genPart_grandmaId.clear();
    ngenPart = 0;
    ngen_p6s3Part = 0;

}

//##########################################################################################
void CoreUtil::genpart::addGenParticleToVectors()
{

    genPart_p4.push_back(tas::genps_p4().at(iGen));
    genPart_pt.push_back(tas::genps_p4().at(iGen).pt());
    genPart_eta.push_back(tas::genps_p4().at(iGen).eta());
    genPart_phi.push_back(tas::genps_p4().at(iGen).phi());
    genPart_mass.push_back(tas::genps_mass().at(iGen));
    genPart_pdgId.push_back(tas::genps_id().at(iGen));
    genPart_status.push_back(tas::genps_status().at(iGen));
    genPart_isp6status3.push_back(tas::genps_isMostlyLikePythia6Status3().at(iGen));
    genPart_charge.push_back(tas::genps_charge().at(iGen));
    genPart_motherId.push_back(tas::genps_id_simplemother().at(iGen));
    genPart_grandmaId.push_back(tas::genps_id_simplegrandma().at(iGen));
    ngenPart++;
    if (tas::genps_isMostlyLikePythia6Status3().at(iGen))
        ngen_p6s3Part++;

}

//##########################################################################################
void CoreUtil::genpart::calcGenHT()
{

    // calculate gen_ht for stitching purposes
    if ((abs(tas::genps_id().at(iGen)) <  6 || // quarks
                abs(tas::genps_id().at(iGen)) == 21)  // gluons
            && (tas::genps_status().at(iGen) == 22 || // something to do with "status 3"
                tas::genps_status().at(iGen) == 23))
    {
        gen_ht += tas::genps_p4().at(iGen).pt();
    }

}
