
{
#include "label.h"
//	int s1 = 12; // black
//	int s2 = 12; // green
//	int s3 = 12; // cyan
//	int s4 = 114; // red
//	int s5 = 118; // blue

	int s1 = 109; // black
	int s2 = 109; // green
	int s3 = 109; // cyan
	int s4 = 127; // red
	int s5 = 128; // blue

	int cent4 = 4;
	// 7 = 120 - 150;
	// 6 = 150 - 185;
	// 5 = 185 - 220;
	// 4 = 220 - 260;
	int cent6 = 6;
	int cent8 = 5;
	if ( cent4 == 6 ) {
		cent6 = 5;
		cent8 = 4;
	}
	if ( cent4 == 5 ) {
		cent6 = 4;
		cent8 = 3;
	}
	if ( cent4 == 4 ) {
		cent6 = 3;
		cent8 = 2;
	}

	bool b1 = 1;
	bool b2 = 0;
	bool b3 = 0;
	bool b4 = 1;
	bool b5 = 1;

	bool bfit = 0;
	bool bfit2 = 0;

	TF1 *finputv2 = new TF1("finputv2", "0.165646*exp(-( (x-2.64741)/1.36298 + exp( -(x-2.64741)/1.36298 ) )/2.)", 0.2, 15);
	TF1 *finputv2D2 = new TF1("finputv2D2", "0.5*0.165646*exp(-( (x-2.64741)/1.36298 + exp( -(x-2.64741)/1.36298 ) )/2.)", 0.2, 15);
	finputv2D2->SetLineStyle(kDashed);
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

	TGraphErrors * gr_v22_1 = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_0_%i", cent4));
	TGraphErrors * gr_v24_1 = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_1_%i", cent4));
	TGraphErrors * gr_v26_1 = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_2_%i", cent6));
	TGraphErrors * gr_v28_1 = (TGraphErrors*) f1->Get(Form("gr_vnPtC_2_3_%i", cent8));

	TGraphErrors * gr_v22_2 = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_0_%i", cent4));
	TGraphErrors * gr_v24_2 = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_1_%i", cent4));
	TGraphErrors * gr_v26_2 = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_2_%i", cent6));
	TGraphErrors * gr_v28_2 = (TGraphErrors*) f2->Get(Form("gr_vnPtC_2_3_%i", cent8));

	TGraphErrors * gr_v22_3 = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_0_%i", cent4));
	TGraphErrors * gr_v24_3 = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_1_%i", cent4));
	TGraphErrors * gr_v26_3 = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_2_%i", cent6));
	TGraphErrors * gr_v28_3 = (TGraphErrors*) f3->Get(Form("gr_vnPtC_2_3_%i", cent8));

	TGraphErrors * gr_v22_4 = (TGraphErrors*) f4->Get(Form("gr_vnPtC_2_0_%i", cent4));
	TGraphErrors * gr_v24_4 = (TGraphErrors*) f4->Get(Form("gr_vnPtC_2_1_%i", cent4));
	TGraphErrors * gr_v26_4 = (TGraphErrors*) f4->Get(Form("gr_vnPtC_2_2_%i", cent6));
	TGraphErrors * gr_v28_4 = (TGraphErrors*) f4->Get(Form("gr_vnPtC_2_3_%i", cent8));

	TGraphErrors * gr_v22_5 = (TGraphErrors*) f5->Get(Form("gr_vnPtC_2_0_%i", cent4));
	TGraphErrors * gr_v24_5 = (TGraphErrors*) f5->Get(Form("gr_vnPtC_2_1_%i", cent4));
	TGraphErrors * gr_v26_5 = (TGraphErrors*) f5->Get(Form("gr_vnPtC_2_2_%i", cent6));
	TGraphErrors * gr_v28_5 = (TGraphErrors*) f5->Get(Form("gr_vnPtC_2_3_%i", cent8));


	TGraphErrors * gr_v22eta_1 = (TGraphErrors*) f1->Get(Form("gr_vnEtaC_2_0_%i", cent4));
	TGraphErrors * gr_v24eta_1 = (TGraphErrors*) f1->Get(Form("gr_vnEtaC_2_1_%i", cent4));
	TGraphErrors * gr_v26eta_1 = (TGraphErrors*) f1->Get(Form("gr_vnEtaC_2_2_%i", cent6));
	TGraphErrors * gr_v28eta_1 = (TGraphErrors*) f1->Get(Form("gr_vnEtaC_2_3_%i", cent8));

	TGraphErrors * gr_v22eta_2 = (TGraphErrors*) f2->Get(Form("gr_vnEtaC_2_0_%i", cent4));
	TGraphErrors * gr_v24eta_2 = (TGraphErrors*) f2->Get(Form("gr_vnEtaC_2_1_%i", cent4));
	TGraphErrors * gr_v26eta_2 = (TGraphErrors*) f2->Get(Form("gr_vnEtaC_2_2_%i", cent6));
	TGraphErrors * gr_v28eta_2 = (TGraphErrors*) f2->Get(Form("gr_vnEtaC_2_3_%i", cent8));

	TGraphErrors * gr_v22eta_3 = (TGraphErrors*) f3->Get(Form("gr_vnEtaC_2_0_%i", cent4));
	TGraphErrors * gr_v24eta_3 = (TGraphErrors*) f3->Get(Form("gr_vnEtaC_2_1_%i", cent4));
	TGraphErrors * gr_v26eta_3 = (TGraphErrors*) f3->Get(Form("gr_vnEtaC_2_2_%i", cent6));
	TGraphErrors * gr_v28eta_3 = (TGraphErrors*) f3->Get(Form("gr_vnEtaC_2_3_%i", cent8));

	TGraphErrors * gr_v22eta_4 = (TGraphErrors*) f4->Get(Form("gr_vnEtaC_2_0_%i", cent4));
	TGraphErrors * gr_v24eta_4 = (TGraphErrors*) f4->Get(Form("gr_vnEtaC_2_1_%i", cent4));
	TGraphErrors * gr_v26eta_4 = (TGraphErrors*) f4->Get(Form("gr_vnEtaC_2_2_%i", cent6));
	TGraphErrors * gr_v28eta_4 = (TGraphErrors*) f4->Get(Form("gr_vnEtaC_2_3_%i", cent8));

	TGraphErrors * gr_v22eta_5 = (TGraphErrors*) f5->Get(Form("gr_vnEtaC_2_0_%i", cent4));
	TGraphErrors * gr_v24eta_5 = (TGraphErrors*) f5->Get(Form("gr_vnEtaC_2_1_%i", cent4));
	TGraphErrors * gr_v26eta_5 = (TGraphErrors*) f5->Get(Form("gr_vnEtaC_2_2_%i", cent6));
	TGraphErrors * gr_v28eta_5 = (TGraphErrors*) f5->Get(Form("gr_vnEtaC_2_3_%i", cent8));

	gr_v22_1->SetMarkerStyle(kFullCircle);
	gr_v22_1->SetMarkerColor(kBlack);
	gr_v22_1->SetLineColor(kBlack);
	gr_v22_2->SetMarkerStyle(kFullCircle);
	gr_v22_2->SetMarkerColor(kGreen+1);
	gr_v22_2->SetLineColor(kGreen+1);
	gr_v22_3->SetMarkerStyle(kFullCircle);
	gr_v22_3->SetMarkerColor(kCyan);
	gr_v22_3->SetLineColor(kCyan);
	gr_v22_4->SetMarkerStyle(kFullCircle);
	gr_v22_4->SetMarkerColor(kRed);
	gr_v22_4->SetLineColor(kRed);
	gr_v22_5->SetMarkerStyle(kFullCircle);
	gr_v22_5->SetMarkerColor(kBlue);
	gr_v22_5->SetLineColor(kBlue);

	gr_v24_1->SetMarkerStyle(kFullSquare);
	gr_v24_1->SetMarkerColor(kBlack);
	gr_v24_1->SetLineColor(kBlack);
	gr_v24_2->SetMarkerStyle(kFullSquare);
	gr_v24_2->SetMarkerColor(kGreen+1);
	gr_v24_2->SetLineColor(kGreen+1);
	gr_v24_3->SetMarkerStyle(kFullSquare);
	gr_v24_3->SetMarkerColor(kCyan);
	gr_v24_3->SetLineColor(kCyan);
	gr_v24_4->SetMarkerStyle(kFullSquare);
	gr_v24_4->SetMarkerColor(kRed);
	gr_v24_4->SetLineColor(kRed);
	gr_v24_5->SetMarkerStyle(kFullSquare);
	gr_v24_5->SetMarkerColor(kBlue);
	gr_v24_5->SetLineColor(kBlue);

	gr_v26_1->SetMarkerStyle(kFullCross);
	gr_v26_1->SetMarkerColor(kBlack);
	gr_v26_1->SetLineColor(kBlack);
	gr_v26_2->SetMarkerStyle(kFullCross);
	gr_v26_2->SetMarkerColor(kGreen+1);
	gr_v26_2->SetLineColor(kGreen+1);
	gr_v26_3->SetMarkerStyle(kFullCross);
	gr_v26_3->SetMarkerColor(kCyan);
	gr_v26_3->SetLineColor(kCyan);
	gr_v26_4->SetMarkerStyle(kFullCross);
	gr_v26_4->SetMarkerColor(kRed);
	gr_v26_4->SetLineColor(kRed);
	gr_v26_5->SetMarkerStyle(kFullCross);
	gr_v26_5->SetMarkerColor(kBlue);
	gr_v26_5->SetLineColor(kBlue);

	gr_v28_1->SetMarkerStyle(kFullDiamond);
	gr_v28_1->SetMarkerColor(kBlack);
	gr_v28_1->SetLineColor(kBlack);
	gr_v28_2->SetMarkerStyle(kFullDiamond);
	gr_v28_2->SetMarkerColor(kGreen+1);
	gr_v28_2->SetLineColor(kGreen+1);
	gr_v28_3->SetMarkerStyle(kFullDiamond);
	gr_v28_3->SetMarkerColor(kCyan);
	gr_v28_3->SetLineColor(kCyan);
	gr_v28_4->SetMarkerStyle(kFullDiamond);
	gr_v28_4->SetMarkerColor(kRed);
	gr_v28_4->SetLineColor(kRed);
	gr_v28_5->SetMarkerStyle(kFullDiamond);
	gr_v28_5->SetMarkerColor(kBlue);
	gr_v28_5->SetLineColor(kBlue);


	gr_v22eta_1->SetMarkerStyle(kFullCircle);
	gr_v22eta_1->SetMarkerColor(kBlack);
	gr_v22eta_1->SetLineColor(kBlack);
	gr_v22eta_2->SetMarkerStyle(kFullCircle);
	gr_v22eta_2->SetMarkerColor(kGreen+1);
	gr_v22eta_2->SetLineColor(kGreen+1);
	gr_v22eta_3->SetMarkerStyle(kFullCircle);
	gr_v22eta_3->SetMarkerColor(kCyan);
	gr_v22eta_3->SetLineColor(kCyan);
	gr_v22eta_4->SetMarkerStyle(kFullCircle);
	gr_v22eta_4->SetMarkerColor(kRed);
	gr_v22eta_4->SetLineColor(kRed);
	gr_v22eta_5->SetMarkerStyle(kFullCircle);
	gr_v22eta_5->SetMarkerColor(kBlue);
	gr_v22eta_5->SetLineColor(kBlue);

	gr_v24eta_1->SetMarkerStyle(kFullSquare);
	gr_v24eta_1->SetMarkerColor(kBlack);
	gr_v24eta_1->SetLineColor(kBlack);
	gr_v24eta_2->SetMarkerStyle(kFullSquare);
	gr_v24eta_2->SetMarkerColor(kGreen+1);
	gr_v24eta_2->SetLineColor(kGreen+1);
	gr_v24eta_3->SetMarkerStyle(kFullSquare);
	gr_v24eta_3->SetMarkerColor(kCyan);
	gr_v24eta_3->SetLineColor(kCyan);
	gr_v24eta_4->SetMarkerStyle(kFullSquare);
	gr_v24eta_4->SetMarkerColor(kRed);
	gr_v24eta_4->SetLineColor(kRed);
	gr_v24eta_5->SetMarkerStyle(kFullSquare);
	gr_v24eta_5->SetMarkerColor(kBlue);
	gr_v24eta_5->SetLineColor(kBlue);

	gr_v26eta_1->SetMarkerStyle(kFullCross);
	gr_v26eta_1->SetMarkerColor(kBlack);
	gr_v26eta_1->SetLineColor(kBlack);
	gr_v26eta_2->SetMarkerStyle(kFullCross);
	gr_v26eta_2->SetMarkerColor(kGreen+1);
	gr_v26eta_2->SetLineColor(kGreen+1);
	gr_v26eta_3->SetMarkerStyle(kFullCross);
	gr_v26eta_3->SetMarkerColor(kCyan);
	gr_v26eta_3->SetLineColor(kCyan);
	gr_v26eta_4->SetMarkerStyle(kFullCross);
	gr_v26eta_4->SetMarkerColor(kRed);
	gr_v26eta_4->SetLineColor(kRed);
	gr_v26eta_5->SetMarkerStyle(kFullCross);
	gr_v26eta_5->SetMarkerColor(kBlue);
	gr_v26eta_5->SetLineColor(kBlue);

	gr_v28eta_1->SetMarkerStyle(kFullDiamond);
	gr_v28eta_1->SetMarkerColor(kBlack);
	gr_v28eta_1->SetLineColor(kBlack);
	gr_v28eta_2->SetMarkerStyle(kFullDiamond);
	gr_v28eta_2->SetMarkerColor(kGreen+1);
	gr_v28eta_2->SetLineColor(kGreen+1);
	gr_v28eta_3->SetMarkerStyle(kFullDiamond);
	gr_v28eta_3->SetMarkerColor(kCyan);
	gr_v28eta_3->SetLineColor(kCyan);
	gr_v28eta_4->SetMarkerStyle(kFullDiamond);
	gr_v28eta_4->SetMarkerColor(kRed);
	gr_v28eta_4->SetLineColor(kRed);
	gr_v28eta_5->SetMarkerStyle(kFullDiamond);
	gr_v28eta_5->SetMarkerColor(kBlue);
	gr_v28eta_5->SetLineColor(kBlue);


#include "../../style.h"
	SetStyle();
	TCanvas * cT = MakeCanvas("cT", "cT", 600, 500);

	TH2D * hframe_pt = new TH2D("hframe_pt", "", 1, 0, 5.9, 1, 0, 0.35);
	InitHist(hframe_pt, "p_{T} (GeV/c)", "v_{2}");

	hframe_pt->Draw();
	if ( b1 ) gr_v22_1->Draw("Psame");
	if ( b2 ) gr_v22_2->Draw("Psame");
	if ( b3 ) gr_v22_3->Draw("Psame");
	if ( b4 ) gr_v22_4->Draw("Psame");
	if ( b5 ) gr_v22_5->Draw("Psame");
	if ( bfit ) finputv2->Draw("same");
	if ( bfit2 ) finputv2D2->Draw("same");
	hframe_pt->GetYaxis()->SetTitle("v_{2}{2}");
	cT->SaveAs(Form("compV22_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_pt->Draw();
	if ( b1 ) gr_v24_1->Draw("Psame");
	if ( b2 ) gr_v24_2->Draw("Psame");
	if ( b3 ) gr_v24_3->Draw("Psame");
	if ( b4 ) gr_v24_4->Draw("Psame");
	if ( b5 ) gr_v24_5->Draw("Psame");
	if ( bfit ) finputv2->Draw("same");
	if ( bfit2 ) finputv2D2->Draw("same");
	hframe_pt->GetYaxis()->SetTitle("v_{2}{4}");
	cT->SaveAs(Form("compV24_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_pt->Draw();
	if ( b1 ) gr_v26_1->Draw("Psame");
	if ( b2 ) gr_v26_2->Draw("Psame");
	if ( b3 ) gr_v26_3->Draw("Psame");
	if ( b4 ) gr_v26_4->Draw("Psame");
	if ( b5 ) gr_v26_5->Draw("Psame");
	if ( bfit ) finputv2->Draw("same");
	if ( bfit2 ) finputv2D2->Draw("same");
	hframe_pt->GetYaxis()->SetTitle("v_{2}{6}");
	cT->SaveAs(Form("compV26_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_pt->Draw();
	if ( b1 ) gr_v28_1->Draw("Psame");
	if ( b2 ) gr_v28_2->Draw("Psame");
	if ( b3 ) gr_v28_3->Draw("Psame");
	if ( b4 ) gr_v28_4->Draw("Psame");
	if ( b5 ) gr_v28_5->Draw("Psame");
	if ( bfit ) finputv2->Draw("same");
	if ( bfit2 ) finputv2D2->Draw("same");
	hframe_pt->GetYaxis()->SetTitle("v_{2}{8}");
	cT->SaveAs(Form("compV28_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));


	TH2D * hframe_eta = new TH2D("hframe_eta", "", 1, -2.5, 2.5, 1, 0, 0.15);
	InitHist(hframe_eta, "#eta", "v_{2}");

	hframe_eta->Draw();
	if ( b1 ) gr_v22eta_1->Draw("Psame");
	if ( b2 ) gr_v22eta_2->Draw("Psame");
	if ( b3 ) gr_v22eta_3->Draw("Psame");
	if ( b4 ) gr_v22eta_4->Draw("Psame");
	if ( b5 ) gr_v22eta_5->Draw("Psame");
	hframe_eta->GetYaxis()->SetTitle("v_{2}{2}");
	cT->SaveAs(Form("compV22eta_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_eta->Draw();
	if ( b1 ) gr_v24eta_1->Draw("Psame");
	if ( b2 ) gr_v24eta_2->Draw("Psame");
	if ( b3 ) gr_v24eta_3->Draw("Psame");
	if ( b4 ) gr_v24eta_4->Draw("Psame");
	if ( b5 ) gr_v24eta_5->Draw("Psame");
	hframe_eta->GetYaxis()->SetTitle("v_{2}{4}");
	cT->SaveAs(Form("compV24eta_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_eta->Draw();
	if ( b1 ) gr_v26eta_1->Draw("Psame");
	if ( b2 ) gr_v26eta_2->Draw("Psame");
	if ( b3 ) gr_v26eta_3->Draw("Psame");
	if ( b4 ) gr_v26eta_4->Draw("Psame");
	if ( b5 ) gr_v26eta_5->Draw("Psame");
	hframe_eta->GetYaxis()->SetTitle("v_{2}{6}");
	cT->SaveAs(Form("compV26eta_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_eta->Draw();
	if ( b1 ) gr_v28eta_1->Draw("Psame");
	if ( b2 ) gr_v28eta_2->Draw("Psame");
	if ( b3 ) gr_v28eta_3->Draw("Psame");
	if ( b4 ) gr_v28eta_4->Draw("Psame");
	if ( b5 ) gr_v28eta_5->Draw("Psame");
	hframe_eta->GetYaxis()->SetTitle("v_{2}{8}");
	cT->SaveAs(Form("compV28eta_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));


	double x[24], y[24], ey[24];
	for ( int i = 0; i < 24; ++i ) {
		x[i] = gr_v24eta_4->GetX()[i];
		y[i] = gr_v24eta_4->GetY()[i]/gr_v24eta_5->GetY()[i];
		ey[i] = y[i]*sqrt( (gr_v24eta_4->GetEY()[i]*gr_v24eta_4->GetEY()[i]/gr_v24eta_4->GetY()[i]/gr_v24eta_4->GetY()[i]) + (gr_v24eta_5->GetEY()[i]*gr_v24eta_5->GetEY()[i]/gr_v24eta_5->GetY()[i]/gr_v24eta_5->GetY()[i]) );
	}

	TGraphErrors * gr_v24eta_4r = new TGraphErrors(24, x, y, 0, ey);
	gr_v24eta_4r->SetMarkerStyle(kFullSquare);
	gr_v24eta_4r->SetMarkerColor(kRed);
	gr_v24eta_4r->SetLineColor(kRed);

	for ( int i = 0; i < 24; ++i ) {
		y[i] = gr_v26eta_4->GetY()[i]/gr_v26eta_5->GetY()[i];
		ey[i] = y[i]*sqrt( (gr_v26eta_4->GetEY()[i]*gr_v26eta_4->GetEY()[i]/gr_v26eta_4->GetY()[i]/gr_v26eta_4->GetY()[i]) + (gr_v26eta_5->GetEY()[i]*gr_v26eta_5->GetEY()[i]/gr_v26eta_5->GetY()[i]/gr_v26eta_5->GetY()[i]) );
	}

	TGraphErrors * gr_v26eta_4r = new TGraphErrors(24, x, y, 0, ey);
	gr_v26eta_4r->SetMarkerStyle(kFullCross);
	gr_v26eta_4r->SetMarkerColor(kRed);
	gr_v26eta_4r->SetLineColor(kRed);

	for ( int i = 0; i < 24; ++i ) {
		y[i] = gr_v28eta_4->GetY()[i]/gr_v28eta_5->GetY()[i];
		ey[i] = y[i]*sqrt( (gr_v28eta_4->GetEY()[i]*gr_v28eta_4->GetEY()[i]/gr_v28eta_4->GetY()[i]/gr_v28eta_4->GetY()[i]) + (gr_v28eta_5->GetEY()[i]*gr_v28eta_5->GetEY()[i]/gr_v28eta_5->GetY()[i]/gr_v28eta_5->GetY()[i]) );
	}

	TGraphErrors * gr_v28eta_4r = new TGraphErrors(24, x, y, 0, ey);
	gr_v28eta_4r->SetMarkerStyle(kFullDiamond);
	gr_v28eta_4r->SetMarkerColor(kRed);
	gr_v28eta_4r->SetLineColor(kRed);


	TH2D * hframe_etaratio = new TH2D("hframe_etaratio", "", 1, -2.5, 2.5, 1, 0, 1.);
	InitHist(hframe_etaratio, "#eta", "v_{2,pPb}/v_{2,PbPb}");

	hframe_etaratio->Draw();
	gr_v24eta_4r->Draw("Psame");
	cT->SaveAs(Form("compV24etar_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_etaratio->Draw();
	gr_v26eta_4r->Draw("Psame");
	cT->SaveAs(Form("compV26etar_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

	hframe_etaratio->Draw();
	gr_v28eta_4r->Draw("Psame");
	cT->SaveAs(Form("compV28etar_%i_%i_%i_%i_%i_%i.pdf", cent4, s1, s2, s3, s4, s5));

//	TFile * fsave = new TFile("graph.root","recreate");
//	gr_v22_1->SetName("gr_v22_1");
//	gr_v24_1->SetName("gr_v24_1");
//	gr_v26_1->SetName("gr_v26_1");
//	gr_v28_1->SetName("gr_v28_1");
//
//	gr_v22_4->SetName("gr_v22_4");
//	gr_v24_4->SetName("gr_v24_4");
//	gr_v26_4->SetName("gr_v26_4");
//	gr_v28_4->SetName("gr_v28_4");
//
//	gr_v22_5->SetName("gr_v22_5");
//	gr_v24_5->SetName("gr_v24_5");
//	gr_v26_5->SetName("gr_v26_5");
//	gr_v28_5->SetName("gr_v28_5");
//
//	gr_v22eta_1->SetName("gr_v22eta_1");
//	gr_v24eta_1->SetName("gr_v24eta_1");
//	gr_v26eta_1->SetName("gr_v26eta_1");
//	gr_v28eta_1->SetName("gr_v28eta_1");
//
//	gr_v22eta_4->SetName("gr_v22eta_4");
//	gr_v24eta_4->SetName("gr_v24eta_4");
//	gr_v26eta_4->SetName("gr_v26eta_4");
//	gr_v28eta_4->SetName("gr_v28eta_4");
//
//	gr_v22eta_5->SetName("gr_v22eta_5");
//	gr_v24eta_5->SetName("gr_v24eta_5");
//	gr_v26eta_5->SetName("gr_v26eta_5");
//	gr_v28eta_5->SetName("gr_v28eta_5");
//
//	gr_v22_1->Write();
//	gr_v24_1->Write();
//	gr_v26_1->Write();
//	gr_v28_1->Write();
//
//	gr_v22_4->Write();
//	gr_v24_4->Write();
//	gr_v26_4->Write();
//	gr_v28_4->Write();
//
//	gr_v22_5->Write();
//	gr_v24_5->Write();
//	gr_v26_5->Write();
//	gr_v28_5->Write();
//
//	gr_v22eta_1->Write();
//	gr_v24eta_1->Write();
//	gr_v26eta_1->Write();
//	gr_v28eta_1->Write();
//
//	gr_v22eta_4->Write();
//	gr_v24eta_4->Write();
//	gr_v26eta_4->Write();
//	gr_v28eta_4->Write();
//
//	gr_v22eta_5->Write();
//	gr_v24eta_5->Write();
//	gr_v26eta_5->Write();
//	gr_v28eta_5->Write();
}
