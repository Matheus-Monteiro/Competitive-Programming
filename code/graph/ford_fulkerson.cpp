#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int OO = 0x3f3f3f3f;
const int MAX = 1e4;

struct edge
{
    int v, f, c;
    edge(){}
    edge(int _v, int _f, int _c)
    {
        v = _v, f = _f, c = _c;
    }
};

vector<edge> edges;
vector<int> G[MAX];
int tempo = 1, cor[MAX];

void add_edge(int u, int v, int cp, int rc)
{
    edges.push_back(edge(v, 0, cp));
    G[u].push_back(edges.size()-1);
    edges.push_back(edge(u, 0, rc));
    G[v].push_back(edges.size()-1);
}

int dfs(int s, int t, int f)
{
    if(s == t) return f;
    cor[s] = tempo;
    for(int e : G[s])
        if(cor[edges[e].v] < tempo and edges[e].c-edges[e].f > 0)
            if(int a = dfs(edges[e].v, t, min(f, edges[e].c-edges[e].f)))
            {
                edges[e].f += a;
                edges[e^1].f -= a;
                return a;
            }
    return 0;
}

int MaxFlow(int s, int t)
{
    int mf = 0;
    while(int a = dfs(s, t, OO))
        mf += a, tempo++;
    return mf;
}

int main()
{
    int n, m, w, u, v;
    
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        add_edge(u-1, v-1, w, 0);
    }
    cin >> u >> v;
    cout << MaxFlow(u-1, v-1) << '\n';

    return 0;
}
