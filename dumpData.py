import ROOT

f = ROOT.TFile('fresult2_62_57.root')

# 11 - 10-30%
# 12 - 30-50%
tab = {}
tab['v24_10_30'] = f.Get('gr_V24_11')
tab['v26_10_30'] = f.Get('gr_V26_11')
tab['v28_10_30'] = f.Get('gr_V28_11')
tab['v24_30_50'] = f.Get('gr_V24_12')
tab['v26_30_50'] = f.Get('gr_V26_12')
tab['v28_30_50'] = f.Get('gr_V28_12')


for key in tab.keys():
    print key;
    print "  N bins:", tab[key].GetN()
    data = [ [tab[key].GetX()[idx], tab[key].GetY()[idx], tab[key].GetEY()[idx]] for idx in range(tab[key].GetN()) ]
    fw = open(key+'.txt', 'w')
    for d in data:
        print '{:10.4f},{:10.4f},{:10.4f}'.format(d[0],d[1], d[2])
        fw.write('{:10.4f},{:10.4f},{:10.4f}'.format(d[0],d[1], d[2]))
        fw.write('\n')
    fw.close()

