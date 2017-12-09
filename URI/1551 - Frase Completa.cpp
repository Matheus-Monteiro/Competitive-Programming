// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Frase Completa
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1551

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdio>

using namespace std;

int main(){
	int n, numero, cont;
	string str;
	char letra;
	vector<int> v;
	
	cin >> n;
	
	while(n--){
		v.clear();
		str.clear();
		for(int i = 0; i < 26; i++)
			v.push_back(0);
		
		getchar();
		getline(cin, str);
		
		for(int i = 0; i < str.length(); i++){
			if(isalpha(str[i])){
				letra = str[i];
				numero = letra - 96;
				v[numero] = 1;
			}
		}
		cont = 0;
		for(int i = 0; i < str.length(); i++){
			if(v[i] == 1)
				cont++;
		}
		if(cont == 26)
			cout << "frase completa" << endl;
		else 
			if(cont > 13)
				cout << "frase quase completa" << endl;
			else
				cout << "frase mal elaborada" << endl;
	}
	
	
	
	return 0;
}
