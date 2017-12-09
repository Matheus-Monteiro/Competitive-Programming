// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Imposto de Renda
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1051

#include <stdio.h>
int main (){

  double s,i;

  scanf("%lf",&s);

  if (s<=2000.00)
      printf("Isento\n");

  if ((s>=2000.01)&&(s<=3000.00))
  {
      s=s-2000;
     i = 0.08*s;
     printf("R$ %.2lf\n",i);

  }else{

   if((s>=3000.01)&&(s<=4500))
        {
        i = 80+(s-3000)*0.18 ;
         printf("R$ %.2lf\n",i);
        }else {
        if (s>4500.00)
          {
            i = 80 + (750*0.36) + (0.28*(s-4500) );
            printf("R$ %.2lf\n",i);
          }
        }
  }

return 0;
}

