// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Kage Bunshin no Jutsu
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2544

#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int n, p, ans;
    
    while(cin >> n)
    {
        p = 1;
        ans = 0;
        while(p < n)
            p *= 2, ans++;
        cout << ans << '\n';
    }
    
    return 0;
}
