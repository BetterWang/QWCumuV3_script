/*
 */


{
#include "label.h"
#include "noff.h"
//	int s1 = 92;
	int s3 = 10;

	bool SAVE = true;

	// Get TFile
	TFile *fr[50];
	for ( int i = 0; i <= s3; i++ ) {
		if ( i == s3 ) fr[i] = new TFile(Form("%s/outputC.root", ftxt[s1]));
		else fr[i] = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], i, s3));
	}

	double dV[50][7][4][20];
	double dX[50][7][4][20];

	double dVp[50][7][4][24][20];
	double dVeta[50][7][4][24][20];
	double dVc[50][7][4][2][20];

	double dC[50][7][4][20];
	double wC[50][7][4][20];
	double dD[50][7][4][20];
	double wD[50][7][4][20];

	double dCp[50][7][4][24][20];
	double wCp[50][7][4][24][20];
	double dCeta[50][7][4][24][20];
	double wCeta[50][7][4][24][20];
	double dCc[50][7][4][2][20];
	double wCc[50][7][4][2][20];



	// Get
	for ( int fn = 0; fn <= s3; fn++ ) {
		TFile * f = fr[fn];
		for ( int n = 1; n < 7; n++ ) {
			for ( int np = 0; np < 4; np++ ) {
				TH1D * h1 = (TH1D*) f->Get(Form("hC%i%i", n, 2+2*np));
				TH1D * h2 = (TH1D*) f->Get(Form("hD%i%i", n, 2+2*np));
				TH1D * h3 = (TH1D*) f->Get(Form("hW%i%i", n, 2+2*np));
				TH1D * h4 = (TH1D*) f->Get(Form("hX%i%i", n, 2+2*np));
				for ( int i = 0; i < 20; i++ ) {
					dC[fn][n][np][i] = h1->GetBinContent(i+1);
					dD[fn][n][np][i] = h2->GetBinContent(i+1);
					wC[fn][n][np][i] = h3->GetBinContent(i+1);
					wD[fn][n][np][i] = h4->GetBinContent(i+1);
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
						dCp[fn][n][np][j][i] = h1->GetBinContent(i+1);
						wCp[fn][n][np][j][i] = h2->GetBinContent(i+1);
						dCeta[fn][n][np][j][i] = h3->GetBinContent(i+1);
						wCeta[fn][n][np][j][i] = h4->GetBinContent(i+1);
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
						dCc[fn][n][np][j][i] = h1->GetBinContent(i+1);
						wCc[fn][n][np][j][i] = h2->GetBinContent(i+1);
					}
					delete h1;
					delete h2;
				}
			}
		}

		// C->V
		for ( int n = 1; n < 7; n++ ) {
			for ( int i = 0; i < 20; i++ ) {
				double C2 = dC[fn][n][0][i];
				double C4 = dC[fn][n][1][i];
				double C6 = dC[fn][n][2][i];
				double C8 = dC[fn][n][3][i];
	
				double V2, V4, V6, V8;
	
				if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
				if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
				if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
				if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);
	
				dV[fn][n][0][i] = V2;
				dV[fn][n][1][i] = V4;
				dV[fn][n][2][i] = V6;
				dV[fn][n][3][i] = V8;
	
				C2 = dD[fn][n][0][i];
				C4 = dD[fn][n][1][i];
				C6 = dD[fn][n][2][i];
				C8 = dD[fn][n][3][i];
				if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
				if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
				if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
				if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);
				dX[fn][n][0][i] = V2;
				dX[fn][n][1][i] = V4;
				dX[fn][n][2][i] = V6;
				dX[fn][n][3][i] = V8;
	
				for ( int j = 0; j < 24; j++ ) {
					C2 = dC[fn][n][0][i];
					C4 = dC[fn][n][1][i];
					C6 = dC[fn][n][2][i];
					C8 = dC[fn][n][3][i];
	
					double C2p = dCp[fn][n][0][j][i];
					double C4p = dCp[fn][n][1][j][i];
					double C6p = dCp[fn][n][2][j][i];
					double C8p = dCp[fn][n][3][j][i];
	
					if ( C2 > 0 ) V2 =       C2p/pow(C2, 1./2) ; else V2 = -fabs(C2p/pow(-C2, 1./2));
					if ( C4 > 0 ) V4 = -fabs(C4p/pow(C4, 3./4)); else V4 =      -C4p/pow(-C4, 3./4);
					if ( C6 > 0 ) V6 =       C6p/pow(C6/4., 5./6)/4. ; else V6 = -fabs(C6p/pow(-C6/4., 5./6))/4.;
					if ( C8 > 0 ) V8 = -fabs(C8p/pow(C8/33., 7./8))/33.; else V8 =      -C8p/pow(-C8/33., 7./8)/33.;
	
///					if ( fn == s3 ) cout << " fn = " << fn << "\tn = " << n << "\tj = " << j << "\ti = " << i << "\t np = " << 0 << "\tV2 = " << V2 << "\tC2p = " << C2p << "\tC2 = " << C2 << endl;
					dVp[fn][n][0][j][i] = V2;
					dVp[fn][n][1][j][i] = V4;
					dVp[fn][n][2][j][i] = V6;
					dVp[fn][n][3][j][i] = V8;
	
					C2p = dCeta[fn][n][0][j][i];
					C4p = dCeta[fn][n][1][j][i];
					C6p = dCeta[fn][n][2][j][i];
					C8p = dCeta[fn][n][3][j][i];
	
					if ( C2 > 0 ) V2 =       C2p/pow(C2, 1./2) ; else V2 = -fabs(C2p/pow(-C2, 1./2));
					if ( C4 > 0 ) V4 = -fabs(C4p/pow(C4, 3./4)); else V4 =      -C4p/pow(-C4, 3./4);
					if ( C6 > 0 ) V6 =       C6p/pow(C6/4., 5./6)/4. ; else V6 = -fabs(C6p/pow(-C6/4., 5./6))/4.;
					if ( C8 > 0 ) V8 = -fabs(C8p/pow(C8/33., 7./8))/33.; else V8 =      -C8p/pow(-C8/33., 7./8)/33.;
	
					dVeta[fn][n][0][j][i] = V2;
					dVeta[fn][n][1][j][i] = V4;
					dVeta[fn][n][2][j][i] = V6;
					dVeta[fn][n][3][j][i] = V8;
				}
	
				for ( int j = 0; j < 2; j++ ) {
					C2 = dC[fn][n][0][i];
					C4 = dC[fn][n][1][i];
					C6 = dC[fn][n][2][i];
					C8 = dC[fn][n][3][i];
	
					double C2p = dCc[fn][n][0][j][i];
					double C4p = dCc[fn][n][1][j][i];
					double C6p = dCc[fn][n][2][j][i];
					double C8p = dCc[fn][n][3][j][i];
	
					if ( C2 > 0 ) V2 =       C2p/pow(C2, 1./2) ; else V2 = -fabs(C2p/pow(-C2, 1./2));
					if ( C4 > 0 ) V4 = -fabs(C4p/pow(C4, 3./4)); else V4 =      -C4p/pow(-C4, 3./4);
					if ( C6 > 0 ) V6 =       C6p/pow(C6/4., 5./6) ; else V6 = -fabs(C6p/pow(-C6/4., 5./6));
					if ( C8 > 0 ) V8 = -fabs(C8p/pow(C8/33., 7./8)); else V8 =      -C8p/pow(-C8/33., 7./8);
	
					dVc[fn][n][0][j][i] = V2;
					dVc[fn][n][1][j][i] = V4;
					dVc[fn][n][2][j][i] = V6;
					dVc[fn][n][3][j][i] = V8;
				}
			}
		}
	}

	// Saved histo
	TH1D * fC[7][4];
	TH1D * fW[7][4];
	TH1D * fD[7][4];
	TH1D * fX[7][4];

	TH1D * fCraw[7][4];
	TH1D * fWraw[7][4];
	TH1D * fDraw[7][4];
	TH1D * fXraw[7][4];

	TH1D * fCp[7][4][24];
	TH1D * fCeta[7][4][24];
	TH1D * fCc[7][4][2];
	TH1D * fWp[7][4][24];
	TH1D * fWeta[7][4][24];
	TH1D * fWc[7][4][2];

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			fC[n][np] = (TH1D*)fr[s3]->Get(Form("hC%i%i", n, 2+2*np));
			fD[n][np] = (TH1D*)fr[s3]->Get(Form("hD%i%i", n, 2+2*np));
			fW[n][np] = (TH1D*)fr[s3]->Get(Form("hW%i%i", n, 2+2*np));
			fX[n][np] = (TH1D*)fr[s3]->Get(Form("hX%i%i", n, 2+2*np));

			fCraw[n][np] = (TH1D*)fr[s3]->Get(Form("hCraw%i%i", n, 2+2*np));
			fDraw[n][np] = (TH1D*)fr[s3]->Get(Form("hDraw%i%i", n, 2+2*np));
			fWraw[n][np] = (TH1D*)fr[s3]->Get(Form("hWraw%i%i", n, 2+2*np));
			fXraw[n][np] = (TH1D*)fr[s3]->Get(Form("hXraw%i%i", n, 2+2*np));

			for ( int j = 0; j < 24; j++ ) {
				fCp[n][np][j] = (TH1D*)fr[s3]->Get(Form("hCp%i%i_%i", n, 2+2*np, j));
				fWp[n][np][j] = (TH1D*)fr[s3]->Get(Form("hWp%i%i_%i", n, 2+2*np, j));
				fCeta[n][np][j] = (TH1D*)fr[s3]->Get(Form("hCeta%i%i_%i", n, 2+2*np, j));
				fWeta[n][np][j] = (TH1D*)fr[s3]->Get(Form("hWeta%i%i_%i", n, 2+2*np, j));
			}

			for ( int j = 0; j < 2; j++ ) {
				fCc[n][np][j] = (TH1D*)fr[s3]->Get(Form("hCc%i%i_%i", n, 2+2*np, j));
				fWc[n][np][j] = (TH1D*)fr[s3]->Get(Form("hWc%i%i_%i", n, 2+2*np, j));
			}
		}
	}

	TH1D * fV[7][4];
	TH1D * fVp[7][4][24];
	TH1D * fVeta[7][4][24];
	TH1D * fVc[7][4][2];


	TH1D * fcV[7][4];
	TH1D * fcX[7][4];
	TH1D * fcVp[7][4][24];
	TH1D * fcVeta[7][4][24];
	TH1D * fcVc[7][4][2];

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			fV[n][np] = new TH1D(Form("hV%i%i", n, 2+2*np), "", 20, 0, 20);
			fcV[n][np] = new TH1D(Form("hcV%i%i", n, 2+2*np), "", 20, 0, 20);
			fcX[n][np] = new TH1D(Form("hcX%i%i", n, 2+2*np), "", 20, 0, 20);
			for ( int j = 0; j < 24; j++ ) {
				fVp[n][np][j] = new TH1D(Form("hVp%i%i_%i", n, 2+2*np, j), "", 20, 0, 20);
				fVeta[n][np][j] = new TH1D(Form("hVeta%i%i_%i", n, 2+2*np, j), "", 20, 0, 20);
				fcVp[n][np][j] = new TH1D(Form("hcVp%i%i_%i", n, 2+2*np, j), "", 20, 0, 20);
				fcVeta[n][np][j] = new TH1D(Form("hcVeta%i%i_%i", n, 2+2*np, j), "", 20, 0, 20);
			}
			for ( int j = 0; j < 2; j++ ) {
				fVc[n][np][j] = new TH1D(Form("hVc%i%i_%i", n, 2+2*np, j), "", 20, 0, 20);
				fcVc[n][np][j] = new TH1D(Form("hcVc%i%i_%i", n, 2+2*np, j), "", 20, 0, 20);
			}
		}
	}

	TH1D * hGausC = new TH1D("hGausC", "hGausC", 2000, -10, 10);
	TH1D * hGausD = new TH1D("hGausD", "hGausD", 2000, -10, 10);
	TH1D * hGausV = new TH1D("hGausV", "hGausV", 2000, -10, 10);
	TH1D * hGausX = new TH1D("hGausX", "hGausX", 2000, -10, 10);
	TH1D * hGausVp = new TH1D("hGausVp", "hGausVp", 2000, -10, 10);
	TH1D * hGausVeta = new TH1D("hGausVeta", "hGausVeta", 2000, -10, 10);
	TH1D * hGausVc = new TH1D("hGausVc", "hGausVc", 2000, -10, 10);

	TH1D * hFGausC = new TH1D("hFGausC", "hFGausC", 2000, -10, 10);
	TH1D * hFGausD = new TH1D("hFGausD", "hFGausD", 2000, -10, 10);
	TH1D * hFGausV = new TH1D("hFGausV", "hFGausV", 2000, -10, 10);
	TH1D * hFGausX = new TH1D("hFGausX", "hFGausX", 2000, -10, 10);
	TH1D * hFGausVp = new TH1D("hFGausVp", "hFGausVp", 2000, -10, 10);
	TH1D * hFGausVeta = new TH1D("hFGausVeta", "hFGausVeta", 2000, -10, 10);
	TH1D * hFGausVc = new TH1D("hFGausVc", "hFGausVc", 2000, -10, 10);


	// Get Error
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < 20; i++ ) {
				double sumC = 0;
				double sumD = 0;
				double sumV = 0;
				double sumX = 0;
				for ( int fn = 0; fn < s3; fn++ ) {
					sumC += (dC[fn][n][np][i]-dC[s3][n][np][i])*(dC[fn][n][np][i]-dC[s3][n][np][i]);
					sumD += (dD[fn][n][np][i]-dD[s3][n][np][i])*(dD[fn][n][np][i]-dD[s3][n][np][i]);
					sumV += (dV[fn][n][np][i]-dV[s3][n][np][i])*(dV[fn][n][np][i]-dV[s3][n][np][i]);
					sumX += (dX[fn][n][np][i]-dX[s3][n][np][i])*(dX[fn][n][np][i]-dX[s3][n][np][i]);
				}
				double errC = sqrt( sumC )/s3;
				double errD = sqrt( sumD )/s3;
				double errV = sqrt( sumV )/s3;
				double errX = sqrt( sumX )/s3;
				fC[n][np]->SetBinError(i+1, errC);
				fD[n][np]->SetBinError(i+1, errD);

				fV[n][np]->SetBinContent(i+1, dV[s3][n][np][i]);
				fX[n][np]->SetBinContent(i+1, dX[s3][n][np][i]);
				fV[n][np]->SetBinError(i+1, errV);
				fX[n][np]->SetBinError(i+1, errX);

				fcV[n][np]->SetBinContent(i+1, dV[s3][n][np][i]);
				fcX[n][np]->SetBinContent(i+1, dX[s3][n][np][i]);
				double te = dV[s3][n][np][i]/(2+2*np)*errC/dC[s3][n][np][i];
				fcV[n][np]->SetBinError(i+1, te);
				te = dX[s3][n][np][i]/(2+2*np)*errD/dD[s3][n][np][i];
				fcX[n][np]->SetBinError(i+1, te);

				for ( int fn = 0; fn < s3; fn++ ) {
					hGausC->Fill((dC[fn][n][np][i] - dC[s3][n][np][i])/errC);
					hGausD->Fill((dD[fn][n][np][i] - dD[s3][n][np][i])/errD);
					hGausV->Fill((dV[fn][n][np][i] - dV[s3][n][np][i])/errV);
					hGausX->Fill((dX[fn][n][np][i] - dX[s3][n][np][i])/errX);

					if ( pow(-1, np) * dC[fn][n][np][i] > 0 && fabs(dC[s3][n][np][i] / errC) > 2. ) hFGausC->Fill((dC[fn][n][np][i] - dC[s3][n][np][i])/errC);
					if ( pow(-1, np) * dD[fn][n][np][i] > 0 && fabs(dD[s3][n][np][i] / errD) > 2. ) hFGausD->Fill((dD[fn][n][np][i] - dD[s3][n][np][i])/errD);
					if ( dV[fn][n][np][i] > 0 ) hFGausV->Fill((dV[fn][n][np][i] - dV[s3][n][np][i])/errV);
					if ( dX[fn][n][np][i] > 0 ) hFGausX->Fill((dX[fn][n][np][i] - dX[s3][n][np][i])/errX);
				}

				///// pT eta
				for ( j = 0; j < 24; j++ ) {
					double sumVp = 0;
					double sumVeta = 0;
					double sumCp = 0;
					double sumCeta = 0;
					for ( int fn = 0; fn < s3; fn++ ) {
						sumVp += (dVp[fn][n][np][j][i]-dVp[s3][n][np][j][i])*(dVp[fn][n][np][j][i]-dVp[s3][n][np][j][i]);
						sumVeta += (dVeta[fn][n][np][j][i]-dVeta[s3][n][np][j][i])*(dVeta[fn][n][np][j][i]-dVeta[s3][n][np][j][i]);

						sumCp += (dCp[fn][n][np][j][i]-dCp[s3][n][np][j][i])*(dCp[fn][n][np][j][i]-dCp[s3][n][np][j][i]);
						sumCeta += (dCeta[fn][n][np][j][i]-dCeta[s3][n][np][j][i])*(dCeta[fn][n][np][j][i]-dCeta[s3][n][np][j][i]);
					}
					double errVp = sqrt( sumVp )/s3;
					double errVeta = sqrt( sumVeta )/s3;

					double errCp = sqrt( sumCp )/s3;
					double errCeta = sqrt( sumCeta )/s3;

					fVp[n][np][j]->SetBinContent(i+1, dVp[s3][n][np][j][i]);
					fVeta[n][np][j]->SetBinContent(i+1, dVeta[s3][n][np][j][i]);
//					if (errVp != errVp && n == 2) cout << "n = " << n << "\tnp = " << np << "\tj = " << j << "\ti = " << i << "\tsumVp = " << sumVp << "\terrVp NaN" << endl;
//					if (errCp != errVp && n == 2) cout << "n = " << n << "\tnp = " << np << "\tj = " << j << "\ti = " << i << "\terrCp NaN" << endl;
					fVp[n][np][j]->SetBinError(i+1, errVp);
					fVeta[n][np][j]->SetBinError(i+1, errVeta);

					fcVp[n][np][j]->SetBinContent(i+1, dVp[s3][n][np][j][i]);
					fcVeta[n][np][j]->SetBinContent(i+1, dVeta[s3][n][np][j][i]);
					te = sqrt( errCp*errCp/dCp[s3][n][np][j][i]/dCp[s3][n][np][j][i]
						+ (1+2*np)*(1+2*np)/(2+2*np)/(2+2*np)*errC*errC/dC[s3][n][np][i]/dC[s3][n][np][i])*fabs(dVp[s3][n][np][j][i] );
					if ( np == 2 ) te /= pow(4., 1./6);
					if ( np == 3 ) te /= pow(33., 1./8);
					fcVp[n][np][j]->SetBinError(i+1, te);
					te = sqrt( errCeta*errCeta/dCeta[s3][n][np][j][i]/dCeta[s3][n][np][j][i]
						+ (1+2*np)*(1+2*np)/(2+2*np)/(2+2*np)*errC*errC/dC[s3][n][np][i]/dC[s3][n][np][i])*fabs(dVeta[s3][n][np][j][i] );
					if ( np == 2 ) { te /= pow(4., 1./6); }
					if ( np == 3 ) { te /= pow(33., 1./8); }
					fcVeta[n][np][j]->SetBinError(i+1, te);

					for ( int fn = 0; fn < s3; fn++ ) {
						hGausVp->Fill( (dVp[fn][n][np][j][i] - dVp[s3][n][np][j][i]) / errVp );
						hGausVeta->Fill( (dVeta[fn][n][np][j][i] - dVeta[s3][n][np][j][i]) / errVeta );
						if ( dVp[fn][n][np][j][i] > 0 ) hFGausVp->Fill( (dVp[fn][n][np][j][i] - dVp[s3][n][np][j][i]) / errVp );
						if ( dVeta[fn][n][np][j][i] > 0 ) hFGausVeta->Fill( (dVeta[fn][n][np][j][i] - dVeta[s3][n][np][j][i]) / errVeta );
					}
				}
				/////  charge
				for ( j = 0; j < 2; j++ ) {
					double sumVc = 0;
					double sumCc = 0;
					for ( int fn = 0; fn < s3; fn++ ) {
						sumVc += (dVc[fn][n][np][j][i]-dVc[s3][n][np][j][i])*(dVc[fn][n][np][j][i]-dVc[s3][n][np][j][i]);
						sumCc += (dCc[fn][n][np][j][i]-dCc[s3][n][np][j][i])*(dCc[fn][n][np][j][i]-dCc[s3][n][np][j][i]);
					}
					double errVc = sqrt( sumVc )/s3;
					double errCc = sqrt( sumCc )/s3;

					fVc[n][np][j]->SetBinContent(i+1, dVc[s3][n][np][j][i]);
					fVc[n][np][j]->SetBinError(i+1, errVc);

					fcVc[n][np][j]->SetBinContent(i+1, dVc[s3][n][np][j][i]);
					te = sqrt( errCc*errCc/dCc[s3][n][np][j][i]/dCc[s3][n][np][j][i]
						+ (1+2*np)*(1+2*np)/(2+2*np)/(2+2*np)*errC*errC/dC[s3][n][np][i]/dC[s3][n][np][i])*fabs(dVc[s3][n][np][j][i] );
					if ( np == 2 ) te /= pow(4., 1./6);
					if ( np == 3 ) te /= pow(33., 1./8);
					fcVc[n][np][j]->SetBinError(i+1, te);

					for ( int fn = 0; fn < s3; fn++ ) {
						hGausVc->Fill( (dVc[fn][n][np][j][i] - dVc[s3][n][np][j][i]) / errVc );
						if ( dVc[fn][n][np][j][i] > 0 ) hGausVc->Fill( (dVc[fn][n][np][j][i] - dVc[s3][n][np][j][i]) / errVc );
					}
				}
			}
		}
	}



	// Write
	TFile * fwrite = new TFile(Form("%s/outputE.root", ftxt[s1]), "recreate");
	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			fC[n][np]->Write();
			fW[n][np]->Write();
			fD[n][np]->Write();
			fX[n][np]->Write();

			fCraw[n][np]->Write();
			fWraw[n][np]->Write();
			fDraw[n][np]->Write();
			fXraw[n][np]->Write();

			fV[n][np]->Write();
			fX[n][np]->Write();

			fcV[n][np]->Write();
			fcX[n][np]->Write();
			for ( int i = 0; i < 24; i++ ) {
				fCp[n][np][i]->Write();
				fCeta[n][np][i]->Write();
				fWp[n][np][i]->Write();
				fWeta[n][np][i]->Write();
				fVp[n][np][i]->Write();
				fVeta[n][np][i]->Write();
				fcVp[n][np][i]->Write();
				fcVeta[n][np][i]->Write();
			}
			for ( int i = 0; i < 2; i++ ) {
				fCc[n][np][i]->Write();
				fWc[n][np][i]->Write();
				fVc[n][np][i]->Write();
				fcVc[n][np][i]->Write();
			}
		}
	}
	hGausC->Write();
	hGausD->Write();
	hGausV->Write();
	hGausX->Write();
	hGausVp->Write();
	hGausVeta->Write();
	hGausVc->Write();

	hFGausC->Write();
	hFGausD->Write();
	hFGausV->Write();
	hFGausX->Write();
	hFGausVp->Write();
	hFGausVeta->Write();
	hFGausVc->Write();

	fwrite->Close();

}
