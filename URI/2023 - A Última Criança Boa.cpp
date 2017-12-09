// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Última Criança Boa
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2023

#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<string, string> > v;
    string s, aux;

    while(getline(cin, s)){
        for(int i = 0; i < s.size(); i++)
            aux.push_back(tolower(s[i]));
        v.push_back({aux, s});
        aux.clear();
    }
    sort(v.begin(), v.end(), [](pair<string, string> a, pair<string, string> b){ return a.first < b.first;});
    cout << v[v.size()-1].second << '\n';
    return 0;
}

