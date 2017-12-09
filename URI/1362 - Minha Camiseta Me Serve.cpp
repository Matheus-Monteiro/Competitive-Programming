// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Minha Camiseta Me Serve
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1362

#include <bits/stdc++.h>
using namespace std;
const int MAX = 400;
const int OO = 0x3f3f3f3f;

struct edge
{
    int v, f, c;
    edge(){}
    edge(int _v, int _f, int _c)
    {
        v = _v, f = _f, c = _c;
    }
};

vector<edge> edges;
vector<int> G[MAX];
int dist[MAX], pai[MAX];

void add_edge(int u, int v, int cp, int rc){
	edges.push_back(edge(v, 0, cp));
	G[u].push_back(edges.size()-1);
	edges.push_back(edge(u, 0, rc));
	G[v].push_back(edges.size()-1);
}

bool bfs(int s, int t)
{
    memset(dist, OO, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int e : G[u])
            if(dist[edges[e].v] == OO and edges[e].c-edges[e].f > 0)
            {
                q.push(edges[e].v);
                pai[edges[e].v] = u;
                dist[edges[e].v] = dist[u] + 1;
            }
    }
    return dist[t] != OO;
}

int dfs(int s, int t, int f)
{
    if(s == t) return f;
    for(int e : G[s])
        if(pai[edges[e].v] == s and dist[edges[e].v] == dist[s] + 1 and edges[e].c-edges[e].f > 0)
            if(int a = dfs(edges[e].v, t, min(f, edges[e].c-edges[e].f)))
            {
                edges[e].f += a;
                edges[e^1].f -= a;
                return a;
            }
    return 0;
}

int MaxFlow(int s, int t)
{
    int mf = 0;
    while(bfs(s, t))
        while(int a = dfs(s, t, OO))
            mf += a;
    return mf;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int t, n, m;
	multimap<string, int> mp;

	cin >> t;
	while(t--)
	{
		cin >> n >> m;
	
		string s1, s2;
		int id = m+1;
		for(int i = 1; i <= m; i++)
			add_edge(0, i, 1, 0);
		for(int i = 1; i <= m; i++)
		{
			cin >> s1 >> s2;
			if(mp.find(s1) == mp.end())
				for(int j = 0; j < n/6; j++)
					mp.insert({s1, id++});
			auto it = mp.find(s1);
			int k = n/6;
			while(k--)
			    add_edge(i, it->second, 1, 0), it++;
			if(mp.find(s2) == mp.end())
				for(int j = 0; j < n/6; j++)
					mp.insert({s2, id++});
			it = mp.find(s2);
			k = n/6;
			while(k--)
				add_edge(i, it->second, 1, 0), it++;
		}	
		for(auto it = mp.begin(); it != mp.end(); it++)
			add_edge(it->second, id, 1, 0);
		cout << (MaxFlow(0, id) == m ? "YES" : "NO") << '\n';
		mp.clear();
		edges.clear();
		for(int i = 0; i <= id; i++)
			G[i].clear();	
	}	
	return 0;
}   
