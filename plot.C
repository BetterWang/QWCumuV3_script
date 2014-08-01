
{
#include "label.h"
#include "noff.h"
	int s1 = 1;
	TFile *f = new TFile(Form("%s/outputC.root", ftxt[s1]));

	////////////
	// HIN-13-002
	gROOT->Macro("HIN-13-002.C");

#include "../../style.h"
	SetStyle();
	////////////
	//Get Histo

	double dC[7][4][20];
	double wC[7][4][20];
	double dD[7][4][20];
	double wD[7][4][20];

	double dCp[7][4][24][20];
	double wCp[7][4][24][20];
	double dCeta[7][4][24][20];
	double wCeta[7][4][24][20];
	double dCc[7][4][2][20];
	double wCc[7][4][2][20];

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			TH1D * h1 = (TH1D*) f->Get(Form("hC%i%i", n, 2+2*np));
			TH1D * h2 = (TH1D*) f->Get(Form("hD%i%i", n, 2+2*np));
			TH1D * h3 = (TH1D*) f->Get(Form("hW%i%i", n, 2+2*np));
			TH1D * h4 = (TH1D*) f->Get(Form("hX%i%i", n, 2+2*np));
			for ( int i = 0; i < 20; i++ ) {
				dC[n][np][i] = h1->GetBinContent(i+1);
				dD[n][np][i] = h2->GetBinContent(i+1);
				wC[n][np][i] = h3->GetBinContent(i+1);
				wD[n][np][i] = h4->GetBinContent(i+1);
			}
			delete h1;
			delete h2;
			delete h3;
			delete h4;
			for ( int j = 0; j < 24; j++ ) {
				h1 = (TH1D*) f->Get(Form("hCp%i%i_%i", n, 2+2*np, j));
				h2 = (TH1D*) f->Get(Form("hWp%i%i_%i", n, 2+2*np, j));
				h3 = (TH1D*) f->Get(Form("hCeta%i%i_%i", n, 2+2*np, j));
				h4 = (TH1D*) f->Get(Form("hWeta%i%i_%i", n, 2+2*np, j));
				for ( int i = 0; i < 20; i++ ) {
					dCp[n][np][j][i] = h1->GetBinContent(i+1);
					wCp[n][np][j][i] = h2->GetBinContent(i+1);
					dCeta[n][np][j][i] = h3->GetBinContent(i+1);
					wCeta[n][np][j][i] = h4->GetBinContent(i+1);
				}
				delete h1;
				delete h2;
				delete h3;
				delete h4;
			}

			for ( int j = 0; j < 2; j++ ) {
				h1 = (TH1D*) f->Get(Form("hCc%i%i_%i", n, 2+2*np, j));
				h2 = (TH1D*) f->Get(Form("hWc%i%i_%i", n, 2+2*np, j));
				for ( int i = 0; i < 20; i++ ) {
					dCc[n][np][j][i] = h1->GetBinContent(i+1);
					wCc[n][np][j][i] = h2->GetBinContent(i+1);
				}
				delete h1;
				delete h2;
			}
		}
	}

	////////////
	
	double dV[7][4][20];
	double dX[7][4][20];

	double dVp[7][4][24][20];
	double dVeta[7][4][24][20];
	double dVc[7][4][24][20];

	for ( int n = 1; n < 7; n++ ) {
		for ( int i = 0; i < 20; i++ ) {
			double C2 = dC[n][0][i];
			double C4 = dC[n][1][i];
			double C6 = dC[n][2][i];
			double C8 = dC[n][3][i];

			double V2, V4, V6, V8;

			if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
			if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
			if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
			if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

			dV[n][0][i] = V2;
			dV[n][1][i] = V4;
			dV[n][2][i] = V6;
			dV[n][3][i] = V8;

			C2 = dD[n][0][i];
			C4 = dD[n][1][i];
			C6 = dD[n][2][i];
			C8 = dD[n][3][i];
			if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
			if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
			if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
			if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);
			dX[n][0][i] = V2;
			dX[n][1][i] = V4;
			dX[n][2][i] = V6;
			dX[n][3][i] = V8;

			for ( int j = 0; j < 24; j++ ) {
				C2 = dC[n][0][i];
				C4 = dC[n][1][i];
				C6 = dC[n][2][i];
				C8 = dC[n][3][i];

				double C2p = dCp[n][0][j][i];
				double C4p = dCp[n][1][j][i];
				double C6p = dCp[n][2][j][i];
				double C8p = dCp[n][3][j][i];

				if ( C2 > 0 ) V2 =       C2p/pow(C2, 1./2) ; else V2 = -fabs(C2p/pow(-C2, 1./2));
				if ( C4 > 0 ) V4 = -fabs(C4p/pow(C4, 3./4)); else V4 =       C4p/pow(-C4, 3./4);
				if ( C6 > 0 ) V6 =       C6p/pow(C6, 5./6) ; else V6 = -fabs(C6p/pow(-C6, 5./6));
				if ( C8 > 0 ) V8 = -fabs(C8p/pow(C8, 1./8)); else V8 =       C8p/pow(-C8, 1./8);

				dVp[n][0][j][i] = V2;
				dVp[n][1][j][i] = V4;
				dVp[n][2][j][i] = V6;
				dVp[n][3][j][i] = V8;

				C2p = dCeta[n][0][j][i];
				C4p = dCeta[n][1][j][i];
				C6p = dCeta[n][2][j][i];
				C8p = dCeta[n][3][j][i];

				if ( C2 > 0 ) V2 =       C2p/pow(C2, 1./2) ; else V2 = -fabs(C2p/pow(-C2, 1./2));
				if ( C4 > 0 ) V4 = -fabs(C4p/pow(C4, 3./4)); else V4 =       C4p/pow(-C4, 3./4);
				if ( C6 > 0 ) V6 =       C6p/pow(C6, 5./6) ; else V6 = -fabs(C6p/pow(-C6, 5./6));
				if ( C8 > 0 ) V8 = -fabs(C8p/pow(C8, 1./8)); else V8 =       C8p/pow(-C8, 1./8);

				dVeta[n][0][j][i] = V2;
				dVeta[n][1][j][i] = V4;
				dVeta[n][2][j][i] = V6;
				dVeta[n][3][j][i] = V8;
			}

			for ( int j = 0; j < 2; j++ ) {
				C2 = dC[n][0][i];
				C4 = dC[n][1][i];
				C6 = dC[n][2][i];
				C8 = dC[n][3][i];

				double C2p = dCc[n][0][j][i];
				double C4p = dCc[n][1][j][i];
				double C6p = dCc[n][2][j][i];
				double C8p = dCc[n][3][j][i];

				if ( C2 > 0 ) V2 =       C2p/pow(C2, 1./2) ; else V2 = -fabs(C2p/pow(-C2, 1./2));
				if ( C4 > 0 ) V4 = -fabs(C4p/pow(C4, 3./4)); else V4 =       C4p/pow(-C4, 3./4);
				if ( C6 > 0 ) V6 =       C6p/pow(C6, 5./6) ; else V6 = -fabs(C6p/pow(-C6, 5./6));
				if ( C8 > 0 ) V8 = -fabs(C8p/pow(C8, 1./8)); else V8 =       C8p/pow(-C8, 1./8);

				dVc[n][0][j][i] = V2;
				dVc[n][1][j][i] = V4;
				dVc[n][2][j][i] = V6;
				dVc[n][3][j][i] = V8;
			}
		}
	}

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 6, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");

	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);
	hframe_pt->Draw();
	mgr_HIN_13_002_pPbv22pt7->Draw();
	mgr_HIN_13_002_pPbv24pt7->Draw();


}
