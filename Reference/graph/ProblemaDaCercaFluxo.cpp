#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;
const int OO = 0x3f3f3f3f;
int SOURCE, SINK;
 
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
 
int n, m, a, b;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
char ANS[60][60];
bool cor[MAX];
 
bool check(int x, int y)
{
	return x >= 0 and x < n and y >= 0 and y < m;
}
 
int vertexIn(int i, int j)
{
	return i * m + j;
}
 
int vertexOut(int i, int j)
{
	return i * m + j + n * m + 1;
}
 
void mountANS(int v)
{
	cor[v] = true;
	for(int &e : G[v])
	{
		if(cor[edges[e].v]) continue;
		if(edges[e].c - edges[e].f > 0)
			mountANS(edges[e].v);
	}
}
 
int main()
{
	memset(ANS, '.', sizeof(ANS));
 	cin >> n >> m >> a >> b; a--; b--;
 	SOURCE = 2 * n * m + 2;
 	SINK = 2 * n * m + 3;
 	for(int i = 0; i < n; i++)
 		for(int j = 0; j < m; j++)
 		{
 			int cost;
 			cin >> cost;
 			if(a == i and b == j) cost = OO;
 			add_edge(vertexIn(i, j), vertexOut(i, j), cost, 0);
 			if(cost == OO) add_edge(vertexOut(i, j), SINK, OO, 0);
 			for(int k = 0; k < 4; k++)
 			{
				int x = i + dx[k], y = j + dy[k];
				if(check(x, y))
 					add_edge(vertexOut(i, j), 
 						vertexIn(x, y), OO, 0);
 			}
 			if(!i or !j or i == n - 1 or j == m - 1)
 				add_edge(SOURCE, vertexIn(i, j), OO, 0);
 		}	
 	cout << MaxFlow(SOURCE, SINK) << '\n';
 	mountANS(SOURCE);
 	for(int i = 0; i < n * m; i++)
 		for(int &e : G[i])
			if(!(e & 1) and cor[i] and !cor[edges[e].v])
				ANS[i / m][i % m] = 'X';
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << ANS[i][j];
		puts("");
	}
    return 0;
}
