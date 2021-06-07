//COT - Count on a tree (SPOJ)
//Em cada vertice existe um valor
//A resposta para uma query eh quantos valores
//distintos existem no caminho de u a v
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6; 
 
typedef long long ll;
 
struct Query
{
    int x, y, l, r, lc, res;
};
 
int n, q, max_log, tempo, blk, ans;
vector<int> G[MAX];
int value[MAX], pos[MAX], anc[MAX][25], depth[MAX];
int tl[MAX], ST[MAX], EN[MAX], freq[MAX], node[MAX];
Query Q[MAX];
ll arr[MAX];
 
void dfs(int v, int p, int d)
{
    anc[v][0] = p;
    depth[v] = d;
    tl[tempo] = v;
    ST[v] = tempo++;
    if(d) max_log = max(max_log, (int)log2(d));
    for(const int &u : G[v])
        if(u != p)
            dfs(u, v, d + 1);
    tl[tempo] = v;
    EN[v] = tempo++;
}
 
int walk(int v, int k)
{
    while(k) v = anc[v][(int)log2(k&-k)], k -= k&-k;
    return v;
}
 
int lca(int u, int v)
{
    if(depth[u] > depth[v]) u = walk(u, depth[u] - depth[v]);
    if(depth[u] < depth[v]) v = walk(v, depth[v] - depth[u]);
    if(u == v) return u;
    for(int i = max_log; i >= 0; i--)
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    return anc[u][0];
}
 
void build()
{
    memset(anc, -1, sizeof(anc));
    dfs(0, -1, 0);
    for(int j = 1; j <= max_log; j++)
        for(int i = 0; i < n; i++)
            if(anc[i][j-1] != -1)
                anc[i][j] = anc[anc[i][j-1]][j-1];
}
 
inline void mo(int i)
{
    int u = tl[i];
    if(node[u] and --freq[value[u]] == 0) ans--;
    else if(!node[u] and ++freq[value[u]] == 1) ans++;
    node[u] ^= 1;
}
 
bool compare(int a, int b)
{
    if(Q[a].l/blk != Q[b].l/blk)
        return Q[a].l < Q[b].l;
    return Q[a].r > Q[b].r;
}
 
int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)//values
        scanf("%d", &arr[i]), pos[i] = i;
        
    sort(pos, pos + n, [](ll a, ll b){return arr[a] < arr[b];});
    for(int i = 0, j = 1; i < n; i++)
        if(!i)
            value[pos[i]] = j++;
        else if(arr[pos[i]] != arr[pos[i-1]])
            value[pos[i]] = j++;
        else value[pos[i]] = value[pos[i-1]];
        
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    build();
    
    for(int i = 0; i < q; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--; 
        if(ST[u] > ST[v]) swap(u, v);
        Q[i].lc = lca(u, v);
        Q[i].x = u, Q[i].y = v;
        if(u == Q[i].lc)
            Q[i].l = ST[u], Q[i].r = ST[v];
        else
            Q[i].l = EN[u], Q[i].r = ST[v];
        pos[i] = i;
    }
 
    blk = sqrt(tempo);
    sort(pos, pos + q, compare);
 
    int curL = 0, curR = 0;
    for(int i = 0; i < q; i++)
    {
        int L = Q[pos[i]].l, R = Q[pos[i]].r;
        while(curL < L)
            mo(curL++);
        while(curL > L)
            mo(--curL);
        while(curR < R + 1)
            mo(curR++);
        while(curR > R + 1)
            mo(--curR);
 
        if(Q[pos[i]].x != Q[pos[i]].lc)
            mo(ST[Q[pos[i]].lc]);
        Q[pos[i]].res = ans;
        if(Q[pos[i]].x != Q[pos[i]].lc)
            mo(ST[Q[pos[i]].lc]);
    }
    for(int i = 0; i < q; i++)
        printf("%d\n", Q[i].res);
 
    return 0;
} 
