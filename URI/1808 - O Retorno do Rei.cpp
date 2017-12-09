// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Retorno do Rei
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1808

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int sum = 0, z = 0;
    
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        s[i+1] == '0' ? sum += 10, z++: sum += s[i]-'0' ;
    cout << setprecision(2) << fixed << (double)sum/(double)(s.size()-z) << '\n';

    return 0;
}
