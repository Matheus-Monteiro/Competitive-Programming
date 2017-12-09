// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Intervalo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1037

#include <stdio.h>
int main (){
double a;

 scanf ("%lf", &a);

if ((a>=0)&&(a<=25)){
       printf("Intervalo [0,25]\n");
    }else{
         if((a>25)&&(a<=50)){
               printf ("Intervalo (25,50]\n");
            }else{
                 if ((a>50)&&(a<=75)){
                       printf("Intervalo (50,75]\n");
                     }else{
                          if ((a>75)&&(a<=100)){
                                printf("Intervalo (75,100]\n");
                              }else{
                                    printf ("Fora de intervalo\n");
                                   }
                          }
                 }
         }

return 0;
}

