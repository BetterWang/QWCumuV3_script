
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015Pix/HIMinimumBias2/crab_HIMB2_pixel_noeff_v4/160722_172018/0000/",			// 1 Pix private run
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIMB2_v4",							// 1
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1, int sx = 0)
{
	std::cout << fname[s1] << std::endl;
	if ( sx == 0 )
		chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
	if ( sx == 1 )
		chV->Add(Form("%s/*.root/cumulant1420/trV", fname[s1]));
	if ( sx == 2 )
		chV->Add(Form("%s/*.root/cumulant2026/trV", fname[s1]));
	if ( sx == 3 )
		chV->Add(Form("%s/*.root/cumulant2635/trV", fname[s1]));
	if ( sx == 4 )
		chV->Add(Form("%s/*.root/cumulant35/trV", fname[s1]));
}
