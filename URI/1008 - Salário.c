// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Salário
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1008

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num, hrsT;
   double P_hra ;

   scanf("%i %i %lf", &num, &hrsT, &P_hra);

   printf("NUMBER = %i\n", num);
   printf("SALARY = U$ %.2lf\n", hrsT*P_hra );


return 0;
}

