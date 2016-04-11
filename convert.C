#include "DataPoints.C"
#include "QuanCumu.C"

void convert()
{
	DataPoints();
	QuanCumu();

	TFile * fsave = new TFile("QuanCumu.root", "recreate");
	for ( int i = 1; i < 4; i++ ) {
		for ( int c = 0; c < 8; c++ ) {
			if ( grQuanCumu[i][c] ) {
				for ( int j = 0; j < grQuanCumu[i][c]->GetN(); j++ ) {
					grQuanCumu[i][c]->GetX()[j] = grSteveSPv2[c]->GetX()[j];
					grQuanCumuSys[i][c]->GetX()[j] = grSteveSPv2[c]->GetX()[j];
				}
				grQuanCumu[i][c]->Write();
				grQuanCumuSys[i][c]->Write();
			}
		}
	}
}
