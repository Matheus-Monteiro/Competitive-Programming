// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Array Hash
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1257

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, l, valor, entrada;
	string str;
	
	cin >> n;
	
	while(n--){
		valor = 0;
		entrada = 0;
		cin >> l;
		while(l--){
			cin >> str;
			for(int j = 0; j < str.size(); j++){
				valor += int(str[j]-65);
				valor += entrada;
				valor += j;
			}
			entrada++;
		}
		cout << valor << endl;
	}
	
	return 0;
}
