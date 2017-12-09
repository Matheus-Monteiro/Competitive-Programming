// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Galopeira
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2147

#include <iostream>

using namespace std;

int main () {
	
	int n;
	string str;
	
	cin >> n;
	
	while(n--){
		cin >> str;
		cout.precision(2);
		cout << fixed;
		cout << str.size()*0.01 << endl;
	}

	return 0;
}
