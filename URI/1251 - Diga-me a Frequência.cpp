// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Diga-me a Frequência
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1251

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<char,int> a, pair<char,int> b){
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    map<char, int> mapa;
    string str;
    bool ok = false;
    
    while(getline(cin, str)){
        cout << (ok ? "\n" : "");
        for(int i = 0; i < str.size(); i++)
            mapa[str[i]]++;
        vector<pair<char,int> >  copymap(mapa.begin(), mapa.end());
        sort(copymap.begin(), copymap.end(), comp);
        for(auto it = copymap.begin(); it != copymap.end(); it++)
            cout << (int)it->first << " " << it->second << "\n";
        
        mapa.clear();
        ok = true;
    }
    
    return  0;
}
