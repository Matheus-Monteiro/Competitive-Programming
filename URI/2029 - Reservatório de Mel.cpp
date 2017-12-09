// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Reservatório de Mel
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2029

#include <stdio.h>

int main () {
   
   int T=0;
   double V, D, ALT, AR;
   
   while (scanf("%lf %lf", &V, &D) != EOF) {
         AR = 3.14 * ((D/2) * (D/2));
         
         ALT = V / (3.14*((D/2) * (D/2)));
         
         printf("ALTURA = %.2lf\n", ALT);
         printf("AREA = %.2lf\n", AR);
   }
   return 0;
}
