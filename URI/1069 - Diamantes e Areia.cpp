// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Diamantes e Areia
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1069

#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> p;
    string s;
    int c, t;
    
    cin >> t;
    while(t--){
        cin >> s;
        c = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<')
                p.push(s[i]);
            else
                if(s[i] == '>' and !p.empty()){
                    p.pop();
                    c++;
                }
        }   
        cout << c << '\n';
        while(!p.empty())
            p.pop();
    }
    return 0;
}

