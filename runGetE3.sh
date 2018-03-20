root -l -b <<EOF
.x bGetError.C+($1)
.q
EOF

root -l -b <<EOF
.x genPlot.C($1)
.q
EOF

