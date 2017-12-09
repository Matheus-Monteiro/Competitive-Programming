// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Guilherme e Suas Pipas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1921

#include <bits/stdc++.h>
using namespace std;
int main() {
unsigned long long int r=0,aux=0,a;

	scanf("%lld",&a);

		if (a==3) printf("0\n");
	else
		if (a==4) printf("2\n");
	else{   
	   for (int i=2; i<a-1; i++){
		  r=aux+i;
		  aux=r;   // se digitar 5 = 5; 6 = 9; 7 =14; 2+3+4+5+6...
	   }
	printf("%lld\n", aux);
	}
	return 0;
}
