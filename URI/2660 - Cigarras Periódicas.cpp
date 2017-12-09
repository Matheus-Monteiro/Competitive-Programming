// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cigarras Periódicas
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2660

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

typedef long long ll;

ll mmc(ll a, ll b)
{
    return (a*b)/__gcd(a, b);
}

int main()
{
    ll n, l, aux, mm = 1;

    cin >> n >> l;

    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        mm = mmc(mm, aux);
    }
    ll mx = 0, ans;
    for(ll i = 1; i <= l; i++)
    {
        ll k = mmc(i, mm);
        if(k > mx and k <= l)
            ans = i, mx = k;
    }
    cout << ans << '\n';

	return 0;
}
