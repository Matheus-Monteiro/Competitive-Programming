// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Evento
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2172

#include <iostream>

using namespace std;

int main(){
	
	int x;
	unsigned long long exp;
	
	while((cin >> x >> exp),x,exp){
		cout << x*exp << endl;
	}
	
	return 0;
}
