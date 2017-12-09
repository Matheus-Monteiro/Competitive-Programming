// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Corvo Contador
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1848

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int cont = 1, num = 0 ;
   char cv[100];
   char cmp[100]="caw caw";

   while(cont<=3){
      gets(cv);
      if(strcmp(cv,cmp)!=0){
         if(cv[0]==42){
            num = num + 4;   
         }
         if(cv[1]==42){
            num = num + 2;   
         }
         if(cv[2]==42){
            num = num + 1;   
         }
      
      }
      else{
         printf("%d\n",num);   
         num = 0;
         cont++;                  
      }      
   
   }
   return 0;
}
