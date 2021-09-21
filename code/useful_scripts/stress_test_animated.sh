make sol brute gen

cmatrix &

for ((i = 1;  ; i++)) do
	./gen $i > in
	./sol < in > out
	./brute < in > out2
	if (! cmp -s out out2) then
		kill -9 `pgrep -u matheus cmatrix`
		reset
		clear
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