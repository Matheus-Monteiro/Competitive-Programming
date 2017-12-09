// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pouca Frequência
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1277

#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<string, string> > chamada;
    vector<string> res;
    string str;
    int t, n, pre, jus;
    double por;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; i++){
            cin >> str;
            chamada.push_back(make_pair(str, " "));
        }
        for(int i = 0; i < n; i++){
            cin >> str;
            chamada[i].second = str;
        }
        for(int i = 0; i < n; i++){
            pre = jus = 0;
            for(int j = 0; j < chamada[i].second.size(); j++){
                if(chamada[i].second[j] == 'P')
                    pre++;
                else
                    if(chamada[i].second[j] == 'M')
                        jus++;
            }
            por = (double)pre/(chamada[i].second.size()-jus);
            por *= 100;
            if(por < 75.0)
                res.push_back(chamada[i].first);
        }
        for(int i = 0; i < res.size(); i++){
            cout << res[i];
            if(i < res.size()-1)
                cout << " ";
        }
        cout << "\n";
        chamada.clear();
        res.clear();
    }
    
    return 0;
}
