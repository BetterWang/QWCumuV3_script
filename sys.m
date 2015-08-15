orig = 'PbPb_ppreco_rfp24_Noff_noacc_eff'
syst = 'PbPb_HLT_rfp24_Noff_noacc_eff_sysPU'
fsave = 'PbPbPU.mat'
sysmacro

orig = 'pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18_full'
syst = 'pPb_HLT_rfp24_Noff_noacc_eff_sysPU_full'
fsave = 'pPbPU.mat'
sysmacro

orig = 'pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18_full'
syst = 'pPb_HLT_rfp24_Noff_noacc_eff_sysEff_full'
fsave = 'pPbEff.mat'
sysmacro

orig = 'pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18_full'
syst = 'pPb_HLT_rfp24_Noff_noacc_eff_sysVtx1_full'
fsave = 'pPbVtx1.mat'
sysmacro

orig = 'pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18_full'
syst = 'pPb_HLT_rfp24_Noff_noacc_eff_sysVtx0_full'
fsave = 'pPbVtx0.mat'
sysmacro

orig = 'pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18_full'
syst = 'pPb_HLT_rfp24_Noff_noacc_eff_sysLoose_full'
fsave = 'pPbLoose.mat'
sysmacro

orig = 'pPb_HLT_rfp24_Noff_noacc_eff_cm1_v18_full'
syst = 'pPb_HLT_rfp24_Noff_noacc_eff_sysTight_full'
fsave = 'pPbTight.mat'
sysmacro

orig = 'PbPb_ppreco_rfp24_Noff_noacc_eff'
syst = 'PbPb_HLT_rfp24_Noff_noacc_eff_sysEff'
fsave = 'PbPbEff.mat'
sysmacro

orig = 'PbPb_ppreco_rfp24_Noff_noacc_eff'
syst = 'PbPb_HLT_rfp24_Noff_noacc_eff_sysVtx1'
fsave = 'PbPbVtx1.mat'
sysmacro

orig = 'PbPb_ppreco_rfp24_Noff_noacc_eff'
syst = 'PbPb_HLT_rfp24_Noff_noacc_eff_sysVtx0'
fsave = 'PbPbVtx0.mat'
sysmacro

orig = 'PbPb_ppreco_rfp24_Noff_noacc_eff'
syst = 'PbPb_HLT_rfp24_Noff_noacc_eff_sysLoose'
fsave = 'PbPbLoose.mat'
sysmacro

orig = 'PbPb_ppreco_rfp24_Noff_noacc_eff'
syst = 'PbPb_HLT_rfp24_Noff_noacc_eff_sysTight'
fsave = 'PbPbTight.mat'
sysmacro

S1 = load("pPbVtx0.mat");
S2 = load("pPbVtx1.mat");
sysmerge(S1, S2, "pPbVtx.mat");

S1 = load("PbPbVtx0.mat");
S2 = load("PbPbVtx1.mat");
sysmerge(S1, S2, "PbPbVtx.mat");

S1 = load("pPbTight.mat");
S2 = load("pPbLoose.mat");
sysmerge(S1, S2, "pPbTrk.mat");

S1 = load("PbPbTight.mat");
S2 = load("PbPbLoose.mat");
sysmerge(S1, S2, "PbPbTrk.mat");

fname = "PbPbPU"
sys2tex

fname = "pPbPU"
sys2tex

fname = "pPbVtx"
sys2tex

fname = "PbPbVtx"
sys2tex

fname = "pPbTrk"
sys2tex

fname = "PbPbTrk"
sys2tex

fname = "pPbEff"
sys2tex

fname = "PbPbEff"
sys2tex
