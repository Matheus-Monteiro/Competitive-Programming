// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: 106 Milhas Para Chicago
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1655

#include <bits/stdc++.h>

using namespace std;

int n, m;
double G[105][105];

int main(){
    int a, b;
    double d, aux;
    
    while(cin >> n >> m and n){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                G[i][j] = 0;
        while(m--){
            cin >> a >> b >> d;
            G[a-1][b-1] = d;
            G[b-1][a-1] = d;
        }      
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(G[i][k]*G[k][j]*0.01 > G[i][j] and G[i][k]*G[k][j]*0.01)
                        G[i][j] = G[i][k]*G[k][j]*0.01;
        cout.precision(6);
        cout << fixed << G[0][n-1] << " percent" << '\n';
    }
        
    return 0;
}
