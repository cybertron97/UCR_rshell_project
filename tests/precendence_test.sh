#!/bin/sh

#tests for precedence operators

cd ..
ls && (echo A || echo “hi”) && ls
echo A || (echo B && echo C)
(echo A && echo B) || (echo C && echo D)
((mkdir love && ls -a) || pwd)

