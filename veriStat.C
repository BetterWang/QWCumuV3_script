#include "label.h"

void veriStat()
{
	int s1 = 21;
	int s3 = 10;
	// Get TFile
	TFile *fr[50];
	for ( int i = 0; i <= s3; i++ ) {
		fr[i] = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], i, s3));
	}
	double dCp[50][7][4][24][20];
	// Get
	for ( int fn = 0; fn <= s3; fn++ ) {
		TFile * f = fr[fn];
		for ( int n = 2; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				for ( int j = 0; j < 24; j++ ) {
					TH1D* h1 = (TH1D*) f->Get(Form("hCp%i%i_%i", n, 2+2*np, j));
					for ( int i = 0; i < 20; i++ ) {
						dCp[fn][n][np][j][i] = h1->GetBinContent(i+1);
					}
				}
			}
		}
	}
	for ( int fn = 0; fn <= s3; fn++ ) {
		cout << " fn = " << fn << "\t\t" << dCp[fn][2][1][7][6] << endl;
	}
}

