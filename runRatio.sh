#root -l -b -q "genPlot.C(99)"
root -l -b -q "genPlot.C(62)"
#root -l -b -q "genPlot.C(68)"
#root -l -b -q "genPlot.C(86)"
#root -l -b -q "mergeTrig.C(68, 63)" # eff
#root -l -b -q "mergeTrig.C(86, 81)" # loose

#root -l -b -q "genPlot.C(80)"
#root -l -b -q "genPlot.C(74)"
#root -l -b -q "mergeTrig.C(80, 75)" # tight
#root -l -b -q "mergeTrig.C(74, 69)" # calo

#root -l -b -q "genPlot.C(92)"
#root -l -b -q "genPlot.C(98)"
#
root -l -b -q "genPlot.C(57, 1)"
root -l -b -q "genPlot.C(57, 2)"
root -l -b -q "genPlot.C(57, 3)"
root -l -b -q "genPlot.C(57, 4)"
root -l -b -q "mergeTrig.C(62, 57)" # default
#
#root -l -b -q "genPlot.C(63, 1)"
#root -l -b -q "genPlot.C(63, 2)"
#root -l -b -q "genPlot.C(63, 3)"
#root -l -b -q "genPlot.C(63, 4)"
#
#root -l -b -q "genPlot.C(69, 1)"
#root -l -b -q "genPlot.C(69, 2)"
#root -l -b -q "genPlot.C(69, 3)"
#root -l -b -q "genPlot.C(69, 4)"
#
#root -l -b -q "genPlot.C(75, 1)"
#root -l -b -q "genPlot.C(75, 2)"
#root -l -b -q "genPlot.C(75, 3)"
#root -l -b -q "genPlot.C(75, 4)"
#
#root -l -b -q "genPlot.C(81, 1)"
#root -l -b -q "genPlot.C(81, 2)"
#root -l -b -q "genPlot.C(81, 3)"
#root -l -b -q "genPlot.C(81, 4)"
#
#root -l -b -q "genPlot.C(87, 1)"
#root -l -b -q "genPlot.C(87, 2)"
#root -l -b -q "genPlot.C(87, 3)"
#root -l -b -q "genPlot.C(87, 4)"
#
#root -l -b -q "genPlot.C(93, 1)"
#root -l -b -q "genPlot.C(93, 2)"
#root -l -b -q "genPlot.C(93, 3)"
#root -l -b -q "genPlot.C(93, 4)"

#root -l -b -q "mergeTrig.C(92, 87)" # Vz0
#root -l -b -q "mergeTrig.C(98, 93)" # Vz1

#root -l -b -q "genPlot.C(18)"
#root -l -b -q "genPlot.C(24)"
#root -l -b -q "genPlot.C(30)"
#root -l -b -q "genPlot.C(36)"
#root -l -b -q "genPlot.C(42)"
#root -l -b -q "genPlot.C(48)"
#root -l -b -q "genPlot.C(54)"

#root -l -b -q "genPlot.C(13, 1)"
#root -l -b -q "genPlot.C(13, 2)"
#root -l -b -q "genPlot.C(13, 3)"
#root -l -b -q "genPlot.C(13, 4)"
#root -l -b -q "genPlot.C(19, 1)"
#root -l -b -q "genPlot.C(19, 2)"
#root -l -b -q "genPlot.C(19, 3)"
#root -l -b -q "genPlot.C(19, 4)"
#root -l -b -q "genPlot.C(25, 1)"
#root -l -b -q "genPlot.C(25, 2)"
#root -l -b -q "genPlot.C(25, 3)"
#root -l -b -q "genPlot.C(25, 4)"
#root -l -b -q "genPlot.C(31, 1)"
#root -l -b -q "genPlot.C(31, 2)"
#root -l -b -q "genPlot.C(31, 3)"
#root -l -b -q "genPlot.C(31, 4)"
#root -l -b -q "genPlot.C(37, 1)"
#root -l -b -q "genPlot.C(37, 2)"
#root -l -b -q "genPlot.C(37, 3)"
#root -l -b -q "genPlot.C(37, 4)"
#root -l -b -q "genPlot.C(43, 1)"
#root -l -b -q "genPlot.C(43, 2)"
#root -l -b -q "genPlot.C(43, 3)"
#root -l -b -q "genPlot.C(43, 4)"
#root -l -b -q "genPlot.C(49, 1)"
#root -l -b -q "genPlot.C(49, 2)"
#root -l -b -q "genPlot.C(49, 3)"
#root -l -b -q "genPlot.C(49, 4)"
#root -l -b -q "genPlot.C(56, 1)"
#root -l -b -q "genPlot.C(56, 2)"
#root -l -b -q "genPlot.C(56, 3)"
#root -l -b -q "genPlot.C(56, 4)"

#root -l -b -q "mergeTrig.C(18, 13)"
#root -l -b -q "mergeTrig.C(30, 25)"
#root -l -b -q "mergeTrig.C(36, 31)"
#root -l -b -q "mergeTrig.C(42, 37)"
#root -l -b -q "mergeTrig.C(48, 43)"
#root -l -b -q "mergeTrig.C(54, 49)"
#root -l -b -q "mergeTrig.C(24, 56)"
#root -l -b -q "mergeTrig.C(24, 19)"
###### eff
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V24_0", "v_{2}{4} with eff", "v_{2}{4} 0 - 5 %"   )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V24_1", "v_{2}{4} with eff", "v_{2}{4} 5 - 10 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V24_2", "v_{2}{4} with eff", "v_{2}{4} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V24_3", "v_{2}{4} with eff", "v_{2}{4} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V24_4", "v_{2}{4} with eff", "v_{2}{4} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V24_5", "v_{2}{4} with eff", "v_{2}{4} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V24_6", "v_{2}{4} with eff", "v_{2}{4} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V26_0", "v_{2}{6} with eff", "v_{2}{6} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V26_1", "v_{2}{6} with eff", "v_{2}{6} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V26_2", "v_{2}{6} with eff", "v_{2}{6} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V26_3", "v_{2}{6} with eff", "v_{2}{6} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V26_4", "v_{2}{6} with eff", "v_{2}{6} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V26_5", "v_{2}{6} with eff", "v_{2}{6} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V26_6", "v_{2}{6} with eff", "v_{2}{6} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V28_0", "v_{2}{8} with eff", "v_{2}{8} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V28_1", "v_{2}{8} with eff", "v_{2}{8} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V28_2", "v_{2}{8} with eff", "v_{2}{8} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V28_3", "v_{2}{8} with eff", "v_{2}{8} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V28_4", "v_{2}{8} with eff", "v_{2}{8} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V28_5", "v_{2}{8} with eff", "v_{2}{8} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_68_63.root", "fresult2_62_57.root", "gr_V28_6", "v_{2}{8} with eff", "v_{2}{8} 50 - 60 %"  )' -b -q
#
#######  calo
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V24_0", "v_{2}{4} without caloMatch", "v_{2}{4} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V24_1", "v_{2}{4} without caloMatch", "v_{2}{4} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V24_2", "v_{2}{4} without caloMatch", "v_{2}{4} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V24_3", "v_{2}{4} without caloMatch", "v_{2}{4} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V24_4", "v_{2}{4} without caloMatch", "v_{2}{4} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V24_5", "v_{2}{4} without caloMatch", "v_{2}{4} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V24_6", "v_{2}{4} without caloMatch", "v_{2}{4} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V26_0", "v_{2}{6} without caloMatch", "v_{2}{6} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V26_1", "v_{2}{6} without caloMatch", "v_{2}{6} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V26_2", "v_{2}{6} without caloMatch", "v_{2}{6} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V26_3", "v_{2}{6} without caloMatch", "v_{2}{6} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V26_4", "v_{2}{6} without caloMatch", "v_{2}{6} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V26_5", "v_{2}{6} without caloMatch", "v_{2}{6} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V26_6", "v_{2}{6} without caloMatch", "v_{2}{6} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V28_0", "v_{2}{8} without caloMatch", "v_{2}{8} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V28_1", "v_{2}{8} without caloMatch", "v_{2}{8} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V28_2", "v_{2}{8} without caloMatch", "v_{2}{8} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V28_3", "v_{2}{8} without caloMatch", "v_{2}{8} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V28_4", "v_{2}{8} without caloMatch", "v_{2}{8} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V28_5", "v_{2}{8} without caloMatch", "v_{2}{8} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_74_69.root", "fresult2_62_57.root", "gr_V28_6", "v_{2}{8} without caloMatch", "v_{2}{8} 50 - 60 %"  )' -b -q
#
####### Tight
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V24_0", "v_{2}{4} tight", "v_{2}{4} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V24_1", "v_{2}{4} tight", "v_{2}{4} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V24_2", "v_{2}{4} tight", "v_{2}{4} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V24_3", "v_{2}{4} tight", "v_{2}{4} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V24_4", "v_{2}{4} tight", "v_{2}{4} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V24_5", "v_{2}{4} tight", "v_{2}{4} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V24_6", "v_{2}{4} tight", "v_{2}{4} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V26_0", "v_{2}{6} tight", "v_{2}{6} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V26_1", "v_{2}{6} tight", "v_{2}{6} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V26_2", "v_{2}{6} tight", "v_{2}{6} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V26_3", "v_{2}{6} tight", "v_{2}{6} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V26_4", "v_{2}{6} tight", "v_{2}{6} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V26_5", "v_{2}{6} tight", "v_{2}{6} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V26_6", "v_{2}{6} tight", "v_{2}{6} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V28_0", "v_{2}{8} tight", "v_{2}{8} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V28_1", "v_{2}{8} tight", "v_{2}{8} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V28_2", "v_{2}{8} tight", "v_{2}{8} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V28_3", "v_{2}{8} tight", "v_{2}{8} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V28_4", "v_{2}{8} tight", "v_{2}{8} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V28_5", "v_{2}{8} tight", "v_{2}{8} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_80_75.root", "fresult2_62_57.root", "gr_V28_6", "v_{2}{8} tight", "v_{2}{8} 50 - 60 %"  )' -b -q
#
####### Loose
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V24_0", "v_{2}{4} loose", "v_{2}{4} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V24_1", "v_{2}{4} loose", "v_{2}{4} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V24_2", "v_{2}{4} loose", "v_{2}{4} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V24_3", "v_{2}{4} loose", "v_{2}{4} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V24_4", "v_{2}{4} loose", "v_{2}{4} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V24_5", "v_{2}{4} loose", "v_{2}{4} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V24_6", "v_{2}{4} loose", "v_{2}{4} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V26_0", "v_{2}{6} loose", "v_{2}{6} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V26_1", "v_{2}{6} loose", "v_{2}{6} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V26_2", "v_{2}{6} loose", "v_{2}{6} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V26_3", "v_{2}{6} loose", "v_{2}{6} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V26_4", "v_{2}{6} loose", "v_{2}{6} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V26_5", "v_{2}{6} loose", "v_{2}{6} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V26_6", "v_{2}{6} loose", "v_{2}{6} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V28_0", "v_{2}{8} loose", "v_{2}{8} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V28_1", "v_{2}{8} loose", "v_{2}{8} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V28_2", "v_{2}{8} loose", "v_{2}{8} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V28_3", "v_{2}{8} loose", "v_{2}{8} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V28_4", "v_{2}{8} loose", "v_{2}{8} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V28_5", "v_{2}{8} loose", "v_{2}{8} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_86_81.root", "fresult2_62_57.root", "gr_V28_6", "v_{2}{8} loose", "v_{2}{8} 50 - 60 %"  )' -b -q
#
####### Vz0
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V24_0", "v_{2}{4} |vz| < 3", "v_{2}{4} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V24_1", "v_{2}{4} |vz| < 3", "v_{2}{4} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V24_2", "v_{2}{4} |vz| < 3", "v_{2}{4} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V24_3", "v_{2}{4} |vz| < 3", "v_{2}{4} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V24_4", "v_{2}{4} |vz| < 3", "v_{2}{4} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V24_5", "v_{2}{4} |vz| < 3", "v_{2}{4} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V24_6", "v_{2}{4} |vz| < 3", "v_{2}{4} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V26_0", "v_{2}{6} |vz| < 3", "v_{2}{6} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V26_1", "v_{2}{6} |vz| < 3", "v_{2}{6} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V26_2", "v_{2}{6} |vz| < 3", "v_{2}{6} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V26_3", "v_{2}{6} |vz| < 3", "v_{2}{6} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V26_4", "v_{2}{6} |vz| < 3", "v_{2}{6} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V26_5", "v_{2}{6} |vz| < 3", "v_{2}{6} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V26_6", "v_{2}{6} |vz| < 3", "v_{2}{6} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V28_0", "v_{2}{8} |vz| < 3", "v_{2}{8} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V28_1", "v_{2}{8} |vz| < 3", "v_{2}{8} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V28_2", "v_{2}{8} |vz| < 3", "v_{2}{8} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V28_3", "v_{2}{8} |vz| < 3", "v_{2}{8} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V28_4", "v_{2}{8} |vz| < 3", "v_{2}{8} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V28_5", "v_{2}{8} |vz| < 3", "v_{2}{8} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_92_87.root", "fresult2_62_57.root", "gr_V28_6", "v_{2}{8} |vz| < 3", "v_{2}{8} 50 - 60 %"  )' -b -q
#
####### Vz1
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V24_0", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V24_1", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V24_2", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V24_3", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V24_4", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V24_5", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V24_6", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V26_0", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V26_1", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V26_2", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V26_3", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V26_4", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V26_5", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V26_6", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V28_0", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V28_1", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V28_2", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V28_3", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V28_4", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V28_5", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_98_93.root", "fresult2_62_57.root", "gr_V28_6", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 50 - 60 %"  )' -b -q

###### HLT
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V24_0", "v_{2}{4} L1MinimumBias", "v_{2}{4} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V24_1", "v_{2}{4} L1MinimumBias", "v_{2}{4} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V24_2", "v_{2}{4} L1MinimumBias", "v_{2}{4} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V24_3", "v_{2}{4} L1MinimumBias", "v_{2}{4} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V24_4", "v_{2}{4} L1MinimumBias", "v_{2}{4} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V24_5", "v_{2}{4} L1MinimumBias", "v_{2}{4} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V24_6", "v_{2}{4} L1MinimumBias", "v_{2}{4} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V26_0", "v_{2}{6} L1MinimumBias", "v_{2}{6} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V26_1", "v_{2}{6} L1MinimumBias", "v_{2}{6} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V26_2", "v_{2}{6} L1MinimumBias", "v_{2}{6} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V26_3", "v_{2}{6} L1MinimumBias", "v_{2}{6} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V26_4", "v_{2}{6} L1MinimumBias", "v_{2}{6} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V26_5", "v_{2}{6} L1MinimumBias", "v_{2}{6} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V26_6", "v_{2}{6} L1MinimumBias", "v_{2}{6} 50 - 60 %"  )' -b -q
#
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V28_0", "v_{2}{8} L1MinimumBias", "v_{2}{8} 0 - 5 %"    )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V28_1", "v_{2}{8} L1MinimumBias", "v_{2}{8} 5 - 10 %"   )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V28_2", "v_{2}{8} L1MinimumBias", "v_{2}{8} 10 - 20 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V28_3", "v_{2}{8} L1MinimumBias", "v_{2}{8} 20 - 30 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V28_4", "v_{2}{8} L1MinimumBias", "v_{2}{8} 30 - 40 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V28_5", "v_{2}{8} L1MinimumBias", "v_{2}{8} 40 - 50 %"  )' -b -q
#root -l 'compare3.C("fresult2_24_56.root", "fresult2_62_57.root", "gr_V28_6", "v_{2}{8} L1MinimumBias", "v_{2}{8} 50 - 60 %"  )' -b -q


