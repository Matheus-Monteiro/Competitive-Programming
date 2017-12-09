// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pares, Ímpares, Positivos...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1066

#include <cstdio>
int main () {

   int v[5],pos=0,i,Par=0,imp=0,neg=0;

  for(i=0;i<5;i++)
 {
    scanf ("%d",&v[i]);
 }


  for (i=0;i<5;i++)
 {
   if(v[i]%2==0)
   Par+=1;
 }

        printf ("%d valor(es) par(es)\n",Par);


  for (i=0;i<5;i++)
 {
   if (v[i]%2!=0)
   imp+=1;
 }

       printf ("%d valor(es) impar(es)\n",imp);


  for (i=0;i<5;i++)
 {
   if (v[i]>0)
   pos+=1;
 }

       printf ("%d valor(es) positivo(s)\n",pos);


  for (i=0;i<5;i++)
 {
   if (v[i]<0)
   neg+=1;
 }

      printf ("%d valor(es) negativo(s)\n",neg);

return 0;
}

