// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tabuada
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1078

#include <iostream>
#include <cstdio>

using namespace std;

int main (){

  int n, v[10], x;
  
      cin >> n;
      for(int i=1; i<=10; i++){
        x = i*n;
        cout << i << " x " << n << " = " << x << endl; 
      }
   
  return 0;
}


