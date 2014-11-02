
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
	"../pPb/pPb_HLT_rfp24_poipos_Noff_noacc_noeff_cm1/", 			// 29 pPb HLT std closed rfp 24 poi eta > 0
	"../pPb/pPb_HLT_rfp24_poipos_Noff_noacc_noeff_cm1_rereco/", 		// 30 pPb HLT std closed rfp 24 poi eta > 0
	"../pPb/Pbp_HLT_rfp24_poipos_Noff_noacc_noeff_cm1/", 			// 31 Pbp HLT std closed rfp 24 poi eta > 0
	"NA", 									// 32 29+30+31 pPb HLT std closed rfp 24 poi eta > 0
	"../pPb/pPb_HLT_rfp24_poineg_Noff_noacc_noeff_cm1/", 			// 33 pPb HLT std closed rfp 24 poi eta < 0
	"../pPb/pPb_HLT_rfp24_poineg_Noff_noacc_noeff_cm1_rereco/", 		// 34 pPb HLT std closed rfp 24 poi eta < 0
	"../pPb/Pbp_HLT_rfp24_poineg_Noff_noacc_noeff_cm1/", 			// 35 Pbp HLT std closed rfp 24 poi eta < 0
	"NA", 									// 36 33+34+35 pPb HLT std closed rfp 24 poi eta < 0
	"../pPb/pPb_HLT_rfp24_poi0_Noff_noacc_noeff_cm1/", 			// 37 pPb HLT std closed rfp 24 poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfp24_poi0_Noff_noacc_noeff_cm1_rereco/", 		// 38 pPb HLT std closed rfp 24 poi eta -2.4, -1.2
	"../pPb/Pbp_HLT_rfp24_poi0_Noff_noacc_noeff_cm1/", 			// 39 Pbp HLT std closed rfp 24 poi eta -2.4, -1.2
	"NA", 									// 40 33+34+35 pPb HLT std closed rfp 24 poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfp24_poi1_Noff_noacc_noeff_cm1/", 			// 41 pPb HLT std closed rfp 24 poi eta -1.2, 0
	"../pPb/pPb_HLT_rfp24_poi1_Noff_noacc_noeff_cm1_rereco/", 		// 42 pPb HLT std closed rfp 24 poi eta -1.2, 0
	"../pPb/Pbp_HLT_rfp24_poi1_Noff_noacc_noeff_cm1/", 			// 43 Pbp HLT std closed rfp 24 poi eta -1.2, 0
	"NA", 									// 44 37+38+39 pPb HLT std closed rfp 24 poi eta -1.2, 0
	"../pPb/pPb_HLT_rfp24_poi2_Noff_noacc_noeff_cm1/", 			// 45 pPb HLT std closed rfp 24 poi eta 0, 1.2
	"../pPb/pPb_HLT_rfp24_poi2_Noff_noacc_noeff_cm1_rereco/", 		// 46 pPb HLT std closed rfp 24 poi eta 0, 1.2
	"../pPb/Pbp_HLT_rfp24_poi2_Noff_noacc_noeff_cm1/", 			// 47 Pbp HLT std closed rfp 24 poi eta 0, 1.2
	"NA", 									// 48 41+42+43 pPb HLT std closed rfp 24 poi eta 0, 1.2
	"../pPb/pPb_HLT_rfp24_poi3_Noff_noacc_noeff_cm1/", 			// 49 pPb HLT std closed rfp 24 poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfp24_poi3_Noff_noacc_noeff_cm1_rereco/", 		// 49 pPb HLT std closed rfp 24 poi eta 1.2, 2.4
	"../pPb/Pbp_HLT_rfp24_poi3_Noff_noacc_noeff_cm1/", 			// 51 Pbp HLT std closed rfp 24 poi eta 1.2, 2.4
	"NA", 									// 52 45+46+47 pPb HLT std closed rfp 24 poi eta 1.2, 2.4
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
	"txt/pPb_HLT_rfp24_poipos_Noff_noacc_noeff_cm1/",			// 29
	"txt/pPb_HLT_rfp24_poipos_Noff_noacc_noeff_cm1_rereco/",		// 30
	"txt/Pbp_HLT_rfp24_poipos_Noff_noacc_noeff_cm1/",			// 31
	"txt/pPb_HLT_rfp24_poipos_Noff_noacc_noeff_cm1_full_reverse/",		// 32
	"txt/pPb_HLT_rfp24_poineg_Noff_noacc_noeff_cm1/",			// 33
	"txt/pPb_HLT_rfp24_poineg_Noff_noacc_noeff_cm1_rereco/",		// 34
	"txt/Pbp_HLT_rfp24_poineg_Noff_noacc_noeff_cm1/",			// 35
	"txt/pPb_HLT_rfp24_poineg_Noff_noacc_noeff_cm1_full_reverse/",		// 36
	"txt/pPb_HLT_rfp24_poi0_Noff_noacc_noeff_cm1/",				// 37
	"txt/pPb_HLT_rfp24_poi0_Noff_noacc_noeff_cm1_rereco/",			// 38
	"txt/Pbp_HLT_rfp24_poi0_Noff_noacc_noeff_cm1/",				// 39
	"txt/pPb_HLT_rfp24_poi0_Noff_noacc_noeff_cm1_full_reverse/",		// 40
	"txt/pPb_HLT_rfp24_poi1_Noff_noacc_noeff_cm1/",				// 41
	"txt/pPb_HLT_rfp24_poi1_Noff_noacc_noeff_cm1_rereco/",			// 42
	"txt/Pbp_HLT_rfp24_poi1_Noff_noacc_noeff_cm1/",				// 43
	"txt/pPb_HLT_rfp24_poi1_Noff_noacc_noeff_cm1_full_reverse/",		// 44
	"txt/pPb_HLT_rfp24_poi2_Noff_noacc_noeff_cm1/",				// 45
	"txt/pPb_HLT_rfp24_poi2_Noff_noacc_noeff_cm1_rereco/",			// 46
	"txt/Pbp_HLT_rfp24_poi2_Noff_noacc_noeff_cm1/",				// 47
	"txt/pPb_HLT_rfp24_poi2_Noff_noacc_noeff_cm1_full_reverse/",		// 48
	"txt/pPb_HLT_rfp24_poi3_Noff_noacc_noeff_cm1/",				// 49
	"txt/pPb_HLT_rfp24_poi3_Noff_noacc_noeff_cm1_rereco/",			// 50
	"txt/Pbp_HLT_rfp24_poi3_Noff_noacc_noeff_cm1/",				// 51
	"txt/pPb_HLT_rfp24_poi3_Noff_noacc_noeff_cm1_full_reverse/",		// 52
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
