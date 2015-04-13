
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
	"../MC/PionFlatPt_M200_rfppos_poipos/", 				// 53 Flat pT M200 rfp eta > 0, poi eta > 0
	"../MC/PionFlatPt_M200_rfppos_poineg/", 				// 54 Flat pT M200 rfp eta > 0, poi eta < 0
	"../pPb/pPb_HLT_rfppos_poi0_Noff_noacc_noeff_cm1/", 			// 55 pPb HLT std closed rfp pos poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfppos_poi0_Noff_noacc_noeff_cm1_rereco/",		// 56 pPb HLT std closed rfp pos poi eta -2.4, -1.2
	"../pPb/Pbp_HLT_rfppos_poi0_Noff_noacc_noeff_cm1/",			// 57 pPb HLT std closed rfp pos poi eta -2.4, -1.2
	"NA",									// 58 pPb HLT std closed rfp pos poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfppos_poi1_Noff_noacc_noeff_cm1/", 			// 59 pPb HLT std closed rfp pos poi eta -1.2, 0
	"../pPb/pPb_HLT_rfppos_poi1_Noff_noacc_noeff_cm1_rereco/",		// 60 pPb HLT std closed rfp pos poi eta -1.2, 0
	"../pPb/Pbp_HLT_rfppos_poi1_Noff_noacc_noeff_cm1/",			// 61 pPb HLT std closed rfp pos poi eta -1.2, 0
	"NA",									// 62 pPb HLT std closed rfp pos poi eta -1.2, 0
	"../pPb/pPb_HLT_rfppos_poi2_Noff_noacc_noeff_cm1/", 			// 63 pPb HLT std closed rfp pos poi eta 0, 1.2
	"../pPb/pPb_HLT_rfppos_poi2_Noff_noacc_noeff_cm1_rereco/",		// 64 pPb HLT std closed rfp pos poi eta 0, 1.2
	"../pPb/Pbp_HLT_rfppos_poi2_Noff_noacc_noeff_cm1/",			// 65 pPb HLT std closed rfp pos poi eta 0, 1.2
	"NA",									// 66 pPb HLT std closed rfp pos poi eta 0, 1.2
	"../pPb/pPb_HLT_rfppos_poi3_Noff_noacc_noeff_cm1/", 			// 67 pPb HLT std closed rfp pos poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfppos_poi3_Noff_noacc_noeff_cm1_rereco/",		// 68 pPb HLT std closed rfp pos poi eta 1.2, 2.4
	"../pPb/Pbp_HLT_rfppos_poi3_Noff_noacc_noeff_cm1/",			// 69 pPb HLT std closed rfp pos poi eta 1.2, 2.4
	"NA",									// 70 pPb HLT std closed rfp pos poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfpneg_poi0_Noff_noacc_noeff_cm1/", 			// 71 pPb HLT std closed rfp neg poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfpneg_poi0_Noff_noacc_noeff_cm1_rereco/",		// 72 pPb HLT std closed rfp neg poi eta -2.4, -1.2
	"../pPb/Pbp_HLT_rfpneg_poi0_Noff_noacc_noeff_cm1/",			// 73 pPb HLT std closed rfp neg poi eta -2.4, -1.2
	"NA",									// 74 pPb HLT std closed rfp neg poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfpneg_poi1_Noff_noacc_noeff_cm1/", 			// 75 pPb HLT std closed rfp neg poi eta -1.2, 0
	"../pPb/pPb_HLT_rfpneg_poi1_Noff_noacc_noeff_cm1_rereco/",		// 76 pPb HLT std closed rfp neg poi eta -1.2, 0
	"../pPb/Pbp_HLT_rfpneg_poi1_Noff_noacc_noeff_cm1/",			// 77 pPb HLT std closed rfp neg poi eta -1.2, 0
	"NA",									// 78 pPb HLT std closed rfp neg poi eta -1.2, 0
	"../pPb/pPb_HLT_rfpneg_poi2_Noff_noacc_noeff_cm1/", 			// 79 pPb HLT std closed rfp neg poi eta 0, 1.2
	"../pPb/pPb_HLT_rfpneg_poi2_Noff_noacc_noeff_cm1_rereco/",		// 80 pPb HLT std closed rfp neg poi eta 0, 1.2
	"../pPb/Pbp_HLT_rfpneg_poi2_Noff_noacc_noeff_cm1/",			// 81 pPb HLT std closed rfp neg poi eta 0, 1.2
	"NA",									// 82 pPb HLT std closed rfp neg poi eta 0, 1.2
	"../pPb/pPb_HLT_rfpneg_poi3_Noff_noacc_noeff_cm1/", 			// 83 pPb HLT std closed rfp neg poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfpneg_poi3_Noff_noacc_noeff_cm1_rereco/",		// 84 pPb HLT std closed rfp neg poi eta 1.2, 2.4
	"../pPb/Pbp_HLT_rfpneg_poi3_Noff_noacc_noeff_cm1/",			// 85 pPb HLT std closed rfp neg poi eta 1.2, 2.4
	"NA",									// 86 pPb HLT std closed rfp neg poi eta 1.2, 2.4
	"../MC/PionFlatPt_M200_rfpneg_poipos/", 				// 87 Flat pT M200 rfp eta < 0, poi eta > 0
	"../MC/PionFlatPt_M200_rfpneg_poineg/", 				// 88 Flat pT M200 rfp eta < 0, poi eta < 0
	"../MC/PionFlatPt_M200_rfppos_poipos_D2/", 				// 89 Flat pT M200 rfp eta > 0, poi eta > 0 pos 2*v2
	"../MC/PionFlatPt_M200_rfppos_poineg_D2/", 				// 90 Flat pT M200 rfp eta > 0, poi eta < 0 pos 2*v2
	"../MC/PionFlatPt_M200_rfpneg_poipos_D2/", 				// 91 Flat pT M200 rfp eta < 0, poi eta > 0 pos 2*v2
	"../MC/PionFlatPt_M200_rfpneg_poineg_D2/", 				// 92 Flat pT M200 rfp eta < 0, poi eta < 0 pos 2*v2
	"../MC/PionFlatPt_M200_rfppos_poipos_D1/", 				// 93 Flat pT M200 rfp eta > 0, poi eta > 0 neg 2*v2
	"../MC/PionFlatPt_M200_rfppos_poineg_D1/", 				// 94 Flat pT M200 rfp eta > 0, poi eta < 0 neg 2*v2
	"../MC/PionFlatPt_M200_rfpneg_poipos_D1/", 				// 95 Flat pT M200 rfp eta < 0, poi eta > 0 neg 2*v2
	"../MC/PionFlatPt_M200_rfpneg_poineg_D1/", 				// 96 Flat pT M200 rfp eta < 0, poi eta < 0 neg 2*v2
	"../MC/PionFlatPt_M200_rfppos_poipos_D3/", 				// 97 Flat pT M200 rfp eta > 0, poi eta > 0 neg .5*v2
	"../MC/PionFlatPt_M200_rfppos_poineg_D3/", 				// 98 Flat pT M200 rfp eta > 0, poi eta < 0 neg .5*v2
	"../MC/PionFlatPt_M200_rfpneg_poipos_D3/", 				// 99 Flat pT M200 rfp eta < 0, poi eta > 0 neg .5*v2
	"../MC/PionFlatPt_M200_rfpneg_poineg_D3/", 				// 100 Flat pT M200 rfp eta < 0, poi eta < 0 neg .5*v2
	"../MC/PionFlatPt_M200_rfppos_poipos_D4/", 				// 101 Flat pT M200 rfp eta > 0, poi eta > 0 pos .5*v2
	"../MC/PionFlatPt_M200_rfppos_poineg_D4/", 				// 102 Flat pT M200 rfp eta > 0, poi eta < 0 pos .5*v2
	"../MC/PionFlatPt_M200_rfpneg_poipos_D4/", 				// 103 Flat pT M200 rfp eta < 0, poi eta > 0 pos .5*v2
	"../MC/PionFlatPt_M200_rfpneg_poineg_D4/", 				// 104 Flat pT M200 rfp eta < 0, poi eta < 0 pos .5*v2
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_cm1/", 				// 105 pPb HLT std closed rfp full, eff applied
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_cm1_rereco/", 			// 106 pPb HLT std closed rfp full, eff applied
	"../pPb/Pbp_HLT_rfp24_Noff_noacc_eff_cm1/", 				// 107 pPb HLT std closed rfp full, eff applied
	"NA", 									// 108 pPb HLT std closed rfp full, eff applied
	"../pPb/PbPb_ppreco_rfp24_Noff_noacc_eff", 				// 109 PbPb pp-rereco std closed rfp full, eff applied
	"../MC/PionFlatPt_M200_rfp24_poi24/", 					// 110 Flat pT M200 rfp full, poi full
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysTight/", 			// 111 pPb HLT std colsed rfp24 poi24, tracking tight cut
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysTight_rereco/", 		// 112 pPb HLT std colsed rfp24 poi24, tracking tight cut
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysTight_reverse/", 		// 113 pPb HLT std colsed rfp24 poi24, tracking tight cut
	"NA", 									// 114 pPb HLT std colsed rfp24 poi24, tracking tight cut
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysLoose/", 			// 115 pPb HLT std colsed rfp24 poi24, tracking loose cut
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysLoose_rereco/", 		// 116 pPb HLT std colsed rfp24 poi24, tracking loose cut
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysLoose_reverse/", 		// 117 pPb HLT std colsed rfp24 poi24, tracking loose cut
	"NA", 									// 118 pPb HLT std colsed rfp24 poi24, tracking loose cut
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0/", 			// 119 pPb HLT std colsed rfp24 poi24, |vz| < 3
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0_rereco/", 			// 120 pPb HLT std colsed rfp24 poi24, |vz| < 3
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0_reverse/", 		// 121 pPb HLT std colsed rfp24 poi24, |vz| < 3
	"NA", 									// 122 pPb HLT std colsed rfp24 poi24, |vz| < 3
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1/", 			// 123 pPb HLT std colsed rfp24 poi24, 3 < |vz| < 15
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1_rereco/", 			// 124 pPb HLT std colsed rfp24 poi24, 3 < |vz| < 15
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1_reverse/", 		// 125 pPb HLT std colsed rfp24 poi24, 3 < |vz| < 15
	"NA", 									// 126 pPb HLT std colsed rfp24 poi24, 3 < |vz| < 15
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
	"txt/PionFlatPt_M200_rfppos_poipos/", 					// 53
	"txt/PionFlatPt_M200_rfppos_poineg/", 					// 54
	"txt/pPb_HLT_rfppos_poi0_Noff_noacc_noeff_cm1/", 			// 55
	"txt/pPb_HLT_rfppos_poi0_Noff_noacc_noeff_cm1_rereco/", 		// 56
	"txt/Pbp_HLT_rfppos_poi0_Noff_noacc_noeff_cm1/", 			// 57
	"txt/pPb_HLT_rfppos_poi0_Noff_noacc_noeff_cm1_full_reverse/", 		// 58
	"txt/pPb_HLT_rfppos_poi1_Noff_noacc_noeff_cm1/", 			// 59
	"txt/pPb_HLT_rfppos_poi1_Noff_noacc_noeff_cm1_rereco/", 		// 60
	"txt/Pbp_HLT_rfppos_poi1_Noff_noacc_noeff_cm1/", 			// 61
	"txt/pPb_HLT_rfppos_poi1_Noff_noacc_noeff_cm1_full_reverse/", 		// 62
	"txt/pPb_HLT_rfppos_poi2_Noff_noacc_noeff_cm1/", 			// 63
	"txt/pPb_HLT_rfppos_poi2_Noff_noacc_noeff_cm1_rereco/", 		// 64
	"txt/Pbp_HLT_rfppos_poi2_Noff_noacc_noeff_cm1/", 			// 65
	"txt/pPb_HLT_rfppos_poi2_Noff_noacc_noeff_cm1_full_reverse/", 		// 66
	"txt/pPb_HLT_rfppos_poi3_Noff_noacc_noeff_cm1/", 			// 67
	"txt/pPb_HLT_rfppos_poi3_Noff_noacc_noeff_cm1_rereco/", 		// 68
	"txt/Pbp_HLT_rfppos_poi3_Noff_noacc_noeff_cm1/", 			// 69
	"txt/pPb_HLT_rfppos_poi3_Noff_noacc_noeff_cm1_full_reverse/", 		// 70
	"txt/pPb_HLT_rfpneg_poi0_Noff_noacc_noeff_cm1/", 			// 71
	"txt/pPb_HLT_rfpneg_poi0_Noff_noacc_noeff_cm1_rereco/", 		// 72
	"txt/Pbp_HLT_rfpneg_poi0_Noff_noacc_noeff_cm1/", 			// 73
	"txt/pPb_HLT_rfpneg_poi0_Noff_noacc_noeff_cm1_full_reverse/", 		// 74
	"txt/pPb_HLT_rfpneg_poi1_Noff_noacc_noeff_cm1/", 			// 75
	"txt/pPb_HLT_rfpneg_poi1_Noff_noacc_noeff_cm1_rereco/", 		// 76
	"txt/Pbp_HLT_rfpneg_poi1_Noff_noacc_noeff_cm1/", 			// 77
	"txt/pPb_HLT_rfpneg_poi1_Noff_noacc_noeff_cm1_full_reverse/", 		// 78
	"txt/pPb_HLT_rfpneg_poi2_Noff_noacc_noeff_cm1/", 			// 79
	"txt/pPb_HLT_rfpneg_poi2_Noff_noacc_noeff_cm1_rereco/", 		// 80
	"txt/Pbp_HLT_rfpneg_poi2_Noff_noacc_noeff_cm1/", 			// 81
	"txt/pPb_HLT_rfpneg_poi2_Noff_noacc_noeff_cm1_full_reverse/", 		// 82
	"txt/pPb_HLT_rfpneg_poi3_Noff_noacc_noeff_cm1/", 			// 83
	"txt/pPb_HLT_rfpneg_poi3_Noff_noacc_noeff_cm1_rereco/", 		// 84
	"txt/Pbp_HLT_rfpneg_poi3_Noff_noacc_noeff_cm1/", 			// 85
	"txt/pPb_HLT_rfpneg_poi3_Noff_noacc_noeff_cm1_full_reverse/", 		// 86
	"txt/PionFlatPt_M200_rfpneg_poipos/", 					// 87
	"txt/PionFlatPt_M200_rfpneg_poineg/", 					// 88
	"txt/PionFlatPt_M200_rfppos_poipos_D2/", 				// 89
	"txt/PionFlatPt_M200_rfppos_poineg_D2/", 				// 90
	"txt/PionFlatPt_M200_rfpneg_poipos_D2/", 				// 91
	"txt/PionFlatPt_M200_rfpneg_poineg_D2/", 				// 92
	"txt/PionFlatPt_M200_rfppos_poipos_D1/", 				// 93
	"txt/PionFlatPt_M200_rfppos_poineg_D1/", 				// 94
	"txt/PionFlatPt_M200_rfpneg_poipos_D1/", 				// 95
	"txt/PionFlatPt_M200_rfpneg_poineg_D1/", 				// 96
	"txt/PionFlatPt_M200_rfppos_poipos_D3/", 				// 97
	"txt/PionFlatPt_M200_rfppos_poineg_D3/", 				// 98
	"txt/PionFlatPt_M200_rfpneg_poipos_D3/", 				// 99
	"txt/PionFlatPt_M200_rfpneg_poineg_D3/", 				// 100
	"txt/PionFlatPt_M200_rfppos_poipos_D4/", 				// 101
	"txt/PionFlatPt_M200_rfppos_poineg_D4/", 				// 102
	"txt/PionFlatPt_M200_rfpneg_poipos_D4/", 				// 103
	"txt/PionFlatPt_M200_rfpneg_poineg_D4/", 				// 104
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1/", 				// 105
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1_rereco/", 			// 106
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1_reverse/", 			// 107
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1_full_reverse/", 			// 108
	"txt/PbPb_ppreco_rfp24_Noff_noacc_eff/", 				// 109
	"txt/PionFlatPt_M200_rfp24_poi24/", 					// 110
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysTight/", 				// 111 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysTight_rereco/", 			// 112 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysTight_reverse/", 			// 113 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysTight_full/", 			// 114 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysLoose/", 				// 115 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysLoose_rereco/", 			// 116 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysLoose_reverse/", 			// 117 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysLoose_full/", 			// 118 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0/", 				// 119 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0_rereco/", 			// 120 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0_reverse/", 			// 121 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0_full/", 			// 122 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1/", 				// 123 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1_rereco/", 			// 124 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1_reverse/", 			// 125 
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1_full/", 			// 126 
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
