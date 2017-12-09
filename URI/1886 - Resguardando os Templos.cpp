// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Resguardando os Templos
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1886

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define gc getchar_unlocked

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct Edge
{
    int v, f, c;
    Edge(int _v, int _f, int _c)
    {
        v = _v, f = _f, c = _c;
    }
};

int cor[MAX];
int t, n, m, tempo;
vector<Edge> edge;
vector<vector<int>> adj;

void addEdge(int u, int v, int c, int cr)
{
    adj[u].pb(edge.size());
    edge.pb(Edge(v, 0, c));
    adj[v].pb(edge.size());
    edge.pb(Edge(u, 0, 0));
}

void toColor(int v, int c)
{
    cor[v] = c;
    REP(i, adj[v].size())
    {
        int e = adj[v][i];
        int u = edge[e].v;
        if(!cor[u])
            toColor(u, c == 1 ? 2 : 1);
    }
}

int dfs(int s, int t, int f)
{
    if(s == t)
        return f;
    cor[s] = tempo;
    for(const int &e : adj[s]) 
        if(cor[edge[e].v] < tempo and edge[e].c - edge[e].f > 0)
            if(int a = dfs(edge[e].v, t, min(f, edge[e].c - edge[e].f)))
            {
                edge[e].f += a;
                edge[e^1].f -= a;                
                return a;
            }
    return 0;
}

int maxFlow(int s, int t)
{
    int mf = 0;
    while(int a = dfs(s, t, OO))
        mf += a, tempo++;
    return mf;    
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        adj.resize(n+3);
        int u, v;
        REP(i, m)
        {
            scanf("%d %d", &u, &v);
            addEdge(u, v, 1, 0);
        }
        tempo = 3;
        memset(cor, 0, sizeof(cor));
        toColor(u, 1);
        FOR(i, 1, n+1)
            if(cor[i] == 1)
                addEdge(0, i, 1, 0);
        FOR(i, 1, n+1)
            if(cor[i] == 2)
                addEdge(i, n+1, 1, 0);
        int ans = n - maxFlow(0, n+1);
        printf("%d\n", ans);
        adj.clear();
        edge.clear();
    }

	return 0;
}
