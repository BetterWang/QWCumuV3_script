root -l -b <<EOF
int s1 = $1;
.x bGetError.C
.q
EOF
