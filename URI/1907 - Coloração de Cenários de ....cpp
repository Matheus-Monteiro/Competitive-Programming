// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Coloração de Cenários de ...
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1907

#include <bits/stdc++.h>
using namespace std;

int n, m;
string G[1030];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c)
{
    if(r >= n or r < 0 or c >= m or c < 0 or G[r][c] != '.')
        return;
    G[r][c] = '#';
    for(int i = 0; i < 4; i++)
        floodfill(r+dr[i], c+dc[i]);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> G[i];
        
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(G[i][j] == '.')
            {
                ans++;
                floodfill(i, j);
            }
    cout << ans << '\n';
   
    return 0;
}
