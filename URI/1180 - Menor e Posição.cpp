// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Menor e Posição
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1180

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
   long int num,i,pos,valor;
   
   cin>>num;

   long int vetor[num];
   cin>>vetor[0];
   pos=0;
   valor=vetor[0];
   
   for(i=1;i<num;i++){
      cin>>vetor[i];
      if(vetor[i]<valor){
         pos=i;
         valor=vetor[i];
      }
   }
   cout<<"Menor valor: "<<valor<<endl;
   cout<<"Posicao: "<<pos<<endl;
}
