
char const * fname[] = {
	"test/",			// 0
	"../XeXe/HIMinimumBias1/crab_XeXe1_CumuV3_eff_Cent_v1/171109_190654/0000/",			// 1 XeXe Cent
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/XeXe_MB1_Cent",						// 1
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
