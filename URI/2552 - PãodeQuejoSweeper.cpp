// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: PãodeQuejoSweeper
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2552

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool B[105][105];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool check(int r, int c)
{
	return r < n and r >= 0 and c < m and c >= 0;
}

int change(int r, int c)
{
	int ans = 0;
	for(int i = 0; i < 4; i++)
		if(check(r+dr[i], c+dc[i]))
			ans += B[r+dr[i]][c+dc[i]];
	return ans;
}

int main()
{
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> B[i][j];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
				cout << (B[i][j] ? 9 : change(i, j));
			cout << '\n';
		}
		memset(B, 0, sizeof(B));
	}
    return 0;
}
