// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Dudu Faz Serviço
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1610

#include <bits/stdc++.h>
#define white 0
#define grey 1
#define black -1
const int MAX = 10100;

using namespace std;

int n, m;
vector<int> graph[MAX];
int color[MAX];

bool dfs(int u){
	color[u] = grey;
	
	for(int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i];
		if(color[v] == white){
			if(!dfs(v)){
				return false;
			}
		}else{
			if(color[v] == grey){
				return false;
			}
		}
	}
	color[u] = black;
	return true;
}

bool temCiclo(){
	memset(color, white, n*(sizeof(int)));
	bool hole_tall;
	for(int i = 0; i < n; i++){
		hole_tall = dfs(i);
		if(!hole_tall)
			return false;
		else
			memset(color, white, n*(sizeof(int)));
	}
	return true;
}

int main(){
	int x, y, t;
	bool hole;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			graph[x-1].push_back(y-1);
		}
		
		hole = temCiclo();
		if(hole)
			cout << "NAO" << endl;
		else
			cout << "SIM" << endl;
		
		for(int i = 0; i < n; i++)
			graph[i].clear();
	}
	
	return 0;
}
