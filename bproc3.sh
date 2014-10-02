root -l -b <<EOF
int s1 = $1;
int s2 = $2;
int s3 = $3;
.x process.C
.q
EOF
