// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequencia IJ 3
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1097

#include <stdio.h>
int main ()
{
  int I,J;

for (I=1,J=7;I<=9 ; I+=2,J+=2)
{
    printf("I=%d J=%d\n",I,J);
    printf("I=%d J=%d\n",I,J-1);
    printf("I=%d J=%d\n",I,J-2);
}
return 0;
}

