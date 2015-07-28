// making plot
#include "label.h"
#include "noff.h"
#include "style.h"

void makeplot()
{

//	int s1 = 109; // PbPb
	int s1 = 139; // pPb
//	int s1 = 143; // pPb
//	int s1 = 12; // pPb
	int s2 = 1; // 1: C, 0:V

	int bPbPb = 0;

	int sN;

	if ( s1 == 109 ) bPbPb = 1;


	TFile *f = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	gROOT->Macro("HIN-13-002.C");


	TGraphErrors * gr_vnPt[7][4][20];
	TGraphErrors * gr_vnEta[7][4][20];

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
					if ( gr_vnPt[n][np][c] ) gr_vnPt[n][np][c]->SetMarkerColor(kBlack);
					if ( gr_vnPt[n][np][c] ) gr_vnPt[n][np][c]->SetLineColor(kBlack);
					if ( gr_vnEta[n][np][c] ) gr_vnEta[n][np][c]->SetMarkerColor(kBlack);
					if ( gr_vnEta[n][np][c] ) gr_vnEta[n][np][c]->SetLineColor(kBlack);
				}
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
	gr_vnPt[2][0][7]->Draw("Psame");
	gr_vnPt[2][1][7]->Draw("Psame");
	gr_vnPt[2][2][6]->Draw("Psame");
	gr_vnPt[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][6]->Draw();
	else mgr_HIN13002_pPbPt[2][0][6]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][6]->Draw();
	else mgr_HIN13002_pPbPt[2][1][6]->Draw();
	gr_vnPt[2][0][6]->Draw("Psame");
	gr_vnPt[2][1][6]->Draw("Psame");
	gr_vnPt[2][2][5]->Draw("Psame");
	gr_vnPt[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][5]->Draw();
	else mgr_HIN13002_pPbPt[2][0][5]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][5]->Draw();
	else mgr_HIN13002_pPbPt[2][1][5]->Draw();
	gr_vnPt[2][0][5]->Draw("Psame");
	gr_vnPt[2][1][5]->Draw("Psame");
	gr_vnPt[2][2][4]->Draw("Psame");
	gr_vnPt[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_pt->Draw();
	if ( bPbPb) mgr_HIN13002_PbPbPt[2][0][4]->Draw();
	else mgr_HIN13002_pPbPt[2][0][4]->Draw();
	if ( bPbPb ) mgr_HIN13002_PbPbPt[2][1][4]->Draw();
	else mgr_HIN13002_pPbPt[2][1][4]->Draw();
	gr_vnPt[2][0][4]->Draw("Psame");
	gr_vnPt[2][1][4]->Draw("Psame");
	gr_vnPt[2][2][3]->Draw("Psame");
	gr_vnPt[2][3][2]->Draw("Psame");

	TLegend * legPt1 = new TLegend(0.1, 0.8, 0.7, 0.95);
	legPt1->SetFillColor(kWhite);
	legPt1->SetBorderSize(0);
	legPt1->AddEntry(gr_HIN_13_002_PbPbv22pt5, "HIN-13-002 v_{2}{2}", "p");
	legPt1->AddEntry(gr_HIN_13_002_PbPbv24pt5, "HIN-13-002 v_{2}{4}", "p");

	TLegend * legPt2 = new TLegend(0.05, 0.65, 0.3, 0.97);
	legPt2->SetFillColor(kWhite);
	legPt2->SetBorderSize(0);
	legPt2->AddEntry(gr_vnPt[2][0][4], "v_{2}{2}", "p");
	legPt2->AddEntry(gr_vnPt[2][1][4], "v_{2}{4}", "p");
	legPt2->AddEntry(gr_vnPt[2][2][4], "v_{2}{6}", "p");
	legPt2->AddEntry(gr_vnPt[2][3][4], "v_{2}{8}", "p");

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(24);
	latex.SetTextAlign(13);

	cT->cd(1);
	if (bPbPb) latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}");
	else latex.DrawLatexNDC(0.20, 0.94, "#bf{CMS pPb #sqrt{s_{NN}} = 5.02 TeV}");

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
	gr_vnEta[2][0][7]->Draw("Psame");
	gr_vnEta[2][1][7]->Draw("Psame");
	gr_vnEta[2][2][6]->Draw("Psame");
	gr_vnEta[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_eta->Draw();
	gr_vnEta[2][0][6]->Draw("Psame");
	gr_vnEta[2][1][6]->Draw("Psame");
	gr_vnEta[2][2][5]->Draw("Psame");
	gr_vnEta[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_eta->Draw();
	gr_vnEta[2][0][5]->Draw("Psame");
	gr_vnEta[2][1][5]->Draw("Psame");
	gr_vnEta[2][2][4]->Draw("Psame");
	gr_vnEta[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_eta->Draw();
	gr_vnEta[2][0][4]->Draw("Psame");
	gr_vnEta[2][1][4]->Draw("Psame");
	gr_vnEta[2][2][3]->Draw("Psame");
	gr_vnEta[2][3][2]->Draw("Psame");

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

	cT->SaveAs(Form("eta_%i.pdf", s1));

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
//	gr_ratio[2][2][6] = makeRatio(gr_vnEta[2][2][6]);
//	gr_ratio[2][3][5] = makeRatio(gr_vnEta[2][3][5]);

	gr_ratio[2][0][7]->Draw("Psame");
	gr_ratio[2][1][7]->Draw("Psame");
//	gr_ratio[2][2][6]->Draw("Psame");
//	gr_ratio[2][3][5]->Draw("Psame");

	cT->cd(2);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][6] = makeRatio(gr_vnEta[2][0][6]);
	gr_ratio[2][1][6] = makeRatio(gr_vnEta[2][1][6]);
//	gr_ratio[2][2][5] = makeRatio(gr_vnEta[2][2][5]);
//	gr_ratio[2][3][4] = makeRatio(gr_vnEta[2][3][4]);

	gr_ratio[2][0][6]->Draw("Psame");
	gr_ratio[2][1][6]->Draw("Psame");
//	gr_ratio[2][2][5]->Draw("Psame");
//	gr_ratio[2][3][4]->Draw("Psame");

	cT->cd(3);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][5] = makeRatio(gr_vnEta[2][0][5]);
	gr_ratio[2][1][5] = makeRatio(gr_vnEta[2][1][5]);
//	gr_ratio[2][2][4] = makeRatio(gr_vnEta[2][2][4]);
//	gr_ratio[2][3][3] = makeRatio(gr_vnEta[2][3][3]);

	gr_ratio[2][0][5]->Draw("Psame");
	gr_ratio[2][1][5]->Draw("Psame");
//	gr_ratio[2][2][4]->Draw("Psame");
//	gr_ratio[2][3][3]->Draw("Psame");

	cT->cd(4);
	hframe_ratio->Draw();
	line->Draw();
	gr_ratio[2][0][4] = makeRatio(gr_vnEta[2][0][4]);
	gr_ratio[2][1][4] = makeRatio(gr_vnEta[2][1][4]);
//	gr_ratio[2][2][3] = makeRatio(gr_vnEta[2][2][3]);
//	gr_ratio[2][3][2] = makeRatio(gr_vnEta[2][3][2]);

	gr_ratio[2][0][4]->Draw("Psame");
	gr_ratio[2][1][4]->Draw("Psame");
//	gr_ratio[2][2][3]->Draw("Psame");
//	gr_ratio[2][3][2]->Draw("Psame");

	gROOT->Macro("HIN-14-008.C");
	mgr_ratio->Draw();

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
	legRatio->AddEntry(gr_ratio[2][0][4], "v_{2}^{Pb}{2}/v_{2}^{p}{2}", "p");
	legRatio->AddEntry(gr_ratio[2][1][4], "v_{2}^{Pb}{4}/v_{2}^{p}{4}", "p");
	cT->cd(3);
	legRatio->Draw();

	cT->SaveAs(Form("ratio_%i.pdf", s1));

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


}

TGraphErrors* makeRatio(TGraphErrors* gr)
{
	double ratio[12] = {};
	double eratio[12] = {};
	double x[12] = {};
	for ( int i = 0; i < 12; i++ ) {
		x[i] = gr->GetX()[i];
		ratio[i] = gr->GetY()[i] / gr->GetY()[23-i];
		eratio[i] = ratio[i]*sqrt((gr->GetEY()[23-i]/gr->GetY()[23-i])**2 + (gr->GetEY()[i]/gr->GetY()[i])**2);
	}
//	for ( int i = 0; i < 12; i++ ) {
//		cout << " x[" << i << "] = " << x[i] << "\t" << "ratio = " << ratio[i] << "\t\t" << "eratio = " << eratio[i] << endl;
//	}
	TGraphErrors * ret = new TGraphErrors(12, x, ratio, 0, eratio);
	ret->SetMarkerStyle(gr->GetMarkerStyle());
	ret->SetMarkerColor(gr->GetMarkerColor());
	ret->SetLineColor(gr->GetLineColor());
	return ret;
}
