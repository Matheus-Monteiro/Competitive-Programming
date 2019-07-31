#include <bits/stdc++.h>
using namespace std;

int n, m;
int G[1005][1005];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int dist[1005][1005];

void dfs(int r, int c) 
{
	for(int i = 0; i < 4; i++)
	{
		int _r = r+dr[i], _c = c+dc[i];
		if(G[_r][_c] and dist[_r][_c] < 0)
		{
			dist[_r][_c] = dist[r][c] + 1;
			dfs(_r, _c);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	int r1, c1, r2, c2;
	memset(dist, -1, sizeof(dist));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
		{
			cin >> G[i][j];
			if(G[i][j] == 2)
				r1 = i, c1 = j;
			if(G[i][j] == 3)
				r2 = i, c2 = j;
		}
	}
	dist[r1][c1] = 1;
	dfs(r1, c1);
	cout << dist[r2][c2] << '\n';
		
	return 0;
}