// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Espaço de Projeto
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2683

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
vector<iii> G;
int pai[MAX];

int find(int x)
{
	return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
	pai[find(x)] = find(y);
}

int main()
{
	int u, v, w;
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> u >> v >> w; u--; v--;
		G.push_back({w, {u, v}});
	}
	sort(G.begin(), G.end());
	int maxi = 0, mini = 0;
	
	for(int i = 0; i < n; i++)
		pai[i] = i;
	for(int i = 0; i < n; i++)
	{
		u = G[i].second.first;
		v = G[i].second.second;
		w = G[i].first;
		if(find(u) != find(v))
		{
			mini += w;
			join(u, v);
		}
	}
	for(int i = 0; i < n; i++)
		pai[i] = i;
	for(int i = n-1; i >= 0; i--)
	{
		u = G[i].second.first;
		v = G[i].second.second;
		w = G[i].first;
		if(find(u) != find(v))
		{
			maxi += w;
			join(u, v);
		}
	}
	cout << maxi << '\n' << mini << '\n';

	return 0;
}
