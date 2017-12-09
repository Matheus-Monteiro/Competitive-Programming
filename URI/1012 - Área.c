// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Área
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1012

#include <stdio.h>

int main () {

    double a, b, c, triangulo, pi, circulo, trapezio, quadrado, retangulo;
    pi=3.14159 ;

    scanf ("%lf %lf %lf", &a, &b, &c);

    triangulo = (a*c)/2 ;
    circulo =  pi*c*c ;
    trapezio =  ((a+b)*c)/2 ;
    quadrado =  b*b ;
    retangulo = a*b ;

    printf("TRIANGULO: %.3lf\n",triangulo);
    printf("CIRCULO: %.3lf\n",circulo);
    printf("TRAPEZIO: %.3lf\n",trapezio);
    printf("QUADRADO: %.3lf\n",quadrado);
    printf("RETANGULO: %.3lf\n",retangulo);


return 0;
}

