// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: PUM
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1142

#include <iostream>

using namespace std;

int main (){

 int n;
 
 cin >> n;
 
 for(int i=1; i<=n*4; i+=4){
    cout << i << " " << i+1 << " " << i+2 << " PUM" << endl;
 }

  
return 0;
}
  


