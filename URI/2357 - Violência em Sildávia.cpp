// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Violência em Sildávia
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2357

#include <bits/stdc++.h>
const int MAX = 1e6;

using namespace std;

int pai[MAX], peso[MAX], a, b, n, m;

int find(int x){
    return ((pai[x] == x) ? x : pai[x] = find(pai[x]));
}

bool join(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return true;
    if(peso[x] > peso[y])
        pai[y] = x;
    if(peso[x] < peso[y])
        pai[x] = y;
    if(peso[x] == peso[y]){
        pai[x] = y;
        peso[y]++;
    }
    return false;
}

int main(){
    while(cin >> n >> m){ 
        for(int i = 0; i <= n+2; i++){
            pai[i] = i;
            peso[i] = 0;
        }
        bool ciclo = false;
        while(m--){
            cin >> a >> b;
            if(join(a-1, b-1))
                ciclo = true;
        }   
        cout << (ciclo ? "Inseguro" : "Seguro") << '\n';
    }
    return 0;
}
