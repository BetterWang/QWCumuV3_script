#include "label.h"
#include "noff.h"
#include "../../style.h"
#include "HIN-10-002.h"

void genPlot(int s1 =2)
{

	int sC = 1;
	int sSimV2 = 0;

	bool SAVE = true;

	TFile *f = new TFile(Form("%s/outputE.root", ftxt[s1]));
//	gROOT->Macro("HIN-10-002.C");
	HIN_10_002();

	SetStyle();
	gStyle->SetMarkerSize(1);
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
				cV[n][np][i] = h3->GetBinContent(i+1);

				dX[n][np][i] = h2->GetBinContent(i+1);
				eX[n][np][i] = h2->GetBinError(i+1);
				cX[n][np][i] = h4->GetBinContent(i+1);
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

					dVeta[n][np][j][i] = h2->GetBinContent(i+1);
					eVeta[n][np][j][i] = h2->GetBinError(i+1);
					cVeta[n][np][j][i] = h4->GetBinError(i+1);
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

				}
				delete h1;
				delete h2;
			}
		}
	}

	// TGraphErrors
	TGraphErrors * gr_vnPtV[7][4][20] = {};
	TGraphErrors * gr_vnPtC[7][4][20] = {};
	TGraphErrors * gr_vnCentV[7][4] = {};
	TGraphErrors * gr_vnCentC[7][4] = {};

	double dY[100];
	double eY[100];
	double cY[100];

        Int_t const * pCent4 = CentPbPb4;
        Int_t const * pCent6 = CentPbPb6;
        Int_t const * pCent8 = CentPbPb8;

        Int_t const * pCent[4] = { pCent4, pCent4, pCent6, pCent8 };

	// pT
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 14; i++ ) {
				dY[i] = dV[n][np][i];
				cY[i] = cV[n][np][i];
				eY[i] = eV[n][np][i];
				if (eY[i] != eY[i]) eY[i] = 999;
				if (cY[i] != cY[i]) cY[i] = 999;
				if (dY[i] != dY[i]) dY[i] = 999;
			}
			gr_vnCentV[n][np] = new TGraphErrors(14, CentPbPbX, dY, 0, eY);
			gr_vnCentC[n][np] = new TGraphErrors(14, CentPbPbX, cY, 0, eY);
			if ( np == 0 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullCircle);
				gr_vnCentV[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentV[n][np]->SetLineColor(kGreen+2);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullCircle);
				gr_vnCentC[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentC[n][np]->SetLineColor(kGreen+2);
			} else if ( np == 1 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullSquare);
				gr_vnCentV[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentV[n][np]->SetLineColor(kGreen+2);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullSquare);
				gr_vnCentC[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentC[n][np]->SetLineColor(kGreen+2);
			} else if ( np == 2 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullCross);
				gr_vnCentV[n][np]->SetMarkerColor(kBlue);
				gr_vnCentV[n][np]->SetLineColor(kBlue);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullCross);
				gr_vnCentC[n][np]->SetMarkerColor(kBlue);
				gr_vnCentC[n][np]->SetLineColor(kBlue);
			} else if ( np == 3 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullDiamond);
				gr_vnCentV[n][np]->SetMarkerColor(kRed);
				gr_vnCentV[n][np]->SetLineColor(kRed);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullDiamond);
				gr_vnCentC[n][np]->SetMarkerColor(kRed);
				gr_vnCentC[n][np]->SetLineColor(kRed);
			}

			for ( int i = 0; i < 20; i++ ) {
				//if ( pCent[np][i] == 0 ) break;
				for ( int j = 0; j < 23; j++ ) {
					dY[j] = dVp[n][np][j][i];
					eY[j] = eVp[n][np][j][i];
					cY[j] = cVp[n][np][j][i];
					if (eY[j] != eY[j]) eY[j] = 999;
					if (cY[j] != cY[j]) cY[j] = 999;
				}
				gr_vnPtV[n][np][i] = new TGraphErrors(23, ptX, dY, 0, eY);
				gr_vnPtC[n][np][i] = new TGraphErrors(23, ptX, dY, 0, cY);
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
	TGraphErrors * gr_vnEtaV[7][4][20] = {};
	TGraphErrors * gr_vnEtaC[7][4][20] = {};

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 20; i++ ) {
				//if ( pCent[np][i] == 0 ) break;
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

//	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 12, 1, 0, 0.35);
	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 120, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");
	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.5, 2.5, 1, 0, 0.35);
	InitHist(hframe_eta, "#eta", "v_{2}");
	TH2D * hframe_cent = new TH2D("hframe_cent", "", 1, 0, 100, 1, 0, 0.35);
	InitHist(hframe_cent, "Centrality", "v_{2}");

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	for ( int n = 2; n < 7; n++ ) {
		cT->cd();
		hframe_cent->GetYaxis()->SetTitle(Form("v_{%i}",n));
		hframe_cent->Draw();
		if (sC) {
			gr_vnCentC[n][0]->Draw("Psame");
			gr_vnCentC[n][1]->Draw("Psame");
			gr_vnCentC[n][2]->Draw("Psame");
			gr_vnCentC[n][3]->Draw("Psame");
		} else {
			gr_vnCentV[n][0]->Draw("Psame");
			gr_vnCentV[n][1]->Draw("Psame");
			gr_vnCentV[n][2]->Draw("Psame");
			gr_vnCentV[n][3]->Draw("Psame");
		}
		cT->SaveAs(Form("%s/cCent_%i_%i.pdf", ftxt[s1], n, sC));
		for ( int i = 0; i < 14; i++ ) {
			//if (pCent[0][i] == 0) break;
			cT->cd();
			hframe_pt->GetYaxis()->SetTitle(Form("v_{%i}",n));
			hframe_pt->Draw();

			TLegend * legPt = new TLegend(0.2, 0.7, 0.55, 0.9);
			legPt->SetFillColor(kWhite);
			legPt->SetTextFont(42);
			legPt->SetTextSize(0.03);
			legPt->SetBorderSize(0);

			// plot HIN-10-002
			if ( mgrHIN_vnEPpt[n][i] ) {
				mgrHIN_vnEPpt[n][i]->Draw("P");
				legPt->AddEntry(mgrHIN_vnEPpt[n][i]->GetListOfGraphs()->At(1), "v_{2}{EP} HIN-10-002", "p");
			}
			if ( mgrHIN_vn2pt[n][i] ) {
				mgrHIN_vn2pt[n][i]->Draw("P");
				legPt->AddEntry(mgrHIN_vn2pt[n][i]->GetListOfGraphs()->At(1), "v_{2}{2} HIN-10-002", "p");
			}
			if ( mgrHIN_vn4pt[n][i] ) {
				mgrHIN_vn4pt[n][i]->Draw("P");
				legPt->AddEntry(mgrHIN_vn4pt[n][i]->GetListOfGraphs()->At(1), "v_{2}{4} HIN-10-002", "p");
			}


			if (sC) {
				gr_vnPtC[n][0][i]->Draw("Psame");
				gr_vnPtC[n][1][i]->Draw("Psame");
//				gr_vnPtC[n][2][i]->Draw("Psame");
//				gr_vnPtC[n][3][i]->Draw("Psame");
			} else {
				gr_vnPtV[n][0][i]->Draw("Psame");
				gr_vnPtV[n][1][i]->Draw("Psame");
//				gr_vnPtV[n][2][i]->Draw("Psame");
//				gr_vnPtV[n][3][i]->Draw("Psame");
			}

			if ( sSimV2 ) {
				if ( n == 2 ) {
					finputv2->Draw("same");
				}
			}

			legPt->AddEntry(gr_vnPtV[n][0][i], Form("v_{%i}{2} %i%% < Centrality < %i%%", n, pCent[0][i]/2, pCent[0][i+1]/2), "p");
			legPt->AddEntry(gr_vnPtV[n][1][i], Form("v_{%i}{4} %i%% < Centrality < %i%%", n, pCent[1][i]/2, pCent[0][i+1]/2), "p");
			legPt->AddEntry(gr_vnPtV[n][2][i], Form("v_{%i}{6} %i%% < Centrality < %i%%", n, pCent[2][i]/2, pCent[2][i+1]/2), "p");
			legPt->AddEntry(gr_vnPtV[n][3][i], Form("v_{%i}{8} %i%% < Centrality < %i%%", n, pCent[3][i]/2, pCent[3][i+1]/2), "p");

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
				gr_vnEtaC[n][2][i]->Draw("Psame");
				gr_vnEtaC[n][3][i]->Draw("Psame");
			} else {
				gr_vnEtaV[n][0][i]->Draw("Psame");
				gr_vnEtaV[n][1][i]->Draw("Psame");
				gr_vnEtaV[n][2][i]->Draw("Psame");
				gr_vnEtaV[n][3][i]->Draw("Psame");
			}
			TLegend * legEta = new TLegend(0.2, 0.6, 0.55, 0.9);
			legEta->SetFillColor(kWhite);
			legEta->SetTextFont(42);
			legEta->SetTextSize(0.03);
			legEta->SetBorderSize(0);

			legEta->AddEntry(gr_vnEtaV[n][0][i], Form("v_{%i}{2} %i%% < Centrality < %i%%", n, pCent[0][i]/2, pCent[0][i+1]/2), "p");
			legEta->AddEntry(gr_vnEtaV[n][1][i], Form("v_{%i}{4} %i%% < Centrality < %i%%", n, pCent[1][i]/2, pCent[0][i+1]/2), "p");
			legEta->AddEntry(gr_vnEtaV[n][2][i], Form("v_{%i}{6} %i%% < Centrality < %i%%", n, pCent[2][i]/2, pCent[2][i+1]/2), "p");
			legEta->AddEntry(gr_vnEtaV[n][3][i], Form("v_{%i}{8} %i%% < Centrality < %i%%", n, pCent[3][i]/2, pCent[3][i+1]/2), "p");

			legEta->Draw();
			cT->SaveAs(Form("%s/cEta_%i_%i_%i.pdf", ftxt[s1], n, i, sC));
			delete legEta;
		}
	}


	TFile * fsave = new TFile(Form("%s/outGraph.root", ftxt[s1]),"recreate");
	ofstream txtout;
	txtout.open(Form("%s/Graph.txt", ftxt[s1]));
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 20; c++ ) {
				if (gr_vnPtV[n][np][c]) {
					gr_vnPtV[n][np][c]->SetName(Form("gr_vnPtV_%i_%i_%i", n, np, c));
					gr_vnPtV[n][np][c]->Write();

					txtout << endl;
					txtout << Form("# name: %s", gr_vnPtV[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
					txtout << "# rows: " << gr_vnPtV[n][np][c]->GetN() << endl;
					txtout << "# columns: 3" << endl;
					for ( int i = 0; i < gr_vnPtV[n][np][c]->GetN(); i++ ) {
						txtout << " " << gr_vnPtV[n][np][c]->GetX()[i] << " " << gr_vnPtV[n][np][c]->GetY()[i] << " " << gr_vnPtV[n][np][c]->GetEY()[i] << endl;
					}
					txtout << endl;
				}
				if (gr_vnPtC[n][np][c]) {
					gr_vnPtC[n][np][c]->SetName(Form("gr_vnPtC_%i_%i_%i", n, np, c));
					gr_vnPtC[n][np][c]->Write();

					txtout << endl;
					txtout << Form("# name: %s", gr_vnPtC[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
					txtout << "# rows: " << gr_vnPtC[n][np][c]->GetN() << endl;
					txtout << "# columns: 3" << endl;
					for ( int i = 0; i < gr_vnPtC[n][np][c]->GetN(); i++ ) {
						txtout << " " << gr_vnPtC[n][np][c]->GetX()[i] << " " << gr_vnPtC[n][np][c]->GetY()[i] << " " << gr_vnPtC[n][np][c]->GetEY()[i] << endl;
					}
					txtout << endl;
				}
				if (gr_vnEtaV[n][np][c]) {
					gr_vnEtaV[n][np][c]->SetName(Form("gr_vnEtaV_%i_%i_%i", n, np, c));
					gr_vnEtaV[n][np][c]->Write();

					txtout << endl;
					txtout << Form("# name: %s", gr_vnEtaV[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
					txtout << "# rows: " << gr_vnEtaV[n][np][c]->GetN() << endl;
					txtout << "# columns: 3" << endl;
					for ( int i = 0; i < gr_vnEtaV[n][np][c]->GetN(); i++ ) {
						txtout << " " << gr_vnEtaV[n][np][c]->GetX()[i] << " " << gr_vnEtaV[n][np][c]->GetY()[i] << " " << gr_vnEtaV[n][np][c]->GetEY()[i] << endl;
					}
					txtout << endl;
				}
				if (gr_vnEtaC[n][np][c]) {
					gr_vnEtaC[n][np][c]->SetName(Form("gr_vnEtaC_%i_%i_%i", n, np, c));
					gr_vnEtaC[n][np][c]->Write();

					txtout << endl;
					txtout << Form("# name: %s", gr_vnEtaC[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
					txtout << "# rows: " << gr_vnEtaC[n][np][c]->GetN() << endl;
					txtout << "# columns: 3" << endl;
					for ( int i = 0; i < gr_vnEtaC[n][np][c]->GetN(); i++ ) {
						txtout << " " << gr_vnEtaC[n][np][c]->GetX()[i] << " " << gr_vnEtaC[n][np][c]->GetY()[i] << " " << gr_vnEtaC[n][np][c]->GetEY()[i] << endl;
					}
					txtout << endl;
				}
			}
		}
	}
}
