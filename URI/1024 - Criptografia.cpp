// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Criptografia
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1024

#include <iostream>
#include <string.h>

using namespace std;

int main(){

	int n;
	string str;
	string aux;
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, str);
		for(int i = 0; i < str.size(); i++){
			if(isalpha(str[i]))
				str[i] = str[i] + 3;
		}
		aux = str;
		int j = 0;
		for(int i = str.size()-1; i > -1; i--){
			aux[j] = str[i];
			j++;
		}
		for(int i = aux.size()/2; i < aux.length(); i++){
			aux[i] = aux[i] - 1;
		}
		cout << aux << endl;
		str.clear();
		aux.clear();
	}

	return 0;
}
