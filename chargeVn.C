#include "../../style.h"
#include "label.h"

void chargeVn(int s1 = 2)
{
	SetStyle();

	TFile *f = new TFile(Form("%s/outGraph.root", ftxt[s1]));

	TGraphErrors * grV2 = (TGraphErrors*) f->Get("gr_vnCentGapC_2");
	TGraphErrors * grV3 = (TGraphErrors*) f->Get("gr_vnCentGapC_3");

	TGraphErrors * grV2n = (TGraphErrors*) f->Get("gr_vnCCentGapV_2_0");
	TGraphErrors * grV2p = (TGraphErrors*) f->Get("gr_vnCCentGapV_2_1");

	TGraphErrors * grV3n = (TGraphErrors*) f->Get("gr_vnCCentGapV_3_0");
	TGraphErrors * grV3p = (TGraphErrors*) f->Get("gr_vnCCentGapV_3_1");

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	grV2n->SetMarkerColor(kRed);
	grV2p->SetMarkerColor(kBlue);

	grV3n->SetMarkerColor(kRed);
	grV3p->SetMarkerColor(kBlue);

	TH2D * hframe_cent = new TH2D("hframe_cent", "", 1, 0, 100, 1, 0, 0.35);
	InitHist(hframe_cent, "Centrality", "v_{2}");
	hframe_cent->GetYaxis()->SetTitle(Form("v_{%i}",2));
	hframe_cent->Draw();

	grV2->Draw("psame");
	grV2n->Draw("psame");
	grV2p->Draw("psame");

	cT->SaveAs("v2.pdf");

	TCanvas * cT1 = MakeCanvas("cT1", "cT1", 600, 500);
	TH2D * hframe_Diff = new TH2D("hframe_Diff", "", 1, 0, 100, 1, -0.001, 0.001);
	InitHist(hframe_Diff, "Centrality", "v_{2}");
	hframe_Diff->GetYaxis()->SetTitle("Diff v_{2}");
	hframe_Diff->Draw();

	TGraphErrors * grV2n_diff = (TGraphErrors*) grV2n->Clone();
	TGraphErrors * grV2p_diff = (TGraphErrors*) grV2p->Clone();
	for ( int i = 0; i < grV2->GetN(); i++ ) {
		grV2n_diff->GetY()[i] -= grV2->GetY()[i];
		grV2p_diff->GetY()[i] -= grV2->GetY()[i];
	}
	grV2n_diff->Draw("psame");
	grV2p_diff->Draw("psame");

	cT1->SaveAs("v2diff.pdf");

	TCanvas * cT2 = MakeCanvas("cT2", "cT2", 600, 500);
	TH2D * hframe3_cent = new TH2D("hframe3_cent", "", 1, 0, 100, 1, 0, 0.35);
	InitHist(hframe3_cent, "Centrality", "v_{2}");
	hframe3_cent->GetYaxis()->SetTitle(Form("v_{%i}",3));
	hframe3_cent->Draw();

	grV3->Draw("psame");
	grV3n->Draw("psame");
	grV3p->Draw("psame");
	cT2->SaveAs("v3.pdf");

	TCanvas * cT3 = MakeCanvas("cT3", "cT3", 600, 500);
	TH2D * hframe3_Diff = new TH2D("hframe3_Diff", "", 1, 0, 100, 1, -0.001, 0.001);
	InitHist(hframe3_Diff, "Centrality", "v_{3}");
	hframe3_Diff->GetYaxis()->SetTitle("Diff v_{3}");
	hframe3_Diff->Draw();

	TGraphErrors * grV3n_diff = (TGraphErrors*) grV3n->Clone();
	TGraphErrors * grV3p_diff = (TGraphErrors*) grV3p->Clone();
	for ( int i = 0; i < grV3->GetN(); i++ ) {
		grV3n_diff->GetY()[i] -= grV3->GetY()[i];
		grV3p_diff->GetY()[i] -= grV3->GetY()[i];
	}
	grV3n_diff->Draw("psame");
	grV3p_diff->Draw("psame");

	cT3->SaveAs("v3diff.pdf");
}
