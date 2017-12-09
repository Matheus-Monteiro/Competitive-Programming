// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pontos de Feno
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1261

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str, s;
    int m, n, aux, ans;
    map<string, int> mp;
    
    cin >> n >> m;
    
    while(n--)
    {
        cin >> str >> aux;
        mp[str] = aux;
    }
    
    while(m--)
    {
        ans = 0;
        while(cin >> s and s != ".")
            if(mp.find(s) != mp.end())
                ans += mp[s];
        cout << ans << '\n';
    }
    
    return 0;
}
