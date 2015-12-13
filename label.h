
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v2/151205_123559/0000/",		// 1 PbPb express MB
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v3/151208_113312/0000/",		// 2 PbPb express MB |eta|<1.
	"../PbPb2015/PYTHIA_QCD_HighPt/",								// 3 MC high pT.

};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIExpressPhysics_MB_Cumu_v2/",				// 1
	"txt/HIExpressPhysics_MB_Cumu_v3/",				// 2
	"txt/PYTHIA_QCD_HighPt/",					// 3
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
