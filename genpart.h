#ifndef genpart_h
#define genpart_h

#include <vector>
#include <utility>

#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

#include "CMS3.h"

namespace CoreUtil
{
    class genpart
    {

        public:

            Int_t ngenPart;
            Int_t ngenLep;
            Int_t ngenLepFromBoson;
            Int_t ngenLepFromTau;
            Int_t ngen_p6s3Part;
            std::vector<LorentzVector> genPart_p4 ;
            std::vector<Float_t> genPart_pt;
            std::vector<Float_t> genPart_eta;
            std::vector<Float_t> genPart_phi;
            //std::vector<Float_t> genPart_mass;
            std::vector<Int_t> genPart_pdgId;
            std::vector<Int_t> genPart_status;
            std::vector<Bool_t> genPart_isp6status3;
            std::vector<Int_t> genPart_charge;
            std::vector<Int_t> genPart_motherId;
            std::vector<Int_t> genPart_grandmaId;
            std::vector<Int_t> genPart_mother_idx;
            std::vector<Int_t> genPart_idx;

            Float_t gen_ht; // Used for W+jets Z+jets HT sliced samples

            genpart() {}
            ~genpart() {}

            void process(std::function<bool(int)> pass=nullptr);
            void clear();
            void addGenParticleToVectors(int iGen);
            void calcGenHT(int iGen);

            // GenParticle print utility
            void printParticleOfInterest();
            static void printParticle(int i);
            static void printLorentzVector(LorentzVector i);
            void printPartonsWithCondition(TString message, std::function<bool(int)> pass=nullptr);

            static bool isIncomingParton    (int i) { if (cms3.genps_status().at(i) == 21) return true; else return false; }
            static bool isIntermediateParton(int i) { if (cms3.genps_status().at(i) == 22) return true; else return false; }
            static bool isOutgoingParton    (int i) { if (cms3.genps_status().at(i) == 23) return true; else return false; }
            static bool isLeptonFromBoson   (int i);
            static bool isNeutrinoFromBoson (int i);
            static bool isQuarkFromBoson    (int i);
            static bool isMotherFromBoson   (int i);

            static bool isStar(int i);

            void printIncomingPartons() { printPartonsWithCondition("== Incoming partons ==", isIncomingParton); }
            void printIntermediatePartons() { printPartonsWithCondition("== Intermediate partons ==", isIntermediateParton); }
            void printOutgoingPartons() { printPartonsWithCondition("== Outgoing partons ==", isOutgoingParton); }
            void printLeptonFromBosons() { printPartonsWithCondition("== Leptons from bosons ==", isLeptonFromBoson); }
            void printNeutrinoFromBosons() { printPartonsWithCondition("== Neutrinos from bosons ==", isNeutrinoFromBoson); }
            void printQuarkFromBosons() { printPartonsWithCondition("== Quarks from bosons ==", isQuarkFromBoson); }
            void printAllParticles() { printPartonsWithCondition("== All particles=="); }

            // Higgs reconstruction related
            class HiggsConstituent
            {
                public:
                HiggsConstituent() {}
                HiggsConstituent(int i)
                {
                    p4 = cms3.genps_p4()[i];
                    id = cms3.genps_id()[i];
                    idx = i;
                    islead = 0;
                    isstar = isStar(i);
                    motherid = -999;
                }
                LorentzVector p4;
                int id;
                int isstar;
                int islead;
                int idx;
                int motherid;
                void print() { printParticle(idx); }
            };

            class Higgs : public HiggsConstituent {
                public:
                std::vector<HiggsConstituent> HiggsDaughters;
                std::vector<HiggsConstituent> HiggsGrandDaughters;
                void addHiggsDaughters(int i, int j)
                {
//                    std::cout <<  " i: " << i <<  " j: " << j <<  std::endl;
                    HiggsConstituent ip(i);
                    HiggsConstituent jp(j);
                    HiggsDaughters.push_back(ip.p4.pt() > jp.p4.pt() ? ip : jp);
                    HiggsDaughters.push_back(ip.p4.pt() > jp.p4.pt() ? jp : ip);
                }
                void addHiggsGrandDaughters(int i, int j, int idx_parent)
                {
                    HiggsConstituent ip(i);
                    HiggsConstituent jp(j);
                    ip.islead = (id == 0) ? true : false;
                    jp.islead = (id == 0) ? true : false;
                    ip.motherid = HiggsDaughters[idx_parent].id;
                    jp.motherid = HiggsDaughters[idx_parent].id;
                    HiggsGrandDaughters.push_back(ip.p4.pt() > jp.p4.pt() ? ip : jp);
                    HiggsGrandDaughters.push_back(ip.p4.pt() > jp.p4.pt() ? jp : ip);
                }
            };

            // GenParticle tree reconstruction utility
            std::vector<Higgs> reconstructHWW(bool verbose=false);
            std::vector<Higgs> reconstructHWWlvjj(bool verbose=false);
            std::vector<Higgs> reconstructHbb();

            bool matchDecay(int iparent, int& ichild, int& jchild, int pid, std::function<bool(int, int)> ispairmatch=nullptr, bool verbose=false);
            static bool isPairPdgIDMatch(int id, int jd, std::vector<std::pair<int, int>> pairs);
            static bool isPairLeptonicWDecay(int id, int jd);
            static bool isPairHadronicWDecay(int id, int jd);
            static bool isPairLeptonicZDecay(int id, int jd);
            static bool isPairHadronicZDecay(int id, int jd);
            static bool isPairHiggsDecay(int id, int jd);
            static bool isPairHWWDecay(int id, int jd);
            static bool isPairHbbDecay(int id, int jd);


    };
}

#endif
