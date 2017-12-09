// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Emplacando os Tuk-tuks
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1890

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main()
{
    int n;
    ll a, b;

    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        ll ans = 1;
        REP(i, a) ans *= 26;
        REP(i, b) ans *= 10;
        cout << (ans == 1 ? 0 : ans) << '\n';
    }
    
    return 0;
}
