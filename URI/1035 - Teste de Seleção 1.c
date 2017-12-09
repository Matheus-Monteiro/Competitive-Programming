// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Teste de Seleção 1
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1035

#include <stdio.h>
int main () {
  int A,B,C,D;

  scanf("%i %i %i %i", &A, &B, &C, &D);

  if ((B>C)&&(D>A))
   {
       if (C+D > A+B)
       {
           if ((C>0)&&(D>0))
           {
               printf("Valores aceitos\n");
           }else{
               printf("Valores nao aceitos\n");
           }

       }else{
           printf("Valores nao aceitos\n");
           }

   }else{
       printf("Valores nao aceitos\n");
   }


return 0;
}
