#!/bin/zsh
echo "tip mandlebort: "
echo "1 = mandelbort \n2 = mandlebort2"
echo "3 = julia\n4 = julia2\n"
read nb
if [ "$nb" -eq 1 ]
then
	./$1 mandlebort
elif [ "$nb" -eq 2 ]
then
	./$1 mandlebort2
elif [ "$nb" -eq 3 ]
then
	./$1 julia
elif
then
	./$1 julia2
fi
