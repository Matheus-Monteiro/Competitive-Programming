#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

int pos[MAX];
int deft[MAX];
int segtree[5*MAX];
vector<int> tl;
vector<int> G[MAX];

void tree_linearization(int v, int p, int d)
{
	deft[v] = d;
	pos[v] = tl.size();
	tl.push_back(v);
	for(const int &u : G[v]) 
		if(u != p)
		{
			tree_linearization(u, v, d + 1);
			tl.push_back(v);
		}
}

void build(int node, int start, int end)
{
	if(start == end)
		segtree[node] = tl[start];
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		if(deft[segtree[2*node]] < deft[segtree[2*node+1]])
			segtree[node] = segtree[2*node];
		else
			segtree[node] = segtree[2*node+1];
	}
}
	
int lca(int node, int start, int end, int l, int r)
{
	if(l > end or r < start)
		return -1;
	if(l <= start and end <= r)
		return segtree[node];
	int mid = (start+end)/2;
	int p1 = lca(2*node, start, mid, l, r);
	int p2 = lca(2*node+1, mid+1, end, l, r);
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return deft[p1] < deft[p2] ? p1 : p2;
}

/*int _lca(int a, int b)
{
	int ancestor = a, nivel = 0x3f3f3f3f;
	for(int i = pos[a]; i <= pos[b]; i++)
		if(deft[tl[i]] < nivel)
		{
			ancestor = tl[i];
			nivel = deft[tl[i]];
		}
	return ancestor;
}*/


int main()
{
	int n, u, v;	
	
	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	
	tree_linearization(1, -1, 0);
	build(1, 0, tl.size()-1);

	/*
	for(int i = 1; i <= n; i++)
		cout << deft[i] << ' ';
	cout << '\n';
	for(int i = 1; i <= n; i++)
		cout << pos[i] << ' ';
	cout << '\n';
	for(const int &p : tl)
		cout << p << ' ';
	cout << '\n';
	for(int i = 1; i <= 4*n; i++)
		cout << segtree[i] << ' ';
	cout << '\n';*/
	
	while(cin >> u >> v)
		cout << /*_lca(u, v) << ' ' <<*/
		 lca(1, 0, tl.size()-1, pos[u], pos[v]) << '\n';
		
	return 0;
}
