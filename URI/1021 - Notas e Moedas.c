// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Notas e Moedas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1021

#include <stdio.h>
  
int main() {
  
    double n,d;
    int i,k;
    do{
        scanf("%lf",&n);
    }while(n<0 && n>1000000);
    k = n/1;
    d = (n-k)*100;
    printf("NOTAS:\n");
    do{
        i = n/100;
        n = (int)n%100;
        printf("%d nota(s) de R$ 100.00\n",i);
    }while(n>=100);
    do{
       i = n/50;
       n = (int)n%50;
       printf("%d nota(s) de R$ 50.00\n",i);
    }while(n>=50);
    do{
        i = n/20;
        n = (int)n%20;
        printf("%d nota(s) de R$ 20.00\n",i);
    }while(n>=20);
    do{
        i = n/10;
        n = (int)n%10;
        printf("%d nota(s) de R$ 10.00\n",i);
    }while(n>=10);
    do{
        i = n/5;
        n = (int)n%5;
        printf("%d nota(s) de R$ 5.00\n",i);
    }while(n>=5);
    do{
        i = n/2;
        n = (int)n%2;
        printf("%d nota(s) de R$ 2.00\n",i);
    }while(n>=2);
    printf("MOEDAS:\n");
    do{
        i = n/1;
        n = (int)n%1;
        printf("%d moeda(s) de R$ 1.00\n",i);
   }while(n>=1);
   do{
        i = d/50;
        d = (int)d%50;
        printf("%d moeda(s) de R$ 0.50\n",i);
    }while(d>=50);
    do{
        i = d/25;
        d = (int)d%25;
        printf("%d moeda(s) de R$ 0.25\n",i);
    }while(n>=25);
    do{
        i = d/10;
        d = (int)d%10;
        printf("%d moeda(s) de R$ 0.10\n",i);
    }while(n>=10);
    do{
        i = d/5;
        d = (int)d%5;
        printf("%d moeda(s) de R$ 0.05\n",i);
    }while(n>=5);
    do{
        i = d/1;
        d = (int)d%1;
        printf("%d moeda(s) de R$ 0.01\n",i);
    }while(n>=1);
  
    return 0;
}
