// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Seleçao em Vetor I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1174

#include <iostream>

using namespace std;

int main (){
    double a[101];

    for(int i=0; i<100; i++){
        cin >> a[i];
    }

    for(int i=0; i<100; i++){
        if(a[i]<=10){
            cout.precision(1);
            cout << fixed;
            cout << "A[" << i << "] = " << a[i] << endl;
        }
    }
}

