// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ciclofaixa
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2086

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fst first
#define snd second
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, q;
vector<iii> G;
vector<ii> mst[105];
int pai[105];

int find(int x){
    return pai[x] == x ? x : pai[x] = find(pai[x]);
}

void join(int x, int y){
    pai[find(x)] = find(y);
}

int get(int u, int v){
    if(u == v)
        return 0;
    queue<iii> q;
    q.push({u, {u, -(1<<30)}});
    
    while(!q.empty()){
        int node = q.front().fst, parent = q.front().snd.fst, value = q.front().snd.snd;
        q.pop();
        if(node == v)
            return value;
        for(int i = 0; i < mst[node].size(); i++)
            if(mst[node][i].fst != parent)
                q.push({mst[node][i].fst, {node, max(value, mst[node][i].snd)}});
    }
    return 0;
}

int main(){    
    while(cin >> n >> m and (n or m)){
        for(int i = 0; i < n; i++)
            mst[i].clear(), pai[i] = i;
        int u, v, w;    
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            G.pb({w, {u-1, v-1}});
        }
        sort(G.begin(), G.end());
        for(int i = 0; i < m; i++){
            u = G[i].snd.fst;
            v = G[i].snd.snd;
            if(find(u) != find(v)){
                join(u, v);
                mst[u].pb({v, G[i].fst});
                mst[v].pb({u, G[i].fst});
            }
        }
        cin >> q;
        while(q--){
            cin >> u >> v;
            cout << get(u-1, v-1) << '\n';
        }
        G.clear();
    }   

    return 0;
}
