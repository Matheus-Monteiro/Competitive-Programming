#!/bin/bash

make sol brute gen check

for ((i = 1; ; i++)) do
	./gen $i > in
	./sol < in > out
	./brute < in > out2
	./check > log

	expected=correct
	result=$(< check.txt)

	if [ "$expected" != "$result" ]; then
		echo "--> entrada:"
		cat in
		echo "--> saida sol"
		cat out
		echo "--> saida2 brute"
		cat out2
		break;
	fi
	echo $i
done
