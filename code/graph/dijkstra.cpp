#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
const int MAX = 1e5;

typedef pair<int, int> ii;

int n, m;
int dist[MAX];
vector<ii> G[MAX];

int dijkstra(int v, int z)
{
    memset(dist, 63, sizeof(dist));
    dist[v] = 0;
    priority_queue<ii> pq;
    pq.push({0, v});
    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        if(u == z) return d;
        for(int i = 0; i < G[u].size(); i++)
        {
            int w = G[u][i].second, _d = G[u][i].first;
            if(dist[w] > d + _d)
            {
                dist[w] = d + _d;
                pq.push({-dist[w], w});
            }
        }
    }
    return OO;
}

int main()
{
    int u, v, w;

    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    cin >> u >> v;
    cout << dijkstra(u-1, v-1) << '\n';
    
    return 0;
}
