// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Inversão
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1550

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t, a, b, ans;
	set<int> st;
	queue<pair<int, int>> fila;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		fila.push({a, 0});
		while(fila.front().first != b)
		{
			pair<int, int> r = fila.front();
			fila.pop();		
			if(st.find(r.first) == st.end())
			{
				fila.push({r.first + 1, r.second + 1});
				string aux = to_string(r.first);
				reverse(aux.begin(), aux.end());
				int k = stoi(aux);
				fila.push({k, r.second + 1});
				if(r.first+1 == b or k == b)
				{
					ans = r.second + 1;
					break;
				}
				st.insert(r.first);
			}
		}
		cout << ans << '\n';
		fila = queue<pair<int, int>>();
		st.clear();
	}

	return 0;
}
