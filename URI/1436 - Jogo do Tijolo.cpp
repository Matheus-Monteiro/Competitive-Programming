// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Jogo do Tijolo
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1436

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, v[100], caso = 1;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> v[i];
		cout << "Case " << caso++ << ": " << v[n/2] << '\n';
	}
	
	return 0;
}
