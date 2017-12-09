// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Tempo de Jogo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1046

#include <cstdio>
int main (){

    int i,f,d;
    
    do{
        scanf ("%d", &i);
    }while(i<0 || i>24);
    
    do{
        scanf ("%d", &f);
    }while (f<0 || f>24);
    
    if (i<f)
      {
         d=f-i;
      }
      
    if (i==f)
      {
         d=24;
      }
      
    if (i>f)
      {
         d=24-i+f;
      }
   
        printf ("O JOGO DUROU %d HORA(S)\n",d);
}

