/*
	μ(n) = 0 se n tem como divisor um outro número natural ao quadrado
	μ(n) = 1 se n não tem como divisor um outro número natural ao quadrado
		e é decomposto em uma quantidade par de números primos
	μ(n) = -1 se n não tem como divisor um outro número natural ao quadrado
		e é decomposto em uma quantidade ímpar de números primos
*/

#include "bits/stdc++.h"
using namespace std;
const int MAX = 1e6;

bool np[MAX];
int mob[MAX];

void mobius()
{
	for(int i = 1; i < MAX; i++)
		mob[i] = 1;
	for(int i = 2; i < MAX; i++)
	{
		if(np[i]) continue;
		for(int j = i; j < MAX; j += i)
		{
			np[j] = true;
			mob[j] *= -1;
			if((j / i) % i == 0)
				mob[j] = 0;
		}
	}
}
 
int main()
{
	mobius();
	    
    for(int i = 2; i <= 10; i++)
    	cout << i << ' ' << mob[i] << '\n';
	puts("");
	    
	return 0;
}
