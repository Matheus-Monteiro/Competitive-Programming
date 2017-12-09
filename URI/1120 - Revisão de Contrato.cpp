// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Revisão de Contrato
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1120

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str, aux;
    char c;
    
    while(cin >> c >> str and (c != '0' or str != "0")){   
        bool ok = false;
        for(int i = 0; i < str.size(); i++){
            if(str[i] != c){
                if(str[i] != '0' or ok){    
                    aux.push_back(str[i]);
                    ok = true;
                }
            }
        }
        if(aux.empty())
            aux.push_back('0');
        cout << aux << endl;
        aux.clear();
    }
    return 0;
}
