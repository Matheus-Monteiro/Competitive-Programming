// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Números Ímpares
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1067

#include <stdio.h>
int main () 
{
	int x=0,i=0;
	
	do  {
		scanf ("%d",&x);
	}while ((x<1)||(x>1000));
	
	if ((x%2)==0)
	{
		for (i=1;i<x;i+=2)
		{
			printf ("%d\n",i);
		}
	}else{
		
		for (i=1;i<=x;i+=2)
		{
			printf ("%d\n",i);
		}
	}
	
	return 0;	
}
