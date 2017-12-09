// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O jogo Matemático de Paula
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1192

#include <bits/stdc++.h>

using namespace std;

int main(){

	char str[4];
	int resposta, n;
	cin >> n;
	while(n--){
		cin >> str;
	
		int aux1 = atoi(&str[0]);
		int aux2 = atoi(&str[2]);
	
		if(aux1 == aux2)
			resposta = aux1*aux2;
		else{
			if(isupper(str[1]))
				resposta = aux2 - aux1;
			if(islower(str[1]))
				resposta = aux1 + aux2;
		}
		cout << resposta << endl;
	}
	return 0;
}
