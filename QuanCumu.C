
TMultiGraph * mgrQuanCumu[4][8] = {0};
TGraphErrors * grQuanCumu[4][8] = {0};
TGraphErrors * grQuanCumuSys[4][8] = {0};

TColor *red = new TColor(3001, 1, 0, 0, "red", 0.4);
TColor *green = new TColor(3002, 0, 0.6, 0, "green", 0.4);
TColor *blue = new TColor(3003, 0, 0, 1, "blue", 0.4);


void QuanCumu()
{
	TFile * fCumu = new TFile("QuanCumu.root");

	for ( int np = 1; np < 4; np++ ) {
		for ( int c = 1; c < 6; c++ ) {
			grQuanCumu[np][c] = (TGraphErrors*) fCumu->Get(Form("grV2%i_%i", 2*np+2, c));
			grQuanCumuSys[np][c] = (TGraphErrors*) fCumu->Get(Form("grV2%is_%i", 2*np+2, c));
			mgrQuanCumu[np][c] = new TMultiGraph();
			mgrQuanCumu[np][c]->Add(grQuanCumuSys[np][c], "[]3");
			mgrQuanCumu[np][c]->Add(grQuanCumu[np][c], "p");
		}
	}
}
