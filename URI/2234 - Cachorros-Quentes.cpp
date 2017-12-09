// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cachorros-Quentes
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2234

#include <iostream>

using namespace std;

int main(){

	int a, b;
	double resposta;
	
	cin >> a >> b;
	
	resposta = (double)a/b;
	
	cout.precision(2);
	cout << fixed;
	cout << resposta << endl;

	return 0;
}
