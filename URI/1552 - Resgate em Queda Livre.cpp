// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Resgate em Queda Livre
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1552

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
typedef pair<double, ii> dii;

int t, n, a, b;
vector<dii> G;
vector<ii> v;
int pai[100000], peso[100000];

int find(int x)
{
	return x == pai[x] ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);
	if(peso[x] > peso[y])
		pai[y] = x;
	else if(peso[x] < peso[y])
		pai[x] = y;
	else
		pai[x] = y, peso[y]++;
}

double dist(int a, int b, int _a, int _b)
{
	return hypot(a-_a, b-_b);
}

int main()
{
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);
		int _n = n;
		while(_n--)
		{
			scanf("%d %d", &a, &b);
			v.push_back({a, b});
		}
		for(int i = 0; i < v.size(); i++)
			for(int j = i+1; j < v.size(); j++)
				G.push_back({dist(v[i].fi, v[i].se, v[j].fi, v[j].se), {i, j}});

		sort(G.begin(), G.end());

		for(int i = 0; i <= n; i++)
			pai[i] = i, peso[i] = 0;

		double ans = 0;
		int u, z;
		double w;
		for(int i = 0; i < G.size(); i++)
		{
			w = G[i].fi;
			u = G[i].se.fi;
			z = G[i].se.se;
			if(find(u) != find(z))
			{
				join(u, z);
				ans += w;
			}
		}
		printf("%.2lf\n", ans/100.0);
		G.clear();
		v.clear();
	}
	
	return 0;
}
