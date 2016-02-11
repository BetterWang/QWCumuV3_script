
char const * fname[] = {
	"test/",			// 0
	"../pp13TeV/HighMultiplicity/crab_pp13TeV_Totem_cumu_v1/160209_185843/0000",		// 1 pp Totem HM
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/Totem_HM/",				// 1
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumu60/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumu85/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumu135/trV", fname[s1]));
}
