
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_ppReco_eff_2part_v2/160829_145024/0000/",			// 1 ppReco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias3/crab_HIMB3_Reco_eff_2part_v1/160831_001948/0000/",			// 2 Reco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_Cumu_ppReco_eff_noff_v1/161128_173103/0000/",		// 3 ppReco rfp 0.3 < pT < 3
	"../PbPb2015_cumu/ExpressPhysicsPA/crab_Express_pA8_noeff_noff_v2/161121_172911/0000/",			// 4 pPb 8 TeV rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighMultiplicity0/crab_PAHM0_noeff_v1/161122_182345/0000/",				// 5 pPb 8 TeV rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v3/161130_004904/0000/",		// 6 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighPt/crab_pPb5_Cumu_eff_noff_v1/161124_111445/0000/",				// 7 pPb 2013 5 TeV rfp 0.3 < pT < 3
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIMB5_ppReco_eff_2part/",					// 1
	"txt/HIMB3_Reco_eff_2part/",					// 2
	"txt/HIMB5_ppReco_eff_2part_v4/",				// 3
	"txt/ExpressPA_8TeV/",						// 4
	"txt/PAHM_8TeV/",						// 5
	"txt/HIMB2_pixel/",						// 6
	"txt/PA5T3V_2013/",						// 7
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
