/*
 * =====================================================================================
 *
 *       Filename:  process.C
 *
 *    Description:  Histree process
 *
 *        Version:  1.0
 *        Created:  06/30/14 17:20:14
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
	int s1 = 0;

	TChain * chV = new TChain("trV");
	if ( s1 == 4 ) {
		addchain(1);
		addchain(2);
		addchain(3);
	} else {
		addchain(s1);
	}

	int gNoff;
	int gMult;
	
	double rQ[7][4];
	double iQ[7][4];
	double wQ[7][4];
	
	double rX[7][4];
	double iX[7][4];
	double wX[7][4];
	
	double rQp[7][4][24];
	double iQp[7][4][24];
	double wQp[7][4][24];
	
	double rQeta[7][4][24];
	double iQeta[7][4][24];
	double wQeta[7][4][24];
	
	double rQc[7][4][2];
	double iQc[7][4][2];
	double wQc[7][4][2];

	chV->SetBranchAddress("Noff", &gNoff);
	chV->SetBranchAddress("Mult", &gMult);
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			chV->SetBranchAddress(Form("rQ%i%i", n, 2+2*np), &rQ[n][np]);
			chV->SetBranchAddress(Form("iQ%i%i", n, 2+2*np), &iQ[n][np]);
			chV->SetBranchAddress(Form("wQ%i%i", n, 2+2*np), &wQ[n][np]);

			chV->SetBranchAddress(Form("rX%i%i", n, 2+2*np), &rX[n][np]);
			chV->SetBranchAddress(Form("iX%i%i", n, 2+2*np), &iX[n][np]);
			chV->SetBranchAddress(Form("wX%i%i", n, 2+2*np), &wX[n][np]);

			chV->SetBranchAddress(Form("rQ%i%ip", n, 2+2*np), rQp[n][np]);
			chV->SetBranchAddress(Form("iQ%i%ip", n, 2+2*np), iQp[n][np]);
			chV->SetBranchAddress(Form("wQ%i%ip", n, 2+2*np), wQp[n][np]);

			chV->SetBranchAddress(Form("rQ%i%ic", n, 2+2*np), rQc[n][np]);
			chV->SetBranchAddress(Form("iQ%i%ic", n, 2+2*np), iQc[n][np]);
			chV->SetBranchAddress(Form("wQ%i%ic", n, 2+2*np), wQc[n][np]);

			chV->SetBranchAddress(Form("rQ%i%ieta", n, 2+2*np), rQeta[n][np]);
			chV->SetBranchAddress(Form("iQ%i%ieta", n, 2+2*np), iQeta[n][np]);
			chV->SetBranchAddress(Form("wQ%i%ieta", n, 2+2*np), wQeta[n][np]);
		}
	}

	int Nevt[500];
	for ( int i = 0; i < 500; i++ ) Nevt[i] = 0;

//	TH1::SetDefaultSumw2();

	TH1D * hMult = new TH1D("hMult", "hMult", 500, 0.5, 500.5);
	TH1D * hNoff = new TH1D("hNoff", "hNoff", 500, 0.5, 500.5);

	TH1D * hQ[7][4];
	TH1D * hX[7][4];
	TH1D * hQp[7][4][24];
	TH1D * hQeta[7][4][24];
	TH1D * hQc[7][4][24];

	TH1D * hW[7][4];
	TH1D * hY[7][4];
	TH1D * hWp[7][4][24];
	TH1D * hWeta[7][4][24];
	TH1D * hWc[7][4][24];

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np] = new TH1D(Form("hQ%i%i", n, 2+2*np), "", 500, 0.5, 500.5);
			hX[n][np] = new TH1D(Form("hX%i%i", n, 2+2*np), "", 500, 0.5, 500.5);
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i] = new TH1D(Form("hQp%i%i_%i", n, 2+2*np, i), "", 500, 0.5, 500.5);
				hQeta[n][np][i] = new TH1D(Form("hQeta%i%i_%i", n, 2+2*np, i), "", 500, 0.5, 500.5);
			}
			for ( int i = 0; i < 2; i++ ) {
				hQc[n][np][i] = new TH1D(Form("hQc%i%i_%i", n, 2+2*np, i), "", 500, 0.5, 500.5);
			}

			hW[n][np] = new TH1D(Form("hW%i%i", n, 2+2*np), "", 500, 0.5, 500.5);
			hY[n][np] = new TH1D(Form("hY%i%i", n, 2+2*np), "", 500, 0.5, 500.5);
			for ( int i = 0; i < 24; i++ ) {
				hWp[n][np][i] = new TH1D(Form("hWp%i%i_%i", n, 2+2*np, i), "", 500, 0.5, 500.5);
				hWeta[n][np][i] = new TH1D(Form("hWeta%i%i_%i", n, 2+2*np, i), "", 500, 0.5, 500.5);
			}
			for ( int i = 0; i < 2; i++ ) {
				hWc[n][np][i] = new TH1D(Form("hWc%i%i_%i", n, 2+2*np, i), "", 500, 0.5, 500.5);
			}
		}
	}

	double dQ[7][4][500];
	double dX[7][4][500];
	double dQp[7][4][24][500];
	double dQeta[7][4][24][500];
	double dQc[7][4][24][500];

	double yQ[7][4][500];
	double yX[7][4][500];
	double yQp[7][4][24][500];
	double yQeta[7][4][24][500];
	double yQc[7][4][24][500];

	int ievt = 0;
	while ( chV->GetEntry(ievt) ) {
		if ( !(ievt%100000) ) cout << "!! ievt = " << ievt << endl;
		ievt++;

		for ( int n = 1; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				if ( TMath::IsNaN(rQ[n][np]) ) continue;
				dQ[n][np][gNoff] += rQ[n][np];
				yQ[n][np][gNoff] += yQ[n][np];

				dX[n][np][gNoff] += rX[n][np];
				yX[n][np][gNoff] += yX[n][np];

				for ( int i = 0; i < 24; i++ ) {
					dQp[n][np][i][gNoff] += rQp[n][np][i];
					yQp[n][np][i][gNoff] += yQp[n][np][i];

					dQeta[n][np][i][gNoff] += rQeta[n][np][i];
					yQeta[n][np][i][gNoff] += yQeta[n][np][i];
				}
				for ( int i = 0; i < 2; i++ ) {
					dQc[n][np][i][gNoff] += rQc[n][np][i];
					yQc[n][np][i][gNoff] += yQc[n][np][i];
				}
			}
		}
		hNoff->Fill(gNoff);
		hMult->Fill(gMult);
	}
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 1; c < 500; c++ ) {
				hQ[n][np]->SetBinContent(c, dQ[n][np][c]);
				hW[n][np]->SetBinContent(c, yQ[n][np][c]);
				hX[n][np]->SetBinContent(c, dX[n][np][c]);
				hY[n][np]->SetBinContent(c, yX[n][np][c]);
				for ( int i = 0; i < 24; i++ ) {
					hQp[n][np][i]->SetBinContent(c, dQp[n][np][i][c]);
					hWp[n][np][i]->SetBinContent(c, yQp[n][np][i][c]);
					hQeta[n][np][i]->SetBinContent(c, dQeta[n][np][i][c]);
					hWeta[n][np][i]->SetBinContent(c, yQeta[n][np][i][c]);
				}
				for ( int i = 0; i < 2; i++ ) {
					hQc[n][np][i]->SetBinContent(c, dQc[n][np][i][c]);
					hWc[n][np][i]->SetBinContent(c, yQc[n][np][i][c]);
				}
			}
		}
	}

	TFile * fwrite = new TFile(Form("%s/output.root", ftxt[s1]), "recreate");
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np]->Write();
			hW[n][np]->Write();
			hX[n][np]->Write();
			hY[n][np]->Write();
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i]->Write();
				hWp[n][np][i]->Write();
				hQeta[n][np][i]->Write();
				hWeta[n][np][i]->Write();
			}
			for ( int i = 0; i < 2; i++ ) {
				hQc[n][np][i]->Write();
				hWc[n][np][i]->Write();
			}
		}
	}
	hNoff->Write();
	hMult->Write();
}
