// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Raiz Quadrada de 10
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2161

#include <iostream>

using namespace std;

int main(){
	int n;
	double resposta = 0;
	
	cin >> n;
	
	while(n--){
		resposta += 1/6;
		resposta += 6;
		resposta = 1/resposta;
	}
	cout.precision(10);
	cout << fixed;
	cout << resposta+3 << endl;
	
	return 0;
}
