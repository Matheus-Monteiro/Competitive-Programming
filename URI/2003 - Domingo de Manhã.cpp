// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Domingo de Manhã
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2003

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int h, m, atraso;
	char p;
	while(cin >> h >> p >> m){
		atraso = 60*h + m + 60 - 480;
		if(atraso > 0)
			cout << "Atraso maximo: " << atraso << endl;
		else
			cout << "Atraso maximo: 0" << endl;			
	}
return 0;
}
