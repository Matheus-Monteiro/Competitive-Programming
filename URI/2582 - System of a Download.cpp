// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: System of a Download
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2582

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> v = {"PROXYCITY", "P.Y.N.G.", "DNSUEY!", "SERVERS", "HOST!",
	 "CRIPTONIZE", "OFFLINE DAY", "SALT", "ANSWER!", "RAR?", "WIFI ANTENNAS"};

	int c, n, m;
	cin >> c;
	while(c--)
	{
		cin >> n >> m;
		cout << v[n+m] << '\n';
	}

	return 0;
}
