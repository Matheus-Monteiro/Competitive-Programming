// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Economia Brasileira
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1796

#include <bits/stdc++.h>

using namespace std;

int main(){
	int v[233010], q, sat = 0, ins = 0;
	bool buraco;
	
	cin >> q;
	for(int i = 0; i < q; i++)
		cin >> v[i];
	for(int i = 0; i < q; i++)
		(v[i] == 0) ? sat++ : ins++;
	(sat > ins) ? buraco = true : buraco = false;
	buraco ? cout << "Y" << endl : cout << "N" << endl;
	return 0;
}
