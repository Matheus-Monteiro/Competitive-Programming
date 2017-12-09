// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Loteria
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2473

#include <bits/stdc++.h>
using namespace std;

int main(){
	int v1[6], v2[6], ans;
	
	for(int i = 0; i < 6; i++)
		cin >> v1[i];
	for(int i = 0; i < 6; i++)
		cin >> v2[i];
	ans = 0;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(v1[i] == v2[j])
				ans++;
		}
	}
	if(ans == 3)
		cout << "terno" << '\n';
	else if(ans == 4)
		cout << "quadra" << '\n';
	else if(ans == 5)
		cout << "quina" << '\n';
	else if(ans == 6)
		cout << "sena" << '\n';
	else
		cout << "azar" << '\n';
	return 0;
}
