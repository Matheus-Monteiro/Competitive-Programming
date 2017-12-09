// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Média 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1006

#include <stdio.h>

int main () {
  double notaA,notaB,notaC,MEDIA;

  scanf("%lf %lf %lf", &notaA, &notaB, &notaC);

  if ((notaA>=0.0)&&(notaA<=10.0))
  {
  }else{ system ("cls"); }

  if ((notaB>=0.0)&&(notaB<=10.0))
  {
  }else{ system ("cls"); }

  if ((notaC >=0.0)&&(notaC <=10.0))
  {
      MEDIA = (((2*notaA)+(3*notaB)+(5*notaC)))/10 ;

      printf("MEDIA = %.1lf\n",MEDIA);

  }else{ system ("cls");}


return 0;
}
