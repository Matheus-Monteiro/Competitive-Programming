// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Promessa de Campanha
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1835

#include <bits/stdc++.h>
const int MAX = 10100;

using namespace std;

int n, m;
vector<int> grafo[MAX];
int cor[MAX];

void dfs(int atual){
	cor[atual] = 1;
	
	for(int i = 0; i < grafo[atual].size(); i++){
		int v = grafo[atual][i];
		if(!cor[v])
			dfs(v);
	}
}

int main(){
	int x, y, t, casos = 1;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			grafo[x-1].push_back(y-1);
			grafo[y-1].push_back(x-1);
		}
		
		int num_componentes = 0;
		memset(cor, 0, n*(sizeof(int)));
		
		for(int i = 0; i < n; i++){
			if(!cor[i]){
				num_componentes++;
				dfs(i);
			}
		}
		
		cout << "Caso #" << casos << ": ";
		
		if(num_componentes == 1)
			cout << "a promessa foi cumprida" << endl;
		else
			cout << "ainda falta(m) " << num_componentes-1 << " estrada(s)" << endl;
	
		casos++;
		for(int i = 0; i < n; i++)
			grafo[i].clear();
	}
	return 0;
}
