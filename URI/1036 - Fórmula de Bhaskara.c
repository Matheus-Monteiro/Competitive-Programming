// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Fórmula de Bhaskara
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1036

#include <stdio.h>
#include <math.h>

int main(){
    double A,B,C,R1,R2, DELTA;

    scanf ("%lf %lf %lf", &A, &B, &C);

    DELTA = sqrt (pow(B,2)-(4*A*C)) ;

    if ((2*A != 0)&&(pow(B,2)-4*A*C >= 0))
        {

    R1 = (-B + DELTA)/(2*A)  ;

    R2 = (-B - DELTA)/(2*A) ;

    printf("R1 = %.5lf\n",R1);
    printf("R2 = %.5lf\n",R2);
    }else{
    printf("Impossivel calcular\n");
    }

    return 0;
}

