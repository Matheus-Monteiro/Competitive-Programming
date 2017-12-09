// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Mapa do Meistre
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1855

#include <bits/stdc++.h>

using namespace std;

int n, m, p;
map<char, pair<int, int>> cii;
string s[110];

bool floodfill(int r, int c, char k)
{
	if(r >= m or r < 0 or c >= n or c < 0)
		return false;
	if(s[r][c] == '#')
		return false;
	if(s[r][c] == '*')
		return true;
	char aux = s[r][c];
	s[r][c] = '#';
	if(aux == '.')
		return floodfill(r+cii[k].first, c+cii[k].second, k);
	else
		return floodfill(r+cii[aux].first, c+cii[aux].second, aux);
	return false;
}

int main()
{
	cii['>'] = {0, 1};
	cii['v'] = {1, 0};
	cii['<'] = {0, -1};
	cii['^'] = {-1, 0};

	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> s[i];
	cout << (floodfill(0, 0, s[0][0]) ? '*' : '!') << '\n';	
		
	return 0;
}
