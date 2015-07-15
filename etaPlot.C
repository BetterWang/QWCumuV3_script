{
#include "label.h"
//	int s0 = 188;
//	int s1 = 189;
//	int s2 = 190;
//	int s3 = 191;
//	int s4 = 192;
//	int s5 = 193;
//	int s6 = 194;
//	int s7 = 195;

	int s0 = 159;
	int s1 = 163;
	int s2 = 167;
	int s3 = 171;
	int s4 = 175;
	int s5 = 179;
	int s6 = 183;
	int s7 = 187;

	int sn = 2;

	int b2 = 1;
	int b4 = 1;
	int b6 = 0;
	int b8 = 0;

	int cent4 = 3;
	// 7 = 120 - 150;
	// 6 = 150 - 185;
	// 5 = 185 - 220;
	// 4 = 220 - 260;
	// 3 = 260 - 300;
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


#include "../../style.h"
	SetStyle();

	TFile *f[8];
	f[0] = new TFile(Form("%s/outputE.root", ftxt[s0]));
	f[1] = new TFile(Form("%s/outputE.root", ftxt[s1]));
	f[2] = new TFile(Form("%s/outputE.root", ftxt[s2]));
	f[3] = new TFile(Form("%s/outputE.root", ftxt[s3]));
	f[4] = new TFile(Form("%s/outputE.root", ftxt[s4]));
	f[5] = new TFile(Form("%s/outputE.root", ftxt[s5]));
	f[6] = new TFile(Form("%s/outputE.root", ftxt[s6]));
	f[7] = new TFile(Form("%s/outputE.root", ftxt[s7]));

	TH1D * hV[7][4][8] = {};
	TH1D * hC[7][4][8] = {};

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int eta = 0; eta < 8; eta++ ) {
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
		for ( int eta = 0; eta < 8; eta++ ) {
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

	double Xeta[8] = {2.1, 1.5, 0.9, 0.3, -0.3, -0.9, -1.5, -2.1};
	double Y[8];
	double eY[8];
	double C[8];
	double eC[8];

	for ( int np = 0; np < 4; np++ ) {
		for ( int c = 0; c < 20; c++ ) {
			for ( int i = 0; i < 8; i++ ) {
				Y[i] = dVn[np][i][c];
				eY[i] = eVn[np][i][c];
				C[i] = dCn[np][i][c];
				eC[i] = eCn[np][i][c];
			}
			grVn[np][c] = new TGraphErrors(8, Xeta, Y, 0, eY);
			grCn[np][c] = new TGraphErrors(8, Xeta, C, 0, eC);
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

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.5, 2.5, 1, 0, 0.15);
	InitHist(hframe_eta, "#eta", "v_{2}");

	hframe_eta->Draw();
	if ( b2 ) grVn[0][cent4]->Draw("Psame");
	if ( b4 ) grVn[1][cent4]->Draw("Psame");
	if ( b6 ) grVn[2][cent6]->Draw("Psame");
	if ( b8 ) grVn[3][cent8]->Draw("Psame");

	TCanvas * cC = MakeCanvas("cC", "cC", 600, 500);

	TH2D * hframe_etaC = new TH2D("hframe_etaC", "", 1, -2.5, 2.5, 1, -0.000058, 0.000058);
	InitHist(hframe_etaC, "#eta", "c_{2}");

	TLine line(-2.5, 0, 2.5, 0);
	line.SetLineStyle(kDashed);

	hframe_etaC->Draw();
	line.Draw();
//	if ( b2 ) grCn[0][cent4]->Draw("Psame");
	if ( b4 ) grCn[1][cent4]->Draw("Psame");
//	if ( b6 ) grCn[2][cent6]->Draw("Psame");
//	if ( b8 ) grCn[3][cent8]->Draw("Psame");

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
