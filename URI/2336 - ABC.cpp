// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: ABC
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2336

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;

ll expmod(ll n, ll e){
    ll ans = 1;
    while(e)
        if(e & 1)
            ans = (ans*n)%M, e--;
        else
            n = (n*n)%M, e /= 2;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string s;

    while(cin >> s){
        ll ans = 0;
        for(int i = s.size()-1, k = 0; i >= 0; i--, k++)
            if(s[i] - 'A')
                ans += (((s[i] - 'A')%M)*(expmod(26, k)))%M;
        cout << ans%M << '\n';
    }

    return 0;
}
