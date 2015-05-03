%function [status] = sys(orig, syst)
%==========================


O = load(sprintf("txt/%s/Graph.txt", orig));
S = load(sprintf("txt/%s/Graph.txt", syst));


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

save("-binary", fsave, "Ov*");
%==========================
%end

