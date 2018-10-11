#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
 
int n;
vector<int> G[MAX], tour, arr;
int in[MAX], out[MAX], rin[MAX], sz[MAX], nxt[MAX], t = 0;
int st[MAX], lazy[MAX], A[MAX], val_vertex[MAX], depth[MAX], father[MAX]; 

void dfs_sz(int v = 0, int p = 0, int d = 0)
{
    sz[v] = 1;
    depth[v] = d;
    father[v] = p;
    for(auto &u: G[v])
    {
    	if(u == p) continue;
        dfs_sz(u, v, d + 1);
        sz[v] += sz[u];
        if(sz[u] > sz[G[v][0]])
            swap(u, G[v][0]);
    }
}
 
void dfs_hld(int v = 0, int p = -1)
{
    in[v] = t++;
    tour.push_back(v);
    arr.push_back(val_vertex[v]);
    rin[in[v]] = v;
    for(auto u: G[v])
    {
    	if(u == p) continue;
        nxt[u] = (u == G[v][0] ? nxt[v] : u);
        dfs_hld(u, v);
    }
    out[v] = t;
}

void build(int node, int start, int end)
{
	if(start == end)
		st[node] = arr[start];
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		st[node] = st[2 * node] + st[2 * node + 1];//😍
	}
}

void update(int node, int start, int end, int l, int r, int value)
{
	if(lazy[node])
	{
		st[node] += (end - start + 1) * lazy[node];
	 	if(start != end)
	 	{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node]; 
		}	
		lazy[node] = 0;
	}
	if(l > end or start > r)
		return;
	if(l <= start and end <= r)
	{
		st[node] += value * (start - end + 1);
		if(start != end)
	 	{
			lazy[2 * node] += value;
			lazy[2 * node + 1] += value; 
		}	
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, value);
	update(2 * node + 1, mid + 1, end, l, r, value);
	st[node] = st[2 * node] + st[2 * node + 1];
}

int query(int node, int start, int end, int l, int r)
{
	if(lazy[node])
	{
		st[node] += (end - start + 1) * lazy[node];
	 	if(start != end)
	 	{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node]; 
		}	
		lazy[node] = 0;
	}
	if(l > end or start > r)
		return 0;
	if(l <= start and end <= r)
		return st[node];
	int mid = (start + end) / 2;
	int q1 = query(2 * node, start, mid, l, r);
	int q2 = query(2 * node + 1, mid + 1, end, l, r);
	return q1 + q2;
}

int lca(int u, int v)
{
	while(nxt[u] != nxt[v])
	{
		if(depth[nxt[u]] < depth[nxt[v]])
			v = father[nxt[v]];
		else
			u = father[nxt[u]];
	}
	return depth[u] < depth[v] ? u : v;
}

void update_up(int u, int l, int value)
{
	while(true)
	{
		if(nxt[u] == nxt[l])
		{
			update(1, 0, n - 1, in[l], in[u], value);
			break;
		}
		update(1, 0, n - 1, in[nxt[u]], in[u], value);
		u = father[nxt[u]];
	}
}

int updatePath(int u, int v, int value)
{
	int l = lca(u, v);
	update_up(u, l, value);
	update_up(v, l, value);
	update(1, 0, n - 1, in[l], in[l], -value);
}

int query_up(int u, int l)
{
	int ans = 0;
	while(true)
	{
		if(nxt[u] == nxt[l])
		{
			ans += query(1, 0, n - 1, in[l], in[u]);
			break;
		}
		ans += query(1, 0, n - 1, in[nxt[u]], in[u]);
		u = father[nxt[u]];
	}
	return ans;
}

int queryPath(int u, int v)
{
	int l = lca(u, v), ans = 0;
	ans += query_up(u, l);
	ans += query_up(v, l);
	ans -= query(1, 0, n - 1, in[l], in[l]);
	return ans;
}

int main()
{
	cin >> n;
	// ler valor inicial em cada vertice (0-indexado)
	//for(int i = 0; i < n; i++)
	//	cin >> val_vertex[i];
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v; u--; v--;
		G[u].push_back(v);
		//G[v].push_back(u);
	}
	dfs_sz();
	// u = G[v][0], a aresta v->u é uma aresta heavy	
	/*for(int i = 0; i < n; i++)
		if(G[i].size() >= 1)
			cout << G[i][0] + 1 << '\n';*/
 
	dfs_hld();
	build(1, 0, n - 1);
 
 	// subarvore de v está no intervalo [ in(v), out(v) ) no array tour
	cout << "in   "; for(int i = 0; i < n; i++) cout << in[i] << ' '; puts("");
	cout << "out  "; for(int i = 0; i < n; i++) cout << out[i] << ' '; puts("");
	cout << "sz   "; for(int i = 0; i < n; i++) cout << sz[i] << ' '; puts("");
	cout << "nxt  "; for(int i = 0; i < n; i++) cout << nxt[i] + 1 << ' '; puts("");
	cout << "tour "; for(int &w : tour) cout << w + 1 << ' '; puts("");
 
 	int o, u, v, w;
 	while(cin >> o)
 	{
 		if(o == 1)
 		{	
 			cin >> u >> v >> w;
 			updatePath(u - 1, v - 1, w);
 		}
 		else
 		{
 			cin >> u >> v;
 			cout << queryPath(u - 1, v - 1) << '\n';
 		}
 	}
 	
 	//LCA usando HLD
 	/*int u, v;
 	while(cin >> u >> v)
 		cout << lca(u - 1, v - 1) + 1 << '\n';
	*/
 
	return 0;
}