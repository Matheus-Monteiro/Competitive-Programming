// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Comparação de Substring
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1237

#include <iostream>

using namespace std;

int pd[10000][10000];

int lcs(string a, string b)
{
	int ans = 0;
	for(int i = 1; i <= a.size(); i++)
		for(int j = 1; j <= b.size(); j++)
			a[i-1] == b[j-1] ? pd[i][j] = pd[i-1][j-1] + 1, ans = max(ans, pd[i][j]) : pd[i][j] = 0;
	return ans;
}

int main()
{
	string a, b;
	
	while(getline(cin, a) and getline(cin, b))
		cout << lcs(a, b) << '\n';

    return 0;
}
