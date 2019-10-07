#include <bits/stdc++.h> 

const int OO = 0x3f3f3f3f;
const int MAX = 1e6;

using namespace std;

int n, m;
vector<pair<int, int>> G[MAX];
int dist1[MAX], dist2[MAX];
vector<int> ts;
bool cor[MAX];

void dfs(int v)
{
	cor[v] = true;
	for(pair<int, int> &w : G[v])
		if(!cor[w.first])
			dfs(w.first);
	ts.push_back(v);
}

// caminho de 0 a n-1
pair<int, int> longestAndShortestPathInDAG()
{
	for(int i = 0; i <= n; i++)
		dist1[i] = -OO, dist2[i] = OO;
	dist1[0] = dist2[0] = 0;
	int p = 0;
	while(p < (int)ts.size())
	{
		int v = ts[p++];
		if(dist1[v] != -OO)
			for(int i = 0; i < (int)G[v].size(); i++)
			{
				int u = G[v][i].first, d = G[v][i].second;
				if(dist1[u] < dist1[v] + d)
					dist1[u] = dist1[v] + d;
			}	
		if(dist2[v] != OO)
			for(int i = 0; i < (int)G[v].size(); i++)
			{
				int u = G[v][i].first, d = G[v][i].second;
				if(dist2[u] > dist2[v] + d)
					dist2[u] = dist2[v] + d;
			}	
	}
	return {dist1[n-1], dist2[n-1]};
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w; u--; v--;
		G[u].push_back({v, w});
	}
	for(int i = 0; i < n; i++)
		if(!cor[i])
			dfs(i);
	reverse(ts.begin(), ts.end());
	pair<int, int> ans = longestAndShortestPathInDAG();
	cout << "Longest Path " << ans.first << '\n';
	cout << "Shortest Path " << ans.second << '\n';

	return 0;
}
