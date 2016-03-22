#include "label.h"
#include "../../style.h"
#include "noff.h"
#include "HIN-11-012.h"

void mergeTrig(int sMB = 24, int sHP = 19, int n = 2)
{
	bool bHIN = true;
	TGraphErrors * gr_V2[4][20] = {};

        Int_t const * pCent4 = CentPbPb4;
        Int_t const * pCent6 = CentPbPb6;
        Int_t const * pCent8 = CentPbPb8;

        Int_t const * pCent[4] = { pCent4, pCent4, pCent6, pCent8 };


	TFile* fMB = new TFile(Form("%s/outGraph.root", ftxt[sMB]));
	TFile* fHP1 = new TFile(Form("%s/outGraph__1.root", ftxt[sHP]));
	TFile* fHP2 = new TFile(Form("%s/outGraph__2.root", ftxt[sHP]));
	TFile* fHP3 = new TFile(Form("%s/outGraph__3.root", ftxt[sHP]));
	TFile* fHP4 = new TFile(Form("%s/outGraph__4.root", ftxt[sHP]));

	TGraphErrors * grMB_v2[4][20] = {};
	TGraphErrors * grHP1_v2[4][20] = {};
	TGraphErrors * grHP2_v2[4][20] = {};
	TGraphErrors * grHP3_v2[4][20] = {};
	TGraphErrors * grHP4_v2[4][20] = {};

	for ( int c = 0; c < 20; c++ ) {
		for ( int np = 0; np < 4; np++ ) {
			grMB_v2[np][c]  = (TGraphErrors*) fMB->Get(Form("gr_vnPtC_%i_%i_%i", n, np, c));
			grHP1_v2[np][c] = (TGraphErrors*) fHP1->Get(Form("gr_vnPtC_%i_%i_%i",n, np, c));
			grHP2_v2[np][c] = (TGraphErrors*) fHP2->Get(Form("gr_vnPtC_%i_%i_%i",n, np, c));
			grHP3_v2[np][c] = (TGraphErrors*) fHP3->Get(Form("gr_vnPtC_%i_%i_%i",n, np, c));
			grHP4_v2[np][c] = (TGraphErrors*) fHP4->Get(Form("gr_vnPtC_%i_%i_%i",n, np, c));

			gr_V2[np][c] = new TGraphErrors(23);
			for ( int i = 0; i < 16; i++ ) {
				gr_V2[np][c]->GetX()[i]  = grMB_v2[np][c]->GetX()[i];
				gr_V2[np][c]->GetY()[i]  = grMB_v2[np][c]->GetY()[i];
				gr_V2[np][c]->GetEY()[i] = grMB_v2[np][c]->GetEY()[i];
			}
				gr_V2[np][c]->GetX()[16]  = grHP1_v2[np][c]->GetX()[16];
				gr_V2[np][c]->GetY()[16]  = grHP1_v2[np][c]->GetY()[16];
				gr_V2[np][c]->GetEY()[16] = grHP1_v2[np][c]->GetEY()[16];

				gr_V2[np][c]->GetX()[17]  = grHP2_v2[np][c]->GetX()[17];
				gr_V2[np][c]->GetY()[17]  = grHP2_v2[np][c]->GetY()[17];
				gr_V2[np][c]->GetEY()[17] = grHP2_v2[np][c]->GetEY()[17];

				gr_V2[np][c]->GetX()[18]  = grHP3_v2[np][c]->GetX()[18];
				gr_V2[np][c]->GetY()[18]  = grHP3_v2[np][c]->GetY()[18];
				gr_V2[np][c]->GetEY()[18] = grHP3_v2[np][c]->GetEY()[18];

			for ( int i = 19; i <= 22; i++ ) {
				gr_V2[np][c]->GetX()[i]  = grHP4_v2[np][c]->GetX()[i];
				gr_V2[np][c]->GetY()[i]  = grHP4_v2[np][c]->GetY()[i];
				gr_V2[np][c]->GetEY()[i] = grHP4_v2[np][c]->GetEY()[i];
			}
		}
		grMB_v2[1][c]->SetMarkerStyle(kOpenSquare);
		grMB_v2[2][c]->SetMarkerStyle(kOpenCross);
		grMB_v2[3][c]->SetMarkerStyle(kOpenDiamond);

		gr_V2[1][c]->SetMarkerStyle(kFullSquare);
		gr_V2[2][c]->SetMarkerStyle(kFullCross);
		gr_V2[3][c]->SetMarkerStyle(kFullDiamond);

		gr_V2[1][c]->SetMarkerColor(kGreen+2);
		gr_V2[2][c]->SetMarkerColor(kBlue);
		gr_V2[3][c]->SetMarkerColor(kRed);
		gr_V2[1][c]->SetLineColor(kGreen+2);
		gr_V2[2][c]->SetLineColor(kBlue);
		gr_V2[3][c]->SetLineColor(kRed);

		/////
		gr_V2[0][c]->RemovePoint(0);
		gr_V2[1][c]->RemovePoint(0);
		gr_V2[2][c]->RemovePoint(0);
		gr_V2[3][c]->RemovePoint(0);

		gr_V2[0][c]->RemovePoint(0);
		gr_V2[1][c]->RemovePoint(0);
		gr_V2[2][c]->RemovePoint(0);
		gr_V2[3][c]->RemovePoint(0);
	}

	SetStyle();
	gStyle->SetMarkerSize(1);

	HIN_11_012();

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);
	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 100, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", Form("v_{%i}", n));
	for ( int c = 0; c < 14; c++ ) {
		TLegend * legPt = new TLegend(0.2, 0.7, 0.55, 0.9);
		legPt->SetFillColor(kWhite);
		legPt->SetTextFont(42);
		legPt->SetTextSize(0.03);
		legPt->SetBorderSize(0);


		hframe_pt->Draw();
		if ( bHIN and mgrHIN11012_v2[c] and n == 2 ) {
//			mgrHIN11012_v2[c]->Draw("P");
//			legPt->AddEntry(mgrHIN11012_v2[c]->GetListOfGraphs()->At(1), "v_{2}{EP} HIN-11-012", "p");
		}
		grMB_v2[1][c]->Draw("psame");
//		grMB_v2[2][c]->Draw("psame");
//		grMB_v2[3][c]->Draw("psame");

		gr_V2[1][c]->Draw("psame");
//		gr_V2[2][c]->Draw("psame");
//		gr_V2[3][c]->Draw("psame");

		legPt->AddEntry(grMB_v2[1][c], Form("v_{%i}{4} MB %i%% < Centrality < %i%%", n, pCent[1][c]/2, pCent[0][c+1]/2), "p");
		legPt->AddEntry(gr_V2[1][c], Form("v_{%i}{4} %i%% < Centrality < %i%%", n, pCent[1][c]/2, pCent[0][c+1]/2), "p");
//		legPt->AddEntry(gr_V2[2][c], Form("v_{%i}{6} %i%% < Centrality < %i%%", n, pCent[1][c]/2, pCent[0][c+1]/2), "p");
//		legPt->AddEntry(gr_V2[3][c], Form("v_{%i}{8} %i%% < Centrality < %i%%", n, pCent[1][c]/2, pCent[0][c+1]/2), "p");

		legPt->Draw();
		cT->SaveAs(Form("v%i_%i.pdf", n, c));
	}

	TFile * fsave = new TFile(Form("fresult%i_%i_%i.root", n, sMB, sHP), "recreate" );
	for ( int np = 0; np < 4; np++ ) {
		for ( int c = 0; c < 7; c++ ) {
			gr_V2[np][c]->SetName(Form("gr_V%i%i_%i", n, 2+2*np, c));
			gr_V2[np][c]->Write();
		}
	}
	fsave->Write();
}
