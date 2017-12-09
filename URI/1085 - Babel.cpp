// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Babel
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1085

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


int n;
vector<iii> G[MAX];
int dist[MAX][28];
map<string, int> mp;

int dijkstra(int v, int z)
{
	priority_queue<iii> pq;
	memset(dist, 63, sizeof(dist));
	REP(i, 26)
		dist[v][i] = 0;
	pq.push({0, {-1, v}});
	while(!pq.empty())
	{
		int u = pq.top().se.se;
		int d = -pq.top().fi;
		int c = pq.top().se.fi;
		pq.pop();
		if(c != -1 and d > dist[u][c]) continue;
		REP(i, G[u].size())
		{
			int w = G[u][i].se.se, _d = G[u][i].fi, _c = G[u][i].se.fi;
			if(dist[w][_c] > d + _d and c != _c)
			{
				dist[w][_c] = d + _d;
				pq.push({-dist[w][_c], {_c, w}});
			}
		}
	}
	int ans = OO;
	REP(i, 26)
		ans = min(ans, dist[z][i]);	
	return ans;	
}

int main()
{
	ios_base::sync_with_stdio(false);

	string u, v, w, o, d;

	while(cin >> n and n)
	{
		int id = 0, _u, _v;
		cin >> o >> d;
		mp[o] = id++;
		if(o != d)
			mp[d] = id++;
		REP(i, n)
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
			G[_u].pb({w.size(), {w[0]-'a', _v}});
			G[_v].pb({w.size(), {w[0]-'a', _u}});
		}
		int ans = dijkstra(mp[o], mp[d]);
		if(ans == OO)
			cout << "impossivel" << '\n';
		else
			cout << ans << '\n';
		REP(i, n)
			G[i].clear();
		mp.clear();
	}
	
	return 0;
}
