// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Sequência Lógica
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1144

#include <cstdio>

using namespace std;

int main()
{
    int n,i,a=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
         printf("%d ",i);
         a=i*i;
         printf("%d ",a);
         a=0;
         a=i*i*i;
         printf("%d\n",a);
         a=0;                     
         printf("%d ",i);
         a=i*i+1;
         printf("%d ",a);
         a=0;
         a=i*i*i+1;
         printf("%d\n",a);
         a=0;
         }           
  return 0;
}
