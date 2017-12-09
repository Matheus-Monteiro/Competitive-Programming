// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tabelas Hash
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1256

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v;
    int n, m, c, aux;
    bool ok = false;

    cin >> n;
    while(n--){
        if(ok) cout << '\n';
        else ok = true;
        cin >> m >> c;
        v.resize(m);
        while(c--){
            cin >> aux;
            v[aux%m].push_back(aux);
        }
        for(int i = 0; i < m; i++){
            cout << i << " -> ";
            for(int j = 0; j < v[i].size(); j++)
                cout << v[i][j] << " -> ";   
            cout << "\\" << '\n';
        }
        v.clear();
    }

    return 0;
}

