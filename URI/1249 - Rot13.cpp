// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Rot13
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1249

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int aux;
  
    while(getline(cin, str)){   
        for(int i = 0; i < str.size(); i++){
            if(isalpha(str[i])){
                if(islower(str[i])){
                    if((int)str[i] <= 97 + 12)
                        str[i] = str[i] + 13;
                    else{
                        aux = (int)str[i];
                        aux = 122 - aux;
                        aux = 12 - aux;
                        str[i] = 97 + aux;
                    }
                }else{
                    if((int)str[i] <= 65 + 12)
                        str[i] = str[i] + 13;
                    else{
                        aux = (int)str[i];
                        aux = 90 - aux;
                        aux = 12 - aux;
                        str[i] = 65 + aux;
                    }
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}

//65 maiuscula
//97 minuscula
