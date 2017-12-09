// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Soma de Impares Consecuti...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1071

#include <stdio.h>
int main () {
    int x,y,i,soma=0,aux;
    scanf("%d %d",&x,&y);
    if(y>x){
        aux=x;
        x=y;
        y=aux;
    }
    if(y%2==-1)
        y++;
    if(y%2==1)
        y--;
    for(i=y;i<x;i++){
        if(i%2==1 || i%2==-1){
            soma+=i;
        }
    }
    printf("%d\n",soma);
    return 0;
}

