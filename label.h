
char const * fname[] = {
	"test/",			// 0
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v2/151205_123559/0000/",		// 1 PbPb express MB
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_MB_Cumu_v3/151208_113312/0000/",		// 2 PbPb express MB |eta|<1.
	"../PbPb2015/PYTHIA_QCD_HighPt/",								// 3 MC high pT.
	"../PbPb2015/HIExpressPhysics/crab_HIExpressPhysics_All_Cumu_v1/",				// 4 PbPb express all |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_v1/151214_231033/0000/",			// 5 PbPb HIHardProbes_Skim |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_PromptSkim_cumu_v2/",				// 6 PbPb Prompt Skim |eta|<1.
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_v7/160211_155304/0000/",			// 7 PbPb Skim |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias1/crab_HIMB1_cal_noeff_v3/160217_111636/0000/",			// 8 PbPb MB1 AOD   |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias2/crab_HIMB2_cal_noeff_v3/",			// 9 PbPb MB2 AOD   |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_v2/160216_221440/0000/",			// 10 PbPb MB3 Skim |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_v3/160217_111658/0000/",			// 11 PbPb MB4 AOD  |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"NA",												// 12 PbPb MB1,2,3,4 8+9+10+11 AOD  |eta|<1, calo, no eff, 0.3 < pt_ref < 3.0
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_v10/160225_134058/0000/",			// 13 PbPb HP  AOD  |eta|<1, calo, with eff, 1.0 < pt_ref < 5.0, eff PbPb_dijet_TT_5TeV_v2.root
	"../PbPb2015/HIMinimumBias1/crab_HIMB1_cal_noeff_v5/",						// 14 PbPb MB1 AOD  |eta|<1, calo, with eff, 1.0 < pt_ref < 5.0 
	"../PbPb2015/HIMinimumBias2/crab_HIMB2_cal_noeff_v5/",						// 15 PbPb MB2 AOD  |eta|<1, calo, with eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_v5/160226_110447/0000/",			// 16 PbPb MB3 Skim |eta|<1, calo, with eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_v5/160226_121157/0000/",			// 17 PbPb MB4 AOD  |eta|<1, calo, with eff, 1.0 < pt_ref < 5.0
	"NA",												// 18 PbPb MB1,2,3,4 14+15+16+17 AOD  |eta|<1, calo, with eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_v11/160303_151550/0000/",		// 19 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIMinimumBias1/crab_HIMB1_cal_noeff_v6/160323_121132/0000/",			// 20 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 
	"../PbPb2015/HIMinimumBias2/crab_HIMB2_cal_noeff_v6/160323_121140/0000/",			// 21 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_v6/160303_223848/0000/",			// 22 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_v6/160306_234511/0000/",			// 23 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0
	"NA",												// 24 PbPb MB1,2,3,4 20+21+22+23 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysCalo_v11/160309_212811/0000/",	// 25 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias1//",									// 26 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias2//",									// 27 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysCalo_v6/160309_214954/0000/",		// 28 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysCalo_v6/160310_140854/0000/",		// 29 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"NA",												// 30 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysTight_v11/160310_163332/0000/",	// 31 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias1//",									// 32 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias2//",									// 33 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysTightAOD_v6/160314_152443/0000/",		// 34 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysTight_v6/160310_194548/0000/",		// 35 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"NA",												// 36 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysLoose_v11/160310_163351/0000/",	// 37 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias1//",									// 38 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias2//",									// 39 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysLooseAOD_v6/160314_152501/0000/",		// 40 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysLoose_v6/160310_194600/0000/",		// 41 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"NA",												// 42 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysVz0_v11/160310_163402/0000/",	// 43 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias1//",									// 44 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias2//",									// 45 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysVz0AOD_v6/160314_152519/0000/",		// 46 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysVz0_v6/160310_194611/0000/",		// 47 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"NA",												// 48 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysVz1_v11/160310_163415/0000/",	// 49 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias1//",									// 50 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias2//",									// 51 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysVz1AOD_v6/160314_152532/0000/",		// 52 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysVz1_v6/160310_194808/0000/",		// 53 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"NA",												// 54 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysHLT_v11/160321_224347/0000/",	// 55 PbPb HP  AOD  |eta|<1, calo, no eff, L1MinBias HLT
	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysHLT_v12/160330_184734/0000/",	// 56 PbPb HP  AOD  |eta|<1, calo, no eff, L1MinBias HLT

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_v13/160405_110427/0000/",		// 57 PbPb HP AOD final cuts
	"../PbPb2015/HIMinimumBias1/crab_HIMB1_cal_noeff_v13/160405_125056/0000/",			// 58 MB1
	"../PbPb2015/HIMinimumBias2/crab_HIMB2_cal_noeff_v13/160405_125109/0000/",			// 59 MB2
	"../PbPb2015//",										// 60 MB3
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_v13/160405_125120/0000/",			// 61 MB4
	"NA",												// 62 MB all

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysEff_v13/160405_114855/0000/",	// 63 PbPb HP AOD sysEff
	"../PbPb2015/HIMinimumBias1//",									// 64 MB1
	"../PbPb2015/HIMinimumBias2//",									// 65 MB2
	"../PbPb2015/HIMinimumBias3//",									// 66 MB3
	"../PbPb2015/HIMinimumBias4//",									// 67 MB4
	"NA",												// 68 MB all

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysCalo_v13/160405_114810/0000/",	// 69 PbPb HP AOD sysCalo
	"../PbPb2015/HIMinimumBias1//",									// 70 MB1
	"../PbPb2015/HIMinimumBias2//",									// 71 MB2
	"../PbPb2015/HIMinimumBias3//",									// 72 MB3
	"../PbPb2015/HIMinimumBias4//",									// 73 MB4
	"NA",												// 74 MB all

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysTight_v13/160405_114818/0000/",	// 75 PbPb HP AOD sysTight
	"../PbPb2015/HIMinimumBias1//",									// 76 MB1
	"../PbPb2015/HIMinimumBias2//",									// 77 MB2
	"../PbPb2015/HIMinimumBias3//",									// 78 MB3
	"../PbPb2015/HIMinimumBias4//",									// 79 MB4
	"NA",												// 80 MB all

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysLoose_v13/160405_114827/0000/",	// 81 PbPb HP AOD sysLoose
	"../PbPb2015/HIMinimumBias1//",									// 82 MB1
	"../PbPb2015/HIMinimumBias2//",									// 83 MB2
	"../PbPb2015/HIMinimumBias3//",									// 84 MB3
	"../PbPb2015/HIMinimumBias4//",									// 85 MB4
	"NA",												// 86 MB all

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysVz0_v13/160405_114839/0000/",	// 87 PbPb HP AOD sysVz0
	"../PbPb2015/HIMinimumBias1//",									// 88 MB1
	"../PbPb2015/HIMinimumBias2//",									// 89 MB2
	"../PbPb2015/HIMinimumBias3//",									// 90 MB3
	"../PbPb2015/HIMinimumBias4//",									// 91 MB4
	"NA",												// 92 MB all

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysVz1_v13/160405_114847/0000/",	// 93 PbPb HP AOD sysVz1
	"../PbPb2015/HIMinimumBias1//",									// 94 MB1
	"../PbPb2015/HIMinimumBias2//",									// 95 MB2
	"../PbPb2015/HIMinimumBias3//",									// 96 MB3
	"../PbPb2015/HIMinimumBias4//",									// 97 MB4
	"NA",												// 98 MB all
};

char const * ftxt[] = {
	"txt/test/",							// 0
	"txt/HIExpressPhysics_MB_Cumu_v2/",				// 1
	"txt/HIExpressPhysics_MB_Cumu_v3/",				// 2
	"txt/PYTHIA_QCD_HighPt/",					// 3
	"txt/HIExpressPhysics_All_Cumu_v1/",				// 4
	"txt/HIHardProbes_Skim_cumu_v1/",				// 5
	"txt/HIHardProbes_PromptSkim_cumu_v2/",				// 6
	"txt/HIHardProbes_Skim_cumu_v7/",				// 7
	"txt/HIMB1_v3/",						// 8
	"txt/HIMB2_v3/",						// 9
	"txt/HIMB3_v2/",						// 10
	"txt/HIMB4_v3/",						// 11
	"txt/HIMB_v1/",							// 12
	"txt/HIHardProbe_v10/",						// 13
	"txt/HIMB1_v5/",						// 14
	"txt/HIMB2_v5/",						// 15
	"txt/HIMB3_v5/",						// 16
	"txt/HIMB4_v5/",						// 17
	"txt/HIMB_v2/",							// 18
	"txt/HIHardProbe_noeff_v11/",					// 19
	"txt/HIMB1_noeff_v6/",						// 20
	"txt/HIMB2_noeff_v6/",						// 21
	"txt/HIMB3_noeff_v6/",						// 22
	"txt/HIMB4_noeff_v6/",						// 23
	"txt/HIMB_noeff_v3/",						// 24

	"txt/HIHardProbe_noeff_sysCalo_v11/",				// 25
	"txt/HIMB1_noeff_sysCalo_v6/",					// 26
	"txt/HIMB2_noeff_sysCalo_v6/",					// 27
	"txt/HIMB3_noeff_sysCalo_v6/",					// 28
	"txt/HIMB4_noeff_sysCalo_v6/",					// 29
	"txt/HIMB_noeff_sysCalo_v3/",					// 30

	"txt/HIHardProbe_noeff_sysTight_v11/",				// 31
	"txt/HIMB1_noeff_sysTight_v6/",					// 32
	"txt/HIMB2_noeff_sysTight_v6/",					// 33
	"txt/HIMB3_noeff_sysTight_v6/",					// 34
	"txt/HIMB4_noeff_sysTight_v6/",					// 35
	"txt/HIMB_noeff_sysTight_v3/",					// 36

	"txt/HIHardProbe_noeff_sysLoose_v11/",				// 37
	"txt/HIMB1_noeff_sysLoose_v6/",					// 38
	"txt/HIMB2_noeff_sysLoose_v6/",					// 39
	"txt/HIMB3_noeff_sysLoose_v6/",					// 40
	"txt/HIMB4_noeff_sysLoose_v6/",					// 41
	"txt/HIMB_noeff_sysLoose_v3/",					// 42

	"txt/HIHardProbe_noeff_sysVz0_v11/",				// 43
	"txt/HIMB1_noeff_sysVz0_v6/",					// 44
	"txt/HIMB2_noeff_sysVz0_v6/",					// 45
	"txt/HIMB3_noeff_sysVz0_v6/",					// 46
	"txt/HIMB4_noeff_sysVz0_v6/",					// 47
	"txt/HIMB_noeff_sysVz0_v3/",					// 48

	"txt/HIHardProbe_noeff_sysVz1_v11/",				// 49
	"txt/HIMB1_noeff_sysVz1_v6/",					// 50
	"txt/HIMB2_noeff_sysVz1_v6/",					// 51
	"txt/HIMB3_noeff_sysVz1_v6/",					// 52
	"txt/HIMB4_noeff_sysVz1_v6/",					// 53
	"txt/HIMB_noeff_sysVz1_v3/",					// 54

	"txt/HIHardProbe_noeff_sysHLT_v11/",				// 55
	"txt/HIHardProbe_noeff_sysHLT_v12/",				// 56

	"txt/HIHardProbe_noeff_v13/",					// 57
	"txt/HIMB1_noeff_v13/",						// 58
	"txt/HIMB2_noeff_v13/",						// 59
	"txt/HIMB3_noeff_v13/",						// 60
	"txt/HIMB4_noeff_v13/",						// 61
	"txt/HIMB_noeff_v13/",						// 62

	"txt/HIHardProbe_eff_v13/",					// 63
	"txt/HIMB1_eff_v13/",						// 64
	"txt/HIMB2_eff_v13/",						// 65
	"txt/HIMB3_eff_v13/",						// 66
	"txt/HIMB4_eff_v13/",						// 67
	"txt/HIMB_eff_v13/",						// 68

	"txt/HIHardProbe_sysCalo_v13/",					// 69
	"txt/HIMB1_sysCalo_v13/",					// 70
	"txt/HIMB2_sysCalo_v13/",					// 71
	"txt/HIMB3_sysCalo_v13/",					// 72
	"txt/HIMB4_sysCalo_v13/",					// 73
	"txt/HIMB_sysCalo_v13/",					// 74

	"txt/HIHardProbe_sysTight_v13/",				// 75
	"txt/HIMB1_sysTight_v13/",					// 76
	"txt/HIMB2_sysTight_v13/",					// 77
	"txt/HIMB3_sysTight_v13/",					// 78
	"txt/HIMB4_sysTight_v13/",					// 79
	"txt/HIMB_sysTight_v13/",					// 80

	"txt/HIHardProbe_sysLoose_v13/",				// 81
	"txt/HIMB1_sysLoose_v13/",					// 82
	"txt/HIMB2_sysLoose_v13/",					// 83
	"txt/HIMB3_sysLoose_v13/",					// 84
	"txt/HIMB4_sysLoose_v13/",					// 85
	"txt/HIMB_sysLoose_v13/",					// 86

	"txt/HIHardProbe_sysVz0_v13/",					// 87
	"txt/HIMB1_sysVz0_v13/",					// 88
	"txt/HIMB2_sysVz0_v13/",					// 89
	"txt/HIMB3_sysVz0_v13/",					// 90
	"txt/HIMB4_sysVz0_v13/",					// 91
	"txt/HIMB_sysVz0_v13/",						// 92

	"txt/HIHardProbe_sysVz1_v13/",					// 93
	"txt/HIMB1_sysVz1_v13/",					// 94
	"txt/HIMB2_sysVz1_v13/",					// 95
	"txt/HIMB3_sysVz1_v13/",					// 96
	"txt/HIMB4_sysVz1_v13/",					// 97
	"txt/HIMB_sysVz1_v13/",						// 98
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
