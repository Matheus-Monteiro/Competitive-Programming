// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Estágio
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2533

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a1, a2;
    double aux1, aux2;
    
    while(cin >> n)
    {
        aux1 = aux2 = 0.0;
        while(n--)
        {
            cin >> a1 >> a2;
            aux1 += a1*a2;
            aux2 += a2;
        }
        cout << setprecision(4) << fixed << aux1/(aux2*100) << '\n';
    }    
    
    return 0;
}
