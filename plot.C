#include "style.h"
#include "DataPoints.C"
//#include "QuanCumu.C"

void plot()
{
	DataPoints();
///	QuanCumu();

	SetStyle();

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);

	TCanvas * cT = MakeCanvas("cT", "cT", 1000, 500);
	makeMultiPanelCanvas(cT, 4, 2, 0.0, 0., 0.15, 0.15, 0.01);
	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0.1, 99, 1, -0.15, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{n}");

	TLine * zero = new TLine(0, 0, 100, 0);
	TLine * one = new TLine(0, 1, 100, 1);

	for ( int c = 0; c < 7; c++ ) {
		cT->cd(c+1);
		hframe_pt->Draw();

		zero->Draw();
		grSteveSPv2[c]->Draw("Psame");

		latex.DrawLatexNDC(0.2, 0.9, strSteveCent[c]);
	}
	for ( int c = 0; c < 6; c++ ) {
		cT->cd(c+1);
		grSteveSPv3[c]->Draw("Psame");
	}

//	for ( int c = 1; c < 6; c++ ) {
//		cT->cd(c+1);
//		mgrQuanCumu[1][c]->Draw();
//		mgrQuanCumu[2][c]->Draw();
//		mgrQuanCumu[3][c]->Draw();
//	}

	cT->cd(8);
	hframe_pt->Draw();

	TLegend *legPt = new TLegend(0.2, 0.35, 0.8, 0.85);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(42);
	legPt->SetTextSize(0.08);
	legPt->SetBorderSize(0);
	legPt->AddEntry(grSteveSPv2[1], "v_{2}{SP}", "p");
	legPt->AddEntry(grSteveSPv3[1], "v_{3}{SP}", "p");
	legPt->Draw();

//	legPt->AddEntry(grQuanCumu[1][1], "v_{2}{4}", "p");
//	legPt->AddEntry(grQuanCumu[2][1], "v_{2}{6}", "p");
//	legPt->AddEntry(grQuanCumu[3][1], "v_{2}{8}", "p");

	cT->SaveAs("final_SPvn.pdf");

	/////////////////////////////////////

	cT = MakeCanvas("cTx", "cTx", 1000, 500);
	makeMultiPanelCanvas(cT, 4, 2, 0.0, 0., 0.15, 0.15, 0.01);
	for ( int c = 0; c < 7; c++ ) {
		cT->cd(c+1);
		hframe_pt->Draw();

		zero->Draw();
		grSteveSPv2[c]->Draw("Psame");
		if ( mgrQuanCumu[1][c] != 0 ) {
			mgrQuanCumu[1][c]->Draw();
			mgrQuanCumu[2][c]->Draw();
			mgrQuanCumu[3][c]->Draw();
		}
		latex.DrawLatexNDC(0.2, 0.9, strSteveCent[c]);
	}
	cT->cd(8);
	hframe_pt->Draw();
	TLegend *legPt1 = new TLegend(0.2, 0.35, 0.8, 0.85);
	legPt1->SetFillColor(kWhite);
	legPt1->SetTextFont(42);
	legPt1->SetTextSize(0.08);
	legPt1->SetBorderSize(0);
	legPt1->AddEntry(grSteveSPv2[1], "v_{2}{SP}", "p");
	legPt1->AddEntry(grQuanCumu[1][1], "v_{2}{4}", "p");
	legPt1->AddEntry(grQuanCumu[2][1], "v_{2}{6}", "p");
	legPt1->AddEntry(grQuanCumu[3][1], "v_{2}{8}", "p");
	legPt1->Draw();

	cT->SaveAs("final_v2.pdf");


	//////////////////////////////////////////////
	cT = new TCanvas("cT4", "cT4", 800, 800);
	cT->SetLeftMargin(0.15);
	cT->SetRightMargin(0.01);
	cT->SetTopMargin(0.01);
	TH2D * hframe_V2HiLow = new TH2D("hframe_V2HiLow", ";v_{2} (1.0 < p_{T} < 1.25 GeV/c);v_{2} high-p_{T}", 1, 0., 0.19, 1, 0.01, 0.19);
	hframe_V2HiLow->GetXaxis()->CenterTitle();
	hframe_V2HiLow->GetYaxis()->CenterTitle();

	hframe_V2HiLow->GetXaxis()->SetLabelSize(0.05);
	hframe_V2HiLow->GetYaxis()->SetLabelSize(0.05);

	hframe_V2HiLow->GetXaxis()->SetTitleSize(0.05);
	hframe_V2HiLow->GetYaxis()->SetTitleSize(0.05);

	hframe_V2HiLow->GetXaxis()->SetTitleOffset(1.5);
	hframe_V2HiLow->GetYaxis()->SetTitleOffset(1.5);

	hframe_V2HiLow->Draw();

	double XSP0[8], XSP0e[8];
	double YSP13[8], YSP13e[8];
	double YSP15[8], YSP15e[8];
	double YSP16[8], YSP16e[8];

	double XCumu0[8],  XCumu0e[8];
	double YCumu13[8], YCumu13e[8];
	double YCumu15[8], YCumu15e[8];
	double YCumu16[8], YCumu16e[8];

	for ( int c = 0; c < 8; c++ ) {
		XSP0[c] = grSteveSPv2[c]->GetY()[0];
		XSP0e[c] = grSteveSPv2[c]->GetEY()[0];

		YSP13[c] = grSteveSPv2[c]->GetY()[13];
		YSP13e[c] = grSteveSPv2[c]->GetEY()[13];

		YSP15[c] = grSteveSPv2[c]->GetY()[15];
		YSP15e[c] = grSteveSPv2[c]->GetEY()[15];

		YSP16[c] = grSteveSPv2[c]->GetY()[16];
		YSP16e[c] = grSteveSPv2[c]->GetEY()[16];
	}
	for ( int c = 1; c < 6; c++ ) {
		XCumu0[c]  = grQuanCumu[1][c]->GetY()[0];
		XCumu0e[c] = grQuanCumu[1][c]->GetEY()[0];

		YCumu13[c]  = grQuanCumu[1][c]->GetY()[13];
		YCumu13e[c] = grQuanCumu[1][c]->GetEY()[13];

		YCumu15[c]  = grQuanCumu[1][c]->GetY()[15];
		YCumu15e[c] = grQuanCumu[1][c]->GetEY()[15];

		YCumu16[c]  = grQuanCumu[1][c]->GetY()[16];
		YCumu16e[c] = grQuanCumu[1][c]->GetEY()[16];
	}

	TGraphErrors * grPtSP_0_16 = new TGraphErrors(7, XSP0, YSP16, XSP0e, YSP16e);
	TGraphErrors * grPtSP_0_15 = new TGraphErrors(7, XSP0, YSP15, XSP0e, YSP15e);
	TGraphErrors * grPtSP_0_13 = new TGraphErrors(7, XSP0, YSP13, XSP0e, YSP13e);

	TGraphErrors * grPtCumu_0_16 = new TGraphErrors(5, XCumu0+1, YCumu16+1, XCumu0e+1, YCumu16e+1);
	TGraphErrors * grPtCumu_0_15 = new TGraphErrors(5, XCumu0+1, YCumu15+1, XCumu0e+1, YCumu15e+1);
	TGraphErrors * grPtCumu_0_13 = new TGraphErrors(5, XCumu0+1, YCumu13+1, XCumu0e+1, YCumu13e+1);

	grPtSP_0_13->SetMarkerStyle(kFullCircle);
	grPtSP_0_13->SetMarkerColor(kBlue);
	grPtSP_0_13->SetLineColor(kBlue);
	grPtSP_0_16->SetMarkerStyle(kFullCircle);
	grPtSP_0_16->SetMarkerColor(kBlack);
	grPtSP_0_16->SetLineColor(kBlack);
	grPtSP_0_15->SetMarkerStyle(kFullCircle);
	grPtSP_0_15->SetMarkerColor(kRed);
	grPtSP_0_15->SetLineColor(kRed);

	grPtCumu_0_13->SetMarkerStyle(kOpenSquare);
	grPtCumu_0_13->SetMarkerColor(kBlue);
	grPtCumu_0_13->SetLineColor(kBlue);
	grPtCumu_0_16->SetMarkerStyle(kOpenSquare);
	grPtCumu_0_16->SetMarkerColor(kBlack);
	grPtCumu_0_16->SetLineColor(kBlack);
	grPtCumu_0_15->SetMarkerStyle(kOpenSquare);
	grPtCumu_0_15->SetMarkerColor(kRed);
	grPtCumu_0_15->SetLineColor(kRed);

	grPtSP_0_13->Draw("psame");
	grPtSP_0_15->Draw("psame");
//	grPtSP_0_16->Draw("psame");
	grPtCumu_0_13->Draw("psame");
	grPtCumu_0_15->Draw("psame");
//	grPtCumu_0_16->Draw("psame");

	TLegend *legHiLow = new TLegend(0.26, 0.77, 0.4, 0.92);
	legHiLow->SetFillColor(kWhite);
	legHiLow->SetTextFont(42);
	legHiLow->SetTextSize(0.03);
	legHiLow->SetBorderSize(0);

	legHiLow->AddEntry(grPtSP_0_13, "v_{2}{SP} (12 < p_{T} < 14 GeV/c)", "p");
	legHiLow->AddEntry(grPtCumu_0_13, "v_{2}{4} (12 < p_{T} < 14 GeV/c)", "p");
	legHiLow->AddEntry(grPtSP_0_15, "v_{2}{SP} (20 < p_{T} < 26 GeV/c)", "p");
	legHiLow->AddEntry(grPtCumu_0_15, "v_{2}{4} (20 < p_{T} < 26 GeV/c)", "p");

	legHiLow->Draw();

	cT->SaveAs("V2_HiLow.pdf");
}
