// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Motoboy
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1286

#include <bits/stdc++.h>
using namespace std;

int K(int n, int *p, int *v, int p_max)
{
    vector<int> pd1, pd2;
    pd1.resize(p_max+1);
    pd2.resize(p_max+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= p_max; j++)
        {
            if(p[i-1] <= j)
                pd2[j] = max(pd1[j], pd1[j-p[i-1]]+v[i-1]);
            else 
                pd2[j] = pd1[j];
        }
        pd1 = pd2;
    }
    return pd2[p_max];
}

int main()
{
    int n, p_max, v[10000], p[10000];
    
    while(cin >> n >> p_max and n)
    {
        for(int i = 0; i < n; i++)
            cin >> v[i] >> p[i];
        cout << K(n, p, v, p_max) << " min." << '\n';
    }
    
    return 0;
}
