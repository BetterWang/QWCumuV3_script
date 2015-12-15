root -l -b <<EOF
int nCut = $1;
int bPbPb = $2;
.x ratioStat.C
.q
EOF
