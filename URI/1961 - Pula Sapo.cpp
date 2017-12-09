// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pula Sapo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1961

#include <iostream>
#include <math.h>
using namespace std;

int main (){

	int p, n, h1, h2=0, aux;
	bool t = false;
	
	cin >> p >> n;
	aux  = n-1;
	while(n--){ 
		cin >> h1;
		
		if(h1-h2 > p  ||  fabs(h2-h1) > p)
			t = true;
		if(aux == n)
			t = false;
		
		h2 = h1;
	}
	if(t)
		cout << "GAME OVER" << endl;
	else
		cout << "YOU WIN" << endl;
		
	return 0;
}
