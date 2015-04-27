%function [status] = sys(orig, syst)
%==========================
 orig = 'pPb_HLT_rfp24_Noff_noacc_noeff_v15_cm1_full_reverse'
 syst = 'pPb_HLT_rfp24_Noff_noacc_eff_sysTight_full'

O = load(sprintf("txt/%s/Graph.txt", orig));
S = load(sprintf("txt/%s/Graph.txt", syst));

%Ov22pt_120 = O.gr_vnPtC_2_0_7;
%Ov22pt_150 = O.gr_vnPtC_2_0_6;
%Ov22pt_185 = O.gr_vnPtC_2_0_5;
%Ov22pt_220 = O.gr_vnPtC_2_0_4;
%Ov24pt_120 = O.gr_vnPtC_2_1_7;
%Ov24pt_150 = O.gr_vnPtC_2_1_6;
%Ov24pt_185 = O.gr_vnPtC_2_1_5;
%Ov24pt_220 = O.gr_vnPtC_2_1_4;
%Ov26pt_120 = O.gr_vnPtC_2_2_6;
%Ov26pt_150 = O.gr_vnPtC_2_2_5;
%Ov26pt_185 = O.gr_vnPtC_2_2_4;
%Ov26pt_220 = O.gr_vnPtC_2_2_3;
%Ov28pt_120 = O.gr_vnPtC_2_3_5;
%Ov28pt_150 = O.gr_vnPtC_2_3_4;
%Ov28pt_185 = O.gr_vnPtC_2_3_3;
%Ov28pt_220 = O.gr_vnPtC_2_3_2;
%
%Ov22eta_120 = O.gr_vnEtaC_2_0_7;
%Ov22eta_150 = O.gr_vnEtaC_2_0_6;
%Ov22eta_185 = O.gr_vnEtaC_2_0_5;
%Ov22eta_220 = O.gr_vnEtaC_2_0_4;
%Ov24eta_120 = O.gr_vnEtaC_2_1_7;
%Ov24eta_150 = O.gr_vnEtaC_2_1_6;
%Ov24eta_185 = O.gr_vnEtaC_2_1_5;
%Ov24eta_220 = O.gr_vnEtaC_2_1_4;
%Ov26eta_120 = O.gr_vnEtaC_2_2_6;
%Ov26eta_150 = O.gr_vnEtaC_2_2_5;
%Ov26eta_185 = O.gr_vnEtaC_2_2_4;
%Ov26eta_220 = O.gr_vnEtaC_2_2_3;
%Ov28eta_120 = O.gr_vnEtaC_2_3_5;
%Ov28eta_150 = O.gr_vnEtaC_2_3_4;
%Ov28eta_185 = O.gr_vnEtaC_2_3_3;
%Ov28eta_220 = O.gr_vnEtaC_2_3_2;
%
%Sv22pt_120 = S.gr_vnPtC_2_0_7;
%Sv22pt_150 = S.gr_vnPtC_2_0_6;
%Sv22pt_185 = S.gr_vnPtC_2_0_5;
%Sv22pt_220 = S.gr_vnPtC_2_0_4;
%Sv24pt_120 = S.gr_vnPtC_2_1_7;
%Sv24pt_150 = S.gr_vnPtC_2_1_6;
%Sv24pt_185 = S.gr_vnPtC_2_1_5;
%Sv24pt_220 = S.gr_vnPtC_2_1_4;
%Sv26pt_120 = S.gr_vnPtC_2_2_6;
%Sv26pt_150 = S.gr_vnPtC_2_2_5;
%Sv26pt_185 = S.gr_vnPtC_2_2_4;
%Sv26pt_220 = S.gr_vnPtC_2_2_3;
%Sv28pt_120 = S.gr_vnPtC_2_3_5;
%Sv28pt_150 = S.gr_vnPtC_2_3_4;
%Sv28pt_185 = S.gr_vnPtC_2_3_3;
%Sv28pt_220 = S.gr_vnPtC_2_3_2;
%
%Sv22eta_120 = S.gr_vnEtaC_2_0_7;
%Sv22eta_150 = S.gr_vnEtaC_2_0_6;
%Sv22eta_185 = S.gr_vnEtaC_2_0_5;
%Sv22eta_220 = S.gr_vnEtaC_2_0_4;
%Sv24eta_120 = S.gr_vnEtaC_2_1_7;
%Sv24eta_150 = S.gr_vnEtaC_2_1_6;
%Sv24eta_185 = S.gr_vnEtaC_2_1_5;
%Sv24eta_220 = S.gr_vnEtaC_2_1_4;
%Sv26eta_120 = S.gr_vnEtaC_2_2_6;
%Sv26eta_150 = S.gr_vnEtaC_2_2_5;
%Sv26eta_185 = S.gr_vnEtaC_2_2_4;
%Sv26eta_220 = S.gr_vnEtaC_2_2_3;
%Sv28eta_120 = S.gr_vnEtaC_2_3_5;
%Sv28eta_150 = S.gr_vnEtaC_2_3_4;
%Sv28eta_185 = S.gr_vnEtaC_2_3_3;
%Sv28eta_220 = S.gr_vnEtaC_2_3_2;


Ov22pt_120 = syscal(O.gr_vnPtC_2_0_7, S.gr_vnPtC_2_0_7);
Ov22pt_150 = syscal(O.gr_vnPtC_2_0_6, S.gr_vnPtC_2_0_6);
Ov22pt_185 = syscal(O.gr_vnPtC_2_0_5, S.gr_vnPtC_2_0_5);
Ov22pt_220 = syscal(O.gr_vnPtC_2_0_4, S.gr_vnPtC_2_0_4);
Ov24pt_120 = syscal(O.gr_vnPtC_2_1_7, S.gr_vnPtC_2_1_7);
Ov24pt_150 = syscal(O.gr_vnPtC_2_1_6, S.gr_vnPtC_2_1_6);
Ov24pt_185 = syscal(O.gr_vnPtC_2_1_5, S.gr_vnPtC_2_1_5);
Ov24pt_220 = syscal(O.gr_vnPtC_2_1_4, S.gr_vnPtC_2_1_4);
Ov26pt_120 = syscal(O.gr_vnPtC_2_2_6, S.gr_vnPtC_2_2_6);
Ov26pt_150 = syscal(O.gr_vnPtC_2_2_5, S.gr_vnPtC_2_2_5);
Ov26pt_185 = syscal(O.gr_vnPtC_2_2_4, S.gr_vnPtC_2_2_4);
Ov26pt_220 = syscal(O.gr_vnPtC_2_2_3, S.gr_vnPtC_2_2_3);
Ov28pt_120 = syscal(O.gr_vnPtC_2_3_5, S.gr_vnPtC_2_3_5);
Ov28pt_150 = syscal(O.gr_vnPtC_2_3_4, S.gr_vnPtC_2_3_4);
Ov28pt_185 = syscal(O.gr_vnPtC_2_3_3, S.gr_vnPtC_2_3_3);
Ov28pt_220 = syscal(O.gr_vnPtC_2_3_2, S.gr_vnPtC_2_3_2);

Ov22eta_120 = syscal(O.gr_vnEtaC_2_0_7, S.gr_vnEtaC_2_0_7);
Ov22eta_150 = syscal(O.gr_vnEtaC_2_0_6, S.gr_vnEtaC_2_0_6);
Ov22eta_185 = syscal(O.gr_vnEtaC_2_0_5, S.gr_vnEtaC_2_0_5);
Ov22eta_220 = syscal(O.gr_vnEtaC_2_0_4, S.gr_vnEtaC_2_0_4);
Ov24eta_120 = syscal(O.gr_vnEtaC_2_1_7, S.gr_vnEtaC_2_1_7);
Ov24eta_150 = syscal(O.gr_vnEtaC_2_1_6, S.gr_vnEtaC_2_1_6);
Ov24eta_185 = syscal(O.gr_vnEtaC_2_1_5, S.gr_vnEtaC_2_1_5);
Ov24eta_220 = syscal(O.gr_vnEtaC_2_1_4, S.gr_vnEtaC_2_1_4);
Ov26eta_120 = syscal(O.gr_vnEtaC_2_2_6, S.gr_vnEtaC_2_2_6);
Ov26eta_150 = syscal(O.gr_vnEtaC_2_2_5, S.gr_vnEtaC_2_2_5);
Ov26eta_185 = syscal(O.gr_vnEtaC_2_2_4, S.gr_vnEtaC_2_2_4);
Ov26eta_220 = syscal(O.gr_vnEtaC_2_2_3, S.gr_vnEtaC_2_2_3);
Ov28eta_120 = syscal(O.gr_vnEtaC_2_3_5, S.gr_vnEtaC_2_3_5);
Ov28eta_150 = syscal(O.gr_vnEtaC_2_3_4, S.gr_vnEtaC_2_3_4);
Ov28eta_185 = syscal(O.gr_vnEtaC_2_3_3, S.gr_vnEtaC_2_3_3);
Ov28eta_220 = syscal(O.gr_vnEtaC_2_3_2, S.gr_vnEtaC_2_3_2);



%==========================
%end
