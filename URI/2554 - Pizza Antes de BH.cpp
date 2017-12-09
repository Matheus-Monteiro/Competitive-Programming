// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pizza Antes de BH
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2554

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, aux;
	string data, ans;

	while(cin >> n >> m)
	{
		bool fl, ok = false;
		for(int i = 0; i < m; i++)
		{
			cin >> data;
			fl = true;
			for(int i = 0; i < n; i++)
			{
				cin >> aux;
				if(!aux)	
					fl = false;
			}
			if(fl and !ok) ans = data, ok = true;
		}
		cout << (ok ? ans : "Pizza antes de FdI") << '\n';
	}

    return 0;
}
