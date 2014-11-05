
{
#include "label.h"
	int s1 = 12; // black
	int s2 = 20; // green
	int s3 = 20; // cyan
	int s4 = 20; // red
	int s5 = 16; // blue

	bool b1 = 1;
	bool b2 = 0;
	bool b3 = 0;
	bool b4 = 1;
	bool b5 = 1;

//	int s2 = 20; // red pos/Pb side
//	int s3 = 16; // blue neg/p side

	TFile *f1 = new TFile(Form("%s/outGraph.root", ftxt[s1]));
	TFile *f2 = new TFile(Form("%s/outGraph.root", ftxt[s2]));
	TFile *f3 = new TFile(Form("%s/outGraph.root", ftxt[s3]));
	TFile *f4 = new TFile(Form("%s/outGraph.root", ftxt[s4]));
	TFile *f5 = new TFile(Form("%s/outGraph.root", ftxt[s5]));

//	string v22pt1, v24pt1, v26pt1, v28pt1, v22eta1, v24eta1, v26wta1, v28eta1;
//	string v22pt2, v24pt2, v26pt2, v28pt2, v22eta2, v24eta2, v26wta2, v28eta2;
//	string v22pt3, v24pt3, v26pt3, v28pt3, v22eta3, v24eta3, v26wta3, v28eta3;

	TGraphErrors * gr_v22_1 = (TGraphErrors*) f1->Get("gr_vnPtC_2_0_6");
	TGraphErrors * gr_v24_1 = (TGraphErrors*) f1->Get("gr_vnPtC_2_1_6");
	TGraphErrors * gr_v26_1 = (TGraphErrors*) f1->Get("gr_vnPtC_2_2_5");
	TGraphErrors * gr_v28_1 = (TGraphErrors*) f1->Get("gr_vnPtC_2_3_3");

	TGraphErrors * gr_v22_2 = (TGraphErrors*) f2->Get("gr_vnPtC_2_0_6");
	TGraphErrors * gr_v24_2 = (TGraphErrors*) f2->Get("gr_vnPtC_2_1_6");
	TGraphErrors * gr_v26_2 = (TGraphErrors*) f2->Get("gr_vnPtC_2_2_5");
	TGraphErrors * gr_v28_2 = (TGraphErrors*) f2->Get("gr_vnPtC_2_3_3");

	TGraphErrors * gr_v22_3 = (TGraphErrors*) f3->Get("gr_vnPtC_2_0_6");
	TGraphErrors * gr_v24_3 = (TGraphErrors*) f3->Get("gr_vnPtC_2_1_6");
	TGraphErrors * gr_v26_3 = (TGraphErrors*) f3->Get("gr_vnPtC_2_2_5");
	TGraphErrors * gr_v28_3 = (TGraphErrors*) f3->Get("gr_vnPtC_2_3_3");

	TGraphErrors * gr_v22_4 = (TGraphErrors*) f4->Get("gr_vnPtC_2_0_6");
	TGraphErrors * gr_v24_4 = (TGraphErrors*) f4->Get("gr_vnPtC_2_1_6");
	TGraphErrors * gr_v26_4 = (TGraphErrors*) f4->Get("gr_vnPtC_2_2_5");
	TGraphErrors * gr_v28_4 = (TGraphErrors*) f4->Get("gr_vnPtC_2_3_3");

	TGraphErrors * gr_v22_5 = (TGraphErrors*) f5->Get("gr_vnPtC_2_0_6");
	TGraphErrors * gr_v24_5 = (TGraphErrors*) f5->Get("gr_vnPtC_2_1_6");
	TGraphErrors * gr_v26_5 = (TGraphErrors*) f5->Get("gr_vnPtC_2_2_5");
	TGraphErrors * gr_v28_5 = (TGraphErrors*) f5->Get("gr_vnPtC_2_3_3");

	gr_v22_1->SetMarkerStyle(kFullCircle);
	gr_v22_1->SetMarkerColor(kBlack);
	gr_v22_1->SetLineColor(kBlack);
	gr_v22_2->SetMarkerStyle(kOpenCircle);
	gr_v22_2->SetMarkerColor(kGreen+1);
	gr_v22_2->SetLineColor(kGreen+1);
	gr_v22_3->SetMarkerStyle(kOpenCircle);
	gr_v22_3->SetMarkerColor(kCyan);
	gr_v22_3->SetLineColor(kCyan);
	gr_v22_4->SetMarkerStyle(kOpenCircle);
	gr_v22_4->SetMarkerColor(kRed);
	gr_v22_4->SetLineColor(kRed);
	gr_v22_5->SetMarkerStyle(kOpenCircle);
	gr_v22_5->SetMarkerColor(kBlue);
	gr_v22_5->SetLineColor(kBlue);

	gr_v24_1->SetMarkerStyle(kFullSquare);
	gr_v24_1->SetMarkerColor(kBlack);
	gr_v24_1->SetLineColor(kBlack);
	gr_v24_2->SetMarkerStyle(kOpenSquare);
	gr_v24_2->SetMarkerColor(kGreen+1);
	gr_v24_2->SetLineColor(kGreen+1);
	gr_v24_3->SetMarkerStyle(kOpenSquare);
	gr_v24_3->SetMarkerColor(kCyan);
	gr_v24_3->SetLineColor(kCyan);
	gr_v24_4->SetMarkerStyle(kOpenSquare);
	gr_v24_4->SetMarkerColor(kRed);
	gr_v24_4->SetLineColor(kRed);
	gr_v24_5->SetMarkerStyle(kOpenSquare);
	gr_v24_5->SetMarkerColor(kBlue);
	gr_v24_5->SetLineColor(kBlue);

	gr_v26_1->SetMarkerStyle(kFullCross);
	gr_v26_1->SetMarkerColor(kBlack);
	gr_v26_1->SetLineColor(kBlack);
	gr_v26_2->SetMarkerStyle(kOpenCross);
	gr_v26_2->SetMarkerColor(kGreen+1);
	gr_v26_2->SetLineColor(kGreen+1);
	gr_v26_3->SetMarkerStyle(kOpenCross);
	gr_v26_3->SetMarkerColor(kCyan);
	gr_v26_3->SetLineColor(kCyan);
	gr_v26_4->SetMarkerStyle(kOpenCross);
	gr_v26_4->SetMarkerColor(kRed);
	gr_v26_4->SetLineColor(kRed);
	gr_v26_5->SetMarkerStyle(kOpenCross);
	gr_v26_5->SetMarkerColor(kBlue);
	gr_v26_5->SetLineColor(kBlue);

	gr_v28_1->SetMarkerStyle(kFullDiamond);
	gr_v28_1->SetMarkerColor(kBlack);
	gr_v28_1->SetLineColor(kBlack);
	gr_v28_2->SetMarkerStyle(kOpenDiamond);
	gr_v28_2->SetMarkerColor(kGreen+1);
	gr_v28_2->SetLineColor(kGreen+1);
	gr_v28_3->SetMarkerStyle(kOpenDiamond);
	gr_v28_3->SetMarkerColor(kCyan);
	gr_v28_3->SetLineColor(kCyan);
	gr_v28_4->SetMarkerStyle(kOpenDiamond);
	gr_v28_4->SetMarkerColor(kRed);
	gr_v28_4->SetLineColor(kRed);
	gr_v28_5->SetMarkerStyle(kOpenDiamond);
	gr_v28_5->SetMarkerColor(kBlue);
	gr_v28_5->SetLineColor(kBlue);


#include "../../style.h"
	SetStyle();
	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 12, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");

	hframe_pt->Draw();
	if ( b1 ) gr_v22_1->Draw("Psame");
	if ( b2 ) gr_v22_2->Draw("Psame");
	if ( b3 ) gr_v22_3->Draw("Psame");
	if ( b4 ) gr_v22_4->Draw("Psame");
	if ( b5 ) gr_v22_5->Draw("Psame");
	cT->SaveAs(Form("compV22_%i_%i_%i_%i_%i.pdf", s1, s2, s3, s4, s5));

	hframe_pt->Draw();
	if ( b1 ) gr_v24_1->Draw("Psame");
	if ( b2 ) gr_v24_2->Draw("Psame");
	if ( b3 ) gr_v24_3->Draw("Psame");
	if ( b4 ) gr_v24_4->Draw("Psame");
	if ( b5 ) gr_v24_5->Draw("Psame");
	cT->SaveAs(Form("compV24_%i_%i_%i_%i_%i.pdf", s1, s2, s3, s4, s5));

	hframe_pt->Draw();
	if ( b1 ) gr_v26_1->Draw("Psame");
	if ( b2 ) gr_v26_2->Draw("Psame");
	if ( b3 ) gr_v26_3->Draw("Psame");
	if ( b4 ) gr_v26_4->Draw("Psame");
	if ( b5 ) gr_v26_5->Draw("Psame");
	cT->SaveAs(Form("compV26_%i_%i_%i_%i_%i.pdf", s1, s2, s3, s4, s5));

	hframe_pt->Draw();
	if ( b1 ) gr_v28_1->Draw("Psame");
	if ( b2 ) gr_v28_2->Draw("Psame");
	if ( b3 ) gr_v28_3->Draw("Psame");
	if ( b4 ) gr_v28_4->Draw("Psame");
	if ( b5 ) gr_v28_5->Draw("Psame");
	cT->SaveAs(Form("compV28_%i_%i_%i_%i_%i.pdf", s1, s2, s3, s4, s5));


}
