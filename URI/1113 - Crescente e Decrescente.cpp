// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Crescente e Decrescente
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1113

#include <iostream>

using namespace std;

int main (){

 int x=0, y=1;
 
    while(x!=y){
      cin >> x >> y;
      
      if(x==y)
        return 0;
      
      if(x>y)
        cout << "Decrescente" << endl;
        
      if(x<y)
        cout << "Crescente" << endl;
    }
return 0;
}
  


