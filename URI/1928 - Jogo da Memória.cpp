// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Jogo da Memória
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1928

#include <bits/stdc++.h>
const int MAX = 50500;

using namespace std;

vector<int> G[MAX];
int pai[MAX], nivel[MAX], v[MAX];

void DFS(int u){
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(nivel[v] == -1){
            pai[v] = u;
            nivel[v] = nivel[u] + 1;
            DFS(v);            
        }
    }
}

int LCA(int a, int b){
    while(a != b){
        if(nivel[a] > nivel[b])
            a = pai[a];
        else
            b = pai[b];
    }
    return a;
}

int main(){
    multimap<int, int> mapa;
    int n, x, y, aux;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> aux;
        mapa.insert({aux, i});
    }

    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
  
  
    for(int i = 0; i < n; i++)  
        nivel[i] = -1;
    nivel[0] = 0;
    DFS(0);
    
    int t = 0;
    for(int i = 1; i <= n/2; i++){
        auto it = mapa.find(i);
        x = it->second;
        it++;
        y = it->second;
        if(!v[it->first]){
            t += nivel[x] + nivel[y] - 2*nivel[LCA(x, y)];
            v[it->first] = 1;
        }
    }
    cout << t << '\n';

    return 0;
}
