
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_ppReco_eff_2part_v2/160829_145024/0000/",			// 1 ppReco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias3/crab_HIMB3_Reco_eff_2part_v1/160831_001948/0000/",			// 2 Reco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_ppReco_eff_2part_v4/160901_011319/0000/",			// 3 ppReco rfp 0.3 < pT < 3
	"../PbPb2015_cumu/ExpressPhysicsPA/crab_Express_pA8_noeff_noff_v1/161119_010156/0000/",			// 4 pPb 8 TeV rfp 0.3 < pT < 3
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIMB5_ppReco_eff_2part/",					// 1
	"txt/HIMB3_Reco_eff_2part/",					// 2
	"txt/HIMB5_ppReco_eff_2part_v4/",				// 3
	"txt/ExpressPA_8TeV/",						// 4
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
