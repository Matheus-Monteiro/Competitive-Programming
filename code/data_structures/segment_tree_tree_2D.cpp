#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3;

int n, leaf;
int arr[MAX][MAX];
int ST[4*MAX][4*MAX];

void buildLeaf(int k, int node, int l, int r)
{
	if(l == r)
		ST[k][node] = arr[leaf][l];
	else
	{
		int mid = (l + r) / 2;
		buildLeaf(k, 2*node, l, mid);
		buildLeaf(k, 2*node + 1, mid + 1, r);
		ST[k][node] = ST[k][2*node] + ST[k][2*node+1];
	}
}

void build(int node, int l, int r)
{
	if(l == r)
		buildLeaf(node, 1, 0, n-1), leaf++;
	else
	{
		int mid = (l + r) / 2;
		build(2*node, l, mid);
		build(2*node + 1, mid + 1, r);
		for(int i = 1; i < 4*n; i++)
			ST[node][i] = ST[2*node][i] + ST[2*node+1][i];
	}
}

int queryNode(int k, int node, int l, int r, int cx, int cy)
{
	if(l > cy or r < cx)
		return 0;
	if(cx <= l and r <= cy)
		return ST[k][node];
	int mid = (l + r) / 2;
	int ans = queryNode(k, 2*node, l, mid, cx, cy);
	ans += queryNode(k, 2*node + 1, mid + 1, r, cx, cy);
	return ans;
}

int query(int node, int l, int r, int lx, int ly, int cx, int cy)
{
	if(l > ly or r < lx)
		return 0;
	if(lx <= l and r <= ly)
		return queryNode(node, 1, 0, n-1, cx, cy);
	int mid = (l + r) / 2;
	int ans = query(2*node, l, mid, lx, ly, cx, cy);
	ans += query(2*node + 1, mid + 1, r, lx, ly, cx, cy);
	return ans;
}

void updateNode(int k, int node, int l, int r, int x, int y, int value)
{
	if(l == r)
		ST[k][node] = arr[x][y] = value;
	else
	{
		int mid = (l + r) / 2;
		if(l <= y and y <= mid)
			updateNode(k, 2*node, l, mid, x, y, value);
		else
			updateNode(k, 2*node + 1, mid + 1, r, x, y, value);
		ST[k][node] = ST[k][2*node] + ST[k][2*node + 1];
	}
}

void update(int node, int l, int r, int x, int y, int value)
{
	if(l == r)
		updateNode(node, 1, 0, n-1, x, y, value);
	else
	{
		int mid = (l + r) / 2;
		if(l <= x and x <= mid)
			update(2*node, l, mid, x, y, value);
		else
			update(2*node + 1, mid + 1, r, x, y, value);
		for(int i = 1; i < 4*n; i++)
			ST[node][i] = ST[2*node][i] + ST[2*node+1][i];
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];
	build(1, 0, n-1);	
	int o, a, b, c, d;
	while(cin >> o)
	{
		cin >> a >> b >> c;
		if(o == 1)
			update(1, 0, n-1, a-1, b-1, c);
		else
		{	
			cin >> d;
			cout << query(1, 0, n-1, a-1, b-1, c-1, d-1) << '\n';
		}
	}
		
	return 0;
}
