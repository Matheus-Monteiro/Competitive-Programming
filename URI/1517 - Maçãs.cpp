// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Maçãs
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1517

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1100;
const int OO = (1<<30);
#define f first
#define s second
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, k;
vector<iii> lista;
int grau[MAX], dist[MAX];
vector<int> ts;
vector<int> G[MAX];

bool test(int i, int j){
	int z = max(abs(lista[i].s.f - lista[j].s.f), abs(lista[i].s.s - lista[j].s.s));
	if(z <= (lista[j].f - lista[i].f))
		return true;
	return false;
}

void topologicaSort(){
	for(int i = 0; i <= k; i++)
		if(!grau[i])
			ts.push_back(i);	
	int ini = 0;
	while(ini < ts.size()){
		int u = ts[ini++];
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			grau[v]--;
			if(!grau[v])
				ts.push_back(v);
		}
	}
}

void longestPaht(){
	for(int i = 0; i <= k; i++)
		dist[i] = -OO;
	dist[0] = 0;
	int p = 0;
	while(p < ts.size()){
		int v = ts[p++];
		if(dist[v] != -OO){
			for(int i = 0; i < G[v].size(); i++){
				int u = G[v][i];
				if(dist[u] < dist[v] + 1)
					dist[u] = dist[v] + 1;
			}
		}
	}
}

int main(){
	int u, v, t;
	
	while(cin >> n >> m >> k and (n or m or k)){
    	int k_ = k;
    	lista.push_back({0, {-1, -1}});
    	while(k_--){
    		cin >> u >> v >> t;
    		lista.push_back({t, {u, v}});
    	}
    	cin >> u >> v;
    	lista[0] = {0, {u, v}};
    	
    	for(int i = 0; i <= k; i++)
    		for(int j = i+1; j <= k; j++)
    			if(test(i, j))
    				G[i].push_back(j), grau[j]++;
    	topologicaSort();
    	longestPaht();
    	int ans = 0;
    	for(int i = 0; i <= k; i++)
    		ans = max(ans, dist[i]);
    	cout << ans << '\n';
    	ts.clear();
    	lista.clear();
    	for(int i = 0; i < MAX; i++){
    	    grau[i] = dist[i] = 0;
    	    G[i].clear();
    	}
	}
	
	return 0;
}
