// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Par ou Ímpar
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1074

#include <stdio.h>
int main () {
  int v[10000];
  int n,i;

  do{
  scanf("%d",&n);
  }while((n<1)||(n>10000));

  for (i=0;i<n;i++)
    {
     scanf("%d",&v[i]);
    }

  for (i=0;i<n;i++)
  {
      if (v[i]==0)
        printf("NULL\n");

      if ((v[i]%2==0)&&(v[i]>0))
          printf("EVEN POSITIVE\n");

      if ((v[i]%2==0)&&(v[i]<0))
          printf("EVEN NEGATIVE\n");

      if ((v[i]%2!=0)&&(v[i]>0))
           printf("ODD POSITIVE\n");

      if ((v[i]%2!=0)&&(v[i]<0))
              printf("ODD NEGATIVE\n");

  }

return 0;
}

