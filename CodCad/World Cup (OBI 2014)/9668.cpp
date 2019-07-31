#include <iostream>
#include <algorithm>
#define MAXN 50500
#define MAXM 200200

using namespace std;

struct t_aresta{
    int dis;
    int x, y;
};

bool comp(t_aresta a, t_aresta b){
    return a.dis < b.dis;
}

int n, m;
t_aresta aresta[MAXM];

int pai[MAXN], peso[MAXN];

t_aresta mst[MAXM];

int find(int x){
    if(pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
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
    int f, r;
    
    cin >> n >> f >> r;
    m = f + r;
    
    for(int i = 1; i <= m; i++){
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
    }
    for(int i = 1; i <= n; i++)
        pai[i] = i; 
    
    sort(aresta+1, aresta+f+1, comp);
    sort(aresta+f+1, aresta+m+1, comp);
   
    int size = 0, qtd = 0;
 
    for(int i = 1; i <= m; i++){
        if(find(aresta[i].x) != find(aresta[i].y)){
            join(aresta[i].x, aresta[i].y);
            mst[++size] = aresta[i];
            qtd += aresta[i].dis;
        }
    }
    cout << qtd << endl;
    
    return 0;
}

