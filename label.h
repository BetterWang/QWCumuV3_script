
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v2/151205_123559/0000/",		// 1 PbPb express MB
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v3/151208_113312/0000/",		// 2 PbPb express MB |eta|<1.
	"../PbPb2015/PYTHIA_QCD_HighPt/",								// 3 MC high pT.
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_All_Cumu_v1/",				// 4 PbPb express all |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_v1/151214_231033/0000/",			// 5 PbPb HIHardProbes_Skim |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_PromptSkim_cumu_v2/",				// 6 PbPb Prompt Skim |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_v5/160204_130827/0000/",			// 7 PbPb Skim |eta|<1.
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIExpressPhysics_MB_Cumu_v2/",				// 1
	"txt/HIExpressPhysics_MB_Cumu_v3/",				// 2
	"txt/PYTHIA_QCD_HighPt/",					// 3
	"txt/HIExpressPhysics_All_Cumu_v1/",				// 4
	"txt/HIHardProbes_Skim_cumu_v1/",				// 5
	"txt/HIHardProbes_PromptSkim_cumu_v2/",				// 6
	"txt/HIHardProbes_Skim_cumu_v5/",				// 7
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
