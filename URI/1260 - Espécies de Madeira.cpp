// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Espécies de Madeira
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1260

#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> si;

map<string, int> mp;

int main()
{
    int n;
    string str;
    bool flag = false;
    
    cin >> n;
    cin.ignore();
    getline(cin, str);
    while(n--)
    {
        int cont = 0;
        while(getline(cin, str) and str != "")
        {
            mp[str]++;
            cont++;
        }
        vector<si> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](si a, si b){return a.first < b.first;});
        if(flag) cout << '\n';
        else flag = true;
        for(int i = 0; i < v.size(); i++)
           cout << fixed << setprecision(4) << v[i].first << ' ' << (100.0*(double)v[i].second/(double)cont) << '\n';
        mp.clear();
    }
    
    return 0;
}
