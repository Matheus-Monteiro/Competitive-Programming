// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Intervalo 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1072

#include <iostream>
#include <cstdio>

using namespace std;

int main (){

  int x=0, y=0, a=0, b=0, c=0, z=0;
  
      cin >> x;
      z=x;
      while(x--){
      
      cin >> y;
      
        if(y>=10 && y<=20){
          a = 1;
          b+=a;
        }
      }
      c = z-b;
      cout << b << " in" << endl;
      cout << c << " out" << endl;
}


