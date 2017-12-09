// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Saltos Ornamentais
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2311

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    double g, v[7];
    string str;
    
    cin >> n;
    
    while(n--){
        cin >> str >> g;
        for(int i = 0; i < 7; i++) cin >> v[i];
        sort(v, v+7);
        double aux = 0.0;
        for(int i = 1; i < 6; i++) aux += v[i];
        cout.precision(2);
        cout << fixed << str << ' ' << g*aux << '\n';
    }
        
    return 0;
}
