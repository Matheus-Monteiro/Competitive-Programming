// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Futebol
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1495

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4;
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<ii> v;
int n, g, a, b, p;

int main()
{
    while(~scanf("%d %d", &n, &g))
    {
        p = 0;
        REP(i, n)
        {
            scanf("%d %d", &a, &b);
            if(a > b) p += 3;
            if(a == b) p += 1;
            if(a <= b) v.pb({a, b});
        }
        sort(v.begin(), v.end(), [](ii a, ii b){return (a.se-a.fi) < (b.se-b.fi);});
        REP(i, v.size())
        {
            if(!g) break;
            if(v[i].fi == v[i].se)
                p += 2, g--;
            else if(g >= (v[i].se-v[i].fi+1))
                p += 3, g -= (v[i].se-v[i].fi+1);
            else if(g >= (v[i].se-v[i].fi))
                p++, g -= (v[i].se-v[i].fi);
        }
        printf("%d\n", p);
        v.clear(); 
    }
    
	return 0;
}
