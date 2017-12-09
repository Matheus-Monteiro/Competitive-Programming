// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pares e Ímpares
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1259

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vi, vp;
    int n, aux;
    
    cin >> n;
    while(n--){
        cin >> aux;
        if(aux%2)
            vi.push_back(aux);
        else
            vp.push_back(aux);
    } 
    sort(vp.begin(), vp.end());
    sort(vi.begin(), vi.end(), [](int a, int b){return a > b;});
    
    for(int &p : vp) cout << p << '\n';
    for(int &p : vi) cout << p << '\n';
    
    return 0;
}
