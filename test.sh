#!/bin/zsh
echo "tip mandlebort: \n 1 = mandelbort \n 2 = julia \n 3 = da"
read nb
if [ "$nb" -eq 1 ]
then
	./$1 mandlebort
elif [ "$nb" -eq 2 ]
then
	./$1 julia
elif
then
	./$1 da
fi
