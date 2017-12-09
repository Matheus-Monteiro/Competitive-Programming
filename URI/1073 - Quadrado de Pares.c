// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Quadrado de Pares
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1073

#include <stdio.h>
int main () {
  int n,i;

  do{
  scanf("%d",&n);
  }while((n<=5)||(n>=2000));


  for (i=2;i<=n;i+=2)
  {
      printf("%d^2 = %d\n",i,i*i);
  }

return 0;
}

