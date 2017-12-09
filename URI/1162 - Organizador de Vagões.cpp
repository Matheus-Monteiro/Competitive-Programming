// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Organizador de Vagões
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1162

#include <bits/stdc++.h>
const int MAXN = 110;

using namespace std;

int v[MAXN], n, cont; 

void bubble_sort(){
    bool ordenado = false;
    while(!ordenado){
        ordenado = true;
        for(int i = 0; i < n-1; i++){
            if(v[i] > v[i+1]){
                swap(v[i], v[i+1]);
                ordenado = false;
                cont++;
            }
        }
    }
}

int main(){
    int t;
    
    cin >> t;
    
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> v[i];
        cont = 0;
        bubble_sort();
        cout << "Optimal train swapping takes " <<  cont  << " swaps." <<  "\n";
    }
               
               
    return 0;
}
