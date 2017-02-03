#include "label.h"
#include "style.h"

void plotPA(int s1 = 4)
{
	SetStyle();
	TFile *f = new TFile(Form("%s/outGraph.root", ftxt[s1]));

	TGraphErrors * gr_vN2Gap[7] = {};
	TGraphErrors * gr_vN[7][4] = {};

	for ( int n = 2; n < 7; n++ ) {
		gr_vN2Gap[n] = (TGraphErrors*) f->Get(Form("gr_vnCentGapC_%i", n));
		gr_vN2Gap[n]->RemovePoint(0);
		gr_vN2Gap[n]->RemovePoint(0);
		gr_vN2Gap[n]->RemovePoint(0);
		gr_vN2Gap[n]->RemovePoint(0);
		gr_vN2Gap[n]->RemovePoint(0);
		gr_vN2Gap[n]->RemovePoint(0);
		for ( int np = 0; np < 4; np++ ) {
			gr_vN[n][np] = (TGraphErrors*) f->Get(Form("gr_vnCentC_%i_%i", n, np));
			gr_vN[n][np]->RemovePoint(0);
			gr_vN[n][np]->RemovePoint(0);
			gr_vN[n][np]->RemovePoint(0);
			gr_vN[n][np]->RemovePoint(0);
			gr_vN[n][np]->RemovePoint(0);
			gr_vN[n][np]->RemovePoint(0);
		}
	}

	TCanvas * cT = MakeCanvas("cT", "cT", 500, 500);
	TH2D * hframe_cent = new TH2D("hframe_cent", "CMS pPb 8 TeV", 1, 1, 380, 1, -0.049, 0.18);

	InitHist(hframe_cent, "N_{trk}^{offline}", "v_{n}");

	TLine * zero = new TLine(0, 0, 380, 0);
	zero->SetLineStyle(2);
	for ( int n = 2; n < 7; n++ ) {
		hframe_cent->SetYTitle(Form("v_{%i}", n));
		hframe_cent->Draw();
		zero->Draw();
		gr_vN2Gap[n]->Draw("Psame");
//		gr_vN[n][0]->Draw("Psame");
		gr_vN[n][1]->Draw("Psame");
		gr_vN[n][2]->Draw("Psame");
		gr_vN[n][3]->Draw("Psame");
		TLegend * legC = new TLegend(0.2, 0.7, 0.55, 0.9);
		legC->SetHeader("CMS pPb 8 TeV 0.3 < p_{T} < 3.0 GeV/c");
		legC->SetFillColor(kWhite);
		legC->SetTextFont(42);
		legC->SetTextSize(0.03);
		legC->SetBorderSize(0);
		legC->AddEntry(gr_vN2Gap[n], Form("v_{%i}{2, #Delta#eta>2.0}", n), "p");
		legC->AddEntry(gr_vN[n][1], Form("v_{%i}{4}", n), "p");
		legC->AddEntry(gr_vN[n][2], Form("v_{%i}{6}", n), "p");
		legC->AddEntry(gr_vN[n][3], Form("v_{%i}{8}", n), "p");
		legC->Draw();
		cT->SaveAs(Form("v%i.pdf", n));
	}

}
