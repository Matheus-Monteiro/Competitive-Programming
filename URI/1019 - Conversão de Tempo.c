// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Conversão de Tempo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1019

#include <stdio.h>
int main (){
  int N,H,m,s;
  scanf("%i", &N);

  H = N/3600 ;

  m = (N - (3600 * H))/60;

  s = N - (3600*H + 60*m);

  printf("%i:%i:%i\n",H,m,s);

return 0;
}

