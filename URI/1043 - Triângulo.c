// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Triângulo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1043

#include <stdio.h>

int main (){
   double A,B,C;

 scanf("%lf %lf %lf", &A, &B, &C);

   if ((fabs(B-C)<A)&&(A < B+C))
   {
     if ((fabs(A-C)<B)&&(B < A+C))
     {
       if ((fabs(A-B)<C)&&(C<A+B))
       {
            printf("Perimetro = %.1lf\n",A+B+C);

       }else{
          printf("Area = %.1lf\n",((A+B)*C)/2);
            }
     }else{
   printf("Area = %.1lf\n",((A+B)*C)/2);
          }
   }else{
   printf("Area = %.1lf\n",((A+B)*C)/2);
        }
return 0;
}

