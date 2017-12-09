// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Produção em Ecaterimburgo
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2115

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

int n;
vector<ii> v;

int main()
{
    while(~scanf("%d", &n))
    {
        REP(i, n)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            v.pb({x, y});
        }
        sort(v.begin(), v.end());
        int m = 1;
        REP(i, n)
            if(v[i].fi <= m)
                m += v[i].se;
            else
                m += (v[i].fi - m) + v[i].se;
        printf("%d\n", m);
        v.clear();
    }
    return 0;
}
