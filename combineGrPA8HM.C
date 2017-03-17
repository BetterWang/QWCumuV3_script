#include "TGraphErrors.h"
#include "label.h"
#include "noff.h"

typedef struct
{
	TGraphErrors * grVn2;
	TGraphErrors * grVn2Gap;
	TGraphErrors * grVn4;
	TGraphErrors * grVn6;
	TGraphErrors * grVn8;

	TGraphErrors * grCn2;
	TGraphErrors * grCn2Gap;
	TGraphErrors * grCn4;
	TGraphErrors * grCn6;
	TGraphErrors * grCn8;
} VnGraph;

void getGraph(TFile * f, VnGraph &gr, int n)
{
	gr.grVn2Gap = (TGraphErrors*) f->Get(Form("gr_vnCentGapC_%i", n));
	gr.grVn2 = (TGraphErrors*) f->Get(Form("gr_vnCentC_%i_0", n));
	gr.grVn4 = (TGraphErrors*) f->Get(Form("gr_vnCentC_%i_1", n));
	gr.grVn6 = (TGraphErrors*) f->Get(Form("gr_vnCentC_%i_2", n));
	gr.grVn8 = (TGraphErrors*) f->Get(Form("gr_vnCentC_%i_3", n));

	gr.grCn2Gap = (TGraphErrors*) f->Get(Form("gr_CnCentGapC_%i", n));
	gr.grCn2 = (TGraphErrors*) f->Get(Form("gr_CnCentC_%i_0", n));
	gr.grCn4 = (TGraphErrors*) f->Get(Form("gr_CnCentC_%i_1", n));
	gr.grCn6 = (TGraphErrors*) f->Get(Form("gr_CnCentC_%i_2", n));
	gr.grCn8 = (TGraphErrors*) f->Get(Form("gr_CnCentC_%i_3", n));
}

TGraphErrors* combineGr(TGraphErrors* gMB0, TGraphErrors* gHM0, TGraphErrors* gHM1, TGraphErrors* gHM7)
{
	double y[14], ey[14];
	for ( int i = 0; i < 6; i++ ) {
		y[i]  = gMB0->GetY() [i];
		ey[i] = gMB0->GetEY()[i];
	}
	for ( int i = 6; i < 8; i++ ) {
		y[i]  = gHM0->GetY() [i];
		ey[i] = gHM0->GetEY()[i];
	}
	for ( int i = 8; i < 10; i++ ) {
		y[i]  = gHM1->GetY() [i];
		ey[i] = gHM1->GetEY()[i];
	}
	for ( int i = 10; i < 14; i++ ) {
		y[i]  = gHM7->GetY() [i];
		ey[i] = gHM7->GetEY()[i];
	}
	TGraphErrors * ret = new TGraphErrors(14, CentPPbX4, y, 0, ey);
	ret->SetMarkerStyle(gMB0->GetMarkerStyle());
	ret->SetMarkerColor(gMB0->GetMarkerColor());
	ret->SetLineColor(gMB0->GetLineColor());
	return ret;
}

void combineGrPA8HM(int sMB = 16, int sHM0 = 8, int sHM1 = 9, int sHM7 = 15, int n = 2)
{
	TFile * fMB0 = new TFile(Form("%s/outGraph.root", ftxt[sMB]));
	TFile * fHM0 = new TFile(Form("%s/outGraph.root", ftxt[sHM0]));
	TFile * fHM1 = new TFile(Form("%s/outGraph.root", ftxt[sHM1]));
	TFile * fHM7 = new TFile(Form("%s/outGraph.root", ftxt[sHM7]));

	VnGraph grMB0;
	VnGraph grHM0;
	VnGraph grHM1;
	VnGraph grHM7;

	getGraph(fMB0, grMB0, n);
	getGraph(fHM0, grHM0, n);
	getGraph(fHM1, grHM1, n);
	getGraph(fHM7, grHM7, n);

	TGraphErrors * grMergedV2Gap = combineGr(grMB0.grVn2Gap, grHM0.grVn2Gap, grHM1.grVn2Gap, grHM7.grVn2Gap);
	TGraphErrors * grMergedV2 = combineGr(grMB0.grVn2, grHM0.grVn2, grHM1.grVn2, grHM7.grVn2);
	TGraphErrors * grMergedV4 = combineGr(grMB0.grVn4, grHM0.grVn4, grHM1.grVn4, grHM7.grVn4);
	TGraphErrors * grMergedV6 = combineGr(grMB0.grVn6, grHM0.grVn6, grHM1.grVn6, grHM7.grVn6);
	TGraphErrors * grMergedV8 = combineGr(grMB0.grVn8, grHM0.grVn8, grHM1.grVn8, grHM7.grVn8);

	TGraphErrors * grMergedC2Gap = combineGr(grMB0.grCn2Gap, grHM0.grCn2Gap, grHM1.grCn2Gap, grHM7.grCn2Gap);
	TGraphErrors * grMergedC2 = combineGr(grMB0.grCn2, grHM0.grCn2, grHM1.grCn2, grHM7.grCn2);
	TGraphErrors * grMergedC4 = combineGr(grMB0.grCn4, grHM0.grCn4, grHM1.grCn4, grHM7.grCn4);
	TGraphErrors * grMergedC6 = combineGr(grMB0.grCn6, grHM0.grCn6, grHM1.grCn6, grHM7.grCn6);
	TGraphErrors * grMergedC8 = combineGr(grMB0.grCn8, grHM0.grCn8, grHM1.grCn8, grHM7.grCn8);

	TFile * fsave = new TFile(Form("combined_%i_%i_%i_%i_%i.root", sMB, sHM0, sHM1, sHM7, n), "recreate");
	grMergedV2Gap->Write("grMergedV2Gap");
	grMergedV2->Write("grMergedV2");
	grMergedV4->Write("grMergedV4");
	grMergedV6->Write("grMergedV6");
	grMergedV8->Write("grMergedV8");

	grMergedC2Gap->Write("grMergedC2Gap");
	grMergedC2->Write("grMergedC2");
	grMergedC4->Write("grMergedC4");
	grMergedC6->Write("grMergedC6");
	grMergedC8->Write("grMergedC8");
}
