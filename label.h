
char * fname[] = {
	"test/",			// 0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1/", 			// 1 pPb HLT std closed
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_rereco/", 			// 2 pPb HLT rereco std closed
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_reverse/", 		// 3 pPb HLT reverse std closed
	"NA", 									// 4 1+2+3 pPb HLT std closed
	"../MC/PionFlatPt_M200/", 						// 5 Flat pT M200
	"../MC/PionExpoPt_M200/", 						// 6 Expo pT M200
	"../pPb/Pbp_HLT_rfp24_Noff_noacc_noeff_v12_cm1/", 			// 7 Pbp HLT std closed reversed eta
	"NA", 									// 8 1+2+7 pPb HLT std closed
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v15_cm1/", 			// 9 pPb HLT std closed fixed poi pt
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v15_cm1_rereco/", 		// 10 pPb HLT std closed fixed poi pt
	"../pPb/Pbp_HLT_rfp24_Noff_noacc_noeff_v15_cm1/", 			// 11 pPb HLT std closed fixed poi pt
	"NA", 									// 12 9+10+11 pPb HLT std closed fixed poi pt
	"../pPb/pPb_HLT_rfppos_Noff_noacc_noeff_v15_cm1/", 			// 13 pPb HLT std closed rfp eta > 0
	"../pPb/pPb_HLT_rfppos_Noff_noacc_noeff_v15_cm1_rereco/", 		// 14 pPb HLT std closed rfp eta > 0
	"../pPb/Pbp_HLT_rfppos_Noff_noacc_noeff_v15_cm1/", 			// 15 pPb HLT std closed rfp eta > 0
	"NA", 									// 16 13+14+15 pPb HLT std closed rfp eta > 0
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_noeff_v15_cm1/", 			// 17 pPb HLT std closed rfp eta < 0
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_noeff_v15_cm1_rereco/", 		// 18 pPb HLT std closed rfp eta < 0
	"../pPb/Pbp_HLT_rfpneg_Noff_noacc_noeff_v15_cm1/", 			// 19 pPb HLT std closed rfp eta < 0
	"NA", 									// 20 17+18+19 pPb HLT std closed rfp eta < 0
	"../pPb/pPb_HLT_rfppos_poipos_Noff_noacc_noeff_v15_cm1/", 		// 21 pPb HLT std closed rfp eta > 0 poi eta > 0
	"../pPb/pPb_HLT_rfppos_poipos_Noff_noacc_noeff_v15_cm1_rereco/", 	// 22 pPb HLT std closed rfp eta > 0 poi eta > 0
	"../pPb/Pbp_HLT_rfppos_poipos_Noff_noacc_noeff_v15_cm1/", 		// 23 pPb HLT std closed rfp eta > 0 poi eta > 0
	"NA", 									// 24 21+22+23 pPb HLT std closed rfp eta > 0 poi eta > 0
	"../pPb/pPb_HLT_rfpneg_poineg_Noff_noacc_noeff_v15_cm1/", 		// 25 pPb HLT std closed rfp eta > 0 poi eta > 0
	"../pPb/pPb_HLT_rfpneg_poineg_Noff_noacc_noeff_v15_cm1_rereco/", 	// 26 pPb HLT std closed rfp eta > 0 poi eta > 0
	"../pPb/Pbp_HLT_rfpneg_poineg_Noff_noacc_noeff_v15_cm1/", 		// 27 pPb HLT std closed rfp eta > 0 poi eta > 0
	"NA", 									// 28 25+26+27 pPb HLT std closed rfp eta > 0 poi eta > 0
};

char * ftxt[] = {
	"txt/test/",								// 0
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1/",				// 1
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_rereco/",			// 2
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_reverse/",			// 3
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_full/",			// 4
	"txt/PionFlatPt_M200/",			// 5
	"txt/PionExpoPt_M200/",			// 6
	"txt/Pbp_HLT_rfp24_Noff_noacc_noeff_v12_cm1/",				// 7
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_full_reverse/",		// 8
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v15_cm1/",				// 9
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v15_cm1_rereco/",			// 10
	"txt/Pbp_HLT_rfp24_Noff_noacc_noeff_v15_cm1/",				// 11
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v15_cm1_full_reverse/",		// 12
	"txt/pPb_HLT_rfppos_Noff_noacc_noeff_v15_cm1/",				// 13
	"txt/pPb_HLT_rfppos_Noff_noacc_noeff_v15_cm1_rereco/",			// 14
	"txt/Pbp_HLT_rfppos_Noff_noacc_noeff_v15_cm1/",				// 15
	"txt/Pbp_HLT_rfppos_Noff_noacc_noeff_v15_cm1_full_reverse/",		// 16
	"txt/pPb_HLT_rfpneg_Noff_noacc_noeff_v15_cm1/",				// 17
	"txt/pPb_HLT_rfpneg_Noff_noacc_noeff_v15_cm1_rereco/",			// 18
	"txt/Pbp_HLT_rfpneg_Noff_noacc_noeff_v15_cm1/",				// 19
	"txt/Pbp_HLT_rfpneg_Noff_noacc_noeff_v15_cm1_full_reverse/",		// 20
	"txt/pPb_HLT_rfppos_poipos_Noff_noacc_noeff_v15_cm1/",			// 21
	"txt/pPb_HLT_rfppos_poipos_Noff_noacc_noeff_v15_cm1_rereco/",		// 22
	"txt/Pbp_HLT_rfppos_poipos_Noff_noacc_noeff_v15_cm1/",			// 23
	"txt/pPb_HLT_rfppos_poipos_Noff_noacc_noeff_v15_cm1_full_reverse/",	// 24
	"txt/pPb_HLT_rfpneg_poineg_Noff_noacc_noeff_v15_cm1/",			// 25
	"txt/pPb_HLT_rfpneg_poineg_Noff_noacc_noeff_v15_cm1_rereco/",		// 26
	"txt/Pbp_HLT_rfpneg_poineg_Noff_noacc_noeff_v15_cm1/",			// 27
	"txt/pPb_HLT_rfpneg_poineg_Noff_noacc_noeff_v15_cm1_full_reverse/",	// 28
};

void addchain(int s1)
{
	cout << fname[s1] << endl;
	chV->Add(Form("%s/*.root/cumulant/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant100/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant130/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant160/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant190/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant220/trV", fname[s1]));
}
