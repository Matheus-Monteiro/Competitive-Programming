// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Fantástico Jaspion
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1449

#include <bits/stdc++.h>

using namespace std;

int main(){
    map<string, string> mapa;
    string s1, s2;
    vector<string> v;
    int n, m, t;
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin.ignore();
        while(n--){
            getline(cin, s1);
            getline(cin, s2);
            mapa[s1] = s2;
        }
        
        while(m--){
            v.clear();
            getline(cin, s1);
            istringstream iss(s1);
            do{
                iss >> s2;
                if(iss) v.push_back(s2);
            }while(iss);
        
            for(int i = 0; i < v.size(); i++){
                auto it = mapa.find(v[i]);
                if(it != mapa.end())
                    cout << it->second;
                else
                    cout << v[i];
                if(i < v.size()-1)
                    cout << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        mapa.clear();
    }
    return 0;
}
