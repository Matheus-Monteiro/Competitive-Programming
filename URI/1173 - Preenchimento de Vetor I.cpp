// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Preenchimento de Vetor I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1173

#include <iostream>
using namespace std;

int main (){

  int n[10] = {0}, v;
  
    cin >> v;
    
    for(int i=1; i<10; i++){
      n[0] = v;
      n[i] = 2*n[i-1];
    }
    
    for(int i=0; i<10; i++){
      cout << "N[" << i << "] = " << n[i] << endl;
    }
   
return 0;
}
  


