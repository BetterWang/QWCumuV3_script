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
	int s1 = 4;
	
	bool SAVE = true;

	TFile *f = new TFile(Form("%s/outputE.root", ftxt[s1]));

#include "../../style.h"
	SetStyle();
	////////////
	//Get Histo

	double dV[7][4][20];
	double dX[7][4][20];
	double eV[7][4][20];
	double eX[7][4][20];

	double dVp[7][4][24][20];
	double dVeta[7][4][24][20];
	double dVc[7][4][2][20];
	double eVp[7][4][24][20];
	double eVeta[7][4][24][20];
	double eVc[7][4][2][20];

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			TH1D * h1 = (TH1D*) f->Get(Form("hV%i%i", n, 2+2*np));
			TH1D * h2 = (TH1D*) f->Get(Form("hX%i%i", n, 2+2*np));
			for ( int i = 0; i < 20; i++ ) {
				dV[n][np][i] = h1->GetBinContent(i+1);
				dX[n][np][i] = h2->GetBinContent(i+1);
				eV[n][np][i] = h1->GetBinError(i+1);
				eX[n][np][i] = h2->GetBinError(i+1);
			}
			delete h1;
			delete h2;

			for ( int j = 0; j < 24; j++ ) {
				h1 = (TH1D*) f->Get(Form("hVp%i%i_%i", n, 2+2*np, j));
				h2 = (TH1D*) f->Get(Form("hVeta%i%i_%i", n, 2+2*np, j));
				for ( int i = 0; i < 20; i++ ) {
					dVp[n][np][j][i] = h1->GetBinContent(i+1);
					dVeta[n][np][j][i] = h2->GetBinContent(i+1);
					eVp[n][np][j][i] = h1->GetBinError(i+1);
					eVeta[n][np][j][i] = h2->GetBinError(i+1);
				}
				delete h1;
				delete h2;
			}
			for ( int j = 0; j < 2; j++ ) {
				h1 = (TH1D*) f->Get(Form("hVc%i%i_%i", n, 2+2*np, j));
				for ( int i = 0; i < 20; i++ ) {
					dVc[n][np][j][i] = h1->GetBinContent(i+1);
					eVc[n][np][j][i] = h1->GetBinError(i+1);
				}
				delete h1;
			}
		}
	}

}
