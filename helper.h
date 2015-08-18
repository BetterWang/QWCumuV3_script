
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
//	cout << "!! N = " << gr->GetN() << endl;
	for ( int i = 0; i < gr->GetN(); i++ ) {
		ret->GetEY()[i] = ret->GetY()[i] * sys;
	}
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
