// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Soma de Fatoriais
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1161

#include <iostream>

using namespace std;

unsigned long long fatorial(long long n){
	long long i = 1;
	for(; n > 0; n--){
		i *= n;
	}
	return i;
}

int main () {
	
	long long fat1, fat2;
	while(cin >> fat1 >> fat2)
		cout << fatorial(fat1) + fatorial(fat2) << endl;
	
	return 0;
}
