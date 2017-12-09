// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Temível Evil-Son
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2218

#include <iostream>	

using namespace std;

int main(){

	int t, n, resposta;
	cin >> t;
	while(t--){
		cin >> n;
		resposta = (n*n + n + 2)/2;
		cout << resposta << endl;
	}

	return 0;
}
