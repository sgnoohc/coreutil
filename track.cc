#include "track.h"

//########################################################################################
void CoreUtil::track::process()
{
    index.clear();
    for (size_t pfind = 0; pfind < cms3.pfcands_p4().size(); pfind++)
    {
        // Track selection criteria
        if (cms3.pfcands_charge().at(pfind)  == 0) { continue; }
        if (fabs(cms3.pfcands_dz()    .at(pfind)) >  0.1) { continue; }
        if (cms3.pfcands_fromPV().at(pfind)  <= 1) { continue; }
        float cand_pt = cms3.pfcands_p4().at(pfind).pt();
        if (cand_pt < 5) { continue; }
        float absiso03 = TrackIso(pfind, 0.3, 0.1, true, false);
        int  pdgId = abs(cms3.pfcands_particleId().at(pfind));
        if (absiso03 < min(0.2 * cand_pt, 8.0))
        {
            if ((cand_pt > 5.) && (pdgId == 11 || pdgId == 13))
            {
                if (absiso03 / cand_pt < 0.2)
                {
                    index.push_back(pfind);
                }
            }
            if (cand_pt > 10. && pdgId == 211)
            {
                if (absiso03 / cand_pt < 0.1)
                {
                    index.push_back(pfind);
                }
            }
        }
    }
}

//########################################################################################
// Ported from CORE because until we migrate completely to CMS4 there are some hacky things to accomodate mixing of CMS3 Data and CMS4 data
float CoreUtil::track::TrackIso(int thisPf, float coneR, float deltaZCut, bool useFromPV, bool useLeptons)
{
    if ((cms3.evt_isRealData() || cms3.evt_CMS3tag().at(0).Contains("08-00-16")) && !(cms3.evt_CMS3tag().at(0).Contains("CMS4")))
    {
        float absIso = 0.0;

        for (int ipf = 0; ipf < (int)cms3.pfcands_p4().size(); ipf++) {

            if( ipf == thisPf ) continue; // skip this PFCandidate
            if(cms3.pfcands_charge().at(ipf) == 0 ) continue; // skip neutrals
            double dr=ROOT::Math::VectorUtil::DeltaR( cms3.pfcands_p4().at(ipf) , cms3.pfcands_p4().at(thisPf) );
            if( dr > coneR ) continue; // skip pfcands outside the cone                                     
            if( cms3.pfcands_p4().at(ipf).pt()>=0.0 && (useLeptons || abs(cms3.pfcands_particleId().at(ipf)) == 211) && 
                    ( (fabs(cms3.pfcands_dz().at(ipf)) < deltaZCut) || (useFromPV && cms3.pfcands_fromPV().at(ipf) > 1)) )
                absIso += cms3.pfcands_p4().at(ipf).pt();

        }

        return absIso;
    }
    else
    {
        return cms3.pfcands_trackIso().at(thisPf);
    }
}
