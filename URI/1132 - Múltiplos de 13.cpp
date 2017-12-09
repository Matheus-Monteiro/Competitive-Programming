// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Múltiplos de 13
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1132

#include <iostream>

using namespace std;

int main (){

 int x, y, aux=0, soma=0;
 
  cin >> x >> y;
  
  if(x>y){
    for(int i=0; i<=x-y; i++){
       aux = y+i;
       if((aux%13) != 0){
          soma+=aux;
       }
    }
  }
  
  if(x<y){        
    for(int i=0; i<=y-x; i++){
       aux = x+i;
       if((aux%13) != 0){
          soma+=aux;
       }
    }
  }
  
  if(x==y)
    soma=0;
    
    cout << soma << endl;
  
  
return 0;
}
  


