// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Enigma do Pronalândia
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1984

#include <iostream>

using namespace std;

int main (){

	string str;
	
	cin >> str;
	
	for(int i = str.size()-1; i >= 0; i--){
		cout << str[i];
	}
	cout << endl;
	
	return 0;
}
