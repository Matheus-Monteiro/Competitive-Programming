// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Nossos Dias Nunca Voltarão
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1864

#include <iostream>

using namespace std;

int main(){
	
	int n;
	string str = "LIFE IS NOT A PROBLEM TO BE SOLVED";

	cin >> n;

	for(int i = 0; i < n; i++){
		cout << str[i];
	}
	cout << endl;
	return 0;
}
