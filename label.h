
char const * fname[] = {
	"test/",			// 0
	"../XeXe/HIMinimumBias1/crab_XeXe1_CumuV3_eff_Cent_v4/180214_200041/0000/",			// 1 XeXe Cent
	"../XeXe/HIMinimumBias2/crab_XeXe2_CumuV3_eff_Cent_v4/180214_215701/0000/",			// 2 XeXe Cent
	"../XeXe/HIMinimumBias3/crab_XeXe3_CumuV3_eff_Cent_v4/180214_215723/0000/",			// 3 XeXe Cent
	"../XeXe/HIMinimumBias4/crab_XeXe4_CumuV3_eff_Cent_v4/180214_215746/0000/",			// 4 XeXe Cent
	"../XeXe/HIMinimumBias5/crab_XeXe5_CumuV3_eff_Cent_v4/180214_215809/0000/",			// 5 XeXe Cent
	"../XeXe/HIMinimumBias6/crab_XeXe6_CumuV3_eff_Cent_v4/180214_215830/0000/",			// 6 XeXe Cent
	"../XeXe/HIMinimumBias7/crab_XeXe7_CumuV3_eff_Cent_v4/180214_215851/0000/",			// 7 XeXe Cent
	"../XeXe/HIMinimumBias8/crab_XeXe8_CumuV3_eff_Cent_v4/180214_215913/0000/",			// 8 XeXe Cent
	"../XeXe/HIMinimumBias9/crab_XeXe9_CumuV3_eff_Cent_v4/180214_215937/0000/",			// 9 XeXe Cent
	"../XeXe/HIMinimumBias10/crab_XeXe10_CumuV3_eff_Cent_v4/180214_215959/0000/",			// 10 XeXe Cent
	"../XeXe/HIMinimumBias11/crab_XeXe11_CumuV3_eff_Cent_v4/180214_220022/0000/",			// 11 XeXe Cent
	"../XeXe/HIMinimumBias12/crab_XeXe12_CumuV3_eff_Cent_v4/180214_220043/0000/",			// 12 XeXe Cent
	"../XeXe/HIMinimumBias13/crab_XeXe13_CumuV3_eff_Cent_v4/180214_220105/0000/",			// 13 XeXe Cent
	"../XeXe/HIMinimumBias14/crab_XeXe14_CumuV3_eff_Cent_v4/180214_220128/0000/",			// 14 XeXe Cent
	"../XeXe/HIMinimumBias15/crab_XeXe15_CumuV3_eff_Cent_v4/180214_220150/0000/",			// 15 XeXe Cent
	"../XeXe/HIMinimumBias16/crab_XeXe16_CumuV3_eff_Cent_v4/180214_220212/0000/",			// 16 XeXe Cent
	"../XeXe/HIMinimumBias17/crab_XeXe17_CumuV3_eff_Cent_v4/180214_220234/0000/",			// 17 XeXe Cent
	"../XeXe/HIMinimumBias18/crab_XeXe18_CumuV3_eff_Cent_v4/180214_220301/0000/",			// 18 XeXe Cent
	"../XeXe/HIMinimumBias19/crab_XeXe19_CumuV3_eff_Cent_v4/180214_220323/0000/",			// 19 XeXe Cent
	"../XeXe/HIMinimumBias20/crab_XeXe20_CumuV3_eff_Cent_v4/180214_220346/0000/",			// 20 XeXe Cent
	"NA",			// 21 XeXe Cent
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/XeXe_MB1_Cent",						// 1
	"txt/XeXe_MB2_Cent",						// 2
	"txt/XeXe_MB3_Cent",						// 3
	"txt/XeXe_MB4_Cent",						// 4
	"txt/XeXe_MB5_Cent",						// 5
	"txt/XeXe_MB6_Cent",						// 6
	"txt/XeXe_MB7_Cent",						// 7
	"txt/XeXe_MB8_Cent",						// 8
	"txt/XeXe_MB9_Cent",						// 9
	"txt/XeXe_MB10_Cent",						// 10
	"txt/XeXe_MB11_Cent",						// 11
	"txt/XeXe_MB12_Cent",						// 12
	"txt/XeXe_MB13_Cent",						// 13
	"txt/XeXe_MB14_Cent",						// 14
	"txt/XeXe_MB15_Cent",						// 15
	"txt/XeXe_MB16_Cent",						// 16
	"txt/XeXe_MB17_Cent",						// 17
	"txt/XeXe_MB18_Cent",						// 18
	"txt/XeXe_MB19_Cent",						// 19
	"txt/XeXe_MB20_Cent",						// 20
	"txt/XeXe_MB_Cent",						// 21
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
