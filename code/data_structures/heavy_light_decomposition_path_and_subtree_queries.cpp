/*
no intervalo [ in[v], out[v] ) do array A
temos a subarvore de v. Para fazer consultas
basta usar a segtree.

no intervalo [ in[nxt[v]], in[v] ] temos os vertices no 
caminho de nxt[v] ate v, Em que nxt[v] esta no inicio da
cadeia da HLD. e o caminho de nxt[v] ate v faz parte da
cadeia que comeca em nxt[v].

Assim, podemos processar queries rapidamente em caminhos
e subarvores usando a mesma segment tree.

Bonus: para uma query de mudanca de raiz: se a raiz atual
for v e a consulta for na subarvore de u, entao, se u for 
ancestral de v a resposta eh a consulta da arvore
total menos a consulta da subarvore enraizada pelo filho
de u que eh ancestral de v, caso contrario a consulta eh
normal como se a raiz da arvore nunca tivesse mudado.
obs: Para encontrar o filho de u que eh ancestral de v
podemos usar binary lifting, da mesma forma que usamos
para calcular lca.
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5 * 1e5;
 
int n;
vector<int> Adj[MAX], G[MAX], A;
int in[MAX], out[MAX], rin[MAX], sz[MAX], nxt[MAX], arr[MAX], t = 0;
int st[MAX], lazy[MAX], val_vertex[MAX], depth[MAX], father[MAX]; 
 
void mount(int v = 0, int p = -1)
{
	for(int &u : Adj[v])
		if(u != p)
		{
			G[v].push_back(u);
			mount(u, v);
		}
}
 
void dfs_sz(int v = 0, int p = 0, int d = 0)
{
    sz[v] = 1;
    depth[v] = d;
    father[v] = p;
    for(int &u: G[v])
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
	rin[in[v]] = v;
    A.push_back(val_vertex[v]);
    for(int u: G[v])
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
		st[node] = A[start];
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		st[node] = st[2 * node] + st[2 * node + 1];
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
		st[node] += value * (end - start + 1);
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
 
// atualiza o valor de cada vertice no caminho de
void updatePath(int u, int v, int value)//u para v.
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

//consulta a soma do valor de cada vertice no caminho  
int queryPath(int u, int v)// de u para v.
{
	int l = lca(u, v), ans = 0;
	ans += query_up(u, l);
	ans += query_up(v, l);
	ans -= query(1, 0, n - 1, in[l], in[l]);
	return ans;
}
 
int main()
{
	int q;
	scanf(" %d %d", &n, &q);
	for(int i = 1; i < n; i++)
	{// ler a arvore em qualquer ordem
		int u, v;
		scanf(" %d %d", &u, &v); u--; v--;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	mount();// montar a arvore direcionada
	
	dfs_sz();
	dfs_hld();
 
	// realizar consultas
 
	return 0;
}
