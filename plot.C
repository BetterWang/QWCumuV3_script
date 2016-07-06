#include "../../style.h"
#include "label.h"

void plot(int sMB = 62, int sHP = 100, int sx = 4)
{
	TFile *fMB = new TFile(Form("%s/outGraph.root", ftxt[sMB]));
	TFile *fHP = new TFile(Form("%s/outGraph__%i.root", ftxt[sHP], sx));

	SetStyle();

	TGraphErrors * grMB_v2[4][20] = {};
	TGraphErrors * grHP_v2[4][20] = {};

	for ( int c = 0; c < 20; c++ ) {
		for ( int np = 0; np < 4; np++ ) {
			grMB_v2[np][c] = (TGraphErrors*) fMB->Get(Form("gr_vnPtC_%i_%i_%i", 2, np, c));
			grHP_v2[np][c] = (TGraphErrors*) fHP->Get(Form("gr_vnPtC_%i_%i_%i", 2, np, c));
		}
	}


	TCanvas * cT = MakeCanvas("cT", "cT", 1000, 500);
	makeMultiPanelCanvas(cT, 4, 2, 0.0, 0., 0.2, 0.2, 0.01);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0.9, 19, 1, -0.049, 0.28);

	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{n}{SP}");
	hframe_pt->SetTitleSize(hframe_pt->GetTitleSize()*1.3,"X");
	hframe_pt->SetTitleSize(hframe_pt->GetTitleSize()*1.3,"Y");
	hframe_pt->SetTitleOffset(hframe_pt->GetTitleOffset()*1.1,"X");
	hframe_pt->SetTitleOffset(hframe_pt->GetTitleOffset()*0.9,"Y");
	hframe_pt->SetLabelSize(hframe_pt->GetLabelSize()*1.1,"X");
	hframe_pt->SetLabelSize(hframe_pt->GetLabelSize()*1.1,"Y");

	TLine * zero = new TLine(0, 0, 100, 0);
	zero->SetLineStyle(2);

	for ( int c = 0; c < 7; c++ ) {
		cT->cd(c+1);
		hframe_pt->Draw();
		zero->Draw();

		grMB_v2[1][c]->SetMarkerStyle(kOpenSquare);
		grMB_v2[1][c]->SetMarkerColor(kBlue);
		grMB_v2[1][c]->SetLineColor(kBlue);
		grHP_v2[1][c]->SetMarkerStyle(kOpenSquare);
		grHP_v2[1][c]->SetMarkerColor(kRed);
		grHP_v2[1][c]->SetLineColor(kRed);

		grMB_v2[1][c]->Draw("psame");
		grHP_v2[1][c]->Draw("psame");
	}
	cT->cd(8);
	hframe_pt->Draw();

	TLegend *legPt = new TLegend(0.05, 0.45, 0.43, 0.67);
	legPt->SetFillColor(kWhite);
	legPt->SetTextFont(43);
	legPt->SetTextSize(18);
	legPt->SetBorderSize(0);
	legPt->AddEntry(grMB_v2[1][1], "v_{2}{4} MB", "p");
	legPt->AddEntry(grHP_v2[1][1], "v_{2}{4} HP, p_{T} > 35 GeV/c", "p");
	legPt->Draw();

	TLatex * latex = new TLatex();
	latex->SetTextFont(43);
	latex->SetTextSize(18);
	latex->SetTextAlign(13);

	cT->cd(1);
	latex->DrawLatexNDC(0.65, 0.89, "0-5%");
	cT->cd(2);
	latex->DrawLatexNDC(0.65, 0.89, "5-10%");
	cT->cd(3);
	latex->DrawLatexNDC(0.65, 0.89, "10-20%");
	cT->cd(4);
	latex->DrawLatexNDC(0.65, 0.89, "20-30%");
	cT->cd(5);
	latex->DrawLatexNDC(0.65, 0.89, "30-40%");
	cT->cd(6);
	latex->DrawLatexNDC(0.65, 0.89, "40-50%");
	cT->cd(7);
	latex->DrawLatexNDC(0.65, 0.89, "50-60%");

	cT->SaveAs("v24.pdf");
}
