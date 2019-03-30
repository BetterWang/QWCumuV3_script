
char const * fname[] = {
	"test/",			// 0
	"../PbPb2018/HIMinimumBias1/crab_HIMB1_CumuV3_noeff_v1/190328_031243/0000/",			// 1
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIMinBias1_noeff/",				// 1
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
