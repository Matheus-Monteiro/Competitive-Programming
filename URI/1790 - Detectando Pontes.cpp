// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Detectando Pontes
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1790

#include <bits/stdc++.h>
using namespace std;

int n, m, tempo, ans;
vector<vector<int>> G;
int cor[55], d[55], low[55];

void dfs(int u, int p)
{
    cor[u] = 1;
    d[u] = low[u] = tempo++;
    for(int v : G[u])
        if(!cor[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > d[u])
                ans++;
        }
        else if(v != p)
            low[u] = min(low[u], d[v]);
}

int main()
{
    int u, v;
    while(cin >> n >> m)
    {
        G.resize(n);
        while(m--)
        {
            cin >> u >> v;
            G[u-1].push_back(v-1);
            G[v-1].push_back(u-1);
        }
        ans = tempo = 0;
        memset(cor, 0, n*sizeof(int));
        dfs(0, -1);
        cout << ans << '\n';
        G.clear();
    }
	return 0;
}
