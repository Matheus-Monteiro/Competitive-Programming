// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Variações
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1632

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, aux, q;
    string str;
    
    cin >> n;
    
    while(n--){
        cin >> str;
        q = 1;
        for(int i = 0; i < str.size(); i++){
            aux = 2;
            if(tolower(str[i]) == 'a' or tolower(str[i]) == 'e' or tolower(str[i]) == 'i'
            or tolower(str[i]) == 'o' or tolower(str[i]) == 's')
                aux++;
            q *= aux;
        }
        cout << q << '\n';
    }
    
    return 0;
}
