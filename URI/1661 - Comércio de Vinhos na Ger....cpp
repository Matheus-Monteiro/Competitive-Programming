// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Comércio de Vinhos na Ger...
// Nível: 2
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1661

#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;

main()
{
	while(cin >> n and n)
	{
		int ans = 0;
		int m, k = 0;
		while(n--)
		{
			cin >> m;
			k += m;
			ans += abs(k);
		}
		cout << ans << '\n';
	}	
}
