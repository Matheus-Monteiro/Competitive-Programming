// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fila do Recreio
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1548

#include <iostream>
#define MAX 1010
using namespace std;


int main (){

  int n, m, p[MAX]={0}, aux[MAX]={0}, a=0, b=0;
  
    cin >> n;
    
    while (n--)
      {   
         cin >> m;
      
              for(int i=0 ; i<m ; i++){
                  cin >> p[i];
                }
                
              for(int i=0 ; i<m ; i++){
                  aux[i] = p[i];
                }
                
             
           int ordenado = 0;
      
          while(ordenado == 0){
      
                    ordenado = 1;
        
              for (int i=0 ; i<m ; i++){
            
                  if (p[i] < p[i+1]){
                    int tmp=p[i];
                    p[i]=p[i+1];
                    p[i+1]=tmp;
                    
                    ordenado = 0;
                     }
                  }
           }
            
             for(int i=0 ; i<m ; i++){
                  
                 if(aux[i] == p[i]){
                    a=1;
                    b+=a;
                    } 
                }
            
              cout << b << endl;
              
              a=0;
              b=0;
   
      }
  

}

