// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Base 32
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1869

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

stack<ulli> s;

int main(){
    ulli n;   
    while(cin >> n and n){
        while(n){
            s.push(n%32);
            n = n/32;
        }
        while(!s.empty()){
            if(s.top() > 9)
                cout << char(s.top()-10+65);
            else
                cout << s.top();
            s.pop();
        }
        cout << '\n';
    }
    cout << 0 << '\n';
    
    return 0;
}
