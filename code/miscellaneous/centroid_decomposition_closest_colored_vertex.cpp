/*
	Centroid Decomposition
	paint(u, u) -> Colors a vertex u
	query(u, u, inf) -> find the distance to 
				the closest colored vertex 
*/

#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e6 + 200;
const long long OO = 0x3f3f3f3f3f3f3f3f;
 
#define ii pair<int, int>
#define f first
#define s second
 
int n;
vector<ii> G[MAX];
vector<int> tl;
int SpT[22][MAX], pos[MAX], depth[MAX];
int CD[MAX], sz[MAX];
bool cut[MAX];
long long ans[MAX], weight[MAX];
 
void dfs(int v, int p, int d)
{
    depth[v] = d;
	pos[v] = tl.size();
	tl.push_back(v);
    for(auto [u, w] : G[v]) {
        if(u != p) {
			weight[u] = weight[v] + w;
            dfs(u, v, d + 1);
			tl.push_back(v);
		}
	}
}
 
void build() {
	int tam = tl.size();
	for(int i = 0; (1 << i) <= tam; i++) {
		for(int j = 0; j + (1 << i) <= tam; j++) {
			if(!i)
				SpT[i][j] = tl[j];
			else if(depth[SpT[i-1][j]] < depth[SpT[i-1][j+(1<<(i-1))]])
				SpT[i][j] = SpT[i-1][j];
			else
				SpT[i][j] = SpT[i-1][j+(1<<(i-1))];
		}
	}
}
 
int lca(int u, int v) {
	int i = min(pos[u], pos[v]);
	int j = max(pos[u], pos[v]);
	int k = log2(j-i+1);
	if(depth[SpT[k][i]] < depth[SpT[k][j+1-(1<<k)]])
		return SpT[k][i];
	else
		return SpT[k][j+1-(1<<k)];
}
 
int dfs2(int v, int p)
{
    int s = 1;
    for(auto [u, w] : G[v])
        if(!cut[u] and u != p)
            s += dfs2(u, v);
    return sz[v] = s;
}
 
int find_centroid(int v, int p, int tot)
{
    int next_v, cnt = 0;
    for(auto [u, w] : G[v])
        if(!cut[u] and u != p and sz[u] > cnt)
            cnt = sz[u], next_v = u;
    if(cnt > tot / 2) return find_centroid(next_v, v, tot);
    return v;
}
 
void build_centroid_tree(int v, int p)
{
    dfs2(v, -1);
    int u = find_centroid(v, -1, sz[v]);
    CD[u] = p;
    cut[u] = true;
    for(auto [w, h] : G[u])
        if(!cut[w])
            build_centroid_tree(w, u);
}
 
long long dist(int u, int v)
{
    return weight[u] + weight[v] - 2 * weight[lca(u, v)];
}
 
void paint(int v, int u)
{
    if(v == -1) return;
    ans[v] = min(ans[v], dist(v, u));
    paint(CD[v], u);
}
 
void unpaint(int v, int u)
{
    if(v == -1) return;
	if(ans[v] == OO) return;
 
    ans[v] = OO;
    unpaint(CD[v], u);
}
 
long long query(int v, int u, long long d)
{
    if(v == -1)
        return d;
    return query(CD[v], u, min(d, dist(v, u) + ans[v]));
}
 
void Init(int N, int A[], int B[], int D[]) {
	n = N;
	for(int i = 0; i < n-1; i++) {
        G[ A[i] ].push_back({B[i], D[i]});
        G[ B[i] ].push_back({A[i], D[i]});
    }
	for(int i = 0; i < N; ++i) ans[i] = OO;
	dfs(0, -1, 0);
	build(); 
    build_centroid_tree(0, -1);
}
 
long long Query(int S, int X[], int T, int Y[]) {
	long long rep = OO;
 
	for(int j = 0; j < S; ++j) 
		paint(X[j], X[j]);
	for(int j = 0; j < T; ++j)
		rep = min(rep, query(Y[j], Y[j], OO));
 
	for(int j = 0; j < S; ++j) 
		unpaint(X[j], X[j]);
	
	return rep;
}
 
void mount() {
	int A[] = {0, 1, 2, 2, 4, 1};
	int B[] = {1, 2, 3, 4, 5, 6};
	int D[] = {4, 4, 5, 6, 5, 3};
	Init(7, A, B, D);
}
 
int test1() {
	int X[] = {0, 6};
	int Y[] = {3, 4};
	return Query(2, Y, 2, X);
}
 
int test2() {
	int X[] = {0, 1, 3};
	int Y[] = {4, 6};
	return Query(2, Y, 3, X);
}
 
int test3() {
	int X[] = {2};
	int Y[] = {5};
	return Query(1, Y, 1, X);
}
 
int main() {
 
	mount();
	assert(test1() == 12);
	assert(test2() == 3);
	assert(test3() == 11);
 
	return 0;
}