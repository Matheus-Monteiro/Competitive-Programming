#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MAX = 300;
const int OO = 0x3f3f3f3f;

typedef pair<int, int> ii;

struct edge
{
    int v, f, c, cost;
    edge(){}
    edge(int _v, int _f, int _c, int _cost)
    {
        v = _v, f = _f, c = _c, cost = _cost;
    }
};

int n, m;
vector<edge> edges;
vector<int> G[MAX];
int dist[MAX], pai[MAX], ant[MAX];

void add_edge(int u, int v, int cp, int rc, int cost)
{
    edges.push_back(edge(v, 0, cp, cost));
    G[u].push_back(edges.size()-1);
    edges.push_back(edge(u, 0, rc, cost));
    G[v].push_back(edges.size()-1);
}

bool dijkstra(int s, int t)
{
	memset(dist, 63, sizeof(dist));
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq; 
	pq.push({0, s});
	while(!pq.empty())
	{
		int u = pq.top().se, d = pq.top().fi;
		pq.pop();
		if(dist[u] < d) continue;
		for(int &e : G[u])
			if(edges[e].c - edges[e].f > 0)
			{
				int w = edges[e].v, dd = edges[e].cost;
				if(dist[w] > d + dd)
				{
					pai[w] = u;
					ant[w] = e;
					dist[w] = d + dd;
					pq.push({dist[w], w});
				}
			}
	}
	return dist[t] != OO;
}

void MCMF(int s, int t)
{
	int mf = 0, mcmf = 0;
	while(dijkstra(s, t))
	{
		int v = t, garg = OO;
		while(v != s)
		{
			int u = pai[v], e = ant[v];
			garg = min(garg, edges[e].c - edges[e].f);
			v = u;
		}
		v = t;
		while(v != s)
		{
			int u = pai[v], e = ant[v];
			edges[e].f += garg;
			edges[e ^ 1].f -= garg;
			if(e & 1)
				mcmf -= garg * edges[e].cost;
			else
				mcmf += garg * edges[e].cost;
			v = u;
		}
		mf += garg;
	}
	cout << "Max Flow " << mf << '\n';
	cout << "Min Cost Max Flow " << mcmf << '\n';
}

int main()
{
	cin >> n >> m;
	while(m--)
	{
		int u, v, w, c;
		//u->v, peso w, c é o custo por unidade de fluxo
		cin >> u >> v >> w >> c; u--; v--;
		add_edge(u, v, w, 0, c);
		add_edge(v, u, 0, 0, c);
	}
	MCMF(0, n - 1);
				
	return 0;
}