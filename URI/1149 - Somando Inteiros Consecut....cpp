// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Somando Inteiros Consecut...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1149

#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, n, soma=0;

		cin >> a;
		do{
			cin >> n;
		}while(n <= 0 );

		for(int i = 0 ; i < n ; i++){
			soma += a+i;
		}
		cout << soma << endl;
return 0;
}
