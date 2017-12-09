// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ataque Programado
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1792

#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<vector<int>> G;
vector<int> ts, fefe, sol, g;

int main()
{
	while(cin >> n >> m >> s and (n+m+s))
	{
		G.resize(n+1);
		fefe.resize(n+1);	
		sol.resize(n+1);
		g.resize(n+1);
		int buraco = s;
		for(int i = 0; i < n; i++)
			cin >> sol[i];
		for(int i = 0; i < n; i++)
			cin >> fefe[i], buraco += fefe[i];
		int u, v;
		while(m--)
		{
			cin >> u >> v;
			u--; v--;
			g[v]++;
			G[u].push_back(v);
		}
		for(int i = 0; i < n; i++)
			if(!g[i])
			{
				if(s > sol[i])
				{
					s += fefe[i];
					ts.push_back(i);
				}	
			}
		int b = 0;
		while(b < ts.size())
		{
			v = ts[b++];
			for(int i = 0; i < G[v].size(); i++)
			{
				u = G[v][i];
				if(g[u])
					g[u]--;
				if(!g[u])
				{
					if(s > sol[u])
					{
						ts.push_back(u);
						s += fefe[u];
					}
				}
			}
		}
		cout << (s == buraco ? "possivel" : "impossivel") << '\n';
		G.clear();
		fefe.clear();
		sol.clear();
		g.clear();
		ts.clear();
	}
	
	return 0;
}
