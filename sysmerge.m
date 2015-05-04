function sysmerge(S1, S2, name)

Ov22pt_120   = [ S1.Ov22pt_120 , S2.Ov22pt_120(:,4:6) ];
Ov22pt_150   = [ S1.Ov22pt_150 , S2.Ov22pt_150(:,4:6) ];
Ov22pt_185   = [ S1.Ov22pt_185 , S2.Ov22pt_185(:,4:6) ];
Ov22pt_220   = [ S1.Ov22pt_220 , S2.Ov22pt_220(:,4:6) ];
Ov24pt_120   = [ S1.Ov24pt_120 , S2.Ov24pt_120(:,4:6) ];
Ov24pt_150   = [ S1.Ov24pt_150 , S2.Ov24pt_150(:,4:6) ];
Ov24pt_185   = [ S1.Ov24pt_185 , S2.Ov24pt_185(:,4:6) ];
Ov24pt_220   = [ S1.Ov24pt_220 , S2.Ov24pt_220(:,4:6) ];
Ov26pt_120   = [ S1.Ov26pt_120 , S2.Ov26pt_120(:,4:6) ];
Ov26pt_150   = [ S1.Ov26pt_150 , S2.Ov26pt_150(:,4:6) ];
Ov26pt_185   = [ S1.Ov26pt_185 , S2.Ov26pt_185(:,4:6) ];
Ov26pt_220   = [ S1.Ov26pt_220 , S2.Ov26pt_220(:,4:6) ];
Ov28pt_120   = [ S1.Ov28pt_120 , S2.Ov28pt_120(:,4:6) ];
Ov28pt_150   = [ S1.Ov28pt_150 , S2.Ov28pt_150(:,4:6) ];
Ov28pt_185   = [ S1.Ov28pt_185 , S2.Ov28pt_185(:,4:6) ];
Ov28pt_220   = [ S1.Ov28pt_220 , S2.Ov28pt_220(:,4:6) ];

Ov22eta_120  = [ S1.Ov22eta_120, S2.Ov22eta_120(:,4:6) ];
Ov22eta_150  = [ S1.Ov22eta_150, S2.Ov22eta_150(:,4:6) ];
Ov22eta_185  = [ S1.Ov22eta_185, S2.Ov22eta_185(:,4:6) ];
Ov22eta_220  = [ S1.Ov22eta_220, S2.Ov22eta_220(:,4:6) ];
Ov24eta_120  = [ S1.Ov24eta_120, S2.Ov24eta_120(:,4:6) ];
Ov24eta_150  = [ S1.Ov24eta_150, S2.Ov24eta_150(:,4:6) ];
Ov24eta_185  = [ S1.Ov24eta_185, S2.Ov24eta_185(:,4:6) ];
Ov24eta_220  = [ S1.Ov24eta_220, S2.Ov24eta_220(:,4:6) ];
Ov26eta_120  = [ S1.Ov26eta_120, S2.Ov26eta_120(:,4:6) ];
Ov26eta_150  = [ S1.Ov26eta_150, S2.Ov26eta_150(:,4:6) ];
Ov26eta_185  = [ S1.Ov26eta_185, S2.Ov26eta_185(:,4:6) ];
Ov26eta_220  = [ S1.Ov26eta_220, S2.Ov26eta_220(:,4:6) ];
Ov28eta_120  = [ S1.Ov28eta_120, S2.Ov28eta_120(:,4:6) ];
Ov28eta_150  = [ S1.Ov28eta_150, S2.Ov28eta_150(:,4:6) ];
Ov28eta_185  = [ S1.Ov28eta_185, S2.Ov28eta_185(:,4:6) ];
Ov28eta_220  = [ S1.Ov28eta_220, S2.Ov28eta_220(:,4:6) ];

save("-binary", name, "Ov*");
end
