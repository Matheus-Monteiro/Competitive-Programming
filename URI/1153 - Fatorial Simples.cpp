// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fatorial Simples
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1153

#include <iostream>

using namespace std;

int fatorial(int n){
    int i=1;
       
        for (;n>=1;n--)
        i*=n;
        return (i);
}

int main () {
  int a;

    cin >> a;
    fatorial(a);
    cout << fatorial(a) << endl;
    
  return 0;
}
