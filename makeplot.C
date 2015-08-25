// making plot

//void makeplot()
{
#include "label.h"
#include "noff.h"
#include "style.h"
#include "helper.h"
//	int s1 = 109; // PbPb
	int s1 = 139; // pPb
	int s2 = 1; // 1: C, 0:V

//	int bSys = 0;
	int bPbPb = 0;

	int bEP = 0;


	double sys_pt = 0;
	double sys_eta = 0;

	if ( s1 == 109 ) bPbPb = 1;


	TFile *f = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("sys.C");
	gROOT->Macro("LYZ.C");
	gROOT->Macro("EP.C");

	if (bPbPb) {
		sys_pt = sys_pt_PbPb;
		sys_eta = sys_eta_PbPb;
	} else {
		sys_pt = sys_pt_pPb;
		sys_eta = sys_eta_pPb;
	}

	TGraphErrors * gr_vnPt[7][4][20] = {};
	TGraphErrors * gr_vnEta[7][4][20] = {};

	TGraphErrors * gr_vnPt_sys[7][4][20] = {};
	TGraphErrors * gr_vnEta_sys[7][4][20] = {};

	TColor *red = new TColor(1001, 1, 0, 0, "red", 0.4);
	TColor *green = new TColor(1002, 1, 0, 0, "green", 0.4);
	TColor *blue = new TColor(1003, 1, 0, 0, "blue", 0.4);

	for ( int n = 1; n < 7; n++ ) {
		for ( int np = 0; np < 4; np++ ) {
			for ( int c = 0; c < 20; c++ ) {
				if ( s2 == 1 ) {
					gr_vnPt[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnPtC_%i_%i_%i", n, np, c));
					gr_vnEta[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnEtaC_%i_%i_%i", n, np, c));

				}

				if ( s2 == 0 ) {
					gr_vnPt[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnPtV_%i_%i_%i", n, np, c));
					gr_vnEta[n][np][c] = (TGraphErrors*)f->Get(Form("gr_vnEtaV_%i_%i_%i", n, np, c));
				}
				if ( np == 0 ) {
					if ( gr_vnPt[n][np][c] ) gr_vnPt[n][np][c]->SetMarkerColor(kRed);
					if ( gr_vnPt[n][np][c] ) gr_vnPt[n][np][c]->SetLineColor(kRed);
//					if ( gr_vnEta[n][np][c] ) gr_vnEta[n][np][c]->SetMarkerColor(kBlack);
//					if ( gr_vnEta[n][np][c] ) gr_vnEta[n][np][c]->SetLineColor(kBlack);
				}
				gr_vnPt_sys[n][np][c] = makeSys(gr_vnPt[n][np][c], sys_pt);
				if ( gr_vnPt_sys[n][np][c] ) {
					for ( int i = 0; i < gr_vnPt_sys[n][np][c]->GetN(); i++ ) {
						gr_vnPt_sys[n][np][c]->GetEX()[i] = 0.15;
					}
				}
				gr_vnEta_sys[n][np][c] = makeSys(gr_vnEta[n][np][c], sys_eta);
				if ( gr_vnEta_sys[n][np][c] ) {
					for ( int i = 0; i < gr_vnEta_sys[n][np][c]->GetN(); i++ ) {
						gr_vnEta_sys[n][np][c]->GetEX()[i] = 0.2;
					}
				}
				if ( np == 0 || np ==3 ) {
					if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(1001);
					if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(1001);
				}
				if ( np == 1 ) {
					if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(1002);
					if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(1002);
				}
				if ( np == 2 ) {
					if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(1003);
					if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(1003);
				}
				if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(kGray);
				if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(kGray);
				trimGrPT(gr_vnPt[n][np][c]);
				trimGrPT(gr_vnPt_sys[n][np][c]);
			}
		}
	}


	SetStyle();
	TCanvas * cT = MakeCanvas("cT", "cT", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, .1, 5.9, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");

	cT->cd(1);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][7]->Draw();
	else mgr_HIN13002_pPbPt[2][0][7]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][7]->Draw();
	else mgr_HIN13002_pPbPt[2][1][7]->Draw();
//	gr_vnPt[2][0][7]->Draw("Psame");
//	gr_vnPt[2][1][7]->Draw("Psame");

	if ( bPbPb ) gr_LYZ_PbPbPt[7]->Draw("Psame");
	else gr_LYZ_pPbPt[7]->Draw("Psame");

	if ( bEP ) {
		gr_v2pt_m_EPde_Pb[7]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_EPde_p[7]->Draw("Psame");
	} else {
		gr_v2pt_m_SPde_Pb[7]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_SPde_p[7]->Draw("Psame");
	}

	if (!bPbPb) gr_vnPt_sys[2][3][5]->RemovePoint(7);
	if (!bPbPb) gr_vnPt_sys[2][3][5]->RemovePoint(7);
	if (!bPbPb) gr_vnPt[2][3][5]->RemovePoint(7);
	if (!bPbPb) gr_vnPt[2][3][5]->RemovePoint(7);
	gr_vnPt_sys[2][2][6]->Draw("[]2");
	gr_vnPt_sys[2][3][5]->Draw("[]2");
	gr_vnPt[2][2][6]->Draw("Psame");
	gr_vnPt[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][6]->Draw();
	else mgr_HIN13002_pPbPt[2][0][6]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][6]->Draw();
	else mgr_HIN13002_pPbPt[2][1][6]->Draw();
//	gr_vnPt[2][0][6]->Draw("Psame");
//	gr_vnPt[2][1][6]->Draw("Psame");

	if ( bPbPb ) gr_LYZ_PbPbPt[6]->Draw("Psame");
	else gr_LYZ_pPbPt[6]->Draw("Psame");

	if ( bEP ) {
		gr_v2pt_m_EPde_Pb[6]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_EPde_p[7]->Draw("Psame");
	} else {
		gr_v2pt_m_SPde_Pb[6]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_SPde_p[7]->Draw("Psame");
	}

	gr_vnPt_sys[2][2][5]->Draw("[]2");
	gr_vnPt_sys[2][3][4]->Draw("[]2");
	gr_vnPt[2][2][5]->Draw("Psame");
	gr_vnPt[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][5]->Draw();
	else mgr_HIN13002_pPbPt[2][0][5]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][5]->Draw();
	else mgr_HIN13002_pPbPt[2][1][5]->Draw();
//	gr_vnPt[2][0][5]->Draw("Psame");
//	gr_vnPt[2][1][5]->Draw("Psame");

	if ( bPbPb ) gr_LYZ_PbPbPt[5]->Draw("Psame");
	else gr_LYZ_pPbPt[5]->Draw("Psame");


	if ( bEP ) {
		gr_v2pt_m_EPde_Pb[5]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_EPde_p[5]->Draw("Psame");
	} else {
		gr_v2pt_m_SPde_Pb[5]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_SPde_p[5]->Draw("Psame");
	}


	gr_vnPt_sys[2][2][4]->Draw("[]2");
	gr_vnPt_sys[2][3][3]->Draw("[]2");
	gr_vnPt[2][2][4]->Draw("Psame");
	gr_vnPt[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][4]->Draw();
	else mgr_HIN13002_pPbPt[2][0][4]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][4]->Draw();
	else mgr_HIN13002_pPbPt[2][1][4]->Draw();
//	gr_vnPt[2][0][4]->Draw("Psame");
//	gr_vnPt[2][1][4]->Draw("Psame");

	if ( bPbPb ) gr_LYZ_PbPbPt[4]->Draw("Psame");
	else gr_LYZ_pPbPt[4]->Draw("Psame");

	if ( bEP ) {
		gr_v2pt_m_EPde_Pb[4]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_EPde_p[4]->Draw("Psame");
	} else {
		gr_v2pt_m_SPde_Pb[4]->Draw("Psame");
		if (!bPbPb) gr_v2pt_m_SPde_p[4]->Draw("Psame");
	}


	gr_vnPt_sys[2][2][3]->Draw("[]2");
//	gr_vnPt_sys[2][3][2]->Draw("[]2");
	gr_vnPt[2][2][3]->Draw("Psame");
	if (bPbPb) gr_vnPt[2][3][2]->Draw("Psame");

	TLegend * legPt1 = new TLegend(0.1, 0.8, 0.7, 0.95);
	legPt1->SetFillColor(kWhite);
	legPt1->SetBorderSize(0);
	legPt1->SetTextFont(43);
	legPt1->SetTextSize(18);
	legPt1->AddEntry(gr_HIN_13_002_PbPbv22pt5, "HIN-13-002 v_{2}{2}", "p");
	legPt1->AddEntry(gr_HIN_13_002_PbPbv24pt5, "HIN-13-002 v_{2}{4}", "p");

	TLegend * legPt2 = new TLegend(0.05, 0.7, 0.6, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->SetTextFont(43);
	legPt2->SetTextSize(18);
//	legPt2->AddEntry(gr_vnPt[2][0][4], "v_{2}{2}", "p");
//	legPt2->AddEntry(gr_vnPt[2][1][4], "v_{2}{4}", "p");
	if (bPbPb) {
		if ( bEP ) legPt2->AddEntry(gr_v2pt_m_EPde_Pb[4], "v_{2}{EP}", "p");
		else legPt2->AddEntry(gr_v2pt_m_SPde_Pb[4], "v_{2}{SP}", "p");
	} else {
		if ( bEP ) {
			legPt2->AddEntry(gr_v2pt_m_EPde_Pb[4], "v_{2}{EP} Pb-going EP", "p");
			legPt2->AddEntry(gr_v2pt_m_EPde_p[4], "v_{2}{EP} p-going EP", "p");
		} else {
			legPt2->AddEntry(gr_v2pt_m_SPde_Pb[4], "v_{2}{SP} Pb-going EP", "p");
			legPt2->AddEntry(gr_v2pt_m_SPde_p[4], "v_{2}{SP} p-going EP", "p");
		}
	}
	legPt2->AddEntry(gr_vnPt[2][2][4], "v_{2}{6}", "p");
	legPt2->AddEntry(gr_vnPt[2][3][4], "v_{2}{8}", "p");
	legPt2->AddEntry(gr_LYZ_pPbPt[4], "v_{2}{LYZ}", "p");

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT->cd(2);
	legPt1->Draw();

	cT->cd(3);
	legPt2->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT->SaveAs(Form("pT_%i_%i.pdf", s1, bEP));

///////////////////////////////////////
	cT = MakeCanvas("cTeta", "cTeta", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.4, 2.4, 1, 0, 0.16);
	InitHist(hframe_eta, "#eta", "v_{2}");

	TGraphErrors* gr_EP_eta[20] = {};
	TGraphErrors* gr_EP_eta_de[20] = {};

	cT->cd(1);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[7]->Draw("Psame");
	else gr_LYZ_pPbEta[7]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta[7] = merge_EP_longrange(gr_v2p_EP[7], gr_v2Pb_EP[7]);
	} else {
		gr_EP_eta[7] = merge_EP_longrange(gr_v2p_SP[7], gr_v2Pb_SP[7]);
	}
	gr_EP_eta[7]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta_de[7] = merge_EP_longrange(gr_v2p_EP_de[7], gr_v2Pb_EP_de[7], kOpenCircle, kBlue);
	} else {
		gr_EP_eta_de[7] = merge_EP_longrange(gr_v2p_SP_de[7], gr_v2Pb_SP_de[7], kOpenCircle, kBlue);
	}
	gr_EP_eta_de[7]->Draw("Psame");

//	gr_vnEta_sys[2][0][7]->Draw("[]2");
	gr_vnEta_sys[2][1][7]->Draw("[]2");
	gr_vnEta_sys[2][2][6]->Draw("[]2");
//	gr_vnEta[2][0][7]->Draw("Psame");
	gr_vnEta[2][1][7]->Draw("Psame");
	gr_vnEta[2][2][6]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[6]->Draw("Psame");
	else gr_LYZ_pPbEta[6]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta[6] = merge_EP_longrange(gr_v2p_EP[6], gr_v2Pb_EP[6]);
	} else {
		gr_EP_eta[6] = merge_EP_longrange(gr_v2p_SP[6], gr_v2Pb_SP[6]);
	}
	gr_EP_eta[6]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta_de[6] = merge_EP_longrange(gr_v2p_EP_de[6], gr_v2Pb_EP_de[6], kOpenCircle, kBlue);
	} else {
		gr_EP_eta_de[6] = merge_EP_longrange(gr_v2p_SP_de[6], gr_v2Pb_SP_de[6], kOpenCircle, kBlue);
	}
	gr_EP_eta_de[6]->Draw("Psame");


//	gr_v2p_SP[6]->Draw("Psame");
//	gr_v2Pb_SP[6]->Draw("Psame");
//	gr_vnEta_sys[2][0][6]->Draw("[]2");
	gr_vnEta_sys[2][1][6]->Draw("[]2");
	gr_vnEta_sys[2][2][5]->Draw("[]2");
//	gr_vnEta[2][0][6]->Draw("Psame");
	gr_vnEta[2][1][6]->Draw("Psame");
	gr_vnEta[2][2][5]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[5]->Draw("Psame");
	else gr_LYZ_pPbEta[5]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta[5] = merge_EP_longrange(gr_v2p_EP[5], gr_v2Pb_EP[5]);
	} else {
		gr_EP_eta[5] = merge_EP_longrange(gr_v2p_SP[5], gr_v2Pb_SP[5]);
	}
	gr_EP_eta[5]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta_de[5] = merge_EP_longrange(gr_v2p_EP_de[5], gr_v2Pb_EP_de[5], kOpenCircle, kBlue);
	} else {
		gr_EP_eta_de[5] = merge_EP_longrange(gr_v2p_SP_de[5], gr_v2Pb_SP_de[5], kOpenCircle, kBlue);
	}
	gr_EP_eta_de[5]->Draw("Psame");


//	gr_vnEta_sys[2][0][5]->Draw("[]2");
	gr_vnEta_sys[2][1][5]->Draw("[]2");
	gr_vnEta_sys[2][2][4]->Draw("[]2");
//	gr_vnEta[2][0][5]->Draw("Psame");
	gr_vnEta[2][1][5]->Draw("Psame");
	gr_vnEta[2][2][4]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[4]->Draw("Psame");
	else gr_LYZ_pPbEta[4]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta[4] = merge_EP_longrange(gr_v2p_EP[4], gr_v2Pb_EP[4]);
	} else {
		gr_EP_eta[4] = merge_EP_longrange(gr_v2p_SP[4], gr_v2Pb_SP[4]);
	}
	gr_EP_eta[4]->Draw("Psame");

	if ( bEP ) {
		gr_EP_eta_de[4] = merge_EP_longrange(gr_v2p_EP_de[4], gr_v2Pb_EP_de[4], kOpenCircle, kBlue);
	} else {
		gr_EP_eta_de[4] = merge_EP_longrange(gr_v2p_SP_de[4], gr_v2Pb_SP_de[4], kOpenCircle, kBlue);
	}
	gr_EP_eta_de[4]->Draw("Psame");


//	gr_vnEta_sys[2][0][4]->Draw("[]2");
	gr_vnEta_sys[2][1][4]->Draw("[]2");
	gr_vnEta_sys[2][2][3]->Draw("[]2");
//	gr_vnEta[2][0][4]->Draw("Psame");
	gr_vnEta[2][1][4]->Draw("Psame");
	gr_vnEta[2][2][3]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][2]->Draw("Psame");

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT->cd(2);
	TLegend * legEtaEP = new TLegend(0.05, 0.8, 0.3, 0.97);
	legEtaEP->SetFillColor(kWhite);
	legEtaEP->SetBorderSize(0);
	legEtaEP->SetTextFont(43);
	legEtaEP->SetTextSize(18);
	if ( bEP ) {
		legEtaEP->AddEntry(gr_EP_eta[4], "v_{2}{EP, #eta_{C}=0}", "p");
		legEtaEP->AddEntry(gr_EP_eta_de[4], "v_{2}{EP, #eta_{C}=#eta_{POI}}", "p");
	} else {
		legEtaEP->AddEntry(gr_EP_eta[4], "v_{2}{SP, #eta_{C}=0}", "p");
		legEtaEP->AddEntry(gr_EP_eta_de[4], "v_{2}{SP, #eta_{C}=#eta_{POI}}", "p");
	}
	legEtaEP->Draw();


	cT->cd(3);
	TLegend * legEta = new TLegend(0.05, 0.7, 0.3, 0.97);
	legEta->SetFillColor(kWhite);
	legEta->SetBorderSize(0);
	legEta->SetTextFont(43);
	legEta->SetTextSize(18);
	legEta->AddEntry(gr_vnEta[2][1][4], "v_{2}{4}", "p");
	legEta->AddEntry(gr_vnEta[2][2][4], "v_{2}{6}", "p");
	if (bPbPb) legEta->AddEntry(gr_vnEta[2][3][4], "v_{2}{8}", "p");
	legEta->AddEntry(gr_LYZ_pPbEta[4], "v_{2}{LYZ}", "p");
	legEta->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT->SaveAs(Form("eta_%i_%i.pdf", s1, bEP));
///**************** 
	cT = MakeCanvas("cTratio", "cTratio", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);


	TH2D * hframe_ratio = new TH2D("hframe_ratio", "", 1, 0, 2.4, 1, 0.61, 1.29);
	InitHist(hframe_ratio, "#eta_{CM}", "v_{2}^{#eta} / v_{2}^{-#eta}");

	TGraphErrors * gr_ratio[7][4][20];
	TGraphErrors * gr_EP_ratio[20];
	TLine *line = new TLine(0., 1., 2.4, 1.);
	line->SetLineStyle(kDashed);

	cT->cd(1);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][7] = makeRatio(gr_vnEta[2][0][7]);
	gr_ratio[2][1][7] = makeRatio(gr_vnEta[2][1][7]);
	gr_ratio[2][2][6] = makeRatio(gr_vnEta[2][2][6]);
	gr_ratio[2][3][5] = makeRatio(gr_vnEta[2][3][5]);

	gr_EP_ratio[7] = makeRatioEP(gr_EP_eta[7]);
	gr_EP_ratio[7]->Draw("Psame");

//	gr_ratio[2][0][7]->Draw("Psame");
	gr_ratio[2][1][7]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][2][6]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][6] = makeRatio(gr_vnEta[2][0][6]);
	gr_ratio[2][1][6] = makeRatio(gr_vnEta[2][1][6]);
	gr_ratio[2][2][5] = makeRatio(gr_vnEta[2][2][5]);
	gr_ratio[2][3][4] = makeRatio(gr_vnEta[2][3][4]);

	gr_EP_ratio[6] = makeRatioEP(gr_EP_eta[6]);
	gr_EP_ratio[6]->Draw("Psame");

//	gr_ratio[2][0][6]->Draw("Psame");
	gr_ratio[2][1][6]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][2][5]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][5] = makeRatio(gr_vnEta[2][0][5]);
	gr_ratio[2][1][5] = makeRatio(gr_vnEta[2][1][5]);
	gr_ratio[2][2][4] = makeRatio(gr_vnEta[2][2][4]);
	gr_ratio[2][3][3] = makeRatio(gr_vnEta[2][3][3]);

	gr_EP_ratio[5] = makeRatioEP(gr_EP_eta[5]);
	gr_EP_ratio[5]->Draw("Psame");


//	gr_ratio[2][0][5]->Draw("Psame");
	gr_ratio[2][1][5]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][2][4]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][4] = makeRatio(gr_vnEta[2][0][4]);
	gr_ratio[2][1][4] = makeRatio(gr_vnEta[2][1][4]);
	gr_ratio[2][2][3] = makeRatio(gr_vnEta[2][2][3]);
	gr_ratio[2][3][2] = makeRatio(gr_vnEta[2][3][2]);

	gr_EP_ratio[4] = makeRatioEP(gr_EP_eta[4]);
	gr_EP_ratio[4]->Draw("Psame");


//	gr_ratio[2][0][4]->Draw("Psame");
	gr_ratio[2][1][4]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][2][3]->Draw("Psame");
//	if (bPbPb) gr_ratio[2][3][2]->Draw("Psame");

	gROOT->Macro("HIN-14-008.C");
	if (!bPbPb) mgr_ratio->Draw();

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	TLegend * legRatio = new TLegend(0.05, 0.75, 0.5, 0.97);
	legRatio->SetFillColor(kWhite);
	legRatio->SetBorderSize(0);
	legRatio->SetTextFont(43);
	legRatio->SetTextSize(18);
	legRatio->AddEntry(gr_ratioHIN, "HIN-14-008", "p");
	if ( bEP ) {
		legRatio->AddEntry(gr_EP_ratio[4], "v_{2}{EP}", "p");
	} else {
		legRatio->AddEntry(gr_EP_ratio[4], "v_{2}{SP}", "p");
	}
	legRatio->AddEntry(gr_ratio[2][1][4], "v_{2}{4}", "p");
	cT->cd(3);
	legRatio->Draw();

	cT->SaveAs(Form("ratio_%i_%i.pdf", s1, bEP));

///////////////////////////////
	if ( !bPbPb ) {
		TCanvas * cNormEta = MakeCanvas("cNormEta", "cNormEta", 600, 500);

		TH2D * hframe_etaNorm = new TH2D("hframe_etaNorm", "", 1, -2.4, 2.4, 1, 0, 1.49);
		InitHist(hframe_etaNorm, "#eta", "v_{2}(#eta) / v_{2}(#eta=0)");

		TGraphErrors * gr_Norm = gr_vnEta[2][1][4]->Clone("gr_Norm");
		double v2norm = (gr_Norm->GetY()[11] + gr_Norm->GetY()[12])/2.;
		double ev2norm = sqrt(gr_Norm->GetEY()[11]**2 + gr_Norm->GetEY()[12]**2)/2;
		for ( int i = 0; i < 24; i++ ) {
			gr_Norm->GetEY()[i] = sqrt( (gr_Norm->GetEY()[i]/gr_Norm->GetY()[i])**2 + (ev2norm/v2norm)**2 ) * gr_Norm->GetY()[i] / v2norm;
			gr_Norm->GetY()[i] = gr_Norm->GetY()[i] / v2norm;
		}
		hframe_etaNorm->Draw();
		gr_Norm->Draw("Psame");
		gr_norm_p->Draw("Psame");
		gr_norm_Pb->Draw("Psame");

		TGraphErrors* gr_Norm_EP = gr_EP_eta[4]->Clone("gr_Norm_EP");
		v2norm = (gr_Norm_EP->GetY()[5] + gr_Norm_EP->GetY()[6]) / 2.;
		ev2norm = sqrt(gr_Norm_EP->GetEY()[5]**2 + gr_Norm_EP->GetEY()[6]**2)/2;
		for ( int i = 0; i < 12; i++ ) {
			gr_Norm_EP->GetEY()[i] = sqrt( (gr_Norm_EP->GetEY()[i]/gr_Norm_EP->GetY()[i])**2 + (ev2norm/v2norm)**2 ) * gr_Norm_EP->GetY()[i] / v2norm;
			gr_Norm_EP->GetY()[i] = gr_Norm_EP->GetY()[i] / v2norm;
		}
		gr_Norm_EP->Draw("Psame");

		latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");
		TLegend * legNorm = new TLegend(0.2, 0.3, 0.55, 0.5);
		legNorm->SetFillColor(kWhite);
		legNorm->SetBorderSize(0);
		legNorm->SetTextFont(43);
		legNorm->SetTextSize(18);
		legNorm->AddEntry(gr_Norm, "v_{2}{4}", "p");
		if ( bEP ) {
			legNorm->AddEntry(gr_Norm_EP, "v_{2}{EP}", "p");
		} else {
			legNorm->AddEntry(gr_Norm_EP, "v_{2}{SP}", "p");
		}
		legNorm->AddEntry(gr_norm_p, "HIN-14-008 p-trig", "p");
		legNorm->AddEntry(gr_norm_Pb, "HIN-14-008 Pb-trig", "p");
		legNorm->Draw();

		cNormEta->SaveAs("norm_pPb.pdf");
	}
//////////////////////////////////////
	if ( !bPbPb ) {
		cT = MakeCanvas("cT_EPpt", "cT_EPpt", 2100, 900);
		makeMultiPanelCanvas(cT, 5, 2, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_EPpt = new TH2D("hframe_EPpt", "", 1, .1, 5.9, 1, 0, 0.39);
		InitHist(hframe_EPpt, "p_{T} (GeV/c)", "v_{2}");

		cT->cd(1);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EP_Pb[7]->Draw("Psame");
			gr_v2pt_Pb_EP_p[7]->Draw("Psame");
		} else {
			gr_v2pt_p_SP_Pb[7]->Draw("Psame");
			gr_v2pt_Pb_SP_p[7]->Draw("Psame");
		}

		cT->cd(6);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EPde_Pb[7]->Draw("Psame");
			gr_v2pt_Pb_EPde_p[7]->Draw("Psame");
		} else {
			gr_v2pt_p_SPde_Pb[7]->Draw("Psame");
			gr_v2pt_Pb_SPde_p[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EP_Pb[6]->Draw("Psame");
			gr_v2pt_Pb_EP_p[6]->Draw("Psame");
		} else {
			gr_v2pt_p_SP_Pb[6]->Draw("Psame");
			gr_v2pt_Pb_SP_p[6]->Draw("Psame");
		}

		cT->cd(7);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EPde_Pb[6]->Draw("Psame");
			gr_v2pt_Pb_EPde_p[6]->Draw("Psame");
		} else {
			gr_v2pt_p_SPde_Pb[6]->Draw("Psame");
			gr_v2pt_Pb_SPde_p[6]->Draw("Psame");
		}

		cT->cd(3);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EP_Pb[5]->Draw("Psame");
			gr_v2pt_Pb_EP_p[5]->Draw("Psame");
		} else {
			gr_v2pt_p_SP_Pb[5]->Draw("Psame");
			gr_v2pt_Pb_SP_p[5]->Draw("Psame");
		}

		cT->cd(8);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EPde_Pb[5]->Draw("Psame");
			gr_v2pt_Pb_EPde_p[5]->Draw("Psame");
		} else {
			gr_v2pt_p_SPde_Pb[5]->Draw("Psame");
			gr_v2pt_Pb_SPde_p[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EP_Pb[4]->Draw("Psame");
			gr_v2pt_Pb_EP_p[4]->Draw("Psame");
		} else {
			gr_v2pt_p_SP_Pb[4]->Draw("Psame");
			gr_v2pt_Pb_SP_p[4]->Draw("Psame");
		}

		cT->cd(9);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EPde_Pb[4]->Draw("Psame");
			gr_v2pt_Pb_EPde_p[4]->Draw("Psame");
		} else {
			gr_v2pt_p_SPde_Pb[4]->Draw("Psame");
			gr_v2pt_Pb_SPde_p[4]->Draw("Psame");
		}

		cT->cd(5);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EP_Pb[3]->Draw("Psame");
			gr_v2pt_Pb_EP_p[3]->Draw("Psame");
		} else {
			gr_v2pt_p_SP_Pb[3]->Draw("Psame");
			gr_v2pt_Pb_SP_p[3]->Draw("Psame");
		}

		cT->cd(10);
		hframe_EPpt->Draw();
		if ( bEP ) {
			gr_v2pt_p_EPde_Pb[3]->Draw("Psame");
			gr_v2pt_Pb_EPde_p[3]->Draw("Psame");
		} else {
			gr_v2pt_p_SPde_Pb[3]->Draw("Psame");
			gr_v2pt_Pb_SPde_p[3]->Draw("Psame");
		}

		cT->cd(1);
		latex.DrawLatexNDC(0.40, 0.2, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex.DrawLatexNDC(0.40, 0.2, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex.DrawLatexNDC(0.40, 0.2, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex.DrawLatexNDC(0.40, 0.2, "#bf{220 #leq N_{trk}^{offline} < 260}");
		cT->cd(5);
		latex.DrawLatexNDC(0.40, 0.2, "#bf{260 #leq N_{trk}^{offline} < 300}");

		TLegend * legEPpT = new TLegend(0.05, 0.7, 0.5, 0.95);
		legEPpT->SetFillColor(kWhite);
		legEPpT->SetBorderSize(0);
		legEPpT->SetTextFont(43);
		legEPpT->SetTextSize(18);
		if ( bEP ) {
			legEPpT->AddEntry(gr_v2pt_p_EP_Pb[3], "v_{2}^{p}{EP, #eta_{C}=0}", "p");
			legEPpT->AddEntry(gr_v2pt_Pb_EP_p[3], "v_{2}^{Pb}{EP, #eta_{C}=0}", "p");
			legEPpT->AddEntry(gr_v2pt_p_EPde_Pb[3], "v_{2}^{p}{EP, #eta_{C}=#eta_{POI}}", "p");
			legEPpT->AddEntry(gr_v2pt_Pb_EPde_p[3], "v_{2}^{Pb}{EP, #eta_{C}=#eta_{POI}}", "p");
		} else {
			legEPpT->AddEntry(gr_v2pt_p_SP_Pb[3], "v_{2}^{p}{SP, #eta_{C}=0}", "p");
			legEPpT->AddEntry(gr_v2pt_Pb_SP_p[3], "v_{2}^{Pb}{SP, #eta_{C}=0}", "p");
			legEPpT->AddEntry(gr_v2pt_p_SPde_Pb[3], "v_{2}^{p}{SP, #eta_{C}=#eta_{POI}}", "p");
			legEPpT->AddEntry(gr_v2pt_Pb_SPde_p[3], "v_{2}^{Pb}{SP, #eta_{C}=#eta_{POI}}", "p");
		}

		cT->cd(10);
		legEPpT->Draw();

		cT->cd(1);
		if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
		else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");


		cT->SaveAs(Form("EPpT_%i_%i.pdf", s1, bEP));
	}

///////////////////////////////////////

	if ( !bPbPb ) {
		cT = MakeCanvas("cTeta3", "cTeta3", 1600, 500);
		makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_eta3 = new TH2D("hframe_eta3", "", 1, -2.4, 2.4, 1, 0, 0.049);
		InitHist(hframe_eta3, "#eta", "v_{3}");

		TGraphErrors* gr_EP_eta3[20] = {};
		TGraphErrors* gr_EP_eta_de3[20] = {};

		cT->cd(1);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[7] = merge_EP_longrange(gr_v3p_EP[7], gr_v3Pb_EP[7]);
			gr_EP_eta3[7]->Draw("Psame");
			gr_EP_eta_de3[7] = merge_EP_longrange(gr_v3p_EP_de[7], gr_v3Pb_EP_de[7], kOpenCircle, kBlue);
			gr_EP_eta_de3[7]->Draw("Psame");
		} else {
			gr_EP_eta3[7] = merge_EP_longrange(gr_v3p_SP[7], gr_v3Pb_SP[7]);
			gr_EP_eta3[7]->Draw("Psame");
			gr_EP_eta_de3[7] = merge_EP_longrange(gr_v3p_SP_de[7], gr_v3Pb_SP_de[7], kOpenCircle, kBlue);
			gr_EP_eta_de3[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[6] = merge_EP_longrange(gr_v3p_EP[6], gr_v3Pb_EP[6]);
			gr_EP_eta3[6]->Draw("Psame");
			gr_EP_eta_de3[6] = merge_EP_longrange(gr_v3p_EP_de[6], gr_v3Pb_EP_de[6], kOpenCircle, kBlue);
			gr_EP_eta_de3[6]->Draw("Psame");
		} else {
			gr_EP_eta3[6] = merge_EP_longrange(gr_v3p_SP[6], gr_v3Pb_SP[6]);
			gr_EP_eta3[6]->Draw("Psame");
			gr_EP_eta_de3[6] = merge_EP_longrange(gr_v3p_SP_de[6], gr_v3Pb_SP_de[6], kOpenCircle, kBlue);
			gr_EP_eta_de3[6]->Draw("Psame");
		}

		cT->cd(3);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[5] = merge_EP_longrange(gr_v3p_EP[5], gr_v3Pb_EP[5]);
			gr_EP_eta3[5]->Draw("Psame");
			gr_EP_eta_de3[5] = merge_EP_longrange(gr_v3p_EP_de[5], gr_v3Pb_EP_de[5], kOpenCircle, kBlue);
			gr_EP_eta_de3[5]->Draw("Psame");
		} else {
			gr_EP_eta3[5] = merge_EP_longrange(gr_v3p_SP[5], gr_v3Pb_SP[5]);
			gr_EP_eta3[5]->Draw("Psame");
			gr_EP_eta_de3[5] = merge_EP_longrange(gr_v3p_SP_de[5], gr_v3Pb_SP_de[5], kOpenCircle, kBlue);
			gr_EP_eta_de3[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[4] = merge_EP_longrange(gr_v3p_EP[4], gr_v3Pb_EP[4]);
			gr_EP_eta3[4]->Draw("Psame");
			gr_EP_eta_de3[4] = merge_EP_longrange(gr_v3p_EP_de[4], gr_v3Pb_EP_de[4], kOpenCircle, kBlue);
			gr_EP_eta_de3[4]->Draw("Psame");
		} else {
			gr_EP_eta3[4] = merge_EP_longrange(gr_v3p_SP[4], gr_v3Pb_SP[4]);
			gr_EP_eta3[4]->Draw("Psame");
			gr_EP_eta_de3[4] = merge_EP_longrange(gr_v3p_SP_de[4], gr_v3Pb_SP_de[4], kOpenCircle, kBlue);
			gr_EP_eta_de3[4]->Draw("Psame");
		}

		cT->cd(1);
		latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

		cT->cd(2);
		TLegend * legEtaEP3 = new TLegend(0.05, 0.75, 0.3, 0.97);
		legEtaEP3->SetFillColor(kWhite);
		legEtaEP3->SetBorderSize(0);
		legEtaEP3->SetTextFont(43);
		legEtaEP3->SetTextSize(18);
		legEtaEP3->AddEntry(gr_EP_eta3[4], "v_{3}{EP, #eta_{C}=0}", "p");
		legEtaEP3->AddEntry(gr_EP_eta_de3[4], "v_{3}{EP, #eta_{C}=#eta_{POI}}", "p");
		legEtaEP3->Draw();

		cT->cd(3);

		cT->cd(1);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

		cT->SaveAs(Form("eta3_%i_%i.pdf", s1, bEP));
	}
//////////////////////
	if ( !bPbPb ) {
		cT = MakeCanvas("cT_EPeta3", "cT_EPeta3", 2100, 900);
		makeMultiPanelCanvas(cT, 5, 2, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_EPeta3 = new TH2D("hframe_EPeta3", "", 1, -2.4, 2.4, 1, 0, 0.049);
		InitHist(hframe_EPeta3, "#eta", "v_{3}");

		cT->cd(1);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP[7]->Draw("Psame");
			gr_v3Pb_EP[7]->Draw("Psame");
		} else {
			gr_v3p_SP[7]->Draw("Psame");
			gr_v3Pb_SP[7]->Draw("Psame");
		}

		cT->cd(6);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP_de[7]->Draw("Psame");
			gr_v3Pb_EP_de[7]->Draw("Psame");
		} else {
			gr_v3p_SP_de[7]->Draw("Psame");
			gr_v3Pb_SP_de[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP[6]->Draw("Psame");
			gr_v3Pb_EP[6]->Draw("Psame");
		} else {
			gr_v3p_SP[6]->Draw("Psame");
			gr_v3Pb_SP[6]->Draw("Psame");
		}

		cT->cd(7);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP_de[6]->Draw("Psame");
			gr_v3Pb_EP_de[6]->Draw("Psame");
		} else {
			gr_v3p_SP_de[7]->Draw("Psame");
			gr_v3Pb_SP_de[7]->Draw("Psame");
		}

		cT->cd(3);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP[5]->Draw("Psame");
			gr_v3Pb_EP[5]->Draw("Psame");
		} else {
			gr_v3p_SP[5]->Draw("Psame");
			gr_v3Pb_SP[5]->Draw("Psame");
		}

		cT->cd(8);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP_de[5]->Draw("Psame");
			gr_v3Pb_EP_de[5]->Draw("Psame");
		} else {
			gr_v3p_SP_de[5]->Draw("Psame");
			gr_v3Pb_SP_de[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP[4]->Draw("Psame");
			gr_v3Pb_EP[4]->Draw("Psame");
		} else {
			gr_v3p_SP[4]->Draw("Psame");
			gr_v3Pb_SP[4]->Draw("Psame");
		}

		cT->cd(9);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP_de[4]->Draw("Psame");
			gr_v3Pb_EP_de[4]->Draw("Psame");
		} else {
			gr_v3p_SP_de[4]->Draw("Psame");
			gr_v3Pb_SP_de[4]->Draw("Psame");
		}

		cT->cd(5);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP[3]->Draw("Psame");
			gr_v3Pb_EP[3]->Draw("Psame");
		} else {
			gr_v3p_SP[3]->Draw("Psame");
			gr_v3Pb_SP[3]->Draw("Psame");
		}

		cT->cd(10);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			gr_v3p_EP_de[3]->Draw("Psame");
			gr_v3Pb_EP_de[3]->Draw("Psame");
		} else {
			gr_v3p_SP_de[3]->Draw("Psame");
			gr_v3Pb_SP_de[3]->Draw("Psame");
		}

		cT->cd(9);
		TLegend * legEPeta3 = new TLegend(0.05, 0.18, 0.5, 0.5);
		legEPeta3->SetFillColor(kWhite);
		legEPeta3->SetBorderSize(0);
		legEPeta3->SetTextFont(43);
		legEPeta3->SetTextSize(18);
		if ( bEP ) {
			legEPeta3->AddEntry(gr_v3p_EP[3], "v_{3}{EP, #eta_{C}=0} p-going EP", "p");
			legEPeta3->AddEntry(gr_v3Pb_EP[3], "v_{3}{EP, #eta_{C}=0} Pb-going EP", "p");
			legEPeta3->AddEntry(gr_v3p_EP_de[3], "v_{3}{EP, #eta_{C}=#eta_{POI}} p-going EP", "p");
			legEPeta3->AddEntry(gr_v3Pb_EP_de[3], "v_{3}{EP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
		} else {
			legEPeta3->AddEntry(gr_v3p_SP[3], "v_{3}{SP, #eta_{C}=0} p-going EP", "p");
			legEPeta3->AddEntry(gr_v3Pb_SP[3], "v_{3}{SP, #eta_{C}=0} Pb-going EP", "p");
			legEPeta3->AddEntry(gr_v3p_SP_de[3], "v_{3}{SP, #eta_{C}=#eta_{POI}} p-going EP", "p");
			legEPeta3->AddEntry(gr_v3Pb_SP_de[3], "v_{3}{SP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
		}
		legEPeta3->Draw();

		cT->cd(1);
		latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

		cT->cd(1);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{220 #leq N_{trk}^{offline} < 260}");
		cT->cd(5);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{260 #leq N_{trk}^{offline} < 300}");

		cT->SaveAs(Form("eta3all_%i_%i.pdf", s1, bEP));
	}
////////////////////////////////
//	if ( !bPbPb ) {
	if ( 1 ) {
		cT = MakeCanvas("cT_EPeta2", "cT_EPeta2", 2100, 900);
		makeMultiPanelCanvas(cT, 5, 2, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_EPeta2 = new TH2D("hframe_EPeta2", "", 1, -2.4, 2.4, 1, 0, 0.14);
		InitHist(hframe_EPeta2, "#eta", "v_{2}");

		cT->cd(1);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP[7]->Draw("Psame");
			gr_v2Pb_EP[7]->Draw("Psame");
		} else {
			gr_v2p_SP[7]->Draw("Psame");
			gr_v2Pb_SP[7]->Draw("Psame");
		}

		cT->cd(6);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP_de[7]->Draw("Psame");
			gr_v2Pb_EP_de[7]->Draw("Psame");
		} else {
			gr_v2p_SP_de[7]->Draw("Psame");
			gr_v2Pb_SP_de[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP[6]->Draw("Psame");
			gr_v2Pb_EP[6]->Draw("Psame");
		} else {
			gr_v2p_SP[6]->Draw("Psame");
			gr_v2Pb_SP[6]->Draw("Psame");
		}

		cT->cd(7);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP_de[6]->Draw("Psame");
			gr_v2Pb_EP_de[6]->Draw("Psame");
		} else {
			gr_v2p_SP_de[6]->Draw("Psame");
			gr_v2Pb_SP_de[6]->Draw("Psame");
		}

		cT->cd(3);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP[5]->Draw("Psame");
			gr_v2Pb_EP[5]->Draw("Psame");
		} else {
			gr_v2p_SP[5]->Draw("Psame");
			gr_v2Pb_SP[5]->Draw("Psame");
		}

		cT->cd(8);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP_de[5]->Draw("Psame");
			gr_v2Pb_EP_de[5]->Draw("Psame");
		} else {
			gr_v2p_SP_de[5]->Draw("Psame");
			gr_v2Pb_SP_de[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP[4]->Draw("Psame");
			gr_v2Pb_EP[4]->Draw("Psame");
		} else {
			gr_v2p_SP[4]->Draw("Psame");
			gr_v2Pb_SP[4]->Draw("Psame");
		}

		cT->cd(9);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP_de[4]->Draw("Psame");
			gr_v2Pb_EP_de[4]->Draw("Psame");
		} else {
			gr_v2p_SP_de[4]->Draw("Psame");
			gr_v2Pb_SP_de[4]->Draw("Psame");
		}

		cT->cd(5);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP[3]->Draw("Psame");
			gr_v2Pb_EP[3]->Draw("Psame");
		} else {
			gr_v2p_SP[3]->Draw("Psame");
			gr_v2Pb_SP[3]->Draw("Psame");
		}

		cT->cd(10);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			gr_v2p_EP_de[3]->Draw("Psame");
			gr_v2Pb_EP_de[3]->Draw("Psame");
		} else {
			gr_v2p_SP_de[3]->Draw("Psame");
			gr_v2Pb_SP_de[3]->Draw("Psame");
		}

		cT->cd(9);
		TLegend * legEPeta2 = new TLegend(0.05, 0.18, 0.5, 0.5);
		legEPeta2->SetFillColor(kWhite);
		legEPeta2->SetBorderSize(0);
		legEPeta2->SetTextFont(43);
		legEPeta2->SetTextSize(18);
		if ( bEP ) {
			legEPeta2->AddEntry(gr_v2p_EP[3], "v_{2}{EP, #eta_{C}=0} p-going EP", "p");
			legEPeta2->AddEntry(gr_v2Pb_EP[3], "v_{2}{EP, #eta_{C}=0} Pb-going EP", "p");
			legEPeta2->AddEntry(gr_v2p_EP_de[3], "v_{2}{EP, #eta_{C}=#eta_{POI}} p-going EP", "p");
			legEPeta2->AddEntry(gr_v2Pb_EP_de[3], "v_{2}{EP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
		} else {
			legEPeta2->AddEntry(gr_v2p_SP[3], "v_{2}{SP, #eta_{C}=0} p-going EP", "p");
			legEPeta2->AddEntry(gr_v2Pb_SP[3], "v_{2}{SP, #eta_{C}=0} Pb-going EP", "p");
			legEPeta2->AddEntry(gr_v2p_SP_de[3], "v_{2}{SP, #eta_{C}=#eta_{POI}} p-going EP", "p");
			legEPeta2->AddEntry(gr_v2Pb_SP_de[3], "v_{2}{SP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
		}
		legEPeta2->Draw();

		cT->cd(1);
		latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

		cT->cd(1);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{220 #leq N_{trk}^{offline} < 260}");
		cT->cd(5);
		latex.DrawLatexNDC(0.40, 0.15, "#bf{260 #leq N_{trk}^{offline} < 300}");

		cT->SaveAs(Form("eta2all_%i_%i.pdf", s1, bEP));
	}


}

