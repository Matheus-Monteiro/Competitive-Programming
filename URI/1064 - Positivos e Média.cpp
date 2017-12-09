// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Positivos e Média
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1064

#include <iostream>
#include <cstdio>

using namespace std;

int main (){

  double v[6];
  int  a=0, b=0;
  double c=0, r;
  
  for(int i=0; i<6; i++){
    cin >> v[i];
  }
  
  for(int i=0; i<6; i++){
    if(v[i]>0){
      a=1;
      b+=a;
      c+=v[i];
    } 
  }
  
  r = c/b;
  
  cout << b << " valores positivos" << endl;
  cout.precision(1);
  cout << fixed;
  cout << r << endl;
}


