// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequência Espelho
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2157

#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, t;
	string str, aux, num;
	cin >> t;
	while(t--){	
		cin >> a >> b;
		for(int i = a; i <= b; i++){
			ostringstream convert;
			convert << i;
			num = convert.str();
			str += num;
		}
		aux = str;
		reverse(aux.begin(), aux.end());
		cout << str << aux << endl;
		aux.clear();
		str.clear();
	}
	
	
	return 0;
}
