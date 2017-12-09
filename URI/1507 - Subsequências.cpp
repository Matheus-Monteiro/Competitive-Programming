// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Subsequências
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1507

#include <bits/stdc++.h>

using namespace std;

bool solve(string s1, string s2)
{
	int j = 0;
	for(int i = 0; i < s1.size() and j < s2.size(); i++)
		if(s1[i] == s2[j])
			j++;
	return (j == s2.size());
}

int main()
{
	string s, str;
	int n, q, p;
	
	cin >> n;
	while(n--)
	{
		cin >> s;	
		cin >> q;
		while(q--)
		{	
			cin >> str;
			cout << (solve(s, str) ? "Yes" : "No") << '\n';
		}
	}


	return 0;
}
