// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Troca em Vetor I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1175

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> N;
    N.resize(20);
    for(int &p : N)
        cin >> p;
    reverse(N.begin(), N.end());
    int i = 0;
    for(int p : N)
        cout << "N[" << i++ << "] = " << p << "\n";
    
    return 0;
}
