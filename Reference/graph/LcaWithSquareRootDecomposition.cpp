#include <bits/stdc++.h>
const int MAX = 50500;

using namespace std;

vector<int> G[MAX];
int nivel[MAX], pai[MAX], jump[MAX], n, blk_sz;

void dfs(int v, int d, int p)
{
    pai[v] = p;
    nivel[v] = d;
    (nivel[v]%blk_sz == 0) ? jump[v] = pai[v] : jump[v] = jump[p];
    for(const int &u : G[v])
        if(u != p)
            dfs(u, d + 1, v);
}

int lcaTrivial(int u, int v)
{
    while(u != v)
        (nivel[u] > nivel[v]) ? u = pai[u] : v = pai[v];
    return u;
}


int lca(int u, int v)
{
    while(jump[u] != jump[v])
        (nivel[u] > nivel[v]) ? u = jump[u] : v = jump[v];
    return lcaTrivial(u, v);
}

void build()
{
    blk_sz = sqrt(n);
    dfs(0, 0, 0);
}

int main()
{
    int x, y;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    build();
    cin >> x >> y;
    cout << lca(x-1, y-1) + 1 << '\n'; 

    return 0;
}
