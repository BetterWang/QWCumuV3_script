#include "label.h"
#include "noff.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "HIN-11-012.h"
#include "../../style.h"

void genPlot(int s1 =2)
{

	int sC = 1;
	int sSimV2 = 0;

	bool SAVE = true;

	TFile *f;
	f = new TFile(Form("%s/outputE.root", ftxt[s1]));
	HIN_11_012();

	SetStyle();
	gStyle->SetMarkerSize(1);
	////////////
	//Get Histo

	double dC[7][4][20];
	double eC[7][4][20];

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

	double dCGap[7][20];
	double eCGap[7][20];

	double dVGap[7][20];
	double eVGap[7][20];
	double cVGap[7][20];

	double dVpGap[7][24][20];
	double eVpGap[7][24][20];
	double cVpGap[7][24][20];

	double dVetaGap[7][24][20];
	double eVetaGap[7][24][20];
	double cVetaGap[7][24][20];

	double dVcGap[7][2][20];
	double eVcGap[7][2][20];
	double cVcGap[7][2][20];

	for ( int n = 2; n < 7; n++ ) {
		TH1D * h1 = (TH1D*) f->Get(Form("hVGap%i", n));
		TH1D * h2 = (TH1D*) f->Get(Form("hcVGap%i", n));
		TH1D * hc = (TH1D*) f->Get(Form("hCGap%i", n));
		for ( int i = 0; i < 20; i++ ) {
			dVGap[n][i] = h1->GetBinContent(i+1);
			eVGap[n][i] = h1->GetBinError(i+1);
			cVGap[n][i] = h2->GetBinError(i+1);
			dCGap[n][i] = hc->GetBinContent(i+1);
			eCGap[n][i] = hc->GetBinError(i+1);
		}
		delete h1;
		delete h2;
		for ( int j = 0; j < 24; j++ ) {
			TH1D * h1 = (TH1D*) f->Get(Form("hVpGap%i_%i", n, j));
			TH1D * h2 = (TH1D*) f->Get(Form("hcVpGap%i_%i", n, j));
			TH1D * h3 = (TH1D*) f->Get(Form("hVetaGap%i_%i", n, j));
			TH1D * h4 = (TH1D*) f->Get(Form("hcVetaGap%i_%i", n, j));
			for ( int i = 0; i < 20; i++ ) {
				dVpGap[n][j][i] = h1->GetBinContent(i+1);
				eVpGap[n][j][i] = h1->GetBinError(i+1);
				cVpGap[n][j][i] = h2->GetBinError(i+1);

				dVetaGap[n][j][i] = h3->GetBinContent(i+1);
				eVetaGap[n][j][i] = h3->GetBinError(i+1);
				cVetaGap[n][j][i] = h4->GetBinError(i+1);
			}
			delete h1;
			delete h2;
			delete h3;
			delete h4;
		}
		for ( int j = 0; j < 2; j++ ) {
			TH1D * h1 = (TH1D*) f->Get(Form("hVcGap%i_%i", n, j));
			TH1D * h2 = (TH1D*) f->Get(Form("hcVcGap%i_%i", n, j));
			for ( int i = 0; i < 20; i++ ) {
				dVcGap[n][j][i] = h1->GetBinContent(i+1);
				eVcGap[n][j][i] = h1->GetBinError(i+1);
				cVcGap[n][j][i] = h2->GetBinError(i+1);
			}
			delete h1;
			delete h2;
		}
		for ( int np = 0; np < 4; np++ ) {
			TH1D * h1 = (TH1D*) f->Get(Form("hV%i%i", n, 2+2*np));
			TH1D * h2 = (TH1D*) f->Get(Form("hX%i%i", n, 2+2*np));
			TH1D * h3 = (TH1D*) f->Get(Form("hcV%i%i", n, 2+2*np));
			TH1D * h4 = (TH1D*) f->Get(Form("hcX%i%i", n, 2+2*np));
			TH1D * hc = (TH1D*) f->Get(Form("hC%i%i", n, 2+2*np));
			for ( int i = 0; i < 20; i++ ) {
				dV[n][np][i] = h1->GetBinContent(i+1);
				eV[n][np][i] = h1->GetBinError(i+1);
				cV[n][np][i] = h3->GetBinError(i+1);

				dC[n][np][i] = hc->GetBinContent(i+1);
				eC[n][np][i] = hc->GetBinError(i+1);

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

	TGraphErrors * gr_CnCentC[7][4] = {};

	TGraphErrors * gr_vnCentGapV[7] = {};
	TGraphErrors * gr_vnCentGapC[7] = {};

	TGraphErrors * gr_CnCentGapC[7] = {};

	TGraphErrors * gr_vnCCentGapV[7][2] = {};
	TGraphErrors * gr_vnCCentGapC[7][2] = {};

	TGraphErrors * gr_vnPtGapV[7][20] = {};
	TGraphErrors * gr_vnPtGapC[7][20] = {};
	TGraphErrors * gr_vnEtaGapV[7][20] = {};
	TGraphErrors * gr_vnEtaGapC[7][20] = {};

	double dY[100];
	double eY[100];
	double cY[100];

        Int_t const * pCent4 = CentPbPb4;
        Int_t const * pCent6 = CentPbPb6;
        Int_t const * pCent8 = CentPbPb8;

        Int_t const * pCent[4] = { pCent4, pCent4, pCent6, pCent8 };

	const double * CentX[4] = {CentPbPbX, CentPbPbX, CentPbPbX, CentPbPbX};

		pCent[0] = CentNoffCutPA8TeV4;
		pCent[1] = CentNoffCutPA8TeV4;
		pCent[2] = CentNoffCutPA8TeV6;
		pCent[3] = CentNoffCutPA8TeV8;

		NCent[0] = NCent8TeV4;
		NCent[1] = NCent8TeV4;
		NCent[2] = NCent8TeV6;
		NCent[3] = NCent8TeV8;

		CentX[0] = CentPPbX4;
		CentX[1] = CentPPbX4;
		CentX[2] = CentPPbX6;
		CentX[3] = CentPPbX8;

	// pT
	for ( int n = 2; n < 7; n++ ) {
		for ( int i = 0; i < NCent[0]; i++ ) {
			dY[i] = dVGap[n][i];
			eY[i] = eVGap[n][i];
			cY[i] = cVGap[n][i];
		}
		gr_vnCentGapV[n] = new TGraphErrors(NCent[0], CentX[0], dY, 0, eY);
		gr_vnCentGapC[n] = new TGraphErrors(NCent[0], CentX[0], dY, 0, cY);
		gr_vnCentGapV[n]->SetMarkerStyle(kOpenSquare);
		gr_vnCentGapC[n]->SetMarkerStyle(kOpenSquare);

		for ( int i = 0; i < NCent[0]; i++ ) {
			dY[i] = dCGap[n][i];
			eY[i] = eCGap[n][i];
		}
		gr_CnCentGapC[n] = new TGraphErrors(NCent[0], CentX[0], dY, 0, eY);
		gr_CnCentGapC[n]->SetMarkerStyle(kOpenSquare);

		for ( int i = 0; i < NCent[0]; i++ ) {
			dY[i] = dVcGap[n][0][i];
			eY[i] = eVcGap[n][0][i];
			cY[i] = cVcGap[n][0][i];
		}
		gr_vnCCentGapV[n][0] = new TGraphErrors(NCent[0], CentX[0], dY, 0, eY);
		gr_vnCCentGapC[n][0] = new TGraphErrors(NCent[0], CentX[0], dY, 0, cY);
		gr_vnCCentGapV[n][0]->SetMarkerStyle(kOpenCircle);
		gr_vnCCentGapC[n][0]->SetMarkerStyle(kOpenCircle);

		for ( int i = 0; i < NCent[0]; i++ ) {
			dY[i] = dVcGap[n][1][i];
			eY[i] = eVcGap[n][1][i];
			cY[i] = cVcGap[n][1][i];
		}
		gr_vnCCentGapV[n][1] = new TGraphErrors(NCent[0], CentX[0], dY, 0, eY);
		gr_vnCCentGapC[n][1] = new TGraphErrors(NCent[0], CentX[0], dY, 0, cY);
		gr_vnCCentGapV[n][1]->SetMarkerStyle(kOpenStar);
		gr_vnCCentGapC[n][1]->SetMarkerStyle(kOpenStar);

		for ( int i = 0; i < NCent[0]; i++ ) {
			for ( int j = 0; j < 24; j++ ) {
				dY[j] = dVpGap[n][j][i];
				eY[j] = eVpGap[n][j][i];
				cY[j] = cVpGap[n][j][i];
				if (eY[i] != eY[i]) eY[i] = 999;
				if (cY[i] != cY[i]) cY[i] = 999;
				if (dY[i] != dY[i]) dY[i] = 999;
			}
			gr_vnPtGapV[n][i] = new TGraphErrors(24, ptX, dY, 0, eY);
			gr_vnPtGapC[n][i] = new TGraphErrors(24, ptX, dY, 0, cY);
			gr_vnPtGapV[n][i]->SetMarkerStyle(kOpenSquare);
			gr_vnPtGapC[n][i]->SetMarkerStyle(kOpenSquare);

			for ( int j = 0; j < 24; j++ ) {
				dY[j] = dVetaGap[n][j][i];
				eY[j] = eVetaGap[n][j][i];
				cY[j] = cVetaGap[n][j][i];
				if (eY[i] != eY[i]) eY[i] = 999;
				if (cY[i] != cY[i]) cY[i] = 999;
				if (dY[i] != dY[i]) dY[i] = 999;
			}
			gr_vnEtaGapV[n][i] = new TGraphErrors(24, etaX, dY, 0, eY);
			gr_vnEtaGapC[n][i] = new TGraphErrors(24, etaX, dY, 0, cY);
			gr_vnEtaGapV[n][i]->SetMarkerStyle(kOpenSquare);
			gr_vnEtaGapC[n][i]->SetMarkerStyle(kOpenSquare);
		}

		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < NCent[np]; i++ ) {
				dY[i] = dV[n][np][i];
				cY[i] = cV[n][np][i];
				eY[i] = eV[n][np][i];
				if (eY[i] != eY[i]) eY[i] = 999;
				if (cY[i] != cY[i]) cY[i] = 999;
				if (dY[i] != dY[i]) dY[i] = 999;
			}
			gr_vnCentV[n][np] = new TGraphErrors(NCent[0], CentX[np], dY, 0, eY);
			gr_vnCentC[n][np] = new TGraphErrors(NCent[0], CentX[np], dY, 0, cY);
			for ( int i = 0; i < NCent[np]; i++ ) {
				dY[i] = dC[n][np][i];
				eY[i] = eC[n][np][i];
				if (dY[i] != dY[i]) dY[i] = 999;
				if (eY[i] != eY[i]) eY[i] = 999;
			}
			gr_CnCentC[n][np] = new TGraphErrors(NCent[0], CentX[np], dY, 0, eY);
			if ( np == 0 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullCircle);
				gr_vnCentV[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentV[n][np]->SetLineColor(kGreen+2);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullCircle);
				gr_vnCentC[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentC[n][np]->SetLineColor(kGreen+2);

				gr_CnCentC[n][np]->SetMarkerStyle(kFullCircle);
				gr_CnCentC[n][np]->SetMarkerColor(kGreen+2);
				gr_CnCentC[n][np]->SetLineColor(kGreen+2);
			} else if ( np == 1 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullSquare);
				gr_vnCentV[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentV[n][np]->SetLineColor(kGreen+2);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullSquare);
				gr_vnCentC[n][np]->SetMarkerColor(kGreen+2);
				gr_vnCentC[n][np]->SetLineColor(kGreen+2);

				gr_CnCentC[n][np]->SetMarkerStyle(kFullSquare);
				gr_CnCentC[n][np]->SetMarkerColor(kGreen+2);
				gr_CnCentC[n][np]->SetLineColor(kGreen+2);
			} else if ( np == 2 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullCross);
				gr_vnCentV[n][np]->SetMarkerColor(kBlue);
				gr_vnCentV[n][np]->SetLineColor(kBlue);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullCross);
				gr_vnCentC[n][np]->SetMarkerColor(kBlue);
				gr_vnCentC[n][np]->SetLineColor(kBlue);

				gr_CnCentC[n][np]->SetMarkerStyle(kFullCross);
				gr_CnCentC[n][np]->SetMarkerColor(kBlue);
				gr_CnCentC[n][np]->SetLineColor(kBlue);
			} else if ( np == 3 ) {
				gr_vnCentV[n][np]->SetMarkerStyle(kFullDiamond);
				gr_vnCentV[n][np]->SetMarkerColor(kRed);
				gr_vnCentV[n][np]->SetLineColor(kRed);
				gr_vnCentC[n][np]->SetMarkerStyle(kFullDiamond);
				gr_vnCentC[n][np]->SetMarkerColor(kRed);
				gr_vnCentC[n][np]->SetLineColor(kRed);

				gr_CnCentC[n][np]->SetMarkerStyle(kFullDiamond);
				gr_CnCentC[n][np]->SetMarkerColor(kRed);
				gr_CnCentC[n][np]->SetLineColor(kRed);
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
				gr_vnPtV[n][np][i] = new TGraphErrors(24, ptX, dY, 0, eY);
				gr_vnPtC[n][np][i] = new TGraphErrors(24, ptX, dY, 0, cY);
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

	for ( int n = 2; n < 7; n++ ) {
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
	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 10, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");
	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.5, 2.5, 1, 0, 0.35);
	InitHist(hframe_eta, "#eta", "v_{2}");
	TH2D * hframe_cent = new TH2D("hframe_cent", "", 1, 0, 400, 1, 0, 0.35);
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
			gr_vnCentGapC[n]->Draw("Psame");
			gr_vnCCentGapC[n][0]->Draw("Psame");
			gr_vnCCentGapC[n][1]->Draw("Psame");
		} else {
			gr_vnCentV[n][0]->Draw("Psame");
			gr_vnCentV[n][1]->Draw("Psame");
			gr_vnCentV[n][2]->Draw("Psame");
			gr_vnCentV[n][3]->Draw("Psame");
			gr_vnCentGapV[n]->Draw("Psame");
			gr_vnCCentGapV[n][0]->Draw("Psame");
			gr_vnCCentGapV[n][1]->Draw("Psame");
		}
		cT->SaveAs(Form("%s/cCent_%i_%i.pdf", ftxt[s1], n, sC));
		for ( int i = 0; i < NCent[0]; i++ ) {
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
//			if ( mgrHIN_vnEPpt[n][i] ) {
//				mgrHIN_vnEPpt[n][i]->Draw("P");
//				legPt->AddEntry(mgrHIN_vnEPpt[n][i]->GetListOfGraphs()->At(1), "v_{2}{EP} HIN-10-002", "p");
//			}
//			if ( mgrHIN_vn2pt[n][i] ) {
//				mgrHIN_vn2pt[n][i]->Draw("P");
//				legPt->AddEntry(mgrHIN_vn2pt[n][i]->GetListOfGraphs()->At(1), "v_{2}{2} HIN-10-002", "p");
//			}
//			if ( mgrHIN_vn4pt[n][i] ) {
//				mgrHIN_vn4pt[n][i]->Draw("P");
//				legPt->AddEntry(mgrHIN_vn4pt[n][i]->GetListOfGraphs()->At(1), "v_{2}{4} HIN-10-002", "p");
//			}

			// plot HIN-11-012
//			if ( n==2 && mgrHIN11012_v2[i] ) {
//				mgrHIN11012_v2[i]->Draw("P");
//				legPt->AddEntry(mgrHIN11012_v2[i]->GetListOfGraphs()->At(1), "v_{2}{EP} HIN-11-012", "p");
//			}

			if (sC) {
				gr_vnPtC[n][0][i]->Draw("Psame");
				gr_vnPtC[n][1][i]->Draw("Psame");
				gr_vnPtC[n][2][i]->Draw("Psame");
				gr_vnPtC[n][3][i]->Draw("Psame");
				gr_vnPtGapC[n][i]->Draw("Psame");
			} else {
				gr_vnPtV[n][0][i]->Draw("Psame");
				gr_vnPtV[n][1][i]->Draw("Psame");
				gr_vnPtV[n][2][i]->Draw("Psame");
				gr_vnPtV[n][3][i]->Draw("Psame");
				gr_vnPtGapV[n][i]->Draw("Psame");
			}

			if ( sSimV2 ) {
				if ( n == 2 ) {
					finputv2->Draw("same");
				}
			}

			legPt->AddEntry(gr_vnPtV[n][0][i], Form("v_{%i}{2} %i #leq N_{trk}^{offline} < %i", n, pCent[0][i], pCent[0][i+1]), "p");
			legPt->AddEntry(gr_vnPtV[n][1][i], Form("v_{%i}{4} %i #leq N_{trk}^{offline} < %i", n, pCent[1][i], pCent[0][i+1]), "p");
			legPt->AddEntry(gr_vnPtV[n][2][i], Form("v_{%i}{6} %i #leq N_{trk}^{offline} < %i", n, pCent[2][i], pCent[2][i+1]), "p");
			legPt->AddEntry(gr_vnPtV[n][3][i], Form("v_{%i}{8} %i #leq N_{trk}^{offline} < %i", n, pCent[3][i], pCent[3][i+1]), "p");
			legPt->AddEntry(gr_vnPtGapC[n][i], Form("v_{%i}{2, |#Delta#eta|>2.0} %i #leq N_{trk}^{offline} < %i", n, pCent[0][i], pCent[0][i+1]), "p");

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
				gr_vnEtaGapC[n][i]->Draw("Psame");
			} else {
				gr_vnEtaV[n][0][i]->Draw("Psame");
				gr_vnEtaV[n][1][i]->Draw("Psame");
				gr_vnEtaV[n][2][i]->Draw("Psame");
				gr_vnEtaV[n][3][i]->Draw("Psame");
				gr_vnEtaGapV[n][i]->Draw("Psame");
			}
			TLegend * legEta = new TLegend(0.2, 0.6, 0.55, 0.9);
			legEta->SetFillColor(kWhite);
			legEta->SetTextFont(42);
			legEta->SetTextSize(0.03);
			legEta->SetBorderSize(0);

//			legEta->AddEntry(gr_vnEtaV[n][0][i], Form("v_{%i}{2} %i #leq N_{trk}^{offline} < %i", n, pCent[0][i], pCent[0][i+1]), "p");
			legEta->AddEntry(gr_vnEtaV[n][1][i], Form("v_{%i}{4} %i #leq N_{trk}^{offline} < %i", n, pCent[1][i], pCent[0][i+1]), "p");
			legEta->AddEntry(gr_vnEtaV[n][2][i], Form("v_{%i}{6} %i #leq N_{trk}^{offline} < %i", n, pCent[2][i], pCent[2][i+1]), "p");
			legEta->AddEntry(gr_vnEtaV[n][3][i], Form("v_{%i}{8} %i #leq N_{trk}^{offline} < %i", n, pCent[3][i], pCent[3][i+1]), "p");

			legEta->Draw();
			cT->SaveAs(Form("%s/cEta_%i_%i_%i.pdf", ftxt[s1], n, i, sC));
			delete legEta;
		}
	}


	TFile * fsave;
//	ofstream txtout;
	fsave = new TFile(Form("%s/outGraph.root", ftxt[s1]),"recreate");
//	txtout.open(Form("%s/Graph.txt", ftxt[s1]));
	for ( int n = 2; n < 7; n++ ) {
		gr_vnCentGapV[n]->SetName(Form("gr_vnCentGapV_%i", n));
		gr_vnCentGapC[n]->SetName(Form("gr_vnCentGapC_%i", n));
		gr_vnCentGapV[n]->Write();
		gr_vnCentGapC[n]->Write();

		gr_CnCentGapC[n]->Write(Form("gr_CnCentGapC_%i", n));

		gr_vnCCentGapV[n][0]->SetName(Form("gr_vnCCentGapV_%i_0", n));
		gr_vnCCentGapC[n][0]->SetName(Form("gr_vnCCentGapC_%i_0", n));
		gr_vnCCentGapV[n][1]->SetName(Form("gr_vnCCentGapV_%i_1", n));
		gr_vnCCentGapC[n][1]->SetName(Form("gr_vnCCentGapC_%i_1", n));
		gr_vnCCentGapV[n][0]->Write();
		gr_vnCCentGapC[n][0]->Write();
		gr_vnCCentGapV[n][1]->Write();
		gr_vnCCentGapC[n][1]->Write();

		for ( int np = 0; np < 4; np++ ) {
			gr_vnCentC[n][np]->Write(Form("gr_vnCentC_%i_%i", n, np));
			gr_vnCentV[n][np]->Write(Form("gr_vnCentV_%i_%i", n, np));
			gr_CnCentC[n][np]->Write(Form("gr_CnCentC_%i_%i", n, np));
		}

		for ( int c = 0; c < 20; c++ ) {
			if ( gr_vnPtGapV[n][c] ) {
				gr_vnPtGapV[n][c]->SetName(Form("gr_vnPtGapV_%i_%i", n, c));
				gr_vnPtGapC[n][c]->SetName(Form("gr_vnPtGapC_%i_%i", n, c));

				gr_vnEtaGapV[n][c]->SetName(Form("gr_vnEtaGapV_%i_%i", n, c));
				gr_vnEtaGapC[n][c]->SetName(Form("gr_vnEtaGapC_%i_%i", n, c));
				gr_vnPtGapV[n][c]->Write();
				gr_vnPtGapC[n][c]->Write();
				gr_vnEtaGapV[n][c]->Write();
				gr_vnEtaGapC[n][c]->Write();
			}
		}
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 20; c++ ) {
				if (gr_vnPtV[n][np][c]) {
					gr_vnPtV[n][np][c]->SetName(Form("gr_vnPtV_%i_%i_%i", n, np, c));
					gr_vnPtV[n][np][c]->Write();

//					txtout << endl;
//					txtout << Form("# name: %s", gr_vnPtV[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
//					txtout << "# rows: " << gr_vnPtV[n][np][c]->GetN() << endl;
//					txtout << "# columns: 3" << endl;
//					for ( int i = 0; i < gr_vnPtV[n][np][c]->GetN(); i++ ) {
//						txtout << " " << gr_vnPtV[n][np][c]->GetX()[i] << " " << gr_vnPtV[n][np][c]->GetY()[i] << " " << gr_vnPtV[n][np][c]->GetEY()[i] << endl;
//					}
//					txtout << endl;
				}
				if (gr_vnPtC[n][np][c]) {
					gr_vnPtC[n][np][c]->SetName(Form("gr_vnPtC_%i_%i_%i", n, np, c));
					gr_vnPtC[n][np][c]->Write();

//					txtout << endl;
//					txtout << Form("# name: %s", gr_vnPtC[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
//					txtout << "# rows: " << gr_vnPtC[n][np][c]->GetN() << endl;
//					txtout << "# columns: 3" << endl;
//					for ( int i = 0; i < gr_vnPtC[n][np][c]->GetN(); i++ ) {
//						txtout << " " << gr_vnPtC[n][np][c]->GetX()[i] << " " << gr_vnPtC[n][np][c]->GetY()[i] << " " << gr_vnPtC[n][np][c]->GetEY()[i] << endl;
//					}
//					txtout << endl;
				}
				if (gr_vnEtaV[n][np][c]) {
					gr_vnEtaV[n][np][c]->SetName(Form("gr_vnEtaV_%i_%i_%i", n, np, c));
					gr_vnEtaV[n][np][c]->Write();

//					txtout << endl;
//					txtout << Form("# name: %s", gr_vnEtaV[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
//					txtout << "# rows: " << gr_vnEtaV[n][np][c]->GetN() << endl;
//					txtout << "# columns: 3" << endl;
//					for ( int i = 0; i < gr_vnEtaV[n][np][c]->GetN(); i++ ) {
//						txtout << " " << gr_vnEtaV[n][np][c]->GetX()[i] << " " << gr_vnEtaV[n][np][c]->GetY()[i] << " " << gr_vnEtaV[n][np][c]->GetEY()[i] << endl;
//					}
//					txtout << endl;
				}
				if (gr_vnEtaC[n][np][c]) {
					gr_vnEtaC[n][np][c]->SetName(Form("gr_vnEtaC_%i_%i_%i", n, np, c));
					gr_vnEtaC[n][np][c]->Write();

//					txtout << endl;
//					txtout << Form("# name: %s", gr_vnEtaC[n][np][c]->GetName()) << endl << "# type: matrix" << endl;
//					txtout << "# rows: " << gr_vnEtaC[n][np][c]->GetN() << endl;
//					txtout << "# columns: 3" << endl;
//					for ( int i = 0; i < gr_vnEtaC[n][np][c]->GetN(); i++ ) {
//						txtout << " " << gr_vnEtaC[n][np][c]->GetX()[i] << " " << gr_vnEtaC[n][np][c]->GetY()[i] << " " << gr_vnEtaC[n][np][c]->GetEY()[i] << endl;
//					}
//					txtout << endl;
				}
			}
		}
	}
}
