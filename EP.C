#include "label.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>

const int NumEPNames = 29;
void EP(int s1 = 6, int EP = 8, int N = 2)
{
	TFile * f = new TFile(Form("%smerged_hist.root", ftxt[s1]));
//	TFile * f = new TFile(Form("%smerged_hist.root", "txt/HIHardProbes_PromptSkim_cumu_v2/"));

	TH2D * hMult = (TH2D*) f->Get("cumulantMB/hMult");

	const double * centbins = hMult->GetXaxis()->GetXbins()->GetArray();
	int nCentBins = hMult->GetXaxis()->GetNbins();
	const double * ptbins = hMult->GetYaxis()->GetXbins()->GetArray();
	int nPtBins = hMult->GetYaxis()->GetNbins();


	TH2D * hEP[nPtBins][7];
	TH2D * hSP[nPtBins][7];
	TH2D * iEP[nPtBins][7];
	TH2D * iSP[nPtBins][7];


	TH2D * hEPresAB = (TH2D*) f->Get("cumulantMB/hEPresAB");
	TH2D * hEPresAC = (TH2D*) f->Get("cumulantMB/hEPresAC");
	TH2D * hEPresBC = (TH2D*) f->Get("cumulantMB/hEPresBC");

	TH2D * hSPresAB = (TH2D*) f->Get("cumulantMB/hSPresAB");
	TH2D * hSPresAC = (TH2D*) f->Get("cumulantMB/hSPresAC");
	TH2D * hSPresBC = (TH2D*) f->Get("cumulantMB/hSPresBC");

	TH2D * hMultRes = (TH2D*) f->Get("cumulantMB/hMultRes");


	for ( int ipt = 0; ipt < nPtBins; ipt++ ) {
		for ( int i = 1; i < 7; i++ ) {
			hEP[ipt][i] = (TH2D*) f->Get(Form("cumulantMB/hEP_%i_%i", ipt, i));
			hSP[ipt][i] = (TH2D*) f->Get(Form("cumulantMB/hSP_%i_%i", ipt, i));
			iEP[ipt][i] = (TH2D*) f->Get(Form("cumulantMB/iEP_%i_%i", ipt, i));
			iSP[ipt][i] = (TH2D*) f->Get(Form("cumulantMB/iSP_%i_%i", ipt, i));
		}
	}


	for ( int c = 0; c < nCentBins; c++ ) {
		for ( int iep = 0; iep < NumEPNames; iep++ ) {
			double val2 = hMultRes->GetBinContent(c+1, iep+1);
			double err2 = hMultRes->GetBinError(c+1, iep+1);

			double val, err;
			val = hEPresAB->GetBinContent(c+1, iep+1);
			err = hEPresAB->GetBinError(c+1, iep+1);
			hEPresAB->SetBinContent(c+1, iep+1, val/val2);
			hEPresAB->SetBinError(c+1, iep+1, sqrt(err2*err2/val2/val2 + err*err/val/val)*val/val2);

			val = hEPresAC->GetBinContent(c+1, iep+1);
			err = hEPresAC->GetBinError(c+1, iep+1);
			hEPresAC->SetBinContent(c+1, iep+1, val/val2);
			hEPresAC->SetBinError(c+1, iep+1, sqrt(err2*err2/val2/val2 + err*err/val/val)*val/val2);

			val = hEPresBC->GetBinContent(c+1, iep+1);
			err = hEPresBC->GetBinError(c+1, iep+1);
			hEPresBC->SetBinContent(c+1, iep+1, val/val2);
			hEPresBC->SetBinError(c+1, iep+1, sqrt(err2*err2/val2/val2 + err*err/val/val)*val/val2);

			val = hSPresAB->GetBinContent(c+1, iep+1);
			err = hSPresAB->GetBinError(c+1, iep+1);
			hSPresAB->SetBinContent(c+1, iep+1, val/val2);
			hSPresAB->SetBinError(c+1, iep+1, sqrt(err2*err2/val2/val2 + err*err/val/val)*val/val2);

			val = hSPresAC->GetBinContent(c+1, iep+1);
			err = hSPresAC->GetBinError(c+1, iep+1);
			hSPresAC->SetBinContent(c+1, iep+1, val/val2);
			hSPresAC->SetBinError(c+1, iep+1, sqrt(err2*err2/val2/val2 + err*err/val/val)*val/val2);

			val = hSPresBC->GetBinContent(c+1, iep+1);
			err = hSPresBC->GetBinError(c+1, iep+1);
			hSPresBC->SetBinContent(c+1, iep+1, val/val2);
			hSPresBC->SetBinError(c+1, iep+1, sqrt(err2*err2/val2/val2 + err*err/val/val)*val/val2);



		}
	}


	TH2D * hEPres = new TH2D("hEPres", "hEPres", nCentBins, centbins, NumEPNames, 0, NumEPNames);
	TH2D * hSPres = new TH2D("hSPres", "hSPres", nCentBins, centbins, NumEPNames, 0, NumEPNames);

	for ( int c = 0; c < nCentBins; c++ ) {
		for ( int iep = 0; iep < NumEPNames; iep++ ) {
			double epAB = hEPresAB->GetBinContent(c+1, iep+1);
			double epAC = hEPresAC->GetBinContent(c+1, iep+1);
			double epBC = hEPresBC->GetBinContent(c+1, iep+1);
			double spAB = hSPresAB->GetBinContent(c+1, iep+1);
			double spAC = hSPresAC->GetBinContent(c+1, iep+1);
			double spBC = hSPresBC->GetBinContent(c+1, iep+1);

			double epABe = hEPresAB->GetBinError(c+1, iep+1);
			double epACe = hEPresAC->GetBinError(c+1, iep+1);
			double epBCe = hEPresBC->GetBinError(c+1, iep+1);
			double spABe = hSPresAB->GetBinError(c+1, iep+1);
			double spACe = hSPresAC->GetBinError(c+1, iep+1);
			double spBCe = hSPresBC->GetBinError(c+1, iep+1);

			double ep = epAB*epAC/epBC;
			double sp = spAB*spAC/spBC;

			double epe = ep*sqrt(epABe*epABe/epAB/epAB + epACe*epACe/epAC/epAC + epBCe*epBCe/epBC/epBC);
			double spe = ep*sqrt(spABe*spABe/spAB/spAB + spACe*spACe/spAC/spAC + spBCe*spBCe/spBC/spBC);

			hEPres->SetBinContent(c+1, iep+1, sqrt(ep));
			hSPres->SetBinContent(c+1, iep+1, sqrt(sp));

			hEPres->SetBinError(c+1, iep+1, epe/2/sqrt(ep));
			hSPres->SetBinError(c+1, iep+1, spe/2/sqrt(sp));
		}
	}

	for ( int ipt = 0; ipt < nPtBins; ipt++ ) {
		for ( int n = 1; n < 7; n++ ) {
			for ( int c = 0; c < nCentBins; c++ ) {
				for ( int iep = 0; iep < NumEPNames; iep++ ) {
					double vn = hEP[ipt][n]->GetBinContent(c+1, iep+1) / hMult->GetBinContent(c, ipt);
					double evn = hEP[ipt][n]->GetBinError(c+1, iep+1) / hMult->GetBinContent(c, ipt);
					double res = hEPres->GetBinContent(c+1, iep+1);
					double rese = hEPres->GetBinError(c+1, iep+1);
					hEP[ipt][n]->SetBinError(c+1, iep+1, sqrt(evn*evn/vn/vn + rese*rese/res/res) * vn/res );
					hEP[ipt][n]->SetBinContent(c+1, iep+1, vn/res);

					vn = hSP[ipt][n]->GetBinContent(c+1, iep+1) / hMult->GetBinContent(c, ipt);
					evn = hSP[ipt][n]->GetBinError(c+1, iep+1) / hMult->GetBinContent(c, ipt);
					res = hSPres->GetBinContent(c+1, iep+1);
					rese = hSPres->GetBinError(c+1, iep+1);
					hSP[ipt][n]->SetBinError(c+1, iep+1, sqrt(evn*evn/vn/vn + rese*rese/res/res) * vn/res );
					hSP[ipt][n]->SetBinContent(c+1, iep+1, vn/res);
				}
			}
		}
	}

	TFile * fsave = new TFile("save.root", "recreate");

	for ( int iep = 0; iep < NumEPNames; iep++ ) {
		for ( int n = 1; n < 7; n++ ) {
			hEP[iep][n]->Write();
			hSP[iep][n]->Write();
		}
	}
	hEPres->Write();
	hSPres->Write();
	hEPresAB->Write();
	hEPresAC->Write();
	hEPresBC->Write();
	hSPresAB->Write();
	hSPresAC->Write();
	hSPresBC->Write();
}
