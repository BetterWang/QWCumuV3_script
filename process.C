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
//	int s1 = 4;
//	int s2 = 10;
//	int s3 = 10;

	TChain * chV = new TChain("trV");
	if ( s1 == 4 ) {
		addchain(1);
		addchain(2);
		addchain(3);
	} else 
	if ( s1 == 8 ) {
		addchain(1);
		addchain(2);
		addchain(7);
	} else 
	if ( s1 == 12 ) {
		addchain(9);
		addchain(10);
		addchain(11);
	} else 
	if ( s1 == 16 ) {
		addchain(13);
		addchain(14);
		addchain(15);
	} else 
	if ( s1 == 20 ) {
		addchain(17);
		addchain(18);
		addchain(19);
	} else 
	if ( s1 == 24 ) {
		addchain(21);
		addchain(22);
		addchain(23);
	} else 
	if ( s1 == 28 ) {
		addchain(25);
		addchain(26);
		addchain(27);
	} else 
	if ( s1 == 32 ) {
		addchain(29);
		addchain(30);
		addchain(31);
	} else 
	if ( s1 == 36 ) {
		addchain(33);
		addchain(34);
		addchain(35);
	} else 
	if ( s1 == 40 ) {
		addchain(37);
		addchain(38);
		addchain(39);
	} else 
	if ( s1 == 44 ) {
		addchain(41);
		addchain(42);
		addchain(43);
	} else 
	if ( s1 == 48 ) {
		addchain(45);
		addchain(46);
		addchain(47);
	} else 
	if ( s1 == 52 ) {
		addchain(49);
		addchain(50);
		addchain(51);
	} else 
	if ( s1 == 58 ) {
		addchain(55);
		addchain(56);
		addchain(57);
	} else 
	if ( s1 == 62 ) {
		addchain(59);
		addchain(60);
		addchain(61);
	} else 
	if ( s1 == 66 ) {
		addchain(63);
		addchain(64);
		addchain(65);
	} else 
	if ( s1 == 70 ) {
		addchain(67);
		addchain(68);
		addchain(69);
	} else 
	if ( s1 == 74 ) {
		addchain(71);
		addchain(72);
		addchain(73);
	} else 
	if ( s1 == 78 ) {
		addchain(75);
		addchain(76);
		addchain(77);
	} else 
	if ( s1 == 82 ) {
		addchain(79);
		addchain(80);
		addchain(81);
	} else 
	if ( s1 == 86 ) {
		addchain(83);
		addchain(84);
		addchain(85);
	} else 
	if ( s1 == 108 ) {
		addchain(105);
		addchain(106);
		addchain(107);
	} else 
	if ( s1 == 114 ) {
		addchain(111);
		addchain(112);
		addchain(113);
	} else 
	if ( s1 == 118 ) {
		addchain(115);
		addchain(116);
		addchain(117);
	} else 
	if ( s1 == 122 ) {
		addchain(119);
		addchain(121);
		addchain(121);
	} else 
	if ( s1 == 126 ) {
		addchain(123);
		addchain(124);
		addchain(125);
	} else
	if ( s1 == 135 ) {
		addchain(132);
		addchain(133);
		addchain(134);
	} else
	if ( s1 == 139 ) {
		addchain(136);
		addchain(137);
		addchain(138);
	} else
	if ( s1 == 143 ) {
		addchain(140);
		addchain(141);
		addchain(142);
	} else
	if ( s1 == 147 ) {
		addchain(144);
		addchain(145);
		addchain(146);
	} else
	if ( s1 == 151 ) {
		addchain(148);
		addchain(149);
		addchain(150);
	} else
	if ( s1 == 155 ) {
		addchain(152);
		addchain(153);
		addchain(154);
	} else
	if ( s1 == 159 ) {
		addchain(156);
		addchain(157);
		addchain(158);
	} else
	if ( s1 == 163 ) {
		addchain(160);
		addchain(161);
		addchain(162);
	} else
	if ( s1 == 167 ) {
		addchain(164);
		addchain(165);
		addchain(166);
	} else
	if ( s1 == 171 ) {
		addchain(168);
		addchain(169);
		addchain(170);
	} else
	if ( s1 == 175 ) {
		addchain(172);
		addchain(173);
		addchain(174);
	} else
	if ( s1 == 179 ) {
		addchain(176);
		addchain(177);
		addchain(178);
	} else
	if ( s1 == 183 ) {
		addchain(180);
		addchain(181);
		addchain(182);
	} else
	{
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
		if ( (s2!=s3) && ((ievt%s3)!=s2) ) continue;
		if (gNoff >=500) continue;

		for ( int n = 1; n < 7; n++ ) {
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

	TFile * fwrite;
	if ( s2==s3 ) {
		fwrite = new TFile(Form("%s/output.root", ftxt[s1]), "recreate");
	} else {
		fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	}
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
