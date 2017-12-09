// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Mensagem de Will
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2523

#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    string str, ans;
    int i, n;
    
    while(cin >> str)
    {
        cin >> n;
        while(n--)
        {
            cin >> i;
            ans += str[i-1];
        }
        cout << ans << '\n';
        ans.clear();
    }
    
    return 0;
}
