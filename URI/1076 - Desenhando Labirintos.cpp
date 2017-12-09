// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Desenhando Labirintos
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1076

#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

vector< vector <int> > grafo;
bool visitado[MAX];
int t, x, y, n, v, a, tam, contador;

void dfs(int atual){
	visitado[atual]=true;
	for(int i = 0; i < grafo[atual].size(); i++){
		if (!visitado[grafo[atual][i]]){
			dfs(grafo[atual][i]);
			contador++;
		}
	}
}

int main (){
	contador = 0;
	
	cin >> t;
	
	while(t--){
		cin >> n >> v >> a;
	    grafo.resize(v);
		while(a--){
			cin >> x >> y;      
			grafo[x].push_back(y);
			grafo[y].push_back(x);
		}
		
		for(int i = 0; i < v; i++)
			sort(grafo[i].begin(), grafo[i].end());
		
		memset(visitado, false, v);
		dfs(n);      

		cout << 2*contador << endl;
		contador = 0;
		for(int i = 0; i < v; i++)
			grafo[i].clear();
		grafo.clear();
	}
}
