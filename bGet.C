#include "label.h"
#include "noff.h"
#include "TH1.h"
#include "TFile.h"

void bGet(int s1 = 0, int s2 = 10, int s3 =10){
//	int s1 = 4;
//	int s2 = 10;
//	int s3 = 10;

	cout << "s1 = " << s1 << "\ts2 = " << s2 << "\ts3 = " << s3 << endl;
	TFile *f = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3));


	double dQGap[7][500] = {};
	double yQGap[7][500] = {};
	double dQpGap[7][24][500] = {};
	double yQpGap[7][24][500] = {};
	double dQetaGap[7][24][500] = {};
	double yQetaGap[7][24][500] = {};
	double dQcGap[7][2][500] = {};
	double yQcGap[7][2][500] = {};

	double dCGap[7][20] = {};
	double dCpGap[7][24][20] = {};
	double dCetaGap[7][24][20] = {};
	double dCcGap[7][2][20] = {};

	double wCGap[7][20] = {};
	double wCpGap[7][24][20] = {};
	double wCetaGap[7][24][20] = {};
	double wCcGap[7][2][20] = {};

	double dQ[7][4][500] = {};
	double wQ[7][4][500] = {};
	double dX[7][4][500] = {};
	double wX[7][4][500] = {};

	double dQp[7][4][24][500] = {};
	double wQp[7][4][24][500] = {};
	double dQeta[7][4][24][500] = {};
	double wQeta[7][4][24][500] = {};
	double dQc[7][4][2][500] = {};
	double wQc[7][4][2][500] = {};

	double dC[7][4][500] = {};
	double dD[7][4][500] = {};

	double dCp[7][4][24][500] = {};
	double dCeta[7][4][24][500] = {};
	double dCc[7][4][2][500] = {};

	Int_t const * pCent4 = CentXeXe4;
	Int_t const * pCent6 = CentXeXe6;
	Int_t const * pCent8 = CentXeXe8;

	Int_t const * pCent[4] = { pCent4, pCent4, pCent6, pCent8 };

	double dCx[7][4][20] = {};
	double wCx[7][4][20] = {};
	double dDx[7][4][20] = {};
	double wDx[7][4][20] = {};

	double dCxp[7][4][24][20] = {};
	double wCxp[7][4][24][20] = {};
	double dCxeta[7][4][24][20] = {};
	double wCxeta[7][4][24][20] = {};
	double dCxc[7][4][2][20] = {};
	double wCxc[7][4][2][20] = {};

	TH1D * hNoff = (TH1D*) f->Get("hNoff");

	TH1D * hNevtCent2 = new TH1D("hNevtCent2", "hNevtCent2", 20, 0, 20);
	TH1D * hNevtCent4 = new TH1D("hNevtCent4", "hNevtCent4", 20, 0, 20);
	TH1D * hNevtCent6 = new TH1D("hNevtCent6", "hNevtCent6", 20, 0, 20);
	TH1D * hNevtCent8 = new TH1D("hNevtCent8", "hNevtCent8", 20, 0, 20);

	TH1D * hNevtCent[4] = {hNevtCent2, hNevtCent4, hNevtCent6, hNevtCent8};

	for ( int n = 2; n < 7; n++ ) {
		TH1D * hQ = (TH1D*) f->Get(Form("hQGap%i", n));
		TH1D * hW = (TH1D*) f->Get(Form("hWQGap%i", n));
		for ( int c = 0; c < 500; c++ ) {
			dQGap[n][c] = hQ->GetBinContent(c+1);
			yQGap[n][c] = hW->GetBinContent(c+1);

			if ( yQGap[n][c] > 0 ) dQGap[n][c] /= yQGap[n][c];
		}
		delete hQ;
		delete hW;
		for ( int i = 0; i < 24; i++ ) {
			TH1D * hQp = (TH1D*) f->Get(Form("hQpGap%i%i", n, i));
			TH1D * hWp = (TH1D*) f->Get(Form("hWQpGap%i%i", n, i));
			TH1D * hQeta = (TH1D*) f->Get(Form("hQetaGap%i%i", n, i));
			TH1D * hWeta = (TH1D*) f->Get(Form("hWQetaGap%i%i", n, i));
			for ( int c = 0; c < 500; c++ ) {
				dQpGap[n][i][c] = hQp->GetBinContent(c+1);
				yQpGap[n][i][c] = hWp->GetBinContent(c+1);

				dQetaGap[n][i][c] = hQeta->GetBinContent(c+1);
				yQetaGap[n][i][c] = hWeta->GetBinContent(c+1);

				if ( yQpGap[n][i][c] > 0 ) dQpGap[n][i][c] /= yQpGap[n][i][c];
				if ( yQetaGap[n][i][c] > 0 ) dQetaGap[n][i][c] /= yQetaGap[n][i][c];
			}
			delete hQp;
			delete hWp;
			delete hQeta;
			delete hWeta;
		}
		for ( int i = 0; i < 2; i++ ) {
			TH1D * hQc = (TH1D*) f->Get(Form("hQcGap%i%i", n, i));
			TH1D * hWc = (TH1D*) f->Get(Form("hWQcGap%i%i", n, i));
			for ( int c = 0; c < 500; c++ ) {
				dQcGap[n][i][c] = hQc->GetBinContent(c+1);
				yQcGap[n][i][c] = hWc->GetBinContent(c+1);

				if ( yQcGap[n][i][c] > 0 ) dQcGap[n][i][c] /= yQcGap[n][i][c];
			}
			delete hQc;
			delete hWc;
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			TH1D * hQ = (TH1D*) f->Get(Form("hQ%i%i", n, 2+2*np));
			TH1D * hW = (TH1D*) f->Get(Form("hW%i%i", n, 2+2*np));
			TH1D * hX = (TH1D*) f->Get(Form("hX%i%i", n, 2+2*np));
			TH1D * hY = (TH1D*) f->Get(Form("hY%i%i", n, 2+2*np));
			for ( int i = 0; i < 500; i++ ) {
				dQ[n][np][i] = hQ->GetBinContent(i+1);
				wQ[n][np][i] = hW->GetBinContent(i+1);
				dX[n][np][i] = hX->GetBinContent(i+1);
				wX[n][np][i] = hY->GetBinContent(i+1);

				if (wQ[n][np][i] > 0) dQ[n][np][i] /= wQ[n][np][i];
				if (wX[n][np][i] > 0) dX[n][np][i] /= wX[n][np][i];
			}
			delete hQ;
			delete hW;
			delete hX;
			delete hY;

			for ( int c = 0; c < 24; c++ ) {
				TH1D * hQp = (TH1D*) f->Get(Form("hQp%i%i_%i", n, 2+2*np, c));
				TH1D * hWp = (TH1D*) f->Get(Form("hWp%i%i_%i", n, 2+2*np, c));
				TH1D * hQeta = (TH1D*) f->Get(Form("hQeta%i%i_%i", n, 2+2*np, c));
				TH1D * hWeta = (TH1D*) f->Get(Form("hWeta%i%i_%i", n, 2+2*np, c));
				for ( int i = 0; i < 500; i++ ) {
					dQp[n][np][c][i] = hQp->GetBinContent(i+1);
					wQp[n][np][c][i] = hWp->GetBinContent(i+1);
					dQeta[n][np][c][i] = hQeta->GetBinContent(i+1);
					wQeta[n][np][c][i] = hWeta->GetBinContent(i+1);

					if ( wQp[n][np][c][i] != 0 ) dQp[n][np][c][i] /= wQp[n][np][c][i];
					if ( wQeta[n][np][c][i] != 0 ) dQeta[n][np][c][i] /= wQeta[n][np][c][i];

				}
				delete hQp;
				delete hWp;
				delete hQeta;
				delete hWeta;
			}

			for ( int c = 0; c < 2; c++ ) {
				TH1D * hQc = (TH1D*) f->Get(Form("hQc%i%i_%i", n, 2+2*np, c));
				TH1D * hWc = (TH1D*) f->Get(Form("hWc%i%i_%i", n, 2+2*np, c));
				for ( int i = 0; i < 500; i++ ) {
					dQc[n][np][c][i] = hQc->GetBinContent(i+1);
					wQc[n][np][c][i] = hWc->GetBinContent(i+1);

					if ( wQc[n][np][c][i] != 0 ) dQc[n][np][c][i] /= wQc[n][np][c][i];
				}
				delete hQc;
				delete hWc;
			}
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int m = 0; m < 500; m++ ) {
			double Q2 = dQ[n][0][m];
			double Q4 = dQ[n][1][m];
			double Q6 = dQ[n][2][m];
			double Q8 = dQ[n][3][m];

			dC[n][0][m] = Q2;
			dC[n][1][m] = Q4 - 2*Q2*Q2;
			dC[n][2][m] = Q6 - 9*Q2*Q4 + 12*Q2*Q2*Q2;
			dC[n][3][m] = Q8 - 16*Q6*Q2 - 18*Q4*Q4 + 144*Q4*Q2*Q2 -144*Q2*Q2*Q2*Q2;

			Q2 = dX[n][0][m];
			Q4 = dX[n][1][m];
			Q6 = dX[n][2][m];
			Q8 = dX[n][3][m];

			dD[n][0][m] = Q2;
			dD[n][1][m] = Q4 - 2*Q2*Q2;
			dD[n][2][m] = Q6 - 9*Q2*Q4 + 12*Q2*Q2*Q2;
			dD[n][3][m] = Q8 - 16*Q6*Q2 - 18*Q4*Q4 + 144*Q4*Q2*Q2 -144*Q2*Q2*Q2*Q2;

		}

		for ( int i = 0; i < 24; i++ ) {
			for ( int m = 0; m < 500; m++ ) {
				double Q2p = dQp[n][0][i][m];
				double Q4p = dQp[n][1][i][m];
				double Q6p = dQp[n][2][i][m];
				double Q8p = dQp[n][3][i][m];

				double Q2 = dQ[n][0][m];
				double Q4 = dQ[n][1][m];
				double Q6 = dQ[n][2][m];
				double Q8 = dQ[n][3][m];

				dCp[n][0][i][m] = Q2p;
				dCp[n][1][i][m] = Q4p - 2*Q2*Q2p;
				dCp[n][2][i][m] = Q6p - 6*Q2*Q4p - 3*Q2p*Q4 + 12*Q2p*Q2*Q2;
				dCp[n][3][i][m] = Q8p - 12*Q2*Q6p - 4*Q2p*Q6 - 18*Q4p*Q4 + 72*Q4p*Q2*Q2 + 72*Q4*Q2p*Q2 - 144*Q2p*Q2*Q2*Q2;

				Q2p = dQeta[n][0][i][m];
				Q4p = dQeta[n][1][i][m];
				Q6p = dQeta[n][2][i][m];
				Q8p = dQeta[n][3][i][m];

				dCeta[n][0][i][m] = Q2p;
				dCeta[n][1][i][m] = Q4p - 2*Q2*Q2p;
				dCeta[n][2][i][m] = Q6p - 6*Q2*Q4p - 3*Q2p*Q4 + 12*Q2p*Q2*Q2;
				dCeta[n][3][i][m] = Q8p - 12*Q2*Q6p - 4*Q2p*Q6 - 18*Q4p*Q4 + 72*Q4p*Q2*Q2 + 72*Q4*Q2p*Q2 - 144*Q2p*Q2*Q2*Q2;

			}
		}

		for ( int i = 0; i < 2; i++ ) {
			for ( int m = 0; m < 500; m++ ) {
				double Q2p = dQc[n][0][i][m];
				double Q4p = dQc[n][1][i][m];
				double Q6p = dQc[n][2][i][m];
				double Q8p = dQc[n][3][i][m];

				double Q2 = dQ[n][0][m];
				double Q4 = dQ[n][1][m];
				double Q6 = dQ[n][2][m];
				double Q8 = dQ[n][3][m];

				dCc[n][0][i][m] = Q2p;
				dCc[n][1][i][m] = Q4p - 2*Q2*Q2p;
				dCc[n][2][i][m] = Q6p - 6*Q2*Q4p - 3*Q2p*Q4 + 12*Q2p*Q2*Q2;
				dCc[n][3][i][m] = Q8p - 12*Q2*Q6p - 4*Q2p*Q6 - 18*Q4p*Q4 + 72*Q4p*Q2*Q2 + 72*Q4*Q2p*Q2 - 144*Q2p*Q2*Q2*Q2;

			}
		}
	}
	// rebin
	for ( int np = 0; np < 4; np++ ) {
		for ( int i = 0; i < NCent[np]; i++ ) {
			double nevt = 0;
			for (int m = pCent[np][i]; m < pCent[np][i+1]; m++ ) {
				if ( m >= 500 ) continue;
				nevt += hNoff->GetBinContent(m);
			}
			hNevtCent[np]->SetBinContent(i+1, nevt);
		}
	}
	for ( int n = 2; n < 7; n++ ) {
		for ( int i = 0; i < NCent[0]; i++ ) {
			double sum = 0;
			double weight = 0;
			for ( int m = pCent[0][i]; m < pCent[0][i+1]; m++ ) {
				if ( m >= 500 ) continue;
				double w = yQGap[n][m];
				double C = dQGap[n][m];

				sum += C*w;
				weight += w;
			}
			if ( weight > 0 ) sum /= weight;
			else sum = 0;
			dCGap[n][i] = sum;
			wCGap[n][i] = weight;
		}
		for ( int j = 0; j < 24; j++ ) {
			for ( int i = 0; i < NCent[0]; i++ ) {
				double sump = 0;
				double weightp = 0;
				double sumeta = 0;
				double weighteta = 0;
				for ( int m = pCent[0][i]; m < pCent[0][i+1]; m++ ) {
					if ( m >= 500 ) continue;
					double C = dQpGap[n][j][m];
					double w = yQpGap[n][j][m];
					sump += C*w;
					weightp += w;

					C = dQetaGap[n][j][m];
					w = yQetaGap[n][j][m];
					sumeta += C*w;
					weighteta += w;
				}
				if ( weightp > 0 ) sump /= weightp;
				else sump = 0;
				if ( weighteta > 0 ) sumeta /= weighteta;
				else sumeta = 0;

				dCpGap[n][j][i] = sump;
				wCpGap[n][j][i] = weightp;
				dCetaGap[n][j][i] = sumeta;
				wCetaGap[n][j][i] = weighteta;
			}
		}
		for ( int j = 0; j < 2; j++ ) {
			for ( int i = 0; i < NCent[0]; i++ ) {
				double sumc = 0;
				double weightc = 0;
				for ( int m = pCent[0][i]; m < pCent[0][i+1]; m++ ) {
					if ( m >= 500 ) continue;
					double C = dQcGap[n][j][m];
					double w = yQcGap[n][j][m];
					sumc += C*w;
					weightc += w;
				}
				if ( weightc > 0 ) sumc /= weightc;
				else sumc = 0;
				dCcGap[n][j][i] = sumc;
				wCcGap[n][j][i] = weightc;
			}
		}

		for ( int np = 0; np < 4; np++ ) {
			for ( int i = 0; i < NCent[np]; i++ ) {
				double sum = 0;
				double sumX = 0;
				double weight = 0;
				double weightX = 0;

				for ( int m = pCent[np][i]; m < pCent[np][i+1]; m++ ) {
					if ( m >= 500 ) continue;
					double w = wQ[n][np][m];
					double wXc = wX[n][np][m];
					double C = dC[n][np][m];
					double D = dD[n][np][m];

					sum += C*w;
					weight += w;
					sumX += D*wXc;
					weightX += wXc;
				}
				if ( weight > 0 ) sum /= weight;
				else sum = 0;
				if ( weightX > 0 ) sumX /= weightX;
				dCx[n][np][i] = sum;
				wCx[n][np][i] = weight;

				dDx[n][np][i] = sumX;
				wDx[n][np][i] = weightX;
			}

			for ( int j = 0; j < 24; j++ ) {
				for ( int i = 0; i < NCent[np]; i++ ) {
					double sump = 0;
					double weightp = 0;
					double sumeta = 0;
					double weighteta = 0;
					for ( int m = pCent[np][i]; m < pCent[np][i+1]; m++ ) {
						if ( m >= 500 ) continue;
						double w = wQp[n][np][j][m];
						double C = dCp[n][np][j][m];
						sump += C*w;
						weightp += w;

						w = wQeta[n][np][j][m];
						C = dCeta[n][np][j][m];
						sumeta += C*w;
						weighteta += w;
					}
					if ( weightp > 0 ) sump /= weightp;
					else sump = 0;
					if ( weighteta > 0 ) sumeta /= weighteta;
					else sumeta = 0;

					dCxp[n][np][j][i] = sump;
					wCxp[n][np][j][i] = weightp;
					dCxeta[n][np][j][i] = sumeta;
					wCxeta[n][np][j][i] = weighteta;
				}
			}
			for ( int j = 0; j < 2; j++ ) {
				for ( int i = 0; i < NCent[np]; i++ ) {
					double sump = 0;
					double weightp = 0;

					for ( int m = pCent[np][i]; m < pCent[np][i+1]; m++ ) {
						if ( m >= 500 ) continue;
						double w = wQc[n][np][j][m];
						double C = dCc[n][np][j][m];
						sump += C*w;
						weightp += w;
					}
					if ( weightp > 0 ) sump /= weightp;
					else sump = 0;

					dCxc[n][np][j][i] = sump;
					wCxc[n][np][j][i] = weightp;
				}
			}
		}
	}

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

	TH1D * fCGap[7];
	TH1D * fCpGap[7][24];
	TH1D * fCetaGap[7][24];
	TH1D * fCcGap[7][2];

	TH1D * fWGap[7];
	TH1D * fWpGap[7][24];
	TH1D * fWetaGap[7][24];
	TH1D * fWcGap[7][2];

	for ( int n = 2; n < 7; n++ ) {
		fCGap[n] = new TH1D(Form("hCGap%i", n), Form("hCGap%i", n), 20, 0, 20);
		fWGap[n] = new TH1D(Form("hWGap%i", n), Form("hWGap%i", n), 20, 0, 20);
		for ( int i = 0; i < 20; i++ ) {
			fCGap[n]->SetBinContent(i+1, dCGap[n][i]);
			fWGap[n]->SetBinContent(i+1, wCGap[n][i]);
		}
		for ( int j = 0; j < 24; j++ ) {
			fCpGap[n][j] = new TH1D(Form("hCpGap%i_%i", n, j), Form("hCpGap%i_%i", n, j), 20, 0, 20);
			fWpGap[n][j] = new TH1D(Form("hWpGap%i_%i", n, j), Form("hWpGap%i_%i", n, j), 20, 0, 20);
			fCetaGap[n][j] = new TH1D(Form("hCetaGap%i_%i", n, j), Form("hCetaGap%i_%i", n, j), 20, 0, 20);
			fWetaGap[n][j] = new TH1D(Form("hWetaGap%i_%i", n, j), Form("hWetaGap%i_%i", n, j), 20, 0, 20);

			for ( int i = 0; i < 20; i++ ) {
				fCpGap[n][j]->SetBinContent(i+1, dCpGap[n][j][i]);
				fWpGap[n][j]->SetBinContent(i+1, wCpGap[n][j][i]);
				fCetaGap[n][j]->SetBinContent(i+1, dCetaGap[n][j][i]);
				fWetaGap[n][j]->SetBinContent(i+1, wCetaGap[n][j][i]);
			}
		}
		for ( int j = 0; j < 2; j++ ) {
			fCcGap[n][j] = new TH1D(Form("hCcGap%i_%i", n, j), Form("hCcGap%i_%i", n, j), 20, 0, 20);
			fWcGap[n][j] = new TH1D(Form("hWcGap%i_%i", n, j), Form("hWcGap%i_%i", n, j), 20, 0, 20);

			for ( int i = 0; i < 20; i++ ) {
				fCcGap[n][j]->SetBinContent(i+1, dCcGap[n][j][i]);
				fWcGap[n][j]->SetBinContent(i+1, wCcGap[n][j][i]);
			}
		}

		for ( int np = 0; np < 4; np++ ) {
			fC[n][np] = new TH1D(Form("hC%i%i", n, 2+2*np), Form("hC%i%i", n, 2+2*np), 20, 0, 20);
			fD[n][np] = new TH1D(Form("hD%i%i", n, 2+2*np), Form("hD%i%i", n, 2+2*np), 20, 0, 20);
			fW[n][np] = new TH1D(Form("hW%i%i", n, 2+2*np), Form("hW%i%i", n, 2+2*np), 20, 0, 20);
			fX[n][np] = new TH1D(Form("hX%i%i", n, 2+2*np), Form("hX%i%i", n, 2+2*np), 20, 0, 20);

			fCraw[n][np] = new TH1D(Form("hCraw%i%i", n, 2+2*np), Form("hCraw%i%i", n, 2+2*np), 500, 0, 500);
			fDraw[n][np] = new TH1D(Form("hDraw%i%i", n, 2+2*np), Form("hDraw%i%i", n, 2+2*np), 500, 0, 500);
			fWraw[n][np] = new TH1D(Form("hWraw%i%i", n, 2+2*np), Form("hWraw%i%i", n, 2+2*np), 500, 0, 500);
			fXraw[n][np] = new TH1D(Form("hXraw%i%i", n, 2+2*np), Form("hXraw%i%i", n, 2+2*np), 500, 0, 500);

			for ( int i = 0; i < 20; i++ ) {
				fC[n][np]->SetBinContent(i+1, dCx[n][np][i]);
				fD[n][np]->SetBinContent(i+1, dDx[n][np][i]);
				fW[n][np]->SetBinContent(i+1, wCx[n][np][i]);
				fX[n][np]->SetBinContent(i+1, wDx[n][np][i]);
			}
			for ( int i = 1; i < 500; i++ ) {
				fCraw[n][np]->SetBinContent(i+1, dC[n][np][i]);
				fDraw[n][np]->SetBinContent(i+1, dD[n][np][i]);
				fWraw[n][np]->SetBinContent(i+1, wQ[n][np][i]);
				fXraw[n][np]->SetBinContent(i+1, wX[n][np][i]);
			}

			for ( int j = 0; j < 24; j++ ) {
				fCp[n][np][j] = new TH1D(Form("hCp%i%i_%i", n, 2+2*np, j), Form("hCp%i%i_%i", n, 2+2*np, j), 20, 0, 20);
				fWp[n][np][j] = new TH1D(Form("hWp%i%i_%i", n, 2+2*np, j), Form("hWp%i%i_%i", n, 2+2*np, j), 20, 0, 20);
				fCeta[n][np][j] = new TH1D(Form("hCeta%i%i_%i", n, 2+2*np, j), Form("hCeta%i%i_%i", n, 2+2*np, j), 20, 0, 20);
				fWeta[n][np][j] = new TH1D(Form("hWeta%i%i_%i", n, 2+2*np, j), Form("hWeta%i%i_%i", n, 2+2*np, j), 20, 0, 20);
				for ( int i = 0; i < 20; i++ ) {
					fCp[n][np][j]->SetBinContent(i+1, dCxp[n][np][j][i]);
					fWp[n][np][j]->SetBinContent(i+1, wCxp[n][np][j][i]);
					fCeta[n][np][j]->SetBinContent(i+1, dCxeta[n][np][j][i]);
					fWeta[n][np][j]->SetBinContent(i+1, wCxeta[n][np][j][i]);
				}
			}

			for ( int j = 0; j < 2; j++ ) {
				fCc[n][np][j] = new TH1D(Form("hCc%i%i_%i", n, 2+2*np, j), Form("hCc%i%i_%i", n, 2+2*np, j), 20, 0, 20);
				fWc[n][np][j] = new TH1D(Form("hWc%i%i_%i", n, 2+2*np, j), Form("hWc%i%i_%i", n, 2+2*np, j), 20, 0, 20);
				for ( int i = 0; i < 20; i++ ) {
					fCc[n][np][j]->SetBinContent(i+1, dCxc[n][np][j][i]);
					fWc[n][np][j]->SetBinContent(i+1, wCxc[n][np][j][i]);
				}
			}
		}

	}

	TFile *fwrite = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			fC[n][np]->Write();
			fW[n][np]->Write();
			fD[n][np]->Write();
			fX[n][np]->Write();
			fCraw[n][np]->Write();
			fWraw[n][np]->Write();
			fDraw[n][np]->Write();
			fXraw[n][np]->Write();
			for ( int i = 0; i < 24; i++ ) {
				fCp[n][np][i]->Write();
				fCeta[n][np][i]->Write();
				fWp[n][np][i]->Write();
				fWeta[n][np][i]->Write();
			}
			for ( int i = 0; i < 2; i++ ) {
				fCc[n][np][i]->Write();
				fWc[n][np][i]->Write();
			}
		}
		fCGap[n]->Write();
		fWGap[n]->Write();
		for ( int j = 0; j < 24; j++ ) {
			fCpGap[n][j]->Write();
			fWpGap[n][j]->Write();
			fCetaGap[n][j]->Write();
			fWetaGap[n][j]->Write();
		}
		for ( int j = 0; j < 2; j++ ) {
			fCcGap[n][j]->Write();
			fWcGap[n][j]->Write();
		}
	}
	fwrite->Close();
}
