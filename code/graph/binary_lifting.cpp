#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

int n, m, nivel[MAX], anc[MAX][30], MAX_LOG;
vector<int> G[MAX];

void dfs(int v, int p, int d)
{
    anc[v][0] = p;
    nivel[v] = d;
    if(d) MAX_LOG = max(MAX_LOG, (int)log2(d));
    for(const int &u : G[v])
        if(u != p)
            dfs(u, v, d + 1);
}

int walk(int v, int k)
{
    while(k) v = anc[v][(int)log2(k&-k)], k -= k&-k;;
    return v;
}

int lca(int u, int v)
{
    if(nivel[u] < nivel[v]) v = walk(v, nivel[v]-nivel[u]);
    if(nivel[u] > nivel[v]) u = walk(u, nivel[u]-nivel[v]);
    if(u == v) return u;
    for(int i = MAX_LOG; i >= 0; i--)
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    return anc[u][0];        
}

void build()
{
    memset(anc, -1, sizeof anc);
    nivel[0] = 0;
    dfs(0, -1, 0);
    for(int j = 1; j <= MAX_LOG; j++)
        for(int i = 1; i <= n; i++)
            if(anc[i][j-1] != -1)
                anc[i][j] = anc[anc[i][j-1]][j-1];
}

int main()
{
    int u, v;
    
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    build();    
    cin >> u >> v;    
    cout << lca(u-1, v-1)+1 << '\n';
    
    return 0;
}


//////////////////////////////////////////////


#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
typedef pair<int, int> ii;

int n, m, max_log;
vector<ii> G[MAX];
int anc[MAX][30], min_edge[MAX][30], depth[MAX];

void dfs(int v, int d, int p, int a)
{
    anc[v][0] = p;
    depth[v] = d;
    if(d) max_log = max(max_log, (int)log2(d));
    if(p != -1) min_edge[v][0] = a;
    for(int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i].second, w = G[v][i].first;
        if(u != p)
            dfs(u, d + 1, v, w);
    }  
}

void build()
{
    memset(anc, -1, sizeof(anc));
    memset(min_edge, 63, sizeof(min_edge));
    dfs(0, 0, -1, -1);
    for(int j = 1; j <= max_log; j++)
        for(int i = 0; i < n; i++)
        {
            if(anc[i][j-1] != -1)
            {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                min_edge[i][j] = min(min_edge[i][j-1], min_edge[anc[i][j-1]][j-1]);
            }
        }
}

int walk(int v, int k)
{
    while(k) v = anc[v][(int)log2(k&-k)], k -= k&-k;
    return v;
}

int lca(int u, int v)
{
    if(depth[u] > depth[v]) u = walk(u, depth[u]-depth[v]);
    if(depth[u] < depth[v]) v = walk(v, depth[v]-depth[u]);
    if(u == v) return u;
    for(int i = max_log; i >= 0; i--)
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    return anc[u][0];
}

int queryMinEdge(int u, int v)
{
    int LCA = lca(u, v);
    int ans = INT_MAX;
    int k = depth[u]-depth[LCA];
    while(k)
    {
        ans = min(ans, min_edge[u][(int)log2(k&-k)]);
        u = walk(u, k&-k);
        k -= k&-k;
    }
    k = depth[v]-depth[LCA];
    while(k)
    {
        ans = min(ans, min_edge[v][(int)log2(k&-k)]);
        v = walk(v, k&-k);
        k -= k&-k;
    }
    return ans;
}

int main()
{
    int u, v, w;

    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    cin >> u >> v;
    build();
    cout << lca(u-1, v-1)+1 << '\n';
    cout << queryMinEdge(u-1, v-1) << '\n';

    return 0;
}
