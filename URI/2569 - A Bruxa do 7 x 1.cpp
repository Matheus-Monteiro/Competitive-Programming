// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Bruxa do 7 x 1
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2569

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, ans;
    char c;
    string s, aux;

    cin >> a >> c >> b;
    
    s = to_string(a);
    for(int i = 0; i < s.size(); i++)
        if(s[i] != '7')
            aux.push_back(s[i]);
        else
            aux.push_back('0');
    a = stoi(aux);
    
    aux.clear();
    s = to_string(b);
    for(int i = 0; i < s.size(); i++)
        if(s[i] != '7')
            aux.push_back(s[i]);
        else
            aux.push_back('0');
    b = stoi(aux);
    
    if(c == 'x')
        ans = a*b;        
    else
        ans = a + b;
    s = to_string(ans);
    
    aux.clear();
    for(int i = 0; i < s.size(); i++)
        if(s[i] != '7')
            aux.push_back(s[i]);
        else
            aux.push_back('0');
    ans = stoi(aux);
    cout << ans << '\n';
  
    return 0;
}
