{
#include "label.h"
#include "noff.h"
#include "style.h"
#include "helper.h"

//	int s1 = 139; // pPb std
//	int s2 = 229; // pPb p-side
//	int s3 = 233; // pPb Pb-side

	int s1 = 139; // pPb std
	int s2 = 40; // pPb p-side
	int s3 = 52; // pPb Pb-side

//	int s1 = 109; // PbPb std
//	int s2 = 234; // PbPb p-side
//	int s3 = 235; // PbPb Pb-side
//

	int bPbPb = 0;
	if ( s1 == 109 ) bPbPb = 1;

	int bEP = 1;
	int bDeco = 0;

	bool bHIN = 1;
	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("sys.C");
	gROOT->Macro("EP.C");

	double sys_pt = 0;
	double sys_eta = 0;
	if (bPbPb) {
		sys_pt = sys_pt_PbPb;
		sys_eta = sys_eta_PbPb;
	} else {
		sys_pt = sys_pt_pPb;
		sys_eta = sys_eta_pPb;
	}

	TFile *f1 = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	TFile *f2 = new TFile(Form("%s/outGraph.root", ftxt[s2]));
	TFile *f3 = new TFile(Form("%s/outGraph.root", ftxt[s3]));

	TGraphErrors * gr_v22_1[4] = {};
	TGraphErrors * gr_v24_1[4] = {};
	TGraphErrors * gr_v26_1[4] = {};
	TGraphErrors * gr_v28_1[4] = {};

	TGraphErrors * gr_v22_2[4] = {};
	TGraphErrors * gr_v24_2[4] = {};
	TGraphErrors * gr_v26_2[4] = {};
	TGraphErrors * gr_v28_2[4] = {};

	TGraphErrors * gr_v22_3[4] = {};
	TGraphErrors * gr_v24_3[4] = {};
	TGraphErrors * gr_v26_3[4] = {};
	TGraphErrors * gr_v28_3[4] = {};

	TGraphErrors * gr_v22_1_sys[4] = {};
	TGraphErrors * gr_v24_1_sys[4] = {};
	TGraphErrors * gr_v26_1_sys[4] = {};
	TGraphErrors * gr_v28_1_sys[4] = {};

	TGraphErrors * gr_v22_2_sys[4] = {};
	TGraphErrors * gr_v24_2_sys[4] = {};
	TGraphErrors * gr_v26_2_sys[4] = {};
	TGraphErrors * gr_v28_2_sys[4] = {};

	TGraphErrors * gr_v22_3_sys[4] = {};
	TGraphErrors * gr_v24_3_sys[4] = {};
	TGraphErrors * gr_v26_3_sys[4] = {};
	TGraphErrors * gr_v28_3_sys[4] = {};


	TMultiGraph * mgr_v22_HIN[4];
	TMultiGraph * mgr_v24_HIN[4];
	for ( int i = 0; i < 4; i++ ) {
		gr_v22_1[i] = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_0_%i", 7-i));
		gr_v24_1[i] = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_1_%i", 7-i));
		gr_v26_1[i] = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_2_%i", 6-i));
		gr_v28_1[i] = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_3_%i", 5-i));

		gr_v22_2[i] = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_0_%i", 7-i));
		gr_v24_2[i] = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_1_%i", 7-i));
		gr_v26_2[i] = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_2_%i", 6-i));
		gr_v28_2[i] = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_3_%i", 5-i));

		gr_v22_3[i] = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_0_%i", 7-i));
		gr_v24_3[i] = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_1_%i", 7-i));
		gr_v26_3[i] = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_2_%i", 6-i));
		gr_v28_3[i] = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_3_%i", 5-i));

		gr_v22_1_sys[i] = makeSys(gr_v22_1[i] , sys_pt);
		gr_v24_1_sys[i] = makeSys(gr_v24_1[i] , sys_pt);
		gr_v26_1_sys[i] = makeSys(gr_v26_1[i] , sys_pt);
		gr_v28_1_sys[i] = makeSys(gr_v28_1[i] , sys_pt);
		gr_v22_2_sys[i] = makeSys(gr_v22_2[i] , sys_pt);
		gr_v24_2_sys[i] = makeSys(gr_v24_2[i] , sys_pt);
		gr_v26_2_sys[i] = makeSys(gr_v26_2[i] , sys_pt);
		gr_v28_2_sys[i] = makeSys(gr_v28_2[i] , sys_pt);
		gr_v22_3_sys[i] = makeSys(gr_v22_3[i] , sys_pt);
		gr_v24_3_sys[i] = makeSys(gr_v24_3[i] , sys_pt);
		gr_v26_3_sys[i] = makeSys(gr_v26_3[i] , sys_pt);
		gr_v28_3_sys[i] = makeSys(gr_v28_3[i] , sys_pt);

		setSysPt(gr_v22_1_sys[i]);
		setSysPt(gr_v24_1_sys[i]);
		setSysPt(gr_v26_1_sys[i]);
		setSysPt(gr_v28_1_sys[i]);
		setSysPt(gr_v22_2_sys[i]);
		setSysPt(gr_v24_2_sys[i]);
		setSysPt(gr_v26_2_sys[i]);
		setSysPt(gr_v28_2_sys[i]);
		setSysPt(gr_v22_3_sys[i]);
		setSysPt(gr_v24_3_sys[i]);
		setSysPt(gr_v26_3_sys[i]);
		setSysPt(gr_v28_3_sys[i]);

		trimGrPT2(gr_v22_1_sys[i]);
		trimGrPT2(gr_v24_1_sys[i]);
		trimGrPT2(gr_v26_1_sys[i]);
		trimGrPT2(gr_v28_1_sys[i]);
		trimGrPT2(gr_v22_2_sys[i]);
		trimGrPT2(gr_v24_2_sys[i]);
		trimGrPT2(gr_v26_2_sys[i]);
		trimGrPT2(gr_v28_2_sys[i]);
		trimGrPT2(gr_v22_3_sys[i]);
		trimGrPT2(gr_v24_3_sys[i]);
		trimGrPT2(gr_v26_3_sys[i]);
		trimGrPT2(gr_v28_3_sys[i]);

		trimGrPT2(gr_v22_1[i]);
		trimGrPT2(gr_v24_1[i]);
		trimGrPT2(gr_v26_1[i]);
		trimGrPT2(gr_v28_1[i]);
		trimGrPT2(gr_v22_2[i]);
		trimGrPT2(gr_v24_2[i]);
		trimGrPT2(gr_v26_2[i]);
		trimGrPT2(gr_v28_2[i]);
		trimGrPT2(gr_v22_3[i]);
		trimGrPT2(gr_v24_3[i]);
		trimGrPT2(gr_v26_3[i]);
		trimGrPT2(gr_v28_3[i]);


		gr_v22_1[i]->SetMarkerStyle(kFullCircle);
		gr_v22_1[i]->SetMarkerColor(kBlack);
		gr_v22_1[i]->SetLineColor(kBlack);
		gr_v22_2[i]->SetMarkerStyle(kFullCircle);
		gr_v22_2[i]->SetMarkerColor(kRed);
		gr_v22_2[i]->SetLineColor(kRed);
		gr_v22_3[i]->SetMarkerStyle(kFullCircle);
		gr_v22_3[i]->SetMarkerColor(kBlue);
		gr_v22_3[i]->SetLineColor(kBlue);

		gr_v24_1[i]->SetMarkerStyle(kFullSquare);
		gr_v24_1[i]->SetMarkerColor(kBlack);
		gr_v24_1[i]->SetLineColor(kBlack);
		gr_v24_2[i]->SetMarkerStyle(kFullSquare);
		gr_v24_2[i]->SetMarkerColor(kRed);
		gr_v24_2[i]->SetLineColor(kRed);
		gr_v24_3[i]->SetMarkerStyle(kFullSquare);
		gr_v24_3[i]->SetMarkerColor(kBlue);
		gr_v24_3[i]->SetLineColor(kBlue);

		gr_v26_1[i]->SetMarkerStyle(kFullCross);
		gr_v26_1[i]->SetMarkerColor(kBlack);
		gr_v26_1[i]->SetLineColor(kBlack);
		gr_v26_2[i]->SetMarkerStyle(kFullCross);
		gr_v26_2[i]->SetMarkerColor(kRed);
		gr_v26_2[i]->SetLineColor(kRed);
		gr_v26_3[i]->SetMarkerStyle(kFullCross);
		gr_v26_3[i]->SetMarkerColor(kBlue);
		gr_v26_3[i]->SetLineColor(kBlue);

		gr_v28_1[i]->SetMarkerStyle(kFullDiamond);
		gr_v28_1[i]->SetMarkerColor(kBlack);
		gr_v28_1[i]->SetLineColor(kBlack);
		gr_v28_2[i]->SetMarkerStyle(kFullDiamond);
		gr_v28_2[i]->SetMarkerColor(kRed);
		gr_v28_2[i]->SetLineColor(kRed);
		gr_v28_3[i]->SetMarkerStyle(kFullDiamond);
		gr_v28_3[i]->SetMarkerColor(kBlue);
		gr_v28_3[i]->SetLineColor(kBlue);

		mgr_v22_HIN[i] = mgr_HIN13002_pPbPt[2][0][7-i];
		mgr_v24_HIN[i] = mgr_HIN13002_pPbPt[2][1][7-i];
		if ( bPbPb ) {
			mgr_v22_HIN[i] = mgr_HIN13002_PbPbPt[2][0][7-i];
			mgr_v24_HIN[i] = mgr_HIN13002_PbPbPt[2][1][7-i];
		}
	}

/////////////////////
	SetStyle();
	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);


/****************
	TCanvas * cT0 = MakeCanvas("cT0", "cT0", 1600, 500);
	makeMultiPanelCanvas(cT0, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, .1, 5.9, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}{2}");

	cT0->cd(1);
	hframe_pt->Draw();
	if ( bHIN ) {
		mgr_v22_HIN[0]->Draw();
	}

	gr_v22_1_sys[0]->Draw("[]2");
	gr_v22_2_sys[0]->Draw("[]2");
	gr_v22_3_sys[0]->Draw("[]2");

	gr_v22_1[0]->Draw("Psame");
	gr_v22_2[0]->Draw("Psame");
	gr_v22_3[0]->Draw("Psame");

	cT0->cd(2);
	hframe_pt->Draw();
	if ( bHIN ) {
		mgr_v22_HIN[1]->Draw();
	}

	gr_v22_1_sys[1]->Draw("[]2");
	gr_v22_2_sys[1]->Draw("[]2");
	gr_v22_3_sys[1]->Draw("[]2");

	gr_v22_1[1]->Draw("Psame");
	gr_v22_2[1]->Draw("Psame");
	gr_v22_3[1]->Draw("Psame");

	cT0->cd(3);
	hframe_pt->Draw();
	if ( bHIN ) {
		mgr_v22_HIN[2]->Draw();
	}

	gr_v22_1_sys[2]->Draw("[]2");
	gr_v22_2_sys[2]->Draw("[]2");
	gr_v22_3_sys[2]->Draw("[]2");

	gr_v22_1[2]->Draw("Psame");
	gr_v22_2[2]->Draw("Psame");
	gr_v22_3[2]->Draw("Psame");

	cT0->cd(4);
	hframe_pt->Draw();
	if ( bHIN ) {
		mgr_v22_HIN[3]->Draw();
	}

	gr_v22_1_sys[3]->Draw("[]2");
	gr_v22_2_sys[3]->Draw("[]2");
	gr_v22_3_sys[3]->Draw("[]2");

	gr_v22_1[3]->Draw("Psame");
	gr_v22_2[3]->Draw("Psame");
	gr_v22_3[3]->Draw("Psame");

	cT0->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT0->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT0->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT0->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT0->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT0->cd(2);
	TLegend * legPt1 = new TLegend(0.05, 0.75, 0.8, 0.97);
	legPt1->SetFillColor(kWhite);
	legPt1->SetBorderSize(0);
	legPt1->SetTextFont(43);
	legPt1->SetTextSize(18);
	legPt1->AddEntry(gr_HIN_13_002_PbPbv22pt5, "v_{2}{2, |#Delta#eta|>2} HIN-13-002", "p");
	legPt1->Draw();

	cT0->cd(3);
	TLegend * legPt2 = new TLegend(0.05, 0.75, 0.5, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->SetTextFont(43);
	legPt2->SetTextSize(18);
	legPt2->AddEntry(gr_v22_1[0], "v_{2}{2} |#eta|<2.4", "p");
	legPt2->AddEntry(gr_v22_2[0], "v_{2}^{p}{2}", "p");
	legPt2->AddEntry(gr_v22_3[0], "v_{2}^{Pb}{2}", "p");

	legPt2->Draw();
****************/

	if ( !bPbPb ) {
		for ( int i = 3; i < 8; i++ ) {
			gr_v2pt_p_EP_Pb[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_p_EP_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_p_EP_Pb[i]->SetLineColor(kRed);

			gr_v2pt_Pb_EP_p[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_Pb_EP_p[i]->SetMarkerColor(kBlue);
			gr_v2pt_Pb_EP_p[i]->SetLineColor(kBlue);

			gr_v2pt_p_EPde_Pb[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_p_EPde_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_p_EPde_Pb[i]->SetLineColor(kRed);

			gr_v2pt_Pb_EPde_p[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_Pb_EPde_p[i]->SetMarkerColor(kBlue);
			gr_v2pt_Pb_EPde_p[i]->SetLineColor(kBlue);

			gr_v2pt_p_SP_Pb[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_p_SP_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_p_SP_Pb[i]->SetLineColor(kRed);

			gr_v2pt_Pb_SP_p[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_Pb_SP_p[i]->SetMarkerColor(kBlue);
			gr_v2pt_Pb_SP_p[i]->SetLineColor(kBlue);

			gr_v2pt_p_SPde_Pb[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_p_SPde_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_p_SPde_Pb[i]->SetLineColor(kRed);

			gr_v2pt_Pb_SPde_p[i]->SetMarkerStyle(kOpenCircle);
			gr_v2pt_Pb_SPde_p[i]->SetMarkerColor(kBlue);
			gr_v2pt_Pb_SPde_p[i]->SetLineColor(kBlue);
		}
	}
/////////////////4////////////////////
	TCanvas * cT1 = MakeCanvas("cT1", "cT1", 1600, 500);
	makeMultiPanelCanvas(cT1, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_pt1 = new TH2D("hframe_pt1", "", 1, .1, 5.9, 1, 0, 0.35);
	InitHist(hframe_pt1, "p_{T} (GeV/c)", "v_{2}");
	hframe_pt1->SetTitleOffset(1.2);

	cT1->cd(1);
	hframe_pt1->Draw();
	if ( bHIN ) {
		mgr_v24_HIN[0]->Draw();
	}

	if ( !bPbPb ) {
		if ( bEP ) {
			if ( bDeco ) {
				gr_v2pt_p_EP_Pb[7]->Draw("Psame");
				gr_v2pt_Pb_EP_p[7]->Draw("Psame");
			} else {
				gr_v2pt_p_EPde_Pb[7]->Draw("Psame");
				gr_v2pt_Pb_EPde_p[7]->Draw("Psame");
			}
		} else {
			if ( bDeco ) {
				gr_v2pt_p_SP_Pb[7]->Draw("Psame");
				gr_v2pt_Pb_SP_p[7]->Draw("Psame");
			} else {
				gr_v2pt_p_SPde_Pb[7]->Draw("Psame");
				gr_v2pt_Pb_SPde_p[7]->Draw("Psame");
			}
		}
	}

//	gr_v24_1_sys[0]->Draw("[]2");
	gr_v24_2_sys[0]->Draw("[]2");
	gr_v24_3_sys[0]->Draw("[]2");

//	gr_v24_1[0]->Draw("Psame");
	gr_v24_2[0]->Draw("Psame");
	gr_v24_3[0]->Draw("Psame");

	cT1->cd(2);
	hframe_pt1->Draw();
	if ( bHIN ) {
		mgr_v24_HIN[1]->Draw();
	}

	if ( !bPbPb ) {
		if ( bEP ) {
			if ( bDeco ) {
				gr_v2pt_p_EP_Pb[6]->Draw("Psame");
				gr_v2pt_Pb_EP_p[6]->Draw("Psame");
			} else {
				gr_v2pt_p_EPde_Pb[6]->Draw("Psame");
				gr_v2pt_Pb_EPde_p[6]->Draw("Psame");
			}
		} else {
			if ( bDeco ) {
				gr_v2pt_p_SP_Pb[6]->Draw("Psame");
				gr_v2pt_Pb_SP_p[6]->Draw("Psame");
			} else {
				gr_v2pt_p_SPde_Pb[6]->Draw("Psame");
				gr_v2pt_Pb_SPde_p[6]->Draw("Psame");
			}
		}
	}


//	gr_v24_1_sys[1]->Draw("[]2");
	gr_v24_2_sys[1]->Draw("[]2");
	gr_v24_3_sys[1]->Draw("[]2");

//	gr_v24_1[1]->Draw("Psame");
	gr_v24_2[1]->Draw("Psame");
	gr_v24_3[1]->Draw("Psame");

	cT1->cd(3);
	hframe_pt1->Draw();
	if ( bHIN ) {
		mgr_v24_HIN[2]->Draw();
	}

	if ( !bPbPb ) {
		if ( bEP ) {
			if ( bDeco ) {
				gr_v2pt_p_EP_Pb[5]->Draw("Psame");
				gr_v2pt_Pb_EP_p[5]->Draw("Psame");
			} else {
				gr_v2pt_p_EPde_Pb[5]->Draw("Psame");
				gr_v2pt_Pb_EPde_p[5]->Draw("Psame");
			}
		} else {
			if ( bDeco ) {
				gr_v2pt_p_SP_Pb[5]->Draw("Psame");
				gr_v2pt_Pb_SP_p[5]->Draw("Psame");
			} else {
				gr_v2pt_p_SPde_Pb[5]->Draw("Psame");
				gr_v2pt_Pb_SPde_p[5]->Draw("Psame");
			}
		}
	}


//	gr_v24_1_sys[2]->Draw("[]2");
	gr_v24_2_sys[2]->Draw("[]2");
	gr_v24_3_sys[2]->Draw("[]2");

//	gr_v24_1[2]->Draw("Psame");
	gr_v24_2[2]->Draw("Psame");
	gr_v24_3[2]->Draw("Psame");

	cT1->cd(4);
	hframe_pt1->Draw();
	if ( bHIN ) {
		mgr_v24_HIN[3]->Draw();
	}

	if ( !bPbPb ) {
		if ( bEP ) {
			if ( bDeco ) {
				gr_v2pt_p_EP_Pb[4]->Draw("Psame");
				gr_v2pt_Pb_EP_p[4]->Draw("Psame");
			} else {
				gr_v2pt_p_EPde_Pb[4]->Draw("Psame");
				gr_v2pt_Pb_EPde_p[4]->Draw("Psame");
			}
		} else {
			if ( bDeco ) {
				gr_v2pt_p_SP_Pb[4]->Draw("Psame");
				gr_v2pt_Pb_SP_p[4]->Draw("Psame");
			} else {
				gr_v2pt_p_SPde_Pb[4]->Draw("Psame");
				gr_v2pt_Pb_SPde_p[4]->Draw("Psame");
			}
		}
	}

//	gr_v24_1_sys[3]->Draw("[]2");
	gr_v24_2_sys[3]->Draw("[]2");
	gr_v24_3_sys[3]->Draw("[]2");

//	gr_v24_1[3]->Draw("Psame");
	gr_v24_2[3]->Draw("Psame");
	gr_v24_3[3]->Draw("Psame");


	cT1->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT1->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT1->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT1->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT1->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT1->cd(2);
	TLegend * legPt1 = new TLegend(0.05, 0.8, 0.8, 0.97);
	legPt1->SetFillColor(kWhite);
	legPt1->SetBorderSize(0);
	legPt1->SetTextFont(43);
	legPt1->SetTextSize(18);
	if ( !bPbPb ) {
		legPt1->AddEntry(gr_v2pt_p_SPde_Pb[7], Form("v_{2}^{p}{%s,%s} 2.0<#eta<2.4", bEP?"EP":"SP", bDeco?"#eta_{C}=#eta_{POI}":"#eta_{C}=0"), "p");
		legPt1->AddEntry(gr_v2pt_Pb_SPde_p[7], Form("v_{2}^{Pb}{%s,%s} -2.4<#eta<-2.0", bEP?"EP":"SP", bDeco?"#eta_{C}=#eta_{POI}":"#eta_{C}=0"), "p");
		legPt1->Draw();
	}

	cT1->cd(3);
	TLegend * legPt2 = new TLegend(0.05, 0.75, 0.5, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->SetTextFont(43);
	legPt2->SetTextSize(18);
//	legPt2->AddEntry(gr_v24_1[0], "v_{2}{4} |#eta|<2.4", "p");
	legPt2->AddEntry(gr_HIN_13_002_PbPbv24pt5, "v_{2}{4} HIN-13-002 |#eta|<2.4", "p");
	legPt2->AddEntry(gr_v24_2[0], "v_{2}^{p}{4} 1.2<#eta<2.4", "p");
	legPt2->AddEntry(gr_v24_3[0], "v_{2}^{Pb}{4} -2.4<#eta<-1.2", "p");

	legPt2->Draw();

	/////////////////6////////////////////
	TCanvas * cT2 = MakeCanvas("cT2", "cT2", 1600, 500);
	makeMultiPanelCanvas(cT2, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_pt2 = new TH2D("hframe_pt2", "", 1, .1, 5.9, 1, 0, 0.35);
	InitHist(hframe_pt2, "p_{T} (GeV/c)", "v_{2}{6}");

	cT2->cd(1);
	hframe_pt2->Draw();

	gr_v26_1_sys[0]->Draw("[]2");
	gr_v26_2_sys[0]->Draw("[]2");
	gr_v26_3_sys[0]->Draw("[]2");

	gr_v26_1[0]->Draw("Psame");
	gr_v26_2[0]->Draw("Psame");
	gr_v26_3[0]->Draw("Psame");

	cT2->cd(2);
	hframe_pt2->Draw();

	gr_v26_1_sys[1]->Draw("[]2");
	gr_v26_2_sys[1]->Draw("[]2");
	gr_v26_3_sys[1]->Draw("[]2");

	gr_v26_1[1]->Draw("Psame");
	gr_v26_2[1]->Draw("Psame");
	gr_v26_3[1]->Draw("Psame");

	cT2->cd(3);
	hframe_pt2->Draw();

	gr_v26_1_sys[2]->Draw("[]2");
	gr_v26_2_sys[2]->Draw("[]2");
	gr_v26_3_sys[2]->Draw("[]2");

	gr_v26_1[2]->Draw("Psame");
	gr_v26_2[2]->Draw("Psame");
	gr_v26_3[2]->Draw("Psame");

	cT2->cd(4);
	hframe_pt2->Draw();

	gr_v26_1_sys[3]->Draw("[]2");
	gr_v26_2_sys[3]->Draw("[]2");
	gr_v26_3_sys[3]->Draw("[]2");

	gr_v26_1[3]->Draw("Psame");
	gr_v26_2[3]->Draw("Psame");
	gr_v26_3[3]->Draw("Psame");


	cT2->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT2->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT2->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT2->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT2->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT2->cd(3);
	TLegend * legPt2 = new TLegend(0.05, 0.75, 0.5, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->SetTextFont(43);
	legPt2->SetTextSize(18);
	legPt2->AddEntry(gr_v26_1[0], "v_{2}{6} |#eta|<2.4", "p");
	legPt2->AddEntry(gr_v26_2[0], "v_{2}^{p}{6}", "p");
	legPt2->AddEntry(gr_v26_3[0], "v_{2}^{Pb}{6}", "p");

	legPt2->Draw();

	/////////////////ratio////////////////////
	TCanvas * cT0r = MakeCanvas("cT0r", "cT0r", 1600, 500);
	makeMultiPanelCanvas(cT0r, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_ptR = new TH2D("hframe_ptR", "", 1, .1, 5.9, 1, 0.3, 1.49);
	InitHist(hframe_ptR, "p_{T} (GeV/c)", "v_{2}{2}(#eta)/v_{2}{2}(-#eta)");

	TLine line(0.1, 1., 5.9, 1.);

	TGraphErrors * gr_r22[4] = {};
	TGraphErrors * gr_r24[4] = {};
	for ( int i = 0; i < 4; i++ ) {
		if ( !bPbPb ) {
			if ( bEP ) {
				if ( bDeco ) {
					gr_r22[i] = makeRatioPt(gr_v2pt_p_EPde_Pb[7-i], gr_v2pt_Pb_EPde_p[7-i], 0, 15);
				} else {
					gr_r22[i] = makeRatioPt(gr_v2pt_p_EP_Pb[7-i], gr_v2pt_Pb_EP_p[7-i], 0, 15);
				}
			} else {
				if ( bDeco ) {
					gr_r22[i] = makeRatioPt(gr_v2pt_p_SPde_Pb[7-i], gr_v2pt_Pb_SPde_p[7-i], 0, 15);
				} else {
					gr_r22[i] = makeRatioPt(gr_v2pt_p_SP_Pb[7-i], gr_v2pt_Pb_SP_p[7-i], 0, 15);
				}
			}
			gr_r22[i]->SetMarkerColor(kRed);
			gr_r22[i]->SetLineColor(kRed);
		}
		gr_r24[i] = makeRatioPt(gr_v24_2[i], gr_v24_3[i], 0, 7);
		gr_r24[i]->SetMarkerColor(kBlue);
		gr_r24[i]->SetLineColor(kBlue);
	}

	cT0r->cd(1);
	hframe_ptR->Draw();
	line.Draw();

	if ( !bPbPb ) gr_r22[0]->Draw("Psame");
	gr_r24[0]->Draw("Psame");

	cT0r->cd(2);
	hframe_ptR->Draw();
	line.Draw();
	if ( !bPbPb ) gr_r22[1]->Draw("Psame");
	gr_r24[1]->Draw("Psame");

	cT0r->cd(3);
	hframe_ptR->Draw();
	line.Draw();
	if ( !bPbPb ) gr_r22[2]->Draw("Psame");
	gr_r24[2]->Draw("Psame");

	cT0r->cd(4);
	hframe_ptR->Draw();
	line.Draw();
	if ( !bPbPb ) gr_r22[3]->Draw("Psame");
	gr_r24[3]->Draw("Psame");


	cT0r->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT0r->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT0r->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT0r->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT0r->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT0r->cd(3);
	TLegend * legPt2 = new TLegend(0.05, 0.8, 0.5, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->SetTextFont(43);
	legPt2->SetTextSize(18);
	if ( !bPbPb ) {
		if ( bEP ) {
			if ( bDeco ) {
				legPt2->AddEntry(gr_r22[0], "v_{2}^{p}{EP,#eta=#eta_{POI}} / v_{2}^{Pb}{EP,#eta=#eta_{POI}}", "p");
			} else {
				legPt2->AddEntry(gr_r22[0], "v_{2}^{p}{EP,#eta=0} / v_{2}^{Pb}{EP,#eta=0}", "p");
			}
		} else {
			if ( bDeco ) {
				legPt2->AddEntry(gr_r22[0], "v_{2}^{p}{SP,#eta=#eta_{POI}} / v_{2}^{Pb}{SP,#eta=#eta_{POI}}", "p");
			} else {
				legPt2->AddEntry(gr_r22[0], "v_{2}^{p}{SP,#eta=0} / v_{2}^{Pb}{SP,#eta=0}", "p");
			}
		}
	}
	legPt2->AddEntry(gr_r24[0], "v_{2}^{p}{4} / v_{2}^{Pb}{4}", "p");

	legPt2->Draw();

	if (bPbPb) {
		cT1->SaveAs(Form("v24_pT_diff_PbPb_%i_%i.pdf", bEP, bDeco));
		cT2->SaveAs(Form("v26_pT_diff_PbPb_%i_%i.pdf", bEP, bDeco));
		cT0r->SaveAs(Form("v2_pT_diffRatio_PbPb_%i_%i.pdf", bEP, bDeco));

		cT1->SaveAs(Form("v24_pT_diff_PbPb_%i_%i_C.C", bEP, bDeco));
		cT2->SaveAs(Form("v26_pT_diff_PbPb_%i_%i_C.C", bEP, bDeco));
		cT0r->SaveAs(Form("v2_pT_diffRatio_PbPb_%i_%i_C.C", bEP, bDeco));
	} else {
		cT1->SaveAs(Form("v24_pT_diff_pPb_%i_%i.pdf", bEP, bDeco));
		cT2->SaveAs(Form("v26_pT_diff_pPb_%i_%i.pdf", bEP, bDeco));
		cT0r->SaveAs(Form("v2_pT_diffRatio_pPb_%i_%i.pdf", bEP, bDeco));

		cT1->SaveAs(Form("v24_pT_diff_pPb_%i_%i_C.C", bEP, bDeco));
		cT2->SaveAs(Form("v26_pT_diff_pPb_%i_%i_C.C", bEP, bDeco));
		cT0r->SaveAs(Form("v2_pT_diffRatio_pPb_%i_%i_C.C", bEP, bDeco));
	}


}
