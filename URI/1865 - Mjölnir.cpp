// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Mjölnir
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1865

#include <bits/stdc++.h>

using namespace std;

int main(){

    string str;
    int n, forca;
    
    cin >> n;
    while(n--){
        cin >> str >> forca;
        if(str == "Thor")
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
