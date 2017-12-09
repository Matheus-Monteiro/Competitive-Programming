// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Números de Ahmoc
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2049

#include <bits/stdc++.h>
using namespace std;

int main(){
	bool flag = false;
	int caso = 1, p;
	string s1, s2;
	
	while(cin >> s1 >> s2 and s1 != "0"){
		if(flag) cout << '\n';
		else flag = true;
		p = s2.find(s1);
		cout << "Instancia " << caso++ << '\n';
		if(p != -1)
			cout << "verdadeira" << '\n';
		else
			cout << "falsa" << '\n';
	}
	
	return 0;
}
