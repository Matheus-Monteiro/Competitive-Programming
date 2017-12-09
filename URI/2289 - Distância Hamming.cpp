// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Distância Hamming
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2289

#include <bits/stdc++.h>
typedef unsigned long long ull;

using namespace std;

int count_bits(ull z){
    int cont = 0;
    while(z){
        z &= (z-1);
        cont++;
    }
    return cont;
}

int main(){
    ull x, y, aux;
    while(cin >> x >> y and x != 0 or y != 0){
        aux = x^y;
        cout << count_bits(aux) << '\n';
    }
    return 0;
}
