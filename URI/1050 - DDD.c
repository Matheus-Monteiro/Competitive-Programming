// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: DDD
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1050

#include <stdio.h>
int main (){
int a;

 scanf("%i",&a);

switch (a)
{
    case 61 : printf("Brasilia\n");
    break;

    case 71 : printf("Salvador\n");
    break;

    case 11 : printf("Sao Paulo\n");
    break;

    case 21 :  printf("Rio de Janeiro\n");
    break;

    case 32 : printf("Juiz de Fora\n");
    break;

    case 19 : printf("Campinas\n");
    break;

    case 27 : printf("Vitoria\n");
    break;

    case 31 : printf("Belo Horizonte\n");
    break;

    default : printf("DDD nao cadastrado\n");
    break;
}

    return 0;
}

