// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Lucro
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1310

#include <bits/stdc++.h>

using namespace std;

int c;

int kadane(vector<int> s){
    int resp = 0, maior = 0;
    for(int i = 0; i < s.size(); i++){
        maior = max(0, maior +s[i]);
        resp = max(maior, resp);
    }
    return resp;
}

int main(){
    int n, c, aux;
    vector<int> v;
    while(cin >> n){
        cin >> c;
        for(int i = 0; i < n; i++){
            cin >> aux;
            v.push_back(aux-c);
        }
        cout << kadane(v) << '\n';
        v.clear();
    }
    return 0;
}
