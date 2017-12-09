// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Máquina de Verificação Au...
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1743

#include <bits/stdc++.h>

using namespace std;

int main(){
	int c1[5], c2[5];
	
	for(int i = 0; i < 5; i++)
		cin >> c1[i];
	for(int i = 0; i < 5; i++)
		cin >> c2[i];
	bool buraco = true;
	for(int i = 0; i < 5 && buraco; i++)
		if(c1[i] == c2[i])
			buraco = false;
	buraco ? cout << "Y" << endl : cout << "N" << endl;
	return 0;
}
