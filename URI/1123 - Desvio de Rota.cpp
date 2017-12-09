// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Desvio de Rota
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1123

#include <bits/stdc++.h>
using namespace std;
const int OO = (1 << 30);

int n, m;
int G[300][300];
int dist[300];
bool cor[300];

int dijkstra(int u, int v)
{
    for(int i = 0; i < n; i++)
        cor[i] = 0, dist[i] = OO;
    dist[u] = 0;
    int a = u, m;
    while(a != v)
    {
        for(int i = 0; i < n; i++)
            if(G[a][i] != OO and dist[a] + G[a][i] < dist[i])
                dist[i] = dist[a] + G[a][i];
        cor[a] = 1;
        m = OO;
        for(int i = 0; i < n; i++)
            if(dist[i] < m and !cor[i])
                m = dist[i], a = i;
        if(m == OO)
            return OO;
    }
    return dist[v];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int u, v, w, c, k;

    while(cin >> n >> m >> c >> k and (n+m+c+k))
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                G[i][j] = OO;
        while(m--)
        {
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = w;
        }
        for(int i = 0; i < c; i++)
        {
            dist[i] = 0;
            for(int j = i; j < c-1; j++)
                dist[i] += G[j][j+1];
        }
        for(int i = 0; i < c; i++)
        {
            for(int j = 0; j < n; j++)
                G[i][j] = OO;    
            G[i][c-1] = dist[i];
        }
        cout << dijkstra(k, c-1) << '\n';    
    }
    
    return 0;
}
