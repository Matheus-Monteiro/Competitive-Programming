// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Idade em Dias
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1020

#include <stdio.h>
int main () {
  int Id,a,b,c;

  scanf("%i",&Id);

  a = Id/365;
  printf("%i ano(s)\n",a);

  b = (Id - 365*a)/30 ;
  printf("%i mes(es)\n",b);

  c = Id-(365*a+30*b);
  printf("%i dia(s)\n",c);

return 0;
}


