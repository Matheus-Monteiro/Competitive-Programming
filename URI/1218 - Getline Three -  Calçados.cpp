// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Getline Three -  Calçados
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1218

#include <bits/stdc++.h>

using namespace std;

int main(){
    string n, str;
    int nm, nf, caso = 1;
    bool ok = false;

    while(cin >> n and cin.ignore() and getline(cin, str)){
        if(ok)
            cout << endl;
        
        nm = nf = 0;        
        for(int i = 0; i < str.size()-1; i++){
            if(str[i] == n[0] and str[i+1] == n[1]){
                if(str[i+3] == 'M')
                    nm++;
                if(str[i+3] == 'F')
                    nf++;
            }
        }
        cout << "Caso " << caso << ":" << endl;
        cout << "Pares Iguais: " << nm+nf << endl;
        cout << "F: " << nf << endl;
        cout << "M: " << nm << endl;
        caso++;
        ok = true;
    }

    return 0;
}
