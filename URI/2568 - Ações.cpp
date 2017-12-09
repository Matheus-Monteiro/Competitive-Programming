// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ações
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2568

#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int d, i, x, f, ans;

    cin >> d >> i >> x >> f;
 
    ans = i;
    for(int j = d+1; j <= (d+f); j++)
        if(j & 1)
            ans -= x;
        else
            ans += x;
    cout << ans << '\n';
    
    return 0;
}
