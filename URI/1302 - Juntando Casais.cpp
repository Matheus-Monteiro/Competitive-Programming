// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Juntando Casais
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1302

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;

int n, MAX_LOG;
vector<int> G[MAX], G_t[MAX];
int pai[MAX], tam[MAX], dist[MAX], anc[MAX][30], deft[MAX];
int ciclo[MAX], cor[MAX];

int find(int x)
{
    return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
        ciclo[x] = true;
    else pai[x] = y;
}

int dfs(int v, int d)
{
	int maxi = d;
    dist[v] = d;
    cor[v] = true;
    ciclo[v] = true;
    for(const int &u : G[v])
        if(!cor[u])
            maxi = max(maxi, dfs(u, d + 1));
    return tam[v] = maxi;
}

void dfs2(int v, int p, int d, int c)
{
    deft[v] = d;
    cor[v] = c;
    anc[v][0] = p;
    if(d) MAX_LOG = max(MAX_LOG, (int)log2(d));
    for(const int &u : G_t[v])
        if(v != p and !ciclo[u])
            dfs2(u, v, d + 1, c);
}

int dist_ciclo(int u, int v)
{
	/*cout << "hehe\n";
	cout << u << ' ' << v << " | " << dist[u] <<  ' ' << dist[v] << '\n';
	cout << abs(dist[u]-dist[v]) << ' ' << abs((tam[v]+1)-abs(dist[u]-dist[v])) << ' ' << tam[u]+1 << '\n';
	cout << "hehe\n";*/
    return min(abs(dist[u]-dist[v]), abs((tam[v]+1)-abs(dist[u]-dist[v])));
}

void build()
{
    memset(anc, -1, sizeof anc);
    memset(cor, 0, sizeof(cor));
    MAX_LOG = 0;
    for(int i = 1; i <= n; i++)
        if(ciclo[i])
            dfs2(i, -1, 0, i);
    for(int j = 1; j <= MAX_LOG; j++)
        for(int i = 1; i <= n; i++)
            if(anc[i][j-1] != -1)
                anc[i][j] = anc[anc[i][j-1]][j-1];
}

int walk(int v, int k)
{
    while(k) v = anc[v][(int)log2(k&-k)], k -= k&-k;
    return v;
}

int lca(int u, int v)
{
    if(deft[u] > deft[v]) u = walk(u, deft[u]-deft[v]);
    if(deft[u] < deft[v]) v = walk(v, deft[v]-deft[u]);
    if(u == v) return u;
    for(int i = MAX_LOG; i >= 0; i--)
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    return anc[u][0];
}

int main()
{
    int aux;

    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i++)
            pai[i] = i;
        memset(ciclo, 0, sizeof(ciclo));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &aux);
            G[i].push_back(aux);
            G_t[aux].push_back(i);
            join(i, aux);
        }
        memset(cor, 0, sizeof(cor));
        for(int i = 1; i <= n; i++) 
            if(!cor[i] and ciclo[i])
                dfs(i, 0);
        build();
        int q, x, y;      
        scanf("%d", &q);
        
        while(q--)
        {
            scanf("%d %d", &x, &y);
            if(find(x) != find(y))
                printf("-1\n");
            else if(cor[x] == cor[y])
                printf("%d\n", deft[x] + deft[y] - 2*deft[lca(x, y)]);
            else
                printf("%d\n", deft[x] + deft[y] + dist_ciclo(cor[x], cor[y]));
        }
        for(int i = 0; i <= n; i++)
        {
            G[i].clear();
            G_t[i].clear();
        }
    }
    return 0;
}
