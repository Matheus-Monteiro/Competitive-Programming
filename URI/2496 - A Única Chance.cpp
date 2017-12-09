// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: A Única Chance
// Nível: 1
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2496

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n, t;
	string str;
	
	cin >> n;
	while(n--)
	{
		cin >> t >> str;
		string aux = str;
		sort(str.begin(), str.end());
		int c = 0;
		for(int i = 0; i < str.size() and c <= 3; i++)
			if(str[i] != aux[i])
				c++;
		cout << (c <= 2 ? "There are the chance." : "There aren't the chance.") << '\n';
	}
	 

	return 0;
}
