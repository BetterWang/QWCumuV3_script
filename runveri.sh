root -l -b <<EOF
int s1 = $1;
.x verify.C
.q
EOF
