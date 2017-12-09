// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O País das Bicicletas
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1454

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, max_log;
vector<iii> G;
vector<ii> mst[MAX];
int anc[MAX][30], max_edge[MAX][30], depth[MAX], pai[MAX];

int find(int x)
{
    return x == pai[x] ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    pai[find(x)] = find(y);
}

void dfs(int v, int d, int p, int a)
{
    anc[v][0] = p;
    depth[v] = d;
    if(d) max_log = max(max_log, (int)log2(d));
    if(p != -1) max_edge[v][0] = a;
    for(int i = 0; i < mst[v].size(); i++)
    {
        int u = mst[v][i].second, w = mst[v][i].first;
        if(u != p)
            dfs(u, d + 1, v, w);
    }  
}

void build()
{
    max_log = 0;
    memset(anc, -1, sizeof(anc));
    memset(max_edge, -1, sizeof(max_edge));
    dfs(0, 0, -1, -1);
    for(int j = 1; j <= max_log; j++)
        for(int i = 0; i < n; i++)
            if(anc[i][j-1] != -1)
            {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                max_edge[i][j] = max(max_edge[i][j-1], max_edge[anc[i][j-1]][j-1]);
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

int queryMaxEdge(int u, int v)
{
    int LCA = lca(u, v);
    int ans = INT_MIN;
    int k = depth[u]-depth[LCA];
    while(k)
    {
        ans = max(ans, max_edge[u][(int)log2(k&-k)]);
        u = walk(u, k&-k);
        k -= k&-k;
    }
    k = depth[v]-depth[LCA];
    while(k)
    {
        ans = max(ans, max_edge[v][(int)log2(k&-k)]);
        v = walk(v, k&-k);
        k -= k&-k;
    }
    return ans;
}

int main()
{
    int u, v, w, caso = 1, t;

    while(scanf("%d %d", &n, &m) and (n or m))
    {
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            G.push_back({w, {u, v}});
        }
        sort(G.begin(), G.end());
        for(int i = 0; i < n; i++)
            pai[i] = i;
        for(int i = 0; i < m; i++)
        {
            w = G[i].first;
            u = G[i].second.first;
            v = G[i].second.second;
            if(find(u) != find(v))
            {
                mst[u].push_back({w, v});
                mst[v].push_back({w, u});
                join(u, v);
            }
        }
        build();
        int q;
        printf("Instancia %d\n", caso++);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &u, &v);
            if(u != v)
                printf("%d\n", queryMaxEdge(u-1, v-1));
            else
                printf("0\n");
        }
        printf("\n");
        G.clear();
        for(int i = 0; i < n; i++)
            mst[i].clear();
    }
    
    return 0;
}
