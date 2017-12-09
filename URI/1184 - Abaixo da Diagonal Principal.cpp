// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Abaixo da Diagonal Principal
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1184

#include <iostream>

using namespace std;

int main(){
	double M[12][12], soma = 0;
	int i, j;
	char t;	
	
	cin >> t;

		for(i = 0; i < 12; i++){
			for(j = 0; j < 12; j++){
				cin >> M[i][j];
			}
		}

		for(i = 0; i < 12; i++){
				for(j = 0; j < 12; j++){
					if(i > j)
						soma += M[i][j];
					
				}
		}

		if(t == 'S'){
			cout << soma << endl;
		}
		if(t == 'M'){
			cout << soma/66 << endl;
		}
return 0;
}
