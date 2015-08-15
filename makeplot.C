// making plot

//void makeplot()
{
#include "label.h"
#include "noff.h"
#include "style.h"
#include "helper.h"
	int s1 = 109; // PbPb
//	int s1 = 139; // pPb
	int s2 = 1; // 1: C, 0:V

//	int bSys = 0;
	int bPbPb = 0;

	double sys_pt = 0;
	double sys_eta = 0;

	if ( s1 == 109 ) bPbPb = 1;


	TFile *f = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("sys.C");
	gROOT->Macro("LYZ.C");

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
	gr_vnPt_sys[2][2][3]->Draw("[]2");
//	gr_vnPt_sys[2][3][2]->Draw("[]2");
	gr_vnPt[2][2][3]->Draw("Psame");
	if (bPbPb) gr_vnPt[2][3][2]->Draw("Psame");

	TLegend * legPt1 = new TLegend(0.1, 0.8, 0.7, 0.95);
	legPt1->SetFillColor(kWhite);
	legPt1->SetBorderSize(0);
	legPt1->AddEntry(gr_HIN_13_002_PbPbv22pt5, "HIN-13-002 v_{2}{2}", "p");
	legPt1->AddEntry(gr_HIN_13_002_PbPbv24pt5, "HIN-13-002 v_{2}{4}", "p");

	TLegend * legPt2 = new TLegend(0.05, 0.75, 0.3, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
//	legPt2->AddEntry(gr_vnPt[2][0][4], "v_{2}{2}", "p");
//	legPt2->AddEntry(gr_vnPt[2][1][4], "v_{2}{4}", "p");
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

	cT->SaveAs(Form("pT_%i.pdf", s1));

	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.4, 2.4, 1, 0, 0.18);
	InitHist(hframe_eta, "#eta", "v_{2}");

	cT->cd(1);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[7]->Draw("Psame");
	else gr_LYZ_pPbEta[7]->Draw("Psame");
	gr_vnEta_sys[2][0][7]->Draw("[]2");
	gr_vnEta_sys[2][1][7]->Draw("[]2");
	gr_vnEta_sys[2][2][6]->Draw("[]2");
	gr_vnEta[2][0][7]->Draw("Psame");
	gr_vnEta[2][1][7]->Draw("Psame");
	gr_vnEta[2][2][6]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[6]->Draw("Psame");
	else gr_LYZ_pPbEta[6]->Draw("Psame");
	gr_vnEta_sys[2][0][6]->Draw("[]2");
	gr_vnEta_sys[2][1][6]->Draw("[]2");
	gr_vnEta_sys[2][2][5]->Draw("[]2");
	gr_vnEta[2][0][6]->Draw("Psame");
	gr_vnEta[2][1][6]->Draw("Psame");
	gr_vnEta[2][2][5]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[5]->Draw("Psame");
	else gr_LYZ_pPbEta[5]->Draw("Psame");
	gr_vnEta_sys[2][0][5]->Draw("[]2");
	gr_vnEta_sys[2][1][5]->Draw("[]2");
	gr_vnEta_sys[2][2][4]->Draw("[]2");
	gr_vnEta[2][0][5]->Draw("Psame");
	gr_vnEta[2][1][5]->Draw("Psame");
	gr_vnEta[2][2][4]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_eta->Draw();
	if ( bPbPb ) gr_LYZ_PbPbEta[4]->Draw("Psame");
	else gr_LYZ_pPbEta[4]->Draw("Psame");
	gr_vnEta_sys[2][0][4]->Draw("[]2");
	gr_vnEta_sys[2][1][4]->Draw("[]2");
	gr_vnEta_sys[2][2][3]->Draw("[]2");
	gr_vnEta[2][0][4]->Draw("Psame");
	gr_vnEta[2][1][4]->Draw("Psame");
	gr_vnEta[2][2][3]->Draw("Psame");
	if (bPbPb) gr_vnEta[2][3][2]->Draw("Psame");

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

	cT->cd(2);
//	legPt1->Draw();
	cT->cd(3);
	TLegend * legEta = new TLegend(0.05, 0.75, 0.3, 0.97);
	legEta->SetFillColor(kWhite);
	legEta->SetBorderSize(0);
	legEta->AddEntry(gr_vnEta[2][0][4], "v_{2}{2}", "p");
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

	cT->SaveAs(Form("eta_%i.pdf", s1));
///**************** 

	TH2D * hframe_ratio = new TH2D("hframe_ratio", "", 1, 0, 2.4, 1, 0.61, 1.29);
	InitHist(hframe_ratio, "#eta", "v_{2}^{#eta} / v_{2}^{-#eta}");

	TGraphErrors * gr_ratio[7][4][20];
	TLine *line = new TLine(0., 1., 2.4, 1.);
	line->SetLineStyle(kDashed);

	cT->cd(1);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][7] = makeRatio(gr_vnEta[2][0][7]);
	gr_ratio[2][1][7] = makeRatio(gr_vnEta[2][1][7]);
	gr_ratio[2][2][6] = makeRatio(gr_vnEta[2][2][6]);
	gr_ratio[2][3][5] = makeRatio(gr_vnEta[2][3][5]);

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
//	legRatio->AddEntry(gr_ratio[2][0][4], "v_{2}^{#eta}{2}/v_{2}^{-#eta}{2}", "p");
	legRatio->AddEntry(gr_ratio[2][1][4], "v_{2}^{#eta}{4}/v_{2}^{-#eta}{4}", "p");
	cT->cd(3);
	legRatio->Draw();

	cT->SaveAs(Form("ratio_%i.pdf", s1));
//*******/
	TFile *fsave = new TFile("fsave.root","recreate");
	gr_vnPt[2][0][7]->SetName("v2Pt_2_120");
	gr_vnPt[2][1][7]->SetName("v2Pt_4_120");
	gr_vnPt[2][2][6]->SetName("v2Pt_6_120");
	gr_vnPt[2][3][5]->SetName("v2Pt_8_120");

	gr_vnPt[2][0][6]->SetName("v2Pt_2_150");
	gr_vnPt[2][1][6]->SetName("v2Pt_4_150");
	gr_vnPt[2][2][5]->SetName("v2Pt_6_150");
	gr_vnPt[2][3][4]->SetName("v2Pt_8_150");

	gr_vnPt[2][0][5]->SetName("v2Pt_2_185");
	gr_vnPt[2][1][5]->SetName("v2Pt_4_185");
	gr_vnPt[2][2][4]->SetName("v2Pt_6_185");
	gr_vnPt[2][3][3]->SetName("v2Pt_8_185");

	gr_vnPt[2][0][4]->SetName("v2Pt_2_220");
	gr_vnPt[2][1][4]->SetName("v2Pt_4_220");
	gr_vnPt[2][2][3]->SetName("v2Pt_6_220");
	gr_vnPt[2][3][2]->SetName("v2Pt_8_220");

	gr_vnPt_sys[2][0][7]->SetName("v2Pt_sys_2_120");
	gr_vnPt_sys[2][1][7]->SetName("v2Pt_sys_4_120");
	gr_vnPt_sys[2][2][6]->SetName("v2Pt_sys_6_120");
	gr_vnPt_sys[2][3][5]->SetName("v2Pt_sys_8_120");

	gr_vnPt_sys[2][0][6]->SetName("v2Pt_sys_2_150");
	gr_vnPt_sys[2][1][6]->SetName("v2Pt_sys_4_150");
	gr_vnPt_sys[2][2][5]->SetName("v2Pt_sys_6_150");
	gr_vnPt_sys[2][3][4]->SetName("v2Pt_sys_8_150");

	gr_vnPt_sys[2][0][5]->SetName("v2Pt_sys_2_185");
	gr_vnPt_sys[2][1][5]->SetName("v2Pt_sys_4_185");
	gr_vnPt_sys[2][2][4]->SetName("v2Pt_sys_6_185");
	gr_vnPt_sys[2][3][3]->SetName("v2Pt_sys_8_185");

	gr_vnPt_sys[2][0][4]->SetName("v2Pt_sys_2_220");
	gr_vnPt_sys[2][1][4]->SetName("v2Pt_sys_4_220");
	gr_vnPt_sys[2][2][3]->SetName("v2Pt_sys_6_220");
	gr_vnPt_sys[2][3][2]->SetName("v2Pt_sys_8_220");


	gr_vnPt[2][0][7]->Write();
	gr_vnPt[2][1][7]->Write();
	gr_vnPt[2][2][6]->Write();
	gr_vnPt[2][3][5]->Write();

	gr_vnPt[2][0][6]->Write();
	gr_vnPt[2][1][6]->Write();
	gr_vnPt[2][2][5]->Write();
	gr_vnPt[2][3][4]->Write();

	gr_vnPt[2][0][5]->Write();
	gr_vnPt[2][1][5]->Write();
	gr_vnPt[2][2][4]->Write();
	gr_vnPt[2][3][3]->Write();

	gr_vnPt[2][0][4]->Write();
	gr_vnPt[2][1][4]->Write();
	gr_vnPt[2][2][3]->Write();
	gr_vnPt[2][3][2]->Write();

	gr_vnPt_sys[2][0][7]->Write();
	gr_vnPt_sys[2][1][7]->Write();
	gr_vnPt_sys[2][2][6]->Write();
	gr_vnPt_sys[2][3][5]->Write();

	gr_vnPt_sys[2][0][6]->Write();
	gr_vnPt_sys[2][1][6]->Write();
	gr_vnPt_sys[2][2][5]->Write();
	gr_vnPt_sys[2][3][4]->Write();

	gr_vnPt_sys[2][0][5]->Write();
	gr_vnPt_sys[2][1][5]->Write();
	gr_vnPt_sys[2][2][4]->Write();
	gr_vnPt_sys[2][3][3]->Write();

	gr_vnPt_sys[2][0][4]->Write();
	gr_vnPt_sys[2][1][4]->Write();
	gr_vnPt_sys[2][2][3]->Write();
	gr_vnPt_sys[2][3][2]->Write();

	gr_vnEta[2][0][7]->SetName("v2Eta_2_120");
	gr_vnEta[2][1][7]->SetName("v2Eta_4_120");
	gr_vnEta[2][2][6]->SetName("v2Eta_6_120");
	gr_vnEta[2][3][5]->SetName("v2Eta_8_120");

	gr_vnEta[2][0][6]->SetName("v2Eta_2_150");
	gr_vnEta[2][1][6]->SetName("v2Eta_4_150");
	gr_vnEta[2][2][5]->SetName("v2Eta_6_150");
	gr_vnEta[2][3][4]->SetName("v2Eta_8_150");

	gr_vnEta[2][0][5]->SetName("v2Eta_2_185");
	gr_vnEta[2][1][5]->SetName("v2Eta_4_185");
	gr_vnEta[2][2][4]->SetName("v2Eta_6_185");
	gr_vnEta[2][3][3]->SetName("v2Eta_8_185");

	gr_vnEta[2][0][4]->SetName("v2Eta_2_220");
	gr_vnEta[2][1][4]->SetName("v2Eta_4_220");
	gr_vnEta[2][2][3]->SetName("v2Eta_6_220");
	gr_vnEta[2][3][2]->SetName("v2Eta_8_220");

	gr_vnEta[2][0][7]->Write();
	gr_vnEta[2][1][7]->Write();
	gr_vnEta[2][2][6]->Write();
	gr_vnEta[2][3][5]->Write();

	gr_vnEta[2][0][6]->Write();
	gr_vnEta[2][1][6]->Write();
	gr_vnEta[2][2][5]->Write();
	gr_vnEta[2][3][4]->Write();

	gr_vnEta[2][0][5]->Write();
	gr_vnEta[2][1][5]->Write();
	gr_vnEta[2][2][4]->Write();
	gr_vnEta[2][3][3]->Write();

	gr_vnEta[2][0][4]->Write();
	gr_vnEta[2][1][4]->Write();
	gr_vnEta[2][2][3]->Write();
	gr_vnEta[2][3][2]->Write();



	gr_vnEta_sys[2][0][7]->SetName("v2Eta_sys_2_120");
	gr_vnEta_sys[2][1][7]->SetName("v2Eta_sys_4_120");
	gr_vnEta_sys[2][2][6]->SetName("v2Eta_sys_6_120");
	gr_vnEta_sys[2][3][5]->SetName("v2Eta_sys_8_120");

	gr_vnEta_sys[2][0][6]->SetName("v2Eta_sys_2_150");
	gr_vnEta_sys[2][1][6]->SetName("v2Eta_sys_4_150");
	gr_vnEta_sys[2][2][5]->SetName("v2Eta_sys_6_150");
	gr_vnEta_sys[2][3][4]->SetName("v2Eta_sys_8_150");

	gr_vnEta_sys[2][0][5]->SetName("v2Eta_sys_2_185");
	gr_vnEta_sys[2][1][5]->SetName("v2Eta_sys_4_185");
	gr_vnEta_sys[2][2][4]->SetName("v2Eta_sys_6_185");
	gr_vnEta_sys[2][3][3]->SetName("v2Eta_sys_8_185");

	gr_vnEta_sys[2][0][4]->SetName("v2Eta_sys_2_220");
	gr_vnEta_sys[2][1][4]->SetName("v2Eta_sys_4_220");
	gr_vnEta_sys[2][2][3]->SetName("v2Eta_sys_6_220");
	gr_vnEta_sys[2][3][2]->SetName("v2Eta_sys_8_220");

	gr_vnEta_sys[2][0][7]->Write();
	gr_vnEta_sys[2][1][7]->Write();
	gr_vnEta_sys[2][2][6]->Write();
	gr_vnEta_sys[2][3][5]->Write();

	gr_vnEta_sys[2][0][6]->Write();
	gr_vnEta_sys[2][1][6]->Write();
	gr_vnEta_sys[2][2][5]->Write();
	gr_vnEta_sys[2][3][4]->Write();

	gr_vnEta_sys[2][0][5]->Write();
	gr_vnEta_sys[2][1][5]->Write();
	gr_vnEta_sys[2][2][4]->Write();
	gr_vnEta_sys[2][3][3]->Write();

	gr_vnEta_sys[2][0][4]->Write();
	gr_vnEta_sys[2][1][4]->Write();
	gr_vnEta_sys[2][2][3]->Write();
	gr_vnEta_sys[2][3][2]->Write();

	gr_ratio[2][0][7]->SetName("v2EtaRatio_2_120");
	gr_ratio[2][1][7]->SetName("v2EtaRatio_4_120");
	gr_ratio[2][2][6]->SetName("v2EtaRatio_6_120");
	gr_ratio[2][3][5]->SetName("v2EtaRatio_8_120");

	gr_ratio[2][0][6]->SetName("v2EtaRatio_2_150");
	gr_ratio[2][1][6]->SetName("v2EtaRatio_4_150");
	gr_ratio[2][2][5]->SetName("v2EtaRatio_6_150");
	gr_ratio[2][3][4]->SetName("v2EtaRatio_8_150");

	gr_ratio[2][0][5]->SetName("v2EtaRatio_2_185");
	gr_ratio[2][1][5]->SetName("v2EtaRatio_4_185");
	gr_ratio[2][2][4]->SetName("v2EtaRatio_6_185");
	gr_ratio[2][3][3]->SetName("v2EtaRatio_8_185");

	gr_ratio[2][0][4]->SetName("v2EtaRatio_2_220");
	gr_ratio[2][1][4]->SetName("v2EtaRatio_4_220");
	gr_ratio[2][2][3]->SetName("v2EtaRatio_6_220");
	gr_ratio[2][3][2]->SetName("v2EtaRatio_8_220");

	gr_ratio[2][0][7]->Write();
	gr_ratio[2][1][7]->Write();
	gr_ratio[2][2][6]->Write();
	gr_ratio[2][3][5]->Write();

	gr_ratio[2][0][6]->Write();
	gr_ratio[2][1][6]->Write();
	gr_ratio[2][2][5]->Write();
	gr_ratio[2][3][4]->Write();

	gr_ratio[2][0][5]->Write();
	gr_ratio[2][1][5]->Write();
	gr_ratio[2][2][4]->Write();
	gr_ratio[2][3][3]->Write();

	gr_ratio[2][0][4]->Write();
	gr_ratio[2][1][4]->Write();
	gr_ratio[2][2][3]->Write();
	gr_ratio[2][3][2]->Write();

}

