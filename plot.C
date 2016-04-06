#include "../../style.h"
#include "SteveSP.C"
#include "QuanCumu.C"

void plot()
{
	SteveSP();
	QuanCumu();

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

	for ( int c = 0; c < 8; c++ ) {
		cT->cd(c+1);
		hframe_pt->Draw();

		zero->Draw();
		grSteveSPv2[c]->Draw("Psame");
		grSteveSPv3[c]->Draw("Psame");
		if ( mgrQuanCumu[1][c] != 0 ) {
			mgrQuanCumu[1][c]->Draw();
			mgrQuanCumu[2][c]->Draw();
			mgrQuanCumu[3][c]->Draw();
		}
		latex.DrawLatexNDC(0.2, 0.9, strSteveCent[c]);

	}

	cT->cd(1);
//	hframe_pt->Draw();

	TLegend *legPt = new TLegend(0.6, 0.45, 0.9, 0.95);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(42);
	legPt->SetTextSize(0.08);
	legPt->SetBorderSize(0);
	legPt->AddEntry(grQuanCumu[1][1], "v_{2}{4}", "p");
	legPt->AddEntry(grQuanCumu[2][1], "v_{2}{6}", "p");
	legPt->AddEntry(grQuanCumu[3][1], "v_{2}{8}", "p");
	legPt->AddEntry(grSteveSPv2[1], "v_{2}{SP}", "p");
	legPt->AddEntry(grSteveSPv3[1], "v_{3}{SP}", "p");
	legPt->Draw();

	cT->SaveAs("final_vn.pdf");

	cT = MakeCanvas("cT0", "cT0", 1000, 500);
	makeMultiPanelCanvas(cT, 4, 2, 0.0, 0., 0.15, 0.15, 0.01);
	TH2D * hframeRatio_pt = new TH2D("hframeRatio_pt", "", 1, 0.1, 99, 1, 0.01, 1.99);
	InitHist(hframeRatio_pt, "p_{T} (GeV/c)", "Ratio");

	TGraphErrors * grRatio[8] = {0};
	for ( int c = 0; c < 7; c++ ) {
		cT->cd(c+1);
		hframeRatio_pt->Draw();
		one->Draw();

		if ( grQuanCumu[1][c] != 0 ) {
			grRatio[c] = (TGraphErrors*) grQuanCumu[1][c]->Clone();
			for ( int i = 0; i < grRatio[c]->GetN(); i++ ) {
				grRatio[c]->GetY()[i] = grSteveSPv2[c]->GetY()[i] / grQuanCumu[1][c]->GetY()[i];
				grRatio[c]->GetEY()[i] = grRatio[c]->GetY()[i] * sqrt( grSteveSPv2[c]->GetEY()[i]*grSteveSPv2[c]->GetEY()[i]/grSteveSPv2[c]->GetY()[i]/grSteveSPv2[c]->GetY()[i] + grQuanCumu[1][c]->GetEY()[i]*grQuanCumu[1][c]->GetEY()[i]/grQuanCumu[1][c]->GetY()[i]/grQuanCumu[1][c]->GetY()[i]  );
			}
			grRatio[c]->Draw("Psame");
		}

		latex.DrawLatexNDC(0.2, 0.9, strSteveCent[c]);
	}

	cT->cd(8);
	hframeRatio_pt->Draw();

	TLegend *legRatio = new TLegend(0.2, 0.3, 0.8, 0.9);
	legRatio->SetFillColor(kWhite);
	legRatio->SetTextFont(42);
	legRatio->SetTextSize(0.1);
	legRatio->SetBorderSize(0);
	legRatio->AddEntry(grRatio[1], "v_{2}{SP}/v_{2}{4}", "p");
	legRatio->Draw();

	cT->SaveAs("final_vn_ratio.pdf");

	TGraphErrors * grNormSP[8];
	TGraphErrors * grNormCumu[8];

	for ( int c = 0; c < 8; c++ ) {
		if (grSteveSPv2[c]) {
			grNormSP[c] = (TGraphErrors*) grSteveSPv2[c]->Clone();
			for ( int i = 0; i < grSteveSPv2[c]->GetN(); i++ ) {
				grNormSP[c]->GetY()[i] /= grSteveSPv2[c]->GetY()[0];
				grNormSP[c]->GetEY()[i] /= grSteveSPv2[c]->GetY()[0];
			}
			grNormSP[c]->SetMarkerColor(1+c);
			grNormSP[c]->SetLineColor(1+c);
//			grNormSP[c]->Draw("plsame");
		}

		if (grQuanCumu[1][c]) {
			grNormCumu[c] = (TGraphErrors*) grQuanCumu[1][c]->Clone();
			for ( int i = 0; i < grQuanCumu[1][c]->GetN(); i++ ) {
				grNormCumu[c]->GetY()[i] /= grQuanCumu[1][c]->GetY()[0];
				grNormCumu[c]->GetEY()[i] /= grQuanCumu[1][c]->GetY()[0];
			}
			grNormCumu[c]->SetMarkerColor(1+c);
			grNormCumu[c]->SetLineColor(1+c);
//			grNormCumu[c]->Draw("plsame");
		}
	}

	cT = new TCanvas("cT1", "cT1", 500, 500);
	cT->SetLeftMargin(0.15);
	cT->SetRightMargin(0.05);
	cT->SetTopMargin(0.05);
	TH2D * hframeNorm_pt = new TH2D("hframeNorm_pt", ";p_{T} (GeV/c);Ratio", 1, 0.1, 19, 1, 0.01, 2.99);
	hframeNorm_pt->Draw();

	TLegend *legNorm = new TLegend(0.4, 0.5, 0.8, 0.9);
	legNorm->SetFillColor(kWhite);
	legNorm->SetTextFont(42);
	legNorm->SetTextSize(0.05);
	legNorm->SetBorderSize(0);

	for ( int c = 0; c < 8; c++ ) {
		grNormSP[c]->Draw("plsame");
		legNorm->AddEntry(grNormSP[c], strSteveCent[c], "p");
	}
	legNorm->Draw();
	cT->SaveAs("SPNorm.pdf");

	cT = new TCanvas("cT2", "cT2", 500, 500);
	cT->SetLeftMargin(0.15);
	cT->SetRightMargin(0.05);
	cT->SetTopMargin(0.05);
	hframeNorm_pt->Draw();

	TLegend *legNorm1 = new TLegend(0.4, 0.5, 0.8, 0.9);
	legNorm1->SetFillColor(kWhite);
	legNorm1->SetTextFont(42);
	legNorm1->SetTextSize(0.05);
	legNorm1->SetBorderSize(0);


	for ( int c = 1; c < 6; c++ ) {
		grNormCumu[c]->Draw("plsame");
		legNorm1->AddEntry(grNormSP[c], strSteveCent[c], "p");
	}
	legNorm1->Draw();
	cT->SaveAs("CumuNorm.pdf");

	//////////////////////////////////////////////

	cT = new TCanvas("cT3", "cT3", 800, 800);
	cT->SetLeftMargin(0.15);
	cT->SetRightMargin(0.01);
	cT->SetTopMargin(0.01);
	TH2D * hframe_cent = new TH2D("hframe_cent", ";Centrality;v_{2}", 1, 0., 85, 1, 0.01, 0.35);

	hframe_cent->Draw();

	double Xcent[8] = {2.5, 7.5, 15, 25, 35, 45, 55, 65};
	double Yv2[8] = {};
	double Yv2e[8] = {};
	int listPt[4] = {0, 4, 13, 16};
	const char * strPt[4] = {
		"1.0 < p_{T} < 1.25 GeV/c",
		"2.5 < p_{T} < 3.0 GeV/c",
		"12. < p_{T} < 14. GeV/c",
		"26. < p_{T} < 35. GeV/c",
	};

	TGraphErrors * grV2SPCent[4] = {};
	TGraphErrors * grV2CumuCent[4] = {};

	TLegend *legCent1 = new TLegend(0.26, 0.77, 0.4, 0.92);
	legCent1->SetFillColor(kWhite);
	legCent1->SetTextFont(42);
	legCent1->SetTextSize(0.03);
	legCent1->SetBorderSize(0);

	TLegend *legCent = new TLegend(0.33, 0.77, 0.6, 0.92);
	legCent->SetFillColor(kWhite);
	legCent->SetTextFont(42);
	legCent->SetTextSize(0.03);
	legCent->SetBorderSize(0);

	latex.DrawLatexNDC(0.24, 0.96, "v_{2}{4}   v_{2}{SP}");

	for ( int i = 0; i < 4; i++ ) {
		for ( int cent = 0 ; cent < 8; cent++ ) {
			Yv2[cent] = grSteveSPv2[cent]->GetY()[listPt[i]];
			Yv2e[cent] = grSteveSPv2[cent]->GetEY()[listPt[i]];
		}
		grV2SPCent[i] = new TGraphErrors(8, Xcent, Yv2, 0, Yv2e);
		grV2SPCent[i]->SetMarkerStyle(kFullCircle);
		grV2SPCent[i]->SetMarkerColor(1+i);
		grV2SPCent[i]->SetLineColor(1+i);

		for ( int cent = 1 ; cent < 6; cent++ ) {
			Yv2[cent] = grQuanCumu[1][cent]->GetY()[listPt[i]];
			Yv2e[cent] = grQuanCumu[1][cent]->GetEY()[listPt[i]];
		}
		grV2CumuCent[i] = new TGraphErrors(5, Xcent+1, Yv2+1, 0, Yv2e+1);
		grV2CumuCent[i]->SetMarkerStyle(kOpenSquare);
		grV2CumuCent[i]->SetMarkerColor(1+i);
		grV2CumuCent[i]->SetLineColor(1+i);

		grV2SPCent[i]->Draw("plsame");
		grV2CumuCent[i]->Draw("plsame");

		legCent->AddEntry(grV2SPCent[i],   strPt[i], "p");
		legCent1->AddEntry(grV2CumuCent[i], " ", "p");
	}
	legCent1->Draw();
	legCent->Draw();

	cT->SaveAs("v2cent.pdf");

}
