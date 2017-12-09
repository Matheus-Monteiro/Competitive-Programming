// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cortando Canos
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1798

#include <bits/stdc++.h>

using namespace std;

int knapsack(int p_max, int *v, int *p, int n)
{
	int pd[n][p_max+1];
	for(int i = 0; i < n; i++)
	{
		for(int w = 0; w <= p_max; w++)
		{
			if(!i)
				pd[i][w] = v[i]*(w/p[i]);
			else
			{
				if(p[i] <= w)
					pd[i][w] = max(v[i]+pd[i][w-p[i]], pd[i-1][w]);
				else
					pd[i][w] = pd[i-1][w];
			}
		}
	}
	return pd[n-1][p_max];
}

int main()
{
	int n, p_max;
	
	cin >> n >> p_max;
	int v[n], p[n];
	
	for(int i = 0; i < n; i++)
		cin >> p[i] >> v[i];
	
	cout  << knapsack(p_max, v, p, n) << '\n';
	
	return 0;
}
