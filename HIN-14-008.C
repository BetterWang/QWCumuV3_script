{
	TFile *fnormv2 = new TFile("txt/HIN-14-008/Fig5_v2_lab_0724.root");
	TFile *fratiov2 = new TFile("txt/HIN-14-008/Fig6_v2_ratio_0724.root");

	TGraphErrors * gr_norm_p = (TGraphErrors*) fnormv2->Get("grOrig_ratio_p");
	TGraphErrors * gr_norm_Pb = (TGraphErrors*) fnormv2->Get("grOrig_ratio_Pb");
	TGraphErrors * gr_norm_sys_p = (TGraphErrors*) fnormv2->Get("gr_ratio_p_sys");
	TGraphErrors * gr_norm_sys_Pb = (TGraphErrors*) fnormv2->Get("gr_ratio_Pb_sys");

	TGraphErrors * gr_norm_p_sub = (TGraphErrors*) fnormv2->Get("gr_ratio_p");
	TGraphErrors * gr_norm_Pb_sub = (TGraphErrors*) fnormv2->Get("gr_ratio_Pb");

	TGraphErrors * gr_ratio = (TGraphErrors*) fratiov2->Get("gr_ratio_Pb_half");
	TGraphErrors * gr_ratio_sys = (TGraphErrors*) fratiov2->Get("gr_ratio_Pb_half_sys");

	TMultiGraph * mgr_norm = new TMultiGraph();
	TMultiGraph * mgr_norm_sub = new TMultiGraph();

	mgr_norm->Add(gr_norm_sys_p, "[]2");
	mgr_norm->Add(gr_norm_sys_Pb, "[]2");
	mgr_norm->Add(gr_norm_p, "p");
	mgr_norm->Add(gr_norm_Pb, "p");

	mgr_norm_sub->Add(gr_norm_p_sub, "p");
	mgr_norm_sub->Add(gr_norm_Pb_sub, "p");

	TMultiGraph * mgr_ratio = new TMultiGraph();

//	mgr_ratio->Add(gr_ratio_sys, "F");
	mgr_ratio->Add(gr_ratio, "p");
}
