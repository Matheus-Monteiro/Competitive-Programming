#include <bits/stdc++.h>
using namespace std;
#define MAX 100008
 
int n, value[MAX];
vector<int> G[MAX];
int pd[MAX][2];
 
int solve(int v, int fl, int p)
{
	if(pd[v][fl] != -1)
		return pd[v][fl];
	int a1 = fl ? value[v] : 0, a2 = 0;
	for(int i = 0; i < (int)G[v].size(); i++)
	{
		int u = G[v][i];
		if(u != p)
		{
			a1 += solve(u, 0, v);
			a2 += solve(u, 1, v);
		}
	}
	int ans = 0;
	if(fl)
		ans = max(a1, a2);
	else	
		ans = a2;
	return pd[v][fl] = ans;
}
 
int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(pd, -1, sizeof(pd));
	for(int i = 0; i < n; i++)
		cin >> value[i];
	cout << max(solve(0, 0, -1), solve(0, 1, -1)) << '\n';
 
	return 0;
}