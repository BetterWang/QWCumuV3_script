root -n -l -b <<EOF
.x process.C+($1, $2, $3, $4)
.q
EOF
