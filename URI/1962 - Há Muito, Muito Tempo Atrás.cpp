// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Há Muito, Muito Tempo Atrás
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1962

#include <iostream>
#define MAX 101

using namespace std;

int main (){

	int n, t;
	
	cin >> n;
	
	while(n--){
		cin >> t;
		if(t >= 2015)
			cout << t - 2015 + 1 << " A.C." << endl;
		else
			cout << 2015 - t << " D.C." << endl;
	}
	
	return 0;
}
