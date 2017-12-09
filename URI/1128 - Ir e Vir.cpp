// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ir e Vir
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1128

	#include <bits/stdc++.h>
	const int MAX = 1e6;
	
	using namespace std;
	
	vector<int> G[MAX];
	vector<int> G_t[MAX];
	stack<int> pilha;
	int cor[MAX];
	int n, m, a, b, p, cont;
	
	void preenche(int v){
		cor[v] = 1;
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i];		
			if(!cor[u])
				preenche(u);
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
			cor[i] = 0;
		
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
		while(cin >> n >> m and (n or m)){
			for(int i = 0; i < m; i++){
				cin >> a >> b >> p;
				if(p == 1){
					G[a-1].push_back(b-1);
					G_t[b-1].push_back(a-1);
				}else{
					G[a-1].push_back(b-1);
					G[b-1].push_back(a-1);
					G_t[a-1].push_back(b-1);
					G_t[b-1].push_back(a-1);
				}	
			}
			cont = 0;
			kosaraju();
			cout << (cont == 1 ? 1 : 0) << '\n';
			for(int i = 0; i < n; i++){
				G[i].clear();
				G_t[i].clear();
			}
		}
		return 0;
	}
