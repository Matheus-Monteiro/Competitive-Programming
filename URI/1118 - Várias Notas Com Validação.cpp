// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Várias Notas Com Validação
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1118

#include <bits/stdc++.h>

using namespace std;

int main(){
	
    double n1, n2, ncal;
	int t=1;

	while(t==1){
		do{
			cin >> n1;
			if(n1 < 0 || n1 > 10)
				cout << "nota invalida" << endl;
		}while(n1 < 0 || n1 > 10);

		do{
			cin >> n2;
			if(n2 < 0 || n2 > 10)
				cout << "nota invalida" << endl;
		}while(n2 < 0 || n2 > 10);

		cout.precision(2);
		cout << fixed;
		cout << "media = " << ((n1+n2)/2) << endl;

		do{
			cout << "novo calculo (1-sim 2-nao)" << endl;
			cin >> t;
		}while(t < 1 || t > 2);
	}
}
