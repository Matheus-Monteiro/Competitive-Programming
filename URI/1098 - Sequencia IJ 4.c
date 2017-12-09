// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequencia IJ 4
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1098

#include <stdio.h>
int main () {
    double i,j=0.8;
    for(i=0;i<=2;i+=0.2){
        j+=0.2;
        printf("I=%g J=%g\n",i,j);
        printf("I=%g J=%g\n",i,j+1);
        printf("I=%g J=%g\n",i,j+2);
    }
    return 0;
}

