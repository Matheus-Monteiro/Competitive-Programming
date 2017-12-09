// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Flores Florescem da França
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1140

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    char aux;
    
    while(getline(cin, str) and str != "*"){
        bool b1 = true, b2 = true;
        for(int i = 0; i < str.size() and b2; i++){
            if(str[i] != ' ' and b1){
                aux = str[i];
                b1 = false;
            }else{
                if(str[i-1] == ' '){
                    if(str[i] == tolower(aux) or str[i] == toupper(aux))
                        b2 = true;
                    else
                        b2 = false;
                }
            }
        }
        if(b2)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    
    return 0;
}
