// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Rodovia
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2429

#include <bits/stdc++.h>
const int MAX = 1e7;

using namespace std;

int n, m, a, b, cont;
vector<int> G[MAX];
vector<int> G_t[MAX];
stack<int> pilha;
int cor[MAX];

void preenche(int v){
	cor[v] = 1;
	for(int i = 0; i < G[v].size(); i++){
		int r = G[v][i];
		if(!cor[r])
			preenche(r);
	}
	pilha.push(v);
}

void dfs(int v){
	cor[v] = 1;
	for(int i = 0; i < G_t[v].size(); i++){
		int r = G_t[v][i];
		if(!cor[r])
			dfs(r);
	}
}

void kosaraju(){
	for(int i = 0; i < n; i++)
		cor[0] = 0;
	
	for(int i = 0; i < n; i++)
		if(!cor[i])
			preenche(i);
	for(int i = 0; i < n; i++)
		cor[i] = 0;
	
	while(!pilha.empty()){
		int v = pilha.top();
		pilha.pop();
		if(!cor[v]){
			cont++;
			dfs(v);
		}
	}	
}

int main(){
	cin >> n;
	int k = n;
	while(k--){
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G_t[b-1].push_back(a-1);
	}
	kosaraju();
	cout << (cont == 1 ? 'S' : 'N') << '\n';
	
	return 0;
}
