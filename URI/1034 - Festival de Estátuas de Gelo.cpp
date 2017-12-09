// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Festival de Estátuas de Gelo
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1034

#include <bits/stdc++.h>

using namespace std;

int pd[30][1000010];
vector<int> v;

int coin(int x)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j <= x; j++)
        {
            if(!i)
                pd[i][j] = j;
            else
            {
                if(j < v[i])
                    pd[i][j] = pd[i-1][j];
                else
                    pd[i][j] = min(pd[i-1][j], pd[i][j-v[i]]+1);    
            }
        }
    }
    return pd[v.size()-1][x];
}

int main()
{
    int n, m, t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        v.resize(n);
        for(int &p : v)
            cin >> p;
        sort(v.begin(), v.end());
        cout << coin(m) << '\n';
        v.clear();
    }
    
    return 0;
}
