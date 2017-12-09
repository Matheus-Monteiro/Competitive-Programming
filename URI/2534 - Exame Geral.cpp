// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Exame Geral
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2534

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, q, j;

	while(cin >> n >> q)
	{
		int v[n+1];
		for(int i = 1; i <= n; i++)
			cin >> v[i];
		sort(v+1, v+n+1, [](int a, int b){return a > b;});
		while(q--)
		{
			cin >> j;
			cout << v[j] << '\n';
		}
	}

	return 0;
}
