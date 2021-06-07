#include <bits/stdc++.h>
using namespace std;

int n, m;	
vector<int> G[1000], bip[1000], ts;
int vis[1000], b[1000], go[1000], tempo = 1;

bool kuhn(int v)
{
	if(vis[v] == tempo)
		return 0;
	vis[v] = tempo;
	for(const int &u : bip[v])
		if(!b[u] or kuhn(b[u]))
		{
			go[v] = u - n;
			return b[u] = v;
		}
	return 0;
}

void topological_sort(int v)
{
	vis[v] = tempo;
	for(const int &u : G[v])
		if(vis[u] != tempo)
			topological_sort(u);
	ts.push_back(v);
}

int main()
{
	cin >> n >> m;
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		bip[u].push_back(v + n);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += kuhn(i), tempo++;
	for(int i = 1; i <= n; i++)
		if(vis[i] != tempo)
			topological_sort(i);
	reverse(ts.begin(), ts.end());
	tempo++;
	cout << n - ans << '\n';
	for(int i = 0; i < n; i++)
	{
		int u = ts[i];
		if(vis[u] != tempo)
		{
			while(u)
			{
				vis[u] = tempo;
				cout << u << ' ';
				u = go[u];
			}
			puts("");
		}
	}	
			
    return 0;
} 
