// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cadeia Alimentar
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1903

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int n, m, x, y, g;
vector<vector<int>> grafo, G, G_t;
vector<int> lista;
stack<int> pilha;
int cor[MAX], grau[MAX], pai[MAX], peso[MAX], grupo[MAX];

int find(int x){
    return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] > peso[y])
        pai[y] = x;
    if(peso[x] < peso[y])
        pai[x] = y;
    if(peso[x] == peso[y]){
        pai[x] = y;
        peso[y]++;
    }
}

void preenche(int v){
    cor[v] = 1;
    for(int i = 0; i < G[v].size(); i++){
        int u = G[v][i];
        if(!cor[u])
            preenche(u);
    }
    pilha.push(v);
}

void dfs(int v, int g){
    cor[v] = 1;
    grupo[v] = g;
    for(int i = 0; i < G_t[v].size(); i++){
        int u = G_t[v][i];
        if(!cor[u]){
            join(v, u);
            dfs(u, g);
        }
    }
}

void kosaraju(){
    for(int i = 0; i < n; i++)
        cor[i] = 0;
    for(int i = 0; i < n; i++)
        if(!cor[i])
            preenche(i);
    for(int i = 0; i < n; i++)
        cor[i] = 0, grupo[i] = -1;
    g = 0;
    while(!pilha.empty()){
        int v = pilha.top();
        pilha.pop();
        if(!cor[v]){
            dfs(v, g);
            g++;
        }
    }
}

int main(){    
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    G.resize(n);
    G_t.resize(n);
    grafo.resize(n);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G_t[y-1].push_back(x-1);
    }
    
    for(int i = 0; i < n; i++) pai[i] = i;
    kosaraju();
    
    for(int i = 0; i < n; i++)
        for(int  j = 0; j < G[i].size(); j++)
            if(find(i) != find(G[i][j])){
                grafo[grupo[i]].push_back(grupo[G[i][j]]); 
                grau[grupo[G[i][j]]]++;    
            }
    
    for(int i = 0; i < g; i++)
        if(!grau[i])
            lista.push_back(i);
    
    int ini = 0;
    while(ini < lista.size()){
        int atual = lista[ini++];
        for(int i = 0; i <  grafo[atual].size(); i++){
            int v = grafo[atual][i];
            grau[v]--;
            if(!grau[v])
                lista.push_back(v);
        }
    }
    bool flag = true, ok;
    for(int i = 0; i < lista.size()-1 and flag; i++){
        ok = false;
        for(int j = 0; j < grafo[lista[i]].size() and !ok; j++)
            if(grafo[lista[i]][j] == lista[i+1])
                ok = true;
        if(!ok) flag = false;
    }    
    cout << (flag ? "Bolada" : "Nao Bolada") << '\n';
    
    return 0;
}
