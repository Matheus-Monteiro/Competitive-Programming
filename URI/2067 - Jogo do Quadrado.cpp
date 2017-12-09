// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Jogo do Quadrado
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2067

#include <bits/stdc++.h>
using namespace std;

int n, m;
int matriz[205][205];
int pd[205][205];

bool check(int k)
{
    bool fl = false;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(i+k-1 <= n and j+k-1 <= m and !(pd[i+k-1][j+k-1] - pd[i-1][j+k-1] - pd[i+k-1][j-1] + pd[i-1][j-1]))
                return true;
    return false;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> matriz[i][j];
            matriz[i][j] = matriz[i][j] ? 0 : 1;
        }   
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            pd[i][j] = pd[i-1][j] + pd[i][j-1] - pd[i-1][j-1] + matriz[i-1][j-1];

    int q, k;
    cin >> q;
    while(q--)
    {
        cin >> k;
        cout << (check(k) ? "yes\n" : "no\n");
    }

    return 0;
}
