// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Colônia de Formigas
// Categoria: GRAPH - LCA
// URL: http://www.codcad.com/problem/160

#include <bits/stdc++.h>
const int MAX = 1e6;

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int n, x, y, q;
int pai[MAX];
int nivel[MAX];
ll dist[MAX];
vector<vector<pii> > G;

void dfs(int u){
	for(int i = 0; i < G[u].size(); i++){
		int r = G[u][i].second;
		if(nivel[r] == -1){
			pai[r] = u;
			nivel[r] = nivel[u] + 1;
			dist[r] = dist[u] + G[u][i].first;
			dfs(r);
		}
	}
}

int lca(int a, int b){
	while(a != b){
		if(nivel[a] > nivel[b])
			a = pai[a];
		else
			b = pai[b];
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	while(cin >> n and n){
    	G.resize(n+5);
    	for(int i = 1; i < n; i++){
    		cin >> x >> y;
    		G[x].push_back({y, i});
    		G[i].push_back({y, x});
    	}
    	
    	for(int i = 0; i <= n; i++){
    		nivel[i] = -1;
    	    dist[i] = 0;
    	}
    	nivel[0] = 0;
    	
    	dfs(0);
    	cin >> q;
    	while(q--){
    		cin >> x >> y;
    		cout << dist[x]+dist[y]-2*dist[lca(x, y)];
    		if(q) cout << ' ';
    	}
    	cout << '\n';
	    G.clear();
	}
	return 0;
}
