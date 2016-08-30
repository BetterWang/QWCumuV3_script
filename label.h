
char const * fname[] = {
	"test/",			// 0
};

char const * ftxt[] = {
	"txt/test/",							// 0
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
