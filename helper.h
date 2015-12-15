TGraphErrors* makeRatioEP(TGraphErrors* gr)
{
	double ratio[6] = {};
	double eratio[6] = {};
	double x[6] = {};
	if ( bPbPb ) {
		gr->Sort();
		for ( int i = 0; i < 6; i++ ) {
			x[i] = gr->GetX()[i+6];
			ratio[i] = gr->GetY()[i+6] / gr->GetY()[5-i];
			eratio[i] = ratio[i]*sqrt((gr->GetEY()[5-i]/gr->GetY()[5-i])**2 + (gr->GetEY()[i+6]/gr->GetY()[i+6])**2);
		}
		TGraphErrors * ret = new TGraphErrors(6, x, ratio, 0, eratio);
		ret->SetMarkerStyle(gr->GetMarkerStyle());
		ret->SetMarkerColor(gr->GetMarkerColor());
		ret->SetLineColor(gr->GetLineColor());
		return ret;
	} else {
		gr->Sort();
		for (int i = 0; i < 5; i++) {
			x[i] = gr->GetX()[i+7] - 0.4;
			ratio[i] = gr->GetY()[i+7] / gr->GetY()[6-i];
			eratio[i] = ratio[i]*sqrt((gr->GetEY()[6-i]/gr->GetY()[6-i])**2 + (gr->GetEY()[i+7]/gr->GetY()[i+7])**2);
		}
		TGraphErrors * ret = new TGraphErrors(5, x, ratio, 0, eratio);
		ret->SetMarkerStyle(gr->GetMarkerStyle());
		ret->SetMarkerColor(gr->GetMarkerColor());
		ret->SetLineColor(gr->GetLineColor());
		return ret;
	}
}


TGraphErrors* makeRatio(TGraphErrors* gr)
{
	double ratio[12] = {};
	double eratio[12] = {};
	double x[12] = {};
	if ( bPbPb ) {
		for ( int i = 0; i < 12; i++ ) {
			x[i] = gr->GetX()[i];
			ratio[i] = gr->GetY()[i] / gr->GetY()[23-i];
			eratio[i] = ratio[i]*sqrt((gr->GetEY()[23-i]/gr->GetY()[23-i])**2 + (gr->GetEY()[i]/gr->GetY()[i])**2);
		}
		TGraphErrors * ret = new TGraphErrors(12, x, ratio, 0, eratio);
		ret->SetMarkerStyle(gr->GetMarkerStyle());
		ret->SetMarkerColor(gr->GetMarkerColor());
		ret->SetLineColor(gr->GetLineColor());
		return ret;
	} else {
		for (int i = 0; i < 10; i++) {
			x[i] = gr->GetX()[i] - 0.4;
			ratio[i] = gr->GetY()[i] / gr->GetY()[19-i];
			eratio[i] = ratio[i]*sqrt((gr->GetEY()[19-i]/gr->GetY()[19-i])**2 + (gr->GetEY()[i]/gr->GetY()[i])**2);
		}
		TGraphErrors * ret = new TGraphErrors(12, x, ratio, 0, eratio);
		ret->SetMarkerStyle(gr->GetMarkerStyle());
		ret->SetMarkerColor(gr->GetMarkerColor());
		ret->SetLineColor(gr->GetLineColor());
		return ret;
	}
}

TGraphErrors* makeSys(TGraphErrors* gr, double sys)
{
	if (!gr) return 0;
	TGraphErrors * ret = gr->Clone();
	for ( int i = 0; i < gr->GetN(); i++ ) {
		ret->GetEY()[i] = ret->GetY()[i] * sys;
		ret->GetEX()[i] = 0.15;
	}
	ret->SetFillColor(kGray);
	return ret;
}



void trimGrPT(TGraphErrors* gr)
{
	if ( !gr ) return;
	for ( int i = 0; i < gr->GetN(); i++ ) {
		if (gr->GetY()[i]!= gr->GetY()[i] || gr->GetX()[i] < 0.1 || gr->GetX()[i] > 6 || gr->GetX()[i] != gr->GetX()[i]) {
			gr->RemovePoint(i);
			i--;
		}
	}
	return;
}

void setSysPt(TGraphErrors* gr)
{
	if (gr) {
		for ( int i = 0; i < gr->GetN(); i++ ) {
			gr->GetEX()[i] = 0.15;
		}
		gr->SetFillColor(kGray);
	}
}

TGraphErrors* makeRatioPt(TGraphErrors* gr, TGraphErrors* grD, int istart = 0, int iend = 9)
{
	double ratio[100];
	double e[100];
	double x[100];
	for ( int i = istart; i < iend; i++ ) {
		x[i] = gr->GetX()[i];
		ratio[i] = gr->GetY()[i] / grD->GetY()[i];
		e[i] = sqrt((gr->GetEY()[i]/gr->GetY()[i])**2 + (grD->GetEY()[i]/grD->GetY()[i])**2) * ratio[i];
		if (!(gr->GetY()[i] > 0) || !(grD->GetY()[i]) ) {
			cout << "!! << " << i << "-> " << x[i] << " ->" << gr->GetY()[i] << " --> " << grD->GetY()[i] << endl;
		}
	}

	TGraphErrors* ret = new TGraphErrors(iend-istart, x+istart, ratio+istart, 0, e+istart);
	ret->SetMarkerStyle(gr->GetMarkerStyle());
	ret->SetMarkerColor(gr->GetMarkerColor());
	ret->SetLineColor(gr->GetLineColor());
	return ret;

}

void trimGrPT2(TGraphErrors* gr)
{
	if ( !gr ) return;
	for ( int i = 0; i < gr->GetN(); i++ ) {
		if (gr->GetX()[i] < 0.21 || gr->GetX()[i] > 6 ) {
			gr->RemovePoint(i);
			i--;
		}
	}
	return;
}

TGraphErrors * merge_EP_longrange(TGraphErrors* a, TGraphErrors* b, int markerStyle = kFullCircle, int color = kRed)
{
	TGraphErrors* ret = new TGraphErrors(12);
	int idx = 0;
	for ( int i = 0; i < 12; i++ ) {
		if ( a->GetX()[i] > 0 ) continue;
		ret->SetPoint(idx, a->GetX()[i], a->GetY()[i]);
		ret->SetPointError(idx, 0, a->GetEY()[i]);
		idx++;
	}
	for ( int i = 0; i < 12; i++ ) {
		if ( b->GetX()[i] < 0 ) continue;
		ret->SetPoint(idx, b->GetX()[i], b->GetY()[i]);
		ret->SetPointError(idx, 0, b->GetEY()[i]);
		idx++;
	}
	ret->Sort();
	ret->SetMarkerStyle(markerStyle);
	ret->SetMarkerColor(color);
	ret->SetLineColor(color);
	return ret;
}


TGraphErrors * rebin_eta(TGraphErrors* gr)
{
	if (!gr) return 0;
	int Nbin = gr->GetN()/2;
	TGraphErrors* ret = new TGraphErrors(Nbin);
	for ( int i = 0; i < Nbin; i++ ) {
		double x = ( gr->GetX()[2*i] + gr->GetX()[2*i+1] ) / 2.;
		double y = ( gr->GetY()[2*i] + gr->GetY()[2*i+1] ) / 2.;
		double ey = sqrt(gr->GetEY()[2*i]**2 + gr->GetEY()[2*i+1]**2) / 2.;
		ret->SetPoint(i, x, y);
		ret->SetPointError(i, 0, ey);
	}
	ret->SetMarkerStyle(gr->GetMarkerStyle());
	ret->SetMarkerColor(gr->GetMarkerColor());
	ret->SetLineColor(gr->GetLineColor());

	return ret;
}

TGraphErrors* DrawSys(TGraphErrors* gr, double sys)
{
	TGraphErrors * gr_sys = makeSys(gr, sys);
	gr_sys->Draw("[]2");
	return gr_sys;
}

double gr_std(TGraphErrors* gr)
{
	double std = 0;
	int N = gr->GetN();
	double mean = 0;
	double y2 = 0;
	for ( int i = 0; i < N; i++ ) {
		mean += gr->GetY()[i];
	}
	mean /= N;
	for ( int i = 0; i < N; i++ ) {
		y2 += (gr->GetY()[i] - mean)**2;
	}
	y2 /= (N-1);
	y2 = sqrt(y2);
	for ( int i = 0; i < N; i++ ) {
		gr->GetEY()[i] = y2;
	}
	return y2;
}

double gr_std_line(TGraphErrors* gr)
{
	TF1 * fit = new TF1("line", "pol1", -2.4, 2.4);
	gr->Fit(fit, "QN");
	int N = gr->GetN();
	double y2 = 0;
	for ( int i = 0; i < N; i++ ) {
		y2 += (gr->GetY()[i] - fit->Eval(gr->GetX()[i]))**2;
	}
	y2 /= (N-1);
	y2 = sqrt(y2);
	for ( int i = 0; i < N; i++ ) {
		gr->GetEY()[i] = y2;
	}

	return y2;
	delete fit;

}

void gr_ratio_err()
{
	TFile * fstat = new TFile(Form("ratioStat2_%i.root", bPbPb));
	TGraphErrors * gr_p[20] = {};
	TGraphErrors * gr_Pb[20] = {};
	for ( int i = 3; i < 8; i++ ) {
		gr_p[i] = (TGraphErrors*) fstat->Get(Form("gr_SavedRatioErr_p_%i", i));
		gr_Pb[i] = (TGraphErrors*) fstat->Get(Form("gr_SavedRatioErr_Pb_%i", i));
		for ( int bin = 0; bin < 12; bin++ ) {
			gr_RatioEta_p[i]->GetEY()[bin] = gr_p[i]->GetEY()[bin];
			gr_RatioEta_Pb[i]->GetEY()[bin] = gr_Pb[i]->GetEY()[bin];
		}
	}
}
