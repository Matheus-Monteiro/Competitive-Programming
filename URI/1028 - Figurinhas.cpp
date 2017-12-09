// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Figurinhas
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1028

#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b){
	return !b ? a : mdc(b, a%b);
}

int main(){
	int n, a, b;
	
	cin >> n;
	while(n--){
		cin >> a >> b;
		cout << mdc(a, b) << '\n';
	}
	
	return 0;
}
