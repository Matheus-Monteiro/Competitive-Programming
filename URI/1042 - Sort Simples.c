// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sort Simples
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1042

#include <stdio.h>
int main () {
  int a,b,c;

  scanf("%i %i %i", &a, &b, &c);

  if ((a>b)&&(a>c))
  {
      if((b<a)&&(b>c))
      {
            printf("%i\n%i\n%i\n",c,b,a);
            printf("\n%i\n%i\n%i\n",a,b,c);
      }else{
            printf("%i\n%i\n%i\n",b,c,a);
            printf("\n%i\n%i\n%i\n",a,b,c);
           }
  }


  if ((b>a)&&(b>c))
  {
      if ((c<b)&&(c>a))
      {
             printf("%i\n%i\n%i\n",a,c,b);
             printf("\n%i\n%i\n%i\n",a,b,c);
      }else{
             printf("%i\n%i\n%i\n",c,a,b);
             printf("\n%i\n%i\n%i\n",a,b,c);
           }
  }

  if ((c>a)&&(c>b)) //a,b,c
  {
      if ((b<c)&&(b>a))
      {
             printf("%i\n%i\n%i\n",a,b,c);
             printf("\n%i\n%i\n%i\n",a,b,c);
      }else{
             printf("%i\n%i\n%i\n",b,a,c);
            printf("\n%i\n%i\n%i\n",a,b,c);
           }
  }

return 0;
}

