// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequências Crescentes
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1146

#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, r;

	while(cin >> x && x != 0){
	
		for(int i = 1 ; i <= x ; i++){
			if(x > i)						
				cout << i << " ";
			else 
				cout << i << endl;
		}
	}
}
