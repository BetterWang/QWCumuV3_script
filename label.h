
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_ppReco_eff_2part_v2/160829_145024/0000/",			// 1 ppReco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias3/crab_HIMB3_Reco_eff_2part_v1/160831_001948/0000/",			// 2 Reco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_Cumu_ppReco_eff_noff_v1/161128_173103/0000/",		// 3 ppReco rfp 0.3 < pT < 3
	"../PbPb2015_cumu/ExpressPhysicsPA/crab_Express_pA8_noeff_noff_v2/161121_172911/0000/",			// 4 pPb 8 TeV rfp 0.3 < pT < 3
	"",													// 5 pPb 8 TeV rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v3/161130_004904/0000/",		// 6 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighPt/crab_pPb5_Cumu_eff_noff_v1/161124_111445/0000/",				// 7 pPb 2013 5 TeV rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumu_eff_v4/161215_142033/0000/",				// 8 pPb 8 TeV HM0 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighMultiplicity1/crab_PAHM1_cumu_eff_v2/161201_195101/0000/",			// 9 pPb 8 TeV HM1 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighMultiplicity2/crab_PAHM2_cumu_eff_v2/161201_195116/0000/",			// 10 pPb 8 TeV HM2 rfp 0.3 < pT < 3
	"",				// 11 pPb 8 TeV HM3 rfp 0.3 < pT < 3
	"",				// 12 pPb 8 TeV HM4 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighMultiplicity5/crab_PAHM5_cumu_eff_v2/161201_195220/0000/",			// 13 pPb 8 TeV HM5 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighMultiplicity6/crab_PAHM6_cumu_eff_v2/161201_195238/0000/",			// 14 pPb 8 TeV HM6 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighMultiplicity7/crab_PAHM7_cumu_eff_v2/161201_195255/0000/",			// 15 pPb 8 TeV HM7 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAMinimumBias1/crab_PAMB1_cumu_eff_v1/161201_162146/0000/",				// 16 pPb 8 TeV MB1 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAMinimumBias2/crab_PAMB2_cumu_eff_v1/161201_162201/0000/",				// 17 pPb 8 TeV MB2 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAMinimumBias3/crab_PAMB3_cumu_eff_v1/161201_162216/0000/",				// 18 pPb 8 TeV MB3 rfp 0.3 < pT < 3
	"",				// 19 pPb 8 TeV MB4 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAMinimumBias5/crab_PAMB5_cumu_eff_v1/161201_162246/0000/",				// 20 pPb 8 TeV MB5 rfp 0.3 < pT < 3
	"",				// 21 pPb 8 TeV MB6 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAMinimumBias7/crab_PAMB7_cumu_eff_v1/161201_162311/0000/",				// 22 pPb 8 TeV MB7 rfp 0.3 < pT < 3
	"",				// 23 pPb 8 TeV MB8 rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v4/161212_200141/0000/",		// 24 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v4/161212_200141/0001/",		// 25 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v4/161212_200141/0002/",		// 26 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v4/161212_200141/0003/",		// 27 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v4/161212_200141/0004/",		// 28 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v5/161215_202815/0000/",		// 29 PbPb pixel rfp 1.0 < pT < 3 |eta|<2.4
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v5/161215_202815/0001/",		// 30 PbPb pixel rfp 1.0 < pT < 3 |eta|<2.4
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v5/161215_202815/0002/",		// 31 PbPb pixel rfp 1.0 < pT < 3 |eta|<2.4
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v5/161215_202815/0003/",		// 32 PbPb pixel rfp 1.0 < pT < 3 |eta|<2.4
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v5/161215_202815/0004/",		// 33 PbPb pixel rfp 1.0 < pT < 3 |eta|<2.4
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v5/161215_202815/0005/",		// 34 PbPb pixel rfp 1.0 < pT < 3 |eta|<2.4
	"",													// 35 PbPb pixel rfp 1.0 < pT < 3 |eta|<2.4
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v6/161220_112708/0000/",		// 36 PbPb pixel rfp 0.3 < pT < 3 |eta|<1.0 Deta > 1.0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v6/161220_112708/0001/",		// 37 PbPb pixel rfp 0.3 < pT < 3 |eta|<1.0 Deta > 1.0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v6/161220_112708/0002/",		// 38 PbPb pixel rfp 0.3 < pT < 3 |eta|<1.0 Deta > 1.0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v6/161220_112708/0003/",		// 39 PbPb pixel rfp 0.3 < pT < 3 |eta|<1.0 Deta > 1.0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v6/161220_112708/0004/",		// 40 PbPb pixel rfp 0.3 < pT < 3 |eta|<1.0 Deta > 1.0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_eta1_v6/161220_112708/0005/",		// 41 PbPb pixel rfp 0.3 < pT < 3 |eta|<1.0 Deta > 1.0
	"",													// 42 PbPb pixel rfp 0.3 < pT < 3 |eta|<1.0 Deta > 1.0
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_general_eff_cent_v7/170105_224504/0000/",		// 43 PbPb general rfp 1.0 < pT < 3 |eta|<1.0 Deta > 1.0
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
	"txt/PAHM0_8TeV/",						// 8
	"txt/PAHM1_8TeV/",						// 9
	"txt/PAHM2_8TeV/",						// 10
	"txt/PAHM3_8TeV/",						// 11
	"txt/PAHM4_8TeV/",						// 12
	"txt/PAHM5_8TeV/",						// 13
	"txt/PAHM6_8TeV/",						// 14
	"txt/PAHM7_8TeV/",						// 15
	"txt/PAMB1_8TeV/",						// 16
	"txt/PAMB2_8TeV/",						// 17
	"txt/PAMB3_8TeV/",						// 18
	"txt/PAMB4_8TeV/",						// 19
	"txt/PAMB5_8TeV/",						// 20
	"txt/PAMB6_8TeV/",						// 21
	"txt/PAMB7_8TeV/",						// 22
	"txt/PAMB8_8TeV/",						// 23
	"txt/HIMB2_pixel_part0/",					// 24
	"txt/HIMB2_pixel_part1/",					// 25
	"txt/HIMB2_pixel_part2/",					// 26
	"txt/HIMB2_pixel_part3/",					// 27
	"txt/HIMB2_pixel_part4/",					// 28
	"txt/HIMB2_pixel_pt1_part0/",					// 29
	"txt/HIMB2_pixel_pt1_part1/",					// 30
	"txt/HIMB2_pixel_pt1_part2/",					// 31
	"txt/HIMB2_pixel_pt1_part3/",					// 32
	"txt/HIMB2_pixel_pt1_part4/",					// 33
	"txt/HIMB2_pixel_pt1_part5/",					// 34
	"txt/HIMB2_pixel_pt1/",						// 35
	"txt/HIMB2_pixel_eta1_part0/",					// 36
	"txt/HIMB2_pixel_eta1_part1/",					// 37
	"txt/HIMB2_pixel_eta1_part2/",					// 38
	"txt/HIMB2_pixel_eta1_part3/",					// 39
	"txt/HIMB2_pixel_eta1_part4/",					// 40
	"txt/HIMB2_pixel_eta1_part5/",					// 41
	"txt/HIMB2_pixel_eta1/",					// 42
	"txt/HIMB2_general_eta1/",					// 43
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
