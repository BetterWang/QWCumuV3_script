// 0, 0 - 10
// 1, 10 - 20
// 2, 20 - 30
// 3, 30 - 40
// 4, 40 - 50
// 5, 50 - 60
TMultiGraph * mgrHIN11012_v2[6] = {};
TGraphErrors * grHIN_v2pt[6] = {};
TGraphErrors * grHIN_v2pt_sys[6] = {};

void HIN_11_012() {

	// 0 - 10%
	grHIN_v2pt[0] = new TGraphErrors(24);
	grHIN_v2pt[0]->SetPoint(0,   1.05,   0.04655	);
	grHIN_v2pt[0]->SetPoint(1,   1.15,   0.04984	);
	grHIN_v2pt[0]->SetPoint(2,   1.29,   0.05443	);
	grHIN_v2pt[0]->SetPoint(3,   1.49,   0.06048	);
	grHIN_v2pt[0]->SetPoint(4,   1.69,   0.06566	);
	grHIN_v2pt[0]->SetPoint(5,   1.89,   0.07118	);
	grHIN_v2pt[0]->SetPoint(6,   2.09,   0.07558	);
	grHIN_v2pt[0]->SetPoint(7,   2.29,   0.08047	);
	grHIN_v2pt[0]->SetPoint(8,   2.7 ,   0.08673	);
	grHIN_v2pt[0]->SetPoint(9,   3.51,   0.09129	);
	grHIN_v2pt[0]->SetPoint(10,  4.32,   0.08402	);
	grHIN_v2pt[0]->SetPoint(11,  5.14,   0.07088	);
	grHIN_v2pt[0]->SetPoint(12,  6   ,   0.05561	);
	grHIN_v2pt[0]->SetPoint(13,  6.8 ,   0.04806	);
	grHIN_v2pt[0]->SetPoint(14,  8.1 ,   0.04596	);
	grHIN_v2pt[0]->SetPoint(15,  10.6,   0.04157	);
	grHIN_v2pt[0]->SetPoint(16,  12.9,   0.03095	);
	grHIN_v2pt[0]->SetPoint(17,  14.9,   0.02726	);
	grHIN_v2pt[0]->SetPoint(18,  17.4,   0.02269	);
	grHIN_v2pt[0]->SetPoint(19,  21.2,   0.02535	);
	grHIN_v2pt[0]->SetPoint(20,  26.1,   0.02387	);
	grHIN_v2pt[0]->SetPoint(21,  31.5,   0.01835	);
	grHIN_v2pt[0]->SetPoint(22,  40  ,   0.01622	);
	grHIN_v2pt[0]->SetPoint(23,  53.1,   0.0306	);

	grHIN_v2pt_sys[0] = (TGraphErrors*) grHIN_v2pt[0]->Clone();

	grHIN_v2pt[0]->SetPointError(0,   0,   0.00012);
	grHIN_v2pt[0]->SetPointError(1,   0,   0.00013);
	grHIN_v2pt[0]->SetPointError(2,   0,   0.00010);
	grHIN_v2pt[0]->SetPointError(3,   0,   0.00012);
	grHIN_v2pt[0]->SetPointError(4,   0,   0.00015);
	grHIN_v2pt[0]->SetPointError(5,   0,   0.00018);
	grHIN_v2pt[0]->SetPointError(6,   0,   0.00022);
	grHIN_v2pt[0]->SetPointError(7,   0,   0.00027);
	grHIN_v2pt[0]->SetPointError(8,   0,   0.00021);
	grHIN_v2pt[0]->SetPointError(9,   0,   0.00044);
	grHIN_v2pt[0]->SetPointError(10,  0,   0.00086);
	grHIN_v2pt[0]->SetPointError(11,  0,   0.00148);
	grHIN_v2pt[0]->SetPointError(12,  0,   0.00229);
	grHIN_v2pt[0]->SetPointError(13,  0,   0.00322);
	grHIN_v2pt[0]->SetPointError(14,  0,   0.00306);
	grHIN_v2pt[0]->SetPointError(15,  0,   0.00565);
	grHIN_v2pt[0]->SetPointError(16,  0,   0.00169);
	grHIN_v2pt[0]->SetPointError(17,  0,   0.00191);
	grHIN_v2pt[0]->SetPointError(18,  0,   0.00218);
	grHIN_v2pt[0]->SetPointError(19,  0,   0.00285);
	grHIN_v2pt[0]->SetPointError(20,  0,   0.00465);
	grHIN_v2pt[0]->SetPointError(21,  0,   0.00637);
	grHIN_v2pt[0]->SetPointError(22,  0,   0.00823);
	grHIN_v2pt[0]->SetPointError(23,  0,   0.01740);

	grHIN_v2pt_sys[0]->SetPointError(0,   1.0,   0.00154);
	grHIN_v2pt_sys[0]->SetPointError(1,   1.0,   0.00164);
	grHIN_v2pt_sys[0]->SetPointError(2,   1.0,   0.00179);
	grHIN_v2pt_sys[0]->SetPointError(3,   1.0,   0.00199);
	grHIN_v2pt_sys[0]->SetPointError(4,   1.0,   0.00217);
	grHIN_v2pt_sys[0]->SetPointError(5,   1.0,   0.00235);
	grHIN_v2pt_sys[0]->SetPointError(6,   1.0,   0.00249);
	grHIN_v2pt_sys[0]->SetPointError(7,   1.0,   0.00266);
	grHIN_v2pt_sys[0]->SetPointError(8,   1.0,   0.00286);
	grHIN_v2pt_sys[0]->SetPointError(9,   1.0,   0.00301);
	grHIN_v2pt_sys[0]->SetPointError(10,  1.0,   0.00277);
	grHIN_v2pt_sys[0]->SetPointError(11,  1.0,   0.00234);
	grHIN_v2pt_sys[0]->SetPointError(12,  1.0,   0.00184);
	grHIN_v2pt_sys[0]->SetPointError(13,  1.0,   0.00159);
	grHIN_v2pt_sys[0]->SetPointError(14,  1.0,   0.00152);
	grHIN_v2pt_sys[0]->SetPointError(15,  1.0,   0.00137);
	grHIN_v2pt_sys[0]->SetPointError(16,  1.0,   0.00102);
	grHIN_v2pt_sys[0]->SetPointError(17,  1.0,   0.00089);
	grHIN_v2pt_sys[0]->SetPointError(18,  1.0,   0.00075);
	grHIN_v2pt_sys[0]->SetPointError(19,  1.0,   0.00084);
	grHIN_v2pt_sys[0]->SetPointError(20,  1.0,   0.00079);
	grHIN_v2pt_sys[0]->SetPointError(21,  1.0,   0.00061);
	grHIN_v2pt_sys[0]->SetPointError(22,  1.0,   0.00060);
	grHIN_v2pt_sys[0]->SetPointError(23,  1.0,   0.00110);


	// 10 -20%
	grHIN_v2pt[1] = new TGraphErrors(24);
	grHIN_v2pt[1]->SetPoint(0,   1.05,   0.08799);
	grHIN_v2pt[1]->SetPoint(1,   1.15,   0.09415);
	grHIN_v2pt[1]->SetPoint(2,   1.29,   0.10303);
	grHIN_v2pt[1]->SetPoint(3,   1.49,   0.11380);
	grHIN_v2pt[1]->SetPoint(4,   1.69,   0.12403);
	grHIN_v2pt[1]->SetPoint(5,   1.89,   0.13345);
	grHIN_v2pt[1]->SetPoint(6,   2.09,   0.14223);
	grHIN_v2pt[1]->SetPoint(7,   2.29,   0.14995);
	grHIN_v2pt[1]->SetPoint(8,   2.7 ,   0.16112);
	grHIN_v2pt[1]->SetPoint(9,   3.51,   0.16730);
	grHIN_v2pt[1]->SetPoint(10,  4.32,   0.15262);
	grHIN_v2pt[1]->SetPoint(11,  5.14,   0.12843);
	grHIN_v2pt[1]->SetPoint(12,  6   ,   0.10681);
	grHIN_v2pt[1]->SetPoint(13,  6.8 ,   0.08905);
	grHIN_v2pt[1]->SetPoint(14,  8.1 ,   0.07472);
	grHIN_v2pt[1]->SetPoint(15,  10.6,   0.06041);
	grHIN_v2pt[1]->SetPoint(16,  12.9,   0.05259);
	grHIN_v2pt[1]->SetPoint(17,  14.9,   0.04884);
	grHIN_v2pt[1]->SetPoint(18,  17.4,   0.04291);
	grHIN_v2pt[1]->SetPoint(19,  21.2,   0.03842);
	grHIN_v2pt[1]->SetPoint(20,  26.1,   0.03326);
	grHIN_v2pt[1]->SetPoint(21,  31.5,   0.03731);
	grHIN_v2pt[1]->SetPoint(22,  40  ,   0.02653);
	grHIN_v2pt[1]->SetPoint(23,  53.1,   0.00790);

	grHIN_v2pt_sys[1] = (TGraphErrors*) grHIN_v2pt[1]->Clone();

	grHIN_v2pt[1]->SetPointError(0,   0,   0.00010);
	grHIN_v2pt[1]->SetPointError(1,   0,   0.00011);
	grHIN_v2pt[1]->SetPointError(2,   0,   0.00009);
	grHIN_v2pt[1]->SetPointError(3,   0,   0.00011);
	grHIN_v2pt[1]->SetPointError(4,   0,   0.00013);
	grHIN_v2pt[1]->SetPointError(5,   0,   0.00016);
	grHIN_v2pt[1]->SetPointError(6,   0,   0.00019);
	grHIN_v2pt[1]->SetPointError(7,   0,   0.00024);
	grHIN_v2pt[1]->SetPointError(8,   0,   0.00019);
	grHIN_v2pt[1]->SetPointError(9,   0,   0.00038);
	grHIN_v2pt[1]->SetPointError(10,  0,   0.00073);
	grHIN_v2pt[1]->SetPointError(11,  0,   0.00123);
	grHIN_v2pt[1]->SetPointError(12,  0,   0.00186);
	grHIN_v2pt[1]->SetPointError(13,  0,   0.00263);
	grHIN_v2pt[1]->SetPointError(14,  0,   0.00247);
	grHIN_v2pt[1]->SetPointError(15,  0,   0.00464);
	grHIN_v2pt[1]->SetPointError(16,  0,   0.00138);
	grHIN_v2pt[1]->SetPointError(17,  0,   0.00157);
	grHIN_v2pt[1]->SetPointError(18,  0,   0.00179);
	grHIN_v2pt[1]->SetPointError(19,  0,   0.00235);
	grHIN_v2pt[1]->SetPointError(20,  0,   0.00386);
	grHIN_v2pt[1]->SetPointError(21,  0,   0.00531);
	grHIN_v2pt[1]->SetPointError(22,  0,   0.00696);
	grHIN_v2pt[1]->SetPointError(23,  0,   0.01490);

	grHIN_v2pt_sys[1]->SetPointError(0,   1.0,   0.00290);
	grHIN_v2pt_sys[1]->SetPointError(1,   1.0,   0.00311);
	grHIN_v2pt_sys[1]->SetPointError(2,   1.0,   0.00339);
	grHIN_v2pt_sys[1]->SetPointError(3,   1.0,   0.00376);
	grHIN_v2pt_sys[1]->SetPointError(4,   1.0,   0.00409);
	grHIN_v2pt_sys[1]->SetPointError(5,   1.0,   0.00440);
	grHIN_v2pt_sys[1]->SetPointError(6,   1.0,   0.00469);
	grHIN_v2pt_sys[1]->SetPointError(7,   1.0,   0.00495);
	grHIN_v2pt_sys[1]->SetPointError(8,   1.0,   0.00532);
	grHIN_v2pt_sys[1]->SetPointError(9,   1.0,   0.00552);
	grHIN_v2pt_sys[1]->SetPointError(10,  1.0,   0.00504);
	grHIN_v2pt_sys[1]->SetPointError(11,  1.0,   0.00424);
	grHIN_v2pt_sys[1]->SetPointError(12,  1.0,   0.00352);
	grHIN_v2pt_sys[1]->SetPointError(13,  1.0,   0.00294);
	grHIN_v2pt_sys[1]->SetPointError(14,  1.0,   0.00247);
	grHIN_v2pt_sys[1]->SetPointError(15,  1.0,   0.00199);
	grHIN_v2pt_sys[1]->SetPointError(16,  1.0,   0.00174);
	grHIN_v2pt_sys[1]->SetPointError(17,  1.0,   0.00161);
	grHIN_v2pt_sys[1]->SetPointError(18,  1.0,   0.00141);
	grHIN_v2pt_sys[1]->SetPointError(19,  1.0,   0.00127);
	grHIN_v2pt_sys[1]->SetPointError(20,  1.0,   0.00109);
	grHIN_v2pt_sys[1]->SetPointError(21,  1.0,   0.00123);
	grHIN_v2pt_sys[1]->SetPointError(22,  1.0,   0.00098);
	grHIN_v2pt_sys[1]->SetPointError(23,  1.0,   0.00030);

	// 20 - 30%
	grHIN_v2pt[2] = new TGraphErrors(24);
	grHIN_v2pt[2]->SetPoint(0,   1.05,   0.11619);
	grHIN_v2pt[2]->SetPoint(1,   1.15,   0.12441);
	grHIN_v2pt[2]->SetPoint(2,   1.29,   0.13574);
	grHIN_v2pt[2]->SetPoint(3,   1.49,   0.14993);
	grHIN_v2pt[2]->SetPoint(4,   1.69,   0.16218);
	grHIN_v2pt[2]->SetPoint(5,   1.89,   0.17426);
	grHIN_v2pt[2]->SetPoint(6,   2.09,   0.18456);
	grHIN_v2pt[2]->SetPoint(7,   2.29,   0.19302);
	grHIN_v2pt[2]->SetPoint(8,   2.7 ,   0.20408);
	grHIN_v2pt[2]->SetPoint(9,   3.51,   0.20590);
	grHIN_v2pt[2]->SetPoint(10,  4.32,   0.18486);
	grHIN_v2pt[2]->SetPoint(11,  5.14,   0.15653);
	grHIN_v2pt[2]->SetPoint(12,  6   ,   0.12938);
	grHIN_v2pt[2]->SetPoint(13,  6.8 ,   0.11404);
	grHIN_v2pt[2]->SetPoint(14,  8.1 ,   0.09865);
	grHIN_v2pt[2]->SetPoint(15,  10.6,   0.06948);
	grHIN_v2pt[2]->SetPoint(16,  12.9,   0.06363);
	grHIN_v2pt[2]->SetPoint(17,  14.9,   0.06299);
	grHIN_v2pt[2]->SetPoint(18,  17.4,   0.05992);
	grHIN_v2pt[2]->SetPoint(19,  21.2,   0.04810);
	grHIN_v2pt[2]->SetPoint(20,  26.1,   0.04515);
	grHIN_v2pt[2]->SetPoint(21,  31.5,   0.03065);
	grHIN_v2pt[2]->SetPoint(22,  40  ,   0.01907);
	grHIN_v2pt[2]->SetPoint(23,  53.1,   0.03890);

	grHIN_v2pt_sys[2] = (TGraphErrors*) grHIN_v2pt[2]->Clone();

	grHIN_v2pt[2]->SetPointError(0,   0,   0.00012	);
	grHIN_v2pt[2]->SetPointError(1,   0,   0.00013	);
	grHIN_v2pt[2]->SetPointError(2,   0,   0.00011	);
	grHIN_v2pt[2]->SetPointError(3,   0,   0.00013	);
	grHIN_v2pt[2]->SetPointError(4,   0,   0.00016	);
	grHIN_v2pt[2]->SetPointError(5,   0,   0.00019	);
	grHIN_v2pt[2]->SetPointError(6,   0,   0.00024	);
	grHIN_v2pt[2]->SetPointError(7,   0,   0.00029	);
	grHIN_v2pt[2]->SetPointError(8,   0,   0.00022	);
	grHIN_v2pt[2]->SetPointError(9,   0,   0.00045	);
	grHIN_v2pt[2]->SetPointError(10,  0,   0.00083	);
	grHIN_v2pt[2]->SetPointError(11,  0,   0.00136	);
	grHIN_v2pt[2]->SetPointError(12,  0,   0.00205	);
	grHIN_v2pt[2]->SetPointError(13,  0,   0.00287	);
	grHIN_v2pt[2]->SetPointError(14,  0,   0.00271	);
	grHIN_v2pt[2]->SetPointError(15,  0,   0.00511	);
	grHIN_v2pt[2]->SetPointError(16,  0,   0.00157	);
	grHIN_v2pt[2]->SetPointError(17,  0,   0.00177	);
	grHIN_v2pt[2]->SetPointError(18,  0,   0.00203	);
	grHIN_v2pt[2]->SetPointError(19,  0,   0.00267	);
	grHIN_v2pt[2]->SetPointError(20,  0,   0.00442	);
	grHIN_v2pt[2]->SetPointError(21,  0,   0.00613	);
	grHIN_v2pt[2]->SetPointError(22,  0,   0.00816	);
	grHIN_v2pt[2]->SetPointError(23,  0,   0.0169	);

	grHIN_v2pt_sys[2]->SetPointError(0,   1.0,   0.00383);
	grHIN_v2pt_sys[2]->SetPointError(1,   1.0,   0.00411);
	grHIN_v2pt_sys[2]->SetPointError(2,   1.0,   0.00448);
	grHIN_v2pt_sys[2]->SetPointError(3,   1.0,   0.00495);
	grHIN_v2pt_sys[2]->SetPointError(4,   1.0,   0.00535);
	grHIN_v2pt_sys[2]->SetPointError(5,   1.0,   0.00575);
	grHIN_v2pt_sys[2]->SetPointError(6,   1.0,   0.00609);
	grHIN_v2pt_sys[2]->SetPointError(7,   1.0,   0.00637);
	grHIN_v2pt_sys[2]->SetPointError(8,   1.0,   0.00673);
	grHIN_v2pt_sys[2]->SetPointError(9,   1.0,   0.00679);
	grHIN_v2pt_sys[2]->SetPointError(10,  1.0,   0.0061 );
	grHIN_v2pt_sys[2]->SetPointError(11,  1.0,   0.00517);
	grHIN_v2pt_sys[2]->SetPointError(12,  1.0,   0.00427);
	grHIN_v2pt_sys[2]->SetPointError(13,  1.0,   0.00376);
	grHIN_v2pt_sys[2]->SetPointError(14,  1.0,   0.00326);
	grHIN_v2pt_sys[2]->SetPointError(15,  1.0,   0.00229);
	grHIN_v2pt_sys[2]->SetPointError(16,  1.0,   0.00209);
	grHIN_v2pt_sys[2]->SetPointError(17,  1.0,   0.00208);
	grHIN_v2pt_sys[2]->SetPointError(18,  1.0,   0.00198);
	grHIN_v2pt_sys[2]->SetPointError(19,  1.0,   0.00159);
	grHIN_v2pt_sys[2]->SetPointError(20,  1.0,   0.00149);
	grHIN_v2pt_sys[2]->SetPointError(21,  1.0,   0.00101);
	grHIN_v2pt_sys[2]->SetPointError(22,  1.0,   0.00070);
	grHIN_v2pt_sys[2]->SetPointError(23,  1.0,   0.00140);

	// 30 - 40%
	grHIN_v2pt[3] = new TGraphErrors(24);
	grHIN_v2pt[3]->SetPoint(0,   1.05,   0.13535	);
	grHIN_v2pt[3]->SetPoint(1,   1.15,   0.14484	);
	grHIN_v2pt[3]->SetPoint(2,   1.29,   0.15715	);
	grHIN_v2pt[3]->SetPoint(3,   1.49,   0.17268	);
	grHIN_v2pt[3]->SetPoint(4,   1.69,   0.18662	);
	grHIN_v2pt[3]->SetPoint(5,   1.89,   0.1986	);
	grHIN_v2pt[3]->SetPoint(6,   2.09,   0.20855	);
	grHIN_v2pt[3]->SetPoint(7,   2.29,   0.217	);
	grHIN_v2pt[3]->SetPoint(8,   2.7 ,   0.22557	);
	grHIN_v2pt[3]->SetPoint(9,   3.51,   0.21976	);
	grHIN_v2pt[3]->SetPoint(10,  4.32,   0.195	);
	grHIN_v2pt[3]->SetPoint(11,  5.14,   0.1685	);
	grHIN_v2pt[3]->SetPoint(12,  6   ,   0.1368	);
	grHIN_v2pt[3]->SetPoint(13,  6.8 ,   0.12169	);
	grHIN_v2pt[3]->SetPoint(14,  8.1 ,   0.10182	);
	grHIN_v2pt[3]->SetPoint(15,  10.6,   0.07942	);
	grHIN_v2pt[3]->SetPoint(16,  12.9,   0.07271	);
	grHIN_v2pt[3]->SetPoint(17,  14.9,   0.06928	);
	grHIN_v2pt[3]->SetPoint(18,  17.4,   0.06067	);
	grHIN_v2pt[3]->SetPoint(19,  21.2,   0.05165	);
	grHIN_v2pt[3]->SetPoint(20,  26.1,   0.05039	);
	grHIN_v2pt[3]->SetPoint(21,  31.5,   0.04069	);
	grHIN_v2pt[3]->SetPoint(22,  40  ,   0.01865	);
	grHIN_v2pt[3]->SetPoint(23,  53.1,   0.0016	);

	grHIN_v2pt_sys[3] = (TGraphErrors*) grHIN_v2pt[3]->Clone();

	grHIN_v2pt[3]->SetPointError(0,   0,   0.00016	);
	grHIN_v2pt[3]->SetPointError(1,   0,   0.00017	);
	grHIN_v2pt[3]->SetPointError(2,   0,   0.00014	);
	grHIN_v2pt[3]->SetPointError(3,   0,   0.00017	);
	grHIN_v2pt[3]->SetPointError(4,   0,   0.00021	);
	grHIN_v2pt[3]->SetPointError(5,   0,   0.00025	);
	grHIN_v2pt[3]->SetPointError(6,   0,   0.00031	);
	grHIN_v2pt[3]->SetPointError(7,   0,   0.00038	);
	grHIN_v2pt[3]->SetPointError(8,   0,   0.00029	);
	grHIN_v2pt[3]->SetPointError(9,   0,   0.00057	);
	grHIN_v2pt[3]->SetPointError(10,  0,   0.00102	);
	grHIN_v2pt[3]->SetPointError(11,  0,   0.00166	);
	grHIN_v2pt[3]->SetPointError(12,  0,   0.00246	);
	grHIN_v2pt[3]->SetPointError(13,  0,   0.00346	);
	grHIN_v2pt[3]->SetPointError(14,  0,   0.00323	);
	grHIN_v2pt[3]->SetPointError(15,  0,   0.00619	);
	grHIN_v2pt[3]->SetPointError(16,  0,   0.00199	);
	grHIN_v2pt[3]->SetPointError(17,  0,   0.00223	);
	grHIN_v2pt[3]->SetPointError(18,  0,   0.00254	);
	grHIN_v2pt[3]->SetPointError(19,  0,   0.00335	);
	grHIN_v2pt[3]->SetPointError(20,  0,   0.00557	);
	grHIN_v2pt[3]->SetPointError(21,  0,   0.00776	);
	grHIN_v2pt[3]->SetPointError(22,  0,   0.01044	);
	grHIN_v2pt[3]->SetPointError(23,  0,   0.0221	);

	grHIN_v2pt_sys[3]->SetPointError(0,   1.0,  0.00447);
	grHIN_v2pt_sys[3]->SetPointError(1,   1.0,  0.00478);
	grHIN_v2pt_sys[3]->SetPointError(2,   1.0,  0.00519);
	grHIN_v2pt_sys[3]->SetPointError(3,   1.0,  0.00569);
	grHIN_v2pt_sys[3]->SetPointError(4,   1.0,  0.00616);
	grHIN_v2pt_sys[3]->SetPointError(5,   1.0,  0.00655);
	grHIN_v2pt_sys[3]->SetPointError(6,   1.0,  0.00688);
	grHIN_v2pt_sys[3]->SetPointError(7,   1.0,  0.00716);
	grHIN_v2pt_sys[3]->SetPointError(8,   1.0,  0.00744);
	grHIN_v2pt_sys[3]->SetPointError(9,   1.0,  0.00725);
	grHIN_v2pt_sys[3]->SetPointError(10,  1.0,  0.00643);
	grHIN_v2pt_sys[3]->SetPointError(11,  1.0,  0.00556);
	grHIN_v2pt_sys[3]->SetPointError(12,  1.0,  0.00451);
	grHIN_v2pt_sys[3]->SetPointError(13,  1.0,  0.00402);
	grHIN_v2pt_sys[3]->SetPointError(14,  1.0,  0.00336);
	grHIN_v2pt_sys[3]->SetPointError(15,  1.0,  0.00262);
	grHIN_v2pt_sys[3]->SetPointError(16,  1.0,  0.00239);
	grHIN_v2pt_sys[3]->SetPointError(17,  1.0,  0.00228);
	grHIN_v2pt_sys[3]->SetPointError(18,  1.0,  0.002	);
	grHIN_v2pt_sys[3]->SetPointError(19,  1.0,  0.0017);
	grHIN_v2pt_sys[3]->SetPointError(20,  1.0,  0.00166);
	grHIN_v2pt_sys[3]->SetPointError(21,  1.0,  0.00134);
	grHIN_v2pt_sys[3]->SetPointError(22,  1.0,  0.00069);
	grHIN_v2pt_sys[3]->SetPointError(23,  1.0,  0.0001);

	// 40 - 50%
	grHIN_v2pt[4] = new TGraphErrors(24);
	grHIN_v2pt[4]->SetPoint(0,   1.05,   0.1464	);
	grHIN_v2pt[4]->SetPoint(1,   1.15,   0.1562	);
	grHIN_v2pt[4]->SetPoint(2,   1.29,   0.1692	);
	grHIN_v2pt[4]->SetPoint(3,   1.49,   0.1849	);
	grHIN_v2pt[4]->SetPoint(4,   1.69,   0.1982	);
	grHIN_v2pt[4]->SetPoint(5,   1.89,   0.2096	);
	grHIN_v2pt[4]->SetPoint(6,   2.09,   0.2177	);
	grHIN_v2pt[4]->SetPoint(7,   2.29,   0.2246	);
	grHIN_v2pt[4]->SetPoint(8,   2.7 ,   0.23	);
	grHIN_v2pt[4]->SetPoint(9,   3.51,   0.2195	);
	grHIN_v2pt[4]->SetPoint(10,  4.32,   0.1943	);
	grHIN_v2pt[4]->SetPoint(11,  5.14,   0.1651	);
	grHIN_v2pt[4]->SetPoint(12,  6   ,   0.1416	);
	grHIN_v2pt[4]->SetPoint(13,  6.8 ,   0.1312	);
	grHIN_v2pt[4]->SetPoint(14,  8.1 ,   0.1061	);
	grHIN_v2pt[4]->SetPoint(15,  10.6,   0.07474	);
	grHIN_v2pt[4]->SetPoint(16,  12.9,   0.07595	);
	grHIN_v2pt[4]->SetPoint(17,  14.9,   0.07223	);
	grHIN_v2pt[4]->SetPoint(18,  17.4,   0.05885	);
	grHIN_v2pt[4]->SetPoint(19,  21.2,   0.06017	);
	grHIN_v2pt[4]->SetPoint(20,  26.1,   0.03951	);
	grHIN_v2pt[4]->SetPoint(21,  31.5,   0.0438	);
	grHIN_v2pt[4]->SetPoint(22,  40  ,   0.0304	);
	grHIN_v2pt[4]->SetPoint(23,  53.1,   0.0088	);

	grHIN_v2pt_sys[4] = (TGraphErrors*) grHIN_v2pt[4]->Clone();

	grHIN_v2pt[4]->SetPointError(0,   0,   0.0002	);
	grHIN_v2pt[4]->SetPointError(1,   0,   0.0003	);
	grHIN_v2pt[4]->SetPointError(2,   0,   0.0002	);
	grHIN_v2pt[4]->SetPointError(3,   0,   0.0003	);
	grHIN_v2pt[4]->SetPointError(4,   0,   0.0003	);
	grHIN_v2pt[4]->SetPointError(5,   0,   0.0004	);
	grHIN_v2pt[4]->SetPointError(6,   0,   0.0004	);
	grHIN_v2pt[4]->SetPointError(7,   0,   0.0005	);
	grHIN_v2pt[4]->SetPointError(8,   0,   0.0004	);
	grHIN_v2pt[4]->SetPointError(9,   0,   0.0008	);
	grHIN_v2pt[4]->SetPointError(10,  0,   0.0014	);
	grHIN_v2pt[4]->SetPointError(11,  0,   0.0022	);
	grHIN_v2pt[4]->SetPointError(12,  0,   0.0033	);
	grHIN_v2pt[4]->SetPointError(13,  0,   0.0046	);
	grHIN_v2pt[4]->SetPointError(14,  0,   0.0043	);
	grHIN_v2pt[4]->SetPointError(15,  0,   0.00823	);
	grHIN_v2pt[4]->SetPointError(16,  0,   0.00277	);
	grHIN_v2pt[4]->SetPointError(17,  0,   0.00308	);
	grHIN_v2pt[4]->SetPointError(18,  0,   0.00348	);
	grHIN_v2pt[4]->SetPointError(19,  0,   0.00463	);
	grHIN_v2pt[4]->SetPointError(20,  0,   0.00774	);
	grHIN_v2pt[4]->SetPointError(21,  0,   0.01098	);
	grHIN_v2pt[4]->SetPointError(22,  0,   0.0147	);
	grHIN_v2pt[4]->SetPointError(23,  0,   0.0318	);

	grHIN_v2pt_sys[4]->SetPointError(0,   1.0,     0.0050 );
	grHIN_v2pt_sys[4]->SetPointError(1,   1.0,     0.0053 );
	grHIN_v2pt_sys[4]->SetPointError(2,   1.0,     0.0058 );
	grHIN_v2pt_sys[4]->SetPointError(3,   1.0,     0.0063 );
	grHIN_v2pt_sys[4]->SetPointError(4,   1.0,     0.0067 );
	grHIN_v2pt_sys[4]->SetPointError(5,   1.0,     0.0071 );
	grHIN_v2pt_sys[4]->SetPointError(6,   1.0,     0.0074 );
	grHIN_v2pt_sys[4]->SetPointError(7,   1.0,     0.0076 );
	grHIN_v2pt_sys[4]->SetPointError(8,   1.0,     0.0078 );
	grHIN_v2pt_sys[4]->SetPointError(9,   1.0,     0.0075 );
	grHIN_v2pt_sys[4]->SetPointError(10,  1.0,     0.0066 );
	grHIN_v2pt_sys[4]->SetPointError(11,  1.0,     0.0056 );
	grHIN_v2pt_sys[4]->SetPointError(12,  1.0,     0.0048 );
	grHIN_v2pt_sys[4]->SetPointError(13,  1.0,     0.0045 );
	grHIN_v2pt_sys[4]->SetPointError(14,  1.0,     0.0036 );
	grHIN_v2pt_sys[4]->SetPointError(15,  1.0,     0.00254);
	grHIN_v2pt_sys[4]->SetPointError(16,  1.0,     0.00258);
	grHIN_v2pt_sys[4]->SetPointError(17,  1.0,     0.00246);
	grHIN_v2pt_sys[4]->SetPointError(18,  1.0,     0.00200);
	grHIN_v2pt_sys[4]->SetPointError(19,  1.0,     0.00205);
	grHIN_v2pt_sys[4]->SetPointError(20,  1.0,     0.00134);
	grHIN_v2pt_sys[4]->SetPointError(21,  1.0,     0.00149);
	grHIN_v2pt_sys[4]->SetPointError(22,  1.0,     0.0032 );
	grHIN_v2pt_sys[4]->SetPointError(23,  1.0,     0.0009 );

	// 50 - 60%
	grHIN_v2pt[5] = new TGraphErrors(24);
	grHIN_v2pt[5]->SetPoint(0,   1.05,   0.1483 );
	grHIN_v2pt[5]->SetPoint(1,   1.15,   0.1595 );
	grHIN_v2pt[5]->SetPoint(2,   1.29,   0.1712 );
	grHIN_v2pt[5]->SetPoint(3,   1.49,   0.1862 );
	grHIN_v2pt[5]->SetPoint(4,   1.69,   0.1972 );
	grHIN_v2pt[5]->SetPoint(5,   1.89,   0.2069 );
	grHIN_v2pt[5]->SetPoint(6,   2.09,   0.2136 );
	grHIN_v2pt[5]->SetPoint(7,   2.29,   0.216  );
	grHIN_v2pt[5]->SetPoint(8,   2.7 ,   0.2179 );
	grHIN_v2pt[5]->SetPoint(9,   3.51,   0.2017 );
	grHIN_v2pt[5]->SetPoint(10,  4.32,   0.1762 );
	grHIN_v2pt[5]->SetPoint(11,  5.14,   0.1569 );
	grHIN_v2pt[5]->SetPoint(12,  6   ,   0.1399 );
	grHIN_v2pt[5]->SetPoint(13,  6.8 ,   0.123  );
	grHIN_v2pt[5]->SetPoint(14,  8.1 ,   0.1069 );
	grHIN_v2pt[5]->SetPoint(15,  10.6,   0.0962 );
	grHIN_v2pt[5]->SetPoint(16,  12.9,   0.07192);
	grHIN_v2pt[5]->SetPoint(17,  14.9,   0.07558);
	grHIN_v2pt[5]->SetPoint(18,  17.4,   0.06493);
	grHIN_v2pt[5]->SetPoint(19,  21.2,   0.06306);
	grHIN_v2pt[5]->SetPoint(20,  26.1,   0.0679 );
	grHIN_v2pt[5]->SetPoint(21,  31.5,   0.0483 );
	grHIN_v2pt[5]->SetPoint(22,  40  ,   0.071  );
	grHIN_v2pt[5]->SetPoint(23,  53.1,   -0.0459);

	grHIN_v2pt_sys[5] = (TGraphErrors*) grHIN_v2pt[5]->Clone();

	grHIN_v2pt[5]->SetPointError(0,   0,   0.0004	);
	grHIN_v2pt[5]->SetPointError(1,   0,   0.0004	);
	grHIN_v2pt[5]->SetPointError(2,   0,   0.0003	);
	grHIN_v2pt[5]->SetPointError(3,   0,   0.0004	);
	grHIN_v2pt[5]->SetPointError(4,   0,   0.0005	);
	grHIN_v2pt[5]->SetPointError(5,   0,   0.0006	);
	grHIN_v2pt[5]->SetPointError(6,   0,   0.0007	);
	grHIN_v2pt[5]->SetPointError(7,   0,   0.0009	);
	grHIN_v2pt[5]->SetPointError(8,   0,   0.0007	);
	grHIN_v2pt[5]->SetPointError(9,   0,   0.0012	);
	grHIN_v2pt[5]->SetPointError(10,  0,   0.0021	);
	grHIN_v2pt[5]->SetPointError(11,  0,   0.0034	);
	grHIN_v2pt[5]->SetPointError(12,  0,   0.0049	);
	grHIN_v2pt[5]->SetPointError(13,  0,   0.0069	);
	grHIN_v2pt[5]->SetPointError(14,  0,   0.0066	);
	grHIN_v2pt[5]->SetPointError(15,  0,   0.0127	);
	grHIN_v2pt[5]->SetPointError(16,  0,   0.00436	);
	grHIN_v2pt[5]->SetPointError(17,  0,   0.00488	);
	grHIN_v2pt[5]->SetPointError(18,  0,   0.00554	);
	grHIN_v2pt[5]->SetPointError(19,  0,   0.00735	);
	grHIN_v2pt[5]->SetPointError(20,  0,   0.0124	);
	grHIN_v2pt[5]->SetPointError(21,  0,   0.0179	);
	grHIN_v2pt[5]->SetPointError(22,  0,   0.0246	);
	grHIN_v2pt[5]->SetPointError(23,  0,   0.0525	);

	grHIN_v2pt_sys[5]->SetPointError(0,   1.0,    0.0050  );
	grHIN_v2pt_sys[5]->SetPointError(1,   1.0,    0.0054  );
	grHIN_v2pt_sys[5]->SetPointError(2,   1.0,    0.0058  );
	grHIN_v2pt_sys[5]->SetPointError(3,   1.0,    0.0063  );
	grHIN_v2pt_sys[5]->SetPointError(4,   1.0,    0.0067  );
	grHIN_v2pt_sys[5]->SetPointError(5,   1.0,    0.0070  );
	grHIN_v2pt_sys[5]->SetPointError(6,   1.0,    0.0073  );
	grHIN_v2pt_sys[5]->SetPointError(7,   1.0,    0.0073  );
	grHIN_v2pt_sys[5]->SetPointError(8,   1.0,    0.0074  );
	grHIN_v2pt_sys[5]->SetPointError(9,   1.0,    0.0069  );
	grHIN_v2pt_sys[5]->SetPointError(10,  1.0,    0.0060  );
	grHIN_v2pt_sys[5]->SetPointError(11,  1.0,    0.0053  );
	grHIN_v2pt_sys[5]->SetPointError(12,  1.0,    0.0048  );
	grHIN_v2pt_sys[5]->SetPointError(13,  1.0,    0.0042  );
	grHIN_v2pt_sys[5]->SetPointError(14,  1.0,    0.0036  );
	grHIN_v2pt_sys[5]->SetPointError(15,  1.0,    0.0033  );
	grHIN_v2pt_sys[5]->SetPointError(16,  1.0,    0.00245 );
	grHIN_v2pt_sys[5]->SetPointError(17,  1.0,    0.00257 );
	grHIN_v2pt_sys[5]->SetPointError(18,  1.0,    0.00221 );
	grHIN_v2pt_sys[5]->SetPointError(19,  1.0,    0.00214 );
	grHIN_v2pt_sys[5]->SetPointError(20,  1.0,    0.0023  );
	grHIN_v2pt_sys[5]->SetPointError(21,  1.0,    0.0016  );
	grHIN_v2pt_sys[5]->SetPointError(22,  1.0,    0.0074  );
	grHIN_v2pt_sys[5]->SetPointError(23,  1.0,    0.0048  );


	for ( int i = 0; i < 6; i++ ) {
		grHIN_v2pt[i]->SetMarkerStyle(kOpenCircle);
		grHIN_v2pt_sys[i]->SetFillColor(kGray);
		mgrHIN11012_v2[i] = new TMultiGraph();
		mgrHIN11012_v2[i]->Add(grHIN_v2pt_sys[i], "[]2");
		mgrHIN11012_v2[i]->Add(grHIN_v2pt[i], "p");
	}
}
