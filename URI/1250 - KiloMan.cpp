// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: KiloMan
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1250

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n;
	vector<int> v;
	string str;

	cin >> t;
	while(t--)
	{
		cin >> n;
		v.resize(n);
		for(int &i : v)
			cin >> i;
		cin >> str;
	
		int ans = 0;
		for(int i = 0; i < str.size(); i++)
			if(str[i] == 'S' and v[i] <= 2)
				ans++;
			else if(str[i] == 'J' and v[i] > 2)
				ans++;
		cout << ans << '\n';
		v.clear();
	}

	return 0;
}
