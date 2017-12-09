// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Dijkstra
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2653

#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> s;
    string str;
    
    while(cin >> str)
        s.insert(str);
    cout << s.size() << '\n';
    
    return 0;
}
