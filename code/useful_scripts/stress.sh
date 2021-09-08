make sol brute gen

for ((i = 1; ; i++)) do
	./gen $i > in
	./sol < in > out
	./brute < in > out2
	if (! cmp -s out out2) then
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
