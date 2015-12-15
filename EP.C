{
	TFile * fv2_ep;
	TFile * fv2_sp;
	TFile * fv2_ep_de;
	TFile * fv2_sp_de;

	TFile * fv3_ep;
	TFile * fv3_sp;
	TFile * fv3_ep_de;
	TFile * fv3_sp_de;

	int bCut = 0;
	if ( bPbPb ) {
		if ( bCut ) {
			fv2_ep = new TFile(Form("txt/EP/cuts/Save_PbPb_v2_0_EP_HM100_cut%i.root", nCut));
			fv2_sp = new TFile(Form("txt/EP/cuts/Save_PbPb_v2_1_SP_HM100_cut%i.root", nCut));
			fv2_ep_de = new TFile(Form("txt/EP/cuts/Save_PbPb_v2_2_EP_HM100_cut%i.root", nCut));
			fv2_sp_de = new TFile(Form("txt/EP/cuts/Save_PbPb_v2_3_SP_HM100_cut%i.root", nCut));
		}
		fv2_ep = new TFile("txt/EP/Save_PbPb_v2_0_EP_HM100.root");
		fv2_sp = new TFile("txt/EP/Save_PbPb_v2_1_SP_HM100.root");
		fv2_ep_de = new TFile("txt/EP/Save_PbPb_v2_2_EP_HM100.root");
		fv2_sp_de = new TFile("txt/EP/Save_PbPb_v2_3_SP_HM100.root");

		fv3_ep = new TFile("txt/EP/Save_PbPb_v3_0_EP_HM100.root");
		fv3_sp = new TFile("txt/EP/Save_PbPb_v3_1_SP_HM100.root");
		fv3_ep_de = new TFile("txt/EP/Save_PbPb_v3_2_EP_HM100.root");
		fv3_sp_de = new TFile("txt/EP/Save_PbPb_v3_3_SP_HM100.root");
	} else {
		if ( bCut ) {
			fv2_ep = new TFile(Form("txt/EP/cuts/Save_v2_0_EP_HM100_cut%i.root", nCut));
			fv2_sp = new TFile(Form("txt/EP/cuts/Save_v2_1_SP_HM100_cut%i.root", nCut));
			fv2_ep_de = new TFile(Form("txt/EP/cuts/Save_v2_2_EP_HM100_cut%i.root", nCut));
			fv2_sp_de = new TFile(Form("txt/EP/cuts/Save_v2_3_SP_HM100_cut%i.root", nCut));
		} else {
			fv2_ep = new TFile("txt/EP/Save_v2_0_EP_HM100.root");
			fv2_sp = new TFile("txt/EP/Save_v2_1_SP_HM100.root");
			fv2_ep_de = new TFile("txt/EP/Save_v2_2_EP_HM100.root");
			fv2_sp_de = new TFile("txt/EP/Save_v2_3_SP_HM100.root");

			fv3_ep = new TFile("txt/EP/Save_v3_0_EP_HM100.root");
			fv3_sp = new TFile("txt/EP/Save_v3_1_SP_HM100.root");
			fv3_ep_de = new TFile("txt/EP/Save_v3_2_EP_HM100.root");
			fv3_sp_de = new TFile("txt/EP/Save_v3_3_SP_HM100.root");
		}
	}


	TGraphErrors * gr_v2p_EP[20] = {};
	TGraphErrors * gr_v2p_SP[20] = {};
	TGraphErrors * gr_v2p_EP_de[20] = {};
	TGraphErrors * gr_v2p_SP_de[20] = {};

	TGraphErrors * gr_v2Pb_EP[20] = {};
	TGraphErrors * gr_v2Pb_SP[20] = {};
	TGraphErrors * gr_v2Pb_EP_de[20] = {};
	TGraphErrors * gr_v2Pb_SP_de[20] = {};

	TGraphErrors * gr_v3p_EP[20] = {};
	TGraphErrors * gr_v3p_SP[20] = {};
	TGraphErrors * gr_v3p_EP_de[20] = {};
	TGraphErrors * gr_v3p_SP_de[20] = {};

	TGraphErrors * gr_v3Pb_EP[20] = {};
	TGraphErrors * gr_v3Pb_SP[20] = {};
	TGraphErrors * gr_v3Pb_EP_de[20] = {};
	TGraphErrors * gr_v3Pb_SP_de[20] = {};


	if ( bPbPb ) {
		gr_v2Pb_EP[7] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM100_HFm2_m");
		gr_v2Pb_EP[6] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM130_HFm2_m");
		gr_v2Pb_EP[5] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM160_HFm2_m");
		gr_v2Pb_EP[4] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM190_HFm2_m");
		gr_v2Pb_EP[3] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM220_HFm2_m");

		gr_v2Pb_SP[7] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM100_HFm2_m");
		gr_v2Pb_SP[6] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM130_HFm2_m");
		gr_v2Pb_SP[5] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM160_HFm2_m");
		gr_v2Pb_SP[4] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM190_HFm2_m");
		gr_v2Pb_SP[3] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM220_HFm2_m");

		gr_v2Pb_EP_de[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM100_HFm2_m");
		gr_v2Pb_EP_de[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM130_HFm2_m");
		gr_v2Pb_EP_de[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM160_HFm2_m");
		gr_v2Pb_EP_de[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM190_HFm2_m");
		gr_v2Pb_EP_de[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM220_HFm2_m");

		gr_v2Pb_SP_de[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM100_HFm2_m");
		gr_v2Pb_SP_de[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM130_HFm2_m");
		gr_v2Pb_SP_de[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM160_HFm2_m");
		gr_v2Pb_SP_de[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM190_HFm2_m");
		gr_v2Pb_SP_de[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM220_HFm2_m");

		if ( !bCut ) {
			gr_v3Pb_EP[7] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM100_HFm3_m");
			gr_v3Pb_EP[6] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM130_HFm3_m");
			gr_v3Pb_EP[5] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM160_HFm3_m");
			gr_v3Pb_EP[4] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM190_HFm3_m");
			gr_v3Pb_EP[3] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM220_HFm3_m");

			gr_v3Pb_EP_de[7] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM100_HFm3_m");
			gr_v3Pb_EP_de[6] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM130_HFm3_m");
			gr_v3Pb_EP_de[5] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM160_HFm3_m");
			gr_v3Pb_EP_de[4] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM190_HFm3_m");
			gr_v3Pb_EP_de[3] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM220_HFm3_m");

			gr_v3Pb_SP[7] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM100_HFm3_m");
			gr_v3Pb_SP[6] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM130_HFm3_m");
			gr_v3Pb_SP[5] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM160_HFm3_m");
			gr_v3Pb_SP[4] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM190_HFm3_m");
			gr_v3Pb_SP[3] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM220_HFm3_m");

			gr_v3Pb_SP_de[7] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM100_HFm3_m");
			gr_v3Pb_SP_de[6] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM130_HFm3_m");
			gr_v3Pb_SP_de[5] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM160_HFm3_m");
			gr_v3Pb_SP_de[4] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM190_HFm3_m");
			gr_v3Pb_SP_de[3] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM220_HFm3_m");
		}

		gr_v2p_EP[7] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM100_HFp2_p");
		gr_v2p_EP[6] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM130_HFp2_p");
		gr_v2p_EP[5] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM160_HFp2_p");
		gr_v2p_EP[4] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM190_HFp2_p");
		gr_v2p_EP[3] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM220_HFp2_p");

		gr_v2p_SP[7] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM100_HFp2_p");
		gr_v2p_SP[6] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM130_HFp2_p");
		gr_v2p_SP[5] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM160_HFp2_p");
		gr_v2p_SP[4] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM190_HFp2_p");
		gr_v2p_SP[3] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM220_HFp2_p");

		gr_v2p_EP_de[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM100_HFp2_p");
		gr_v2p_EP_de[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM130_HFp2_p");
		gr_v2p_EP_de[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM160_HFp2_p");
		gr_v2p_EP_de[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM190_HFp2_p");
		gr_v2p_EP_de[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM220_HFp2_p");

		gr_v2p_SP_de[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM100_HFp2_p");
		gr_v2p_SP_de[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM130_HFp2_p");
		gr_v2p_SP_de[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM160_HFp2_p");
		gr_v2p_SP_de[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM190_HFp2_p");
		gr_v2p_SP_de[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM220_HFp2_p");

		if ( !bCut ) {
			gr_v3p_EP[7] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM100_HFp3_p");
			gr_v3p_EP[6] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM130_HFp3_p");
			gr_v3p_EP[5] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM160_HFp3_p");
			gr_v3p_EP[4] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM190_HFp3_p");
			gr_v3p_EP[3] = (TGraphErrors*) fv3_ep->Get("v3_0_PbPb_HM220_HFp3_p");

			gr_v3p_SP[7] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM100_HFp3_p");
			gr_v3p_SP[6] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM130_HFp3_p");
			gr_v3p_SP[5] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM160_HFp3_p");
			gr_v3p_SP[4] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM190_HFp3_p");
			gr_v3p_SP[3] = (TGraphErrors*) fv3_sp->Get("v3_1_PbPb_HM220_HFp3_p");

			gr_v3p_EP_de[7] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM100_HFp3_p");
			gr_v3p_EP_de[6] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM130_HFp3_p");
			gr_v3p_EP_de[5] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM160_HFp3_p");
			gr_v3p_EP_de[4] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM190_HFp3_p");
			gr_v3p_EP_de[3] = (TGraphErrors*) fv3_ep_de->Get("v3_2_PbPb_HM220_HFp3_p");

			gr_v3p_SP_de[7] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM100_HFp3_p");
			gr_v3p_SP_de[6] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM130_HFp3_p");
			gr_v3p_SP_de[5] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM160_HFp3_p");
			gr_v3p_SP_de[4] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM190_HFp3_p");
			gr_v3p_SP_de[3] = (TGraphErrors*) fv3_sp_de->Get("v3_3_PbPb_HM220_HFp3_p");
		}

	} else {
		gr_v2Pb_EP[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_HFp2_Pb");
		gr_v2Pb_EP[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_HFp2_Pb");
		gr_v2Pb_EP[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_HFp2_Pb");
		gr_v2Pb_EP[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_HFp2_Pb");
		gr_v2Pb_EP[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_HFp2_Pb");

		gr_v2Pb_SP[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_HFp2_Pb");
		gr_v2Pb_SP[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_HFp2_Pb");
		gr_v2Pb_SP[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_HFp2_Pb");
		gr_v2Pb_SP[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_HFp2_Pb");
		gr_v2Pb_SP[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_HFp2_Pb");

		gr_v2Pb_EP_de[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_HFp2_Pb");
		gr_v2Pb_EP_de[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_HFp2_Pb");
		gr_v2Pb_EP_de[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_HFp2_Pb");
		gr_v2Pb_EP_de[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_HFp2_Pb");
		gr_v2Pb_EP_de[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_HFp2_Pb");

		gr_v2Pb_SP_de[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_HFp2_Pb");
		gr_v2Pb_SP_de[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_HFp2_Pb");
		gr_v2Pb_SP_de[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_HFp2_Pb");
		gr_v2Pb_SP_de[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_HFp2_Pb");
		gr_v2Pb_SP_de[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_HFp2_Pb");

		if ( !bCut ) {
			gr_v3Pb_EP[7] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM100_HFp3_Pb");
			gr_v3Pb_EP[6] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM130_HFp3_Pb");
			gr_v3Pb_EP[5] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM160_HFp3_Pb");
			gr_v3Pb_EP[4] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM190_HFp3_Pb");
			gr_v3Pb_EP[3] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM220_HFp3_Pb");

			gr_v3Pb_EP_de[7] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM100_HFp3_Pb");
			gr_v3Pb_EP_de[6] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM130_HFp3_Pb");
			gr_v3Pb_EP_de[5] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM160_HFp3_Pb");
			gr_v3Pb_EP_de[4] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM190_HFp3_Pb");
			gr_v3Pb_EP_de[3] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM220_HFp3_Pb");

			gr_v3Pb_SP[7] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM100_HFp3_Pb");
			gr_v3Pb_SP[6] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM130_HFp3_Pb");
			gr_v3Pb_SP[5] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM160_HFp3_Pb");
			gr_v3Pb_SP[4] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM190_HFp3_Pb");
			gr_v3Pb_SP[3] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM220_HFp3_Pb");

			gr_v3Pb_SP_de[7] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM100_HFp3_Pb");
			gr_v3Pb_SP_de[6] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM130_HFp3_Pb");
			gr_v3Pb_SP_de[5] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM160_HFp3_Pb");
			gr_v3Pb_SP_de[4] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM190_HFp3_Pb");
			gr_v3Pb_SP_de[3] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM220_HFp3_Pb");
		}

		gr_v2p_EP[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_HFm2_p");
		gr_v2p_EP[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_HFm2_p");
		gr_v2p_EP[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_HFm2_p");
		gr_v2p_EP[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_HFm2_p");
		gr_v2p_EP[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_HFm2_p");

		gr_v2p_SP[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_HFm2_p");
		gr_v2p_SP[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_HFm2_p");
		gr_v2p_SP[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_HFm2_p");
		gr_v2p_SP[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_HFm2_p");
		gr_v2p_SP[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_HFm2_p");

		gr_v2p_EP_de[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_HFm2_p");
		gr_v2p_EP_de[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_HFm2_p");
		gr_v2p_EP_de[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_HFm2_p");
		gr_v2p_EP_de[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_HFm2_p");
		gr_v2p_EP_de[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_HFm2_p");

		gr_v2p_SP_de[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_HFm2_p");
		gr_v2p_SP_de[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_HFm2_p");
		gr_v2p_SP_de[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_HFm2_p");
		gr_v2p_SP_de[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_HFm2_p");
		gr_v2p_SP_de[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_HFm2_p");

		if ( !bCut ) {
			gr_v3p_EP[7] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM100_HFm3_p");
			gr_v3p_EP[6] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM130_HFm3_p");
			gr_v3p_EP[5] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM160_HFm3_p");
			gr_v3p_EP[4] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM190_HFm3_p");
			gr_v3p_EP[3] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM220_HFm3_p");

			gr_v3p_SP[7] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM100_HFm3_p");
			gr_v3p_SP[6] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM130_HFm3_p");
			gr_v3p_SP[5] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM160_HFm3_p");
			gr_v3p_SP[4] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM190_HFm3_p");
			gr_v3p_SP[3] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM220_HFm3_p");

			gr_v3p_EP_de[7] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM100_HFm3_p");
			gr_v3p_EP_de[6] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM130_HFm3_p");
			gr_v3p_EP_de[5] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM160_HFm3_p");
			gr_v3p_EP_de[4] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM190_HFm3_p");
			gr_v3p_EP_de[3] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM220_HFm3_p");

			gr_v3p_SP_de[7] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM100_HFm3_p");
			gr_v3p_SP_de[6] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM130_HFm3_p");
			gr_v3p_SP_de[5] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM160_HFm3_p");
			gr_v3p_SP_de[4] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM190_HFm3_p");
			gr_v3p_SP_de[3] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM220_HFm3_p");
		}
	}

	for ( int i = 3; i < 8; i++ ) {
		gr_v2p_EP[i]->SetMarkerStyle(kOpenSquare);
		gr_v2p_EP[i]->SetMarkerColor(kBlue);
		gr_v2p_EP[i]->SetLineColor(kBlue);
		gr_v2p_EP[i]->SetMarkerSize(2);

		gr_v2Pb_EP[i]->SetMarkerStyle(kOpenSquare);
		gr_v2Pb_EP[i]->SetMarkerColor(kRed);
		gr_v2Pb_EP[i]->SetLineColor(kRed);
		gr_v2Pb_EP[i]->SetMarkerSize(2);

		gr_v2p_EP_de[i]->SetMarkerStyle(kFullSquare);
		gr_v2p_EP_de[i]->SetMarkerColor(kBlue);
		gr_v2p_EP_de[i]->SetLineColor(kBlue);
		gr_v2p_EP_de[i]->SetMarkerSize(2);

		gr_v2Pb_EP_de[i]->SetMarkerStyle(kFullSquare);
		gr_v2Pb_EP_de[i]->SetMarkerColor(kRed);
		gr_v2Pb_EP_de[i]->SetLineColor(kRed);
		gr_v2Pb_EP_de[i]->SetMarkerSize(2);

		gr_v2p_SP[i]->SetMarkerStyle(kOpenSquare);
		gr_v2p_SP[i]->SetMarkerColor(kBlue);
		gr_v2p_SP[i]->SetLineColor(kBlue);
		gr_v2p_SP[i]->SetMarkerSize(2);

		gr_v2Pb_SP[i]->SetMarkerStyle(kOpenSquare);
		gr_v2Pb_SP[i]->SetMarkerColor(kRed);
		gr_v2Pb_SP[i]->SetLineColor(kRed);
		gr_v2Pb_SP[i]->SetMarkerSize(2);

		gr_v2p_SP_de[i]->SetMarkerStyle(kFullSquare);
		gr_v2p_SP_de[i]->SetMarkerColor(kBlue);
		gr_v2p_SP_de[i]->SetLineColor(kBlue);
		gr_v2p_SP_de[i]->SetMarkerSize(2);

		gr_v2Pb_SP_de[i]->SetMarkerStyle(kFullSquare);
		gr_v2Pb_SP_de[i]->SetMarkerColor(kRed);
		gr_v2Pb_SP_de[i]->SetLineColor(kRed);
		gr_v2Pb_SP_de[i]->SetMarkerSize(2);

	}

///////////////////////////////////////////

	fv2_ep = new TFile("txt/EP/Save_pt_0_EP.root");
	fv2_sp = new TFile("txt/EP/Save_pt_1_SP.root");
	fv2_ep_de = new TFile("txt/EP/Save_pt_2_DecorEP.root");
	fv2_sp_de = new TFile("txt/EP/Save_pt_3_DecorSP.root");

	TGraphErrors* gr_v2pt_p_EP_p[20] = {};
	TGraphErrors* gr_v2pt_p_EP_Pb[20] = {};
	TGraphErrors* gr_v2pt_m_EP_p[20] = {};
	TGraphErrors* gr_v2pt_m_EP_Pb[20] = {};
	TGraphErrors* gr_v2pt_Pb_EP_p[20] = {};
	TGraphErrors* gr_v2pt_Pb_EP_Pb[20] = {};

	TGraphErrors* gr_v2pt_p_SP_p[20] = {};
	TGraphErrors* gr_v2pt_p_SP_Pb[20] = {};
	TGraphErrors* gr_v2pt_m_SP_p[20] = {};
	TGraphErrors* gr_v2pt_m_SP_Pb[20] = {};
	TGraphErrors* gr_v2pt_Pb_SP_p[20] = {};
	TGraphErrors* gr_v2pt_Pb_SP_Pb[20] = {};

	TGraphErrors* gr_v2pt_p_EPde_p[20] = {};
	TGraphErrors* gr_v2pt_p_EPde_Pb[20] = {};
	TGraphErrors* gr_v2pt_m_EPde_p[20] = {};
	TGraphErrors* gr_v2pt_m_EPde_Pb[20] = {};
	TGraphErrors* gr_v2pt_Pb_EPde_p[20] = {};
	TGraphErrors* gr_v2pt_Pb_EPde_Pb[20] = {};

	TGraphErrors* gr_v2pt_p_SPde_p[20] = {};
	TGraphErrors* gr_v2pt_p_SPde_Pb[20] = {};
	TGraphErrors* gr_v2pt_m_SPde_p[20] = {};
	TGraphErrors* gr_v2pt_m_SPde_Pb[20] = {};
	TGraphErrors* gr_v2pt_Pb_SPde_p[20] = {};
	TGraphErrors* gr_v2pt_Pb_SPde_Pb[20] = {};


	if ( bPbPb ) {
		gr_v2pt_m_EP_p[7] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM100_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_p[6] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM130_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_p[5] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM160_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_p[4] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM190_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_p[3] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM220_HFp2_-0.8_00.8_p");

		gr_v2pt_m_EP_Pb[7] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM100_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_Pb[6] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM130_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_Pb[5] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM160_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_Pb[4] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM190_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EP_Pb[3] = (TGraphErrors*) fv2_ep->Get("v2_0_PbPb_HM220_HFp2_-0.8_00.8_p");

///
		gr_v2pt_m_SP_p[7] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM100_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_p[6] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM130_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_p[5] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM160_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_p[4] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM190_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_p[3] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM220_HFp2_-0.8_00.8_p");

		gr_v2pt_m_SP_Pb[7] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM100_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_Pb[6] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM130_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_Pb[5] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM160_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_Pb[4] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM190_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SP_Pb[3] = (TGraphErrors*) fv2_sp->Get("v2_1_PbPb_HM220_HFp2_-0.8_00.8_p");

///
		gr_v2pt_m_EPde_p[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM100_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM130_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM160_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM190_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM220_HFp2_-0.8_00.8_p");

		gr_v2pt_m_EPde_Pb[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM100_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_Pb[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM130_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_Pb[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM160_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_Pb[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM190_HFp2_-0.8_00.8_p");
		gr_v2pt_m_EPde_Pb[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_PbPb_HM220_HFp2_-0.8_00.8_p");

///
		gr_v2pt_m_SPde_p[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM100_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM130_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM160_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM190_HFp2_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM220_HFp2_-0.8_00.8_p");

		gr_v2pt_m_SPde_Pb[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM100_HFm2_-0.8_00.8_m");
		gr_v2pt_m_SPde_Pb[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM130_HFm2_-0.8_00.8_m");
		gr_v2pt_m_SPde_Pb[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM160_HFm2_-0.8_00.8_m");
		gr_v2pt_m_SPde_Pb[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM190_HFm2_-0.8_00.8_m");
		gr_v2pt_m_SPde_Pb[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_PbPb_HM220_HFm2_-0.8_00.8_m");


	} else {
		gr_v2pt_p_EP_p[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_02.0_02.4_p");
		gr_v2pt_p_EP_p[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_02.0_02.4_p");
		gr_v2pt_p_EP_p[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_02.0_02.4_p");
		gr_v2pt_p_EP_p[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_02.0_02.4_p");
		gr_v2pt_p_EP_p[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_02.0_02.4_p");

		gr_v2pt_p_EP_Pb[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_02.0_02.4_Pb");
		gr_v2pt_p_EP_Pb[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_02.0_02.4_Pb");
		gr_v2pt_p_EP_Pb[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_02.0_02.4_Pb");
		gr_v2pt_p_EP_Pb[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_02.0_02.4_Pb");
		gr_v2pt_p_EP_Pb[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_02.0_02.4_Pb");

		gr_v2pt_m_EP_p[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_-0.8_00.8_p");
		gr_v2pt_m_EP_p[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_-0.8_00.8_p");
		gr_v2pt_m_EP_p[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_-0.8_00.8_p");
		gr_v2pt_m_EP_p[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_-0.8_00.8_p");
		gr_v2pt_m_EP_p[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_-0.8_00.8_p");

		gr_v2pt_m_EP_Pb[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_-0.8_00.8_Pb");
		gr_v2pt_m_EP_Pb[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_-0.8_00.8_Pb");
		gr_v2pt_m_EP_Pb[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_-0.8_00.8_Pb");
		gr_v2pt_m_EP_Pb[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_-0.8_00.8_Pb");
		gr_v2pt_m_EP_Pb[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_-0.8_00.8_Pb");

		gr_v2pt_Pb_EP_p[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_-2.4_-2.0_p");
		gr_v2pt_Pb_EP_p[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_-2.4_-2.0_p");
		gr_v2pt_Pb_EP_p[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_-2.4_-2.0_p");
		gr_v2pt_Pb_EP_p[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_-2.4_-2.0_p");
		gr_v2pt_Pb_EP_p[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_-2.4_-2.0_p");

		gr_v2pt_Pb_EP_Pb[7] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM100_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EP_Pb[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EP_Pb[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EP_Pb[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EP_Pb[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_-2.4_-2.0_Pb");

///
		gr_v2pt_p_SP_p[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_02.0_02.4_p");
		gr_v2pt_p_SP_p[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_02.0_02.4_p");
		gr_v2pt_p_SP_p[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_02.0_02.4_p");
		gr_v2pt_p_SP_p[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_02.0_02.4_p");
		gr_v2pt_p_SP_p[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_02.0_02.4_p");

		gr_v2pt_p_SP_Pb[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_02.0_02.4_Pb");
		gr_v2pt_p_SP_Pb[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_02.0_02.4_Pb");
		gr_v2pt_p_SP_Pb[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_02.0_02.4_Pb");
		gr_v2pt_p_SP_Pb[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_02.0_02.4_Pb");
		gr_v2pt_p_SP_Pb[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_02.0_02.4_Pb");

		gr_v2pt_m_SP_p[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_-0.8_00.8_p");
		gr_v2pt_m_SP_p[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_-0.8_00.8_p");
		gr_v2pt_m_SP_p[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_-0.8_00.8_p");
		gr_v2pt_m_SP_p[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_-0.8_00.8_p");
		gr_v2pt_m_SP_p[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_-0.8_00.8_p");

		gr_v2pt_m_SP_Pb[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_-0.8_00.8_Pb");
		gr_v2pt_m_SP_Pb[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_-0.8_00.8_Pb");
		gr_v2pt_m_SP_Pb[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_-0.8_00.8_Pb");
		gr_v2pt_m_SP_Pb[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_-0.8_00.8_Pb");
		gr_v2pt_m_SP_Pb[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_-0.8_00.8_Pb");

		gr_v2pt_Pb_SP_p[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_-2.4_-2.0_p");
		gr_v2pt_Pb_SP_p[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_-2.4_-2.0_p");
		gr_v2pt_Pb_SP_p[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_-2.4_-2.0_p");
		gr_v2pt_Pb_SP_p[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_-2.4_-2.0_p");
		gr_v2pt_Pb_SP_p[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_-2.4_-2.0_p");

		gr_v2pt_Pb_SP_Pb[7] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM100_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SP_Pb[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SP_Pb[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SP_Pb[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SP_Pb[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_-2.4_-2.0_Pb");

///
		gr_v2pt_p_EPde_p[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_02.0_02.4_p");
		gr_v2pt_p_EPde_p[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_02.0_02.4_p");
		gr_v2pt_p_EPde_p[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_02.0_02.4_p");
		gr_v2pt_p_EPde_p[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_02.0_02.4_p");
		gr_v2pt_p_EPde_p[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_02.0_02.4_p");

		gr_v2pt_p_EPde_Pb[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_02.0_02.4_Pb");
		gr_v2pt_p_EPde_Pb[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_02.0_02.4_Pb");
		gr_v2pt_p_EPde_Pb[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_02.0_02.4_Pb");
		gr_v2pt_p_EPde_Pb[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_02.0_02.4_Pb");
		gr_v2pt_p_EPde_Pb[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_02.0_02.4_Pb");

		gr_v2pt_m_EPde_p[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_-0.8_00.8_p");
		gr_v2pt_m_EPde_p[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_-0.8_00.8_p");

		gr_v2pt_m_EPde_Pb[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_-0.8_00.8_Pb");
		gr_v2pt_m_EPde_Pb[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_-0.8_00.8_Pb");
		gr_v2pt_m_EPde_Pb[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_-0.8_00.8_Pb");
		gr_v2pt_m_EPde_Pb[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_-0.8_00.8_Pb");
		gr_v2pt_m_EPde_Pb[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_-0.8_00.8_Pb");

		gr_v2pt_Pb_EPde_p[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_-2.4_-2.0_p");
		gr_v2pt_Pb_EPde_p[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_-2.4_-2.0_p");
		gr_v2pt_Pb_EPde_p[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_-2.4_-2.0_p");
		gr_v2pt_Pb_EPde_p[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_-2.4_-2.0_p");
		gr_v2pt_Pb_EPde_p[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_-2.4_-2.0_p");

		gr_v2pt_Pb_EPde_Pb[7] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM100_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EPde_Pb[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EPde_Pb[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EPde_Pb[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_-2.4_-2.0_Pb");
		gr_v2pt_Pb_EPde_Pb[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_-2.4_-2.0_Pb");

///
		gr_v2pt_p_SPde_p[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_02.0_02.4_p");
		gr_v2pt_p_SPde_p[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_02.0_02.4_p");
		gr_v2pt_p_SPde_p[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_02.0_02.4_p");
		gr_v2pt_p_SPde_p[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_02.0_02.4_p");
		gr_v2pt_p_SPde_p[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_02.0_02.4_p");

		gr_v2pt_p_SPde_Pb[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_02.0_02.4_Pb");
		gr_v2pt_p_SPde_Pb[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_02.0_02.4_Pb");
		gr_v2pt_p_SPde_Pb[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_02.0_02.4_Pb");
		gr_v2pt_p_SPde_Pb[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_02.0_02.4_Pb");
		gr_v2pt_p_SPde_Pb[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_02.0_02.4_Pb");

		gr_v2pt_m_SPde_p[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_-0.8_00.8_p");
		gr_v2pt_m_SPde_p[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_-0.8_00.8_p");

		gr_v2pt_m_SPde_Pb[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_-0.8_00.8_Pb");
		gr_v2pt_m_SPde_Pb[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_-0.8_00.8_Pb");
		gr_v2pt_m_SPde_Pb[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_-0.8_00.8_Pb");
		gr_v2pt_m_SPde_Pb[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_-0.8_00.8_Pb");
		gr_v2pt_m_SPde_Pb[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_-0.8_00.8_Pb");

		gr_v2pt_Pb_SPde_p[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_-2.4_-2.0_p");
		gr_v2pt_Pb_SPde_p[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_-2.4_-2.0_p");
		gr_v2pt_Pb_SPde_p[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_-2.4_-2.0_p");
		gr_v2pt_Pb_SPde_p[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_-2.4_-2.0_p");
		gr_v2pt_Pb_SPde_p[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_-2.4_-2.0_p");

		gr_v2pt_Pb_SPde_Pb[7] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM100_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SPde_Pb[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SPde_Pb[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SPde_Pb[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_-2.4_-2.0_Pb");
		gr_v2pt_Pb_SPde_Pb[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_-2.4_-2.0_Pb");
	}

	for ( int i = 3; i < 8; i++ ) {
		if ( bPbPb ) {
			gr_v2pt_m_EP_p[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_EP_p[i]->SetMarkerColor(kRed);
			gr_v2pt_m_EP_p[i]->SetLineColor(kRed);
			gr_v2pt_m_EP_p[i]->SetMarkerSize(2);
			gr_v2pt_m_EP_p[i]->SetLineWidth(1);

			gr_v2pt_m_EP_Pb[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_EP_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_m_EP_Pb[i]->SetLineColor(kRed);
			gr_v2pt_m_EP_Pb[i]->SetMarkerSize(2);
			gr_v2pt_m_EP_Pb[i]->SetLineWidth(1);

			gr_v2pt_m_SP_p[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_SP_p[i]->SetMarkerColor(kRed);
			gr_v2pt_m_SP_p[i]->SetLineColor(kRed);
			gr_v2pt_m_SP_p[i]->SetMarkerSize(2);
			gr_v2pt_m_SP_p[i]->SetLineWidth(1);

			gr_v2pt_m_SP_Pb[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_SP_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_m_SP_Pb[i]->SetLineColor(kRed);
			gr_v2pt_m_SP_Pb[i]->SetMarkerSize(2);
			gr_v2pt_m_SP_Pb[i]->SetLineWidth(1);

			gr_v2pt_m_EPde_p[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_EPde_p[i]->SetMarkerColor(kBlue);
			gr_v2pt_m_EPde_p[i]->SetLineColor(kBlue);
			gr_v2pt_m_EPde_p[i]->SetMarkerSize(2);
			gr_v2pt_m_EPde_p[i]->SetLineWidth(1);

			gr_v2pt_m_EPde_Pb[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_EPde_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_m_EPde_Pb[i]->SetLineColor(kRed);
			gr_v2pt_m_EPde_Pb[i]->SetMarkerSize(2);
			gr_v2pt_m_EPde_Pb[i]->SetLineWidth(1);

			gr_v2pt_m_SPde_p[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_SPde_p[i]->SetMarkerColor(kBlue);
			gr_v2pt_m_SPde_p[i]->SetLineColor(kBlue);
			gr_v2pt_m_SPde_p[i]->SetMarkerSize(2);
			gr_v2pt_m_SPde_p[i]->SetLineWidth(1);

			gr_v2pt_m_SPde_Pb[i]->SetMarkerStyle(kFullSquare);
			gr_v2pt_m_SPde_Pb[i]->SetMarkerColor(kRed);
			gr_v2pt_m_SPde_Pb[i]->SetLineColor(kRed);
			gr_v2pt_m_SPde_Pb[i]->SetMarkerSize(2);
			gr_v2pt_m_SPde_Pb[i]->SetLineWidth(1);

			if ( !bCut ) {
				gr_v3p_EP[i]->SetMarkerStyle(kOpenSquare);
				gr_v3p_EP[i]->SetMarkerColor(kBlue);
				gr_v3p_EP[i]->SetLineColor(kBlue);
				gr_v3p_EP[i]->SetMarkerSize(2);

				gr_v3Pb_EP[i]->SetMarkerStyle(kOpenSquare);
				gr_v3Pb_EP[i]->SetMarkerColor(kRed);
				gr_v3Pb_EP[i]->SetLineColor(kRed);
				gr_v3Pb_EP[i]->SetMarkerSize(2);

				gr_v3p_EP_de[i]->SetMarkerStyle(kFullSquare);
				gr_v3p_EP_de[i]->SetMarkerColor(kBlue);
				gr_v3p_EP_de[i]->SetLineColor(kBlue);
				gr_v3p_EP_de[i]->SetMarkerSize(2);

				gr_v3Pb_EP_de[i]->SetMarkerStyle(kFullSquare);
				gr_v3Pb_EP_de[i]->SetMarkerColor(kRed);
				gr_v3Pb_EP_de[i]->SetLineColor(kRed);
				gr_v3Pb_EP_de[i]->SetMarkerSize(2);

				gr_v3p_SP[i]->SetMarkerStyle(kOpenSquare);
				gr_v3p_SP[i]->SetMarkerColor(kBlue);
				gr_v3p_SP[i]->SetLineColor(kBlue);
				gr_v3p_SP[i]->SetMarkerSize(2);

				gr_v3Pb_SP[i]->SetMarkerStyle(kOpenSquare);
				gr_v3Pb_SP[i]->SetMarkerColor(kRed);
				gr_v3Pb_SP[i]->SetLineColor(kRed);
				gr_v3Pb_SP[i]->SetMarkerSize(2);

				gr_v3p_SP_de[i]->SetMarkerStyle(kFullSquare);
				gr_v3p_SP_de[i]->SetMarkerColor(kBlue);
				gr_v3p_SP_de[i]->SetLineColor(kBlue);
				gr_v3p_SP_de[i]->SetMarkerSize(2);

				gr_v3Pb_SP_de[i]->SetMarkerStyle(kFullSquare);
				gr_v3Pb_SP_de[i]->SetMarkerColor(kRed);
				gr_v3Pb_SP_de[i]->SetLineColor(kRed);
				gr_v3Pb_SP_de[i]->SetMarkerSize(2);
			}

			continue;
		}
		gr_v2pt_p_EP_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_p_EP_p[i]->SetMarkerColor(kRed);
		gr_v2pt_p_EP_p[i]->SetLineColor(kRed);
		gr_v2pt_p_EP_p[i]->SetMarkerSize(2);
		gr_v2pt_p_EP_p[i]->SetLineWidth(1);

		gr_v2pt_p_EP_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_p_EP_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_p_EP_Pb[i]->SetLineColor(kRed);
		gr_v2pt_p_EP_Pb[i]->SetMarkerSize(2);
		gr_v2pt_p_EP_Pb[i]->SetLineWidth(1);

		gr_v2pt_m_EP_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_EP_p[i]->SetMarkerColor(kRed);
		gr_v2pt_m_EP_p[i]->SetLineColor(kRed);
		gr_v2pt_m_EP_p[i]->SetMarkerSize(2);
		gr_v2pt_m_EP_p[i]->SetLineWidth(1);

		gr_v2pt_m_EP_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_EP_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_m_EP_Pb[i]->SetLineColor(kRed);
		gr_v2pt_m_EP_Pb[i]->SetMarkerSize(2);
		gr_v2pt_m_EP_Pb[i]->SetLineWidth(1);

		gr_v2pt_Pb_EP_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_Pb_EP_p[i]->SetMarkerColor(kBlue);
		gr_v2pt_Pb_EP_p[i]->SetLineColor(kBlue);
		gr_v2pt_Pb_EP_p[i]->SetMarkerSize(2);
		gr_v2pt_Pb_EP_p[i]->SetLineWidth(1);

		gr_v2pt_Pb_EP_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_Pb_EP_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_Pb_EP_Pb[i]->SetLineColor(kRed);
		gr_v2pt_Pb_EP_Pb[i]->SetMarkerSize(2);
		gr_v2pt_Pb_EP_Pb[i]->SetLineWidth(1);

///
		gr_v2pt_p_SP_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_p_SP_p[i]->SetMarkerColor(kRed);
		gr_v2pt_p_SP_p[i]->SetLineColor(kRed);
		gr_v2pt_p_SP_p[i]->SetMarkerSize(2);
		gr_v2pt_p_SP_p[i]->SetLineWidth(1);

		gr_v2pt_p_SP_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_p_SP_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_p_SP_Pb[i]->SetLineColor(kRed);
		gr_v2pt_p_SP_Pb[i]->SetMarkerSize(2);
		gr_v2pt_p_SP_Pb[i]->SetLineWidth(1);

		gr_v2pt_m_SP_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_SP_p[i]->SetMarkerColor(kRed);
		gr_v2pt_m_SP_p[i]->SetLineColor(kRed);
		gr_v2pt_m_SP_p[i]->SetMarkerSize(2);
		gr_v2pt_m_SP_p[i]->SetLineWidth(1);

		gr_v2pt_m_SP_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_SP_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_m_SP_Pb[i]->SetLineColor(kRed);
		gr_v2pt_m_SP_Pb[i]->SetMarkerSize(2);
		gr_v2pt_m_SP_Pb[i]->SetLineWidth(1);

		gr_v2pt_Pb_SP_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_Pb_SP_p[i]->SetMarkerColor(kBlue);
		gr_v2pt_Pb_SP_p[i]->SetLineColor(kBlue);
		gr_v2pt_Pb_SP_p[i]->SetMarkerSize(2);
		gr_v2pt_Pb_SP_p[i]->SetLineWidth(1);

		gr_v2pt_Pb_SP_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_Pb_SP_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_Pb_SP_Pb[i]->SetLineColor(kRed);
		gr_v2pt_Pb_SP_Pb[i]->SetMarkerSize(2);
		gr_v2pt_Pb_SP_Pb[i]->SetLineWidth(1);

///
		gr_v2pt_p_EPde_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_p_EPde_p[i]->SetMarkerColor(kRed);
		gr_v2pt_p_EPde_p[i]->SetLineColor(kRed);
		gr_v2pt_p_EPde_p[i]->SetMarkerSize(2);
		gr_v2pt_p_EPde_p[i]->SetLineWidth(1);

		gr_v2pt_p_EPde_Pb[i]->SetMarkerStyle(kOpenCircle);
		gr_v2pt_p_EPde_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_p_EPde_Pb[i]->SetLineColor(kRed);
		gr_v2pt_p_EPde_Pb[i]->SetMarkerSize(2);
		gr_v2pt_p_EPde_Pb[i]->SetLineWidth(1);

		gr_v2pt_m_EPde_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_EPde_p[i]->SetMarkerColor(kBlue);
		gr_v2pt_m_EPde_p[i]->SetLineColor(kBlue);
		gr_v2pt_m_EPde_p[i]->SetMarkerSize(2);
		gr_v2pt_m_EPde_p[i]->SetLineWidth(1);

		gr_v2pt_m_EPde_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_EPde_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_m_EPde_Pb[i]->SetLineColor(kRed);
		gr_v2pt_m_EPde_Pb[i]->SetMarkerSize(2);
		gr_v2pt_m_EPde_Pb[i]->SetLineWidth(1);

		gr_v2pt_Pb_EPde_p[i]->SetMarkerStyle(kOpenCircle);
		gr_v2pt_Pb_EPde_p[i]->SetMarkerColor(kBlue);
		gr_v2pt_Pb_EPde_p[i]->SetLineColor(kBlue);
		gr_v2pt_Pb_EPde_p[i]->SetMarkerSize(2);
		gr_v2pt_Pb_EPde_p[i]->SetLineWidth(1);

		gr_v2pt_Pb_EPde_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_Pb_EPde_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_Pb_EPde_Pb[i]->SetLineColor(kRed);
		gr_v2pt_Pb_EPde_Pb[i]->SetMarkerSize(2);
		gr_v2pt_Pb_EPde_Pb[i]->SetLineWidth(1);

///
		gr_v2pt_p_SPde_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_p_SPde_p[i]->SetMarkerColor(kRed);
		gr_v2pt_p_SPde_p[i]->SetLineColor(kRed);
		gr_v2pt_p_SPde_p[i]->SetMarkerSize(2);
		gr_v2pt_p_SPde_p[i]->SetLineWidth(1);

		gr_v2pt_p_SPde_Pb[i]->SetMarkerStyle(kOpenCircle);
		gr_v2pt_p_SPde_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_p_SPde_Pb[i]->SetLineColor(kRed);
		gr_v2pt_p_SPde_Pb[i]->SetMarkerSize(2);
		gr_v2pt_p_SPde_Pb[i]->SetLineWidth(1);

		gr_v2pt_m_SPde_p[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_SPde_p[i]->SetMarkerColor(kBlue);
		gr_v2pt_m_SPde_p[i]->SetLineColor(kBlue);
		gr_v2pt_m_SPde_p[i]->SetMarkerSize(2);
		gr_v2pt_m_SPde_p[i]->SetLineWidth(1);

		gr_v2pt_m_SPde_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_m_SPde_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_m_SPde_Pb[i]->SetLineColor(kRed);
		gr_v2pt_m_SPde_Pb[i]->SetMarkerSize(2);
		gr_v2pt_m_SPde_Pb[i]->SetLineWidth(1);

		gr_v2pt_Pb_SPde_p[i]->SetMarkerStyle(kOpenCircle);
		gr_v2pt_Pb_SPde_p[i]->SetMarkerColor(kBlue);
		gr_v2pt_Pb_SPde_p[i]->SetLineColor(kBlue);
		gr_v2pt_Pb_SPde_p[i]->SetMarkerSize(2);
		gr_v2pt_Pb_SPde_p[i]->SetLineWidth(1);

		gr_v2pt_Pb_SPde_Pb[i]->SetMarkerStyle(kFullSquare);
		gr_v2pt_Pb_SPde_Pb[i]->SetMarkerColor(kRed);
		gr_v2pt_Pb_SPde_Pb[i]->SetLineColor(kRed);
		gr_v2pt_Pb_SPde_Pb[i]->SetMarkerSize(2);
		gr_v2pt_Pb_SPde_Pb[i]->SetLineWidth(1);

		if ( !bCut ) {
			gr_v3p_EP[i]->SetMarkerStyle(kOpenSquare);
			gr_v3p_EP[i]->SetMarkerColor(kBlue);
			gr_v3p_EP[i]->SetLineColor(kBlue);
			gr_v3p_EP[i]->SetMarkerSize(2);

			gr_v3Pb_EP[i]->SetMarkerStyle(kOpenSquare);
			gr_v3Pb_EP[i]->SetMarkerColor(kRed);
			gr_v3Pb_EP[i]->SetLineColor(kRed);
			gr_v3Pb_EP[i]->SetMarkerSize(2);

			gr_v3p_EP_de[i]->SetMarkerStyle(kFullSquare);
			gr_v3p_EP_de[i]->SetMarkerColor(kBlue);
			gr_v3p_EP_de[i]->SetLineColor(kBlue);
			gr_v3p_EP_de[i]->SetMarkerSize(2);

			gr_v3Pb_EP_de[i]->SetMarkerStyle(kFullSquare);
			gr_v3Pb_EP_de[i]->SetMarkerColor(kRed);
			gr_v3Pb_EP_de[i]->SetLineColor(kRed);
			gr_v3Pb_EP_de[i]->SetMarkerSize(2);

			gr_v3p_SP[i]->SetMarkerStyle(kOpenSquare);
			gr_v3p_SP[i]->SetMarkerColor(kBlue);
			gr_v3p_SP[i]->SetLineColor(kBlue);
			gr_v3p_SP[i]->SetMarkerSize(2);

			gr_v3Pb_SP[i]->SetMarkerStyle(kOpenSquare);
			gr_v3Pb_SP[i]->SetMarkerColor(kRed);
			gr_v3Pb_SP[i]->SetLineColor(kRed);
			gr_v3Pb_SP[i]->SetMarkerSize(2);

			gr_v3p_SP_de[i]->SetMarkerStyle(kFullSquare);
			gr_v3p_SP_de[i]->SetMarkerColor(kBlue);
			gr_v3p_SP_de[i]->SetLineColor(kBlue);
			gr_v3p_SP_de[i]->SetMarkerSize(2);

			gr_v3Pb_SP_de[i]->SetMarkerStyle(kFullSquare);
			gr_v3Pb_SP_de[i]->SetMarkerColor(kRed);
			gr_v3Pb_SP_de[i]->SetLineColor(kRed);
			gr_v3Pb_SP_de[i]->SetMarkerSize(2);
		}

	}

	for ( int i = 0 ; i < 20; i++ ) {

		if ( gr_v2pt_p_EP_p[i] ) {
			TString s = gr_v2pt_p_EP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_EP_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_p_EP_Pb[i] ) {
			TString s = gr_v2pt_p_EP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_EP_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_EP_p[i] ) {
			TString s = gr_v2pt_m_EP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_EP_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_EP_Pb[i] ) {
			TString s = gr_v2pt_m_EP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_EP_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_EP_p[i] ) {
			TString s = gr_v2pt_Pb_EP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_EP_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_EP_Pb[i] ) {
			TString s = gr_v2pt_Pb_EP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_EP_Pb[i]->SetName((char*)s);
		}

		if ( gr_v2pt_p_SP_p[i] ) {
			TString s = gr_v2pt_p_SP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_SP_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_p_SP_Pb[i] ) {
			TString s = gr_v2pt_p_SP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_SP_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_SP_p[i] ) {
			TString s = gr_v2pt_m_SP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_SP_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_SP_Pb[i] ) {
			TString s = gr_v2pt_m_SP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_SP_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_SP_p[i] ) {
			TString s = gr_v2pt_Pb_SP_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_SP_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_SP_Pb[i] ) {
			TString s = gr_v2pt_Pb_SP_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_SP_Pb[i]->SetName((char*)s);
		}

		if ( gr_v2pt_p_EPde_p[i] ) {
			TString s = gr_v2pt_p_EPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_EPde_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_p_EPde_Pb[i] ) {
			TString s = gr_v2pt_p_EPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_EPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_EPde_p[i] ) {
			TString s = gr_v2pt_m_EPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_EPde_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_EPde_Pb[i] ) {
			TString s = gr_v2pt_m_EPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_EPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_EPde_p[i] ) {
			TString s = gr_v2pt_Pb_EPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_EPde_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_EPde_Pb[i] ) {
			TString s = gr_v2pt_Pb_EPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_EPde_Pb[i]->SetName((char*)s);
		}

		if ( gr_v2pt_p_SPde_p[i] ) {
			TString s = gr_v2pt_p_SPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_SPde_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_p_SPde_Pb[i] ) {
			TString s = gr_v2pt_p_SPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_p_SPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_SPde_p[i] ) {
			TString s = gr_v2pt_m_SPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_SPde_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_m_SPde_Pb[i] ) {
			TString s = gr_v2pt_m_SPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_m_SPde_Pb[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_SPde_p[i] ) {
			TString s = gr_v2pt_Pb_SPde_p[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_SPde_p[i]->SetName((char*)s);
		}
		if ( gr_v2pt_Pb_SPde_Pb[i] ) {
			TString s = gr_v2pt_Pb_SPde_Pb[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2pt_Pb_SPde_Pb[i]->SetName((char*)s);
		}

		if ( gr_v2p_EP[i] ) {
			TString s = gr_v2p_EP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2p_EP[i]->SetName((char*)s);
		}
		if ( gr_v2p_SP[i] ) {
			TString s = gr_v2p_SP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2p_SP[i]->SetName((char*)s);
		}
		if ( gr_v2p_EP_de[i] ) {
			TString s = gr_v2p_EP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2p_EP_de[i]->SetName((char*)s);
		}
		if ( gr_v2p_SP_de[i] ) {
			TString s = gr_v2p_SP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2p_SP_de[i]->SetName((char*)s);
		}

		if ( gr_v2Pb_EP[i] ) {
			TString s = gr_v2Pb_EP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2Pb_EP[i]->SetName((char*)s);
		}
		if ( gr_v2Pb_SP[i] ) {
			TString s = gr_v2Pb_SP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2Pb_SP[i]->SetName((char*)s);
		}
		if ( gr_v2Pb_EP_de[i] ) {
			TString s = gr_v2Pb_EP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2Pb_EP_de[i]->SetName((char*)s);
		}
		if ( gr_v2Pb_SP_de[i] ) {
			TString s = gr_v2Pb_SP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v2Pb_SP_de[i]->SetName((char*)s);
		}

		if ( gr_v3p_EP[i] ) {
			TString s = gr_v3p_EP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3p_EP[i]->SetName((char*)s);
		}
		if ( gr_v3p_SP[i] ) {
			TString s = gr_v3p_SP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3p_SP[i]->SetName((char*)s);
		}
		if ( gr_v3p_EP_de[i] ) {
			TString s = gr_v3p_EP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3p_EP_de[i]->SetName((char*)s);
		}
		if ( gr_v3p_SP_de[i] ) {
			TString s = gr_v3p_SP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3p_SP_de[i]->SetName((char*)s);
		}

		if ( gr_v3Pb_EP[i] ) {
			TString s = gr_v3Pb_EP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3Pb_EP[i]->SetName((char*)s);
		}
		if ( gr_v3Pb_SP[i] ) {
			TString s = gr_v3Pb_SP[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3Pb_SP[i]->SetName((char*)s);
		}
		if ( gr_v3Pb_EP_de[i] ) {
			TString s = gr_v3Pb_EP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3Pb_EP_de[i]->SetName((char*)s);
		}
		if ( gr_v3Pb_SP_de[i] ) {
			TString s = gr_v3Pb_SP_de[i]->GetName();
			s.ReplaceAll("-","_");
			s.ReplaceAll(".","0");
			gr_v3Pb_SP_de[i]->SetName((char*)s);
		}
	}

}


