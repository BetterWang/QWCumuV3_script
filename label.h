
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
	"../PbPb2015/HIMinimumBias1/crab_HIMB1_cal_noeff_v6/",						// 20 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 
	"../PbPb2015/HIMinimumBias2/crab_HIMB2_cal_noeff_v6/",						// 21 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_v6/160303_223848/0000/",			// 22 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_v6/160306_234511/0000/",			// 23 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0
	"NA",												// 24 PbPb MB1,2,3,4 20+21+22+23 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysCalo_v11/160309_212811/0000/",	// 25 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias1//",									// 26 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias2//",									// 27 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysCalo_v6/",					// 28 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysCalo_v6/",					// 29 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo
	"NA",												// 30 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 no calo

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysTight_v11/",			// 31 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias1//",									// 32 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias2//",									// 33 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysTight_v6/",					// 34 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysTight_v6/",					// 35 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight
	"NA",												// 36 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 tight

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysLoose_v11/",			// 37 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias1//",									// 38 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias2//",									// 39 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysLoose_v6/",					// 40 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysLoose_v6/",					// 41 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose
	"NA",												// 42 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 loose

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysVz0_v11/",			// 43 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias1//",									// 44 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias2//",									// 45 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysVz0_v6/",					// 46 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysVz0_v6/",					// 47 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0
	"NA",												// 48 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz0

	"../PbPb2015/HIHardProbes/crab_HIHardProbes_Skim_cumu_noeff_sysVz1_v11/",			// 49 PbPb HP  AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias1//",									// 50 PbPb MB1 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias2//",									// 51 PbPb MB2 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias3/crab_HIMB3_cal_noeff_sysVz1_v6/",					// 52 PbPb MB3 Skim |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"../PbPb2015/HIMinimumBias4/crab_HIMB4_cal_noeff_sysVz1_v6/",					// 53 PbPb MB4 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
	"NA",												// 54 PbPb MB1,2,3,4 26+27+28+29 AOD  |eta|<1, calo, no eff, 1.0 < pt_ref < 5.0 Vz1
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
