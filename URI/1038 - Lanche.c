// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Lanche
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1038

#include <stdio.h>
int main () {
 int codigo, quantidade;

scanf("%i %i", &codigo, &quantidade);

if ((codigo>=1)&&(codigo<=5))
{

if (codigo==1)
{
    printf("Total: R$ %.2lf\n",quantidade*4.0);
}

if (codigo==2)
{
    printf("Total: R$ %.2lf\n",quantidade*4.5);
}

if (codigo==3)
{
    printf("Total: R$ %.2lf\n",quantidade*5.0);
}

if (codigo==4)
{
    printf("Total: R$ %.2lf\n",quantidade*2.0);
}

if (codigo==5)
{
    printf("Total: R$ %.2lf\n",quantidade*1.5);
}

}else{
system ("cls");
}

return 0;
}

