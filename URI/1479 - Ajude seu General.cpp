// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ajude seu General
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1479

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
const int INF = (1<<30);
typedef pair<int, int> pii;

int n, m;
vector<pii> G[MAX];
int dist[MAX];
bool visit[MAX];

int dijkstra(int v, int z){
    for(int i = 0; i < n; i++) dist[i] = INF, visit[i] = false;
    dist[v] = 0;
    priority_queue<pii> pq;
    pq.push({0, v});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(u == z) return dist[u];
        if(!visit[u]){
            visit[u] = true;
            for(pii it : G[u]){
                int w = it.second, d = it.first;
                if(dist[w] > dist[u] + d){
                    dist[w] = dist[u] + d;
                    pq.push({-dist[w], w});
                }
            }
        }
    }
    return INF;
}

int main(){
    int u, v, w, q;
    char c;
    while(cin >> n >> m and (n or m)){
        while(m--){
            cin >> u >> v >> w;
            u--; v--;
            G[u].push_back({w, v});
        }
        cin >> q;
        while(q--){
            cin >> c;
            if(c == 'R'){
                cin >> u >> v;
                u--; v--;
                for(int i = 0; i < G[u].size(); i++)
                    if(G[u][i].second == v)
                        G[u].erase(G[u].begin()+i);
            }else{
                if(c == 'I'){
                    cin >> u >> v >> w;
                    u--; v--;
                    G[u].push_back({w, v});
                }else{
                    cin >> w;
                    int d = dijkstra(0, w-1);
                    cout << (d != INF ? d : -1) << '\n';
                }
            }
        }
        for(int i = 0; i < n; i++) G[i].clear();
        cout << '\n';
    }   
    return 0;
}
