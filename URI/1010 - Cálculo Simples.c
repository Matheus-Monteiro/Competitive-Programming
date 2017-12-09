// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cálculo Simples
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1010

#include <stdio.h>

int main () {

    int cod1, num1, cod2, num2;
    double vlrU1, vlrU2;

    scanf("%i %i %lf", &cod1, &num1, &vlrU1);
    scanf("%i %i %lf", &cod2, &num2, &vlrU2);

    printf("VALOR A PAGAR: R$ %.2lf\n",vlrU1*num1 + vlrU2*num2 );


return 0;
}

