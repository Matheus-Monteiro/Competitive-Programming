// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Balanço de Parênteses I
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1068

#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<int> p;
    string s;
    int e, d;

    while(cin >> s){
        e = d = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                p.push(s[i]);
                e++;
            }else
                if(s[i] == ')' and !p.empty())
                    p.pop();
            if(s[i] == ')')
                d++;
        }   
        cout << ((p.empty()and e == d) ? "correct" : "incorrect") << '\n';
        while(!p.empty())
            p.pop();
    }
    return 0;
}

