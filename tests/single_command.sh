#!/bin/sh
echo "Test 1: ls"
echo "Test 2: echo This is my comment"
echo "Test 3: mkdir aFold"
echo "Test 4: df -h"

echo "\nChanging directory to 'rshell...'"
cd ..
bin/rshell << EOF
echo ls; ls
echo echo This is my comment; echo This is my comment
echo mkdir aFold; mkdir aFold
echo df -h; df -h
echo exit; exit
EOF