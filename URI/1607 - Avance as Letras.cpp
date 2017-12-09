// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Avance as Letras
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1607

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string a, b;
    int cont = 0, t;
    
    cin >> t;
    
    while(t--){
        cin >> a >> b;   
        cont = 0;
        for(int i = 0; i < a.size(); i++){
            if(b[i] >= a[i] and b[i] <= 'z')
                cont += b[i] - a[i];
            else
                cont += 26 - a[i] + b[i];
        }
        cout << cont << "\n";
    }
    
    return 0;
}
