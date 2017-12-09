// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Máquina de Café
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2670

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1, a2, a3;
    
    cin >> a1 >> a2 >> a3;
    int a = 2*a2 + 4*a3;
    int b = 2*a1 + 2*a3;
    int c = 2*a2 + 4*a1;
    
    cout << min(a, min(b, c)) << '\n';
    
	return 0;
}
