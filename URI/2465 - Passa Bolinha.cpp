// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Passa Bolinha
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2465

#include <bits/stdc++.h>
using namespace std;

int G[105][105][2], n;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int floodfill(int x, int y, int r, int c)
{
	if(r < 0 or r >= n or c < 0 or c >= n or G[r][c][1] or G[r][c][0] < G[x][y][0])
		return 0;
	G[r][c][1] = 1;
	int ans = 1;
	for(int i = 0; i < 4; i++)
		ans += floodfill(r, c, r+dr[i], c+dc[i]);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int u, v; 
	
	cin >> n >> u >> v;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> G[i][j][0];
	cout << floodfill(u-1, v-1, u-1, v-1) << '\n';

	return 0;
}
