// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Estradas Escuras
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1152

#include <bits/stdc++.h>
#include <algorithm>
typedef long long int lli;

using namespace std;

const lli MAXN = 200200;
const lli MAXM = 200200;

struct t_aresta{
    lli dis;
    lli x, y;
};

bool comp(t_aresta a, t_aresta b){
    return a.dis < b.dis;
}

int n, m;
int peso[MAXN], pai[MAXN];
t_aresta aresta[MAXM];
t_aresta mst[MAXM];

int find(lli x){
    if(pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(lli a, lli b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return;
    if(peso[a] < peso[b])
        pai[a] = b;
    if(peso[a] > peso[b])
        pai[b] = a;
    if(peso[a] == peso[b]){
        pai[a] = b;
        peso[b]++;
    }
}

int main(){
    while(cin >> n >> m and m != 0 or n != 0){
    
        for(lli i = 0; i < m; i++)
            cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
            
        for(lli i = 0; i < n; i++)
            pai[i] = i;
        memset(peso, 0, (n+2)*(sizeof(lli)));
        
        sort(aresta, aresta+m, comp);
        
        lli aux = 0, c = 0, java = 0;
        for(lli i = 0; i < m; i++){
            if(find(aresta[i].x) != find(aresta[i].y)){
                join(aresta[i].x, aresta[i].y);
                mst[++aux] = aresta[i];
                c += aresta[i].dis;
            }
            java += aresta[i].dis;
        }
     
        cout << java-c << endl;
    }   
    return 0;
}
