// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Mergulho
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1471

#include <bits/stdc++.h>

using namespace std;

int v[10010];

int main()
{
    int n, num, r;
    
    while(cin >> n >> r)
    {
        memset(v, 0, (n+1)*sizeof(int));
        bool flag = (n == r);
        while(r--)
        {
            cin >> num;
            v[num]++;
        }
        if(flag)
        {
            cout << '*' << '\n';
            continue;
        }
        for(int i = 1; i <= n; i++)
            if(!v[i])
                cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}
