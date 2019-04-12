
char const * fname[] = {
	"test/",			// 0
	"../PbPb2018/HIMinimumBias1/crab_HIMB1_CumuV3_noeff_v1/190328_031243/0000/",			                    // 1 MB1 no eff
	"../PbPb2018/MinBias_Hydjet_Drum5F_2018_5p02TeV/crab_Hydjet_CumuV3_noeff_v2/190411_045820/0000/",			// 2 Hydjet MB no eff
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIMinBias1_noeff/",				// 1
	"txt/Hydjet_noeff/",				    // 2
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
