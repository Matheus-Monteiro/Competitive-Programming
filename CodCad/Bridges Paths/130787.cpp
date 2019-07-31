#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;  

#define MAXN 10100
#define INFINITO 0x3f3f3f3f

int n, m;                                 
int dist[MAXN], H[MAXN]; 
bool vis[MAXN];         
vector<pii> G[MAXN];    

int Dijkstra(int S, int E){
	
	memset(dist, 63, sizeof(dist));
	dist[S] = 0;                        
	priority_queue< pii, vector<pii>, greater<pii> > pq; 
	pq.push( pii(0, S) );                    

	while(!pq.empty())
	{ 
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		if(u == E) return dist[u];
		for(int i = 0; i < (int)G[u].size(); i++)
		{
			int d = G[u][i].first;
			int w = G[u][i].second;
			if(dist[w] > dist[u] + d)
			{
				dist[w] = dist[u] + d;
				pq.push( pii(dist[w] + H[w], w) );  
			}
		}
		vis[u] = true;
	}
	return -1;
}

void bfs(int v)
{
	queue<int> q;
	H[v] = 0;
	q.push(v);
	vis[v] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < (int)G[u].size(); i++)
		{
			int w = G[u][i].second;
			if(!vis[w])
			{
				H[w] = H[u] + 1;
				q.push(w);  
				vis[w] = true;
			}
		}
	}
	memset(vis, false, sizeof(vis));
}

int main(){
	
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		int x, y, tempo;
		scanf(" %d %d %d", &x, &y, &tempo);
		G[x].push_back( pii(tempo, y) );
		G[y].push_back( pii(tempo, x) );
	}
	bfs(n + 1);
	cout << Dijkstra(0, n + 1) << endl;
	
	return 0;
}