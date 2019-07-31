#include <bits/stdc++.h>

using namespace std;

int c, n;
int m[105][105][2];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void f(int x, int y)
{
	m[x][y][1] = 1;
	for(int i = 0; i < 4; i++)
	{	
		if(x + dx[i] < 0 or x + dx[i] >= n or y + dy[i] < 0 or y + dy[i] >= n or m[x + dx[i]][y + dy[i]][1])
			continue;
		if(m[x + dx[i]][y + dy[i]][0] >= m[x][y][0])
			f(x + dx[i], y + dy[i]), c++;
	}
}

int main()
{
	int x, y;
	cin >> n >> x >> y;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> m[i][j][0];
	c = 1;
	f(x - 1, y - 1);
	cout << c << '\n';

	return 0;
}