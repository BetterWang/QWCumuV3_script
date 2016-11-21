

void Gcomp(TString s1, TString s2, TString str1, TString str2, TString fname)
{
	TFile * f1 = new TFile(s1.Data());
	TFile * f2 = new TFile(s2.Data());

	TGraphErrors * gr1 = (TGraphErrors*) f1->Get(str_gr.Data());
	TGraphErrors * gr2 = (TGraphErrors*) f2->Get(str_gr.Data());

	gr1->SetMarkerStyle(kOpenSquare);
	gr1->SetMarkerColor(kRed);
	gr1->SetLineColor(kRed);
	gr2->SetMarkerStyle(kOpenCircle);
	gr2->SetMarkerColor(kBlue);
	gr2->SetLineColor(kBlue);

	double N1 = gr1->GetN();
	double N2 = gr2->GetN();

	double low1 = std::min_element(gr1->GetY(), gr1->GetY()+N1);
	double low2 = std::min_element(gr2->GetY(), gr2->GetY()+N2);
	double low = std::min(low1, low2);

	double up1 = std::max_element(gr1->GetY(), gr1->GetY()+N1);
	double up2 = std::max_element(gr2->GetY(), gr2->GetY()+N2);
	double up = std::max(low1, low2);

	low = low - 0.1*(up - low);
	up = up + 0.1*(up - low);


}
