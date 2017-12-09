// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Azulejos
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1512

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mdc(ll a, ll b){
	return (b == 0 ? a : mdc(b, a%b));
}

ll mmc(ll a, ll b){
	return a*b/mdc(a, b);
}

int main(){
	long long n, a, b;
	
	while(cin >> n >> a >> b and (n or a or b))
		cout << ((n/a)+(n/b)-(n/mmc(a, b))) << '\n';
	
	return 0;
}
