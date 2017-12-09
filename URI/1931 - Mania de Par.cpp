// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Mania de Par
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1931

#include <bits/stdc++.h>
#define gc getchar_unlocked
const int MAX = 1e6;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int> ii;

int n, m;
vector<ii> G[MAX], G_aux[MAX];
int dist[MAX];
queue<int> fila;
int inqueue[MAX];

void shortestPathFasterAlgorithm(int v)
{
    memset(dist, 63, sizeof(dist));
    dist[v] = 0;
    fila.push(v);
    inqueue[v] = 1;
    while(!fila.empty())
    {
        int u = fila.front();
        fila.pop();
        inqueue[u] = 0;
        for(int i = 0; i < G_aux[u].size(); i++)
        {
            int w = G_aux[u][i].second, d = G_aux[u][i].first;
            if(dist[w] > dist[u] + d)
            {
                dist[w] = dist[u] + d;
                if(!inqueue[w])
                {
                    fila.push(w);
                    inqueue[w] = 1;
                }
            }
        }
    }
}

void funcao(){
    for(int i = 0; i < n; i++){
        for(pair<int,int> it : G[i]){
            int v = it.second;
            int dist1 = it.first;
            bool ok = G[v].size();
            if(ok){
                for(pair<int,int> it2 : G[v]){
                    int u = it2.second;
                    int dist2 = it2.first;
                    G_aux[i].push_back({dist1+dist2, u});
                    G_aux[u].push_back({dist1+dist2, i});  
                }
            }
        }    
    }
}

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(; c < 48 or c > 57; c = gc());
    for(; c >= 48 and c <= 57; c = gc())
        x = (x << 1) + (x << 3) + c - 48;
}

int main(){
    int u, v, w;
    scanint(n); scanint(m);
    while(m--){
        scanint(u); scanint(v); scanint(w);
        u--; v--;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    funcao();
    shortestPathFasterAlgorithm(0);
    printf("%d\n", dist[n-1] == INF ? -1 : dist[n-1]);
    
    return 0;
}
