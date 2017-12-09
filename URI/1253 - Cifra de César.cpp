// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cifra de César
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1253

#include <iostream>

using namespace std;

int main(){

	int t, n, aux;
	string str;
	
	cin >> t;
	
	while(t--){
		cin >> str;
		cin >> n;
		
		for(int i = 0; i < str.size(); i++){
			str[i] -= n;
			if(!isalpha(str[i])){
				str[i] += n;
				aux = str[i];
				aux = aux + 26 - n;
				str[i] = aux;
			}
		}
		cout << str << endl;
	}

	return 0;
}
