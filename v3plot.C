{
#include "style.h"

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

	TCanvas * cT = MakeCanvas("cTeta3", "cTeta3", 1600, 500);
	makeMultiPanelCanvas(cT, 4, 1, 0.0, 0., 0.15, 0.15, 0.01);

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

	gr_pA_eta3_de[7]->SetMarkerStyle(kFullSquare);
	gr_pA_eta3_de[6]->SetMarkerStyle(kFullSquare);
	gr_pA_eta3_de[5]->SetMarkerStyle(kFullSquare);
	gr_pA_eta3_de[4]->SetMarkerStyle(kFullSquare);
	gr_pA_eta3_de[3]->SetMarkerStyle(kFullSquare);

	gr_pA_eta3_de[7]->SetMarkerColor(kBlue);
	gr_pA_eta3_de[7]->SetLineColor(kBlue);
	gr_pA_eta3_de[6]->SetMarkerColor(kBlue);
	gr_pA_eta3_de[6]->SetLineColor(kBlue);
	gr_pA_eta3_de[5]->SetMarkerColor(kBlue);
	gr_pA_eta3_de[5]->SetLineColor(kBlue);
	gr_pA_eta3_de[4]->SetMarkerColor(kBlue);
	gr_pA_eta3_de[4]->SetLineColor(kBlue);
	gr_pA_eta3_de[3]->SetMarkerColor(kBlue);
	gr_pA_eta3_de[3]->SetLineColor(kBlue);



	gr_AA_eta3_de[7]->SetMarkerStyle(kFullCircle);
	gr_AA_eta3_de[6]->SetMarkerStyle(kFullCircle);
	gr_AA_eta3_de[5]->SetMarkerStyle(kFullCircle);
	gr_AA_eta3_de[4]->SetMarkerStyle(kFullCircle);
	gr_AA_eta3_de[3]->SetMarkerStyle(kFullCircle);

	gr_AA_eta3_de[7]->SetMarkerColor(kRed);
	gr_AA_eta3_de[7]->SetLineColor(kRed);
	gr_AA_eta3_de[6]->SetMarkerColor(kRed);
	gr_AA_eta3_de[6]->SetLineColor(kRed);
	gr_AA_eta3_de[5]->SetMarkerColor(kRed);
	gr_AA_eta3_de[5]->SetLineColor(kRed);
	gr_AA_eta3_de[4]->SetMarkerColor(kRed);
	gr_AA_eta3_de[4]->SetLineColor(kRed);
	gr_AA_eta3_de[3]->SetMarkerColor(kRed);
	gr_AA_eta3_de[3]->SetLineColor(kRed);

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

	gr_pA_eta_de[7]->SetMarkerStyle(kOpenSquare);
	gr_pA_eta_de[6]->SetMarkerStyle(kOpenSquare);
	gr_pA_eta_de[5]->SetMarkerStyle(kOpenSquare);
	gr_pA_eta_de[4]->SetMarkerStyle(kOpenSquare);
	gr_pA_eta_de[3]->SetMarkerStyle(kOpenSquare);

	gr_pA_eta_de[7]->SetMarkerColor(kBlue);
	gr_pA_eta_de[7]->SetLineColor(kBlue);
	gr_pA_eta_de[6]->SetMarkerColor(kBlue);
	gr_pA_eta_de[6]->SetLineColor(kBlue);
	gr_pA_eta_de[5]->SetMarkerColor(kBlue);
	gr_pA_eta_de[5]->SetLineColor(kBlue);
	gr_pA_eta_de[4]->SetMarkerColor(kBlue);
	gr_pA_eta_de[4]->SetLineColor(kBlue);
	gr_pA_eta_de[3]->SetMarkerColor(kBlue);
	gr_pA_eta_de[3]->SetLineColor(kBlue);



	gr_AA_eta_de[7]->SetMarkerStyle(kOpenCircle);
	gr_AA_eta_de[6]->SetMarkerStyle(kOpenCircle);
	gr_AA_eta_de[5]->SetMarkerStyle(kOpenCircle);
	gr_AA_eta_de[4]->SetMarkerStyle(kOpenCircle);
	gr_AA_eta_de[3]->SetMarkerStyle(kOpenCircle);

	gr_AA_eta_de[7]->SetMarkerColor(kRed);
	gr_AA_eta_de[7]->SetLineColor(kRed);
	gr_AA_eta_de[6]->SetMarkerColor(kRed);
	gr_AA_eta_de[6]->SetLineColor(kRed);
	gr_AA_eta_de[5]->SetMarkerColor(kRed);
	gr_AA_eta_de[5]->SetLineColor(kRed);
	gr_AA_eta_de[4]->SetMarkerColor(kRed);
	gr_AA_eta_de[4]->SetLineColor(kRed);
	gr_AA_eta_de[3]->SetMarkerColor(kRed);
	gr_AA_eta_de[3]->SetLineColor(kRed);


	cT->cd(1);
	hframe_eta3->Draw();

	gr_pA_eta3_de[7]->Draw("Psame");
	gr_AA_eta3_de[7]->Draw("Psame");
	gr_pA_eta_de[7]->Draw("Psame");
	gr_AA_eta_de[7]->Draw("Psame");

	cT->cd(2);
	hframe_eta3->Draw();

	gr_pA_eta3_de[6]->Draw("Psame");
	gr_AA_eta3_de[6]->Draw("Psame");
	gr_pA_eta_de[6]->Draw("Psame");
	gr_AA_eta_de[6]->Draw("Psame");

	cT->cd(3);
	hframe_eta3->Draw();

	gr_pA_eta3_de[5]->Draw("Psame");
	gr_AA_eta3_de[5]->Draw("Psame");
	gr_pA_eta_de[5]->Draw("Psame");
	gr_AA_eta_de[5]->Draw("Psame");

	cT->cd(4);
	hframe_eta3->Draw();

	gr_pA_eta3_de[4]->Draw("Psame");
	gr_AA_eta3_de[4]->Draw("Psame");
	gr_pA_eta_de[4]->Draw("Psame");
	gr_AA_eta_de[4]->Draw("Psame");

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);


	cT->cd(1);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{120 #leq N_{trk}^{offline} < 150}");
	cT->cd(2);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{150 #leq N_{trk}^{offline} < 185}");
	cT->cd(3);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{185 #leq N_{trk}^{offline} < 220}");
	cT->cd(4);
	latex.DrawLatexNDC(0.40, 0.44, "#bf{220 #leq N_{trk}^{offline} < 260}");

	cT->cd(2);
	TLegend * legEtaEP2 = new TLegend(0.05, 0.8, 0.3, 0.97);
	legEtaEP2->SetFillColor(kWhite);
	legEtaEP2->SetBorderSize(0);
	legEtaEP2->SetTextFont(43);
	legEtaEP2->SetTextSize(24);

	legEtaEP2->AddEntry(gr_pA_eta_de[4], "v_{2}{EP,#eta_{C}=#eta_{POI}} pPb", "p");
	legEtaEP2->AddEntry(gr_AA_eta_de[4], "v_{2}{EP,#eta_{C}=#eta_{POI}} PbPb", "p");

	legEtaEP2->Draw();

	cT->cd(1);
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{#bf{CMS}}{Preliminary}");

	cT->cd(3);
	TLegend * legEtaEP3 = new TLegend(0.05, 0.8, 0.3, 0.97);
	legEtaEP3->SetFillColor(kWhite);
	legEtaEP3->SetBorderSize(0);
	legEtaEP3->SetTextFont(43);
	legEtaEP3->SetTextSize(24);

	legEtaEP3->AddEntry(gr_pA_eta3_de[4], "v_{3}{EP,#eta_{C}=#eta_{POI}} pPb", "p");
	legEtaEP3->AddEntry(gr_AA_eta3_de[4], "v_{3}{EP,#eta_{C}=#eta_{POI}} PbPb", "p");

	legEtaEP3->Draw();

	cT->cd(4);
	latex.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");


	cT->SaveAs("eta3.pdf");
	cT->SaveAs("eta3_C.C");
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
	latex.DrawLatexNDC(0.20, 0.94, "0.3 < p_{T} < 3.0 GeV/c");


	cT->SaveAs("Fluct.pdf");
	cT->SaveAs("Fluct_C.C");

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
