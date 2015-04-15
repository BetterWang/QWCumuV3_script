{
	TGraphErrors * v22 = (TGraphErrors*) _file0->Get("gr_vnPtV_2_0_6");
	TGraphErrors * v24 = (TGraphErrors*) _file0->Get("gr_vnPtV_2_1_6");
	TGraphErrors * v26 = (TGraphErrors*) _file0->Get("gr_vnPtV_2_2_5");
	TGraphErrors * v28 = (TGraphErrors*) _file0->Get("gr_vnPtV_2_3_3");

	for ( int i = 0; i < v22->GetN(); i++ ) {
		cout << " v22 i = " << i << "\tx = " << v22->GetX()[i] << "\ty = " << v22->GetY()[i] << "\tey = " << v22->GetEY()[i] << endl; 
	}

	for ( int i = 0; i < v24->GetN(); i++ ) {
		cout << " v24 i = " << i << "\tx = " << v24->GetX()[i] << "\ty = " << v24->GetY()[i] << "\tey = " << v24->GetEY()[i] << endl; 
	}

	for ( int i = 0; i < v26->GetN(); i++ ) {
		cout << " v26 i = " << i << "\tx = " << v26->GetX()[i] << "\ty = " << v26->GetY()[i] << "\tey = " << v26->GetEY()[i] << endl; 
	}

	for ( int i = 0; i < v28->GetN(); i++ ) {
		cout << " v28 i = " << i << "\tx = " << v28->GetX()[i] << "\ty = " << v28->GetY()[i] << "\tey = " << v28->GetEY()[i] << endl; 
	}
}
