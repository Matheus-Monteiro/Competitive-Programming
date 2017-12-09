// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Número Primo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1165

#include <bits/stdc++.h>

using namespace std;

bool isprimo(int n){
	if(n < 5 || n%2 == 0 || n%3 == 0)
		return (n==2 || n==3);
	
	int maxP = sqrt(n) + 2;

	for(int p = 5 ; p < maxP ; p+=6)
		if(n%p == 0 || n%(p+2) == 0)
			return false;

	return true;
}


int main(){

	int num, n;

	cin >> n;

	while(n--){
		cin >> num;
		isprimo(num);

		if(isprimo(num) == true)
			cout << num << " eh primo" << endl;
		else
			cout << num << " nao eh primo" << endl;
	}
}
