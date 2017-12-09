// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cidade no Centro
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2676

#include <bits/stdc++.h>
using namespace std;

const int OO = 0x3f3f3f3f;
const int MAX = 1e5;
const double EPS = 1e-8;

#define bug(x) cout << #x << ' ' << x << '\n';
#define FOR(i, a, n) for(int i = 0; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
vector<ii> G[MAX];
int dist[MAX];

ii dijkstra(int v)
{
    memset(dist, 63, sizeof(dist));
    dist[v] = 0;
    priority_queue<ii> pq;
    pq.push({0, v});
    while(!pq.empty())
    {
        int u = pq.top().se;
        int d = -pq.top().fi;
        pq.pop();
        if(d > dist[u]) continue;
        REP(i, G[u].size())
        {
            int w = G[u][i].se, _d = G[u][i].fi;
            if(dist[w] > d + _d)
            {
                dist[w] = d + _d;
                pq.push({-dist[w], w});
            }
        }
    }
    int sum = 0;
    REP(i, n)
        sum += dist[i];
    return ii(sum, v);
}

int main()
{
    int u, v, w;

    while(scanf("%d %d", &n, &m) and (n or m))
    {    
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w); 
            u--; v--;
            G[u].pb({w, v});
            G[v].pb({w, u});
        }
        
        vector<ii> v;
        
        REP(i, n)
            v.pb(dijkstra(i));
        int mini = OO;
        REP(i, n)
            if(v[i].fi < mini)
                mini = v[i].fi;
        vector<int> ans;
        REP(i, n)
            if(mini == v[i].fi)
                ans.pb(v[i].se+1);
        sort(ans.begin(), ans.end());
        REP(i, ans.size())
            printf("%d ", ans[i]);
        printf("\n");  
        ans.clear();
        REP(i, n) G[i].clear();      
    }  
        
    return 0;
}
