root -l -b <<EOF
int s1 = $1;
.x genPlot.C
.q
EOF
