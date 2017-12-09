// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Rota do Taxista
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1947

#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
typedef pair<int, int> pii;

int n, m, k, _dist[100000];
bool visit[100000];
vector<pii> G[100000];
vector<pii> rota;
int dist[17][17], memo[17][1 << 17];

int dijkstra(int v, int z){
    for(int i = 0; i < n; i++) _dist[i] = INF, visit[i] = false;
    _dist[v] = 0;
    priority_queue<pii> pq;
    pq.push({0, v});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(u == z) return _dist[u];    
        if(visit[u]) continue;
        for(pii it : G[u]){
            int w = it.second, d = it.first;
            if(_dist[w] > _dist[u] + d){
                _dist[w] = _dist[u] + d;
                pq.push({-_dist[w], w});
            }
        }
        visit[u] = true;
    }
}

int tsp(int id, int bitmask){
    if(bitmask == (1<<k)-1)
        return dist[id][0];
    if(memo[id][bitmask] != -1)
        return memo[id][bitmask];
        
    int ans = INF;
    for(int i = 0; i < k; i++)
        if(!(bitmask & (1<<i)))
            ans = min(ans, dist[id][i] + tsp(i, bitmask | (1<<i)));
    return memo[id][bitmask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int u, v, w;
    cin >> n >> m >> k;
    while(m--){
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    int custo_rota = 0, k_ = k;
    while(k_--){
        cin >> u >> v;
        u--; v--;
        custo_rota += dijkstra(u, v);
        rota.push_back({u, v});
    }   
    for(int i = 0; i < rota.size(); i++){
        dist[0][i+1] = dijkstra(0, rota[i].first);
        dist[i+1][0] = dijkstra(rota[i].second, 0);   
    }
    for(int i = 0; i < rota.size(); i++)
        for(int j = 0; j < rota.size(); j++)
            if(i != j)
                dist[i+1][j+1] = dijkstra(rota[i].second, rota[j].first);
    k++;
    memset(memo, -1, sizeof(memo));
    cout << tsp(0, 1) + custo_rota << '\n';
    
    return 0;
}
