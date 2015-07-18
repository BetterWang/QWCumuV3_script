{
#include "label.h"
	int s0 = 196;
	int s1 = 197;
	int s2 = 198;
	int s3 = 199;
	int s4 = 200;
	int s5 = 201;

//	int s0 = 205;
//	int s1 = 209;
//	int s2 = 213;
//	int s3 = 217;
//	int s4 = 221;
//	int s5 = 225;

	int sn = 2;

	int b2 = 1;
	int b4 = 1;
	int b6 = 0;
	int b8 = 0;

	int cent4 = 5;
	// 7 = 120 - 150;
	// 6 = 150 - 185;
	// 5 = 185 - 220;
	// 4 = 220 - 260;
	int cent6 = 6;
	int cent8 = 5;
	if ( cent4 == 6 ) {
		cent6 = 5;
		cent8 = 4;
	}
	if ( cent4 == 5 ) {
		cent6 = 4;
		cent8 = 3;
	}
	if ( cent4 == 4 ) {
		cent6 = 3;
		cent8 = 2;
	}
	if ( cent4 == 3 ) {
		cent6 = 2;
		cent8 = 1;
	}

	TString strNoff;
	if (cent4 == 3) strNoff = "#bf{260 #leq N_{trk}^{offline} < 300}";
	if (cent4 == 4) strNoff = "#bf{220 #leq N_{trk}^{offline} < 260}";
	if (cent4 == 5) strNoff = "#bf{185 #leq N_{trk}^{offline} < 220}";
	if (cent4 == 6) strNoff = "#bf{150 #leq N_{trk}^{offline} < 185}";
	if (cent4 == 7) strNoff = "#bf{120 #leq N_{trk}^{offline} < 150}";

#include "../../style.h"
	SetStyle();

	TFile *f[8];
	f[0] = new TFile(Form("%s/outputE.root", ftxt[s0]));
	f[1] = new TFile(Form("%s/outputE.root", ftxt[s1]));
	f[2] = new TFile(Form("%s/outputE.root", ftxt[s2]));
	f[3] = new TFile(Form("%s/outputE.root", ftxt[s3]));
	f[4] = new TFile(Form("%s/outputE.root", ftxt[s4]));
	f[5] = new TFile(Form("%s/outputE.root", ftxt[s5]));

	TH1D * hV[7][4][6] = {};
	TH1D * hC[7][4][6] = {};

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int eta = 0; eta < 6; eta++ ) {
				hV[n][np][eta] = (TH1D*)f[eta]->Get(Form("hcV%i%i", n, 2+2*np));
				hC[n][np][eta] = (TH1D*)f[eta]->Get(Form("hC%i%i", n, 2+2*np));
			}
		}
	}

	double dVn[4][8][20];
	double eVn[4][8][20];

	double dCn[4][8][20];
	double eCn[4][8][20];

	for ( int np = 0; np < 4; np++ ) {
		for ( int eta = 0; eta < 6; eta++ ) {
			for ( int i = 0; i < 20; i++ ) {
				dVn[np][eta][i] = hV[sn][np][eta]->GetBinContent(i+1);
				eVn[np][eta][i] = hV[sn][np][eta]->GetBinError(i+1);
				dCn[np][eta][i] = hC[sn][np][eta]->GetBinContent(i+1);
				eCn[np][eta][i] = hC[sn][np][eta]->GetBinError(i+1);
			}
		}
	}

	TGraphErrors * grVn[4][20] = {};
	TGraphErrors * grCn[4][20] = {};

	double Xeta[6] = {2.0, 1.2, 0.4, -0.4, -1.2, -2.0};
	double Y[6];
	double eY[6];
	double C[6];
	double eC[6];

	for ( int np = 0; np < 4; np++ ) {
		for ( int c = 0; c < 20; c++ ) {
			for ( int i = 0; i < 6; i++ ) {
				Y[i] = dVn[np][i][c];
				eY[i] = eVn[np][i][c];
				C[i] = dCn[np][i][c];
				eC[i] = eCn[np][i][c];
			}
			grVn[np][c] = new TGraphErrors(6, Xeta, Y, 0, eY);
			grCn[np][c] = new TGraphErrors(6, Xeta, C, 0, eC);
		}
	}
	for ( int c = 0; c < 20; c++ ) {
		grVn[0][c]->SetMarkerStyle(kOpenCircle);
		grVn[1][c]->SetMarkerStyle(kOpenSquare);
		grVn[2][c]->SetMarkerStyle(kFullCross);
		grVn[3][c]->SetMarkerStyle(kFullDiamond);

		grVn[0][c]->SetMarkerColor(kRed);
		grVn[1][c]->SetMarkerColor(kBlue);
		grVn[2][c]->SetMarkerColor(kBlue);
		grVn[3][c]->SetMarkerColor(kRed);

		grVn[0][c]->SetLineColor(kRed);
		grVn[1][c]->SetLineColor(kBlue);
		grVn[2][c]->SetLineColor(kBlue);
		grVn[3][c]->SetLineColor(kRed);

		grCn[0][c]->SetMarkerStyle(kOpenCircle);
		grCn[1][c]->SetMarkerStyle(kOpenSquare);
		grCn[2][c]->SetMarkerStyle(kFullCross);
		grCn[3][c]->SetMarkerStyle(kFullDiamond);

		grCn[0][c]->SetMarkerColor(kRed);
		grCn[1][c]->SetMarkerColor(kBlue);
		grCn[2][c]->SetMarkerColor(kBlue);
		grCn[3][c]->SetMarkerColor(kRed);

		grCn[0][c]->SetLineColor(kRed);
		grCn[1][c]->SetLineColor(kBlue);
		grCn[2][c]->SetLineColor(kBlue);
		grCn[3][c]->SetLineColor(kRed);
	}

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);
	cT->SetTopMargin(0.04);

	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.5, 2.5, 1, 0, 0.15);
	InitHist(hframe_eta, "#eta", "v_{2}");

	hframe_eta->Draw();
	if ( b2 ) grVn[0][cent4]->Draw("Psame");
	if ( b4 ) grVn[1][cent4]->Draw("Psame");
	if ( b6 ) grVn[2][cent6]->Draw("Psame");
	if ( b8 ) grVn[3][cent8]->Draw("Psame");

	TLegend * legV2 = new TLegend(0.2, 0.8, 0.3, 0.95);
	legV2->SetFillColor(kWhite);
	legV2->SetTextFont(42);
	legV2->SetTextSize(0.06);
	legV2->SetBorderSize(0);
	if ( b2 ) legV2->AddEntry(grVn[0][cent4], "v_{2}{2}", "p");
	if ( b4 ) legV2->AddEntry(grVn[1][cent4], "v_{2}{4}", "p");
	if ( b6 ) legV2->AddEntry(grVn[2][cent4], "v_{2}{6}", "p");
	if ( b8 ) legV2->AddEntry(grVn[3][cent4], "v_{2}{8}", "p");

	legV2->Draw();

	latex.DrawLatexNDC(0.18, 0.27, strNoff);

	TCanvas * cC = MakeCanvas("cC", "cC", 600, 500);
	cT->SetTopMargin(0.04);

	TH2D * hframe_etaC = new TH2D("hframe_etaC", "", 1, -2.5, 2.5, 1, -0.000018, 0.000018);
	InitHist(hframe_etaC, "#eta", "c_{2}{4}");

	TLine line(-2.5, 0, 2.5, 0);
	line.SetLineStyle(kDashed);

	hframe_etaC->Draw();
	line.Draw();
//	if ( b2 ) grCn[0][cent4]->Draw("Psame");
	if ( b4 ) grCn[1][cent4]->Draw("Psame");
//	if ( b6 ) grCn[2][cent6]->Draw("Psame");
//	if ( b8 ) grCn[3][cent8]->Draw("Psame");

	TLegend * legC2 = new TLegend(0.2, 0.75, 0.5, 0.9);
	legC2->SetFillColor(kWhite);
	legC2->SetTextFont(42);
	legC2->SetTextSize(0.06);
	legC2->SetBorderSize(0);

	legC2->AddEntry(grCn[1][cent4], "c_{2}{4}", "p");
	legC2->Draw();

	latex.DrawLatexNDC(0.58, 0.27, strNoff);

	cT->SaveAs(Form("V2pA_rfp_eta_%i.pdf", cent4));
	cC->SaveAs(Form("C2pA_rfp_eta_%i.pdf", cent4));

//	grCn[1][3]->SetMarkerStyle(kOpenCircle);
//	grCn[1][4]->SetMarkerStyle(kOpenSquare);
//	grCn[1][5]->SetMarkerStyle(kOpenCircle);
//	grCn[1][6]->SetMarkerStyle(kOpenSquare);
//	grCn[1][7]->SetMarkerStyle(kOpenDiamond);
//
//	grCn[1][3]->SetMarkerColor(kBlue);
//	grCn[1][4]->SetMarkerColor(kRed);
//	grCn[1][5]->SetMarkerColor(kBlack);
//	grCn[1][6]->SetMarkerColor(kBlue);
//	grCn[1][7]->SetMarkerColor(kRed);
//
//	grCn[1][3]->SetLineColor(kBlue);
//	grCn[1][4]->SetLineColor(kRed);
//	grCn[1][5]->SetLineColor(kBlack);
//	grCn[1][6]->SetLineColor(kBlue);
//	grCn[1][7]->SetLineColor(kRed);
//
//
//	hframe_etaC->Draw();
//	line.Draw();
//	grCn[1][3]->Draw("Psame");
//	grCn[1][4]->Draw("Psame");
//	grCn[1][5]->Draw("Psame");
//	grCn[1][6]->Draw("Psame");
//	grCn[1][7]->Draw("Psame");
}
