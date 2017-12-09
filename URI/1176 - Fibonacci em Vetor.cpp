// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fibonacci em Vetor
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1176

#include <iostream>

using namespace std;

int main()
{
	unsigned long long int fibonacci[62];
	int t, n;
	
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	
	for(int i = 2; i < 61; i++){
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
	}
	
	cin >> t;
	while(t--){
		cin >> n;
		cout << "Fib(" << n <<") = " << fibonacci[n] << endl;
	}
	
return 0;
}

