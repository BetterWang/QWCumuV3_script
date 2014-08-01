//                                       0,   1,   2,   3,   4,   5,   6,   7,   8,   9, 10, 11, 12, 13, 14, 15, 16, 17,
  const Int_t CentNoffCut[] = {100000, 350, 320, 300, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
// 5bin                                 70,  64,  60,  52,  48,  44,  37,  30,  24,  20, 16, 12, 10,  8,  6,  4,  2, 0,
//                                       0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10, 11, 12, 13, 14, 15, 16, 17, 18
const Int_t CentNoffCutPbPb[]={100000, 350, 320, 300, 280, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
//                                       0,        1,        2,   3,   4,   5,   6,   7,   8,  9,     10,     11,         12, 13, 14, 15, 16, 17, 18,
const Int_t MergedNoff6[] =   {100000, 350,      300,      260, 240, 220, 185, 150, 120, 100, 80,     60,     40,         5};

//                                       0,                  1,        2,   3,   4,   5,   6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
const Int_t MergedNoff8[] =   {100000, 350,                260,      220, 185, 150, 120, 100, 80, 40,  5};

//                                       0,   1,   2,   3,   4,   5,   6,   7,   8,   9, 10, 11, 12, 13, 14, 15, 16, 17,
const Int_t CentNoffCutHJ[] = {100000, 350, 320, 300, 260, 240, 220, 185, 150, 120, 100, 80, 40,  0};

//                                            0,   1,   2,   3,/  4,   5,/  6,/  7,   8,/  9, 10, 11, 12, 13, 14, 15, 16, 17,
  const Int_t CentNoffCutTest4[] = {100000, 350, 320, 300, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
//                                            0,        1,   2,   3,   4,   5,   6,   7,   8,      9,     10, 11, 12, 13, 14, 15, 16, 17,
  const Int_t CentNoffCutTest6[] = {100000, 350,      300, 260, 240, 220, 185, 150, 120, 100,     60,     40,  0};
//                                            0,             1,        2,   3,   4,   5,   6,      7,      8,  9, 10, 11, 12, 13, 14, 15, 16, 17,
  const Int_t CentNoffCutTest8[] = {100000, 350,           260,      220, 185, 150, 120, 100,     60,     40,  0};


//                                        0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,      11,      12,      13,      14,      15,      16, 17
  const Int_t NoffX4[] =           {359.764, 328.683, 306.788, 270.533, 247.167, 227.471, 196.657, 162.105, 131.342, 108.182, 88.3896, 68.6361, 54.3307, 44.3644, 34.3945, 24.4108, 14.3734, 0};
//                                        0,     1,       2,       3,       4,       5,       6,       7,       8,       9,      10,11,
  const Int_t NoffX6[] =           {359.764, 310.8, 270.533, 247.167, 227.471, 196.657, 162.105, 131.342, 108.182, 75.6681, 48.8896, 0};
//                                        0,       1,       2,       3,       4,       5,       6,       7,       8, 9
  const Int_t NoffX8[] =           {359.764, 272.147, 231.495, 196.657, 162.105, 131.342, 108.182, 75.6681, 48.8896, 0};

int NCent4 = 17;
int NCent6 = 11;
int NCent8 = 9;
int NCent[4] = { NCent4, NCent4, NCent6, NCent8};


int getNoff(int N) {
	int cent = 18;
	while ( CentNoffCut[cent] <= N ) cent--;
	return cent;
}

int getNoffPbPb(int N) {
	int cent = 19;
	while ( CentNoffCutPbPb[cent] <= N ) cent--;
	return cent;
}



int getNoff6(int N) {
	int cent = 13;
	while ( MergedNoff6[cent] <= N ) cent--;
	return cent;
}

int getNoff8(int N) {
	int cent = 9;
	while ( MergedNoff8[cent] <= N ) cent--;
	return cent;

}

//int getNoffGen(int N) {
//	int cent = 1;
//	while ( pCent[cent] > N ) cent++;
//	cent--;
//	return cent;
//}


const double ptbins[] = {
	                0.1, 0.3, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 6.0, 8.0,
			                        10.0, 12.0, 16.0, 20.0, 30.0, 40.0, 100.0}; // pPb pt binning nPtBins = 18;
const Int_t nPtBins = sizeof(ptbins)/sizeof(double)-1;

//                         0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,   12,   13,   14,   15,   16,   17
const double ptX[18] = { 0.2, 0.4, 0.7, 1.2, 1.7, 2.2, 2.7, 3.4, 4.4, 5.4, 7.0, 9.0, 11.0, 14.0, 18.0, 25.0, 35.0, 70.0};

const double etabins[] = {
	                -2.4, -2.2, -2, -1.8, -1.6, -1.4, -1.2, -1, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4
};
const Int_t nEtaBins = sizeof(etabins)/sizeof(double)-1;

