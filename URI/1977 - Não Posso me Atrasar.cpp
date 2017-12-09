// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Não Posso me Atrasar
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1977

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4;
const int OO = 0x3f3f3f3f;

#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<int, ii> iii;


int x, m, n;
map<string, int> mp; 
vector<ii> G[MAX];
int dist[MAX];

int dijkstra(int v, int z)
{
	priority_queue<ii> pq;
	memset(dist, 63, n*sizeof(int));
	pq.push({0, v});
	dist[v] = 0;
	while(!pq.empty())
	{
		int u = pq.top().se;
		int d = -pq.top().fi;
		pq.pop();
		if(d > dist[u]) continue;
		if(z == u) return dist[u];
		REP(i, G[u].size())
		{
			int w = G[u][i].se, _d = G[u][i].fi;
			if(dist[w] > d + _d)
			{
				dist[w] = d + _d;
				pq.push({-dist[w], w});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	string u, v;
	int w;

	while(cin >> x >> m >> n and (n+m+x))
	{
		int _u, _v, id = 0;
		while(m--)
		{
			cin >> u >> v >> w;
			if(mp.find(u) == mp.end())
				mp[u] = id, _u = id++;
			else
				_u = mp[u];
			if(mp.find(v) == mp.end())
				mp[v] = id, _v = id++;
			else
				_v = mp[v];
			G[_u].pb({w, _v});
		}
		if(x > 30)
			x = 50;
		else
			x = 30;
		x += dijkstra(mp["varzea"], mp["alto"]);
		int h = x/60;
		x -= h*60;
		h += 17;
		cout << (h%24 < 10 ? "0" : "") << (h%24) << ':' << (x < 10 ? "0" : "") << x << '\n';
		if(h > 17 and x > 0)
			cout << "Ira se atrasar" << '\n';
		else
			cout << "Nao ira se atrasar" << '\n';
		mp.clear();
		REP(i, n)
			G[i].clear();
	}
	return 0;
}
