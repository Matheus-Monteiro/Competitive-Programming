// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Polícia e Ladrão
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1905

#include <bits/stdc++.h>

using namespace std;

int m[6][6], n;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int floodfill(int r, int c)
{
    if(r >= 5 or r < 0 or c >= 5 or c < 0)
        return 0;
    if(m[r][c] == 1 or m[r][c] == -1)
        return 0;
    if(r == 4 and c == 4)
        return 1;
    m[r][c] = -1;
    int ans = 0;
    for(int i = 0; i < 4; i++)
        ans += floodfill(r+dr[i], c+dc[i]);
    return ans;
}

int main()
{
    cin >> n;
    
    while(n--)
    {
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                cin >> m[i][j];
        cout << (floodfill(0, 0) ? "COPS" : "ROBBERS") << '\n';
    }

    return 0;
}
