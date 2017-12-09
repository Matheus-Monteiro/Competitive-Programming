// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Dona Minhoca
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1711

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10; 
const int OO = (1 << 30);
typedef pair<int, int> ii;

int n, m;
vector<ii> G[MAX];
set<ii> s;
int d[MAX], cor[MAX], low[MAX], pai1[MAX], peso1[MAX], pai2[MAX], peso2[MAX], cycle_peso[MAX], tempo;

int find1(int x){return x == pai1[x] ? x : pai1[x] = find1(pai1[x]);}

void join1(int x, int y)
{
    y = find1(y);
    x = find1(x);
    if(x == y) return;
    if(peso1[x] > peso1[y])
        pai1[y] = x;
    else if(peso1[x] < peso1[y])
        pai1[x] = y;
    else
        pai1[x] = y, peso1[y]++;;
}

int find2(int x){return x == pai2[x] ? x : pai2[x] = find2(pai2[x]);}

void join2(int x, int y)
{
    y = find2(y);
    x = find2(x);
    if(x == y) return;
    if(peso2[x] > peso2[y])
        pai2[y] = x;
    else if(peso2[x] < peso2[y])
        pai2[x] = y;
    else
        pai2[x] = y, peso2[y]++;;
}

void dfs(int u, int p)
{
    cor[u] = 1;
    d[u] = low[u] = tempo++;
    for(ii v : G[u])
        if(!cor[v.second])
        {
            dfs(v.second, u);
            low[u] = min(low[u], low[v.second]);
            if(low[v.second] > d[u])
                join1(u, v.second);
        }
        else if(v.second != p)
            low[u] = min(low[u], d[v.second]);
}

int weight(int u)
{
    int w = 0;
    for(ii v : G[u])
        if(find1(u) != find1(v.second) and s.find({u, v.second}) == s.end())
        {
            join2(u, v.second);
            s.insert({u, v.second});
            s.insert({v.second, u});
            w += v.first;
            w += weight(v.second);
        }
    return w;
}

int dijkstra(int v, int pm)
{
    int ans = OO;
    priority_queue<ii> pq;
    for(int i = 0; i < n; i++)
        d[i] = OO;
    d[v] = 0;
    pq.push({0, v});
    while(!pq.empty())
    {
        int u = pq.top().second;
        int dd = -pq.top().first;
        pq.pop();
        if(dd > d[u]) continue;
        for(ii w : G[u])
            if(d[w.second] > d[u] + w.first)
            {
                if(find1(u) != find1(w.second) and cycle_peso[find2(u)] >= pm)
                    ans = min(2*d[u] + cycle_peso[find2(u)], ans);
                d[w.second] = d[u] + w.first;
                pq.push({-d[w.second], w.second});
            }    
    }
    return ans == OO ? -1 : ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int u, v, w, q;

    while(cin >> n >> m)
    {
        while(m--)
        {
            cin >> u >> v >> w;
            G[u-1].push_back({w, v-1});
            G[v-1].push_back({w, u-1});
        }
        for(int i = 0; i < n; i++)
            pai1[i] = pai2[i] = i, peso1[i] = peso2[i] = cor[i] = 0;
        tempo = 0;
        for(int i = 0; i < n; i++)
            if(!cor[i])
                dfs(i, -1);
        s = set<ii>();
        for(int i = 0; i < n; i++)
        {
            int ppp = weight(i);
            if(ppp)
                cycle_peso[find2(i)] = ppp;
        }
        cin >> q;
        while(q--)
        {
            cin >> u >> w;
            cout << dijkstra(u-1, w) << '\n';
        }
        for(int i = 0; i < n; i++)
            G[i].clear();
    }
    
    return 0;
}
