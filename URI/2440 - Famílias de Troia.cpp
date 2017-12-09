// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Famílias de Troia
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2440

#include <bits/stdc++.h>
const int MAX = 1e7;

using namespace std;

int n, m, a, b;
vector<int> G[MAX];
int cor[MAX];

void dfs(int v){
	cor[v] = 1;
	for(int i = 0; i < G[v].size(); i++){
		int r = G[v][i];
		if(!cor[r])
			dfs(r);
	}
}

int main(){
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	int cont = 0;
	for(int i = 0; i < n; i++){
		if(!cor[i]){
			cont++;
			dfs(i);
		}
	}
	cout << cont << '\n';
	return 0;
}
