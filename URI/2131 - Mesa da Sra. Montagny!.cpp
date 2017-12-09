// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Mesa da Sra. Montagny!
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2131

#include <bits/stdc++.h>
const int MAX = 1e6;

using namespace std;

vector<vector<int> > G;
int cor[MAX], n, m, x, y;
bool b;

void dfs(int u, int c){
    cor[u] = c;
    for(int i = 0; i < G[u].size() and !b; i++){
        int r  = G[u][i];
        if(!cor[r])
            dfs(r, (c == 1 ? 2 : 1));
        else
            b = (cor[r] == cor[u]);
    }
    cor[u] = -1;
}

void e_digrafo(){
    memset(cor, 0, (n+2)*sizeof(int));
    b = false;
    for(int i = 0; i < n and !b; i++)
        if(!cor[i])
            dfs(i, 1);
}

int main(){
    int ins = 1;
    
    while(cin >> n >> m){
    	G.resize(n+2);
        while(m--){
            cin >> x >> y;
            G[x-1].push_back(y-1);
            G[y-1].push_back(x-1);
        }
        e_digrafo();
        cout << "Instancia " << ins++ << '\n';
        cout << (!b ? "sim" : "nao") << '\n';
        cout << '\n';
        G.clear();
    }
    return 0;
}

