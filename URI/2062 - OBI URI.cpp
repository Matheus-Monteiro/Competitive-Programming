// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: OBI URI
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2062

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int n;
    
    cin >> n;
    cin.ignore();
    
    while(n--){
        cin >> str;
        if(str.size() == 3){
            if(str[0] == 'U' and str[1] == 'R')
                cout << "URI";
            else
                if(str[0] == 'O' and str[1] == 'B')
                    cout << "OBI";
                else
                    cout << str;
        }else
            cout << str;
        if(n > 0)
            cout << ' ';
    }
    cout << '\n';
    
    return 0;
}
