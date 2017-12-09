// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Coordenadas de um Ponto
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1041

#include <stdio.h>
int main () {
  double x,y;

    scanf("%lf %lf", &x, &y);

  if ((x==0)&&(y==0))
      printf ("Origem\n");

  if ((x==0)&&(y!=0))
      printf("Eixo Y\n");

  if ((x!=0)&&(y==0))
      printf("Eixo X\n");

  if ((x>0)&&(y>0))
      printf("Q1\n");

  if ((x<0)&&(y>0))
      printf("Q2\n");

  if ((x<0)&&(y<0))
      printf("Q3\n");

  if ((x>0)&&(y<0))
      printf("Q4\n");

return 0;
}

