// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Soma Natural
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1805

#include <iostream>

using namespace std;

int main () {
  unsigned long long int a, b, x = 0, aux=0, y;
  
    cin >> a >> b;
    
      if(a>b){
          y = b + (a-b);
          
          x = ((a-b+1) * (b+y))/2;
          
          cout << x << endl;
        }
        
      if(a<b){
          y = a + (b-a);
          
          x = ((b-a+1) * (a+y))/2;
          
          cout << x << endl;
        }
        
      if(a==b)
        cout << a << endl;

  return 0;
}
