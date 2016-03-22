#root -l -b -q "genPlot.C(30)"
#root -l -b -q "genPlot.C(36)"
#root -l -b -q "genPlot.C(42)"
#root -l -b -q "genPlot.C(48)"
#root -l -b -q "genPlot.C(54)"
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
#
root -l -b -q "mergeTrig.C(18, 13)"
root -l -b -q "mergeTrig.C(24, 19)"
root -l -b -q "mergeTrig.C(30, 25)"
root -l -b -q "mergeTrig.C(36, 31)"
root -l -b -q "mergeTrig.C(42, 37)"
root -l -b -q "mergeTrig.C(48, 43)"
root -l -b -q "mergeTrig.C(54, 49)"
###### eff
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V24_0", "v_{2}{4} with eff", "v_{2}{4} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V24_1", "v_{2}{4} with eff", "v_{2}{4} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V24_2", "v_{2}{4} with eff", "v_{2}{4} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V24_3", "v_{2}{4} with eff", "v_{2}{4} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V24_4", "v_{2}{4} with eff", "v_{2}{4} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V24_5", "v_{2}{4} with eff", "v_{2}{4} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V24_6", "v_{2}{4} with eff", "v_{2}{4} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V26_0", "v_{2}{6} with eff", "v_{2}{6} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V26_1", "v_{2}{6} with eff", "v_{2}{6} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V26_2", "v_{2}{6} with eff", "v_{2}{6} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V26_3", "v_{2}{6} with eff", "v_{2}{6} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V26_4", "v_{2}{6} with eff", "v_{2}{6} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V26_5", "v_{2}{6} with eff", "v_{2}{6} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V26_6", "v_{2}{6} with eff", "v_{2}{6} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V28_0", "v_{2}{8} with eff", "v_{2}{8} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V28_1", "v_{2}{8} with eff", "v_{2}{8} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V28_2", "v_{2}{8} with eff", "v_{2}{8} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V28_3", "v_{2}{8} with eff", "v_{2}{8} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V28_4", "v_{2}{8} with eff", "v_{2}{8} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V28_5", "v_{2}{8} with eff", "v_{2}{8} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_18_13.root", "fresult2_24_19.root", "gr_V28_6", "v_{2}{8} with eff", "v_{2}{8} 60 - 70 %"  )' -b -q

######  calo
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V24_0", "v_{2}{4} without caloMatch", "v_{2}{4} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V24_1", "v_{2}{4} without caloMatch", "v_{2}{4} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V24_2", "v_{2}{4} without caloMatch", "v_{2}{4} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V24_3", "v_{2}{4} without caloMatch", "v_{2}{4} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V24_4", "v_{2}{4} without caloMatch", "v_{2}{4} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V24_5", "v_{2}{4} without caloMatch", "v_{2}{4} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V24_6", "v_{2}{4} without caloMatch", "v_{2}{4} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V26_0", "v_{2}{6} without caloMatch", "v_{2}{6} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V26_1", "v_{2}{6} without caloMatch", "v_{2}{6} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V26_2", "v_{2}{6} without caloMatch", "v_{2}{6} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V26_3", "v_{2}{6} without caloMatch", "v_{2}{6} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V26_4", "v_{2}{6} without caloMatch", "v_{2}{6} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V26_5", "v_{2}{6} without caloMatch", "v_{2}{6} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V26_6", "v_{2}{6} without caloMatch", "v_{2}{6} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V28_0", "v_{2}{8} without caloMatch", "v_{2}{8} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V28_1", "v_{2}{8} without caloMatch", "v_{2}{8} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V28_2", "v_{2}{8} without caloMatch", "v_{2}{8} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V28_3", "v_{2}{8} without caloMatch", "v_{2}{8} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V28_4", "v_{2}{8} without caloMatch", "v_{2}{8} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V28_5", "v_{2}{8} without caloMatch", "v_{2}{8} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_30_25.root", "fresult2_24_19.root", "gr_V28_6", "v_{2}{8} without caloMatch", "v_{2}{8} 60 - 70 %"  )' -b -q

###### Tight
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V24_0", "v_{2}{4} tight", "v_{2}{4} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V24_1", "v_{2}{4} tight", "v_{2}{4} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V24_2", "v_{2}{4} tight", "v_{2}{4} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V24_3", "v_{2}{4} tight", "v_{2}{4} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V24_4", "v_{2}{4} tight", "v_{2}{4} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V24_5", "v_{2}{4} tight", "v_{2}{4} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V24_6", "v_{2}{4} tight", "v_{2}{4} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V26_0", "v_{2}{6} tight", "v_{2}{6} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V26_1", "v_{2}{6} tight", "v_{2}{6} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V26_2", "v_{2}{6} tight", "v_{2}{6} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V26_3", "v_{2}{6} tight", "v_{2}{6} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V26_4", "v_{2}{6} tight", "v_{2}{6} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V26_5", "v_{2}{6} tight", "v_{2}{6} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V26_6", "v_{2}{6} tight", "v_{2}{6} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V28_0", "v_{2}{8} tight", "v_{2}{8} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V28_1", "v_{2}{8} tight", "v_{2}{8} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V28_2", "v_{2}{8} tight", "v_{2}{8} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V28_3", "v_{2}{8} tight", "v_{2}{8} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V28_4", "v_{2}{8} tight", "v_{2}{8} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V28_5", "v_{2}{8} tight", "v_{2}{8} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_36_31.root", "fresult2_24_19.root", "gr_V28_6", "v_{2}{8} tight", "v_{2}{8} 60 - 70 %"  )' -b -q

###### Loose
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V24_0", "v_{2}{4} loose", "v_{2}{4} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V24_1", "v_{2}{4} loose", "v_{2}{4} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V24_2", "v_{2}{4} loose", "v_{2}{4} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V24_3", "v_{2}{4} loose", "v_{2}{4} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V24_4", "v_{2}{4} loose", "v_{2}{4} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V24_5", "v_{2}{4} loose", "v_{2}{4} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V24_6", "v_{2}{4} loose", "v_{2}{4} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V26_0", "v_{2}{6} loose", "v_{2}{6} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V26_1", "v_{2}{6} loose", "v_{2}{6} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V26_2", "v_{2}{6} loose", "v_{2}{6} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V26_3", "v_{2}{6} loose", "v_{2}{6} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V26_4", "v_{2}{6} loose", "v_{2}{6} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V26_5", "v_{2}{6} loose", "v_{2}{6} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V26_6", "v_{2}{6} loose", "v_{2}{6} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V28_0", "v_{2}{8} loose", "v_{2}{8} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V28_1", "v_{2}{8} loose", "v_{2}{8} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V28_2", "v_{2}{8} loose", "v_{2}{8} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V28_3", "v_{2}{8} loose", "v_{2}{8} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V28_4", "v_{2}{8} loose", "v_{2}{8} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V28_5", "v_{2}{8} loose", "v_{2}{8} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_42_37.root", "fresult2_24_19.root", "gr_V28_6", "v_{2}{8} loose", "v_{2}{8} 60 - 70 %"  )' -b -q

###### Vz0
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V24_0", "v_{2}{4} |vz| < 3", "v_{2}{4} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V24_1", "v_{2}{4} |vz| < 3", "v_{2}{4} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V24_2", "v_{2}{4} |vz| < 3", "v_{2}{4} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V24_3", "v_{2}{4} |vz| < 3", "v_{2}{4} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V24_4", "v_{2}{4} |vz| < 3", "v_{2}{4} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V24_5", "v_{2}{4} |vz| < 3", "v_{2}{4} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V24_6", "v_{2}{4} |vz| < 3", "v_{2}{4} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V26_0", "v_{2}{6} |vz| < 3", "v_{2}{6} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V26_1", "v_{2}{6} |vz| < 3", "v_{2}{6} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V26_2", "v_{2}{6} |vz| < 3", "v_{2}{6} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V26_3", "v_{2}{6} |vz| < 3", "v_{2}{6} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V26_4", "v_{2}{6} |vz| < 3", "v_{2}{6} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V26_5", "v_{2}{6} |vz| < 3", "v_{2}{6} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V26_6", "v_{2}{6} |vz| < 3", "v_{2}{6} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V28_0", "v_{2}{8} |vz| < 3", "v_{2}{8} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V28_1", "v_{2}{8} |vz| < 3", "v_{2}{8} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V28_2", "v_{2}{8} |vz| < 3", "v_{2}{8} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V28_3", "v_{2}{8} |vz| < 3", "v_{2}{8} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V28_4", "v_{2}{8} |vz| < 3", "v_{2}{8} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V28_5", "v_{2}{8} |vz| < 3", "v_{2}{8} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_48_43.root", "fresult2_24_19.root", "gr_V28_6", "v_{2}{8} |vz| < 3", "v_{2}{8} 60 - 70 %"  )' -b -q

###### Vz1
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V24_0", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V24_1", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V24_2", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V24_3", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V24_4", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V24_5", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V24_6", "v_{2}{4} 3 < |vz| < 15", "v_{2}{4} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V26_0", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V26_1", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V26_2", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V26_3", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V26_4", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V26_5", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V26_6", "v_{2}{6} 3 < |vz| < 15", "v_{2}{6} 60 - 70 %"  )' -b -q

root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V28_0", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 0 - 10 %"   )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V28_1", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 10 - 20 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V28_2", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 20 - 30 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V28_3", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 30 - 40 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V28_4", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 40 - 50 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V28_5", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 50 - 60 %"  )' -b -q
root -l 'compare3.C("fresult2_54_49.root", "fresult2_24_19.root", "gr_V28_6", "v_{2}{8} 3 < |vz| < 15", "v_{2}{8} 60 - 70 %"  )' -b -q


