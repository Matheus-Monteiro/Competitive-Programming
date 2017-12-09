// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Guildas
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1527

#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

int pai[MAXN], peso[MAXN], pontos[MAXN];

int find(int x){
    if(pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y)
        return;
    
    if(peso[x] < peso[y]){
        pai[x] = y;
        pontos[y] += pontos[x];
    }
    if(peso[x] > peso[y]){
        pai[y] = x;
        pontos[x] += pontos[y];
    }
    if(peso[x] == peso[y]){
        pai[x] = y;
        peso[y]++;
        pontos[y] += pontos[x];
    }
}

int main(){
    int n, m, q, a, b, aux1, aux2, p1, p2, vitoria;
    
    while(cin >> n >> m && n != 0 || m != 0){
    
        for(int i = 1; i <= n; i++)
            pai[i] = i;
        memset(peso, 0, (n+2)*(sizeof(int)));
        
        for(int i = 1; i <= n; i++)
            cin >> pontos[i];
        
        vitoria = 0;
        while(m--){
            cin >> q >> a >> b;
            
            if(q == 1){
                join(a, b);
            }else{
                aux1 = find(a);
                aux2 = find(b);
                
                p1 = pontos[aux1];
                p2 = pontos[aux2];
                
                if(p1 > p2 && find(1) == aux1)
                    vitoria++;
                if(p1 < p2 && find(1) == aux2)
                    vitoria++;
            }
        }
        cout << vitoria << endl;
    }
    return 0;
}
