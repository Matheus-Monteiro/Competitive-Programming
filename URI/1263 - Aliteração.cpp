// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Aliteração
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1263

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int cont;
    vector<char> aux;
    
    while(getline(cin, str)){
        aux.push_back(tolower(str[0]));
        for(int i = 0; i < str.size(); i++)
            if(str[i] == ' ')
                aux.push_back(tolower(str[i+1]));
        bool ok = true;
        cont = 0;
        for(int i = 0; i < aux.size()-1; i++){
            if(aux[i] == aux[i+1] and ok){
                cont++;
                ok = false;
            }else{
                if(aux[i] != aux[i+1])
                    ok = true;
            }
        }
        cout << cont << "\n";
        aux.clear();
    }
    
    return 0;
}
