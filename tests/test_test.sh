#!/bin/sh
#tests for test command

cd ..
test Makefile
test -d src
[ -e src ] && echo "path exists"
test -e src && echo "path does exist"

