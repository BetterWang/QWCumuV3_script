{
	char s1[] = "/afs/cern.ch/work/q/qwang/cleanroomRun2/Ana/CMSSW_7_5_7_patch2/src/QWAna/QWCumuV3/PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v3/151208_113312/0000/merged.root";
	TFile * f = new TFile(s1);
	TCanvas c;
	TH1D * h;
	TTree * trV = (TTree*) f->Get("cumulantMB/trV");
	trV->Draw("Noff>>hh(200, 0 , 200)", "", "goff");
	hh->SetTitle("cumulantMB/Noff");
	hh->Draw();
	c.SaveAs("report.pdf(");
	trV->Draw("Mult>>hhh(3000, 0 , 3000)", "", "goff");
	hhh->SetTitle("cumulantMB/Mult");
	hhh->Draw();
	c.SaveAs("report.pdf");
	trV->Draw("Noff:Mult>>h2d(3000, 0 , 3000, 200, 0, 200)", "", "goff");
	h2d->SetTitle("cumulantMB/Mult-Noff");
	h2d->Draw("colz");
	c.SaveAs("report.pdf");
	for ( int i = 0; i < 14; i++ ) {
		h = (TH1D*) f->Get(Form("cumulantMB/hPt_%i", i));
		h->SetTitle(Form("cumulantMB/hPt_%i", i));
		h->Draw();
		c.SaveAs("report.pdf");
	}
	TH2D * h2;
	for ( int i = 0; i < 14; i++ ) {
		h2 = (TH2D*) f->Get(Form("cumulantMB/hdNdPtdEta_%i", i));
		h2->SetTitle(Form("cumulantMB/hdNdPtdEta_%i", i));
		h2->Draw("colz");
		c.SaveAs("report.pdf");
	}
	TH2D * hp, * hn;
	for ( int i = 0; i < 14; i++ ) {
		for ( int j = 0; j < 8; j++ ) {
			hp = (TH2D*) f->Get(Form("cumulantMB/hPhiEta_%i_%i_0", i, j));
			hn = (TH2D*) f->Get(Form("cumulantMB/hPhiEta_%i_%i_1", i, j));
			hp->Add(hn);
			hp->Draw("colz");
			c.SaveAs("report.pdf");
		}
	}
	c.SaveAs("report.pdf)");
}
