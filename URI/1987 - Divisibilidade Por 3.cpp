// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Divisibilidade Por 3
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1987

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, soma;
	string num;
	
	while(cin >> n >> num){
		soma = 0;
		for(int i = 0; i < num.size(); i++){
			char c = num[i];
			int z = atoi(&c);
			soma += z;
		}
		
		if(soma%3 == 0)
			cout << soma << " " << "sim" << endl;
		else
			cout << soma << " " << "nao" << endl;
	}
	
	return 0;
}
