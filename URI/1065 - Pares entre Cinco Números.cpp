// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pares entre Cinco Números
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1065

#include <iostream>
#include <cstdio>

using namespace std;

int main (){

  int v[5], a=0, b=0;
  
  for(int i=0; i<5; i++){
    cin >> v[i];
  }
  
  for(int i=0; i<5; i++){
    if(v[i]%2 == 0){
      a=1;
      b+=a;
    }
  }
   
   cout << b << " valores pares" << endl;
}


