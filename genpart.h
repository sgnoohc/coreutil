#ifndef genpart_h
#define genpart_h

#include <vector>

#include "Math/LorentzVector.h"

#include "CMS3.h"

namespace CoreUtil
{
    class genpart
    {

        public:

            Int_t ngenPart;
            Int_t ngenLep;
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


    };
}

#endif
