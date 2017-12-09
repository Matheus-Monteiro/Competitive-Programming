// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fatorial de Novo!
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1429

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[20];

ll fat(int n)
{
    if(memo[n] != -1)
        return memo[n];
    return memo[n] = n*fat(n-1);
}

int main()
{
    ll n;
    memset(memo, -1, sizeof(memo));
    memo[0] = memo[1] = 1;

    while(scanf("%lld", &n) and n)
    {
        ll ans = 0;
        string str = to_string(n);    
        for(int i = 0; i < str.size(); i++)
            ans += (str[i]-'0')*fat(str.size()-i);
        printf("%lld\n", ans);
    }
    
    return 0;
}
