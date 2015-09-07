{
	TFile * f20 = new TFile("txt/PionFlatPt_M200_rfp24_poi24/outGraph.root");
	TFile * f10 = new TFile("txt/PionFlatPt_M200_rfp24_poi24/bak/outGraph.root");

	TGraphErrors * gr_v22_10 = (TGraphErrors*) f10->Get("gr_vnEtaV_2_0_5");
	TGraphErrors * gr_v24_10 = (TGraphErrors*) f10->Get("gr_vnEtaV_2_1_5");
	TGraphErrors * gr_v26_10 = (TGraphErrors*) f10->Get("gr_vnEtaV_2_2_5");
	TGraphErrors * gr_v28_10 = (TGraphErrors*) f10->Get("gr_vnEtaV_2_3_5");

	TGraphErrors * gr_v22_20 = (TGraphErrors*) f20->Get("gr_vnEtaV_2_0_5");
	TGraphErrors * gr_v24_20 = (TGraphErrors*) f20->Get("gr_vnEtaV_2_1_5");
	TGraphErrors * gr_v26_20 = (TGraphErrors*) f20->Get("gr_vnEtaV_2_2_5");
	TGraphErrors * gr_v28_20 = (TGraphErrors*) f20->Get("gr_vnEtaV_2_3_5");

	TGraphErrors * gr_veri2 = new TGraphErrors(24);
	TGraphErrors * gr_veri4 = new TGraphErrors(24);
	TGraphErrors * gr_veri6 = new TGraphErrors(24);
	TGraphErrors * gr_veri8 = new TGraphErrors(24);

	for ( int i = 0; i < 24; i++ ) {
		gr_veri2->SetPoint(i, gr_v22_10->GetX()[i], gr_v22_20->GetEY()[i] / gr_v22_10->GetEY()[i]);
		gr_veri4->SetPoint(i, gr_v24_10->GetX()[i], gr_v24_20->GetEY()[i] / gr_v24_10->GetEY()[i]);
		gr_veri6->SetPoint(i, gr_v26_10->GetX()[i], gr_v26_20->GetEY()[i] / gr_v26_10->GetEY()[i]);
		gr_veri8->SetPoint(i, gr_v28_10->GetX()[i], gr_v28_20->GetEY()[i] / gr_v28_10->GetEY()[i]);
	}

	gr_veri2->SetMarkerColor(kRed);
	gr_veri4->SetMarkerColor(kBlue);
	gr_veri6->SetMarkerColor(kGreen);
	gr_veri8->SetMarkerColor(kBlack);

	gr_veri2->SetLineColor(kRed);
	gr_veri4->SetLineColor(kBlue);
	gr_veri6->SetLineColor(kGreen);
	gr_veri8->SetLineColor(kBlack);



	TCanvas c;
	TH2D *hframe = new TH2D("hframe", "hframe;#eta;#sigma_{20}/#sigma_{10}", 1, -2.4, 2.4, 1, 0, 2);
	hframe->Draw();
	gr_veri2->Draw("Plsame");
	gr_veri4->Draw("Plsame");
	gr_veri6->Draw("Plsame");
	gr_veri8->Draw("Plsame");

	c.SaveAs("Stat.pdf");
}
