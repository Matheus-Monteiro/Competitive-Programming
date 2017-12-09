// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequência S
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1155

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	double s=0;

	for(int i = 1 ; i <= 100 ; i++){
		s += double(1)/i;
	}

	cout.precision(2);
	cout << fixed;
	cout << s << endl;
}
