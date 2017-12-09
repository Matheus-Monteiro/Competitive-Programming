// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Rede Ótica
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2190

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> G;
vector<ii> mst;
int pai[1000], sz[1000];

int find(int x)
{
	return x == pai[x] ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(sz[x] > sz[y])
		swap(x, y);
	pai[x] = y;
	sz[y] += sz[x];
}

int main()
{
	int n, m, caso = 1;
	
	while(cin >> n >> m and (n or m))
	{
		int u, v, w;
		for(int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			G.push_back({w, {u-1, v-1}});
		}
		for(int i = 0; i <= n; i++)
			pai[i] = i, sz[i] = 1;
		sort(G.begin(), G.end());
		for(int i = 0; i < m; i++)
		{
			u = G[i].second.first;
			v = G[i].second.second;
			w = G[i].first;
			if(find(u) != find(v))
			{
				join(u, v);
				if(u > v)
					swap(u, v);
				mst.push_back({u, v});
			}
		}
		cout << "Teste " << caso++ << '\n';
		for(int i = 0; i < mst.size(); i++)
			cout << mst[i].first+1 << ' ' << mst[i].second+1 << '\n';
		cout << '\n';
		G.clear();
		mst.clear();
	}

	return 0;
}
