// o peso das arestas eh 0 ou 1

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
const int OO = 0x3f3f3f3f;
typedef pair<int, int> ii;

int n, m;
vector<ii> G[MAX];
int dist[MAX];
deque<int> dq;

void zeroOneBfs(int v)
{
    memset(dist, 63, sizeof(dist));
    dist[v] = 0;
    dq.push_back(v);
    while(!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        for(int i = 0; i < G[u].size(); i++)
        {
            int w = G[u][i].first, d = G[u][i].second;
            if(dist[w] > dist[u] + d)
            {
                dist[w] = dist[u] + d;
                if(!d) dq.push_front(w);
                else dq.push_back(w);
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << dist[i] << ' ';
    puts("");
}

int main()
{
    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w; u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    zeroOneBfs(0);

    return 0;
}
