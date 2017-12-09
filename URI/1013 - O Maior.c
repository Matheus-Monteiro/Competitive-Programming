// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: O Maior
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1013

#include <stdio.h>

int main () {
   int a,b,s;

   scanf("%i %i %i",&a, &b, &s);

   if ((a>b)&&(a>s))
   {
        printf("%i",a);
       printf(" eh o maior\n");
   }

     if ((b>a)&&(b>s))
     {
         printf("%i",b);
       printf(" eh o maior\n");
     }

   if ((s>a)&&(s>b))
   {
       printf("%i",s);
       printf(" eh o maior\n");
   }



return 0;
}

