// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Combate à Dengue
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2088

#include <bits/stdc++.h>

using namespace std;
const double INF = (1<<30);

int n;
double dist[17][17], memo[17][1<<17];

double d(int x1, int y1, int x2, int y2){
    return hypot(x1 - x2, y1 - y2);
}

double solve(int id, int bitmask){
    if(bitmask == (1 << n)-1)
        return dist[id][0];
    if(memo[id][bitmask] != -1)
        return memo[id][bitmask];
        
    double ans = INF;
    for(int i = 0; i < n; i++)
        if(!(bitmask & (1 << i)))
            ans = min(ans, dist[id][i] + solve(i, bitmask | (1 << i)));
    return memo[id][bitmask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(cin >> n and n){
        n++;
        int x[n], y[n];
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                dist[i][j] = dist[j][i] = d(x[i], y[i], x[j], y[j]);
    
        for(int i = 0; i < n; i++)
            for(int j = 0; j < (1<<n); j++)
                memo[i][j] = -1;
        cout << setprecision(2) << fixed << solve(0, 1) << '\n';
    }
  
    return 0;
}
