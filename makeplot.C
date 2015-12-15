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

	int bPbPb = 0;

	int bEP = 1;

	int bEtaRebin = 1;

	double sys_pt = 0;
	double sys_eta = 0;
	double sys_EP_pt = 0;
	double sys_EP_eta = 0;
	double sys_EP3_eta = 0;

	if ( s1 == 109 ) bPbPb = 1;

	TFile * fsave = new TFile(Form("eta3_%i_%i.root", s1, bEP), "recreate");

	TFile *f = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("sys.C");
	gROOT->Macro("LYZ.C");
	gROOT->Macro("EP.C");

	if (bPbPb) {
		sys_pt = sys_pt_PbPb;
		sys_eta = sys_eta_PbPb;

		sys_EP_pt = sys_EP_pt_PbPb;
		sys_EP_eta = sys_EP_eta_PbPb;

		sys_EP3_eta = sys_EP3_eta_PbPb;
	} else {
		sys_pt = sys_pt_pPb;
		sys_eta = sys_eta_pPb;

		sys_EP_pt = sys_EP_pt_pPb;
		sys_EP_eta = sys_EP_eta_pPb;

		sys_EP3_eta = sys_EP3_eta_pPb;
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
//				gr_vnPt_sys[n][np][c] = makeSys(gr_vnPt[n][np][c], sys_pt);
//				if ( gr_vnPt_sys[n][np][c] ) {
//					for ( int i = 0; i < gr_vnPt_sys[n][np][c]->GetN(); i++ ) {
//						gr_vnPt_sys[n][np][c]->GetEX()[i] = 0.15;
//					}
//				}
//				gr_vnEta_sys[n][np][c] = makeSys(gr_vnEta[n][np][c], sys_eta);
//				if ( gr_vnEta_sys[n][np][c] ) {
//					for ( int i = 0; i < gr_vnEta_sys[n][np][c]->GetN(); i++ ) {
//						gr_vnEta_sys[n][np][c]->GetEX()[i] = 0.2;
//					}
//				}
////				if ( np == 0 || np ==3 ) {
////					if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(1001);
////					if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(1001);
////				}
////				if ( np == 1 ) {
////					if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(1002);
////					if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(1002);
////				}
////				if ( np == 2 ) {
////					if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(1003);
////					if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(1003);
////				}
//				if ( gr_vnPt_sys[n][np][c] ) gr_vnPt_sys[n][np][c]->SetFillColor(kGray);
//				if ( gr_vnEta_sys[n][np][c] ) gr_vnEta_sys[n][np][c]->SetFillColor(kGray);
				trimGrPT(gr_vnPt[n][np][c]);
//				trimGrPT(gr_vnPt_sys[n][np][c]);
			}
		}
	}

	// fix 8-part marker size
	for ( int i = 2; i < 8; i++ ) {
		gr_vnPt[2][3][i]->SetMarkerSize(3);
		gr_vnEta[2][3][i]->SetMarkerSize(3);
	}

	TGraphErrors* gr_sys_l = new TGraphErrors();
	gr_sys_l->SetFillColor(kGray);
	gr_sys_l->SetLineColor(kGray);
//	gr_sys_l->SetLineColor(kBlack);

	SetStyle();
	TCanvas * cT = MakeCanvas("cT", "cT", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, .1, 5.9, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");
	hframe_pt->SetTitleOffset(1.2);

	TGraphErrors * gr_EP_sys[20] = {};
	TGraphErrors * gr_EP1_sys[20] = {};

	cT->cd(1);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][7]->Draw();
	else mgr_HIN13002_pPbPt[2][0][7]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][7]->Draw();
	else mgr_HIN13002_pPbPt[2][1][7]->Draw();
//	gr_vnPt[2][0][7]->Draw("Psame");
//	gr_vnPt[2][1][7]->Draw("Psame");

	if ( bPbPb ) {
		mgr_LYZ_PbPbPt[7]->Draw();
	} else {
		mgr_LYZ_pPbPt[7]->Draw();
	}

	TGraphErrors* gr_sys = 0;
	if ( bEP ) {
		gr_EP_sys[7] = DrawSys(gr_v2pt_m_EPde_Pb[7], sys_EP_pt);
		gr_v2pt_m_EPde_Pb[7]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[7] = DrawSys(gr_v2pt_m_EPde_p[7], sys_EP_pt);
			gr_v2pt_m_EPde_p[7]->Draw("Psame");
		}
	} else {
		gr_EP_sys[7] = DrawSys(gr_v2pt_m_SPde_Pb[7], sys_EP_pt);
		gr_v2pt_m_SPde_Pb[7]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[7] = DrawSys(gr_v2pt_m_SPde_p[7], sys_EP_pt);
			gr_v2pt_m_SPde_p[7]->Draw("Psame");
		}
	}

	if (!bPbPb) gr_vnPt[2][3][5]->RemovePoint(7);
	if (!bPbPb) gr_vnPt[2][3][5]->RemovePoint(7);

	gr_vnPt_sys[2][2][6] = DrawSys(gr_vnPt[2][2][6], sys_pt);
	gr_vnPt_sys[2][3][5] = DrawSys(gr_vnPt[2][3][5], sys_pt);
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

	if ( bPbPb ) mgr_LYZ_PbPbPt[6]->Draw();
	else mgr_LYZ_pPbPt[6]->Draw();

	if ( bEP ) {
		gr_EP_sys[6] = DrawSys(gr_v2pt_m_EPde_Pb[6], sys_EP_pt);
		gr_v2pt_m_EPde_Pb[6]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[6] = DrawSys(gr_v2pt_m_EPde_p[6], sys_EP_pt);
			gr_v2pt_m_EPde_p[6]->Draw("Psame");
		}
	} else {
		gr_EP_sys[6] = DrawSys(gr_v2pt_m_SPde_Pb[6], sys_EP_pt);
		gr_v2pt_m_SPde_Pb[6]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[6] = DrawSys(gr_v2pt_m_SPde_p[6], sys_EP_pt);
			gr_v2pt_m_SPde_p[6]->Draw("Psame");
		}
	}

	gr_vnPt_sys[2][2][5] = DrawSys(gr_vnPt[2][2][5], sys_pt);
	gr_vnPt_sys[2][3][4] = DrawSys(gr_vnPt[2][3][4], sys_pt);
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

	if ( bPbPb ) mgr_LYZ_PbPbPt[5]->Draw();
	else mgr_LYZ_pPbPt[5]->Draw();

	if ( bEP ) {
		gr_EP_sys[5] = DrawSys(gr_v2pt_m_EPde_Pb[5], sys_EP_pt);
		gr_v2pt_m_EPde_Pb[5]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[5] = DrawSys(gr_v2pt_m_EPde_p[5], sys_EP_pt);
			gr_v2pt_m_EPde_p[5]->Draw("Psame");
		}
	} else {
		gr_EP_sys[5] = DrawSys(gr_v2pt_m_SPde_Pb[5], sys_EP_pt);
		gr_v2pt_m_SPde_Pb[5]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[5] = DrawSys(gr_v2pt_m_SPde_p[5], sys_EP_pt);
			gr_v2pt_m_SPde_p[5]->Draw("Psame");
		}
	}

	gr_vnPt_sys[2][2][4] = DrawSys(gr_vnPt[2][2][4], sys_pt);
	gr_vnPt_sys[2][3][3] = DrawSys(gr_vnPt[2][3][3], sys_pt);
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

	if ( bPbPb ) mgr_LYZ_PbPbPt[4]->Draw();
	else mgr_LYZ_pPbPt[4]->Draw();

	if ( bEP ) {
		gr_EP_sys[4] = DrawSys(gr_v2pt_m_EPde_Pb[4], sys_EP_pt);
		gr_v2pt_m_EPde_Pb[4]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[4] = DrawSys(gr_v2pt_m_EPde_p[4], sys_EP_pt);
			gr_v2pt_m_EPde_p[4]->Draw("Psame");
		}
	} else {
		gr_EP_sys[4] = DrawSys(gr_v2pt_m_SPde_Pb[4], sys_EP_pt);
		gr_v2pt_m_SPde_Pb[4]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[4] = DrawSys(gr_v2pt_m_SPde_p[4], sys_EP_pt);
			gr_v2pt_m_SPde_p[4]->Draw("Psame");
		}
	}


	gr_vnPt_sys[2][2][3] = DrawSys(gr_vnPt[2][2][3], sys_pt);
	gr_vnPt[2][2][3]->Draw("Psame");
	if (bPbPb) {
	//	gr_vnPt_sys[2][3][2]->Draw("Psame");
		gr_vnPt_sys[2][3][2] = DrawSys(gr_vnPt[2][3][2], sys_pt);
		gr_vnPt[2][3][2]->Draw("Psame");
	}

	TLegend * legPt1 = new TLegend(0.05, 0.7, 0.7, 0.95);
	TLegendEntry * legPt1e[10] = {};
	legPt1->SetFillColor(kWhite);
	legPt1->SetBorderSize(0);
	legPt1->SetTextFont(43);
	legPt1->SetTextSize(24);
	legPt1e[0] = legPt1->AddEntry(gr_HIN_13_002_PbPbv22pt5, "v_{2}{2,|#Delta#eta|>2} |#eta|<2.4", "p");
	legPt1e[1] = legPt1->AddEntry(gr_HIN_13_002_PbPbv24pt5, "v_{2}{4} |#eta|<2.4", "p");

	TLegend * legPt2 = new TLegend(0.05, 0.7, 0.6, 0.97);
	TLegendEntry * legPt2e[10] = {};
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->SetTextFont(43);
	legPt2->SetTextSize(24);
//	legPt2->AddEntry(gr_vnPt[2][0][4], "v_{2}{2}", "p");
//	legPt2->AddEntry(gr_vnPt[2][1][4], "v_{2}{4}", "p");
	if (bPbPb) {
		if ( bEP ) legPt1e[2] = legPt1->AddEntry(gr_v2pt_m_EPde_Pb[4], "v_{2}{EP} |#eta|<0.8", "p");
		else legPt1e[2] = legPt1->AddEntry(gr_v2pt_m_SPde_Pb[4], "v_{2}{SP} |#eta|<0.8", "p");
		legPt1->AddEntry((TObject*)0, "", "");
	} else {
		if ( bEP ) {
			legPt1e[3] = legPt1->AddEntry(gr_v2pt_m_EPde_p[4], "v_{2}{EP} |#eta|<0.8 p-going EP", "p");
			legPt1e[2] = legPt1->AddEntry(gr_v2pt_m_EPde_Pb[4], "v_{2}{EP} |#eta|<0.8 Pb-going EP", "p");
		} else {
			legPt1e[3] = legPt1->AddEntry(gr_v2pt_m_SPde_p[4], "v_{2}{SP} |#eta|<0.8 p-going EP", "p");
			legPt1e[2] = legPt1->AddEntry(gr_v2pt_m_SPde_Pb[4], "v_{2}{SP} |#eta|<0.8 Pb-going EP", "p");
		}
	}
	legPt2e[0] = legPt2->AddEntry(gr_vnPt[2][2][4], "v_{2}{6} |#eta|<2.4", "p");
	legPt2e[1] = legPt2->AddEntry(gr_vnPt[2][3][4], "v_{2}{8} |#eta|<2.4", "p");
	legPt2e[2] = legPt2->AddEntry(gr_LYZ_pPbPt[4], "v_{2}{LYZ} |#eta|<2.4", "p");

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(28);
	latex.SetTextAlign(13);

	TLatex latex28;
	latex28.SetTextFont(43);
	latex28.SetTextSize(28);
	latex28.SetTextAlign(13);


	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
	else latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");

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

	TLegend * legPtSys = new TLegend(0.05, 0.9, 0.6, 0.95);
	legPtSys->SetFillColor(kWhite);
	legPtSys->SetBorderSize(0);
	legPtSys->SetTextFont(43);
	legPtSys->SetTextSize(24);
	legPtSys->AddEntry(gr_sys_l, "Systematic uncertainties", "f");
	legPtSys->Draw();

	cT->SaveAs(Form("pT_%i_%i.pdf", s1, bEP));
	cT->SaveAs(Form("pT_%i_%i_C.C", s1, bEP));

/////////////// QM
if ( 0 ) {
	TCanvas * cTQM = MakeCanvas("cTQM", "cTQM", 900, 500);
	makeMultiPanelCanvas(cTQM, 2, 1, 0.0, 0., 0.15, 0.15, 0.01);

	cTQM->cd(1);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][5]->Draw();
	else mgr_HIN13002_pPbPt[2][0][5]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][5]->Draw();
	else mgr_HIN13002_pPbPt[2][1][5]->Draw();

	if ( bPbPb ) mgr_LYZ_PbPbPt[5]->Draw();
	else mgr_LYZ_pPbPt[5]->Draw();

	if ( bEP ) {
		gr_EP_sys[5] = DrawSys(gr_v2pt_m_EPde_Pb[5], sys_EP_pt);
		gr_v2pt_m_EPde_Pb[5]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[5] = DrawSys(gr_v2pt_m_EPde_p[5], sys_EP_pt);
			gr_v2pt_m_EPde_p[5]->Draw("Psame");
		}
	} else {
		gr_EP_sys[5] = DrawSys(gr_v2pt_m_SPde_Pb[5], sys_EP_pt);
		gr_v2pt_m_SPde_Pb[5]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[5] = DrawSys(gr_v2pt_m_SPde_p[5], sys_EP_pt);
			gr_v2pt_m_SPde_p[5]->Draw("Psame");
		}
	}

	gr_vnPt_sys[2][2][4] = DrawSys(gr_vnPt[2][2][4], sys_pt);
	gr_vnPt_sys[2][3][3] = DrawSys(gr_vnPt[2][3][3], sys_pt);
	gr_vnPt[2][2][4]->Draw("Psame");
	gr_vnPt[2][3][3]->Draw("Psame");

	cTQM->cd(2);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][4]->Draw();
	else mgr_HIN13002_pPbPt[2][0][4]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][4]->Draw();
	else mgr_HIN13002_pPbPt[2][1][4]->Draw();

	if ( bPbPb ) mgr_LYZ_PbPbPt[4]->Draw();
	else mgr_LYZ_pPbPt[4]->Draw();

	if ( bEP ) {
		gr_EP_sys[4] = DrawSys(gr_v2pt_m_EPde_Pb[4], sys_EP_pt);
		gr_v2pt_m_EPde_Pb[4]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[4] = DrawSys(gr_v2pt_m_EPde_p[4], sys_EP_pt);
			gr_v2pt_m_EPde_p[4]->Draw("Psame");
		}
	} else {
		gr_EP_sys[4] = DrawSys(gr_v2pt_m_SPde_Pb[4], sys_EP_pt);
		gr_v2pt_m_SPde_Pb[4]->Draw("Psame");
		if (!bPbPb) {
			gr_EP1_sys[4] = DrawSys(gr_v2pt_m_SPde_p[4], sys_EP_pt);
			gr_v2pt_m_SPde_p[4]->Draw("Psame");
		}
	}


	gr_vnPt_sys[2][2][3] = DrawSys(gr_vnPt[2][2][3], sys_pt);
	gr_vnPt[2][2][3]->Draw("Psame");
	if (bPbPb) {
		gr_vnPt_sys[2][3][2] = DrawSys(gr_vnPt[2][3][2], sys_pt);
		gr_vnPt[2][3][2]->Draw("Psame");
	}

	legPt1->SetX1NDC(0.18);
	cTQM->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	legPt1->Draw();
	cTQM->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");
	legPt2->Draw();
	if (bPbPb) latex.DrawLatexNDC(0.60, 0.94, "#splitline{#bf{CMS PbPb}}{Preliminary}");
	else latex.DrawLatexNDC(0.60, 0.94, "#splitline{#bf{CMS pPb}}{Preliminary}");

	cTQM->SaveAs(Form("pTQM_%i_%i.pdf", s1, bEP));

}

/////////////Anime
	if ( 0 ) {
		for ( int i = 3; i < 8; i++ ) {
			gr_LYZ_sys_pPbPt[i]->Delete();
			gr_LYZ_pPbPt[i]->Delete();
			gr_LYZ_sys_PbPbPt[i]->Delete();
			gr_LYZ_PbPbPt[i]->Delete();
		}
		legPt2e[2]->SetLabel();
		legPt2e[2]->SetOption("");
		cT->SaveAs(Form("pT0_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("pTQM0_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 20; i++ ) {
			if ( gr_vnPt_sys[2][3][i] ) gr_vnPt_sys[2][3][i]->Delete();
			if ( gr_vnPt[2][3][i] ) gr_vnPt[2][3][i]->Delete();
		}
		legPt2e[1]->SetLabel();
		legPt2e[1]->SetOption("");
		cT->SaveAs(Form("pT1_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("pTQM1_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 20; i++ ) {
			if ( gr_vnPt_sys[2][2][i] ) gr_vnPt_sys[2][2][i]->Delete();
			if ( gr_vnPt[2][2][i] ) gr_vnPt[2][2][i]->Delete();
		}
		legPt2e[0]->SetLabel();
		legPt2e[0]->SetOption("");
		cT->SaveAs(Form("pT2_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("pTQM2_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 20; i++ ) {
			if ( gr_EP_sys[i] ) gr_EP_sys[i]->Delete();
			if ( gr_EP1_sys[i] ) gr_EP1_sys[i]->Delete();
			if ( gr_v2pt_m_EPde_Pb[i] ) gr_v2pt_m_EPde_Pb[i]->Delete();
			if ( gr_v2pt_m_EPde_p[i] ) gr_v2pt_m_EPde_p[i]->Delete();
			if ( gr_v2pt_m_SPde_Pb[i] ) gr_v2pt_m_SPde_Pb[i]->Delete();
			if ( gr_v2pt_m_SPde_p[i] ) gr_v2pt_m_SPde_p[i]->Delete();
		}
		if (legPt1e[2]) {
			legPt1e[2]->SetLabel();
			legPt1e[2]->SetOption("");
		}
		if (legPt1e[3]) {
			legPt1e[3]->SetLabel();
			legPt1e[3]->SetOption("");
		}
		cT->SaveAs(Form("pT3_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("pTQM3_%i_%i.pdf", s1, bEP));
	}


///////////////////////////////////////
	cT = MakeCanvas("cTeta", "cTeta", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.4, 2.4, 1, 0, 0.16);
	InitHist(hframe_eta, "#eta", "v_{2}");
	hframe_eta->SetTitleOffset(1.2);

	TGraphErrors* gr_EP_eta[20] = {};
	TGraphErrors* gr_EP_eta_de[20] = {};
	TGraphErrors* gr_EP_eta_sys[20] = {};
	TGraphErrors* gr_EP_eta_de_sys[20] = {};

	for ( int i = 3; i < 8; i++ ) {
		if ( bEP ) {
			gr_EP_eta[i] = merge_EP_longrange(gr_v2p_EP[i], gr_v2Pb_EP[i], kOpenCircle, kRed);
		} else {
			gr_EP_eta[i] = merge_EP_longrange(gr_v2p_SP[i], gr_v2Pb_SP[i], kOpenCircle, kRed);
		}
		if ( bEP ) {
			gr_EP_eta_de[i] = merge_EP_longrange(gr_v2p_EP_de[i], gr_v2Pb_EP_de[i], kFullCircle, kBlue);
		} else {
			gr_EP_eta_de[i] = merge_EP_longrange(gr_v2p_SP_de[i], gr_v2Pb_SP_de[i], kFullCircle, kBlue);
		}
	}

	cT->cd(1);
	hframe_eta->Draw();
	if ( bPbPb ) mgr_LYZ_PbPbEta[7]->Draw();
	else mgr_LYZ_pPbEta[7]->Draw();

	gr_EP_eta_sys[7] = DrawSys(gr_EP_eta[7], sys_EP_eta);;
	gr_EP_eta_de_sys[7] = DrawSys(gr_EP_eta_de[7], sys_EP_eta);

	gr_EP_eta[7]->Draw("Psame");
	gr_EP_eta_de[7]->Draw("Psame");

	if ( bEtaRebin ) {
		gr_vnEta[2][1][7] = rebin_eta(gr_vnEta[2][1][7]);
		gr_vnEta[2][2][6] = rebin_eta(gr_vnEta[2][2][6]);
		gr_vnEta[2][3][5] = rebin_eta(gr_vnEta[2][3][5]);
		gr_vnEta[2][3][5]->SetMarkerSize(3);
	}

	gr_vnEta_sys[2][1][7] = DrawSys(gr_vnEta[2][1][7], sys_eta);
	gr_vnEta_sys[2][2][6] = DrawSys(gr_vnEta[2][2][6], sys_eta);
	if (bPbPb) {
		gr_vnEta_sys[2][3][5] = DrawSys(gr_vnEta[2][3][5], sys_eta);
	}
	gr_vnEta[2][1][7]->Draw("Psame");
	gr_vnEta[2][2][6]->Draw("Psame");
	if (bPbPb) {
		gr_vnEta[2][3][5]->Draw("Psame");
	}

	cT->cd(2);
	hframe_eta->Draw();
	if ( bPbPb ) mgr_LYZ_PbPbEta[6]->Draw();
	else mgr_LYZ_pPbEta[6]->Draw();

	gr_EP_eta_sys[6] = DrawSys(gr_EP_eta[6], sys_EP_eta);;
	gr_EP_eta_de_sys[6] = DrawSys(gr_EP_eta_de[6], sys_EP_eta);

	gr_EP_eta[6]->Draw("Psame");
	gr_EP_eta_de[6]->Draw("Psame");

	if ( bEtaRebin ) {
		gr_vnEta[2][1][6] = rebin_eta(gr_vnEta[2][1][6]);
		gr_vnEta[2][2][5] = rebin_eta(gr_vnEta[2][2][5]);
		gr_vnEta[2][3][4] = rebin_eta(gr_vnEta[2][3][4]);
		gr_vnEta[2][3][4]->SetMarkerSize(3);
	}

	gr_vnEta_sys[2][1][6] = DrawSys(gr_vnEta[2][1][6], sys_eta);
	gr_vnEta_sys[2][2][5] = DrawSys(gr_vnEta[2][2][5], sys_eta);
	if (bPbPb) {
		gr_vnEta_sys[2][3][4] = DrawSys(gr_vnEta[2][3][4], sys_eta);
	}
	gr_vnEta[2][1][6]->Draw("Psame");
	gr_vnEta[2][2][5]->Draw("Psame");
	if (bPbPb) {
		gr_vnEta[2][3][4]->Draw("Psame");
	}

	cT->cd(3);
	hframe_eta->Draw();
	if ( bPbPb ) mgr_LYZ_PbPbEta[5]->Draw();
	else mgr_LYZ_pPbEta[5]->Draw();

	gr_EP_eta_sys[5] = DrawSys(gr_EP_eta[5], sys_EP_eta);;

	gr_EP_eta_de_sys[5] = DrawSys(gr_EP_eta_de[5], sys_EP_eta);

	gr_EP_eta[5]->Draw("Psame");
	gr_EP_eta_de[5]->Draw("Psame");

	if ( bEtaRebin ) {
		gr_vnEta[2][1][5] = rebin_eta(gr_vnEta[2][1][5]);
		gr_vnEta[2][2][4] = rebin_eta(gr_vnEta[2][2][4]);
		gr_vnEta[2][3][3] = rebin_eta(gr_vnEta[2][3][3]);
		gr_vnEta[2][3][3]->SetMarkerSize(3);
	}

	gr_vnEta_sys[2][1][5] = DrawSys(gr_vnEta[2][1][5], sys_eta);
	gr_vnEta_sys[2][2][4] = DrawSys(gr_vnEta[2][2][4], sys_eta);
	if (bPbPb) {
		gr_vnEta_sys[2][3][3] = DrawSys(gr_vnEta[2][3][3], sys_eta);
	}
	gr_vnEta[2][1][5]->Draw("Psame");
	gr_vnEta[2][2][4]->Draw("Psame");
	if (bPbPb) {
		gr_vnEta[2][3][3]->Draw("Psame");
	}


	cT->cd(4);
	hframe_eta->Draw();
	if ( bPbPb ) mgr_LYZ_PbPbEta[4]->Draw();
	else mgr_LYZ_pPbEta[4]->Draw();

	gr_EP_eta_sys[4] = DrawSys(gr_EP_eta[4], sys_EP_eta);;
	gr_EP_eta_de_sys[4] = DrawSys(gr_EP_eta_de[4], sys_EP_eta);

	gr_EP_eta[4]->Draw("Psame");
	gr_EP_eta_de[4]->Draw("Psame");

	if ( bEtaRebin ) {
		gr_vnEta[2][1][4] = rebin_eta(gr_vnEta[2][1][4]);
		gr_vnEta[2][2][3] = rebin_eta(gr_vnEta[2][2][3]);
		gr_vnEta[2][3][2] = rebin_eta(gr_vnEta[2][3][2]);
		gr_vnEta[2][3][2]->SetMarkerSize(3);
	}

	gr_vnEta_sys[2][1][4] = DrawSys(gr_vnEta[2][1][4], sys_eta);
	gr_vnEta_sys[2][2][3] = DrawSys(gr_vnEta[2][2][3], sys_eta);
	if (bPbPb) {
		gr_vnEta_sys[2][3][2] = DrawSys(gr_vnEta[2][3][2], sys_eta);
	}
	gr_vnEta[2][1][4]->Draw("Psame");
	gr_vnEta[2][2][3]->Draw("Psame");
	if (bPbPb) {
		gr_vnEta[2][3][2]->Draw("Psame");
	}

	cT->cd(1);
	if (bPbPb) latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
	else latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");

	cT->cd(2);
	TLegend * legEtaEP = new TLegend(0.05, 0.78, 0.3, 0.97);
	TLegendEntry * legEtaEPe[10] = {};
	legEtaEP->SetFillColor(kWhite);
	legEtaEP->SetBorderSize(0);
	legEtaEP->SetTextFont(43);
	legEtaEP->SetTextSize(24);
	if ( bEP ) {
		legEtaEPe[0] = legEtaEP->AddEntry(gr_EP_eta[4], "v_{2}{EP, #eta_{C}=0}", "p");
		legEtaEPe[1] = legEtaEP->AddEntry(gr_EP_eta_de[4], "v_{2}{EP, #eta_{C}=#eta_{POI}}", "p");
	} else {
		legEtaEPe[0] = legEtaEP->AddEntry(gr_EP_eta[4], "v_{2}{SP, #eta_{C}=0}", "p");
		legEtaEPe[1] = legEtaEP->AddEntry(gr_EP_eta_de[4], "v_{2}{SP, #eta_{C}=#eta_{POI}}", "p");
	}
	legEtaEP->Draw();


	cT->cd(3);
	TLegend * legEta = new TLegend(0.05, 0.7, 0.3, 0.97);
	TLegendEntry * legEtae[10] = {};
	legEta->SetFillColor(kWhite);
	legEta->SetBorderSize(0);
	legEta->SetTextFont(43);
	legEta->SetTextSize(24);
	legEtae[0] = legEta->AddEntry(gr_vnEta[2][1][4], "v_{2}{4}", "p");
	legEtae[1] = legEta->AddEntry(gr_vnEta[2][2][4], "v_{2}{6}", "p");
	if (bPbPb) legEtae[2] = legEta->AddEntry(gr_vnEta[2][3][4], "v_{2}{8}", "p");
	legEtae[3] = legEta->AddEntry(gr_LYZ_pPbEta[4], "v_{2}{LYZ}", "p");
	if (!bPbPb) legEta->AddEntry((TObject*)0, "", "");
	legEta->Draw();

	cT->cd(4);
	latex28.DrawLatexNDC(0.20, 0.85, "0.3 < p_{T} < 3.0 GeV/c");

	cT->cd(1);
	latex28.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex28.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex28.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex28.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	legPtSys->Draw();


	cT->SaveAs(Form("eta_%i_%i.pdf", s1, bEP));
	cT->SaveAs(Form("eta_%i_%i_C.C", s1, bEP));

//////////////////////// QM
if ( 0 ) {
	TCanvas * cTQM = MakeCanvas("cTetaQM", "cTetaQM", 900, 500);
	makeMultiPanelCanvas(cTQM, 2, 1, 0.0, 0., 0.15, 0.15, 0.01);

	cTQM->cd(1);
	hframe_eta->Draw();
	if ( bPbPb ) mgr_LYZ_PbPbEta[5]->Draw();
	else mgr_LYZ_pPbEta[5]->Draw();

	gr_EP_eta_sys[5] = DrawSys(gr_EP_eta[5], sys_EP_eta);;

	gr_EP_eta_de_sys[5] = DrawSys(gr_EP_eta_de[5], sys_EP_eta);

	gr_EP_eta[5]->Draw("Psame");
	gr_EP_eta_de[5]->Draw("Psame");

	gr_vnEta_sys[2][1][5] = DrawSys(gr_vnEta[2][1][5], sys_eta);
	gr_vnEta_sys[2][2][4] = DrawSys(gr_vnEta[2][2][4], sys_eta);
	if (bPbPb) {
		gr_vnEta_sys[2][3][3] = DrawSys(gr_vnEta[2][3][3], sys_eta);
	}
	gr_vnEta[2][1][5]->Draw("Psame");
	gr_vnEta[2][2][4]->Draw("Psame");
	if (bPbPb) {
		gr_vnEta[2][3][3]->Draw("Psame");
	}

	cTQM->cd(2);
	hframe_eta->Draw();
	if ( bPbPb ) mgr_LYZ_PbPbEta[4]->Draw();
	else mgr_LYZ_pPbEta[4]->Draw();

	gr_EP_eta_sys[4] = DrawSys(gr_EP_eta[4], sys_EP_eta);;
	gr_EP_eta_de_sys[4] = DrawSys(gr_EP_eta_de[4], sys_EP_eta);

	gr_EP_eta[4]->Draw("Psame");
	gr_EP_eta_de[4]->Draw("Psame");

	gr_vnEta_sys[2][1][4] = DrawSys(gr_vnEta[2][1][4], sys_eta);
	gr_vnEta_sys[2][2][3] = DrawSys(gr_vnEta[2][2][3], sys_eta);
	if (bPbPb) {
		gr_vnEta_sys[2][3][2] = DrawSys(gr_vnEta[2][3][2], sys_eta);
	}
	gr_vnEta[2][1][4]->Draw("Psame");
	gr_vnEta[2][2][3]->Draw("Psame");
	if (bPbPb) {
		gr_vnEta[2][3][2]->Draw("Psame");
	}

	cTQM->cd(1);
	legEtaEP->SetX1NDC(0.2);
	legEtaEP->SetX2NDC(0.6);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	legEtaEP->Draw();
	cTQM->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");
	legEta->Draw();
	if (bPbPb) latex.DrawLatexNDC(0.60, 0.94, "#splitline{#bf{CMS PbPb}}{Preliminary}");
	else latex.DrawLatexNDC(0.60, 0.94, "#splitline{#bf{CMS pPb}}{Preliminary}");


	cTQM->SaveAs(Form("etaQM_%i_%i.pdf", s1, bEP));
}
/////////////////Anime
	if ( 0 ) {
		for ( int i = 0; i < 20; i++ ) {
			if (gr_LYZ_sys_PbPbEta[i]) gr_LYZ_sys_PbPbEta[i]->Delete();
			if (gr_LYZ_PbPbEta[i]) gr_LYZ_PbPbEta[i]->Delete();
			if (gr_LYZ_sys_pPbEta[i]) gr_LYZ_sys_pPbEta[i]->Delete();
			if (gr_LYZ_pPbEta[i]) gr_LYZ_pPbEta[i]->Delete();
		}
		legEtae[3]->SetLabel();
		legEtae[3]->SetOption("");
		cT->SaveAs(Form("eta0_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("etaQM0_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 20; i++ ) {
			if (gr_vnEta_sys[2][3][i]) gr_vnEta_sys[2][3][i]->Delete();
			if (gr_vnEta[2][3][i]) gr_vnEta[2][3][i]->Delete();
		}
		if (legEtae[2]) legEtae[2]->SetLabel();
		if (legEtae[2]) legEtae[2]->SetOption("");
		cT->SaveAs(Form("eta1_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("etaQM1_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 20; i++ ) {
			if (gr_vnEta_sys[2][2][i]) gr_vnEta_sys[2][2][i]->Delete();
			if (gr_vnEta[2][2][i]) gr_vnEta[2][2][i]->Delete();
		}
		legEtae[1]->SetLabel();
		legEtae[1]->SetOption("");
		cT->SaveAs(Form("eta2_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("etaQM2_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 20; i++ ) {
			if (gr_vnEta_sys[2][1][i]) gr_vnEta_sys[2][1][i]->Delete();
			if (gr_vnEta[2][1][i]) gr_vnEta[2][1][i]->Delete();
		}
		legEtae[0]->SetLabel();
		legEtae[0]->SetOption("");
		cT->SaveAs(Form("eta3_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("etaQM3_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 20; i++ ) {
			if (gr_EP_eta_de_sys[i]) gr_EP_eta_de_sys[i]->Delete();
			if (gr_EP_eta_de[i]) gr_EP_eta_de[i]->Delete();
		}
		legEtaEPe[1]->SetLabel();
		legEtaEPe[1]->SetOption("");
		cT->SaveAs(Form("eta4_%i_%i.pdf", s1, bEP));
		cTQM->SaveAs(Form("etaQM4_%i_%i.pdf", s1, bEP));

	}
///**************** 
	cT = MakeCanvas("cTratio", "cTratio", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);


	TH2D * hframe_ratio = new TH2D("hframe_ratio", "", 1, 0, 2.4, 1, 0.61, 1.29);
	InitHist(hframe_ratio, "#eta_{CM}", "v_{2}^{#eta} / v_{2}^{-#eta}");
	hframe_ratio->SetTitleOffset(1.2);

	TGraphErrors * gr_ratio[7][4][20];
	TGraphErrors * gr_EP_ratio[20];
	TGraphErrors * gr_EPde_ratio[20];
	TLine *line = new TLine(0., 1., 2.4, 1.);
	line->SetLineStyle(kDashed);

	for ( int i = 3; i < 8; i++ ) {
		gr_EP_ratio[i] = makeRatioEP(gr_EP_eta[i]);
		gr_EPde_ratio[i] = makeRatioEP(gr_EP_eta_de[i]);

		gr_EP_ratio[i]->SetMarkerStyle(kOpenCircle);
		gr_EPde_ratio[i]->SetMarkerStyle(kFullCircle);

		gr_EPde_ratio[i]->SetMarkerColor(kRed);
		gr_EPde_ratio[i]->SetLineColor(kRed);
	}

	for (int i = 3; i < 8; i++) {
		if ( bEtaRebin ) {
			gr_ratio[2][1][i] = makeRatioEP(gr_vnEta[2][1][i]);
		} else {
			gr_ratio[2][1][i] = makeRatio(gr_vnEta[2][1][i]);
		}
//		gr_ratio[2][1][i]->SetMarkerStyle(kOpenSquare);
	}

	cT->cd(1);
	hframe_ratio->Draw();
	line->Draw();

	gr_EP_ratio[7]->Draw("Psame");
	gr_EPde_ratio[7]->Draw("Psame");
	gr_ratio[2][1][7]->Draw("Psame");

	cT->cd(2);
	hframe_ratio->Draw();
	line->Draw();

	gr_EP_ratio[6]->Draw("Psame");
	gr_EPde_ratio[6]->Draw("Psame");
	gr_ratio[2][1][6]->Draw("Psame");

	cT->cd(3);
	hframe_ratio->Draw();
	line->Draw();

	gr_EP_ratio[5]->Draw("Psame");
	gr_EPde_ratio[5]->Draw("Psame");
	gr_ratio[2][1][5]->Draw("Psame");

	cT->cd(4);
	hframe_ratio->Draw();
	line->Draw();

	gr_EP_ratio[4]->Draw("Psame");
	gr_EPde_ratio[4]->Draw("Psame");
	gr_ratio[2][1][4]->Draw("Psame");

	gROOT->Macro("HIN-14-008.C");
	if (!bPbPb) mgr_ratio->Draw();

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
	else latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

	TLegend * legRatio = new TLegend(0.1, 0.7, 0.55, 0.97);
	legRatio->SetFillColor(kWhite);
	legRatio->SetBorderSize(0);
	legRatio->SetTextFont(43);
	legRatio->SetTextSize(24);
	legRatio->SetTextAlign(11);
	legRatio->AddEntry(gr_ratio[2][1][4], "v_{2}{4}", "p");
	if ( bEP ) {
		legRatio->AddEntry(gr_EP_ratio[4], "v_{2}{EP,#eta_{C}=0}", "p");
		legRatio->AddEntry(gr_EPde_ratio[4], "v_{2}{EP,#eta_{C}=#eta_{POI}}", "p");
	} else {
		legRatio->AddEntry(gr_EP_ratio[4], "v_{2}{SP,#eta_{C}=0}", "p");
		legRatio->AddEntry(gr_EPde_ratio[4], "v_{2}{SP,#eta_{C}=#eta_{POI}}", "p");
	}
	if (!bPbPb) legRatio->AddEntry(gr_ratioHIN, "2-part correlation", "p");
	else legRatio->AddEntry((TObject*)0, "", "");
	cT->cd(2);
	legRatio->Draw();

	cT->SaveAs(Form("ratio_%i_%i.pdf", s1, bEP));
	cT->SaveAs(Form("ratio_%i_%i_C.C", s1, bEP));
////////////////// QM
	if ( 0 ) {
		cTQM = MakeCanvas("cT_ratioQM", "cT_ratioQM", 600, 500);
		cTQM->SetTopMargin(0.02);
		cTQM->SetRightMargin(0.02);

		TH2D * hframe_ratioQM = new TH2D("hframe_ratioQM", "", 1, 0, 2.4, 1, 0.61, 1.29);
		InitHist(hframe_ratioQM, "#eta_{CM}", "v_{2}^{#eta} / v_{2}^{-#eta}");
		hframe_ratioQM->SetTitleOffset(1.2);

		hframe_ratioQM->Draw();
		line->Draw();

		latex.DrawLatexNDC(0.18, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		latex.DrawLatexNDC(0.60, 0.26, "#bf{220 #leq N_{trk}^{offline} < 260}");

		TLegend * legRatioQM = new TLegend(0.16, 0.2, 0.55, 0.47);
		legRatioQM->SetFillColor(kWhite);
		legRatioQM->SetBorderSize(0);
		legRatioQM->SetTextFont(43);
		legRatioQM->SetTextSize(24);
		legRatioQM->SetTextAlign(11);
//		gr_ratio[2][1][4]->SetMarkerStyle(kOpenSquare);
		TLegendEntry * legRatioQMe[10] = {};
		legRatioQMe[0] = legRatioQM->AddEntry(gr_ratio[2][1][4], "v_{2}{4}", "p");
		if ( bEP ) {
			legRatioQMe[1] = legRatioQM->AddEntry(gr_EP_ratio[4], "v_{2}{EP,#eta_{C}=0}", "p");
			legRatioQMe[2] = legRatioQM->AddEntry(gr_EPde_ratio[4], "v_{2}{EP,#eta_{C}=#eta_{POI}}", "p");
		} else {
			legRatioQMe[1] = legRatioQM->AddEntry(gr_EP_ratio[4], "v_{2}{SP,#eta_{C}=0}", "p");
			legRatioQMe[2] = legRatioQM->AddEntry(gr_EPde_ratio[4], "v_{2}{SP,#eta_{C}=#eta_{POI}}", "p");
		}
		legRatioQMe[3] = legRatioQM->AddEntry(gr_ratioHIN, "2-part correlation", "p");
		legRatioQM->Draw();

		gr_EP_ratio[4]->Draw("Psame");
		gr_EPde_ratio[4]->Draw("Psame");
		gr_ratio[2][1][4]->Draw("Psame");
		mgr_ratio->Draw();

		cTQM->SaveAs("ratioQM.pdf");

		gr_ratio[2][1][4]->Delete();
		legRatioQMe[0]->SetLabel();
		legRatioQMe[0]->SetOption("");
		cTQM->SaveAs("ratioQM0.pdf");

		gr_ratioHIN->Delete();
		legRatioQMe[3]->SetLabel();
		legRatioQMe[3]->SetOption("");
		cTQM->SaveAs("ratioQM1.pdf");

		gr_EPde_ratio[4]->Delete();
		legRatioQMe[2]->SetLabel();
		legRatioQMe[2]->SetOption("");
		cTQM->SaveAs("ratioQM2.pdf");

	}
//////////////// QM
if ( 1 ) {
	cTQM = MakeCanvas("cTratioQM", "cTratioQM", 900, 500);
	makeMultiPanelCanvas(cTQM, 2, 1, 0.0, 0., 0.15, 0.15, 0.01);

	cTQM->cd(1);
	hframe_ratio->Draw();
	line->Draw();

	gr_EP_ratio[5]->Draw("Psame");
	gr_EPde_ratio[5]->Draw("Psame");
	gr_ratio[2][1][5]->Draw("Psame");

	cTQM->cd(2);
	hframe_ratio->Draw();
	line->Draw();

	gr_EP_ratio[4]->Draw("Psame");
	gr_EPde_ratio[4]->Draw("Psame");
	gr_ratio[2][1][4]->Draw("Psame");

	if (!bPbPb) mgr_ratio->Draw();

	cTQM->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
	else latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
	latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");

	cTQM->cd(2);
	latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");
	legRatio->SetX1NDC(0.4);
	legRatio->SetX2NDC(0.8);
	legRatio->Draw();

	cTQM->SaveAs(Form("ratioQM_%i_%i.pdf", s1, bEP));
}

///////////////////////////////
	if ( !bPbPb ) {
		TCanvas * cNormEta = MakeCanvas("cNormEta", "cNormEta", 600, 500);
		cNormEta->SetTopMargin(0.02);
		cNormEta->SetRightMargin(0.02);

		TH2D * hframe_etaNorm = new TH2D("hframe_etaNorm", "", 1, -2.4, 2.4, 1, 0, 1.49);
		InitHist(hframe_etaNorm, "#eta", "v_{2}(#eta) / v_{2}(#eta=0)");
		hframe_etaNorm->SetTitleOffset(1.2);

		TGraphErrors * gr_Norm = gr_vnEta[2][1][4]->Clone("gr_Norm");
		double v2norm, ev2norm;
		if ( bEtaRebin ) {
			double v2norm = (gr_Norm->GetY()[5] + gr_Norm->GetY()[6])/2.;
			double ev2norm = sqrt(gr_Norm->GetEY()[5]**2 + gr_Norm->GetEY()[6]**2)/2;
			for ( int i = 0; i < 12; i++ ) {
				gr_Norm->GetEY()[i] = sqrt( (gr_Norm->GetEY()[i]/gr_Norm->GetY()[i])**2 + (ev2norm/v2norm)**2 ) * gr_Norm->GetY()[i] / v2norm;
				gr_Norm->GetY()[i] = gr_Norm->GetY()[i] / v2norm;
			}
		} else {
			double v2norm = (gr_Norm->GetY()[11] + gr_Norm->GetY()[12])/2.;
			double ev2norm = sqrt(gr_Norm->GetEY()[11]**2 + gr_Norm->GetEY()[12]**2)/2;
			for ( int i = 0; i < 24; i++ ) {
				gr_Norm->GetEY()[i] = sqrt( (gr_Norm->GetEY()[i]/gr_Norm->GetY()[i])**2 + (ev2norm/v2norm)**2 ) * gr_Norm->GetY()[i] / v2norm;
				gr_Norm->GetY()[i] = gr_Norm->GetY()[i] / v2norm;
			}
		}
		hframe_etaNorm->Draw();
		gr_Norm->Draw("Psame");
		gr_norm_p->Draw("Psame");
		gr_norm_Pb->Draw("Psame");

		TGraphErrors* gr_Norm_EP = gr_EP_eta[4]->Clone("gr_Norm_EP");
		v2norm = (gr_Norm_EP->GetY()[5] + gr_Norm_EP->GetY()[6]) / 2.;
		ev2norm = sqrt(gr_Norm_EP->GetEY()[5]**2 + gr_Norm_EP->GetEY()[6]**2)/2;

		TGraphErrors* gr_Norm_EP_de = gr_EP_eta_de[4]->Clone("gr_Norm_EP_de");
		v2norm = (gr_Norm_EP_de->GetY()[5] + gr_Norm_EP_de->GetY()[6]) / 2.;
		ev2norm = sqrt(gr_Norm_EP_de->GetEY()[5]**2 + gr_Norm_EP_de->GetEY()[6]**2)/2;
		for ( int i = 0; i < 12; i++ ) {
			gr_Norm_EP->GetEY()[i] = sqrt( (gr_Norm_EP->GetEY()[i]/gr_Norm_EP->GetY()[i])**2 + (ev2norm/v2norm)**2 ) * gr_Norm_EP->GetY()[i] / v2norm;
			gr_Norm_EP->GetY()[i] = gr_Norm_EP->GetY()[i] / v2norm;

			gr_Norm_EP_de->GetEY()[i] = sqrt( (gr_Norm_EP_de->GetEY()[i]/gr_Norm_EP_de->GetY()[i])**2 + (ev2norm/v2norm)**2 ) * gr_Norm_EP_de->GetY()[i] / v2norm;
			gr_Norm_EP_de->GetY()[i] = gr_Norm_EP_de->GetY()[i] / v2norm;
		}
		gr_Norm_EP_de->SetMarkerColor(kRed);
		gr_Norm_EP_de->SetLineColor(kRed);
		gr_Norm_EP->Draw("Psame");
		gr_Norm_EP_de->Draw("Psame");

		TLatex latex_small;
		latex_small.SetTextFont(43);
		latex_small.SetTextSize(24);
		latex_small.SetTextAlign(13);
		latex_small.DrawLatexNDC(0.56, 0.35, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{#bf{220 #leq N_{trk}^{offline} < 260}}");
		TLegend * legNorm = new TLegend(0.2, 0.25, 0.55, 0.55);
		legNorm->SetFillColor(kWhite);
		legNorm->SetBorderSize(0);
		legNorm->SetTextFont(43);
		legNorm->SetTextSize(20);
		legNorm->AddEntry(gr_Norm, "v_{2}{4}", "p");
		if ( bEP ) {
			legNorm->AddEntry(gr_Norm_EP, "v_{2}{EP,#eta_{C}=0}", "p");
			legNorm->AddEntry(gr_Norm_EP_de, "v_{2}{EP,#eta_{C}=#eta_{POI}}", "p");
		} else {
			legNorm->AddEntry(gr_Norm_EP, "v_{2}{SP,#eta_{C}=0}", "p");
			legNorm->AddEntry(gr_Norm_EP_de, "v_{2}{SP,#eta_{C}=#eta_{POI}}", "p");
		}
		legNorm->AddEntry(gr_norm_Pb, "Pb-trig 2-part", "p");
		legNorm->AddEntry(gr_norm_p, "p-trig 2-part", "p");
		legNorm->Draw();

		latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");

		cNormEta->SaveAs("norm_pPb.pdf");
		cNormEta->SaveAs("norm_pPb_C.C");
	}

	if ( bEtaRebin ) {
		cT = MakeCanvas("cFluct", "cFluct", 1600, 500);
		makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_etaFluct = new TH2D("hframe_etaFluct", "hframe_etaFluct", 1, -2.4, 2.4, 1, 0, 1);
		InitHist(hframe_etaFluct, "#eta", "Fluct");
		hframe_etaFluct->SetTitleOffset(1.2);

		TGraphErrors* gr_Fluct[20] = {};
		for ( i = 3; i < 8; i++ ) {
			gr_Fluct[i] = (TGraphErrors*)gr_EP_eta[i]->Clone();
			for ( int j = 0; j < gr_Fluct[i]->GetN(); j++ ) {
				double y1 = gr_EP_eta[i]->GetY()[j];
				double ey1 = gr_EP_eta[i]->GetEY()[j];
				double y2 = gr_vnEta[2][1][i]->GetY()[j];
				double ey2 = gr_vnEta[2][1][i]->GetEY()[j];

				gr_Fluct[i]->GetY()[j] = sqrt( (y1*y1 - y2*y2)/(y1*y1 + y2*y2) );
				double t = y1*y1 - y2*y2;
				double g = y1*y1 + y2*y2;
				double f1 = 2*y1;
				double f2 = -2*y2;
				double g1 = 2*y1;
				double g2 = 2*y2;

				double err1 = (f1/g - t*g1/g/g)**2*ey1*ey1;
				double err2 = (f2/g - t*g2/g/g)**2*ey2*ey2;
				double x = t/g;
				double ex = sqrt(err1 + err2);
				gr_Fluct[i]->GetEY()[j] = ex/sqrt(x)/2;

//				double v4 = gr_EP_eta[i]->GetY()[j];
//				double ev4 = gr_EP_eta[i]->GetEY()[j];
//				double v2 = gr_vnEta[2][1][i]->GetY()[j];
//				double ev2 = gr_vnEta[2][1][i]->GetEY()[j];
//
//				double w2 = v2*v2;
//				double w4 = v4*v4;
//				double ew2 = 4*v2*v2*ev2*ev2;
//				double ew4 = 4*v4*v4*ev4*ev4;
//				double F = gr_Fluct[i]->GetY()[j];
//
//				double enorm = ( ew4*(w2 / (w2+w4) / (w2+w4))**2 + ew2*( w4 / (w2+w4) / (w2+w4) )**2) / F / F;
//
//				cout << i << "," << j << "\terr1 = " << gr_Fluct[i]->GetEY()[j];
//				gr_Fluct[i]->GetEY()[j] = sqrt(enorm);
//				cout << "\terr2 = " << sqrt(enorm) << endl;
//
			}
		}
		cT->cd(1);
		hframe_etaFluct->Draw();
		gr_Fluct[7]->Draw("Psame");

		cT->cd(2);
		hframe_etaFluct->Draw();
		gr_Fluct[6]->Draw("Psame");

		cT->cd(3);
		hframe_etaFluct->Draw();
		gr_Fluct[5]->Draw("Psame");

		cT->cd(4);
		hframe_etaFluct->Draw();
		gr_Fluct[4]->Draw("Psame");

		cT->cd(1);
		if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
		else latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");

		cT->cd(1);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

		TLegend * legFluct = new TLegend(0.05, 0.7, 0.6, 0.97);
		legFluct->SetFillColor(kWhite);
		legFluct->SetBorderSize(0);
		legFluct->SetTextFont(43);
		legFluct->SetTextSize(24);

		legFluct->AddEntry(gr_Fluct[7], " ", "p");
		legFluct->Draw();
		latex.DrawLatexNDC(0.28, 0.91, "#sqrt{#frac{v_{2}#left{EP#right}^{2} - v_{2}#left{4#right}^{2}}{v_{2}#left{EP#right}^{2} + v_{2}#left{4#right}^{2}}}");

		cT->SaveAs(Form("fluct_%i_%i.pdf", s1, bEP));
		cT->SaveAs(Form("fluct_%i_%i_C.C", s1, bEP));

		fsave->cd();
		gr_Fluct[7]->SetName("gr_Fluct_7");
		gr_Fluct[6]->SetName("gr_Fluct_6");
		gr_Fluct[5]->SetName("gr_Fluct_5");
		gr_Fluct[4]->SetName("gr_Fluct_4");
		gr_Fluct[3]->SetName("gr_Fluct_3");

		gr_Fluct[7]->Write();
		gr_Fluct[6]->Write();
		gr_Fluct[5]->Write();
		gr_Fluct[4]->Write();
		gr_Fluct[3]->Write();

	}
//////////////////////////////////////
	if ( !bPbPb ) {
		cT = MakeCanvas("cT_EPpt", "cT_EPpt", 2100, 900);
		makeMultiPanelCanvas(cT, 5, 2, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_EPpt = new TH2D("hframe_EPpt", "", 1, .1, 5.9, 1, 0.01, 0.39);
		InitHist(hframe_EPpt, "p_{T} (GeV/c)", "v_{2}{EP}");
		hframe_EPpt->GetXaxis()->SetLabelFont(43);
		hframe_EPpt->GetXaxis()->SetLabelSize(26);

		int bCM = 1;
		gROOT->Macro("EPeta.C");

		cT->cd(1);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EP_Pb[7], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EP_p[7], sys_EP_pt);
			gr_cm_v2pt_p_EP_Pb[7]->Draw("Psame");
			gr_cm_v2pt_Pb_EP_p[7]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SP_Pb[7], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SP_p[7], sys_EP_pt);
			gr_cm_v2pt_p_SP_Pb[7]->Draw("Psame");
			gr_cm_v2pt_Pb_SP_p[7]->Draw("Psame");
		}

		cT->cd(6);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EPde_Pb[7], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EPde_p[7], sys_EP_pt);
			gr_cm_v2pt_p_EPde_Pb[7]->Draw("Psame");
			gr_cm_v2pt_Pb_EPde_p[7]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SPde_Pb[7], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SPde_p[7], sys_EP_pt);
			gr_cm_v2pt_p_SPde_Pb[7]->Draw("Psame");
			gr_cm_v2pt_Pb_SPde_p[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EP_Pb[6], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EP_p[6], sys_EP_pt);
			gr_cm_v2pt_p_EP_Pb[6]->Draw("Psame");
			gr_cm_v2pt_Pb_EP_p[6]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SP_Pb[6], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SP_p[6], sys_EP_pt);
			gr_cm_v2pt_p_SP_Pb[6]->Draw("Psame");
			gr_cm_v2pt_Pb_SP_p[6]->Draw("Psame");
		}

		cT->cd(7);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EPde_Pb[6], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EPde_p[6], sys_EP_pt);
			gr_cm_v2pt_p_EPde_Pb[6]->Draw("Psame");
			gr_cm_v2pt_Pb_EPde_p[6]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SPde_Pb[6], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SPde_p[6], sys_EP_pt);
			gr_cm_v2pt_p_SPde_Pb[6]->Draw("Psame");
			gr_cm_v2pt_Pb_SPde_p[6]->Draw("Psame");
		}

		cT->cd(3);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EP_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EP_p[5], sys_EP_pt);
			gr_cm_v2pt_p_EP_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_EP_p[5]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SP_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SP_p[5], sys_EP_pt);
			gr_cm_v2pt_p_SP_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_SP_p[5]->Draw("Psame");
		}

		cT->cd(8);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EPde_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EPde_p[5], sys_EP_pt);
			gr_cm_v2pt_p_EPde_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_EPde_p[5]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SPde_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SPde_p[5], sys_EP_pt);
			gr_cm_v2pt_p_SPde_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_SPde_p[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EP_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EP_p[4], sys_EP_pt);
			gr_cm_v2pt_p_EP_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_EP_p[4]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SP_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SP_p[4], sys_EP_pt);
			gr_cm_v2pt_p_SP_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_SP_p[4]->Draw("Psame");
		}

		cT->cd(9);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EPde_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EPde_p[4], sys_EP_pt);
			gr_cm_v2pt_p_EPde_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_EPde_p[4]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SPde_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SPde_p[4], sys_EP_pt);
			gr_cm_v2pt_p_SPde_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_SPde_p[4]->Draw("Psame");
		}

		cT->cd(5);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EP_Pb[3], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EP_p[3], sys_EP_pt);
			gr_cm_v2pt_p_EP_Pb[3]->Draw("Psame");
			gr_cm_v2pt_Pb_EP_p[3]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SP_Pb[3], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SP_p[3], sys_EP_pt);
			gr_cm_v2pt_p_SP_Pb[3]->Draw("Psame");
			gr_cm_v2pt_Pb_SP_p[3]->Draw("Psame");
		}

		cT->cd(10);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EPde_Pb[3], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EPde_p[3], sys_EP_pt);
			gr_cm_v2pt_p_EPde_Pb[3]->Draw("Psame");
			gr_cm_v2pt_Pb_EPde_p[3]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SPde_Pb[3], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SPde_p[3], sys_EP_pt);
			gr_cm_v2pt_p_SPde_Pb[3]->Draw("Psame");
			gr_cm_v2pt_Pb_SPde_p[3]->Draw("Psame");
		}

		cT->cd(1);
		latex28.DrawLatexNDC(0.40, 0.2, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex28.DrawLatexNDC(0.40, 0.2, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex28.DrawLatexNDC(0.40, 0.2, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex28.DrawLatexNDC(0.40, 0.2, "#bf{220 #leq N_{trk}^{offline} < 260}");
		cT->cd(5);
		latex28.DrawLatexNDC(0.40, 0.2, "#bf{260 #leq N_{trk}^{offline} < 300}");

		TLegend * legEPpT1 = new TLegend(0.05, 0.7, 0.5, 0.95);
		legEPpT1->SetFillColor(kWhite);
		legEPpT1->SetBorderSize(0);
		legEPpT1->SetTextFont(43);
		legEPpT1->SetTextSize(26);

		TLegend * legEPpT2 = new TLegend(0.05, 0.7, 0.5, 0.95);
		legEPpT2->SetFillColor(kWhite);
		legEPpT2->SetBorderSize(0);
		legEPpT2->SetTextFont(43);
		legEPpT2->SetTextSize(26);

		if ( bEP ) {
			legEPpT1->AddEntry(gr_cm_v2pt_Pb_EP_p[3], "v_{2}^{Pb}{EP, #eta_{C}=0} -2.0<#eta_{CM}<-1.6", "p");
			legEPpT1->AddEntry(gr_cm_v2pt_p_EP_Pb[3], "v_{2}^{p}{EP, #eta_{C}=0} 1.6<#eta_{CM}<2.0", "p");
			legEPpT2->AddEntry(gr_cm_v2pt_Pb_EPde_p[3], "v_{2}^{Pb}{EP, #eta_{C}=#eta_{POI}} -2.0<#eta_{CM}<-1.6", "p");
			legEPpT2->AddEntry(gr_cm_v2pt_p_EPde_Pb[3], "v_{2}^{p}{EP, #eta_{C}=#eta_{POI}} 1.6<#eta_{CM}<2.0", "p");
		} else {
			legEPpT1->AddEntry(gr_cm_v2pt_Pb_SP_p[3], "v_{2}^{Pb}{SP, #eta_{C}=0} -2.0<#eta_{CM}<-1.6", "p");
			legEPpT1->AddEntry(gr_cm_v2pt_p_SP_Pb[3], "v_{2}^{p}{SP, #eta_{C}=0} 1.6<#eta_{CM}<2.0", "p");
			legEPpT2->AddEntry(gr_cm_v2pt_Pb_SPde_p[3], "v_{2}^{Pb}{SP, #eta_{C}=#eta_{POI}} -2.0<#eta_{CM}<-1.6", "p");
			legEPpT2->AddEntry(gr_cm_v2pt_p_SPde_Pb[3], "v_{2}^{p}{SP, #eta_{C}=#eta_{POI}} 1.6<#eta_{CM}<2.0", "p");
		}

		cT->cd(4);
		legEPpT1->Draw();
		cT->cd(9);
		legEPpT2->Draw();
		cT->cd(10);
		legPtSys->Draw();

		cT->cd(1);
		if (bPbPb) latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
		else latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");


		cT->SaveAs(Form("EPpT_%i_%i.pdf", s1, bEP));
		cT->SaveAs(Form("EPpT_%i_%i_C.C", s1, bEP));

		if ( 0 ) {
			cTQM = MakeCanvas("cT_EPptQM", "cT_EPptQM", 950, 500);
			makeMultiPanelCanvas(cTQM, 2, 1, 0.0, 0., 0.15, 0.15, 0.01);

			TH2D * hframe_EPptQM = new TH2D("hframe_EPptQM", "", 1, .1, 5.9, 1, 0.01, 0.39);
			InitHist(hframe_EPptQM, "p_{T} (GeV/c)", "v_{2}{EP}");
			hframe_EPptQM->SetTitleOffset(1.2);
			cTQM->cd(1);
			hframe_EPptQM->Draw();
			if ( bEP ) {
				DrawSys(gr_cm_v2pt_p_EP_Pb[3], sys_EP_pt);
				DrawSys(gr_cm_v2pt_Pb_EP_p[3], sys_EP_pt);
				gr_cm_v2pt_p_EP_Pb[3]->Draw("Psame");
				gr_cm_v2pt_Pb_EP_p[3]->Draw("Psame");
			} else {
				DrawSys(gr_cm_v2pt_p_SP_Pb[3], sys_EP_pt);
				DrawSys(gr_cm_v2pt_Pb_SP_p[3], sys_EP_pt);
				gr_cm_v2pt_p_SP_Pb[3]->Draw("Psame");
				gr_cm_v2pt_Pb_SP_p[3]->Draw("Psame");
			}

			cTQM->cd(2);
			hframe_EPptQM->Draw();
			if ( bEP ) {
				DrawSys(gr_cm_v2pt_p_EPde_Pb[3], sys_EP_pt);
				DrawSys(gr_cm_v2pt_Pb_EPde_p[3], sys_EP_pt);
				gr_cm_v2pt_p_EPde_Pb[3]->Draw("Psame");
				gr_cm_v2pt_Pb_EPde_p[3]->Draw("Psame");
			} else {
				DrawSys(gr_cm_v2pt_p_SPde_Pb[3], sys_EP_pt);
				DrawSys(gr_cm_v2pt_Pb_SPde_p[3], sys_EP_pt);
				gr_cm_v2pt_p_SPde_Pb[3]->Draw("Psame");
				gr_cm_v2pt_Pb_SPde_p[3]->Draw("Psame");
			}

			cTQM->cd(1);
			latex28.DrawLatexNDC(0.18, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
			cTQM->cd(2);
			TLegend * legEPpT2QM = new TLegend(0.05, 0.65, 0.80, 0.95);
			legEPpT2QM->SetFillColor(kWhite);
			legEPpT2QM->SetBorderSize(0);
			legEPpT2QM->SetTextFont(43);
			legEPpT2QM->SetTextSize(26);

			if ( bEP ) {
				legEPpT2QM->AddEntry(gr_cm_v2pt_p_EP_Pb[3], "v_{2}^{p}{EP, #eta_{C}=0} 1.6<#eta_{CM}<2.0", "p");
				legEPpT2QM->AddEntry(gr_cm_v2pt_Pb_EP_p[3], "v_{2}^{Pb}{EP, #eta_{C}=0} -2.0<#eta_{CM}<-1.6", "p");
				legEPpT2QM->AddEntry(gr_cm_v2pt_p_EPde_Pb[3], "v_{2}^{p}{EP, #eta_{C}=#eta_{POI}} 1.6<#eta_{CM}<2.0", "p");
				legEPpT2QM->AddEntry(gr_cm_v2pt_Pb_EPde_p[3], "v_{2}^{Pb}{EP, #eta_{C}=#eta_{POI}} -2.0<#eta_{CM}<-1.6", "p");
			} else {
				legEPpT2QM->AddEntry(gr_cm_v2pt_p_SPde_Pb[3], "v_{2}^{p}{SP, #eta_{C}=#eta_{POI}} 1.6<#eta_{CM}<2.0", "p");
				legEPpT2QM->AddEntry(gr_cm_v2pt_Pb_SPde_p[3], "v_{2}^{Pb}{SP, #eta_{C}=#eta_{POI}} -2.0<#eta_{CM}<-1.6", "p");
			}

			latex28.DrawLatexNDC(0.45, 0.3, "#bf{260 #leq N_{trk}^{offline} < 300}");

			legEPpT2QM->Draw();
			cTQM->SaveAs("EPpT_QM.pdf");
		}
	}
////////////////////// QM
if ( 1 ) {
	if ( !bPbPb ) {
		TCanvas * cTQM = MakeCanvas("cT_EPptQM", "cT_EPptQM", 1000, 900);
		makeMultiPanelCanvas(cTQM, 2, 2, 0.0, 0., 0.15, 0.15, 0.01);

		cTQM->cd(1);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EP_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EP_p[5], sys_EP_pt);
			gr_cm_v2pt_p_EP_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_EP_p[5]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SP_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SP_p[5], sys_EP_pt);
			gr_cm_v2pt_p_SP_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_SP_p[5]->Draw("Psame");
		}
		cTQM->cd(3);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EPde_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EPde_p[5], sys_EP_pt);
			gr_cm_v2pt_p_EPde_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_EPde_p[5]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SPde_Pb[5], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SPde_p[5], sys_EP_pt);
			gr_cm_v2pt_p_SPde_Pb[5]->Draw("Psame");
			gr_cm_v2pt_Pb_SPde_p[5]->Draw("Psame");
		}
		cTQM->cd(2);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EP_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EP_p[4], sys_EP_pt);
			gr_cm_v2pt_p_EP_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_EP_p[4]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SP_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SP_p[4], sys_EP_pt);
			gr_cm_v2pt_p_SP_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_SP_p[4]->Draw("Psame");
		}

		cTQM->cd(4);
		hframe_EPpt->Draw();
		if ( bEP ) {
			DrawSys(gr_cm_v2pt_p_EPde_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_EPde_p[4], sys_EP_pt);
			gr_cm_v2pt_p_EPde_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_EPde_p[4]->Draw("Psame");
		} else {
			DrawSys(gr_cm_v2pt_p_SPde_Pb[4], sys_EP_pt);
			DrawSys(gr_cm_v2pt_Pb_SPde_p[4], sys_EP_pt);
			gr_cm_v2pt_p_SPde_Pb[4]->Draw("Psame");
			gr_cm_v2pt_Pb_SPde_p[4]->Draw("Psame");
		}

		cTQM->cd(1);
		latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		latex28.DrawLatexNDC(0.40, 0.2, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cTQM->cd(2);
		latex28.DrawLatexNDC(0.40, 0.2, "#bf{220 #leq N_{trk}^{offline} < 260}");
		cTQM->cd(3);
		legEPpT1->SetX1NDC(0.2);
		legEPpT1->Draw();
		cTQM->cd(4);
		legEPpT2->Draw();

		cTQM->SaveAs("EPpTQM.pdf");
	}
}
///////////////////////////////////////

	if ( 1 ) {
		cT = MakeCanvas("cTeta3", "cTeta3", 1600, 500);
		makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_eta3 = new TH2D("hframe_eta3", "", 1, -2.4, 2.4, 1, 0, 0.049);
		InitHist(hframe_eta3, "#eta", "v_{3}");
		hframe_eta3->SetTitleOffset(1.2);

		TGraphErrors* gr_EP_eta3[20] = {};
		TGraphErrors* gr_EP_eta_de3[20] = {};

		cT->cd(1);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[7] = merge_EP_longrange(gr_v3p_EP[7], gr_v3Pb_EP[7]);
			DrawSys(gr_EP_eta3[7], sys_EP3_eta);
			gr_EP_eta_de3[7] = merge_EP_longrange(gr_v3p_EP_de[7], gr_v3Pb_EP_de[7], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[7], sys_EP3_eta);
			gr_EP_eta3[7]->Draw("Psame");
			gr_EP_eta_de3[7]->Draw("Psame");
		} else {
			gr_EP_eta3[7] = merge_EP_longrange(gr_v3p_SP[7], gr_v3Pb_SP[7]);
			DrawSys(gr_EP_eta3[7], sys_EP3_eta);
			gr_EP_eta_de3[7] = merge_EP_longrange(gr_v3p_SP_de[7], gr_v3Pb_SP_de[7], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[7], sys_EP3_eta);
			gr_EP_eta3[7]->Draw("Psame");
			gr_EP_eta_de3[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[6] = merge_EP_longrange(gr_v3p_EP[6], gr_v3Pb_EP[6]);
			DrawSys(gr_EP_eta3[6], sys_EP3_eta);
			gr_EP_eta_de3[6] = merge_EP_longrange(gr_v3p_EP_de[6], gr_v3Pb_EP_de[6], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[6], sys_EP3_eta);
			gr_EP_eta3[6]->Draw("Psame");
			gr_EP_eta_de3[6]->Draw("Psame");
		} else {
			gr_EP_eta3[6] = merge_EP_longrange(gr_v3p_SP[6], gr_v3Pb_SP[6]);
			DrawSys(gr_EP_eta3[6], sys_EP3_eta);
			gr_EP_eta_de3[6] = merge_EP_longrange(gr_v3p_SP_de[6], gr_v3Pb_SP_de[6], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[6], sys_EP3_eta);
			gr_EP_eta3[6]->Draw("Psame");
			gr_EP_eta_de3[6]->Draw("Psame");
		}

		cT->cd(3);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[5] = merge_EP_longrange(gr_v3p_EP[5], gr_v3Pb_EP[5]);
			DrawSys(gr_EP_eta3[5], sys_EP3_eta);
			gr_EP_eta_de3[5] = merge_EP_longrange(gr_v3p_EP_de[5], gr_v3Pb_EP_de[5], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[5], sys_EP3_eta);
			gr_EP_eta3[5]->Draw("Psame");
			gr_EP_eta_de3[5]->Draw("Psame");
		} else {
			gr_EP_eta3[5] = merge_EP_longrange(gr_v3p_SP[5], gr_v3Pb_SP[5]);
			DrawSys(gr_EP_eta3[5], sys_EP3_eta);
			gr_EP_eta_de3[5] = merge_EP_longrange(gr_v3p_SP_de[5], gr_v3Pb_SP_de[5], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[5], sys_EP3_eta);
			gr_EP_eta3[5]->Draw("Psame");
			gr_EP_eta_de3[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_eta3->Draw();

		if ( bEP ) {
			gr_EP_eta3[4] = merge_EP_longrange(gr_v3p_EP[4], gr_v3Pb_EP[4]);
			DrawSys(gr_EP_eta3[4], sys_EP3_eta);
			gr_EP_eta_de3[4] = merge_EP_longrange(gr_v3p_EP_de[4], gr_v3Pb_EP_de[4], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[4], sys_EP3_eta);
			gr_EP_eta3[4]->Draw("Psame");
			gr_EP_eta_de3[4]->Draw("Psame");

			gr_EP_eta3[3] = merge_EP_longrange(gr_v3p_EP[3], gr_v3Pb_EP[3]);
			gr_EP_eta_de3[3] = merge_EP_longrange(gr_v3p_EP_de[3], gr_v3Pb_EP_de[3], kOpenCircle, kBlue);
		} else {
			gr_EP_eta3[4] = merge_EP_longrange(gr_v3p_SP[4], gr_v3Pb_SP[4]);
			DrawSys(gr_EP_eta3[4], sys_EP3_eta);
			gr_EP_eta_de3[4] = merge_EP_longrange(gr_v3p_SP_de[4], gr_v3Pb_SP_de[4], kOpenCircle, kBlue);
			DrawSys(gr_EP_eta_de3[4], sys_EP3_eta);
			gr_EP_eta3[4]->Draw("Psame");
			gr_EP_eta_de3[4]->Draw("Psame");

			gr_EP_eta3[3] = merge_EP_longrange(gr_v3p_SP[3], gr_v3Pb_SP[3]);
			gr_EP_eta_de3[3] = merge_EP_longrange(gr_v3p_SP_de[3], gr_v3Pb_SP_de[3], kOpenCircle, kBlue);
		}

		cT->cd(1);
		if ( bPbPb ) {
			latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
		} else {
			latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		}

		cT->cd(2);
		TLegend * legEtaEP3 = new TLegend(0.05, 0.8, 0.3, 0.97);
		legEtaEP3->SetFillColor(kWhite);
		legEtaEP3->SetBorderSize(0);
		legEtaEP3->SetTextFont(43);
		legEtaEP3->SetTextSize(24);
		if ( bEP ) {
			legEtaEP3->AddEntry(gr_EP_eta3[4], "v_{3}{EP, #eta_{C}=0}", "p");
			legEtaEP3->AddEntry(gr_EP_eta_de3[4], "v_{3}{EP, #eta_{C}=#eta_{POI}}", "p");
		} else {
			legEtaEP3->AddEntry(gr_EP_eta3[4], "v_{3}{SP, #eta_{C}=0}", "p");
			legEtaEP3->AddEntry(gr_EP_eta_de3[4], "v_{3}{SP, #eta_{C}=#eta_{POI}}", "p");
		}
		legEtaEP3->Draw();

		cT->cd(1);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex.DrawLatexNDC(0.40, 0.24, "#bf{220 #leq N_{trk}^{offline} < 260}");

		cT->cd(4);
		latex.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");

		gr_EP_eta3[7]->SetName("gr_EP_eta3_7");
		gr_EP_eta3[6]->SetName("gr_EP_eta3_6");
		gr_EP_eta3[5]->SetName("gr_EP_eta3_5");
		gr_EP_eta3[4]->SetName("gr_EP_eta3_4");
		gr_EP_eta3[3]->SetName("gr_EP_eta3_3");
		gr_EP_eta_de3[7]->SetName("gr_EP_eta_de3_7");
		gr_EP_eta_de3[6]->SetName("gr_EP_eta_de3_6");
		gr_EP_eta_de3[5]->SetName("gr_EP_eta_de3_5");
		gr_EP_eta_de3[4]->SetName("gr_EP_eta_de3_4");
		gr_EP_eta_de3[3]->SetName("gr_EP_eta_de3_3");

		gr_EP_eta[7]->SetName("gr_EP_eta_7");
		gr_EP_eta[6]->SetName("gr_EP_eta_6");
		gr_EP_eta[5]->SetName("gr_EP_eta_5");
		gr_EP_eta[4]->SetName("gr_EP_eta_4");
		gr_EP_eta[3]->SetName("gr_EP_eta_3");
		gr_EP_eta_de[7]->SetName("gr_EP_eta_de_7");
		gr_EP_eta_de[6]->SetName("gr_EP_eta_de_6");
		gr_EP_eta_de[5]->SetName("gr_EP_eta_de_5");
		gr_EP_eta_de[4]->SetName("gr_EP_eta_de_4");
		gr_EP_eta_de[3]->SetName("gr_EP_eta_de_3");

		fsave->cd();

		gr_EP_eta3[7]->Write();
		gr_EP_eta3[6]->Write();
		gr_EP_eta3[5]->Write();
		gr_EP_eta3[4]->Write();
		gr_EP_eta3[3]->Write();
		gr_EP_eta_de3[7]->Write();
		gr_EP_eta_de3[6]->Write();
		gr_EP_eta_de3[5]->Write();
		gr_EP_eta_de3[4]->Write();
		gr_EP_eta_de3[3]->Write();

		gr_EP_eta[7]->Write();
		gr_EP_eta[6]->Write();
		gr_EP_eta[5]->Write();
		gr_EP_eta[4]->Write();
		gr_EP_eta[3]->Write();
		gr_EP_eta_de[7]->Write();
		gr_EP_eta_de[6]->Write();
		gr_EP_eta_de[5]->Write();
		gr_EP_eta_de[4]->Write();
		gr_EP_eta_de[3]->Write();

//		cT->SaveAs(Form("eta3_%i_%i.pdf", s1, bEP));
//		cT->SaveAs(Form("eta3_%i_%i_C.C", s1, bEP));
	}
//////////////////////
	if ( 1 ) {
		cT = MakeCanvas("cT_EPeta3", "cT_EPeta3", 2100, 900);
		makeMultiPanelCanvas(cT, 5, 2, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_EPeta3 = new TH2D("hframe_EPeta3", "", 1, -2.4, 2.4, 1, 0.001, 0.049);
		InitHist(hframe_EPeta3, "#eta", "v_{3}{EP}");

		cT->cd(1);
		hframe_EPeta3->Draw();

		for ( int i = 3; i < 8; i++ ) {
			gr_v3p_EP[i]->SetLineWidth(1);
			gr_v3Pb_EP[i]->SetLineWidth(1);
			gr_v3p_SP[i]->SetLineWidth(1);
			gr_v3Pb_SP[i]->SetLineWidth(1);

			gr_v3p_EP_de[i]->SetLineWidth(1);
			gr_v3Pb_EP_de[i]->SetLineWidth(1);
			gr_v3p_SP_de[i]->SetLineWidth(1);
			gr_v3Pb_SP_de[i]->SetLineWidth(1);
		}

		if ( bEP ) {
			DrawSys(gr_v3p_EP[7], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP[7], sys_EP3_eta);
			gr_v3p_EP[7]->Draw("Psame");
			gr_v3Pb_EP[7]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP[7], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP[7], sys_EP3_eta);
			gr_v3p_SP[7]->Draw("Psame");
			gr_v3Pb_SP[7]->Draw("Psame");
		}

		cT->cd(6);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP_de[7], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP_de[7], sys_EP3_eta);
			gr_v3p_EP_de[7]->Draw("Psame");
			gr_v3Pb_EP_de[7]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP_de[7], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP_de[7], sys_EP3_eta);
			gr_v3p_SP_de[7]->Draw("Psame");
			gr_v3Pb_SP_de[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP[6], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP[6], sys_EP3_eta);
			gr_v3p_EP[6]->Draw("Psame");
			gr_v3Pb_EP[6]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP[6], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP[6], sys_EP3_eta);
			gr_v3p_SP[6]->Draw("Psame");
			gr_v3Pb_SP[6]->Draw("Psame");
		}

		cT->cd(7);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP_de[6], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP_de[6], sys_EP3_eta);
			gr_v3p_EP_de[6]->Draw("Psame");
			gr_v3Pb_EP_de[6]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP_de[7], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP_de[7], sys_EP3_eta);
			gr_v3p_SP_de[7]->Draw("Psame");
			gr_v3Pb_SP_de[7]->Draw("Psame");
		}

		cT->cd(3);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP[5], sys_EP3_eta);
			gr_v3p_EP[5]->Draw("Psame");
			gr_v3Pb_EP[5]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP[5], sys_EP3_eta);
			gr_v3p_SP[5]->Draw("Psame");
			gr_v3Pb_SP[5]->Draw("Psame");
		}

		cT->cd(8);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP_de[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP_de[5], sys_EP3_eta);
			gr_v3p_EP_de[5]->Draw("Psame");
			gr_v3Pb_EP_de[5]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP_de[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP_de[5], sys_EP3_eta);
			gr_v3p_SP_de[5]->Draw("Psame");
			gr_v3Pb_SP_de[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP[4], sys_EP3_eta);
			gr_v3p_EP[4]->Draw("Psame");
			gr_v3Pb_EP[4]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP[4], sys_EP3_eta);
			gr_v3p_SP[4]->Draw("Psame");
			gr_v3Pb_SP[4]->Draw("Psame");
		}

		cT->cd(9);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP_de[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP_de[4], sys_EP3_eta);
			gr_v3p_EP_de[4]->Draw("Psame");
			gr_v3Pb_EP_de[4]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP_de[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP_de[4], sys_EP3_eta);
			gr_v3p_SP_de[4]->Draw("Psame");
			gr_v3Pb_SP_de[4]->Draw("Psame");
		}

		cT->cd(5);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP[3], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP[3], sys_EP3_eta);
			gr_v3p_EP[3]->Draw("Psame");
			gr_v3Pb_EP[3]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP[3], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP[3], sys_EP3_eta);
			gr_v3p_SP[3]->Draw("Psame");
			gr_v3Pb_SP[3]->Draw("Psame");
		}

		cT->cd(10);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP_de[3], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP_de[3], sys_EP3_eta);
			gr_v3p_EP_de[3]->Draw("Psame");
			gr_v3Pb_EP_de[3]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP_de[3], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP_de[3], sys_EP3_eta);
			gr_v3p_SP_de[3]->Draw("Psame");
			gr_v3Pb_SP_de[3]->Draw("Psame");
		}

		cT->cd(9);
		TLegend * legEPeta3 = new TLegend(0.05, 0.18, 0.5, 0.5);
		legEPeta3->SetFillColor(kWhite);
		legEPeta3->SetBorderSize(0);
		legEPeta3->SetTextFont(43);
		legEPeta3->SetTextSize(24);
		if ( bEP ) {
			if ( bPbPb ) {
				legEPeta3->AddEntry(gr_v3p_EP[3], "v_{3}{EP, #eta_{C}=0} HF+ EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_EP[3], "v_{3}{EP, #eta_{C}=0} HF- EP", "p");
				legEPeta3->AddEntry(gr_v3p_EP_de[3], "v_{3}{EP, #eta_{C}=#eta_{POI}} HF+ EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_EP_de[3], "v_{3}{EP, #eta_{C}=#eta_{POI}} HF- EP", "p");
			} else {
				legEPeta3->AddEntry(gr_v3p_EP[3], "v_{3}{EP, #eta_{C}=0} p-going EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_EP[3], "v_{3}{EP, #eta_{C}=0} Pb-going EP", "p");
				legEPeta3->AddEntry(gr_v3p_EP_de[3], "v_{3}{EP, #eta_{C}=#eta_{POI}} p-going EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_EP_de[3], "v_{3}{EP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
			}
		} else {
			if ( bPbPb ) {
				legEPeta3->AddEntry(gr_v3p_SP[3], "v_{3}{SP, #eta_{C}=0} HF+ EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_SP[3], "v_{3}{SP, #eta_{C}=0} HF- EP", "p");
				legEPeta3->AddEntry(gr_v3p_SP_de[3], "v_{3}{SP, #eta_{C}=#eta_{POI}} HF+ EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_SP_de[3], "v_{3}{SP, #eta_{C}=#eta_{POI}} HF- EP", "p");
			} else {
				legEPeta3->AddEntry(gr_v3p_SP[3], "v_{3}{SP, #eta_{C}=0} p-going EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_SP[3], "v_{3}{SP, #eta_{C}=0} Pb-going EP", "p");
				legEPeta3->AddEntry(gr_v3p_SP_de[3], "v_{3}{SP, #eta_{C}=#eta_{POI}} p-going EP", "p");
				legEPeta3->AddEntry(gr_v3Pb_SP_de[3], "v_{3}{SP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
			}
		}
		legEPeta3->Draw();

		cT->cd(1);
		if ( bPbPb ) {
			latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
		} else {
			latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		}

		cT->cd(5);
		latex28.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");

		cT->cd(1);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{220 #leq N_{trk}^{offline} < 260}");
		cT->cd(5);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{260 #leq N_{trk}^{offline} < 300}");

		cT->cd(10);
		TLegend * legSysV3 = new TLegend(0.05, 0.2, 0.6, 0.26);
		legSysV3->SetFillColor(kWhite);
		legSysV3->SetBorderSize(0);
		legSysV3->SetTextFont(43);
		legSysV3->SetTextSize(24);
		legSysV3->AddEntry(gr_sys_l, "Systematic uncertainties", "f");
		legSysV3->Draw();


		cT->SaveAs(Form("eta3all_%i_%i.pdf", s1, bEP));
		cT->SaveAs(Form("eta3all_%i_%i_C.C", s1, bEP));
	}
/////////////////////////// QM
	if ( 1 ) {
		cTQM = MakeCanvas("cT_EPeta3QM", "cT_EPeta3QM", 1000, 900);
		makeMultiPanelCanvas(cTQM, 2, 2, 0.0, 0., 0.15, 0.15, 0.01);

		cTQM->cd(1);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP[5], sys_EP3_eta);
			gr_v3p_EP[5]->Draw("Psame");
			gr_v3Pb_EP[5]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP[5], sys_EP3_eta);
			gr_v3p_SP[5]->Draw("Psame");
			gr_v3Pb_SP[5]->Draw("Psame");
		}

		cTQM->cd(3);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP_de[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP_de[5], sys_EP3_eta);
			gr_v3p_EP_de[5]->Draw("Psame");
			gr_v3Pb_EP_de[5]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP_de[5], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP_de[5], sys_EP3_eta);
			gr_v3p_SP_de[5]->Draw("Psame");
			gr_v3Pb_SP_de[5]->Draw("Psame");
		}

		cTQM->cd(2);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP[4], sys_EP3_eta);
			gr_v3p_EP[4]->Draw("Psame");
			gr_v3Pb_EP[4]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP[4], sys_EP3_eta);
			gr_v3p_SP[4]->Draw("Psame");
			gr_v3Pb_SP[4]->Draw("Psame");
		}

		cTQM->cd(4);
		hframe_EPeta3->Draw();

		if ( bEP ) {
			DrawSys(gr_v3p_EP_de[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_EP_de[4], sys_EP3_eta);
			gr_v3p_EP_de[4]->Draw("Psame");
			gr_v3Pb_EP_de[4]->Draw("Psame");
		} else {
			DrawSys(gr_v3p_SP_de[4], sys_EP3_eta);
			DrawSys(gr_v3Pb_SP_de[4], sys_EP3_eta);
			gr_v3p_SP_de[4]->Draw("Psame");
			gr_v3Pb_SP_de[4]->Draw("Psame");
		}

		cTQM->cd(1);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{185 #leq N_{trk}^{offline} < 220}");
		if ( bPbPb ) {
			latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
		} else {
			latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		}


		cTQM->cd(2);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{220 #leq N_{trk}^{offline} < 260}");
		latex28.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");
		cTQM->cd(3);
		cTQM->cd(4);
		legEPeta3->Draw();

		cTQM->SaveAs(Form("eta3allQM_%i_%i.pdf", s1, bEP));
	}
////////////////////////////////
	if ( 1 ) {
		cT = MakeCanvas("cT_EPeta2", "cT_EPeta2", 2100, 900);
		makeMultiPanelCanvas(cT, 5, 2, 0.0, 0., 0.15, 0.15, 0.01);

		TH2D * hframe_EPeta2 = new TH2D("hframe_EPeta2", "", 1, -2.4, 2.4, 1, 0.001, 0.14);
		InitHist(hframe_EPeta2, "#eta", "v_{2}{EP}");

		cT->cd(1);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP[7], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[7], sys_EP_eta);
			gr_v2p_EP[7]->Draw("Psame");
			gr_v2Pb_EP[7]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[7], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[7], sys_EP_eta);
			gr_v2p_SP[7]->Draw("Psame");
			gr_v2Pb_SP[7]->Draw("Psame");
		}

		cT->cd(6);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP_de[7], sys_EP_eta);
			DrawSys(gr_v2Pb_EP_de[7], sys_EP_eta);
			gr_v2p_EP_de[7]->Draw("Psame");
			gr_v2Pb_EP_de[7]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP_de[7], sys_EP_eta);
			DrawSys(gr_v2Pb_SP_de[7], sys_EP_eta);
			gr_v2p_SP_de[7]->Draw("Psame");
			gr_v2Pb_SP_de[7]->Draw("Psame");
		}

		cT->cd(2);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP[6], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[6], sys_EP_eta);
			gr_v2p_EP[6]->Draw("Psame");
			gr_v2Pb_EP[6]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[6], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[6], sys_EP_eta);
			gr_v2p_SP[6]->Draw("Psame");
			gr_v2Pb_SP[6]->Draw("Psame");
		}

		cT->cd(7);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP_de[6], sys_EP_eta);
			DrawSys(gr_v2Pb_EP_de[6], sys_EP_eta);
			gr_v2p_EP_de[6]->Draw("Psame");
			gr_v2Pb_EP_de[6]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP_de[6], sys_EP_eta);
			DrawSys(gr_v2Pb_SP_de[6], sys_EP_eta);
			gr_v2p_SP_de[6]->Draw("Psame");
			gr_v2Pb_SP_de[6]->Draw("Psame");
		}

		cT->cd(3);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[5], sys_EP_eta);
			gr_v2p_EP[5]->Draw("Psame");
			gr_v2Pb_EP[5]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[5], sys_EP_eta);
			gr_v2p_SP[5]->Draw("Psame");
			gr_v2Pb_SP[5]->Draw("Psame");
		}

		cT->cd(8);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP_de[5], sys_EP_eta);
			DrawSys(gr_v2Pb_EP_de[5], sys_EP_eta);
			gr_v2p_EP_de[5]->Draw("Psame");
			gr_v2Pb_EP_de[5]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP_de[5], sys_EP_eta);
			DrawSys(gr_v2Pb_SP_de[5], sys_EP_eta);
			gr_v2p_SP_de[5]->Draw("Psame");
			gr_v2Pb_SP_de[5]->Draw("Psame");
		}

		cT->cd(4);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP[4], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[4], sys_EP_eta);
			gr_v2p_EP[4]->Draw("Psame");
			gr_v2Pb_EP[4]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[4], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[4], sys_EP_eta);
			gr_v2p_SP[4]->Draw("Psame");
			gr_v2Pb_SP[4]->Draw("Psame");
		}

		cT->cd(9);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP_de[4], sys_EP_eta);
			DrawSys(gr_v2Pb_EP_de[4], sys_EP_eta);
			gr_v2p_EP_de[4]->Draw("Psame");
			gr_v2Pb_EP_de[4]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP_de[4], sys_EP_eta);
			DrawSys(gr_v2Pb_SP_de[4], sys_EP_eta);
			gr_v2p_SP_de[4]->Draw("Psame");
			gr_v2Pb_SP_de[4]->Draw("Psame");
		}

		cT->cd(5);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP[3], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[3], sys_EP_eta);
			gr_v2p_EP[3]->Draw("Psame");
			gr_v2Pb_EP[3]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[3], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[3], sys_EP_eta);
			gr_v2p_SP[3]->Draw("Psame");
			gr_v2Pb_SP[3]->Draw("Psame");
		}

		cT->cd(10);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP_de[3], sys_EP_eta);
			DrawSys(gr_v2Pb_EP_de[3], sys_EP_eta);
			gr_v2p_EP_de[3]->Draw("Psame");
			gr_v2Pb_EP_de[3]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP_de[3], sys_EP_eta);
			DrawSys(gr_v2Pb_SP_de[3], sys_EP_eta);
			gr_v2p_SP_de[3]->Draw("Psame");
			gr_v2Pb_SP_de[3]->Draw("Psame");
		}

		cT->cd(9);
		TLegend * legEPeta2 = new TLegend(0.05, 0.18, 0.5, 0.5);
		legEPeta2->SetFillColor(kWhite);
		legEPeta2->SetBorderSize(0);
		legEPeta2->SetTextFont(43);
		legEPeta2->SetTextSize(24);
		if ( bEP ) {
			if ( bPbPb ) {
				legEPeta2->AddEntry(gr_v2p_EP[3], "v_{2}{EP, #eta_{C}=0} HF+ EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_EP[3], "v_{2}{EP, #eta_{C}=0} HF- EP", "p");
				legEPeta2->AddEntry(gr_v2p_EP_de[3], "v_{2}{EP, #eta_{C}=#eta_{POI}} HF+ EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_EP_de[3], "v_{2}{EP, #eta_{C}=#eta_{POI}} HF- EP", "p");
			} else {
				legEPeta2->AddEntry(gr_v2p_EP[3], "v_{2}{EP, #eta_{C}=0} p-going EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_EP[3], "v_{2}{EP, #eta_{C}=0} Pb-going EP", "p");
				legEPeta2->AddEntry(gr_v2p_EP_de[3], "v_{2}{EP, #eta_{C}=#eta_{POI}} p-going EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_EP_de[3], "v_{2}{EP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
			}
		} else {
			if ( bPbPb ) {
				legEPeta2->AddEntry(gr_v2p_SP[3], "v_{2}{SP, #eta_{C}=0} HF+ EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_SP[3], "v_{2}{SP, #eta_{C}=0} HF- EP", "p");
				legEPeta2->AddEntry(gr_v2p_SP_de[3], "v_{2}{SP, #eta_{C}=#eta_{POI}} HF+ EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_SP_de[3], "v_{2}{SP, #eta_{C}=#eta_{POI}} HF- EP", "p");
			} else {
				legEPeta2->AddEntry(gr_v2p_SP[3], "v_{2}{SP, #eta_{C}=0} p-going EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_SP[3], "v_{2}{SP, #eta_{C}=0} Pb-going EP", "p");
				legEPeta2->AddEntry(gr_v2p_SP_de[3], "v_{2}{SP, #eta_{C}=#eta_{POI}} p-going EP", "p");
				legEPeta2->AddEntry(gr_v2Pb_SP_de[3], "v_{2}{SP, #eta_{C}=#eta_{POI}} Pb-going EP", "p");
			}
		}
		legEPeta2->Draw();

		cT->cd(1);
		if ( bPbPb ) {
			latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
		} else {
			latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		}

		cT->cd(1);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{120 #leq N_{trk}^{offline} < 150}");
		cT->cd(2);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{150 #leq N_{trk}^{offline} < 185}");
		cT->cd(3);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cT->cd(4);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{220 #leq N_{trk}^{offline} < 260}");
		cT->cd(5);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{260 #leq N_{trk}^{offline} < 300}");

		cT->cd(5);
		latex28.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");

		cT->cd(10);

		TLegend * legSysV3 = new TLegend(0.05, 0.2, 0.6, 0.26);
		legSysV3->SetFillColor(kWhite);
		legSysV3->SetBorderSize(0);
		legSysV3->SetTextFont(43);
		legSysV3->SetTextSize(24);
		legSysV3->AddEntry(gr_sys_l, "Systematic uncertainties", "f");
		legSysV3->Draw();


		legSysV3->Draw();

		cT->SaveAs(Form("eta2all_%i_%i.pdf", s1, bEP));
		cT->SaveAs(Form("eta2all_%i_%i_C.C", s1, bEP));
	}
///////////////////////////////// QM
	if ( 0 ) {
		cTQM = MakeCanvas("eta2single", "eta2single", 500, 500);
		cTQM->SetTopMargin(0.02);
		cTQM->SetRightMargin(0.02);

		hframe_eta->Draw();
		if ( bEP ) {
			DrawSys(gr_v2p_EP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[5], sys_EP_eta);
			gr_v2p_EP[5]->Draw("Psame");
			gr_v2Pb_EP[5]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[5], sys_EP_eta);
			gr_v2p_SP[5]->Draw("Psame");
			gr_v2Pb_SP[5]->Draw("Psame");
		}
		latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		latex28.DrawLatexNDC(0.40, 0.25, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cTQM->SaveAs(Form("eta2allQMsingle_%i_%i.pdf", s1, bEP));

		for ( int i = 0; i < 6; i++ ) {
			gr_v2p_EP[5]->RemovePoint(11-i);
			gr_v2Pb_EP[5]->RemovePoint(11-i);
		}
		hframe_eta->Draw();
		if ( bEP ) {
			DrawSys(gr_v2p_EP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[5], sys_EP_eta);
			gr_v2p_EP[5]->Draw("Psame");
			gr_v2Pb_EP[5]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[5], sys_EP_eta);
			gr_v2p_SP[5]->Draw("Psame");
			gr_v2Pb_SP[5]->Draw("Psame");
		}
		latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		latex28.DrawLatexNDC(0.40, 0.25, "#bf{185 #leq N_{trk}^{offline} < 220}");
		cTQM->SaveAs(Form("eta2allQMsingle0_%i_%i.pdf", s1, bEP));


	}
	if ( 0 ) {
		cTQM = MakeCanvas("cT_EPeta2QM", "cT_EPeta2", 1000, 900);
		makeMultiPanelCanvas(cTQM, 2, 2, 0.0, 0., 0.15, 0.15, 0.01);

		cTQM->cd(1);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[5], sys_EP_eta);
			gr_v2p_EP[5]->Draw("Psame");
			gr_v2Pb_EP[5]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[5], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[5], sys_EP_eta);
			gr_v2p_SP[5]->Draw("Psame");
			gr_v2Pb_SP[5]->Draw("Psame");
		}

		cTQM->cd(3);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP_de[5], sys_EP_eta);
			DrawSys(gr_v2Pb_EP_de[5], sys_EP_eta);
			gr_v2p_EP_de[5]->Draw("Psame");
			gr_v2Pb_EP_de[5]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP_de[5], sys_EP_eta);
			DrawSys(gr_v2Pb_SP_de[5], sys_EP_eta);
			gr_v2p_SP_de[5]->Draw("Psame");
			gr_v2Pb_SP_de[5]->Draw("Psame");
		}

		cTQM->cd(2);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP[4], sys_EP_eta);
			DrawSys(gr_v2Pb_EP[4], sys_EP_eta);
			gr_v2p_EP[4]->Draw("Psame");
			gr_v2Pb_EP[4]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP[4], sys_EP_eta);
			DrawSys(gr_v2Pb_SP[4], sys_EP_eta);
			gr_v2p_SP[4]->Draw("Psame");
			gr_v2Pb_SP[4]->Draw("Psame");
		}

		cTQM->cd(4);
		hframe_EPeta2->Draw();

		if ( bEP ) {
			DrawSys(gr_v2p_EP_de[4], sys_EP_eta);
			DrawSys(gr_v2Pb_EP_de[4], sys_EP_eta);
			gr_v2p_EP_de[4]->Draw("Psame");
			gr_v2Pb_EP_de[4]->Draw("Psame");
		} else {
			DrawSys(gr_v2p_SP_de[4], sys_EP_eta);
			DrawSys(gr_v2Pb_SP_de[4], sys_EP_eta);
			gr_v2p_SP_de[4]->Draw("Psame");
			gr_v2Pb_SP_de[4]->Draw("Psame");
		}

		cTQM->cd(1);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{185 #leq N_{trk}^{offline} < 220}");
		if ( bPbPb ) {
			latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
		} else {
			latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
		}


		cTQM->cd(2);
		latex28.DrawLatexNDC(0.40, 0.15, "#bf{220 #leq N_{trk}^{offline} < 260}");
		latex28.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");

		cTQM->cd(4);
		legEPeta2->Draw();

		cTQM->SaveAs(Form("eta2allQM_%i_%i.pdf", s1, bEP));
	}

///////SP/EP ratio vs pT////////////////////////
	cT = MakeCanvas("cT_RatioPtSP2EP", "cT_RatioPtSP2EP", 2100, 500);
	makeMultiPanelCanvas(cT, 5, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_RatioPtSP2EP = new TH2D("hframe_RatioPtSP2EP", "", 1, 0.1, 5.9, 1, 0.9, 1.29);
	InitHist(hframe_RatioPtSP2EP, "p_{T}", "v_{2}{SP}/v_{2}{EP}");
	hframe_RatioPtSP2EP->SetTitleOffset(1.2, "X");
//	hframe_RatioPtSP2EP->GetXaxis()->SetLabelSize(24);

	TGraphErrors * gr_RatioPt_p[20] = {};
	TGraphErrors * gr_RatioPt_Pb[20] = {};

        TLine *line_pt = new TLine(0.1,1,5.9,1);

	cT->cd(1);
	hframe_RatioPtSP2EP->Draw();
	line_pt->Draw();

	gr_RatioPt_p[7] = makeRatioPt(gr_v2pt_m_SPde_p[7], gr_v2pt_m_EPde_p[7], 0, 15);
	gr_RatioPt_Pb[7] = makeRatioPt(gr_v2pt_m_SPde_Pb[7], gr_v2pt_m_EPde_Pb[7], 0, 15);

	gr_RatioPt_p[7]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_p[7]->SetMarkerColor(kBlue);
	gr_RatioPt_p[7]->SetLineColor(kBlue);

	gr_RatioPt_Pb[7]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_Pb[7]->SetMarkerColor(kRed);
	gr_RatioPt_Pb[7]->SetLineColor(kRed);

	gr_RatioPt_p[7]->Draw("Psame");
	gr_RatioPt_Pb[7]->Draw("Psame");

	cT->cd(2);
	hframe_RatioPtSP2EP->Draw();
	line_pt->Draw();

	gr_RatioPt_p[6] = makeRatioPt(gr_v2pt_m_SPde_p[6], gr_v2pt_m_EPde_p[6], 0, 15);
	gr_RatioPt_Pb[6] = makeRatioPt(gr_v2pt_m_SPde_Pb[6], gr_v2pt_m_EPde_Pb[6], 0, 15);

	gr_RatioPt_p[6]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_p[6]->SetMarkerColor(kBlue);
	gr_RatioPt_p[6]->SetLineColor(kBlue);

	gr_RatioPt_Pb[6]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_Pb[6]->SetMarkerColor(kRed);
	gr_RatioPt_Pb[6]->SetLineColor(kRed);

	gr_RatioPt_p[6]->Draw("Psame");
	gr_RatioPt_Pb[6]->Draw("Psame");

	cT->cd(3);
	hframe_RatioPtSP2EP->Draw();
	line_pt->Draw();

	gr_RatioPt_p[5] = makeRatioPt(gr_v2pt_m_SPde_p[5], gr_v2pt_m_EPde_p[5], 0, 15);
	gr_RatioPt_Pb[5] = makeRatioPt(gr_v2pt_m_SPde_Pb[5], gr_v2pt_m_EPde_Pb[5], 0, 15);

	gr_RatioPt_p[5]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_p[5]->SetMarkerColor(kBlue);
	gr_RatioPt_p[5]->SetLineColor(kBlue);

	gr_RatioPt_Pb[5]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_Pb[5]->SetMarkerColor(kRed);
	gr_RatioPt_Pb[5]->SetLineColor(kRed);

	gr_RatioPt_p[5]->Draw("Psame");
	gr_RatioPt_Pb[5]->Draw("Psame");


	cT->cd(4);
	hframe_RatioPtSP2EP->Draw();
	line_pt->Draw();

	gr_RatioPt_p[4] = makeRatioPt(gr_v2pt_m_SPde_p[4], gr_v2pt_m_EPde_p[4], 0, 15);
	gr_RatioPt_Pb[4] = makeRatioPt(gr_v2pt_m_SPde_Pb[4], gr_v2pt_m_EPde_Pb[4], 0, 15);

	gr_RatioPt_p[4]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_p[4]->SetMarkerColor(kBlue);
	gr_RatioPt_p[4]->SetLineColor(kBlue);

	gr_RatioPt_Pb[4]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_Pb[4]->SetMarkerColor(kRed);
	gr_RatioPt_Pb[4]->SetLineColor(kRed);

	gr_RatioPt_p[4]->Draw("Psame");
	gr_RatioPt_Pb[4]->Draw("Psame");

	cT->cd(5);
	hframe_RatioPtSP2EP->Draw();
	line_pt->Draw();

	gr_RatioPt_p[3] = makeRatioPt(gr_v2pt_m_SPde_p[3], gr_v2pt_m_EPde_p[3], 0, 15);
	gr_RatioPt_Pb[3] = makeRatioPt(gr_v2pt_m_SPde_Pb[3], gr_v2pt_m_EPde_Pb[3], 0, 15);

	gr_RatioPt_p[3]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_p[3]->SetMarkerColor(kBlue);
	gr_RatioPt_p[3]->SetLineColor(kBlue);

	gr_RatioPt_Pb[3]->SetMarkerStyle(kFullSquare);
	gr_RatioPt_Pb[3]->SetMarkerColor(kRed);
	gr_RatioPt_Pb[3]->SetLineColor(kRed);

	gr_RatioPt_p[3]->Draw("Psame");
	gr_RatioPt_Pb[3]->Draw("Psame");

	cT->cd(1);
	if ( bPbPb ) {
		latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
	} else {
		latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
	}

	cT->cd(1);
	latex28.DrawLatexNDC(0.40, 0.25, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex28.DrawLatexNDC(0.40, 0.25, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex28.DrawLatexNDC(0.40, 0.25, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex28.DrawLatexNDC(0.40, 0.25, "#bf{220 #leq N_{trk}^{offline} < 260}");
	cT->cd(5);
	latex28.DrawLatexNDC(0.40, 0.25, "#bf{260 #leq N_{trk}^{offline} < 300}");

	cT->cd(4);

	TLegend * legPtSP2EP = new TLegend(0.05, 0.8, 0.7, 0.95);
	legPtSP2EP->SetFillColor(kWhite);
	legPtSP2EP->SetBorderSize(0);
	legPtSP2EP->SetTextFont(43);
	legPtSP2EP->SetTextSize(28);
	if ( bPbPb ) {
		legPtSP2EP->AddEntry(gr_RatioPt_Pb[3], "v_{2}{SP}/v_{2}{EP} HF- EP", "p");
		legPtSP2EP->AddEntry(gr_RatioPt_p[3], "v_{2}{SP}/v_{2}{EP} HF+ EP", "p");
	} else {
		legPtSP2EP->AddEntry(gr_RatioPt_Pb[3], "v_{2}{SP}/v_{2}{EP} Pb-going EP", "p");
		legPtSP2EP->AddEntry(gr_RatioPt_p[3], "v_{2}{SP}/v_{2}{EP} p-going EP", "p");
	}
	legPtSP2EP->Draw();

	cT->cd(3);
	latex28.DrawLatexNDC(0.20, 0.94, "|#eta| < 0.8");


	cT->SaveAs(Form("SP2EP_ratioPt_%i.pdf", s1));
	cT->SaveAs(Form("SP2EP_ratioPt_%i_C.C", s1));

///////SP/EP ratio vs eta////////////////////////
	cT = MakeCanvas("cT_RatioEtaSP2EP", "cT_RatioEtaSP2EP", 2100, 500);
	makeMultiPanelCanvas(cT, 5, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_RatioEtaSP2EP = new TH2D("hframe_RatioEtaSP2EP", "", 1, -2.4, 2.4, 1, 0.92, 1.09);
	InitHist(hframe_RatioEtaSP2EP, "#eta", "v_{2}{SP}/v_{2}{EP}");
	hframe_RatioEtaSP2EP->SetTitleOffset(1.2, "X");

	TGraphErrors * gr_RatioEta_p[20] = {};
	TGraphErrors * gr_RatioEta_Pb[20] = {};

	fsave->cd();
	for ( int i = 3; i < 8; i++ ) {
		gr_RatioEta_p[i] = makeRatioPt(gr_v2p_SP_de[i], gr_v2p_EP_de[i], 0, 12);
		gr_RatioEta_p[i]->SetMarkerStyle(kFullSquare);
		gr_RatioEta_p[i]->SetMarkerColor(kBlue);
		gr_RatioEta_p[i]->SetLineColor(kBlue);

		gr_RatioEta_Pb[i] = makeRatioPt(gr_v2Pb_SP_de[i], gr_v2Pb_EP_de[i], 0, 12);
		gr_RatioEta_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_RatioEta_Pb[i]->SetMarkerColor(kRed);
		gr_RatioEta_Pb[i]->SetLineColor(kRed);

		gr_RatioEta_p[i]->SetName(Form("gr_RatioEta_p_%i", i));
		gr_RatioEta_p[i]->Write();
		gr_RatioEta_Pb[i]->SetName(Form("gr_RatioEta_Pb_%i", i));
		gr_RatioEta_Pb[i]->Write();

		gr_std(gr_RatioEta_p[i]);
		gr_std(gr_RatioEta_Pb[i]);

	}
	gr_std_line(gr_RatioEta_Pb[7]);
	gr_std_line(gr_RatioEta_Pb[6]);
	gr_std_line(gr_RatioEta_Pb[5]);

	gr_ratio_err();


        TLine *line = new TLine(-2.4,1,2.4,1);
	cT->cd(1);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_RatioEta_p[7]->Draw("Psame");
	gr_RatioEta_Pb[7]->Draw("Psame");

	cT->cd(2);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_RatioEta_p[6]->Draw("Psame");
	gr_RatioEta_Pb[6]->Draw("Psame");

	cT->cd(3);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_RatioEta_p[5]->Draw("Psame");
	gr_RatioEta_Pb[5]->Draw("Psame");

	cT->cd(4);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_RatioEta_p[4]->Draw("Psame");
	gr_RatioEta_Pb[4]->Draw("Psame");

	cT->cd(5);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_RatioEta_p[3]->Draw("Psame");
	gr_RatioEta_Pb[3]->Draw("Psame");

	cT->cd(1);
	latex28.DrawLatexNDC(0.40, 0.3, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex28.DrawLatexNDC(0.40, 0.3, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex28.DrawLatexNDC(0.40, 0.3, "#bf{220 #leq N_{trk}^{offline} < 260}");
	cT->cd(5);
	latex28.DrawLatexNDC(0.40, 0.3, "#bf{260 #leq N_{trk}^{offline} < 300}");

	cT->cd(1);
	if ( bPbPb ) {
		latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}}{Preliminary}");
	} else {
		latex28.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}}{Preliminary}");
	}


	cT->cd(4);
	TLegend * legEtaSP2EP = new TLegend(0.05, 0.8, 0.7, 0.95);
	legEtaSP2EP->SetFillColor(kWhite);
	legEtaSP2EP->SetBorderSize(0);
	legEtaSP2EP->SetTextFont(43);
	legEtaSP2EP->SetTextSize(28);
	if ( bPbPb ) {
		legEtaSP2EP->AddEntry(gr_RatioEta_Pb[3], "v_{2}{SP}/v_{2}{EP} HF- EP", "p");
		legEtaSP2EP->AddEntry(gr_RatioEta_p[3], "v_{2}{SP}/v_{2}{EP} HF+ EP", "p");
	} else {
		legEtaSP2EP->AddEntry(gr_RatioEta_Pb[3], "v_{2}{SP}/v_{2}{EP} Pb-going EP", "p");
		legEtaSP2EP->AddEntry(gr_RatioEta_p[3], "v_{2}{SP}/v_{2}{EP} p-going EP", "p");
	}
	legEtaSP2EP->Draw();

	cT->cd(3);
	latex28.DrawLatexNDC(0.20, 0.94, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{#eta_{C}=#eta_{POI}}");

	cT->SaveAs(Form("SP2EP_ratioEta_%i.pdf", s1));
	cT->SaveAs(Form("SP2EP_ratioEta_%i_C.C", s1));

	fsave->Close();
}

