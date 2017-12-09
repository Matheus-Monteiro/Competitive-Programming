// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Olimpíadas de Natal
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2018

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<string, iii> siii;

map<string, iii> placar;

bool f(siii a, siii b){
    if(a.second.first != b.second.first)
        return a.second.first > b.second.first;
    else if(a.second.second.first != b.second.second.first)
        return a.second.second.first > b.second.second.first;
    else if(a.second.second.second != b.second.second.second)
        return a.second.second.second > b.second.second.second;
    else
        return a.first < b.first;
}

int main(){
    int o, p, b;
    string str;
    
    while(getline(cin, str)){
        iii *aux;
        
        getline(cin, str);
        aux = &placar[str];
        aux->first++;
        
        getline(cin, str);
        aux = &placar[str];
        aux->second.first++;
        
        getline(cin, str);
        aux = &placar[str];
        aux->second.second++;
    }
   
    vector<siii> v(placar.begin(), placar.end());
    
    sort(v.begin(), v.end(), f);
    
    cout << "Quadro de Medalhas" << '\n';
    for(int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second.first << ' ' << v[i].second.second.second <<  '\n';
   
    return 0;
}
