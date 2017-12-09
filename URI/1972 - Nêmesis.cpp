// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Nêmesis
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1972

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int OO = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
string G[510];
int dist[510][510];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
set<ii> s;
priority_queue<iii> pq;

int dijkstra(int r, int c)
{
	memset(dist, 63, sizeof(dist));
	dist[r][c] = 0;
	pq.push({0, {r, c}});
	while(!pq.empty())
	{
		int d = -pq.top().fi;
		r = pq.top().se.fi;
		c = pq.top().se.se;
		pq.pop();
		if(s.find({r, c}) != s.end())
			continue;
		if(G[r][c] == 'E')
			return d; 
		for(int i = 0; i < 4; i++)
		{
			int u = r+dr[i], v = c+dc[i];
			if(u < n and u >= 0 and v < m and v >= 0 and G[u][v] != '#')
			{
				if(G[u][v] >= '0' and G[u][v] <= '9')
				{
					int _d = G[u][v] - '0';
					if(dist[u][v] >= d + _d)
					{
						dist[u][v] = d + _d;
						pq.push({-dist[u][v], {u, v}});
					}
				}
				else if(G[u][v] == '.' or G[u][v] == 'E')
				{
					dist[u][v] = d;
					pq.push({-dist[u][v], {u, v}});
				}
			}
		}
		s.insert({r, c});
	}
	return OO;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> G[i];
	int u = -1, v;
	for(int i = 0; i < n and u == -1; i++)
		for(int j = 0; j < m and u == -1; j++)
			if(G[i][j] == 'H')
				u = i, v = j;
	int ans = dijkstra(u, v);
	if(ans == OO) cout << "ARTSKJID" << '\n';
	else cout << ans << '\n';

	return 0;
}
