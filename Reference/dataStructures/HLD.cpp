#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

// Heavy-Light Decomposition
vector<int> adj[MAX];
int par[MAX], h[MAX];

int chainno, chain[MAX], head[MAX], chainpos[MAX],;
int chainsz[MAX], pos[MAX], arrsz;
int sc[MAX], sz[MAX];

void dfs(int u)
{
    sz[u] = 1, sc[u] = 0; // nodes 1-indexed (0-ind: sc[u]=-1)
    for(int v : adj[u])
        if(v != par[u])
        {
            par[v] = u, h[v] = h[u]+1, dfs(v);
            sz[u]+=sz[v];
            if(sz[sc[u]] < sz[v]) sc[u] = v; // 1-indexed (0-ind: sc[u]<0 or ...)
        }
}

void hld(int u)
{
    if(!head[chainno]) head[chainno] = u; // 1-indexed
    chain[u] = chainno;
    chainpos[u] = chainsz[chainno];
    chainsz[chainno]++;
    pos[u] = ++arrsz;
    if(sc[u]) hld(sc[u]);
    for(int v : adj[u]) if(v != par[u] and v != sc[u]) chainno++, hld(v);
}

int lca(int u, int v)
{
    while(chain[u] != chain[v])
    {
        if(h[head[chain[u]]] < h[head[chain[v]]]) swap(u, v);
        u = par[head[chain[u]]];
    }
    if(h[u] > h[v]) swap(u, v);
    return u;
}

/*int query_up(int u, int v)
{
    if(u == v) return 0;
    int ans = -1;
    while(true)
    {
        if(chain[u] == chain[v])
        {
            if (u == v) break;
            ans = max(ans, query(1, 1, n, chainpos[v]+1, chainpos[u]));
            break;
        }
        ans = max(ans, query(1, 1, n, chainpos[head[chain[u]]], chainpos[u]));
        u = par[head[chain[u]]];
    }
    return ans;
}

int query(int u, int v)
{
    int l = lca(u, v);
    return max(query_up(u, l), query_up(v, l));
}*/

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);             
    }
    dfs(1);
    hld(1);
    for(int i = 1; i <= n; i++) 
        cout << chain[i] << ' ';
    puts("");
    for(int i = 1; i <= n; i++) 
        cout << chainpos[i] << ' ';
    puts("");

    return 0;
}

///////////////////////////////////////////////////
//Heavy Light Decomposition para encontrar a maior aresta no
// caminho de u para v em uma arvore

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

// Heavy-Light Decomposition
vector<int> adj[MAX], W[MAX];
int par[MAX], h[MAX];
map<pair<int, int>, int> number_edge; 
int chainno, chain[MAX], head[MAX], A[MAX], pos[MAX];
int sc[MAX], sz[MAX], weight[MAX], st[MAX], edge_counted, n;

void dfs(int u)
{
    sz[u] = 1, sc[u] = 0; // nodes 1-indexed (0-ind: sc[u]=-1)
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i], w = W[u][i];
        if(v != par[u])
        {
            weight[v] = w, par[v] = u, h[v] = h[u] + 1, dfs(v);
            sz[u]+=sz[v];
            if(sz[sc[u]] < sz[v]) sc[u] = v; // 1-indexed (0-ind: sc[u]<0 or ...)
        }
    }
}

void hld(int u)
{
    if(!head[chainno]) head[chainno] = u; // 1-indexed
    chain[u] = chainno;
    pos[u] = edge_counted;
    A[edge_counted++] = weight[u];
    if(sc[u]) hld(sc[u]);
    for(int v : adj[u]) 
        if(v != par[u] and v != sc[u]) 
        {
            number_edge[{u, v}] = edge_counted;
            chainno++, hld(v);
        }
}

int lca(int u, int v)
{
    while(chain[u] != chain[v])
    {
        if(h[head[chain[u]]] < h[head[chain[v]]]) swap(u, v);
        u = par[head[chain[u]]];
    }
    if(h[u] > h[v]) swap(u, v);
    return u;
}

void build(int node, int start, int end)
{
    if(start == end)
        st[node] = A[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        st[node] = max(st[2 * node], st[2 * node + 1]);
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(l > end or start > r)
        return -1;
    if(l <= start and end <= r)
        return st[node];
    int mid = (start + end) / 2;
    int q1 = query(2 * node, start, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);
    return max(q1, q2);
}

void update(int node, int start, int end, int idx, int value)
{
    if(start == end)
        st[node] = A[idx] = value;
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2 * node, start, mid, idx, value);
        else
            update(2 * node + 1, mid + 1, end, idx, value);
        st[node] = max(st[2 * node], st[2 * node + 1]);
    }
}

int query_up(int u, int v)
{
    if(u == v) return 0;
    int ans = -1;
    while(true)
    {
        if(chain[u] == chain[v])
        {
            if(u == v) break;
            ans = max(ans, query(1, 0, n-1, pos[v] + 1, pos[u]));
            break;
        }
        ans = max(ans, query(1, 0, n-1, pos[head[chain[u]]], pos[u]));
        u = par[head[chain[u]]];
    }
    return ans;
}

int queryMaxEdge(int u, int v)
{
    int l = lca(u, v);
    return max(query_up(u, l), query_up(v, l));
}

void updateEdge(int u, int v, int value)
{
    int idx;
    if(number_edge.find({u, v}) != number_edge.end())
        idx = number_edge[{u, v}];
    else
        idx = number_edge[{v, u}];
    update(1, 0, n-1, idx, value);
}

int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u); 
        W[u].push_back(w);
        W[v].push_back(w);
    }
    weight[1] = -1;
    dfs(1);
    hld(1);
    build(1, 0, n-1);
    int x, y, o;
    while(cin >> o >> x >> y)
    {
        if(o == 1)
            cout << queryMaxEdge(x, y) << '\n';
        else
        {
            int w; cin >> w;
            updateEdge(x, y, w);
        }
    }
    return 0;
}
