// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Jogo de Boca
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2667

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int ans = 0;
    
    cin >> str;
    
    for(int i = 0; i < str.size(); i++)
        ans += (str[i]-'0');
    cout << ans%3 << '\n';
        
    return 0;
}
