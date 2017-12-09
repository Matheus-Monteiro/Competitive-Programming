// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cédulas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1018

#include <stdio.h>
  
int main() {
  
    int n,i;
    do{
        scanf("%d",&n);
    }while(n<0 && n>1000000);
    printf("%d\n",n);
    do{
        i = n/100;
        n = n%100;
        printf("%d nota(s) de R$ 100,00\n",i);
    }while(n>=100);
    do{
       i = n/50;
       n = n%50;
       printf("%d nota(s) de R$ 50,00\n",i);
    }while(n>=50);
    do{
        i = n/20;
        n = n%20;
        printf("%d nota(s) de R$ 20,00\n",i);
    }while(n>=20);
    do{
        i = n/10;
        n = n%10;
        printf("%d nota(s) de R$ 10,00\n",i);
    }while(n>=10);
    do{
        i = n/5;
        n = n%5;
        printf("%d nota(s) de R$ 5,00\n",i);
    }while(n>=5);
    do{
        i = n/2;
        n = n%2;
        printf("%d nota(s) de R$ 2,00\n",i);
    }while(n>=2);
    do{
        i = n/1;
        n = n%1;
        printf("%d nota(s) de R$ 1,00\n",i);
    }while(n>=1);
 
  
    return 0;
}


