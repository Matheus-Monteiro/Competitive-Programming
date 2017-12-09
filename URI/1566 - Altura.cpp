// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Altura
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1566

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int t, n;
    vector<int> v;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        v.resize(n);
        for(int &p : v)
            cin >> p;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            cout << v[i];
            if(i < v.size()-1)
                cout << " ";
        }
        cout << "\n";
        v.clear();
    }
    
    
    return 0;    
}

