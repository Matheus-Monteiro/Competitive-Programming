// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Componentes Conexos
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1082

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector< vector<char> > grafo;
int cor[27];
vector<int> componentes;

void dfs(int a){
    cor[a] = 1;
    for(int i = 0; i < grafo[a].size(); i++){
        int v = grafo[a][i];
        if(!cor[v]){
            componentes.push_back(v);
            dfs(v);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int v, a, t, contador=1;;
	char l1, l2;

    cin >> t;
    
    while(t--){
        cin >> v >> a;
        grafo.resize(v);
         
	    for(int i = 0; i < a; i++){
	        cin >> l1 >> l2;
	        int x = (int)l1-97;
	        int y = (int)l2-97;
	        grafo[x].push_back(y);
	        grafo[y].push_back(x);
	    }
	    
	    memset(cor, 0, sizeof(cor));
	    int num_componentes = 0;
	    componentes.clear();
	    
	    cout << "Case #" << contador << ":" << endl;
	    for(int i = 0; i < v; i++){
	        if(!cor[i]){
	            num_componentes++;
	            componentes.push_back(i);
	            dfs(i);
	        }
	        sort(componentes.begin(), componentes.end());
	        for(int j = 0; j < componentes.size(); j++){
	            char aux = 'a' + componentes[j];
	            cout << aux << ",";
	            if(j == componentes.size()-1)
	                 cout << endl;
	        }
	        componentes.clear();
	    }
	    cout << num_componentes << " connected components" << endl;
	    cout << endl;
	    contador++;
	    grafo.clear();
    }   
	return 0;
}
