// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Resto 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1075

#include <iostream>
#include <cstdio>

using namespace std;

int main (){

  int n;
  
    cin >> n;
    
      for(int i=1; i<10000; i++){
        if((i%n)==2){
          cout << i << endl;
        }
        
      }
}


