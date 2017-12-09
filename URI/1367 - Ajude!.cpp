// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ajude!
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1367

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ac[26], wa[26];
    int n, num, q;
    char c;
    string s;
    
    while(cin >> n and n)
    {
        q = 0;
        memset(ac, 0, sizeof(ac));
        memset(wa, 0, sizeof(wa));
        while(n--)
        {
            cin >> c >> num >> s;
            if(s == "correct")
                ac[c-'A'] += (num + wa[c-'A']), q++;
            else
                wa[c-'A'] += 20;
        }
        int soma = 0;
        for(int i = 0; i < 26; i++)
            soma += ac[i];
        cout << q << ' ' << soma << '\n';
    }
    
    return 0;
}
