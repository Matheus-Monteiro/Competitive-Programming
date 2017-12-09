// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Contando Caracters
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2108

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str, aux, biggest;
	
	while(getline(cin, str) and str != "0"){
		int ans = 0;
		bool flag = false;
		for(int i = 0; i < str.size(); i++){
		    if(!isspace(str[i]))
			aux.push_back(str[i]);
			if(isspace(str[i])){
				if(aux.size() >= biggest.size())
					biggest = aux;
				aux.clear();
				cout << ans << '-';
				ans = 0;
			}else
				ans++;
			if(i == str.size()-1){
				if(aux.size() >= biggest.size())
					biggest = aux;
				aux.clear();
				cout << ans << '\n';
			}
		}
	}
	cout << '\n' << "The biggest word: " << biggest << '\n';
	
	return 0;
}
