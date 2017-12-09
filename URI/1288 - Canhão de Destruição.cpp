// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Canhão de Destruição
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1288

#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int *p, int *v, int p_max){
    int T[n+1][p_max+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= p_max; w++){
            if(i == 0 or w == 0)
                T[i][w] = 0;
            else{
                if(p[i-1] <= w)
                    T[i][w] = max(v[i-1]+T[i-1][w-p[i-1]], T[i-1][w]);    
                else
                    T[i][w] = T[i-1][w];
            }
        }
    }
    return T[n][p_max];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t, n, w, wc;
    int peso[100], val[100];
    
    cin >> t;
    
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> val[i] >> peso[i];   
        cin >> w >> wc;
        cout << (knapsack(n, peso, val, w) >= wc ? "Missao completada com sucesso" : "Falha na missao") << '\n';
    }
    
    return 0;
}
