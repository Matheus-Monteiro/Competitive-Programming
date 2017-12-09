// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Rato no Labirinto
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1799

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

int n, m, id;
int dist[MAX];
int anterior[MAX];
bool cor[MAX];
vector<int> G[MAX];

void bfs(int v){
    for(int i = 0; i < id; i++)
        cor[i] = false, anterior[i] = -1;
    cor[v] = true;
    queue<int> fila;
    fila.push(v);
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        for(int i = 0; i < G[u].size(); i++){
            int r = G[u][i];
            if(!cor[r]){
                cor[r] = true;
                fila.push(r);
                anterior[r] = u;
            }
        }
    }
}

int path(int a, int b){
    stack<int> s;
    int i = b;
    while(i != a){
        s.push(i);
        i = anterior[i];
    }
    s.push(a);
    return s.size();
}

int main(){
    map<string, int> mapa;

    cin >> n >> m;
    string s1, s2;
    while(m--){
        cin >> s1 >> s2;
        if(mapa.find(s1) == mapa.end())
            mapa[s1] = id++;
        if(mapa.find(s2) == mapa.end())
            mapa[s2] = id++;
        G[mapa[s1]].push_back(mapa[s2]);
        G[mapa[s2]].push_back(mapa[s1]);
    }
    int ans = 0;
    bfs(mapa["Entrada"]);
    ans += path(mapa["Entrada"], mapa["*"]);   
    bfs(mapa["Saida"]);
    ans += path(mapa["Saida"], mapa["*"]);
    cout << ans-2 << '\n';
 
    return 0;
}
