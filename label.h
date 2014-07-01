
char * fname[] = {
	"reserved/",			// 0
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1/", 			// 1 pPb HLT std closed
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_rereco/", 			// 2 pPb HLT rereco std closed
	"../pPb/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_reverse/", 		// 3 pPb HLT reverse std closed
	"NA", 									// 4 1+2+3 pPb HLT std closed
};

char * ftxt[] = {
	"reserved/",								// 0
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1/",				// 1
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_rereco/",			// 2
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_reverse/",			// 3
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_full/",			// 4
};

void addchain(int s1)
{
	cout << fname[s1] << endl;
	for ( int n = 1; n < 7; n++ ) {
		ch[n]->Add(Form("%s/*.root/cumulant100/trV%i", fname[s1], n));
		ch[n]->Add(Form("%s/*.root/cumulant130/trV%i", fname[s1], n));
		ch[n]->Add(Form("%s/*.root/cumulant160/trV%i", fname[s1], n));
		ch[n]->Add(Form("%s/*.root/cumulant190/trV%i", fname[s1], n));
		ch[n]->Add(Form("%s/*.root/cumulant220/trV%i", fname[s1], n));
	}
	chG->Add(Form("%s/*.root/cumulant100/trG", fname[s1]));
	chG->Add(Form("%s/*.root/cumulant130/trG", fname[s1]));
	chG->Add(Form("%s/*.root/cumulant160/trG", fname[s1]));
	chG->Add(Form("%s/*.root/cumulant190/trG", fname[s1]));
	chG->Add(Form("%s/*.root/cumulant220/trG", fname[s1]));
}
