#include "label.h"
#include "noff.h"
#include "../../style.h"

void plotC(int s1=62)
{
	SetStyle();
	TFile * f = new TFile(Form("%s/outputE.root", ftxt[s1]));
	TH1D * hC24 = (TH1D*)f->Get("hC24");

	double X[200];
	double Y[200];
	double eY[200];
	for ( int i = 0; i < NCent4; i++ ) {
		X[i] = ( CentPbPb4[i] + CentPbPb4[i+1] ) / 4.;
		Y[i] = hC24->GetBinContent(i+1);
		eY[i] = hC24->GetBinError(i+1);
	}
	TGraphErrors * gr_C24 = new TGraphErrors(NCent4, X, Y, 0, eY);

	gr_C24->SetMarkerStyle(kFullSquare);
	gr_C24->SetMarkerColor(kGreen+2);
	gr_C24->SetLineColor(kGreen+2);

	TCanvas * cT = MakeCanvas("cT", "cT", 500, 500);
	TH2D * hframe = new TH2D("hframe", "", 1, 0.0, 5., 1, -0.000001, 0.000001);
	InitHist(hframe, "Centrality (%)", "c_{2}{4}");

	hframe->Draw();
	gr_C24->Draw("Psame");
	TLine *l0 = new TLine(0, 0, 5, 0);
	l0->Draw();

	cT->SaveAs("c24.pdf");

}
