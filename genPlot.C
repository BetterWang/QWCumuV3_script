/*
 * =====================================================================================
 *
 *       Filename:  genPlot.C
 *
 *    Description:  generate all plots
 *
 *        Version:  1.0
 *        Created:  09/11/2014 09:41:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


{
#include "label.h"
#include "noff.h"
	int s1 = 5;

	int sC = 1;
	int sSimV2 = 1;
	
	bool SAVE = true;

	TFile *f = new TFile(Form("%s/outputE.root", ftxt[s1]));
	gROOT->Macro("HIN-13-002.C");

#include "../../style.h"
	SetStyle();
	////////////
	//Get Histo

	double dV[7][4][20];
	double eV[7][4][20];
	double cV[7][4][20];

	double dX[7][4][20];
	double eX[7][4][20];
	double cX[7][4][20];

	double dVp[7][4][24][20];
	double eVp[7][4][24][20];
	double cVp[7][4][24][20];

	double dVeta[7][4][24][20];
	double eVeta[7][4][24][20];
	double cVeta[7][4][24][20];

	double dVc[7][4][2][20];
	double eVc[7][4][2][20];
	double cVc[7][4][2][20];

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			TH1D * h1 = (TH1D*) f->Get(Form("hV%i%i", n, 2+2*np));
			TH1D * h2 = (TH1D*) f->Get(Form("hX%i%i", n, 2+2*np));
			TH1D * h3 = (TH1D*) f->Get(Form("hcV%i%i", n, 2+2*np));
			TH1D * h4 = (TH1D*) f->Get(Form("hcX%i%i", n, 2+2*np));
			for ( int i = 0; i < 20; i++ ) {
				dV[n][np][i] = h1->GetBinContent(i+1);
				eV[n][np][i] = h1->GetBinError(i+1);
				cV[n][np][i] = h3->GetBinError(i+1);
				if ( dV[n][np][i] != h3->GetBinContent(i+1) ) cout << "!! dV[" << n << "][" << np << "][" << i << "] = " << dV[n][np][i] << "\tdcV = " << h3->GetBinContent(i+1) << endl;

				dX[n][np][i] = h2->GetBinContent(i+1);
				eX[n][np][i] = h2->GetBinError(i+1);
				cX[n][np][i] = h4->GetBinError(i+1);
				if ( dX[n][np][i] != h4->GetBinContent(i+1) ) cout << "!! dX[" << n << "][" << np << "][" << i << "] = " << dX[n][np][i] << "\tdcX = " << h4->GetBinContent(i+1) << endl;
			}
			delete h1;
			delete h2;
			delete h3;
			delete h4;

			for ( int j = 0; j < 24; j++ ) {
				h1 = (TH1D*) f->Get(Form("hVp%i%i_%i", n, 2+2*np, j));
				h2 = (TH1D*) f->Get(Form("hVeta%i%i_%i", n, 2+2*np, j));
				h3 = (TH1D*) f->Get(Form("hcVp%i%i_%i", n, 2+2*np, j));
				h4 = (TH1D*) f->Get(Form("hcVeta%i%i_%i", n, 2+2*np, j));
				for ( int i = 0; i < 20; i++ ) {
					dVp[n][np][j][i] = h1->GetBinContent(i+1);
					eVp[n][np][j][i] = h1->GetBinError(i+1);
					cVp[n][np][j][i] = h3->GetBinError(i+1);
//					cout << "!! eVp[" << n << "][" << np << "][" << j << "][" << i << "] = " << eVp[n][np][j][i] << "\tcVp = " << cVp[n][np][j][i] << endl;
//					if ( dVp[n][np][j][i] != h3->GetBinContent(i+1) ) cout << "!! dVp[" << n << "][" << np << "][" << j << "][" << i << "] = " << dVp[n][np][j][i] << "\tdcVp = " << h3->GetBinContent(i+1) << endl;

					dVeta[n][np][j][i] = h2->GetBinContent(i+1);
					eVeta[n][np][j][i] = h2->GetBinError(i+1);
					cVeta[n][np][j][i] = h4->GetBinError(i+1);
//					if ( dVeta[n][np][j][i] != h4->GetBinContent(i+1) ) cout << "!! dVeta[" << n << "][" << np << "][" << j << "][" << i << "] = " << dVeta[n][np][j][i] << "\tdcVeta = " << h4->GetBinContent(i+1) << endl;
				}
				delete h1;
				delete h2;
				delete h3;
				delete h4;
			}
			for ( int j = 0; j < 2; j++ ) {
				h1 = (TH1D*) f->Get(Form("hVc%i%i_%i", n, 2+2*np, j));
				h2 = (TH1D*) f->Get(Form("hcVc%i%i_%i", n, 2+2*np, j));
				for ( int i = 0; i < 20; i++ ) {
					dVc[n][np][j][i] = h1->GetBinContent(i+1);
					eVc[n][np][j][i] = h1->GetBinError(i+1);
					cVc[n][np][j][i] = h2->GetBinError(i+1);

//					if ( dVc[n][np][j][i] != h2->GetBinContent(i+1) ) cout << "!! dVc[" << n << "][" << np << "][" << j << "][" << i << "] = " << dVc[n][np][j][i] << "\tdcVc = " << h2->GetBinContent(i+1) << endl;
				}
				delete h1;
				delete h2;
			}
		}
	}

	// TGraphErrors
	TGraphErrors * gr_vnPtV[7][4][20];
	TGraphErrors * gr_vnPtC[7][4][20];
	memset(gr_vnPtV, 0, sizeof(gr_vnPtV));
	memset(gr_vnPtC, 0, sizeof(gr_vnPtC));

	double dY[100];
	double eY[100];
	double cY[100];

        Int_t * pCent4;
        Int_t * pCent6;
        Int_t * pCent8;

        pCent4 = CentNoffCutTest4;
        pCent6 = CentNoffCutTest6;
        pCent8 = CentNoffCutTest8;

        Int_t * pCent[4] = { pCent4, pCent4, pCent6, pCent8 };

	// pT
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 20; i++ ) {
				if ( pCent[np][i] == 0 ) break;
				for ( int j = 0; j < 18; j++ ) {
					dY[j] = dVp[n][np][j][i];
					eY[j] = eVp[n][np][j][i];
					cY[j] = cVp[n][np][j][i];
					if (eY[j] != eY[j]) eY[j] = 999;
					if (cY[j] != cY[j]) cY[j] = 999;
				}
				gr_vnPtV[n][np][i] = new TGraphErrors(18, ptX, dY, 0, eY);
				gr_vnPtC[n][np][i] = new TGraphErrors(18, ptX, dY, 0, cY);
				if ( np == 0 ) {
					gr_vnPtV[n][np][i]->SetMarkerStyle(kFullCircle);
					gr_vnPtV[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnPtV[n][np][i]->SetLineColor(kGreen+2);
					gr_vnPtC[n][np][i]->SetMarkerStyle(kFullCircle);
					gr_vnPtC[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnPtC[n][np][i]->SetLineColor(kGreen+2);
				} else if ( np == 1 ) {
					gr_vnPtV[n][np][i]->SetMarkerStyle(kFullSquare);
					gr_vnPtV[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnPtV[n][np][i]->SetLineColor(kGreen+2);
					gr_vnPtC[n][np][i]->SetMarkerStyle(kFullSquare);
					gr_vnPtC[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnPtC[n][np][i]->SetLineColor(kGreen+2);
				} else if ( np == 2 ) {
					gr_vnPtV[n][np][i]->SetMarkerStyle(kFullCross);
					gr_vnPtV[n][np][i]->SetMarkerColor(kBlue);
					gr_vnPtV[n][np][i]->SetLineColor(kBlue);
					gr_vnPtC[n][np][i]->SetMarkerStyle(kFullCross);
					gr_vnPtC[n][np][i]->SetMarkerColor(kBlue);
					gr_vnPtC[n][np][i]->SetLineColor(kBlue);
				} else if ( np == 3 ) {
					gr_vnPtV[n][np][i]->SetMarkerStyle(kFullDiamond);
					gr_vnPtV[n][np][i]->SetMarkerColor(kRed);
					gr_vnPtV[n][np][i]->SetLineColor(kRed);
					gr_vnPtC[n][np][i]->SetMarkerStyle(kFullDiamond);
					gr_vnPtC[n][np][i]->SetMarkerColor(kRed);
					gr_vnPtC[n][np][i]->SetLineColor(kRed);
				}
			}
		}
	}

	// eta
	TGraphErrors * gr_vnEtaV[7][4][20];
	TGraphErrors * gr_vnEtaC[7][4][20];
	memset(gr_vnEtaV, 0, sizeof(gr_vnEtaV));
	memset(gr_vnEtaC, 0, sizeof(gr_vnEtaC));

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 20; i++ ) {
				if ( pCent[np][i] == 0 ) break;
				for ( int j = 0; j < 24; j++ ) {
					dY[j] = dVeta[n][np][j][i];
					eY[j] = eVeta[n][np][j][i];
					cY[j] = cVeta[n][np][j][i];
					if (eY[j] != eY[j]) eY[j] = 999;
					if (cY[j] != cY[j]) cY[j] = 999;
				}
				gr_vnEtaV[n][np][i] = new TGraphErrors(24, etaX, dY, 0, eY);
				gr_vnEtaC[n][np][i] = new TGraphErrors(24, etaX, dY, 0, cY);
				if ( np == 0 ) {
					gr_vnEtaV[n][np][i]->SetMarkerStyle(kFullCircle);
					gr_vnEtaV[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnEtaV[n][np][i]->SetLineColor(kGreen+2);
					gr_vnEtaC[n][np][i]->SetMarkerStyle(kFullCircle);
					gr_vnEtaC[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnEtaC[n][np][i]->SetLineColor(kGreen+2);
				} else if ( np == 1 ) {
					gr_vnEtaV[n][np][i]->SetMarkerStyle(kFullSquare);
					gr_vnEtaV[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnEtaV[n][np][i]->SetLineColor(kGreen+2);
					gr_vnEtaC[n][np][i]->SetMarkerStyle(kFullSquare);
					gr_vnEtaC[n][np][i]->SetMarkerColor(kGreen+2);
					gr_vnEtaC[n][np][i]->SetLineColor(kGreen+2);
				} else if ( np == 2 ) {
					gr_vnEtaV[n][np][i]->SetMarkerStyle(kFullCross);
					gr_vnEtaV[n][np][i]->SetMarkerColor(kBlue);
					gr_vnEtaV[n][np][i]->SetLineColor(kBlue);
					gr_vnEtaC[n][np][i]->SetMarkerStyle(kFullCross);
					gr_vnEtaC[n][np][i]->SetMarkerColor(kBlue);
					gr_vnEtaC[n][np][i]->SetLineColor(kBlue);
				} else if ( np == 3 ) {
					gr_vnEtaV[n][np][i]->SetMarkerStyle(kFullDiamond);
					gr_vnEtaV[n][np][i]->SetMarkerColor(kRed);
					gr_vnEtaV[n][np][i]->SetLineColor(kRed);
					gr_vnEtaC[n][np][i]->SetMarkerStyle(kFullDiamond);
					gr_vnEtaC[n][np][i]->SetMarkerColor(kRed);
					gr_vnEtaC[n][np][i]->SetLineColor(kRed);
				}
			}
		}
	}

	// plot 
	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(20);
	latex.SetTextAlign(13);

	TF1 *finputv2 = new TF1("finputv2", "0.165646*exp(-( (x-2.64741)/1.36298 + exp( -(x-2.64741)/1.36298 ) )/2.)", 0.2, 15);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 12, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");
	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.5, 2.5, 1, 0, 0.35);
	InitHist(hframe_eta, "#eta", "v_{2}");

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	for ( int n = 2; n < 7; n++ ) {
		for ( int i = 0; i < 20; i++ ) {
			if (pCent[0][i] == 0) break;
//			cout << " n = " << n << " i = " << i << endl;
			cT->cd();
			hframe_pt->GetYaxis()->SetTitle(Form("v_{%i}",n));
			hframe_pt->Draw();


			// plot current

			int c2 = 0;
			for ( int ii = 0; ii < 20; ii++ ) {
				if ( pCent[0][i+1] >=  pCent[2][ii+1] && pCent[0][i+1] < pCent[2][ii] ) {
					c2 = ii;
					break;
				}
			}
			int c3 = 0;
			for ( int ii = 0; ii < 20; ii++ ) {
				if ( pCent[0][i+1] >=  pCent[3][ii+1] && pCent[0][i+1] < pCent[3][ii] ) {
					c3 = ii;
					break;
				}
			}

//			cout << " i = " << i << "\tc2 = " << c2 << "\tc3 = " << c3 << endl;
			TLegend * legPt = new TLegend(0.2, 0.6, 0.55, 0.9);
			legPt->SetFillColor(kWhite);
			legPt->SetTextFont(42);
			legPt->SetTextSize(0.03);
			legPt->SetBorderSize(0);

			// plot HIN-13-002
			if ( mgr_HIN13002_pPbPt[n][0][i] ) {
				mgr_HIN13002_pPbPt[n][0][i]->Draw("P");
				legPt->AddEntry(gr_HIN_13_002_pPbv22pt5, "v_{2}{2, |#Delta#eta|>2}", "p");
			}
			if ( mgr_HIN13002_pPbPt[n][1][i] ) {
				mgr_HIN13002_pPbPt[n][1][i]->Draw("P");
				legPt->AddEntry(gr_HIN_13_002_pPbv24pt5, "v_{2}{4}", "p");
			}

			if (sC) {
				gr_vnPtC[n][0][i]->Draw("Psame");
				gr_vnPtC[n][1][i]->Draw("Psame");
				gr_vnPtC[n][2][c2]->Draw("Psame");
				gr_vnPtC[n][3][c3]->Draw("Psame");
			} else {
				gr_vnPtV[n][0][i]->Draw("Psame");
				gr_vnPtV[n][1][i]->Draw("Psame");
				gr_vnPtV[n][2][c2]->Draw("Psame");
				gr_vnPtV[n][3][c3]->Draw("Psame");
			}

			if ( sSimV2 ) {
				if ( n == 2 ) {
					finputv2->Draw("same");
				}
			}

			legPt->AddEntry(gr_vnPtV[n][0][i], Form("v_{%i}{2} %i#leq N_{off} < %i", n, pCent[0][i+1], pCent[0][i]), "p");
			legPt->AddEntry(gr_vnPtV[n][1][i], Form("v_{%i}{4} %i#leq N_{off} < %i", n, pCent[1][i+1], pCent[0][i]), "p");
			legPt->AddEntry(gr_vnPtV[n][2][c2], Form("v_{%i}{6} %i#leq N_{off} < %i", n, pCent[2][c2+1], pCent[2][c2]), "p");
			legPt->AddEntry(gr_vnPtV[n][3][c2], Form("v_{%i}{8} %i#leq N_{off} < %i", n, pCent[3][c3+1], pCent[3][c3]),"p");

			legPt->Draw();
			cT->SaveAs(Form("%s/cPt_%i_%i_%i.pdf", ftxt[s1], n, i, sC));
			delete legPt;


			// plot eta
			cT->cd();
			hframe_eta->GetYaxis()->SetTitle(Form("v_{%i}",n));
			hframe_eta->Draw();

			if (sC) {
				gr_vnEtaC[n][0][i]->Draw("Psame");
				gr_vnEtaC[n][1][i]->Draw("Psame");
				gr_vnEtaC[n][2][c2]->Draw("Psame");
				gr_vnEtaC[n][3][c3]->Draw("Psame");
			} else {
				gr_vnEtaV[n][0][i]->Draw("Psame");
				gr_vnEtaV[n][1][i]->Draw("Psame");
				gr_vnEtaV[n][2][c2]->Draw("Psame");
				gr_vnEtaV[n][3][c3]->Draw("Psame");
			}
			TLegend * legEta = new TLegend(0.2, 0.6, 0.55, 0.9);
			legEta->SetFillColor(kWhite);
			legEta->SetTextFont(42);
			legEta->SetTextSize(0.03);
			legEta->SetBorderSize(0);

			legEta->AddEntry(gr_vnEtaV[n][0][i], Form("v_{%i}{2} %i#leq N_{off} < %i", n, pCent[0][i+1], pCent[0][i]), "p");
			legEta->AddEntry(gr_vnEtaV[n][1][i], Form("v_{%i}{4} %i#leq N_{off} < %i", n, pCent[1][i+1], pCent[0][i]), "p");
			legEta->AddEntry(gr_vnEtaV[n][2][c2], Form("v_{%i}{6} %i#leq N_{off} < %i", n, pCent[2][c2+1], pCent[2][c2]), "p");
			legEta->AddEntry(gr_vnEtaV[n][3][c2], Form("v_{%i}{8} %i#leq N_{off} < %i", n, pCent[3][c3+1], pCent[3][c3]),"p");

			legEta->Draw();
			cT->SaveAs(Form("%s/cEta_%i_%i_%i.pdf", ftxt[s1], n, i, sC));
			delete legEta;

		}
	}
}
