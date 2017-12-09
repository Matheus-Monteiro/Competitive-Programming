// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Médias Ponderadas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1079

#include <iostream>
#include <cstdio>

using namespace std;

int main (){

  int n;
  double a, b, c, x;
  
    cin >> n;
  
    while(n--){
    
      cin >> a >> b >> c ;
      
      x = (2*a + 3*b + 5*c)/10;
      
      cout.precision(1);
      cout << fixed;
      cout << x << endl; 
    }
     
 return 0;
}


