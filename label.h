
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_ppReco_eff_2part_v2/160829_145024/0000/",			// 1 ppReco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias3/crab_HIMB3_Reco_eff_2part_v1/160831_001948/0000/",			// 2 Reco rfp 1 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias5/crab_HIMB5_Cumu_ppReco_eff_noff_v1/161128_173103/0000/",		// 3 ppReco rfp 0.3 < pT < 3
	"../PbPb2015_cumu/ExpressPhysicsPA/crab_Express_pA8_noeff_noff_v2/161121_172911/0000/",			// 4 pPb 8 TeV rfp 0.3 < pT < 3
	"",													// 5 pPb 8 TeV rfp 0.3 < pT < 3
	"../PbPb2015_cumu/HIMinimumBias2/crab_HIMB2_Cumu_pixel_eff_cent_v3/161130_004904/0000/",		// 6 PbPb pixel rfp 0.3 < pT < 3
	"../PbPb2015_cumu/PAHighPt/crab_pPb5_Cumu_eff_noff_v1/161124_111445/0000/",				// 7 pPb 2013 5 TeV rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumu_eff_v8/170219_155607/0000/",				// 8 pPb 8 TeV HM0 rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumu_eff_v8/170219_155918/0000/",				// 9 pPb 8 TeV HM1 rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity2/crab_PAHM2_cumu_eff_v5/170112_121913/0000/",				// 10 pPb 8 TeV HM2 rfp 0.3 < pT < 3
	"",			// 11 pPb 8 TeV HM3 rfp 0.3 < pT < 3
	"",			// 12 pPb 8 TeV HM4 rfp 0.3 < pT < 3
	"",			// 13 pPb 8 TeV HM5 rfp 0.3 < pT < 3
	"",			// 14 pPb 8 TeV HM6 rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumu_eff_v8/170219_160110/0000/",				// 15 pPb 8 TeV HM7 rfp 0.3 < pT < 3
	"../pPb/PAMinimumBias1/crab_PAMB1_cumu_eff_v8/170219_175845/0000/",					// 16 pPb 8 TeV MB1 rfp 0.3 < pT < 3
	"",				// 17 pPb 8 TeV MB2 rfp 0.3 < pT < 3
	"",				// 18 pPb 8 TeV MB3 rfp 0.3 < pT < 3
	"",				// 19 pPb 8 TeV MB4 rfp 0.3 < pT < 3
	"",				// 20 pPb 8 TeV MB5 rfp 0.3 < pT < 3
	"",				// 21 pPb 8 TeV MB6 rfp 0.3 < pT < 3
	"",				// 22 pPb 8 TeV MB7 rfp 0.3 < pT < 3
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
	"../pPb/PAHighMultiplicity0/crab_PAHM0_cumu_eff_reverse_v8/170228_150959/0000/",			// 44 Pbp 8 TeV HM0 rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity1/crab_PAHM1_cumu_eff_reverse_v8/170228_151020/0000/",			// 45 Pbp 8 TeV HM1 rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity2/crab_PAHM2_cumu_eff_reverse_v5/170204_191500/0000/",			// 46 Pbp 8 TeV HM2 rfp 0.3 < pT < 3
	"",				// 47 Pbp 8 TeV HM3 rfp 0.3 < pT < 3
	"",				// 48 Pbp 8 TeV HM4 rfp 0.3 < pT < 3
	"",				// 49 Pbp 8 TeV HM5 rfp 0.3 < pT < 3
	"",				// 50 Pbp 8 TeV HM6 rfp 0.3 < pT < 3
	"../pPb/PAHighMultiplicity7/crab_PAHM7_cumu_eff_reverse_v8/170228_151041/0000/",			// 51 Pbp 8 TeV HM7 rfp 0.3 < pT < 3
	"../pPb/PAMinimumBias1/crab_PAMB1_cumu_eff_reverse_v8/170228_152313/0000/",				// 52 Pbp 8 MB1
	"",				// 53 Pbp 8 MB2
	"",				// 54 Pbp 8 MB3
	"",				// 55 Pbp 8 MB4
	"",				// 56 Pbp 8 MB5
	"",				// 57 Pbp 8 MB6
	"",				// 58 Pbp 8 MB7
	"",				// 59 Pbp 8 MB8
	"",				// 60 pPb 8 HM1-6 merged
	"",				// 61 pPb 8 MB merged
	"",				// 62 Pbp 8 HM1-6 merged
	"",				// 63 Pbp 8 MB merged
	"",			// 64 tmp1 8 done,  44->part1
	"",			// 65 tmp2 9 done,  45->part1
	"",			// 66 tmp3 15 done, 51 done
	"",				// 67 tmp4 16 done, 52->part1
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
	"txt/PAHM0_reverse_8TeV/",					// 44
	"txt/PAHM1_reverse_8TeV/",					// 45
	"txt/PAHM2_reverse_8TeV/",					// 46
	"txt/PAHM3_reverse_8TeV/",					// 47
	"txt/PAHM4_reverse_8TeV/",					// 48
	"txt/PAHM5_reverse_8TeV/",					// 49
	"txt/PAHM6_reverse_8TeV/",					// 50
	"txt/PAHM7_reverse_8TeV/",					// 51
	"txt/PAMB1_reverse_8TeV/",					// 52
	"txt/PAMB2_reverse_8TeV/",					// 53
	"txt/PAMB3_reverse_8TeV/",					// 54
	"txt/PAMB4_reverse_8TeV/",					// 55
	"txt/PAMB5_reverse_8TeV/",					// 56
	"txt/PAMB6_reverse_8TeV/",					// 57
	"txt/PAMB7_reverse_8TeV/",					// 58
	"txt/PAMB8_reverse_8TeV/",					// 59
	"txt/PAHM1to6_merge_8TeV/",					// 60
	"txt/PAMB_merge_8TeV/",						// 61
	"txt/PAHM1to6_reverse_merge_8TeV/",				// 62
	"txt/PAMB_merge_reverse_8TeV/",					// 63
	"txt/tmp1/",					// 64
	"txt/tmp2/",					// 65
	"txt/tmp3/",					// 66
	"txt/tmp4/",					// 67
};

#include <TChain.h>
#include <iostream>

TChain * chV = new TChain("trV");
void addchain(int s1)
{
	std::cout << fname[s1] << std::endl;
	chV->Add(Form("%s/*.root/cumulantMB/trV", fname[s1]));
}
