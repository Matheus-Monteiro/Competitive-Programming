// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tipos Analógimôn
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2562

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G; 
vector<bool> cor;

void dfs(int v)
{
    cor[v] = true;
    for(int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i];
        if(!cor[u])
            dfs(u);
    }
}

int main()
{
    int u, v;
    
    while(cin >> n >> m)
    {
        G.resize(n+1);
        cor.resize(n+1);
        while(m--)
        {
            cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cin >> u;
        dfs(u-1);
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(cor[i])
                ans++;
        cout << ans << '\n';
        G.clear();
        cor.clear();
    }
    return 0;
}

