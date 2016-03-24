
TGraphErrors * grSteveSPv2[8];
TGraphErrors * grSteveSPv3[8];

char const * strSteveCent[8] = {
	"0 - 5%",
	"5 - 10%",
	"10 - 20%",
	"20 - 30%",
	"30 - 40%",
	"40 - 50%",
	"50 - 60%",
	"60 - 70%",
};

void
SteveSP() {
	TFile * fSP = new TFile("txt/plotSteve.root");
	for ( int i = 0; i < 8; i++ ) {
		grSteveSPv2[i] = (TGraphErrors*) fSP->Get(Form("v2_%i", i));
		grSteveSPv3[i] = (TGraphErrors*) fSP->Get(Form("v3_%i", i));
	}
}
