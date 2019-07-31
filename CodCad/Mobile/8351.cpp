#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > grafo;
int cont;
int cor[100001];

void dfs(int atual){
	cor[atual] = 1;
	for(int i = 0; i < grafo[atual].size(); i++){
		if(!cor[grafo[atual][i]]){
			cont++;
			dfs(grafo[atual][i]);
		}
	}
}

int main(){
	
	int n, x, y;
	vector<int> aux;
	bool buraco = true;
	
	cin >> n;
	
	grafo.resize(n+1);
	
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		grafo[y].push_back(x);
	}
	
	memset(cor, 0, sizeof(cor));
	
	for(int i = 0; i < n+1; i++){
		if(grafo[i].size() > 1){
			for(int j = 0; j < grafo[i].size(); j++){
				cont = 0;
				int n = grafo[i][j];
				dfs(n);
				aux.push_back(cont);
				memset(cor, 0, sizeof(cor));
			}
			int one = aux[0];
			for(int k = 0; k < aux.size(); k++){
				if(one != aux[k]){
					buraco = false;
					break;
				}
			}
			aux.clear();
		}
	}
	if(buraco)
		cout << "bem" << endl;
	else
		cout << "mal" << endl;
	
	  
	return 0;
}