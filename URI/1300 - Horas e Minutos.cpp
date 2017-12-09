// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Horas e Minutos
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1300

#include <bits/stdc++.h>

using namespace std;

int main() {
	int a;

	while( scanf( "%d", &a ) != EOF )
		printf( "%s\n", !( a%6 ) ? "Y" : "N" );
}
