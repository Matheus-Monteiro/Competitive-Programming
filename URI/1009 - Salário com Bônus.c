// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Salário com Bônus
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1009

#include <stdio.h>

int main () {
   char    nom[20];
   double  salF, totalV, x;

  scanf ("%s %lf %lf", &nom, &salF, &totalV);

  printf ("TOTAL = R$ %.2lf\n",  salF + 0.15*totalV );


return 0;
}

