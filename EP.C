
{
	TFile * fv2_ep = new TFile("txt/EP/Save_v2_0_EP.root");
	TFile * fv2_sp = new TFile("txt/EP/Save_v2_1_SP.root");
	TFile * fv2_ep_de = new TFile("txt/EP/Save_v2_2_EP.root");
	TFile * fv2_sp_de = new TFile("txt/EP/Save_v2_3_SP.root");

	TFile * fv3_ep = new TFile("txt/EP/Save_v3_0_EP.root");
	TFile * fv3_sp = new TFile("txt/EP/Save_v3_1_SP.root");
	TFile * fv3_ep_de = new TFile("txt/EP/Save_v3_2_EP.root");
	TFile * fv3_sp_de = new TFile("txt/EP/Save_v3_3_SP.root");



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

	gr_v2p_EP[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_p");
	gr_v2p_EP[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_p");
	gr_v2p_EP[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_p");
	gr_v2p_EP[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_p");

	gr_v2Pb_EP[6] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM130_Pb");
	gr_v2Pb_EP[5] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM160_Pb");
	gr_v2Pb_EP[4] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM190_Pb");
	gr_v2Pb_EP[3] = (TGraphErrors*) fv2_ep->Get("v2_0_pPb_HM220_Pb");

	gr_v2p_SP[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_p");
	gr_v2p_SP[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_p");
	gr_v2p_SP[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_p");
	gr_v2p_SP[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_p");

	gr_v2Pb_SP[6] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM130_Pb");
	gr_v2Pb_SP[5] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM160_Pb");
	gr_v2Pb_SP[4] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM190_Pb");
	gr_v2Pb_SP[3] = (TGraphErrors*) fv2_sp->Get("v2_1_pPb_HM220_Pb");

	gr_v2p_EP_de[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_p");
	gr_v2p_EP_de[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_p");
	gr_v2p_EP_de[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_p");
	gr_v2p_EP_de[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_p");

	gr_v2Pb_EP_de[6] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM130_Pb");
	gr_v2Pb_EP_de[5] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM160_Pb");
	gr_v2Pb_EP_de[4] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM190_Pb");
	gr_v2Pb_EP_de[3] = (TGraphErrors*) fv2_ep_de->Get("v2_2_pPb_HM220_Pb");

	gr_v2p_SP_de[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_p");
	gr_v2p_SP_de[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_p");
	gr_v2p_SP_de[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_p");
	gr_v2p_SP_de[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_p");

	gr_v2Pb_SP_de[6] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM130_Pb");
	gr_v2Pb_SP_de[5] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM160_Pb");
	gr_v2Pb_SP_de[4] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM190_Pb");
	gr_v2Pb_SP_de[3] = (TGraphErrors*) fv2_sp_de->Get("v2_3_pPb_HM220_Pb");


	gr_v3p_EP[6] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM130_p");
	gr_v3p_EP[5] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM160_p");
	gr_v3p_EP[4] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM190_p");
	gr_v3p_EP[3] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM220_p");

	gr_v3Pb_EP[6] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM130_Pb");
	gr_v3Pb_EP[5] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM160_Pb");
	gr_v3Pb_EP[4] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM190_Pb");
	gr_v3Pb_EP[3] = (TGraphErrors*) fv3_ep->Get("v3_0_pPb_HM220_Pb");

	gr_v3p_SP[6] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM130_p");
	gr_v3p_SP[5] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM160_p");
	gr_v3p_SP[4] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM190_p");
	gr_v3p_SP[3] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM220_p");

	gr_v3Pb_SP[6] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM130_Pb");
	gr_v3Pb_SP[5] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM160_Pb");
	gr_v3Pb_SP[4] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM190_Pb");
	gr_v3Pb_SP[3] = (TGraphErrors*) fv3_sp->Get("v3_1_pPb_HM220_Pb");

	gr_v3p_EP_de[6] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM130_p");
	gr_v3p_EP_de[5] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM160_p");
	gr_v3p_EP_de[4] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM190_p");
	gr_v3p_EP_de[3] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM220_p");

	gr_v3Pb_EP_de[6] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM130_Pb");
	gr_v3Pb_EP_de[5] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM160_Pb");
	gr_v3Pb_EP_de[4] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM190_Pb");
	gr_v3Pb_EP_de[3] = (TGraphErrors*) fv3_ep_de->Get("v3_2_pPb_HM220_Pb");

	gr_v3p_SP_de[6] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM130_p");
	gr_v3p_SP_de[5] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM160_p");
	gr_v3p_SP_de[4] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM190_p");
	gr_v3p_SP_de[3] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM220_p");

	gr_v3Pb_SP_de[6] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM130_Pb");
	gr_v3Pb_SP_de[5] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM160_Pb");
	gr_v3Pb_SP_de[4] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM190_Pb");
	gr_v3Pb_SP_de[3] = (TGraphErrors*) fv3_sp_de->Get("v3_3_pPb_HM220_Pb");


}
