// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Reunião
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2372

#include <bits/stdc++.h>
const int INFINITO = 1e7;

using namespace std;

int n, m, x, y, d;
int G[110][110];

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            (i != j) ? G[i][j] = INFINITO : G[i][j] = 0;
            
    while(m--){
        cin >> x >> y >> d;
        G[x][y] = d;
        G[y][x] = d;
    }
    
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
    
    int _m = INFINITO, m;
    for(int i = 0; i < n; i++){
        m = 0;
        for(int j = 0; j < n; j++)
            m = max(m, G[i][j]);
        _m = min(_m, m);
    }
    cout << _m << '\n';
    
    return 0;
}
