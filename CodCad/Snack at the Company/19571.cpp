#include <bits/stdc++.h>
const int INF = 1e5;

using namespace std;

int a, b, d;
int n, m, G[260][260];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            G[i][j] = (i == j ? 0 : INF);
    
    while(m--){
        cin >> a >> b >> d;
        G[a][b] = d;
        G[b][a] = d;
    }
        
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    
    int dist_ma, dist = INF, p = -1;
    for(int i = 1; i <= n; i++){
        dist_ma = 0;
        for(int j = 1; j <= n; j++)
            dist_ma = max(dist_ma, G[i][j]);
        if(dist > dist_ma){
            dist = dist_ma;
            p = i;
        }
        dist = min(dist, dist_ma);
    }
    int r = 0;
    for(int i = 1; i <= n; i++)
        r = max(r, G[p][i]);
    cout << r << '\n';
    return 0;
}