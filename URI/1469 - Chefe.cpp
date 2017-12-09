// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Chefe
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1469

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;
int cor[100000], age[100000];
int ans, _v;

void troca(int u, int v)
{
    vector<int> tmp1 = G[v], tmp2 = G[u];
    G[u].clear(); G[v].clear();
    for(int i = 0; i < tmp1.size(); i++)
        G[u].push_back(tmp1[i]);
    for(int i = 0; i < tmp2.size(); i++)
        G[v].push_back(tmp2[i]);
    vector<pair<int, int>> pu, pv;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < G[i].size(); j++)
        {
            if(G[i][j] == u)
                pu.push_back({i, j});
            if(G[i][j] == v)
                pv.push_back({i, j});
        }
    }
    for(int i = 0; i < pu.size(); i++)
        G[pu[i].first][pu[i].second] = v;
    for(int i = 0; i < pv.size(); i++)
        G[pv[i].first][pv[i].second] = u;
}

void dfs(int v)
{
    if(_v != v) ans = min(ans, age[v]);
    cor[v] = 1;
    for(int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i];
        if(!cor[u])
            dfs(u);
    }
}

int main()
{
    int u, v, k;  
         
    while(cin >> n >> m >> k)
    {
        G.resize(n+2);
        for(int i = 0; i < n; i++)
            cin >> age[i];
        while(m--)
        {
            cin >> u >> v;
            G[v-1].push_back(u-1);
        }
        char c;
        while(k--)
        {
            cin >> c;
            if(c == 'T')
            {
                cin >> u >> v;
                troca(u-1, v-1);
            }
            else
            {
                cin >> v;
                memset(cor, 0, sizeof(cor));
                ans = INT_MAX;
                _v = v-1;  
                dfs(_v);
                if(ans == INT_MAX)
                    cout << '*' << '\n';
                else
                    cout << ans << '\n';         
            }
        }
        G.clear();
    }    
    return 0;
}
