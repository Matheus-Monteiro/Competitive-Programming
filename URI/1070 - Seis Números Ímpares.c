// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Seis Números Ímpares
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1070

#include <stdio.h>
int main ()
{
  int x;

  scanf("%d",&x);



  switch(x%2)
      {
      case 0 :    printf("%d\n%d\n%d\n%d\n%d\n%d\n",x+1,x+3,x+5,x+7,x+9,x+11);
      break;

      default:  printf("%d\n%d\n%d\n%d\n%d\n%d\n",x,x+2,x+4,x+6,x+8,x+10);
      break;
      }


return 0;
}

