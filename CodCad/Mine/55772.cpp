#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, G[105][105];
int dist[105][105];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool check(int r, int c)
{
	if(r >= 0 and c >= 0 and r < n and c < n)
		return true;
	return false;
}


int dijkstra()
{
	memset(dist, 63, sizeof(dist));
	ii a = {0, 0};
	dist[0][0] = 0;
	
	priority_queue<iii> pq;
	pq.push({0, a});
	while(!pq.empty())
	{
		a = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		if(d > dist[a.first][a.second]) continue;
		for(int i = 0; i < 4; i++)
		{
			int r = a.first+dr[i], c = a.second+dc[i];
			if(check(r, c))
				if(dist[r][c] > dist[r-dr[i]][c-dc[i]] + G[r][c])
				{
					dist[r][c] = dist[r-dr[i]][c-dc[i]] + G[r][c];
					pq.push({-dist[r-dr[i]][c-dc[i]], {r, c}});
				}
		}
	}
	return dist[n-1][n-1];
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> G[i][j];
	cout << dijkstra() << '\n';
	
	return 0;
}