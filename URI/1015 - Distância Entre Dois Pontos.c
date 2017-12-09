// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Distância Entre Dois Pontos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1015

#include <stdio.h>
#include <math.h>
int main () {
double x,x1,y,y1,d;

 scanf("%lf",&x);
 scanf("%lf",&y);
 scanf("%lf",&x1);
 scanf("%lf",&y1);

 d = sqrt (pow(x1-x,2)+pow(y1-y,2));

 printf("%.4lf\n",d);

 return 0;

}

