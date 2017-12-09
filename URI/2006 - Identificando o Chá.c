// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Identificando o Chá
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2006

#include <stdio.h>
int main () {
int v[6],i,s=0;

    for(i=0;i<6;i++){
        scanf ("%d",&v[i]);
    }
    for(i=0;i<5;i++){
        if(v[0] == v[i+1]){
            s+=1;
        }
    }
    printf("%d\n",s);
return 0;

}

