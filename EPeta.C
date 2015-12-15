{
	TFile * fv2_ep;
	TFile * fv2_sp;
	TFile * fv2_ep_de;
	TFile * fv2_sp_de;


	if ( bCM ) {
		fv2_ep = new TFile("txt/EP/Save_pt_0_EP_cm.root");
		fv2_sp = new TFile("txt/EP/Save_pt_1_SP_cm.root");
		fv2_ep_de = new TFile("txt/EP/Save_pt_2_DecorEP_cm.root");
		fv2_sp_de = new TFile("txt/EP/Save_pt_3_DecorSP_cm.root");
	} else {
		fv2_ep = new TFile("txt/EP/Save_pt_0_EP_extended.root");
		fv2_sp = new TFile("txt/EP/Save_pt_1_SP_extended.root");
		fv2_ep_de = new TFile("txt/EP/Save_pt_2_DecorEP_extended.root");
		fv2_sp_de = new TFile("txt/EP/Save_pt_3_DecorSP_extended.root");
	}

	TGraphErrors* gr_cm_v2pt_p_EP_p[20] = {};
	TGraphErrors* gr_cm_v2pt_p_EP_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_m_EP_p[20] = {};
	TGraphErrors* gr_cm_v2pt_m_EP_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_EP_p[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_EP_Pb[20] = {};

	TGraphErrors* gr_cm_v2pt_p_SP_p[20] = {};
	TGraphErrors* gr_cm_v2pt_p_SP_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_m_SP_p[20] = {};
	TGraphErrors* gr_cm_v2pt_m_SP_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_SP_p[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_SP_Pb[20] = {};

	TGraphErrors* gr_cm_v2pt_p_EPde_p[20] = {};
	TGraphErrors* gr_cm_v2pt_p_EPde_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_m_EPde_p[20] = {};
	TGraphErrors* gr_cm_v2pt_m_EPde_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_EPde_p[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_EPde_Pb[20] = {};

	TGraphErrors* gr_cm_v2pt_p_SPde_p[20] = {};
	TGraphErrors* gr_cm_v2pt_p_SPde_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_m_SPde_p[20] = {};
	TGraphErrors* gr_cm_v2pt_m_SPde_Pb[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_SPde_p[20] = {};
	TGraphErrors* gr_cm_v2pt_Pb_SPde_Pb[20] = {};

	TString HM[] = {
		"", // 0
		"", // 1
		"", // 2
		"HM100", // 3
		"HM130", // 4
		"HM160", // 5
		"HM190", // 6
		"HM220", // 7
		"", // 8
		"", // 9
		"", // 10
		"", // 11
	};

	for ( int i = 3; i < 8; i++ ) {
		gr_cm_v2pt_p_EP_p[i]  = (TGraphErrors*) fv2_ep->Get(Form("v2_0_pPb_%s_02.0_02.4_p",  HM[i].Data() ));
		gr_cm_v2pt_p_EP_Pb[i] = (TGraphErrors*) fv2_ep->Get(Form("v2_0_pPb_%s_02.0_02.4_Pb", HM[i].Data() ));
		gr_cm_v2pt_m_EP_p[i]  = (TGraphErrors*) fv2_ep->Get(Form("v2_0_pPb_%s_-0.8_00.8_p",  HM[i].Data() ));
		gr_cm_v2pt_m_EP_Pb[i] = (TGraphErrors*) fv2_ep->Get(Form("v2_0_pPb_%s_-0.8_00.8_Pb", HM[i].Data() ));
		gr_cm_v2pt_Pb_EP_p[i] = (TGraphErrors*) fv2_ep->Get(Form("v2_0_pPb_%s_-1.6_-1.2_p",  HM[i].Data() ));
		gr_cm_v2pt_Pb_EP_Pb[i]= (TGraphErrors*) fv2_ep->Get(Form("v2_0_pPb_%s_-1.6_-1.2_Pb", HM[i].Data() ));

		gr_cm_v2pt_p_SP_p[i]  = (TGraphErrors*) fv2_sp->Get(Form("v2_1_pPb_%s_02.0_02.4_p",  HM[i].Data() ));
		gr_cm_v2pt_p_SP_Pb[i] = (TGraphErrors*) fv2_sp->Get(Form("v2_1_pPb_%s_02.0_02.4_Pb", HM[i].Data() ));
		gr_cm_v2pt_m_SP_p[i]  = (TGraphErrors*) fv2_sp->Get(Form("v2_1_pPb_%s_-0.8_00.8_p",  HM[i].Data() ));
		gr_cm_v2pt_m_SP_Pb[i] = (TGraphErrors*) fv2_sp->Get(Form("v2_1_pPb_%s_-0.8_00.8_Pb", HM[i].Data() ));
		gr_cm_v2pt_Pb_SP_p[i] = (TGraphErrors*) fv2_sp->Get(Form("v2_1_pPb_%s_-1.6_-1.2_p",  HM[i].Data() ));
		gr_cm_v2pt_Pb_SP_Pb[i]= (TGraphErrors*) fv2_sp->Get(Form("v2_1_pPb_%s_-1.6_-1.2_Pb", HM[i].Data() ));

		gr_cm_v2pt_p_EPde_p[i]  = (TGraphErrors*) fv2_ep_de->Get(Form("v2_2_pPb_%s_02.0_02.4_p",  HM[i].Data() ));
		gr_cm_v2pt_p_EPde_Pb[i] = (TGraphErrors*) fv2_ep_de->Get(Form("v2_2_pPb_%s_02.0_02.4_Pb", HM[i].Data() ));
		gr_cm_v2pt_m_EPde_p[i]  = (TGraphErrors*) fv2_ep_de->Get(Form("v2_2_pPb_%s_-0.8_00.8_p",  HM[i].Data() ));
		gr_cm_v2pt_m_EPde_Pb[i] = (TGraphErrors*) fv2_ep_de->Get(Form("v2_2_pPb_%s_-0.8_00.8_Pb", HM[i].Data() ));
		gr_cm_v2pt_Pb_EPde_p[i] = (TGraphErrors*) fv2_ep_de->Get(Form("v2_2_pPb_%s_-1.6_-1.2_p",  HM[i].Data() ));
		gr_cm_v2pt_Pb_EPde_Pb[i]= (TGraphErrors*) fv2_ep_de->Get(Form("v2_2_pPb_%s_-1.6_-1.2_Pb", HM[i].Data() ));

		gr_cm_v2pt_p_SPde_p[i]  = (TGraphErrors*) fv2_sp_de->Get(Form("v2_3_pPb_%s_02.0_02.4_p",  HM[i].Data() ));
		gr_cm_v2pt_p_SPde_Pb[i] = (TGraphErrors*) fv2_sp_de->Get(Form("v2_3_pPb_%s_02.0_02.4_Pb", HM[i].Data() ));
		gr_cm_v2pt_m_SPde_p[i]  = (TGraphErrors*) fv2_sp_de->Get(Form("v2_3_pPb_%s_-0.8_00.8_p",  HM[i].Data() ));
		gr_cm_v2pt_m_SPde_Pb[i] = (TGraphErrors*) fv2_sp_de->Get(Form("v2_3_pPb_%s_-0.8_00.8_Pb", HM[i].Data() ));
		gr_cm_v2pt_Pb_SPde_p[i] = (TGraphErrors*) fv2_sp_de->Get(Form("v2_3_pPb_%s_-1.6_-1.2_p",  HM[i].Data() ));
		gr_cm_v2pt_Pb_SPde_Pb[i]= (TGraphErrors*) fv2_sp_de->Get(Form("v2_3_pPb_%s_-1.6_-1.2_Pb", HM[i].Data() ));


		gr_cm_v2pt_p_EP_Pb[i]->SetMarkerStyle(kOpenSquare);
		gr_cm_v2pt_p_EP_Pb[i]->SetMarkerSize(2);
		gr_cm_v2pt_p_EP_Pb[i]->SetMarkerColor(kRed);
		gr_cm_v2pt_p_EP_Pb[i]->SetLineColor(kRed);

		gr_cm_v2pt_Pb_EP_p[i]->SetMarkerStyle(kOpenSquare);
		gr_cm_v2pt_Pb_EP_p[i]->SetMarkerSize(2);
		gr_cm_v2pt_Pb_EP_p[i]->SetMarkerColor(kBlue);
		gr_cm_v2pt_Pb_EP_p[i]->SetLineColor(kBlue);

		gr_cm_v2pt_p_EPde_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_cm_v2pt_p_EPde_Pb[i]->SetMarkerSize(2);
		gr_cm_v2pt_p_EPde_Pb[i]->SetMarkerColor(kRed);
		gr_cm_v2pt_p_EPde_Pb[i]->SetLineColor(kRed);

		gr_cm_v2pt_Pb_EPde_p[i]->SetMarkerStyle(kFullSquare);
		gr_cm_v2pt_Pb_EPde_p[i]->SetMarkerSize(2);
		gr_cm_v2pt_Pb_EPde_p[i]->SetMarkerColor(kBlue);
		gr_cm_v2pt_Pb_EPde_p[i]->SetLineColor(kBlue);

		gr_cm_v2pt_p_SP_Pb[i]->SetMarkerStyle(kOpenSquare);
		gr_cm_v2pt_p_SP_Pb[i]->SetMarkerSize(2);
		gr_cm_v2pt_p_SP_Pb[i]->SetMarkerColor(kRed);
		gr_cm_v2pt_p_SP_Pb[i]->SetLineColor(kRed);

		gr_cm_v2pt_Pb_SP_p[i]->SetMarkerStyle(kOpenSquare);
		gr_cm_v2pt_Pb_SP_p[i]->SetMarkerSize(2);
		gr_cm_v2pt_Pb_SP_p[i]->SetMarkerColor(kBlue);
		gr_cm_v2pt_Pb_SP_p[i]->SetLineColor(kBlue);

		gr_cm_v2pt_p_SPde_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_cm_v2pt_p_SPde_Pb[i]->SetMarkerSize(2);
		gr_cm_v2pt_p_SPde_Pb[i]->SetMarkerColor(kRed);
		gr_cm_v2pt_p_SPde_Pb[i]->SetLineColor(kRed);

		gr_cm_v2pt_Pb_SPde_p[i]->SetMarkerStyle(kFullSquare);
		gr_cm_v2pt_Pb_SPde_p[i]->SetMarkerSize(2);
		gr_cm_v2pt_Pb_SPde_p[i]->SetMarkerColor(kBlue);
		gr_cm_v2pt_Pb_SPde_p[i]->SetLineColor(kBlue);

	}

	for ( int i = 0; i < 20; i++ ) {
		if ( gr_cm_v2pt_p_EP_p[i] ) {
			TString s = gr_cm_v2pt_p_EP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_EP_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_p_EP_Pb[i] ) {
			TString s = gr_cm_v2pt_p_EP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_EP_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_EP_p[i] ) {
			TString s = gr_cm_v2pt_m_EP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_EP_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_EP_Pb[i] ) {
			TString s = gr_cm_v2pt_m_EP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_EP_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_EP_p[i] ) {
			TString s = gr_cm_v2pt_Pb_EP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_EP_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_EP_Pb[i] ) {
			TString s = gr_cm_v2pt_Pb_EP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_EP_Pb[i]->SetName((char*)s);
		}

		if ( gr_cm_v2pt_p_SP_p[i] ) {
			TString s = gr_cm_v2pt_p_SP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_SP_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_p_SP_Pb[i] ) {
			TString s = gr_cm_v2pt_p_SP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_SP_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_SP_p[i] ) {
			TString s = gr_cm_v2pt_m_SP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_SP_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_SP_Pb[i] ) {
			TString s = gr_cm_v2pt_m_SP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_SP_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_SP_p[i] ) {
			TString s = gr_cm_v2pt_Pb_SP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_SP_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_SP_Pb[i] ) {
			TString s = gr_cm_v2pt_Pb_SP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_SP_Pb[i]->SetName((char*)s);
		}

		if ( gr_cm_v2pt_p_EPde_p[i] ) {
			TString s = gr_cm_v2pt_p_EPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_EPde_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_p_EPde_Pb[i] ) {
			TString s = gr_cm_v2pt_p_EPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_EPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_EPde_p[i] ) {
			TString s = gr_cm_v2pt_m_EPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_EPde_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_EPde_Pb[i] ) {
			TString s = gr_cm_v2pt_m_EPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_EPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_EPde_p[i] ) {
			TString s = gr_cm_v2pt_Pb_EPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_EPde_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_EPde_Pb[i] ) {
			TString s = gr_cm_v2pt_Pb_EPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_EPde_Pb[i]->SetName((char*)s);
		}

		if ( gr_cm_v2pt_p_SPde_p[i] ) {
			TString s = gr_cm_v2pt_p_SPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_SPde_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_p_SPde_Pb[i] ) {
			TString s = gr_cm_v2pt_p_SPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_p_SPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_SPde_p[i] ) {
			TString s = gr_cm_v2pt_m_SPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_SPde_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_m_SPde_Pb[i] ) {
			TString s = gr_cm_v2pt_m_SPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_m_SPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_SPde_p[i] ) {
			TString s = gr_cm_v2pt_Pb_SPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_SPde_p[i]->SetName((char*)s);
		}
		if ( gr_cm_v2pt_Pb_SPde_Pb[i] ) {
			TString s = gr_cm_v2pt_Pb_SPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_cm_v2pt_Pb_SPde_Pb[i]->SetName((char*)s);
		}

	}


}
