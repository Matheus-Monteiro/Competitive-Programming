// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Labirinto
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1621

#include <bits/stdc++.h>
using namespace std;

int n, m;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int dist[600][600];
string G[600];

void dfs(int r, int c)
{
	for(int i = 0; i < 4; i++)
	if(r+dr[i] >= 0 and r+dr[i] < n and c+dc >= 0 and c+dc[i] < m and G[r+dr[i]][c+dc[i]] == '.' and dist[r+dr[i]][c+dc[i]] == -1)
	{
		dist[r+dr[i]][c+dc[i]] = dist[r][c] + 1;
		dfs(r+dr[i], c+dc[i]);
	}
}

int main()
{
	while(cin >> n >> m and (n or m))
	{
		for(int i = 0; i < n; i++)
			cin >> G[i];
		int x = -1, y;
		for(int i = 0; i < n and x == -1; i++)
			for(int j = 0; j < m and x == -1; j++)
				if(G[i][j] == '.')
					x = i, y = j;
		memset(dist, -1, sizeof(dist));
		dist[x][y] = 0;
		dfs(x, y);
		int maxi = 0;	
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(maxi < dist[i][j])
					maxi = dist[i][j], x = i, y = j;
		memset(dist, -1, sizeof(dist));
		dist[x][y] = 0;
		dfs(x, y);
		maxi = -1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(maxi < dist[i][j])
					maxi = dist[i][j];
		cout << maxi << '\n';
	}
	return 0;
}
