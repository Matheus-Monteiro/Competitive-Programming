// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Imposto Real
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2666

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;

#define fi first
#define se second

typedef pair<int, int> ii;

int n, c, ans;
vector<ii> G[MAX];
int gold[MAX];

void dfs(int v, int p)
{
    for(int i = 0; i < G[v].size(); i++)
    {
        int u = G[v][i].se, d = G[v][i].fi;
        if(u != p)
        {
            ans += d;
            dfs(u, v);
            ans += (d*(2*ceil((double)gold[u]/(double)c)-1));
        }
    }
    gold[p] += gold[v];
}

int main()
{
    int u, v, w;
    
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> gold[i];
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    dfs(1, 0);
    cout << ans << '\n';
    
	return 0;
}
