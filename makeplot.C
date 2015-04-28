// making plot
{
#include "label.h"
#include "noff.h"
#include "style.h"

//	int s1 = 109; // PbPb
	int s1 = 139; // pPb
	int s2 = 1; // 1: C, 0:V

	int bPbPb = 0;

	int sN;

	if ( s1 == 109 ) bPbPb = 1;


	TFile *f = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	gROOT->Macro("HIN-13-002.C");


	TGraphErrors * gr_vnPt[7][4][20];
	TGraphErrors * gr_vnEta[7][4][20];

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 20; c++ ) {
				if ( s2 == 1 ) {
					gr_vnPt[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnPtC_%i_%i_%i", n, np, c));
					gr_vnEta[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnEtaC_%i_%i_%i", n, np, c));
				}

				if ( s2 == 0 ) {
					gr_vnPt[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnPtV_%i_%i_%i", n, np, c));
					gr_vnEta[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnEtaV_%i_%i_%i", n, np, c));
				}
			}
		}
	}


	SetStyle();
	TCanvas * cT = MakeCanvas("cT", "cT", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, .1, 5.9, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");

	cT->cd(1);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][7]->Draw();
	else mgr_HIN13002_pPbPt[2][0][7]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][7]->Draw();
	else mgr_HIN13002_pPbPt[2][1][7]->Draw();
	gr_vnPt[2][0][7]->Draw("Psame");
	gr_vnPt[2][1][7]->Draw("Psame");
	gr_vnPt[2][2][6]->Draw("Psame");
	gr_vnPt[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][6]->Draw();
	else mgr_HIN13002_pPbPt[2][0][6]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][6]->Draw();
	else mgr_HIN13002_pPbPt[2][1][6]->Draw();
	gr_vnPt[2][0][6]->Draw("Psame");
	gr_vnPt[2][1][6]->Draw("Psame");
	gr_vnPt[2][2][5]->Draw("Psame");
	gr_vnPt[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][5]->Draw();
	else mgr_HIN13002_pPbPt[2][0][5]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][5]->Draw();
	else mgr_HIN13002_pPbPt[2][1][5]->Draw();
	gr_vnPt[2][0][5]->Draw("Psame");
	gr_vnPt[2][1][5]->Draw("Psame");
	gr_vnPt[2][2][4]->Draw("Psame");
	gr_vnPt[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][4]->Draw();
	else mgr_HIN13002_pPbPt[2][0][4]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][4]->Draw();
	else mgr_HIN13002_pPbPt[2][1][4]->Draw();
	gr_vnPt[2][0][4]->Draw("Psame");
	gr_vnPt[2][1][4]->Draw("Psame");
	gr_vnPt[2][2][3]->Draw("Psame");
	gr_vnPt[2][3][2]->Draw("Psame");

	TLegend * legPt1 = new TLegend(0.1, 0.8, 0.7, 0.95);
	legPt1->SetFillColor(kWhite);
	legPt1->SetBorderSize(0);
	legPt1->AddEntry(gr_HIN_13_002_PbPbv22pt5, "HIN-13-002 v_{2}{2}", "p");
	legPt1->AddEntry(gr_HIN_13_002_PbPbv24pt5, "HIN-13-002 v_{2}{4}", "p");

	TLegend * legPt2 = new TLegend(0.05, 0.65, 0.3, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->AddEntry(gr_vnPt[2][0][4], "v_{2}{2}", "p");
	legPt2->AddEntry(gr_vnPt[2][1][4], "v_{2}{4}", "p");
	legPt2->AddEntry(gr_vnPt[2][2][4], "v_{2}{6}", "p");
	legPt2->AddEntry(gr_vnPt[2][3][4], "v_{2}{8}", "p");

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT->cd(2);
	legPt1->Draw();
	cT->cd(3);
	legPt2->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT->SaveAs(Form("pT_%i.pdf", s1));

	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.4, 2.4, 1, 0, 0.18);
	InitHist(hframe_eta, "#eta", "v_{2}");

	cT->cd(1);
	hframe_eta->Draw();
	gr_vnEta[2][0][7]->Draw("Psame");
	gr_vnEta[2][1][7]->Draw("Psame");
	gr_vnEta[2][2][6]->Draw("Psame");
	gr_vnEta[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_eta->Draw();
	gr_vnEta[2][0][6]->Draw("Psame");
	gr_vnEta[2][1][6]->Draw("Psame");
	gr_vnEta[2][2][5]->Draw("Psame");
	gr_vnEta[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_eta->Draw();
	gr_vnEta[2][0][5]->Draw("Psame");
	gr_vnEta[2][1][5]->Draw("Psame");
	gr_vnEta[2][2][4]->Draw("Psame");
	gr_vnEta[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_eta->Draw();
	gr_vnEta[2][0][4]->Draw("Psame");
	gr_vnEta[2][1][4]->Draw("Psame");
	gr_vnEta[2][2][3]->Draw("Psame");
	gr_vnEta[2][3][2]->Draw("Psame");

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT->cd(2);
	legPt1->Draw();
	cT->cd(3);
	legPt2->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");


	cT->SaveAs(Form("eta_%i.pdf", s1));

}
