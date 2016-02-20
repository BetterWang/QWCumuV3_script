
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v2/151205_123559/0000/",		// 1 PbPb express MB
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v3/151208_113312/0000/",		// 2 PbPb express MB |eta|<1.
	"../PbPb2015/PYTHIA_QCD_HighPt/",								// 3 MC high pT.
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_All_Cumu_v1/",				// 4 PbPb express all |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_v1/151214_231033/0000/",			// 5 PbPb HIHardProbes_Skim |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_PromptSkim_cumu_v2/",				// 6 PbPb Prompt Skim |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_v7/160211_155304/0000/",			// 7 PbPb Skim |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias1/crab_HIMB1_cal_noeff_v3/160217_111636/0000/",			// 8 PbPb MB1 AOD   |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias2/crab_HIMB2_cal_noeff_v3/",			// 9 PbPb MB2 AOD   |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_v2/160216_221440/0000/",			// 10 PbPb MB3 Skim |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_v3/160217_111658/0000/",			// 11 PbPb MB4 AOD  |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"NA",												// 12 PbPb MB1,2,3,4 8+9+10+11 AOD  |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIExpressPhysics_MB_Cumu_v2/",				// 1
	"txt/HIExpressPhysics_MB_Cumu_v3/",				// 2
	"txt/PYTHIA_QCD_HighPt/",					// 3
	"txt/HIExpressPhysics_All_Cumu_v1/",				// 4
	"txt/HIHardProbes_Skim_cumu_v1/",				// 5
	"txt/HIHardProbes_PromptSkim_cumu_v2/",				// 6
	"txt/HIHardProbes_Skim_cumu_v7/",				// 7
	"txt/HIMB1_v3/",						// 8
	"txt/HIMB2_v3/",						// 9
	"txt/HIMB3_v2/",						// 10
	"txt/HIMB4_v3/",						// 11
	"txt/HIMB_v1/",							// 12
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
