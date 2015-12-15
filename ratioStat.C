{
#include "helper.h"

	TGraphErrors * gr_RatioEta_p[20] = {};
	TGraphErrors * gr_RatioEta_Pb[20] = {};
	gROOT->Macro("EP.C");

	TFile *fsave = new TFile(Form("ratioGr_%i_%i.root", nCut, bPbPb), "recreate");
	for ( int i = 3; i < 8; i++ ) {
		gr_RatioEta_p[i] = makeRatioPt(gr_v2p_SP_de[i], gr_v2p_EP_de[i], 0, 12);
		gr_RatioEta_Pb[i] = makeRatioPt(gr_v2Pb_SP_de[i], gr_v2Pb_EP_de[i], 0, 12);
		gr_RatioEta_p[i]->SetName(Form("gr_RatioEta_p_%i", i));
		gr_RatioEta_p[i]->Write();
		gr_RatioEta_Pb[i]->SetName(Form("gr_RatioEta_Pb_%i", i));
		gr_RatioEta_Pb[i]->Write();
	}
}
