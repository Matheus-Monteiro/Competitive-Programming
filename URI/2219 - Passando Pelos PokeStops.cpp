// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Passando Pelos PokeStops
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2219

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, m, aux;
	vector<int> v;

	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		v.push_back(0);
		for(int i = 1; i <= m; i++)
		{
			cin >> aux;
			if(aux <= n) v.push_back(aux);
		}
		v.push_back(n);
		int ans = -1;
		sort(v.begin(), v.end());
		for(int i = 1; i < v.size(); i++)
			ans = max(ans, v[i]-v[i-1]);
		cout << ans << '\n';
		v.clear();
	}

	return 0;
}
