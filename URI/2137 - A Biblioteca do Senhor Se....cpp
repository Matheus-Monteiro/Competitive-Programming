// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Biblioteca do Senhor Se...
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2137

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> v;
    
    while(cin >> n)
    {
        v.resize(n);
        for(string &s : v)
            cin >> s;
        sort(v.begin(), v.end());
        for(const string &s : v)
            cout << s << '\n';
        v.clear();
    }
    
    return 0;
}
