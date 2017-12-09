// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Preenchimento de Vetor III
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1178

#include <bits/stdc++.h>
using namespace std;

int main(){
	double v[100], x;
    cin >> x;

		for(int i = 0 ; i < 100 ; i++){
			v[i] = x;
			x = x/2;
		}
			cout.precision(4);
			cout << fixed;
		for(int i = 0 ; i < 100 ; i++)
			cout << "N[" << i << "] = " << v[i] << endl;

	return 0;
}
