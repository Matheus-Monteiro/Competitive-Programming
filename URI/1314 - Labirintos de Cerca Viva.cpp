// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Labirintos de Cerca Viva
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1314

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;

vector<vector<int>> G;
int tempo, low[MAX], d[MAX], pai[MAX], peso[MAX], z;
bool cor[MAX];

int find(int x)
{
    return x == pai[x] ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] > peso[y])
        pai[y] = x;
    if(peso[x] < peso[y])
        pai[x] = y;
    if(peso[x] == peso[y])
    {
        peso[y]++;
        pai[x] = y;
    } 
}

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
                join(u, v);
        }
        else if(v != p)
                low[u] = min(low[u], d[v]);
}

bool solve(int u)
{
    cor[u] = true;
    bool flag = (u == z);
    for(int i = 0; i < G[u].size() and !flag; i++)
    {
        int v = G[u][i];
        if(!cor[v] and find(u) == find(v))
            flag = solve(v);
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, u, v, q;
    
    while(cin >> n >> m >> q and (n+m+q))
    {
        G.resize(n+1);
        while(m--)
        {
            cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }	
        for(int i = 0; i < n; i++)
            pai[i] = i, peso[i] = 0;
        memset(cor, 0, sizeof(cor));
        tempo = 0;
	    for(int i = 0; i < n; i++)
	        if(!cor[i])
	            dfs(i, -1);
        while(q--)
        {
            cin >> u >> v;
            u--; v--;
            z = v;
            memset(cor, 0, sizeof(cor));
            cout << (solve(u) ? 'Y' : 'N') << '\n';
        } 
        cout << '-' << '\n';
        G.clear();
    }
    
	return 0;
}
