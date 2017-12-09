// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Gerando Permutações Orden...
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1401

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    
    cin >> n;
    while(n--)
    {
        cin >> str;
        sort(str.begin(), str.end());
        do{
            cout << str << '\n';
        }while(next_permutation(str.begin(), str.end()));
        cout << '\n';
    }
    
    return 0;
}
