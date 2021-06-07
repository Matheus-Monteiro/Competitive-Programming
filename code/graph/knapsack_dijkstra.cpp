#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
#define ii pair<int, int>
#define fi first
#define se second
 
vector<ii> G[105];
int dist[100000008];
vector<int> peso;
 
void dijkstra()
{
	memset(dist, 63, sizeof(dist));
	dist[0] = 0;
	priority_queue<ii> pq;
	pq.push({0, 0});
	while(!pq.empty())
	{
		int u = pq.top().se;
		int d = -pq.top().fi;
		pq.pop();
		if(d > dist[u]) continue;
		for(int i = 0; i < G[u].size(); i++)
		{
			int w = G[u][i].fi, dd = G[u][i].se;
			if(dist[w] > dist[u] + dd)
			{
				dist[w] = dist[u] + dd;
				pq.push({-dist[w], w});
			}
		}
	}
	dist[0] = peso[0];
}
 
int32_t main()
{
	int n, e, d;
	cin >> n >> d >> e;
	// ler pesos
	peso = vector<int>{d, 2 * d, 5 * d, 10 * d, 20 * d, 50 * d, 100 * d,
		5 * e, 10 * e, 20 * e, 50 * e, 100 * e, 200 * e};	
	// ordena pra pegar o menor valor
	sort(peso.begin(), peso.end());
	//montar grafo
	for(int i = 0; i < peso[0]; i++)
		for(int j = 0; j < peso.size(); j++)
		{
			int x = (i + peso[j]) % peso[0];
			G[i].push_back({x, peso[j]});
		}
	/*
		dist[i] eh o menor numero que eu consigo formar usando
		os meus objetos tal que dist[i] % peso[0] == i
	*/
	dijkstra();
	
	/*
		se dist[X % peso[0]] <= X eh possivel gerar um valor X
		utilizando os valores do array peso
		OBS: cada valor pode ser usado infinitas vezes
	*/
	return 0;
}
