// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Andando no Tempo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2235

#include <iostream>

using namespace std;

int main(){

	int a, b, c;
	
	cin >> a >> b >> c;
	
	if(a == b || a == c || b == c || a == b+c || b == a+c || c == b+a)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	
	return 0;
}
