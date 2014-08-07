
char * fname[] = {
	"test/",			// 0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1/", 			// 1 pPb HLT std closed
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_rereco/", 			// 2 pPb HLT rereco std closed
	"../pPb/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_reverse/", 		// 3 pPb HLT reverse std closed
	"NA", 									// 4 1+2+3 pPb HLT std closed
};

char * ftxt[] = {
	"txt/test/",								// 0
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1/",				// 1
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_rereco/",			// 2
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_reverse/",			// 3
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm1_full/",			// 4
};

void addchain(int s1)
{
	cout << fname[s1] << endl;
	chV->Add(Form("%s/*.root/cumulant100/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant130/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant160/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant190/trV", fname[s1]));
	chV->Add(Form("%s/*.root/cumulant220/trV", fname[s1]));
}
