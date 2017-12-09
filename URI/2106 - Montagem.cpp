// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Montagem
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2106

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

int n;
int dist[20][20];
int memo[1 << 18];

int solve(int id, int bitmask)
{
	if(bitmask == (1 << n) - 1)
		return 0;
	if(memo[bitmask] != -1)
		return memo[bitmask];
	int ans = INT_MAX;
	for(int i = 0; i < n; i++)
		if(!(bitmask & (1 << i)))
			ans = min(ans, dist[i][id] + solve(id + 1, bitmask | (1 << i)));
	return memo[bitmask] = ans;
}

void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for(; c < 48 or c > 57; c = gc());
	for(; c >= 48 and c <= 57; c = gc())
		x = (x << 1) + (x << 3) + c - 48;
}

int main()
{
	scanint(n);
	while(n)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanint(dist[i][j]);
		memset(memo, -1, sizeof(memo));
		cout << solve(0, 0) << '\n';
		scanint(n);
	}

	return 0;
}
