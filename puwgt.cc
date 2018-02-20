#include "puwgt.h"

void CoreUtil::puwgt::setup()
{
    h_vtxweight = NULL;
    f_vtx = NULL;
    f_vtx = TFile::Open("puWeight2016.root", "READ");
    h_vtxweight = (TH1F*)f_vtx->Get("pileupWeight")->Clone("h_vtxweight");
}

float CoreUtil::puwgt::getPUWgt(int nTrueInt)
{
    return h_vtxweight->GetBinContent(h_vtxweight->FindBin(nTrueInt));
}
