// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Apagando e Ganhando
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1084

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int n, d;
    string str;
    stack<int> p;
    
    while(cin >> n >> d and (n or d)){
        cin >> str;
        for(int i = 0; i < n; i++){
            if(d){
                if(!p.empty()){
                    while(!p.empty() and d and str[i]-48 > p.top()){
                        d--;
                        p.pop();
                    }
                    p.push(str[i]-48);
                }else if(d)
                        p.push(str[i]-48);
            }else
                p.push(str[i]-48);
        }   
        stack<int> s_;
        while(!p.empty()){
            if(!d)
                s_.push(p.top());
            else
                d--;
            p.pop();
        }
        while(!s_.empty()){
            cout << s_.top();
            s_.pop();
        }
        cout << '\n';
    }
    return 0;
}
