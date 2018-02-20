#!/bin/sh
echo "Test case 1: exit";
echo "Test case 2: echo A && exit";
echo "Test case 3: echo B || exit";

echo "\nChanging directory to 'rshell...'"
cd ..
echo "------Testing with 'exit'------";
bin/rshell << EOF
echo "Test case 1:"; exit
EOF
echo "------Testing with 'echo A && exit '------";
bin/rshell << EOF
echo "Test case 2:"; echo A && exit 
EOF
echo "------Testing with 'echo B || exit'------";
bin/rshell << EOF
echo "Test case 3:"; echo B || exit
echo Exiting 'exit.sh'; exit
EOF