// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Carrega ou não Carrega?
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1026

#include <bits/stdc++.h>
typedef long long int lli;

using namespace std;

int main(){
    lli a, b;
    
    while(cin >>a >> b){
        cout << (a ^ b) << endl;
    }

    return 0;
}
