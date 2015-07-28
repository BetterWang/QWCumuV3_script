
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
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_sysTight/",			// 127 PbPb HLT std colsed rfp24 poi24, tracking tight
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_sysLoose/",			// 128 PbPb HLT std colsed rfp24 poi24, tracking loose
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_sysVtx0/",			// 129 PbPb HLT std colsed rfp24 poi24, |vz| < 3
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_sysVtx1/",			// 130 PbPb HLT std colsed rfp24 poi24, 3 < |vz| < 15
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_sysEff/",				// 131 PbPb HLT std colsed rfp24 poi24, eff
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysEff/",				// 132 pPb HLT std colsed rfp24 poi24, eff
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysEff_rereco/",			// 133 pPb HLT std colsed rfp24 poi24, eff
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysEff_reverse/",			// 134 pPb HLT std colsed rfp24 poi24, eff
	"NA",									// 135 pPb HLT std colsed rfp24 poi24, eff
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18/",				// 136 pPb HLT std colsed rfp24 poi24, v18
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_cm1_rereco_v18/",			// 137 pPb HLT std colsed rfp24 poi24, v18
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_cm1_reverse_v18/",			// 138 pPb HLT std colsed rfp24 poi24, v18
	"NA",									// 139 pPb HLT std colsed rfp24 poi24, v18
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_Prompt_cm1/",			// 140 pPb HLT std colsed rfp24 poi24, Prompt
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_Prompt_cm1_rereco/",		// 141 pPb HLT std colsed rfp24 poi24, Prompt
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_Prompt_cm1_reverse/",		// 142 pPb HLT std colsed rfp24 poi24, Prompt
	"NA",									// 143 pPb HLT std colsed rfp24 poi24, Prompt
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysHLT/",				// 144 pPb HLT std colsed rfp24 poi24, HLT trigger
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysHLT_rereco/",			// 145 pPb HLT std colsed rfp24 poi24, HLT trigger
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysHLT_reverse/",			// 146 pPb HLT std colsed rfp24 poi24, HLT trigger
	"NA",									// 147 pPb HLT std colsed rfp24 poi24, HLT trigger
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysPU/",				// 148 pPb HLT std colsed rfp24 poi24, PU rejection, single vtx
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysPU_rereco/",			// 149 pPb HLT std colsed rfp24 poi24, PU rejection, single vtx
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_sysPU_reverse/",			// 150 pPb HLT std colsed rfp24 poi24, PU rejection, single vtx
	"NA",									// 151 pPb HLT std colsed rfp24 poi24,
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_GT/",				// 152 pPb HLT std colsed rfp24 poi24, GR_P_V43D::All
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_GT_rereco/",			// 153 pPb HLT std colsed rfp24 poi24, GR_P_V43D::All
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_GT_reverse/",			// 154 pPb HLT std colsed rfp24 poi24, GR_P_V43D::All
	"NA",									// 155 pPb HLT std colsed rfp24 poi24,
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta0/",				// 156 pPb HLT std colsed rfp eta, -2.4, -1.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta0_rereco/",			// 157 pPb HLT std colsed rfp eta, -2.4, -1.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta0_reverse/",			// 158 pPb HLT std colsed rfp eta, -2.4, -1.8
	"NA",									// 159 pPb HLT std colsed rfp eta, -2.4, -1.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta1/",				// 160 pPb HLT std colsed rfp eta, -1.8, -1.2
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta1_rereco/",			// 161 pPb HLT std colsed rfp eta, -1.8, -1.2
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta1_reverse/",			// 162 pPb HLT std colsed rfp eta, -1.8, -1.2
	"NA",									// 163 pPb HLT std colsed rfp eta, -1.8, -1.2
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta2/",				// 164 pPb HLT std colsed rfp eta, -1.2, -0.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta2_rereco/",			// 165 pPb HLT std colsed rfp eta, -1.2, -0.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta2_reverse/",			// 166 pPb HLT std colsed rfp eta, -1.2, -0.6
	"NA",									// 167 pPb HLT std colsed rfp eta, -1.2, -0.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta3/",				// 168 pPb HLT std colsed rfp eta, -0.6, -0.0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta3_rereco/",			// 169 pPb HLT std colsed rfp eta, -0.6, -0.0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta3_reverse/",			// 170 pPb HLT std colsed rfp eta, -0.6, -0.0
	"NA",									// 171 pPb HLT std colsed rfp eta, -0.6, -0.0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta4/",				// 172 pPb HLT std colsed rfp eta, -0.0, 0.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta4_rereco/",			// 173 pPb HLT std colsed rfp eta, -0.0, 0.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta4_reverse/",			// 174 pPb HLT std colsed rfp eta, -0.0, 0.6
	"NA",									// 175 pPb HLT std colsed rfp eta, -0.0, 0.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta5/",				// 176 pPb HLT std colsed rfp eta, 0.6, 1.2
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta5_rereco/",			// 177 pPb HLT std colsed rfp eta, 0.6, 1.2
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta5_reverse/",			// 178 pPb HLT std colsed rfp eta, 0.6, 1.2
	"NA",									// 179 pPb HLT std colsed rfp eta, 0.6, 1.2
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta6/",				// 180 pPb HLT std colsed rfp eta, 1.2, 1.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta6_rereco/",			// 181 pPb HLT std colsed rfp eta, 1.2, 1.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta6_reverse/",			// 182 pPb HLT std colsed rfp eta, 1.2, 1.8
	"NA",									// 183 pPb HLT std colsed rfp eta, 1.2, 1.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta7/",				// 184 pPb HLT std colsed rfp eta, 1.8, 2.4
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta7_rereco/",			// 185 pPb HLT std colsed rfp eta, 1.8, 2.4
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_eta7_reverse/",			// 186 pPb HLT std colsed rfp eta, 1.8, 2.4
	"NA",									// 187 pPb HLT std colsed rfp eta, 1.8, 2.4
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta0/",				// 188 PbPb HLT std colsed rfp eta, -2.4, -1.8
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta1/",				// 189 PbPb HLT std colsed rfp eta, -1.8, -1.2
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta2/",				// 190 PbPb HLT std colsed rfp eta, -1.2, -0.6
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta3/",				// 191 PbPb HLT std colsed rfp eta, -0.6, -0.0
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta4/",				// 192 PbPb HLT std colsed rfp eta, 0.0, 0.6
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta5/",				// 193 PbPb HLT std colsed rfp eta, 0.6, 1.2
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta6/",				// 194 PbPb HLT std colsed rfp eta, 1.2, 1.8
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_eta7/",				// 195 PbPb HLT std colsed rfp eta, 1.8, 2.4
	"../MC/PionExpoPt_ref_etaR0/",						// 196 Expo pT pion rfp eta, -2.4, -1.6
	"../MC/PionExpoPt_ref_etaR1/",						// 197 Expo pT pion rfp eta, -1.6, -0.8
	"../MC/PionExpoPt_ref_etaR2/",						// 198 Expo pT pion rfp eta, -0.8, 0.
	"../MC/PionExpoPt_ref_etaR3/",						// 199 Expo pT pion rfp eta, 0.0, 0.8
	"../MC/PionExpoPt_ref_etaR4/",						// 200 Expo pT pion rfp eta, 0.8, 1.6
	"../MC/PionExpoPt_ref_etaR5/",						// 201 Expo pT pion rfp eta, 1.6, 2.4
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR0/",				// 202 pPb HLT std colsed rfp eta, -2.4, -1.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR0_rereco/",			// 203 pPb HLT std colsed rfp eta, -2.4, -1.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR0_reverse/",			// 204 pPb HLT std colsed rfp eta, -2.4, -1.6
	"NA",									// 205 pPb HLT std colsed rfp eta, -2.4, -1.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR1/",				// 206 pPb HLT std colsed rfp eta, -1.6, -0.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR1_rereco/",			// 207 pPb HLT std colsed rfp eta, -1.6, -0.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR1_reverse/",			// 208 pPb HLT std colsed rfp eta, -1.6, -0.8
	"NA",									// 209 pPb HLT std colsed rfp eta, -1.6, -0.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR2/",				// 210 pPb HLT std colsed rfp eta, -0.8, 0.0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR2_rereco/",			// 211 pPb HLT std colsed rfp eta, -0.8, 0.0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR2_reverse/",			// 212 pPb HLT std colsed rfp eta, -0.8, 0.0
	"NA",									// 213 pPb HLT std colsed rfp eta, -0.8, 0.0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR3/",				// 214 pPb HLT std colsed rfp eta, 0., 0.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR3_rereco/",			// 215 pPb HLT std colsed rfp eta, 0., 0.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR3_reverse/",			// 216 pPb HLT std colsed rfp eta, 0., 0.8
	"NA",									// 217 pPb HLT std colsed rfp eta, 0., 0.8
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR4/",				// 218 pPb HLT std colsed rfp eta, 0.8, 1.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR4_rereco/",			// 219 pPb HLT std colsed rfp eta, 0.8, 1.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR4_reverse/",			// 220 pPb HLT std colsed rfp eta, 0.8, 1.6
	"NA",									// 221 pPb HLT std colsed rfp eta, 0.8, 1.6
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR5/",				// 222 pPb HLT std colsed rfp eta, 1.6, 2.4
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR5_rereco/",			// 223 pPb HLT std colsed rfp eta, 1.6, 2.4
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_etaR5_reverse/",			// 224 pPb HLT std colsed rfp eta, 1.6, 2.4
	"NA",									// 225 pPb HLT std colsed rfp eta, 1.6, 2.4
	"../pPb/pPb_HLT_rfppos_Noff_noacc_eff_poi0/",				// 226 pPb HLT std colsed rfp eta, 0., 2.4, poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfppos_Noff_noacc_eff_poi0_rereco/",			// 227 pPb HLT std colsed rfp eta, 0., 2.4, poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfppos_Noff_noacc_eff_poi0_reverse/",			// 228 pPb HLT std colsed rfp eta, 0., 2.4, poi eta -2.4, -1.2
	"NA",									// 229 pPb HLT std colsed rfp eta, 0., 2.4, poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_eff_poi3/",				// 230 pPb HLT std colsed rfp eta, -2.4, 0., poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_eff_poi3_rereco/",			// 231 pPb HLT std colsed rfp eta, -2.4, 0., poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_eff_poi3_reverse/",			// 232 pPb HLT std colsed rfp eta, -2.4, 0., poi eta 1.2, 2.4
	"NA",									// 233 pPb HLT std colsed rfp eta, -2.4, 0., poi eta 1.2, 2.4
	"../pPb/PbPb_HLT_rfppos_Noff_noacc_eff_poi0",				// 234 PbPb HLT std colsed rfp eta pos, poi eta -2.4, -1.2
	"../pPb/PbPb_HLT_rfpneg_Noff_noacc_eff_poi3",				// 235 PbPb HLT std colsed rfp eta neg, poi eta 1.2, 2.4
	"../MC/PionExpoPt_refpos_poi0/",					// 236 MC Expo pT std colsed rfp eta pos, poi eta -2.4, -1.2
	"../MC/PionExpoPt_refneg_poi3/",					// 237 MC Expo pT std colsed rfp eta neg, poi eta 1.2, 2.4
	"../MC/PionExpoPt_refneg_poi0/",					// 238 MC Expo pT std colsed rfp eta neg, poi eta -2.4, -1.2
	"../MC/PionExpoPt_refpos_poi3/",					// 239 MC Expo pT std colsed rfp eta pos, poi eta 1.2, 2.4
	"../pPb/PbPb_HLT_rfpneg_Noff_noacc_eff_poi0",				// 240 PbPb HLT std colsed rfp eta neg, poi eta -2.4, -1.2
	"../pPb/PbPb_HLT_rfppos_Noff_noacc_eff_poi3",				// 241 PbPb HLT std colsed rfp eta pos, poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_eff_poi0/",				// 242 pPb HLT std colsed rfp eta, -2.4, 0., , poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_eff_poi0_rereco/",			// 243 pPb HLT std colsed rfp eta, -2.4, 0., , poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfpneg_Noff_noacc_eff_poi0_reverse/",			// 244 pPb HLT std colsed rfp eta, -2.4, 0., , poi eta -2.4, -1.2
	"NA",									// 245 pPb HLT std colsed rfp eta, -2.4, 0., , poi eta -2.4, -1.2
	"../pPb/pPb_HLT_rfppos_Noff_noacc_eff_poi3/",				// 246 pPb HLT std colsed rfp eta, 0., 2.4, poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfppos_Noff_noacc_eff_poi3_rereco/",			// 247 pPb HLT std colsed rfp eta, 0., 2.4, poi eta 1.2, 2.4
	"../pPb/pPb_HLT_rfppos_Noff_noacc_eff_poi3_reverse/",			// 248 pPb HLT std colsed rfp eta, 0., 2.4, poi eta 1.2, 2.4
	"NA",									// 249 pPb HLT std colsed rfp eta, 0., 2.4, poi eta 1.2, 2.4
	"../MC/PionExpoPt_ref0_poi0_v2eta/",					// 250 Expo pT pion rfp eta v2, -2.4, -1.6
	"../MC/PionExpoPt_ref1_poi1_v2eta/",					// 251 Expo pT pion rfp eta v2, -1.6, -0.8
	"../MC/PionExpoPt_ref2_poi2_v2eta/",					// 252 Expo pT pion rfp eta v2, -0.8, -0.
	"../MC/PionExpoPt_ref3_poi3_v2eta/",					// 253 Expo pT pion rfp eta v2, 0.0, 0.8
	"../MC/PionExpoPt_ref4_poi4_v2eta/",					// 254 Expo pT pion rfp eta v2, 0.8, 1.6
	"../MC/PionExpoPt_ref5_poi5_v2eta/",					// 255 Expo pT pion rfp eta v2, 1.6, 2.4
	"../pPb/PbPb_HLT_rfp24_Noff_noacc_eff_sysPU/",				// 256 PbPb sysPU

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
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_sysTight/",				// 127
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_sysLoose/",				// 128
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_sysVtx0/",				// 129
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_sysVtx1/",				// 130
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_sysEff/",				// 131
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysEff/",				// 132
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysEff_rereco/",			// 133
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysEff_reverse/",			// 134
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysEff_full/",			// 135
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18/",				// 136
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1_rereco_v18/",			// 137
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1_reverse_v18/",			// 138
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18_full/",			// 139
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_Prompt_cm1/",				// 140
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_Prompt_cm1_rereco/",			// 141
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_Prompt_cm1_reverse/",			// 142
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_Prompt_cm1_full/",			// 143
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysHLT/",				// 144
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysHLT_rereco/",			// 145
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysHLT_reverse/",			// 146
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysHLT_full/",			// 147
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysPU/",				// 148
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysPU_rereco/",			// 149
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysPU_reverse/",			// 150
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_sysPU_full/",				// 151
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_GT/",					// 152
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_GT_rereco/",				// 153
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_GT_reverse/",				// 154
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_GT_full/",				// 155
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta0/",				// 156
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta0_rereco/",			// 157
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta0_reverse/",			// 158
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta0_full/",				// 159
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta1/",				// 160
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta1_rereco/",			// 161
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta1_reverse/",			// 162
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta1_full/",				// 163
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta2/",				// 164
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta2_rereco/",			// 165
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta2_reverse/",			// 166
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta2_full/",				// 167
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta3/",				// 168
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta3_rereco/",			// 169
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta3_reverse/",			// 170
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta3_full/",				// 171
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta4/",				// 172
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta4_rereco/",			// 173
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta4_reverse/",			// 174
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta4_full/",				// 175
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta5/",				// 176
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta5_rereco/",			// 177
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta5_reverse/",			// 178
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta5_full/",				// 179
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta6/",				// 180
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta6_rereco/",			// 181
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta6_reverse/",			// 182
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta6_full/",				// 183
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta7/",				// 184
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta7_rereco/",			// 185
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta7_reverse/",			// 186
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_eta7_full/",				// 187
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta0/",				// 188
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta1/",				// 189
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta2/",				// 190
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta3/",				// 191
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta4/",				// 192
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta5/",				// 193
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta6/",				// 194
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_eta7/",				// 195
	"txt/PionExpoPt_ref_etaR0/",						// 196
	"txt/PionExpoPt_ref_etaR1/",						// 197
	"txt/PionExpoPt_ref_etaR2/",						// 198
	"txt/PionExpoPt_ref_etaR3/",						// 199
	"txt/PionExpoPt_ref_etaR4/",						// 200
	"txt/PionExpoPt_ref_etaR5/",						// 201
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR0/",				// 202
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR0_rereco/",			// 203
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR0_reverse/",			// 204
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR0_full/",				// 205
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR1/",				// 206
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR1_rereco/",			// 207
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR1_reverse/",			// 208
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR1_full/",				// 209
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR2/",				// 210
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR2_rereco/",			// 211
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR2_reverse/",			// 212
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR2_full/",				// 213
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR3/",				// 214
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR3_rereco/",			// 215
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR3_reverse/",			// 216
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR3_full/",				// 217
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR4/",				// 218
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR4_rereco/",			// 219
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR4_reverse/",			// 220
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR4_full/",				// 221
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR5/",				// 222
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR5_rereco/",			// 223
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR5_reverse/",			// 224
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_etaR5_full/",				// 225
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi0/",				// 226
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi0_rereco/",			// 227
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi0_reverse/",			// 228
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi0_full/",				// 229
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi3/",				// 230
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi3_rereco/",			// 231
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi3_reverse/",			// 232
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi3_full/",				// 233
	"txt/PbPb_HLT_rfppos_Noff_noacc_eff_poi0/",				// 234
	"txt/PbPb_HLT_rfpneg_Noff_noacc_eff_poi3/",				// 235
	"txt/PionExpoPt_refpos_poi0/",						// 236
	"txt/PionExpoPt_refneg_poi3/",						// 237
	"txt/PionExpoPt_refneg_poi0/",						// 238
	"txt/PionExpoPt_refpos_poi3/",						// 239
	"txt/PbPb_HLT_rfpneg_Noff_noacc_eff_poi0/",				// 240
	"txt/PbPb_HLT_rfppos_Noff_noacc_eff_poi3/",				// 241
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi0/",				// 242
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi0_rereco/",			// 243
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi0_reverse/",			// 244
	"txt/pPb_HLT_rfpneg_Noff_noacc_eff_poi0_full/",				// 245
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi3/",				// 246
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi3_rereco/",			// 247
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi3_reverse/",			// 248
	"txt/pPb_HLT_rfppos_Noff_noacc_eff_poi3_full/",				// 249
	"txt/PionExpoPt_ref0_poi0_v2eta/",					// 250
	"txt/PionExpoPt_ref1_poi1_v2eta/",					// 251
	"txt/PionExpoPt_ref2_poi2_v2eta/",					// 252
	"txt/PionExpoPt_ref3_poi3_v2eta/",					// 253
	"txt/PionExpoPt_ref4_poi4_v2eta/",					// 254
	"txt/PionExpoPt_ref5_poi5_v2eta/",					// 255
	"txt/PbPb_HLT_rfp24_Noff_noacc_eff_sysPU/",				// 256

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
