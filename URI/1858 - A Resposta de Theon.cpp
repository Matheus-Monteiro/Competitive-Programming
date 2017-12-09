// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Resposta de Theon
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1858

#include <iostream>
#define MAX 110

using namespace std;

int main(){
	int n, t[MAX], aux, x = 1;
	
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> t[i];
		}

		aux = t[1];

		for(int i = 1; i <= n; i++){
			if(aux > t[i]){
				aux = t[i];
				x = i;
			}
		}

			cout << x << endl;
		
return 0;
}
