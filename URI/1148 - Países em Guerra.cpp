// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Países em Guerra
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1148

#include <bits/stdc++.h>
using namespace std;
const int OO = (1 << 30);

int n, m;
int G[550][550];
int dist[550];
bool cor[550];

int dijkstra(int v, int u)
{
    for(int i = 0; i < n; i++) dist[i] = OO, cor[i] = 0;
    dist[v] = 0;
    int a = v, m;
    while(a != u)
    {
        for(int i = 0; i < n; i++)
            if(G[a][i] != OO and dist[a] + G[a][i] < dist[i])
                dist[i] = dist[a] + G[a][i];
        cor[a] = 1;
        m = OO;
        for(int i = 0; i < n; i++)
            if(dist[i] < m and !cor[i])
                m = dist[i], a = i;
        if(m >= OO)
            return OO;
    }
    return dist[u];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int u, v, w;    
    
    while(cin >> n >> m and (n+m)) 
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                G[i][j] = OO;
        while(m--)
        {
            cin >> u >> v >> w;
            u--; v--;
            G[u][v] = w;
            if(G[v][u] != OO)
                G[u][v] = G[v][u] = 0;
        }
        cin >> w;
        while(w--)
        {
            cin >> u >> v;
            int d = dijkstra(u-1, v-1);
            if(d == OO)
                cout << "Nao e possivel entregar a carta" << '\n';
            else
                cout << d << '\n';
        }
        cout << '\n';
    }
    return 0;
}
