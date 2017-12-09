// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Filme
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1963

#include <iostream>

using namespace std;

int main (){

	double a, b;
	
	cin >> a >> b;
	
	cout.precision(2);
	cout << fixed;
	cout << ( 100*b/a ) - 100 << "%" << endl;
	
	return 0;
}
