{
#include "style.h"
#include "helper.h"

	TFile * fpPb = new TFile("eta3_139_1.root");
	TFile * fPbPb = new TFile("eta3_109_1.root");

	TGraphErrors * gr_pA_eta3[20] = {};
	TGraphErrors * gr_AA_eta3[20] = {};
	TGraphErrors * gr_pA_eta3_de[20] = {};
	TGraphErrors * gr_AA_eta3_de[20] = {};

	TGraphErrors * gr_pA_eta[20] = {};
	TGraphErrors * gr_AA_eta[20] = {};
	TGraphErrors * gr_pA_eta_de[20] = {};
	TGraphErrors * gr_AA_eta_de[20] = {};


	SetStyle();

	TGraphErrors* gr_sys_l = new TGraphErrors();
	gr_sys_l->SetFillColor(kGray);
	gr_sys_l->SetLineColor(kGray);
//	gr_sys_l->SetLineColor(kBlack);

	TLegend * legPtSys = new TLegend(0.05, 0.9, 0.6, 0.95);
	legPtSys->SetFillColor(kWhite);
	legPtSys->SetBorderSize(0);
	legPtSys->SetTextFont(43);
	legPtSys->SetTextSize(24);
	legPtSys->AddEntry(gr_sys_l, "Systematic uncertainties", "f");
	legPtSys->Draw();



	TCanvas * cT = MakeCanvas("cTeta3", "cTeta3", 2100, 500);
	makeMultiPanelCanvas(cT, 5, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_eta3 = new TH2D("hframe_eta3", "", 1, -2.4, 2.4, 1, 0, 0.16);
	InitHist(hframe_eta3, "#eta", "v_{n}");
	hframe_eta3->SetTitleOffset(1.2);

	gr_pA_eta3[7] = (TGraphErrors*) fpPb->Get("gr_EP_eta3_7");
	gr_pA_eta3[6] = (TGraphErrors*) fpPb->Get("gr_EP_eta3_6");
	gr_pA_eta3[5] = (TGraphErrors*) fpPb->Get("gr_EP_eta3_5");
	gr_pA_eta3[4] = (TGraphErrors*) fpPb->Get("gr_EP_eta3_4");
	gr_pA_eta3[3] = (TGraphErrors*) fpPb->Get("gr_EP_eta3_3");

	gr_pA_eta3_de[7] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de3_7");
	gr_pA_eta3_de[6] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de3_6");
	gr_pA_eta3_de[5] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de3_5");
	gr_pA_eta3_de[4] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de3_4");
	gr_pA_eta3_de[3] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de3_3");

	gr_AA_eta3[7] = (TGraphErrors*) fPbPb->Get("gr_EP_eta3_7");
	gr_AA_eta3[6] = (TGraphErrors*) fPbPb->Get("gr_EP_eta3_6");
	gr_AA_eta3[5] = (TGraphErrors*) fPbPb->Get("gr_EP_eta3_5");
	gr_AA_eta3[4] = (TGraphErrors*) fPbPb->Get("gr_EP_eta3_4");
	gr_AA_eta3[3] = (TGraphErrors*) fPbPb->Get("gr_EP_eta3_3");

	gr_AA_eta3_de[7] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de3_7");
	gr_AA_eta3_de[6] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de3_6");
	gr_AA_eta3_de[5] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de3_5");
	gr_AA_eta3_de[4] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de3_4");
	gr_AA_eta3_de[3] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de3_3");



	///2
	gr_pA_eta[7] = (TGraphErrors*) fpPb->Get("gr_EP_eta_7");
	gr_pA_eta[6] = (TGraphErrors*) fpPb->Get("gr_EP_eta_6");
	gr_pA_eta[5] = (TGraphErrors*) fpPb->Get("gr_EP_eta_5");
	gr_pA_eta[4] = (TGraphErrors*) fpPb->Get("gr_EP_eta_4");
	gr_pA_eta[3] = (TGraphErrors*) fpPb->Get("gr_EP_eta_3");

	gr_pA_eta_de[7] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de_7");
	gr_pA_eta_de[6] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de_6");
	gr_pA_eta_de[5] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de_5");
	gr_pA_eta_de[4] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de_4");
	gr_pA_eta_de[3] = (TGraphErrors*) fpPb->Get("gr_EP_eta_de_3");

	gr_AA_eta[7] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_7");
	gr_AA_eta[6] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_6");
	gr_AA_eta[5] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_5");
	gr_AA_eta[4] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_4");
	gr_AA_eta[3] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_3");

	gr_AA_eta_de[7] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de_7");
	gr_AA_eta_de[6] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de_6");
	gr_AA_eta_de[5] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de_5");
	gr_AA_eta_de[4] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de_4");
	gr_AA_eta_de[3] = (TGraphErrors*) fPbPb->Get("gr_EP_eta_de_3");

	for ( int i = 3; i < 8; i++ ) {
		gr_pA_eta3_de[i]->SetMarkerStyle(kFullSquare);
		gr_pA_eta3_de[i]->SetMarkerColor(kBlue);
		gr_pA_eta3_de[i]->SetLineColor(kBlue);

		gr_AA_eta3_de[i]->SetMarkerStyle(kOpenSquare);
		gr_AA_eta3_de[i]->SetMarkerColor(kRed);
		gr_AA_eta3_de[i]->SetLineColor(kRed);

		gr_pA_eta_de[i]->SetMarkerStyle(kFullCircle);
		gr_pA_eta_de[i]->SetMarkerColor(kBlue);
		gr_pA_eta_de[i]->SetLineColor(kBlue);

		gr_AA_eta_de[i]->SetMarkerStyle(kOpenCircle);
		gr_AA_eta_de[i]->SetMarkerColor(kRed);
		gr_AA_eta_de[i]->SetLineColor(kRed);
	}


	cT->cd(1);
	hframe_eta3->Draw();

	DrawSys(gr_pA_eta3_de[7], 0.1);
	DrawSys(gr_AA_eta3_de[7], 0.1);
	DrawSys(gr_pA_eta_de[7], 0.03);
	DrawSys(gr_AA_eta_de[7], 0.03);

	gr_pA_eta3_de[7]->Draw("Psame");
	gr_AA_eta3_de[7]->Draw("Psame");
	gr_pA_eta_de[7]->Draw("Psame");
	gr_AA_eta_de[7]->Draw("Psame");

	cT->cd(2);
	hframe_eta3->Draw();

	DrawSys(gr_pA_eta3_de[6], 0.1);
	DrawSys(gr_AA_eta3_de[6], 0.1);
	DrawSys(gr_pA_eta_de[6], 0.03);
	DrawSys(gr_AA_eta_de[6], 0.03);

	gr_pA_eta3_de[6]->Draw("Psame");
	gr_AA_eta3_de[6]->Draw("Psame");
	gr_pA_eta_de[6]->Draw("Psame");
	gr_AA_eta_de[6]->Draw("Psame");

	cT->cd(3);
	hframe_eta3->Draw();

	DrawSys(gr_pA_eta3_de[5], 0.1);
	DrawSys(gr_AA_eta3_de[5], 0.1);
	DrawSys(gr_pA_eta_de[5], 0.03);
	DrawSys(gr_AA_eta_de[5], 0.03);

	gr_pA_eta3_de[5]->Draw("Psame");
	gr_AA_eta3_de[5]->Draw("Psame");
	gr_pA_eta_de[5]->Draw("Psame");
	gr_AA_eta_de[5]->Draw("Psame");

	cT->cd(4);
	hframe_eta3->Draw();

	DrawSys(gr_pA_eta3_de[4], 0.1);
	DrawSys(gr_AA_eta3_de[4], 0.1);
	DrawSys(gr_pA_eta_de[4], 0.03);
	DrawSys(gr_AA_eta_de[4], 0.03);

	gr_pA_eta3_de[4]->Draw("Psame");
	gr_AA_eta3_de[4]->Draw("Psame");
	gr_pA_eta_de[4]->Draw("Psame");
	gr_AA_eta_de[4]->Draw("Psame");

	cT->cd(5);
	hframe_eta3->Draw();

	DrawSys(gr_pA_eta3_de[3], 0.1);
	DrawSys(gr_AA_eta3_de[3], 0.1);
	DrawSys(gr_pA_eta_de[3], 0.03);
	DrawSys(gr_AA_eta_de[3], 0.03);

	gr_pA_eta3_de[3]->Draw("Psame");
	gr_AA_eta3_de[3]->Draw("Psame");
	gr_pA_eta_de[3]->Draw("Psame");
	gr_AA_eta_de[3]->Draw("Psame");


	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(28);
	latex.SetTextAlign(13);


	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{220 #leq N_{trk}^{offline} < 260}");
	cT->cd(5);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{260 #leq N_{trk}^{offline} < 300}");


	cT->cd(3);
	TLegend * legEtaEP2 = new TLegend(0.05, 0.8, 0.3, 0.97);
	legEtaEP2->SetFillColor(kWhite);
	legEtaEP2->SetBorderSize(0);
	legEtaEP2->SetTextFont(43);
	legEtaEP2->SetTextSize(24);

	legEtaEP2->AddEntry(gr_AA_eta_de[4], "v_{2}{EP,#eta_{C}=#eta_{POI}} PbPb", "p");
	legEtaEP2->AddEntry(gr_pA_eta_de[4], "v_{2}{EP,#eta_{C}=#eta_{POI}} pPb", "p");

	legEtaEP2->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS}}{Preliminary}");

	cT->cd(4);
	TLegend * legEtaEP3 = new TLegend(0.05, 0.8, 0.3, 0.97);
	legEtaEP3->SetFillColor(kWhite);
	legEtaEP3->SetBorderSize(0);
	legEtaEP3->SetTextFont(43);
	legEtaEP3->SetTextSize(24);

	legEtaEP3->AddEntry(gr_AA_eta3_de[4], "v_{3}{EP,#eta_{C}=#eta_{POI}} PbPb", "p");
	legEtaEP3->AddEntry(gr_pA_eta3_de[4], "v_{3}{EP,#eta_{C}=#eta_{POI}} pPb", "p");

	legEtaEP3->Draw();

	cT->cd(2);
	latex.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");

	cT->cd(5);
	legPtSys->Draw();

	cT->SaveAs("eta3.pdf");
	cT->SaveAs("eta3_C.C");
////// QM plot
	if ( 1 ) {
		cT = MakeCanvas("cTeta3QM", "cTeta3QM", 900, 500);
		makeMultiPanelCanvas(cT, 2, 1, 0.0, 0., 0.15, 0.15, 0.01);

		cT->cd(1);
		hframe_eta3->Draw();
		DrawSys(gr_pA_eta3_de[5], 0.1);
		DrawSys(gr_AA_eta3_de[5], 0.1);
		DrawSys(gr_pA_eta_de[5], 0.03);
		DrawSys(gr_AA_eta_de[5], 0.03);

		gr_pA_eta3_de[5]->Draw("Psame");
		gr_AA_eta3_de[5]->Draw("Psame");
		gr_pA_eta_de[5]->Draw("Psame");
		gr_AA_eta_de[5]->Draw("Psame");

		latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS}}{Preliminary}");

		TLegend * legEtaEP2x = new TLegend(0.1, 0.8, 0.5, 0.97);
		legEtaEP2x->SetFillColor(kWhite);
		legEtaEP2x->SetBorderSize(0);
		legEtaEP2x->SetTextFont(43);
		legEtaEP2x->SetTextSize(24);

		legEtaEP2x->AddEntry(gr_AA_eta_de[4], "v_{2}{EP} PbPb", "p");
		legEtaEP2x->AddEntry(gr_pA_eta_de[4], "v_{2}{EP} pPb", "p");

		latex.DrawLatexNDC(0.55, 0.94, "#splitline{#eta_{C}=#eta_{POI}}{0.3<p_{T}<3.0 GeV/c}");

		cT->cd(2);
		hframe_eta3->Draw();
		DrawSys(gr_pA_eta3_de[4], 0.1);
		DrawSys(gr_AA_eta3_de[4], 0.1);
		DrawSys(gr_pA_eta_de[4], 0.03);
		DrawSys(gr_AA_eta_de[4], 0.03);

		gr_pA_eta3_de[4]->Draw("Psame");
		gr_AA_eta3_de[4]->Draw("Psame");
		gr_pA_eta_de[4]->Draw("Psame");
		gr_AA_eta_de[4]->Draw("Psame");

		TLegend * legEtaEP3x = new TLegend(0.55, 0.8, 0.9, 0.97);
		legEtaEP3x->SetFillColor(kWhite);
		legEtaEP3x->SetBorderSize(0);
		legEtaEP3x->SetTextFont(43);
		legEtaEP3x->SetTextSize(24);

		legEtaEP3x->AddEntry(gr_AA_eta3_de[4], "v_{3}{EP} PbPb", "p");
		legEtaEP3x->AddEntry(gr_pA_eta3_de[4], "v_{3}{EP} pPb", "p");

		legEtaEP2x->Draw();
		legEtaEP3x->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{220 #leq N_{trk}^{offline} < 260}");

		cT->SaveAs("eta3_QM.pdf");
	}


////// Fluct
	TGraphErrors * gr_pA_Fluct[20] = {};
	TGraphErrors * gr_AA_Fluct[20] = {};
	for ( int i = 3; i < 8; i++ ) {
		gr_pA_Fluct[i] = (TGraphErrors*) fpPb->Get(Form("gr_Fluct_%i", i));
		gr_pA_Fluct[i]->SetMarkerStyle(kFullCircle);
		gr_pA_Fluct[i]->SetMarkerColor(kRed);
		gr_pA_Fluct[i]->SetLineColor(kRed);

		gr_AA_Fluct[i] = (TGraphErrors*) fPbPb->Get(Form("gr_Fluct_%i", i));
		gr_AA_Fluct[i]->SetMarkerStyle(kOpenCircle);
		gr_AA_Fluct[i]->SetMarkerColor(kRed);
		gr_AA_Fluct[i]->SetLineColor(kRed);
	}

	cT = MakeCanvas("cTFluct", "cTFluct", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_fluct = new TH2D("hframe_fluct", "", 1, -2.4, 2.4, 1, 0.01, 0.99);
	InitHist(hframe_fluct, "#eta", "Fluctuation");
	hframe_fluct->SetTitleOffset(1.2);

	cT->cd(1);
	hframe_fluct->Draw();
	gr_pA_Fluct[7]->Draw("Psame");
	gr_AA_Fluct[7]->Draw("Psame");

	cT->cd(2);
	hframe_fluct->Draw();
	gr_pA_Fluct[6]->Draw("Psame");
	gr_AA_Fluct[6]->Draw("Psame");

	cT->cd(3);
	hframe_fluct->Draw();
	gr_pA_Fluct[5]->Draw("Psame");
	gr_AA_Fluct[5]->Draw("Psame");

	cT->cd(4);
	hframe_fluct->Draw();
	gr_pA_Fluct[4]->Draw("Psame");
	gr_AA_Fluct[4]->Draw("Psame");

	cT->cd(1);
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS}}{Preliminary}");

	cT->cd(2);
	latex.DrawLatexNDC(0.28, 0.91, "#sqrt{#frac{v_{2}#left{EP#right}^{2} - v_{2}#left{4#right}^{2}}{v_{2}#left{EP#right}^{2} + v_{2}#left{4#right}^{2}}}");

	cT->cd(3);
	TLegend * legFluct = new TLegend(0.05, 0.8, 0.6, 0.97);
	legFluct->SetFillColor(kWhite);
	legFluct->SetBorderSize(0);
	legFluct->SetTextFont(43);
	legFluct->SetTextSize(24);

	legFluct->AddEntry(gr_pA_Fluct[4], "pPb #sqrt{s_{NN}} = 5.02 TeV", "p");
	legFluct->AddEntry(gr_AA_Fluct[4], "PbPb #sqrt{s_{NN}} = 2.76 TeV", "p");

	legFluct->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT->cd(4);
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{0.3 < p_{T} < 3.0 GeV/c}{#eta_{C} = 0}");


	cT->SaveAs("Fluct.pdf");
	cT->SaveAs("Fluct_C.C");
///////////////////// QM
if ( 1 ) {
	cT = MakeCanvas("cTFluctQM", "cTFluctQM", 900, 500);
	makeMultiPanelCanvas(cT, 2, 1, 0.0, 0., 0.15, 0.15, 0.01);

	cT->cd(1);
	hframe_fluct->Draw();
	gr_pA_Fluct[5]->Draw("Psame");
	gr_AA_Fluct[5]->Draw("Psame");
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS}}{Preliminary}");
	latex.DrawLatexNDC(0.40, 0.3, "#bf{185 #leq N_{trk}^{offline} < 220}");

	cT->cd(2);
	hframe_fluct->Draw();
	gr_pA_Fluct[4]->Draw("Psame");
	gr_AA_Fluct[4]->Draw("Psame");
	legFluct->Draw();
	latex.DrawLatexNDC(0.40, 0.3, "#bf{220 #leq N_{trk}^{offline} < 260}");


	cT->SaveAs("FluctQM.pdf");
}

////// fluct slope
	TF1 * fit = new TF1("line", "pol1", -2.4, 2.4);
	double Fslope_pA[4] = {};
	double Fslope_AA[4] = {};
	double Fslope_pA_e[4] = {};
	double Fslope_AA_e[4] = {};

	for ( int i = 4; i < 8; i++ ) {
		gr_pA_Fluct[i]->Fit(fit, "QN");
		Fslope_pA[i-4] = fit->GetParameter(1);
		Fslope_pA_e[i-4] = fit->GetParError(1);

		gr_AA_Fluct[i]->Fit(fit, "QN");
		Fslope_AA[i-4] = fit->GetParameter(1);
		Fslope_AA_e[i-4] = fit->GetParError(1);
	}
	double xnoff[4] = {135, 167, 202, 240};

	TGraphErrors* gr_pA_slop = new TGraphErrors(4, xnoff, Fslope_pA, 0, Fslope_pA_e);
	TGraphErrors* gr_AA_slop = new TGraphErrors(4, xnoff, Fslope_AA, 0, Fslope_AA_e);

	gr_pA_slop->SetMarkerStyle(kFullCircle);
	gr_pA_slop->SetMarkerColor(kRed);
	gr_pA_slop->SetLineColor(kRed);

	gr_AA_slop->SetMarkerStyle(kOpenCircle);
	gr_AA_slop->SetMarkerColor(kRed);
	gr_AA_slop->SetLineColor(kRed);

	cT = MakeCanvas("FluctSlope", "FluctSlope", 600, 500);
	TH2D * hframe_FluctSlope = new TH2D("hframe_FluctSlope", "", 1, 120, 260, 1, -0.05, 0.05);
	InitHist(hframe_FluctSlope, "N_{trk}^{offline}", "Fluctuation Slope");
	hframe_FluctSlope->SetTitleOffset(1.2, "X");

	hframe_FluctSlope->Draw();
	gr_pA_slop->Draw("psame");
	gr_AA_slop->Draw("psame");

	legFluct->Draw();

	TLine *line_noff = new TLine(120,0,260,0);
	line_noff->Draw();
	cT->SaveAs("FluctSlope.pdf");

////// SP2EP eta
	TGraphErrors * gr_pA_RatioEta_p[20] = {};
	TGraphErrors * gr_pA_RatioEta_Pb[20] = {};
	TGraphErrors * gr_AA_RatioEta_p[20] = {};
	TGraphErrors * gr_AA_RatioEta_Pb[20] = {};

	for ( int i = 3; i < 8; i++ ) {
		gr_pA_RatioEta_p[i] = (TGraphErrors*) fpPb->Get(Form("gr_RatioEta_p_%i", i));
		gr_pA_RatioEta_p[i]->SetMarkerStyle(kFullCircle);
		gr_pA_RatioEta_p[i]->SetMarkerColor(kBlue);
		gr_pA_RatioEta_p[i]->SetLineColor(kBlue);

		gr_pA_RatioEta_Pb[i] = (TGraphErrors*) fpPb->Get(Form("gr_RatioEta_Pb_%i", i));
		gr_pA_RatioEta_Pb[i]->SetMarkerStyle(kFullCircle);
		gr_pA_RatioEta_Pb[i]->SetMarkerColor(kRed);
		gr_pA_RatioEta_Pb[i]->SetLineColor(kRed);

		gr_AA_RatioEta_p[i] = (TGraphErrors*) fPbPb->Get(Form("gr_RatioEta_p_%i", i));
		gr_AA_RatioEta_p[i]->SetMarkerStyle(kOpenCircle);
		gr_AA_RatioEta_p[i]->SetMarkerColor(kBlue);
		gr_AA_RatioEta_p[i]->SetLineColor(kBlue);

		gr_AA_RatioEta_Pb[i] = (TGraphErrors*) fPbPb->Get(Form("gr_RatioEta_Pb_%i", i));
		gr_AA_RatioEta_Pb[i]->SetMarkerStyle(kOpenCircle);
		gr_AA_RatioEta_Pb[i]->SetMarkerColor(kRed);
		gr_AA_RatioEta_Pb[i]->SetLineColor(kRed);
	}

	cT = MakeCanvas("cT_RatioEtaSP2EP", "cT_RatioEtaSP2EP", 2100, 500);
	makeMultiPanelCanvas(cT, 5, 1, 0.0, 0., 0.15, 0.15, 0.01);

	TH2D * hframe_RatioEtaSP2EP = new TH2D("hframe_RatioEtaSP2EP", "", 1, -2.4, 2.4, 1, 0.91, 1.14);
	InitHist(hframe_RatioEtaSP2EP, "#eta", "v_{2}{SP}/v_{2}{EP}");
	hframe_RatioEtaSP2EP->SetTitleOffset(1.2, "X");

	TLine *line = new TLine(-2.4,1,2.4,1);
	cT->cd(1);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_pA_RatioEta_p[7]->Draw("Psame");
	gr_pA_RatioEta_Pb[7]->Draw("Psame");
	gr_AA_RatioEta_p[7]->Draw("Psame");
	gr_AA_RatioEta_Pb[7]->Draw("Psame");

	cT->cd(2);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_pA_RatioEta_p[6]->Draw("Psame");
	gr_pA_RatioEta_Pb[6]->Draw("Psame");
	gr_AA_RatioEta_p[6]->Draw("Psame");
	gr_AA_RatioEta_Pb[6]->Draw("Psame");

	cT->cd(3);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_pA_RatioEta_p[5]->Draw("Psame");
	gr_pA_RatioEta_Pb[5]->Draw("Psame");
	gr_AA_RatioEta_p[5]->Draw("Psame");
	gr_AA_RatioEta_Pb[5]->Draw("Psame");

	cT->cd(4);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_pA_RatioEta_p[4]->Draw("Psame");
	gr_pA_RatioEta_Pb[4]->Draw("Psame");
	gr_AA_RatioEta_p[4]->Draw("Psame");
	gr_AA_RatioEta_Pb[4]->Draw("Psame");

	cT->cd(5);
	hframe_RatioEtaSP2EP->Draw();
	line->Draw();
	gr_pA_RatioEta_p[3]->Draw("Psame");
	gr_pA_RatioEta_Pb[3]->Draw("Psame");
	gr_AA_RatioEta_p[3]->Draw("Psame");
	gr_AA_RatioEta_Pb[3]->Draw("Psame");

	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{220 #leq N_{trk}^{offline} < 260}");
	cT->cd(5);
	latex.DrawLatexNDC(0.40, 0.3, "#bf{260 #leq N_{trk}^{offline} < 300}");

	cT->cd(1);
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS}}{Preliminary}");

	cT->cd(3);
	latex.DrawLatexNDC(0.20, 0.9, "0.3 < p_{T} < 3.0 GeV/c");

	cT->cd(4);
	TLegend * legSP2EPeta = new TLegend(0.05, 0.7, 0.6, 0.97);
	legSP2EPeta->SetFillColor(kWhite);
	legSP2EPeta->SetBorderSize(0);
	legSP2EPeta->SetTextFont(43);
	legSP2EPeta->SetTextSize(24);

	legSP2EPeta->AddEntry(gr_pA_RatioEta_p[3], "pPb v_{2}{SP}/v_{2}{EP} p-going EP", "p");
	legSP2EPeta->AddEntry(gr_pA_RatioEta_Pb[3], "pPb v_{2}{SP}/v_{2}{EP} Pb-going EP", "p");
	legSP2EPeta->AddEntry(gr_AA_RatioEta_p[3], "PbPb v_{2}{SP}/v_{2}{EP} HF+ EP", "p");
	legSP2EPeta->AddEntry(gr_AA_RatioEta_Pb[3], "PbPb v_{2}{SP}/v_{2}{EP} HF- EP", "p");
	legSP2EPeta->Draw();



	cT->SaveAs("EP2SP_eta.pdf");
	cT->SaveAs("EP2SP_eta_C.C");



}
