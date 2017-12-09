// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Bicho da Goiaba
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2485

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
int G[105][105];
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};


int solve(int r, int c)
{
    queue<iii> q;
    set<ii> s;
    q.push({0, {r, c}});
    s.insert({r, c});
    int ans = 0;
    while(!q.empty())
    {
        int d = q.front().first+1;
        r = q.front().second.first;
        c = q.front().second.second;
        q.pop();
        for(int i = 0; i < 8; i++)
            if(r+dr[i] < n and r+dr[i] >= 0 and c+dc[i] < m and c+dc[i] >= 0 and G[r+dr[i]][c+dc[i]] and s.find({r+dr[i], c+dc[i]}) == s.end()){
                q.push({d, {r+dr[i], c+dc[i]}});
                ans = max(ans, d);
                s.insert({r+dr[i], c+dc[i]});  
            }              
    }
    return ans;
}

int main()
{
    int t;
    
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int i, j;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)  
                cin >> G[i][j];    
        cin >> i >> j;
        cout << solve(i-1, j-1) << '\n';
    }
        
    return 0;
}

