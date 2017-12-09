// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Nome no Formulário
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2160

#include <iostream>
#include <string>

using namespace std;

int main () {
	
	string str;
	
	getline(cin, str);

	if(str.length() <= 80)
		cout << "YES" << endl;
	if(str.length() > 80)
		cout << "NO" << endl;
	
	return 0;
}
