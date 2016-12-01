#include "label.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TMath.h>
using namespace std;
void process(int s1 = 0, int s2 = 10, int s3 = 10)
{
//	int s1 = 4;
//	int s2 = 10;
//	int s3 = 10;

	cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
	TH1::SetDefaultSumw2();
	addchain(s1);

	int gNoff;
	int gMult;

	double rQGap[7] = {};
	double wQGap[7] = {};

	double rQpGap[7][24] = {};
	double wQpGap[7][24] = {};

	double rQetaGap[7][24] = {};
	double wQetaGap[7][24] = {};

	double rQcGap[7][2] = {};
	double wQcGap[7][2] = {};

	double rQ[7][4] = {};
//	double iQ[7][4] = {};
	double wQ[7][4] = {};

	double rX[7][4] = {};
//	double iX[7][4] = {};
	double wX[7][4] = {};

	double rQp[7][4][24] = {};
//	double iQp[7][4][24] = {};
	double wQp[7][4][24] = {};

	double rQeta[7][4][24] = {};
//	double iQeta[7][4][24] = {};
	double wQeta[7][4][24] = {};

	double rQc[7][4][2] = {};
//	double iQc[7][4][2] = {};
	double wQc[7][4][2] = {};

	chV->SetBranchAddress("Noff", &gNoff);
	chV->SetBranchAddress("Mult", &gMult);

	chV->SetBranchAddress("wQGap22", &wQGap[2]);
	chV->SetBranchAddress("wQpGap22", wQpGap[2]);
	chV->SetBranchAddress("wQetaGap22", wQetaGap[2]);
	chV->SetBranchAddress("wQcGap22", wQcGap[2]);


	for ( int n = 2; n < 7; n++ ) {
		chV->SetBranchAddress(Form("rQGap%i2", n), &rQGap[n]);
		chV->SetBranchAddress(Form("rQpGap%i2", n), &rQpGap[n]);
		chV->SetBranchAddress(Form("rQetaGap%i2", n), &rQetaGap[n]);
		chV->SetBranchAddress(Form("rQcGap%i2", n), &rQcGap[n]);
	}
	for ( int np = 0; np < 4; np++ ) {
		for ( int n = 2; n < 7; n++ ) {
			chV->SetBranchAddress(Form("rQ%i%i", n, 2+2*np), &rQ[n][np]);
//			chV->SetBranchAddress(Form("iQ%i%i", n, 2+2*np), &iQ[n][np]);

			chV->SetBranchAddress(Form("rX%i%i", n, 2+2*np), &rX[n][np]);
//			chV->SetBranchAddress(Form("iX%i%i", n, 2+2*np), &iX[n][np]);

			chV->SetBranchAddress(Form("rQ%i%ip", n, 2+2*np), rQp[n][np]);
//			chV->SetBranchAddress(Form("iQ%i%ip", n, 2+2*np), iQp[n][np]);

			chV->SetBranchAddress(Form("rQ%i%ic", n, 2+2*np), rQc[n][np]);
//			chV->SetBranchAddress(Form("iQ%i%ic", n, 2+2*np), iQc[n][np]);

			chV->SetBranchAddress(Form("rQ%i%ieta", n, 2+2*np), rQeta[n][np]);
//			chV->SetBranchAddress(Form("iQ%i%ieta", n, 2+2*np), iQeta[n][np]);
		}
		int n = 2;
		chV->SetBranchAddress(Form("wQ%i%i", n, 2+2*np), &wQ[n][np]);
		chV->SetBranchAddress(Form("wX%i%i", n, 2+2*np), &wX[n][np]);
		chV->SetBranchAddress(Form("wQ%i%ip", n, 2+2*np), wQp[n][np]);
		chV->SetBranchAddress(Form("wQ%i%ic", n, 2+2*np), wQc[n][np]);
		chV->SetBranchAddress(Form("wQ%i%ieta", n, 2+2*np), wQeta[n][np]);
	}

//	int Nevt[500] = {};


	TH1D * hMult = new TH1D("hMult", "hMult", 1000, -0.5, 999.5);
	TH1D * hNoff = new TH1D("hNoff", "hNoff", 1000, -0.5, 999.5);

	TH1D * hQGap[7] = {};
	TH1D * hQpGap[7][24] = {};
	TH1D * hQetaGap[7][24] = {};
	TH1D * hQcGap[7][2] = {};

	TH1D * hWQGap[7] = {};
	TH1D * hWQpGap[7][24] = {};
	TH1D * hWQetaGap[7][24] = {};
	TH1D * hWQcGap[7][2] = {};


	TH1D * hQ[7][4] = {};
	TH1D * hX[7][4] = {};
	TH1D * hQp[7][4][24] = {};
	TH1D * hQeta[7][4][24] = {};
	TH1D * hQc[7][4][2] = {};

	TH1D * hW[7][4] = {};
	TH1D * hY[7][4] = {};
	TH1D * hWp[7][4][24] = {};
	TH1D * hWeta[7][4][24] = {};
	TH1D * hWc[7][4][2] = {};

	// book histo

	for ( int n = 2; n < 7; n++ ) {
		hQGap[n] = new TH1D(Form("hQGap%i", n), Form("hQGap%i", n), 600, -0.5, 599.5);
		hWQGap[n] = new TH1D(Form("hWQGap%i", n), Form("hWQGap%i", n), 600, -0.5, 599.5);

		for ( int i = 0; i < 24; i++ ) {
			hQpGap[n][i] = new TH1D(Form("hQpGap%i%i", n, i), Form("hQpGap%i%i", n, i), 600, -0.5, 599.5);
			hWQpGap[n][i] = new TH1D(Form("hWQpGap%i%i", n, i), Form("hWQpGap%i%i", n, i), 600, -0.5, 599.5);
			hQetaGap[n][i] = new TH1D(Form("hQetaGap%i%i", n, i), Form("hQetaGap%i%i", n, i), 600, -0.5, 599.5);
			hWQetaGap[n][i] = new TH1D(Form("hWQetaGap%i%i", n, i), Form("hWQetaGap%i%i", n, i), 600, -0.5, 599.5);
		}
		for ( int i = 0; i < 2; i++ ) {
			hQcGap[n][i] = new TH1D(Form("hQcGap%i%i", n, i), Form("hQcGap%i%i", n, i), 600, -0.5, 599.5);
			hWQcGap[n][i] = new TH1D(Form("hWQcGap%i%i", n, i), Form("hWQcGap%i%i", n, i), 600, -0.5, 599.5);
		}

		for ( int np = 0; np < 4; np++ ) {
			hQ[n][np] = new TH1D(Form("hQ%i%i", n, 2+2*np), Form("hQ%i%i", n, 2+2*np), 600, -0.5, 599.5);
			hX[n][np] = new TH1D(Form("hX%i%i", n, 2+2*np), Form("hX%i%i", n, 2+2*np), 600, -0.5, 599.5);
			for ( int i = 0; i < 24; i++ ) {
				hQp[n][np][i] = new TH1D(Form("hQp%i%i_%i", n, 2+2*np, i), Form("hQp%i%i_%i", n, 2+2*np, i), 600, -0.5, 599.5);
				hQeta[n][np][i] = new TH1D(Form("hQeta%i%i_%i", n, 2+2*np, i), Form("hQeta%i%i_%i", n, 2+2*np, i), 600, -0.5, 599.5);
			}
			for ( int i = 0; i < 2; i++ ) {
				hQc[n][np][i] = new TH1D(Form("hQc%i%i_%i", n, 2+2*np, i), Form("hQc%i%i_%i", n, 2+2*np, i), 600, -0.5, 599.5);
			}

			hW[n][np] = new TH1D(Form("hW%i%i", n, 2+2*np), Form("hW%i%i", n, 2+2*np), 600, -0.5, 599.5);
			hY[n][np] = new TH1D(Form("hY%i%i", n, 2+2*np), Form("hY%i%i", n, 2+2*np), 600, -0.5, 599.5);
			for ( int i = 0; i < 24; i++ ) {
				hWp[n][np][i] = new TH1D(Form("hWp%i%i_%i", n, 2+2*np, i), Form("hWp%i%i_%i", n, 2+2*np, i), 600, -0.5, 599.5);
				hWeta[n][np][i] = new TH1D(Form("hWeta%i%i_%i", n, 2+2*np, i), Form("hWeta%i%i_%i", n, 2+2*np, i), 600, -0.5, 599.5);
			}
			for ( int i = 0; i < 2; i++ ) {
				hWc[n][np][i] = new TH1D(Form("hWc%i%i_%i", n, 2+2*np, i), Form("hWc%i%i_%i", n, 2+2*np, i), 600, -0.5, 599.5);
			}
		}
	}

	double dQGap[7][600] = {};
	double yQGap[7][600] = {};

	double dQpGap[7][24][600] = {};
	double yQpGap[7][24][600] = {};

	double dQetaGap[7][24][600] = {};
	double yQetaGap[7][24][600] = {};

	double dQcGap[7][2][600] = {};
	double yQcGap[7][2][600] = {};

	double dQ[7][4][600] = {};
	double dX[7][4][600] = {};
	double dQp[7][4][24][600] = {};
	double dQeta[7][4][24][600] = {};
	double dQc[7][4][2][600] = {};

	double yQ[7][4][600] = {};
	double yX[7][4][600] = {};
	double yQp[7][4][24][600] = {};
	double yQeta[7][4][24][600] = {};
	double yQc[7][4][2][600] = {};

	unsigned int ievt = 0;
	if (s2!=s3) ievt = s2;
	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
//		cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;
		//if ( (s2!=s3) && ((ievt%s3)!=s2) ) continue;
		if (gNoff >=600) continue;
		for ( int n = 3; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				wQ[n][np] = wQ[2][np];
				wX[n][np] = wX[2][np];
				for ( int i = 0; i < 24; i++ ) {
					wQp[n][np][i] = wQp[2][np][i];
					wQeta[n][np][i] = wQeta[2][np][i];
				}
				for ( int i = 0; i < 2; i++ ) {
					wQc[n][np][i] = wQc[2][np][i];
				}
			}
			wQGap[n] = wQGap[2];
			for ( int i = 0; i < 24; i++ ) {
				wQpGap[n][i] = wQpGap[2][i];
				wQetaGap[n][i] = wQetaGap[2][i];
			}
			for ( int i = 0; i < 2; i++ ) {
				wQcGap[n][i] = wQcGap[2][i];
			}
		}

		for ( int n = 2; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				if ( TMath::IsNaN(rQ[n][np]) ) continue;
				dQ[n][np][gNoff] += rQ[n][np];
				yQ[n][np][gNoff] += wQ[n][np];

				dX[n][np][gNoff] += rX[n][np];
				yX[n][np][gNoff] += wX[n][np];

				for ( int i = 0; i < 24; i++ ) {
					dQp[n][np][i][gNoff] += rQp[n][np][i];
					yQp[n][np][i][gNoff] += wQp[n][np][i];

					dQeta[n][np][i][gNoff] += rQeta[n][np][i];
					yQeta[n][np][i][gNoff] += wQeta[n][np][i];
				}
				for ( int i = 0; i < 2; i++ ) {
					dQc[n][np][i][gNoff] += rQc[n][np][i];
					yQc[n][np][i][gNoff] += wQc[n][np][i];
				}
			}

			dQGap[n][gNoff] += rQGap[n];
			yQGap[n][gNoff] += wQGap[2];

			for ( int i = 0; i < 24; i++ ) {
				dQpGap[n][i][gNoff] += rQpGap[n][i];
				yQpGap[n][i][gNoff] += wQpGap[n][i];

				dQetaGap[n][i][gNoff] += rQetaGap[n][i];
				yQetaGap[n][i][gNoff] += wQetaGap[n][i];
			}
			for ( int i = 0; i < 2; i++ ) {
				dQcGap[n][i][gNoff] += rQcGap[n][i];
				yQcGap[n][i][gNoff] += wQcGap[n][i];
			}
		}
		hNoff->Fill(gNoff);
		hMult->Fill(gMult);
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 600; c++ ) {
				hQ[n][np]->SetBinContent(c+1, dQ[n][np][c]);
				hW[n][np]->SetBinContent(c+1, yQ[n][np][c]);
				hX[n][np]->SetBinContent(c+1, dX[n][np][c]);
				hY[n][np]->SetBinContent(c+1, yX[n][np][c]);
				for ( int i = 0; i < 24; i++ ) {
					hQp[n][np][i]->SetBinContent(c+1, dQp[n][np][i][c]);
					hWp[n][np][i]->SetBinContent(c+1, yQp[n][np][i][c]);
					hQeta[n][np][i]->SetBinContent(c+1, dQeta[n][np][i][c]);
					hWeta[n][np][i]->SetBinContent(c+1, yQeta[n][np][i][c]);
				}
				for ( int i = 0; i < 2; i++ ) {
					hQc[n][np][i]->SetBinContent(c+1, dQc[n][np][i][c]);
					hWc[n][np][i]->SetBinContent(c+1, yQc[n][np][i][c]);
				}
			}
		}
		for ( int c = 0; c < 600; c++ ) {
			hQGap[n]->SetBinContent(c+1, dQGap[n][c]);
			hWQGap[n]->SetBinContent(c+1, yQGap[n][c]);
			for ( int i = 0; i < 24; i++ ) {
				hQpGap[n][i]->SetBinContent(c+1, dQpGap[n][i][c]);
				hWQpGap[n][i]->SetBinContent(c+1, yQpGap[n][i][c]);

				hQetaGap[n][i]->SetBinContent(c+1, dQetaGap[n][i][c]);
				hWQetaGap[n][i]->SetBinContent(c+1, yQetaGap[n][i][c]);
			}
			for ( int i = 0; i < 2; i++ ) {
				hQcGap[n][i]->SetBinContent(c+1, dQcGap[n][i][c]);
				hWQcGap[n][i]->SetBinContent(c+1, yQcGap[n][i][c]);
			}
		}
	}

	TFile * fwrite;
	if ( s2==s3 ) {
		fwrite = new TFile(Form("%s/output.root", ftxt[s1]), "recreate");
	} else {
		fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	}
	for ( int n = 2; n < 7; n++ ) {
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
		hQGap[n]->Write();
		hWQGap[n]->Write();
		for ( int i = 0; i < 24; i++ ) {
			hQpGap[n][i]->Write();
			hQetaGap[n][i]->Write();
			hWQpGap[n][i]->Write();
			hWQetaGap[n][i]->Write();
		}
		for ( int i = 0; i < 2; i++ ) {
			hQcGap[n][i]->Write();
			hWQcGap[n][i]->Write();
		}
	}
	hNoff->Write();
	hMult->Write();

	return;
}
