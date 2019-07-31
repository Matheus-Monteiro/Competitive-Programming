#include <iostream>

using namespace std;

int collatz(int n, int resposta){
	int cont;
	if(n > 1){
		if(n%2 == 0)
			n = n/2;
		else
			n = 3*n + 1;
		resposta++;
		return collatz(n, resposta); 
	}else{
		return resposta;
	}
}
	
int main(){

	int n, resposta=0, r;
	
	cin >> n;
	r = collatz(n, resposta);
	cout << r << endl;
	return 0;
}