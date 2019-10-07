#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<array<int, 3>> edge;
int pai[100100], sz[100100];

int find(int x)
{
    return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    pai[x] = y;
    sz[y] += sz[x];
}

int main()
{
    scanf(" %d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf(" %d %d %d", &u, &v, &w); u--; v--;
        edge.push_back({w, v, u});
    }
    for(int i = 0; i < n; i++)
        pai[i] = i, sz[i] = 1;
    int mst_cost = 0;
    bool fl = true;
    while(fl)
    {
        fl = false;
        vector<int> aux(n, -1);
        for(int i = 0; i < m; i++)
        {
            int u = find(edge[i][1]), v = find(edge[i][2]), w = edge[i][0];
            if(u == v) continue;
            if(aux[u] == -1) aux[u] = i;
            else if(edge[aux[u]][0] > w) aux[u] = i;
            if(aux[v] == -1) aux[v] = i;
            else if(edge[aux[v]][0] > w) aux[v] = i;
        }
        for(int i = 0; i < n; i++)
        {
            if(aux[i] == -1) continue;
            int u = find(edge[aux[i]][1]), v = find(edge[aux[i]][2]);
            if(u == v) continue;
            // add_edge edge[aux[i]][1] --- edge[aux[i]][2] in the MST
            join(u, v);
            mst_cost += edge[aux[i]][0];
            fl = true;
        }
    }
    cout << mst_cost << '\n';

    return 0;
}

