// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Primo Rápido
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1221

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
	int k = sqrt(x);
	for(int i = 2; i <= k; i++)
		if(!(x%i))
			return false;
	return true;
}

int main(){
	int n, x;
	cin >> n;
	while(n--){
		cin >> x;
		cout << (isPrime(x) ? "Prime" : "Not Prime") << '\n';
	}
	
	return 0;
}
