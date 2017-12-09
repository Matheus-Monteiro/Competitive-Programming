// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Triângulo de Pascal
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2232

#include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned int t, n, soma, aux;
	
	cin >> t;	
	
	while(t--){
		cin >> n;
		soma = 0;
		for(int i = 0; i < n; i++){
			aux = pow(2, i);
			soma += aux;
		}
		cout << soma << endl;
	}
	
	return 0;
}
