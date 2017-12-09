// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Árvore de Natal
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2026

#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;

int knapsack(int n, int *v, int *p, int p_max)
{
    int pd[n+1][p_max+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= p_max; j++)
        {
            if(!i or !j)
                pd[i][j] = 0;
            else
            {
                if(j < p[i-1])
                    pd[i][j] = pd[i-1][j];
                else
                    pd[i][j] = max(pd[i-1][j], pd[i-1][j-p[i-1]]+v[i-1]);
            }
        }
    }
    return pd[n][p_max];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t, n, p_max, c = 1;
    int v[MAX], p[MAX];
    bool flag = false;
    
    cin >> t;
    
    while(t--)
    {
        cin >> n >> p_max;
        for(int i = 0; i < n; i++)
            cin >> v[i] >> p[i];
        cout << "Galho " << c++ << ':' << '\n';
        cout << "Numero total de enfeites: " << knapsack(n, v, p, p_max) << '\n' << '\n';
    }
    

    return 0;
}
