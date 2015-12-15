{
	int N = 16;
	TFile * f;

        TGraphErrors * gr_RatioEta_p[20][20] = {};
        TGraphErrors * gr_RatioEta_Pb[20][20] = {};

	int bPbPb = 1;

	for ( int i = 0; i < N; i++ ) {
		f = new TFile(Form("ratioGr_%i_%i.root", i, bPbPb));
		for ( int j = 3; j < 8; j++ ) {
			gr_RatioEta_p[i][j] = (TGraphErrors*) f->Get(Form("gr_RatioEta_p_%i", j));
			gr_RatioEta_Pb[i][j] = (TGraphErrors*) f->Get(Form("gr_RatioEta_Pb_%i", j));
		}
	}

	TGraphErrors * gr_SavedRatioErr_p[20];
	TGraphErrors * gr_SavedRatioErr_Pb[20];
	for ( int i = 3; i < 8; i++ ) {
		gr_SavedRatioErr_p[i] = new TGraphErrors(12);
		gr_SavedRatioErr_Pb[i] = new TGraphErrors(12);
		double mean_p[12] = {};
		double mean_p2[12] = {};
		double mean_Pb[12] = {};
		double mean_Pb2[12] = {};
		for ( int n = 0; n < N; n++ ) {
			for ( int bin = 0; bin < 12; bin++ ) {
				mean_p[bin] += gr_RatioEta_p[n][i]->GetY()[bin];
				mean_Pb[bin] += gr_RatioEta_Pb[n][i]->GetY()[bin];

				mean_p2[bin] += gr_RatioEta_p[n][i]->GetY()[bin]**2;
				mean_Pb2[bin] += gr_RatioEta_Pb[n][i]->GetY()[bin]**2;

				gr_SavedRatioErr_p[i]->SetPoint(bin, gr_RatioEta_p[n][i]->GetX()[bin], 1);
				gr_SavedRatioErr_Pb[i]->SetPoint(bin, gr_RatioEta_Pb[n][i]->GetX()[bin], 1);
			}
		}
		for ( int bin = 0; bin < 12; bin++ ) {
			gr_SavedRatioErr_p[i]->GetEY()[bin] = sqrt(mean_p2[bin]/N - (mean_p[bin]/N)**2)/sqrt(N);
			gr_SavedRatioErr_Pb[i]->GetEY()[bin] = sqrt(mean_Pb2[bin]/N - (mean_Pb[bin]/N)**2)/sqrt(N);
		}
	}
	f = new TFile(Form("ratioStat2_%i.root", bPbPb), "recreate");

	for ( int i = 3; i < 8; i++ ) {
		gr_SavedRatioErr_p[i]->SetName(Form("gr_SavedRatioErr_p_%i", i));
		gr_SavedRatioErr_Pb[i]->SetName(Form("gr_SavedRatioErr_Pb_%i", i));
		gr_SavedRatioErr_p[i]->Write();
		gr_SavedRatioErr_Pb[i]->Write();
	}
}
