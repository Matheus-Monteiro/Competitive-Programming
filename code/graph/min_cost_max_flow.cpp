/*
 *  from IME Library
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3;
const int OO = 0x3f3f3f3f;
 
struct edge {int v, f, w, c; };
 
// flw_lmt eh a quantidade de de fluxo que posso passar
// no maximo, alterar se necessario
// node_count eh o valor do maior vertice no grafo...
// inicializar node_count com numero de vertices no inicio...
int node_count, flw_lmt = OO, p[MAX];
vector<edge> edges;
vector<int> G[MAX];

// u--->v, custo w e capacidade c
void add_edge(int u, int v, int w, int c)
{
	int k = edges.size();
	node_count = max(node_count, u+1);
	node_count = max(node_count, v+1);
	G[u].push_back(k);
	G[v].push_back(k+1);
	edges.push_back({ v, 0,  w, c });
	edges.push_back({ u, 0, -w, 0 });
}

void clear()
{
	flw_lmt = OO;
	for(int i = 0; i < node_count; ++i) G[i].clear();
	edges.clear();
	node_count = 0;
}
 
bool SPFA(int s, int t)
{
	vector<int> dist(node_count, OO);
	vector<int> et(node_count, 0);
	deque<int> q;
	q.push_back(s), dist[s] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop_front();
		et[u] = 2;
		for(int i : G[u])
		{
			edge &e = edges[i];
			int v = e.v;
			if (e.f < e.c and dist[v] > dist[u] + e.w)
			{
				dist[v] = dist[u] + e.w;
				if (et[v] == 0) q.push_back(v);
				else if (et[v] == 2) q.push_front(v);
				et[v] = 1;
				p[v] = i;
			}
      		}
	}
	return dist[t] != OO;
}
 
int min_cost_max_flow(int s, int t)
{
	int mf = 0, cost = 0;
  	while(SPFA(s, t) and mf < flw_lmt)
  	{
		int inc = flw_lmt - mf;
		for (int u = t; u != s; u = edges[p[u]^1].v)
		{
			edge &e = edges[p[u]];
			inc = min(inc, e.c - e.f);
		}
		for (int u = t; u != s; u = edges[p[u]^1].v)
		{
			edge &e = edges[p[u]], &rev = edges[p[u]^1];
			e.f += inc;
			rev.f -= inc;
			cost += inc * e.w;
		}
    		if (!inc) break;
    		mf += inc;
	}
	cout << "Max Flow " << mf << '\n';
	cout << "Min Cost " << cost << '\n';
	return cost;
}
 
int main()
{
	
 
	return 0;
} 
