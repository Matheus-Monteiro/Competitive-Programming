// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fibonacci Fácil
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1151

#include <iostream>

using namespace std;

int main () {
  int v[48], n;
    
    cin >> n;
    
    if(n==1){
      cout << "0" << endl;
      return 0;
    }
      v[0] = 0;
      v[1] = 1;
      
    for(int i=2; i<n; i++){

      v[i] = v[i-2]+v[i-1];
    }
    
    for(int i=0; i<n; i++){
      cout << v[i];
      if(i<n-1){
        cout << " ";
      }
    }
    
    cout << "\n" ;    
  return 0;
}
