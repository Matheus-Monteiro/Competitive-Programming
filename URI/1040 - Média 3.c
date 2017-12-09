// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Média 3
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1040

#include <stdio.h>

int main()
{
    double n1,n2,n3,n4,r,m;

    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
    m = (n1*2 + n2*3 + n3*4 + n4*1)/10;
    if (m>=5 && m<=6.9){
        scanf("%lf",&r);
    }
    printf("Media: %.1f\n",m);
    if (m>=5 && m<=6.9){
        printf("Aluno em exame.\n");
        printf("Nota do exame: %.1lf\n",r);
        if ((m+r)/2 >= 5){
            printf("Aluno aprovado.\n");
        }else{
          printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n",(m+r)/2);
    }
    if (m>=7){
        printf("Aluno aprovado.\n");
    }
    if (m<5){
        printf("Aluno reprovado.\n");
    }

    return 0;
}
