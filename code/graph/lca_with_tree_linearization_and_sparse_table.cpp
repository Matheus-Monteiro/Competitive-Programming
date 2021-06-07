#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10; 
 
int n, m;
vector<int> G[MAX], tl;
int deft[MAX], SpT[27][MAX], pos[MAX];
 
void tree_linearization(int v, int p, int d)
{
	deft[v] = d;
	pos[v] = tl.size();
	tl.push_back(v);
	for(int &u : G[v])
	{
		if(u != p)
		{
			tree_linearization(u, v, d + 1);
			tl.push_back(v);
		}
	}
}
 
void build(int tam)
{
	for(int i = 0; (1 << i) <= tam; i++)
	{
		for(int j = 0; j + (1 << i) <= tam; j++)
			if(!i)
				SpT[i][j] = tl[j];
			else if(deft[SpT[i-1][j]] < deft[SpT[i-1][j+(1<<(i-1))]])
				SpT[i][j] = SpT[i-1][j];
			else
				SpT[i][j] = SpT[i-1][j+(1<<(i-1))];
	}
}

int lca(int i, int j)
{
	int k = log2(j-i+1);
	if(deft[SpT[k][i]] < deft[SpT[k][j+1-(1<<k)]])
		return SpT[k][i];
	else
		return SpT[k][j+1-(1<<k)];
}
 
int main()
{
    int u, v, q;
 
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	tree_linearization(1, -1, 0);
	build(tl.size());
	
	cin >> q;
	while(q--)
	{
		cin >> u >> v;
		cout <<  lca(min(pos[u], pos[v]), max(pos[u], pos[v])) << '\n';
	}
	 
	return 0;
}
