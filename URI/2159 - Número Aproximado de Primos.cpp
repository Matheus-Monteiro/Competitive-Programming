// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Número Aproximado de Primos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2159

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	cout.precision(1);
	cout << fixed;
	cout << n/log(n) << " " << 1.25506*(n/log(n)) << endl;
	
	return 0;
}
