// making plot
{
#include "label.h"
#include "noff.h"
#include "style.h"

	int s1 = 12;
	int s2 = 1; // 1: C, 0:V

	int sN;

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
	mgr_HIN13002_pPbPt[2][0][7]->Draw();
	mgr_HIN13002_pPbPt[2][1][7]->Draw();
	gr_vnPt[2][0][7]->Draw("Psame");
	gr_vnPt[2][1][7]->Draw("Psame");
	gr_vnPt[2][2][6]->Draw("Psame");
	gr_vnPt[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_pt->Draw();
	mgr_HIN13002_pPbPt[2][0][6]->Draw();
	mgr_HIN13002_pPbPt[2][1][6]->Draw();
	gr_vnPt[2][0][6]->Draw("Psame");
	gr_vnPt[2][1][6]->Draw("Psame");
	gr_vnPt[2][2][5]->Draw("Psame");
	gr_vnPt[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_pt->Draw();
	mgr_HIN13002_pPbPt[2][0][5]->Draw();
	mgr_HIN13002_pPbPt[2][1][5]->Draw();
	gr_vnPt[2][0][5]->Draw("Psame");
	gr_vnPt[2][1][5]->Draw("Psame");
	gr_vnPt[2][2][4]->Draw("Psame");
	gr_vnPt[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_pt->Draw();
	mgr_HIN13002_pPbPt[2][0][4]->Draw();
	mgr_HIN13002_pPbPt[2][1][4]->Draw();
	gr_vnPt[2][0][4]->Draw("Psame");
	gr_vnPt[2][1][4]->Draw("Psame");
	gr_vnPt[2][2][3]->Draw("Psame");
	gr_vnPt[2][3][2]->Draw("Psame");
}
