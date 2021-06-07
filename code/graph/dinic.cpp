#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;
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
int dist[MAX], work[MAX];
 
void add_edge(int u, int v, int cp, int rc){
	edges.push_back(edge(v, 0, cp));
	G[u].push_back(edges.size()-1);
	edges.push_back(edge(u, 0, rc));
	G[v].push_back(edges.size()-1);
}
 
bool bfs(int s, int t)
{
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int e : G[u])
            if(dist[edges[e].v] == -1 and edges[e].c-edges[e].f > 0)
            {
                q.push(edges[e].v);
                dist[edges[e].v] = dist[u] + 1;
            }
    }
    return dist[t] != -1;
}
 
int dfs(int s, int t, int f)
{
    if(s == t) return f;
    for(int &i = work[s]; i < G[s].size(); i++)
    {
    	int e = G[s][i];
        if(dist[edges[e].v] == dist[s] + 1 and edges[e].c-edges[e].f > 0)
            if(int a = dfs(edges[e].v, t, min(f, edges[e].c-edges[e].f)))
            {
                edges[e].f += a;
                edges[e^1].f -= a;
                return a;
            }
    }
    return 0;
}
 
int MaxFlow(int s, int t)
{
    int mf = 0;
    while(bfs(s, t))
	{
    	memset(work, 0, sizeof(work));
        while(int a = dfs(s, t, OO))
            mf += a;
    }
    return mf;
}
 
int main()
{
    int n, m, u, v, w;
 
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        add_edge(u-1, v-1, w, 0);
    }
    cin >> u >> v;
    cout << MaxFlow(u-1, v-1) << '\n';
 
    return 0;
}
