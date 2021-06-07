#include <bits/stdc++.h>
using namespace std;

vector<int> G[1000];
int b[1000], vis[1000], tempo;

bool kuhn(int v)
{
	if(vis[v] == tempo)
		return 0;
	vis[v] = tempo;
	for(const int &u : G[v])
		if(!b[u] or kuhn(b[u]))
			return b[u] = v;
	return 0;
}

int main()
{
	int n, m, e;
	cin >> n >> m >> e;
	while(e--)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v + n);
	}
	int ans = 0;
	tempo = 1;
	for(int i = 1; i <= n; i++)
		ans += kuhn(i), tempo++;
	
	
	//encontrar as arestas do Minimum Edge Cover
	vector<bool> covered(n + m + 10, false);
    vector<pair<int, int>> cover;
	for(int i = n + 1; i <= n + m; i++)
		if(b[i])	
		{
			covered[b[i]] = covered[i] = true;
			cover.push_back({b[i], i - n});
		}
	for(int i = 1; i <= n; i++)
	{
		bool is_covered = covered[i];
		for(const int &u : G[i])
			if(!covered[u])
			{
				is_covered = true;
				cover.push_back({i, u - n});
				covered[i] = covered[u] = true;
			}
		if(!is_covered and !G[i].empty())
			cover.push_back({i, G[i].front() - n});
	}
	cout << "MEC = " << cover.size() << '\n';
	for(int i = 0; i < cover.size(); i++)
		cout << cover[i].first << ' ' << cover[i].second << '\n';

    return 0;
} 
