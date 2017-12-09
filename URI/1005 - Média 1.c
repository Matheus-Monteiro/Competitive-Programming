// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Média 1
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1005

#include <stdio.h>

int main() {
    double notaA,notaB,MEDIA;
    scanf("%lf %lf", &notaA, &notaB);

    if((notaA >= 0.0)&&(notaA <= 10.0))
    {
     }else{ system ("cls");}

     if ((notaB>=0.0)&&(notaB<=10.0))
     {
           MEDIA = ((3.5*notaA)+(7.5*notaB))/11;
     }else{ system ("cls");}



    printf("MEDIA = %.5lf\n", MEDIA);
    return 0;
}

