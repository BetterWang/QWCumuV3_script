
{
//#include "helper.h"
	TFile * fLYZpPb = new TFile("txt/LYZ/v2diffpPbdataLYZN20.root");
	TFile * fLYZPbPb = new TFile("txt/LYZ/v2diffPbPbdataLYZN20.root");

	TGraphErrors * gr_LYZ_pPbPt[20] = {};
	TGraphErrors * gr_LYZ_pPbEta[20] = {};
	TGraphErrors * gr_LYZ_PbPbPt[20] = {};
	TGraphErrors * gr_LYZ_PbPbEta[20] = {};

	TGraphErrors * gr_LYZ_sys_pPbPt[20] = {};
	TGraphErrors * gr_LYZ_sys_pPbEta[20] = {};
	TGraphErrors * gr_LYZ_sys_PbPbPt[20] = {};
	TGraphErrors * gr_LYZ_sys_PbPbEta[20] = {};

	TMultiGraph * mgr_LYZ_pPbPt[20] = {};
	TMultiGraph * mgr_LYZ_pPbEta[20] = {};
	TMultiGraph * mgr_LYZ_PbPbPt[20] = {};
	TMultiGraph * mgr_LYZ_PbPbEta[20] = {};



	gr_LYZ_pPbPt[7] = (TGraphErrors*) fLYZpPb->Get("v2vspt120_150");
	gr_LYZ_pPbPt[6] = (TGraphErrors*) fLYZpPb->Get("v2vspt150_185");
	gr_LYZ_pPbPt[5] = (TGraphErrors*) fLYZpPb->Get("v2vspt185_220");
	gr_LYZ_pPbPt[4] = (TGraphErrors*) fLYZpPb->Get("v2vspt220_260");
	gr_LYZ_pPbPt[3] = (TGraphErrors*) fLYZpPb->Get("v2vspt260_300");

	gr_LYZ_pPbEta[7] = (TGraphErrors*) fLYZpPb->Get("v2vseta120_150");
	gr_LYZ_pPbEta[6] = (TGraphErrors*) fLYZpPb->Get("v2vseta150_185");
	gr_LYZ_pPbEta[5] = (TGraphErrors*) fLYZpPb->Get("v2vseta185_220");
	gr_LYZ_pPbEta[4] = (TGraphErrors*) fLYZpPb->Get("v2vseta220_260");
	gr_LYZ_pPbEta[3] = (TGraphErrors*) fLYZpPb->Get("v2vseta260_300");


	gr_LYZ_PbPbPt[7] = (TGraphErrors*) fLYZPbPb->Get("v2vspt120_150");
	gr_LYZ_PbPbPt[6] = (TGraphErrors*) fLYZPbPb->Get("v2vspt150_185");
	gr_LYZ_PbPbPt[5] = (TGraphErrors*) fLYZPbPb->Get("v2vspt185_220");
	gr_LYZ_PbPbPt[4] = (TGraphErrors*) fLYZPbPb->Get("v2vspt220_260");
	gr_LYZ_PbPbPt[3] = (TGraphErrors*) fLYZPbPb->Get("v2vspt260_300");

	gr_LYZ_PbPbEta[7] = (TGraphErrors*) fLYZPbPb->Get("v2vseta120_150");
	gr_LYZ_PbPbEta[6] = (TGraphErrors*) fLYZPbPb->Get("v2vseta150_185");
	gr_LYZ_PbPbEta[5] = (TGraphErrors*) fLYZPbPb->Get("v2vseta185_220");
	gr_LYZ_PbPbEta[4] = (TGraphErrors*) fLYZPbPb->Get("v2vseta220_260");
	gr_LYZ_PbPbEta[3] = (TGraphErrors*) fLYZPbPb->Get("v2vseta260_300");

	for ( int i = 3; i < 8; i++ ) {
		gr_LYZ_pPbPt[i]->SetMarkerStyle(kFullCircle);
		gr_LYZ_pPbPt[i]->SetMarkerSize(2);
		gr_LYZ_pPbPt[i]->SetMarkerColor(kBlack);
		gr_LYZ_pPbPt[i]->SetLineColor(kBlack);

		gr_LYZ_sys_pPbPt[i] = makeSys(gr_LYZ_pPbPt[i], sys_LYZ_pt_pPb);
		for ( int j = 0; j < gr_LYZ_sys_pPbPt[i]->GetN(); j++ ) {
			gr_LYZ_sys_pPbPt[i]->GetEX()[j] = 0.15;
		}
		gr_LYZ_sys_pPbPt[i]->SetFillColor(kGray);

		gr_LYZ_pPbEta[i]->SetMarkerStyle(kFullCircle);
		gr_LYZ_pPbEta[i]->SetMarkerSize(2);
		gr_LYZ_pPbEta[i]->SetMarkerColor(kBlack);
		gr_LYZ_pPbEta[i]->SetLineColor(kBlack);

		gr_LYZ_sys_pPbEta[i] = makeSys(gr_LYZ_pPbEta[i], sys_LYZ_eta_pPb);
		gr_LYZ_sys_pPbEta[i]->SetFillColor(kGray);

		gr_LYZ_PbPbPt[i]->SetMarkerStyle(kFullCircle);
		gr_LYZ_PbPbPt[i]->SetMarkerSize(2);
		gr_LYZ_PbPbPt[i]->SetMarkerColor(kBlack);
		gr_LYZ_PbPbPt[i]->SetLineColor(kBlack);

		gr_LYZ_sys_PbPbPt[i] = makeSys(gr_LYZ_PbPbPt[i], sys_LYZ_pt_PbPb);
		gr_LYZ_sys_PbPbPt[i]->SetFillColor(kGray);

		gr_LYZ_PbPbEta[i]->SetMarkerStyle(kFullCircle);
		gr_LYZ_PbPbEta[i]->SetMarkerSize(2);
		gr_LYZ_PbPbEta[i]->SetMarkerColor(kBlack);
		gr_LYZ_PbPbEta[i]->SetLineColor(kBlack);

		gr_LYZ_sys_PbPbEta[i] = makeSys(gr_LYZ_PbPbEta[i], sys_LYZ_eta_PbPb);
		gr_LYZ_sys_PbPbEta[i]->SetFillColor(kGray);

		mgr_LYZ_pPbPt[i] = new TMultiGraph();
		mgr_LYZ_pPbPt[i]->Add(gr_LYZ_sys_pPbPt[i], "[]2");
		mgr_LYZ_pPbPt[i]->Add(gr_LYZ_pPbPt[i], "p");

		mgr_LYZ_pPbEta[i] = new TMultiGraph();
		mgr_LYZ_pPbEta[i]->Add(gr_LYZ_sys_pPbEta[i], "[]2");
		mgr_LYZ_pPbEta[i]->Add(gr_LYZ_pPbEta[i], "p");

		mgr_LYZ_PbPbPt[i] = new TMultiGraph();
		mgr_LYZ_PbPbPt[i]->Add(gr_LYZ_sys_PbPbPt[i], "[]2");
		mgr_LYZ_PbPbPt[i]->Add(gr_LYZ_PbPbPt[i], "p");

		mgr_LYZ_PbPbEta[i] = new TMultiGraph();
		mgr_LYZ_PbPbEta[i]->Add(gr_LYZ_sys_PbPbEta[i], "[]2");
		mgr_LYZ_PbPbEta[i]->Add(gr_LYZ_PbPbEta[i], "p");
	}

}
