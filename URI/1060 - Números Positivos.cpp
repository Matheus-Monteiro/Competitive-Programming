// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Números Positivos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1060

#include <iostream>


using namespace std;

int main (){

  double n[6], a=0, b=0;
  
  for(int i=0; i<6; i++){
    cin >> n[i];  
  }
  
  for(int i=0; i<6; i++){
    if(n[i]>0){
        a = 1;
        b+=a;
    }
  }
  cout << b << " valores positivos" << endl;
}
