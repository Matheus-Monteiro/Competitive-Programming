// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Etiquetas de Noel
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2482

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    map<string, string> mapa;
    int n, m;
    string str1, str2;
    
    cin >> n;
    cin.ignore(); 
    while(n--){
        getline(cin, str1);
        getline(cin, str2);
        mapa[str1] = str2;
    }
    cin >> m;
    cin.ignore();
    while(m--){
        getline(cin, str1);
        getline(cin, str2);
        cout << str1 << '\n';
        cout << mapa[str2] << '\n';
        cout << '\n';
    }
    

    return 0;
}
