// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Desafio de Bino
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2060

#include <iostream>

using namespace std;

int main (){

	int casos, n, two=0, three=0, four=0, five=0;
	
	cin >> casos;
	
	while(casos--){
	
		cin >> n;
		
		if(n%2 == 0)
			two++;
		if(n%3 == 0)
			three++;
		if(n%4 == 0)
			four++;
		if(n%5 == 0)
			five++;
	}
	
	cout << two << " Multiplo(s) de 2" << endl;
	cout << three << " Multiplo(s) de 3" << endl;
	cout << four << " Multiplo(s) de 4" << endl;
	cout << five << " Multiplo(s) de 5" << endl;
	
	return 0;
}
