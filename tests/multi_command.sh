#!/bin/sh
echo "Test case 1: ls -a echo Hello World!"; 
echo "Test case 2: ls -a; echo hello && mkdir myfolder || echo world";
echo "Test case 3: df -h || rm -rf myfolder";
echo "Test case 4: echo Test && df -h";

echo "\nChanging directory to 'rshell...'"
cd ..
bin/rshell << EOF
echo ls -a; ls -a; echo Hello World! 
echo echo hello && mkdir myfolder || echo world; ls -a; echo hello && mkdir myfolder || echo world
echo df -h || rm -rf myfolder; df -h || rm -rf myfolder
echo echo "Test" && df -h; echo "Test" && df -h
echo exit; exit
EOF