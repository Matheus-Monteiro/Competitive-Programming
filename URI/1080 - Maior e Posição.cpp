// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Maior e Posição
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1080

#include <iostream>
#define MAX 110

using namespace std;

int vetor[MAX], aux[MAX];

  void bubble_sort(){
      
       int  ordenado = 0;
      
      while(ordenado == 0){
      
            ordenado = 1;
        
        for(int i=1 ; i<100 ; i++){
        
          if (vetor[i] < vetor[i+1]){
            int tmp=vetor[i];
            vetor[i]=vetor[i+1];
            vetor[i+1]=tmp;
            
            ordenado = 0;
          }
        }
      }
  }
  
  int main (){
  
    for (int i=1; i<=100 ; i++)
      cin >> vetor[i];
      
    for(int i=1; i<=100; i++){
      aux[i] = vetor[i];  
    }
      
      bubble_sort();
    
    cout << vetor[1] << endl;
    
    for(int i=1; i<=100; i++){
      if(vetor[1] == aux[i]){ 
        cout << i << endl;
      }
    }
  }
  


