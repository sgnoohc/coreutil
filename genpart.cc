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

//##########################################################################################
// Currently only support "HWWlvjj"
std::vector<CoreUtil::genpart::Higgs> CoreUtil::genpart::reconstructHWWlvjj()
{
    // Return object
    std::vector<Higgs> higgses;

    // Get all Higgs and create Higgs object
    // For Higgs get the status 62
    for (unsigned int idx = 0; idx < cms3.genps_p4().size(); idx++)
    {
//        printParticle(idx);
        if (abs(cms3.genps_id()[idx]) == 25 && cms3.genps_status()[idx] == 62)
        {
            Higgs higgs;
            higgs.p4 = cms3.genps_p4()[idx];
            higgs.id = 25;
            higgs.isstar = false;
            higgs.islead = false;
            higgs.idx = idx;
            higgses.push_back(higgs);
        }
    }

    for (unsigned int ih = 0; ih < higgses.size(); ih++)
    {
        int ichild = -1;
        int jchild = -1;
        if (matchDecay(higgses[ih].idx, ichild, jchild, 25, isPairHWWDecay))
            higgses[ih].addHiggsDaughters(ichild, jchild);
//        std::cout <<  " ichild: " << ichild <<  std::endl;
//        std::cout <<  " jchild: " << jchild <<  std::endl;
//        std::cout << " searching grand daughters " << std::endl;

        bool wlep_found = false;
        bool whad_found = false;
        for (unsigned int id = 0; id < higgses[ih].HiggsDaughters.size(); ++id)
        {
//            std::cout <<  " id: " << id <<  std::endl;
//            std::cout <<  " higgses[ih].HiggsDaughters[id].p4.mass(): " << higgses[ih].HiggsDaughters[id].p4.mass() <<  std::endl;
//            std::cout <<  " higgses[ih].HiggsDaughters[id].id: " << higgses[ih].HiggsDaughters[id].id <<  std::endl;
//            std::cout <<  " higgses[ih].HiggsDaughters[id].idx: " << higgses[ih].HiggsDaughters[id].idx <<  std::endl;
//            std::cout <<  " cms3.genps_p4()[higgses[ih].HiggsDaughters[id].idx].mass(): " << cms3.genps_p4()[higgses[ih].HiggsDaughters[id].idx].mass() <<  std::endl;
            int igrandchild = -1;
            int jgrandchild = -1;
            if (matchDecay(higgses[ih].HiggsDaughters[id].idx, igrandchild, jgrandchild, higgses[ih].HiggsDaughters[id].id, isPairLeptonicWDecay) && !wlep_found)
            //if (matchDecay(higgses[ih].HiggsDaughters[id].idx, igrandchild, jgrandchild, -999, isPairLeptonicWDecay))
            {
//                std::cout <<  " 'wlep_found': " << "wlep_found" <<  std::endl;
//                printParticle(igrandchild);
//                printParticle(jgrandchild);
//                std::cout <<  " wlep_found: " << wlep_found <<  std::endl;
                higgses[ih].addHiggsGrandDaughters(igrandchild, jgrandchild, id);
                wlep_found = true;
            }
            else if (matchDecay(higgses[ih].HiggsDaughters[id].idx, igrandchild, jgrandchild, higgses[ih].HiggsDaughters[id].id, isPairHadronicWDecay) && !whad_found)
            //else if (matchDecay(higgses[ih].HiggsDaughters[id].idx, igrandchild, jgrandchild, -999, isPairHadronicWDecay))
            {
//                std::cout <<  " 'whad_found': " << "whad_found" <<  std::endl;
//                printParticle(higgses[ih].HiggsDaughters[id].idx);
//                printParticle(igrandchild);
//                printParticle(jgrandchild);
//                std::cout <<  " whad_found: " << whad_found <<  std::endl;
                higgses[ih].addHiggsGrandDaughters(igrandchild, jgrandchild, id);
                whad_found = true;
            }
            else
            {
                std::cout <<  " higgses[ih].HiggsDaughters[id].idx: " << higgses[ih].HiggsDaughters[id].idx <<  std::endl;
                std::cout <<  " higgses[ih].HiggsDaughters[id].id: " << higgses[ih].HiggsDaughters[id].id <<  std::endl;
                higgses[ih].HiggsDaughters[id].print();
                std::cout << "did not find any" << std::endl;
                printAllParticles();
                exit(-1);
            }

        }
    }

    return higgses;
}

//##########################################################################################
// Currently only support "HWWlvjj"
std::vector<CoreUtil::genpart::Higgs> CoreUtil::genpart::reconstructHbb()
{
    // Return object
    std::vector<Higgs> higgses;

    // Get all Higgs and create Higgs object
    // For Higgs get the status 62
    for (unsigned int idx = 0; idx < cms3.genps_p4().size(); idx++)
    {
        if (abs(cms3.genps_id()[idx]) == 25 && cms3.genps_status()[idx] == 62)
        {
            Higgs higgs;
            higgs.p4 = cms3.genps_p4()[idx];
            higgs.id = 25;
            higgs.isstar = false;
            higgs.islead = false;
            higgs.idx = idx;
            higgses.push_back(higgs);
        }
    }

    for (unsigned int ih = 0; ih < higgses.size(); ih++)
    {
        int ichild = -1;
        int jchild = -1;
        if (matchDecay(higgses[ih].idx, ichild, jchild, 25, isPairHbbDecay))
            higgses[ih].addHiggsDaughters(ichild, jchild);
    }

    return higgses;
}

//##########################################################################################
bool CoreUtil::genpart::matchDecay(int iparent, int& ichild, int& jchild, int pid, std::function<bool(int, int)> ispairmatch)
{
    LorentzVector parent_p4 = cms3.genps_p4()[iparent];
    int parent_id = cms3.genps_id()[iparent];

    ichild = -1;
    jchild = -1;

    // Get particles with either mother or grandmother being 25 with status 22 and try to match

    // Loop over the gen particles
    for (unsigned int idx = 0; idx < cms3.genps_p4().size(); idx++)
    {

        // Set the i-th particle variables
        int motherid  = cms3.genps_id_simplemother()[idx];
        int grandmaid = cms3.genps_id_simplegrandma()[idx];
        int id        = cms3.genps_id()[idx];
        int status    = cms3.genps_status()[idx];

        // Check the iparticle is from whatever the parent i am looking for (if pid == -999, don't do anything)
        if (pid != -999 && (motherid != pid && grandmaid != pid))
            continue;

        // Set the i-th particle 4 vector
        LorentzVector ip4 = cms3.genps_p4()[idx];

        // Loop over the other leg of the decay
        for (unsigned int jdx = idx + 1; jdx < cms3.genps_p4().size(); jdx++)
        {

            // Set the j-th particle variable
            int j_motherid = cms3.genps_id_simplemother()[jdx];
            int j_grandmaid = cms3.genps_id_simplegrandma()[jdx];
            int j_id = cms3.genps_id()[jdx];
            int j_status = cms3.genps_status()[jdx];

            // Check the iparticle is from whatever the parent i am looking for (if pid == -999, don't do anything)
            if (pid != -999 && (j_motherid != pid && j_grandmaid != pid))
                continue;

            // Check the children id combo
            if (ispairmatch)
                if (!(ispairmatch(id, j_id)))
                    continue;

            // But require at least that the mother matches
            if (j_motherid != motherid)
                continue;

            // Require the mother is not some hadron
            if (abs(j_motherid) > 25 || abs(motherid) > 25)
                continue;

            //// check mother to be same as parent_id
            //if (abs(j_motherid) != parent_id && abs(motherid) != parent_id)
            //    continue;

            // Set the j-th particle 4 vector
            LorentzVector jp4 = cms3.genps_p4()[jdx];

//            printLorentzVector(ip4);
//            printLorentzVector(jp4);
//            printLorentzVector(parent_p4);
//            std::cout <<  " fabs((ip4+jp4).mass()): " << fabs((ip4+jp4).mass()) <<  " parent_p4.mass(): " << parent_p4.mass() <<  std::endl;
//            std::cout <<  " fabs((ip4+jp4).energy()): " << fabs((ip4+jp4).energy()) <<  " parent_p4.energy(): " << parent_p4.energy() <<  std::endl;
            //if ((fabs((ip4 + jp4).mass() - parent_p4.mass()) < 10) || ((fabs((ip4 + jp4).energy() - parent_p4.energy()) < 12) && (fabs((ip4 + jp4).mass() - parent_p4.mass()) < 30)))
            if ((fabs((ip4 + jp4).mass() - parent_p4.mass()) < 10))
            {

                if (ichild == -1 && jchild == -1)
                {
                    ichild = ip4.pt() > jp4.pt() ? idx : jdx;
                    jchild = ip4.pt() > jp4.pt() ? jdx : idx;
                    break;
                }
            }
        }
        if (ichild != -1 && jchild != -1)
            break;
    }
    if (ichild != -1 && jchild != -1)
        return true;
    else
        return false;
}

//##########################################################################################
bool CoreUtil::genpart::isPairLeptonicWDecay(int id, int jd)
{
    std::vector<std::pair<int, int>> pairs;
    pairs.push_back(make_pair(11, -12));
    pairs.push_back(make_pair(13, -14));
    pairs.push_back(make_pair(15, -16));
    pairs.push_back(make_pair(-11, 12));
    pairs.push_back(make_pair(-13, 14));
    pairs.push_back(make_pair(-15, 16));
    return isPairPdgIDMatch(id, jd, pairs);
}

//##########################################################################################
bool CoreUtil::genpart::isPairHadronicWDecay(int id, int jd)
{
    // 2 4 6
    // 1 3 5
    std::vector<std::pair<int, int>> pairs;
    pairs.push_back(make_pair(1, -2));
    pairs.push_back(make_pair(1, -4));
    pairs.push_back(make_pair(2, -1));
    pairs.push_back(make_pair(2, -3));
    pairs.push_back(make_pair(2, -5));
    pairs.push_back(make_pair(3, -2));
    pairs.push_back(make_pair(3, -4));
    pairs.push_back(make_pair(4, -1));
    pairs.push_back(make_pair(4, -3));
    pairs.push_back(make_pair(4, -5));
    pairs.push_back(make_pair(5, -2));
    pairs.push_back(make_pair(5, -4));
    return isPairPdgIDMatch(id, jd, pairs);
}

//##########################################################################################
bool CoreUtil::genpart::isPairHWWDecay(int id, int jd)
{
    std::vector<std::pair<int, int>> pairs;
    pairs.push_back(make_pair(24, -24));
    return isPairPdgIDMatch(id, jd, pairs);
}

//##########################################################################################
bool CoreUtil::genpart::isPairHbbDecay(int id, int jd)
{
    std::vector<std::pair<int, int>> pairs;
    pairs.push_back(make_pair(5, -5));
    return isPairPdgIDMatch(id, jd, pairs);
}


//##########################################################################################
bool CoreUtil::genpart::isPairHiggsDecay(int id, int jd)
{
    std::vector<std::pair<int, int>> pairs;
    pairs.push_back(make_pair(1, -1));
    pairs.push_back(make_pair(2, -2));
    pairs.push_back(make_pair(3, -3));
    pairs.push_back(make_pair(4, -4));
    pairs.push_back(make_pair(5, -5));
    pairs.push_back(make_pair(6, -6));
    pairs.push_back(make_pair(11, -11));
    pairs.push_back(make_pair(13, -13));
    pairs.push_back(make_pair(15, -15));
    pairs.push_back(make_pair(21, 21));
    pairs.push_back(make_pair(22, 22));
    pairs.push_back(make_pair(23, 23));
    pairs.push_back(make_pair(24, -24));
    return isPairPdgIDMatch(id, jd, pairs);
}

//##########################################################################################
bool CoreUtil::genpart::isPairPdgIDMatch(int id, int jd, std::vector<std::pair<int, int>> pairs)
{
    for (unsigned ipair = 0; ipair < pairs.size(); ++ipair)
    {
        if (id == pairs[ipair].first && jd == pairs[ipair].second)
            return true;
        if (jd == pairs[ipair].first && id == pairs[ipair].second)
            return true;
    }
    return false;
}

//##########################################################################################
// The motivation is driven by Higgs decay going off-shell
// Not necessarily intended for SUSY or others
bool CoreUtil::genpart::isStar(int i)
{
    int absid = abs(cms3.genps_id()[i]);
    switch (absid)
    {
        case 24: if (cms3.genps_p4()[i].mass() < 62.5           ) return true; break;
        case 23: if (abs(cms3.genps_p4()[i].mass() - 90.) > 27.5) return true; break;
    }
    return false;
}


//##########################################################################################
bool CoreUtil::genpart::isMotherFromBoson(int i)
{
    if (abs(cms3.genps_id_simplegrandma().at(i)) == 23)
        return true;
    if (abs(cms3.genps_id_simplegrandma().at(i)) == 24)
        return true;
    if (abs(cms3.genps_id_simplegrandma().at(i)) == 25)
        return true;
    return false;
}

//##########################################################################################
bool CoreUtil::genpart::isLeptonFromBoson(int i)
{
    if (cms3.genps_status().at(i) == 1 && (abs(cms3.genps_id().at(i)) == 11 || abs(cms3.genps_id().at(i)) == 13) && isMotherFromBoson(i))
        return true;
    if (cms3.genps_status().at(i) == 23 && (abs(cms3.genps_id().at(i)) == 15) && isMotherFromBoson(i))
        return true;
    return false;
}

//##########################################################################################
bool CoreUtil::genpart::isNeutrinoFromBoson(int i)
{
    if (cms3.genps_status().at(i) == 1 && (abs(cms3.genps_id().at(i)) == 12 || abs(cms3.genps_id().at(i)) == 14 || abs(cms3.genps_id().at(i)) == 16) && isMotherFromBoson(i))
        return true;
    return false;
}

//##########################################################################################
bool CoreUtil::genpart::isQuarkFromBoson(int i)
{
    if (
            (abs(cms3.genps_id().at(i)) >= 1 && abs(cms3.genps_id().at(i)) <= 5)
            && (cms3.genps_status().at(i) == 23 || cms3.genps_status().at(i) == 1)
            && (abs(cms3.genps_id_simplemother().at(i)) == 24 || abs(cms3.genps_id_simplemother().at(i)) == 23 || abs(cms3.genps_id_simplemother().at(i)) == 25)
       )
        return true;
    return false;
}

//##########################################################################################
void CoreUtil::genpart::printParticleOfInterest()
{
    printIncomingPartons();
    printIntermediatePartons();
    printOutgoingPartons();
    printLeptonFromBosons();
    printNeutrinoFromBosons();
    printQuarkFromBosons();
}

//##########################################################################################
void CoreUtil::genpart::printPartonsWithCondition(TString message, std::function<bool(int)> pass)
{
    std::cout << message << std::endl;
    for (unsigned int i = 0; i < genPart_idx.size(); ++i)
    {
        int idx = genPart_idx.at(i);
        if (pass)
        {
            if (pass(idx))
                printParticle(idx);
        }
        else
        {
            printParticle(idx);
        }
    }
}


//##########################################################################################
void CoreUtil::genpart::printParticle(int i)
{
    int pdgId = cms3.genps_id()[i];
    int status = cms3.genps_status()[i];
    int motherId = cms3.genps_id_simplemother()[i];
    int grandmaId = cms3.genps_id_simplegrandma()[i];
    LorentzVector p4 = cms3.genps_p4()[i];
    printf("pdgId: %6d motherId: %6d grandmaId: %6d status: %4d p4.pt(): %8.3f p4.eta(): %8.3f p4.phi(): %8.3f p4.mass(): %8.3f p4.energy(): %8.3f\n",
            pdgId, motherId, grandmaId, status, p4.pt(), p4.eta(), p4.phi(), p4.mass(), p4.energy());
//    std::cout <<  " pdgId: " << pdgId <<  " motherId: " << motherId <<  " grandmaId: " << grandmaId <<  " status: " << status <<  " p4.pt(): " << p4.pt() <<  " p4.eta(): " << p4.eta() <<  " p4.phi(): " << p4.phi() <<  std::endl;
}

//##########################################################################################
void CoreUtil::genpart::printLorentzVector(LorentzVector i)
{
    std::cout <<  " i.pt(): " << i.pt() <<  " i.eta(): " << i.eta() <<  " i.phi(): " << i.phi() <<  " i.mass(): " << i.mass() <<  " i.energy(): " << i.energy() <<  std::endl;
}
