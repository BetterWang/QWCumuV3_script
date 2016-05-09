#include "../../style.h"

char const * strSteveCent[8] = {
	"0 - 2%",
	"2 - 5%",
	"5 - 10%",
	"10 - 20%",
	"20 - 40%",
	"40 - 50%",
	"50 - 60%",
	"60 - 70%",
};

TGraphErrors * grV2[4][20];
TGraphErrors * grV2s[4][20];

double pTlimit[4][20] = 
{
	{0},
	// 0   1    2    3    4   5    6
	{ 14, 20,  80,  80,  100, 60, 40},
	{ 14, 20,  80,  80,  100, 60, 40},
	{ 14, 20,  80,  80,  100, 60, 40},
};


// < 14
double sys1[4][20] = {
	{0},
	// 0     1     2     3     4     5
	{0.06, 0.06, 0.06, 0.06, 0.06, 0.06},
	{0.06, 0.06, 0.06, 0.06, 0.06, 0.06},
	{0.06, 0.06, 0.06, 0.06, 0.06, 0.06},
};

// < 20
double sys2[4][20] = {
	{0},
	// 0     1     2     3     4     5
	{0.06, 0.06, 0.06, 0.06, 0.06, 0.06},
	{0.12, 0.12, 0.06, 0.06, 0.06, 0.06},
	{0.12, 0.12, 0.12, 0.06, 0.06, 0.06},
};

// < 26
double sys3[4][20] = {
	{0},
	// 0     1     2     3     4     5
	{0.08, 0.08, 0.08, 0.08, 0.08, 0.08},
	{0.12, 0.12, 0.12, 0.12, 0.08, 0.08},
	{0.12, 0.12, 0.12, 0.12, 0.08, 0.08},
};

// > 26
double sys4[4][20] = {
	{0},
	// 0     1     2     3     4     5
	{0.08, 0.08, 0.08, 0.08, 0.08, 0.08},
	{0.12, 0.12, 0.12, 0.12, 0.12, 0.12},
	{0.12, 0.12, 0.12, 0.12, 0.12, 0.12},
};


void fplot(TString s1 = "fresult2_62_57.root")
{
	TFile * f1 = new TFile(s1.Data());

	TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
	TColor *green = new TColor(3002, 0, 0.6, 0, "green", 0.4);
	TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);

	for ( int np = 1; np < 4; np++ ) {
		for ( int cent = 0; cent < 7; cent++ ) {
			grV2[np][cent] = (TGraphErrors*) f1->Get(Form("gr_V2%i_%i", 2*np+2, cent));
			//grV2[np][cent]->SetMarkerSize(1.2);
			for ( int i = 0; i < grV2[np][cent]->GetN(); i++ ) {
				if ( grV2[np][cent]->GetX()[i] > pTlimit[np][cent] ) {
					grV2[np][cent]->RemovePoint(i);
					i--;
				}
			}

			grV2s[np][cent] = (TGraphErrors*) grV2[np][cent]->Clone();
			for ( int i = 0; i < grV2s[np][cent]->GetN(); i++ ) {
				if ( grV2s[np][cent]->GetX()[i] < 14 ) {
					grV2s[np][cent]->GetEY()[i] = grV2s[np][cent]->GetY()[i] * sys1[np][cent];
				} else if ( grV2s[np][cent]->GetX()[i] < 20 ) {
					grV2s[np][cent]->GetEY()[i] = grV2s[np][cent]->GetY()[i] * sys2[np][cent];
				} else if ( grV2s[np][cent]->GetX()[i] < 26 ) {
					grV2s[np][cent]->GetEY()[i] = grV2s[np][cent]->GetY()[i] * sys3[np][cent];
				} else {
					grV2s[np][cent]->GetEY()[i] = grV2s[np][cent]->GetY()[i] * sys4[np][cent];
				}

				grV2s[np][cent]->GetEX()[i] = 2;
			}
			if ( np == 1 ) {
				grV2s[np][cent]->SetFillColor(3002);
			}
			if ( np == 2 ) {
				grV2s[np][cent]->SetFillColor(3003);
			}
			if ( np == 3 ) {
				grV2s[np][cent]->SetFillColor(3001);
			}
		}
	}

	SetStyle();

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);

	TCanvas * cT = MakeCanvas("cT", "cT", 1000, 500);
	makeMultiPanelCanvas(cT, 4, 2, 0.0, 0., 0.15, 0.15, 0.01);
	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0.1, 99, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");

	for ( int c = 0; c < 7; c++ ) {
		cT->cd(c+1);
		hframe_pt->Draw();

		grV2s[1][c]->Draw("[]3");
		grV2s[2][c]->Draw("[]3");
		grV2s[3][c]->Draw("[]3");

		grV2[1][c]->Draw("Psame");
		grV2[2][c]->Draw("Psame");
		grV2[3][c]->Draw("Psame");

		latex.DrawLatexNDC(0.4, 0.8, strSteveCent[c]);

	}
	cT->cd(8);
	hframe_pt->Draw();
	TLegend *legPt = new TLegend(0.2, 0.5, 0.8, 0.9);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(42);
	legPt->SetTextSize(0.1);
	legPt->SetBorderSize(0);
	legPt->AddEntry(grV2[1][1], "v_{2}{4}", "p");
	legPt->AddEntry(grV2[2][1], "v_{2}{6}", "p");
	legPt->AddEntry(grV2[3][1], "v_{2}{8}", "p");
	legPt->Draw();

	cT->SaveAs("cumu.pdf");

	TFile f("fsave.root", "recreate");
	for ( int np = 1; np < 4; np++ ) {
		for ( int c = 0; c < 7; c++ ) {
			grV2s[np][c]->SetName(Form("grV2%is_%i", np*2+2, c));
			grV2s[np][c]->SetTitle(Form("V2%i systematic %s", np*2+2, strSteveCent[c]));
			grV2s[np][c]->Write();

			grV2[np][c]->SetName(Form("grV2%i_%i", np*2+2, c));
			grV2[np][c]->SetTitle(Form("V2%i %s", np*2+2, strSteveCent[c]));
			grV2[np][c]->Write();
		}
	}
}


