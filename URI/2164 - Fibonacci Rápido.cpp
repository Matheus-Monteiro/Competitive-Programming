// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fibonacci Rápido
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2164

#include <iostream>
#include <math.h>

using namespace std;

int main () {
	
	double t1, t2, td;
	int n;
	
	cin >> n;
	t1 = pow(((1 + sqrt(5))/2), n);
	t2 = pow(((1 - sqrt(5))/2), n);
	td = (t1 - t2)/ sqrt(5);
	cout.precision(1);
	cout << fixed;
	cout << td << endl;
	return 0;
}
