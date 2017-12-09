// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Patinhos
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2334

#include <iostream>

using namespace std;

int main(){
    unsigned long long int p;
    
    while(cin >> p and p != -1){
        if(p > 0)
            cout << p-1 << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}
