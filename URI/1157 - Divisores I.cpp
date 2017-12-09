// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Divisores I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1157

#include <iostream>

using namespace std;

int main(){
    int x;
      
      cin >> x;
      
      for(int i=1; i<=x; i++){
        if(x%i==0){
          cout << i << endl;
        }
      }
    

    
}
