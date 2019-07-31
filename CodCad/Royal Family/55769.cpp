#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;

vector<int> G[MAX];
int apa[MAX];
int cor[MAX];
int por[MAX];
int divi[MAX];

void bfs()
{
	memset(cor, -1, sizeof(cor));
	queue<int> q;
	q.push(0);
	cor[0] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v : G[u])
			if(cor[v] == -1)
			{
				cor[v] = cor[u] + 1;
				q.push(v);
			}
	}
}

int main()
{
	int n, m, u;
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &u);
		G[u].push_back(i);
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &u);
		apa[u] = 1;
	}
	
	bfs();
	int maxi = -1;	

	for(int i = 1; i <= n; i++)
	{
		if(apa[i])
			por[cor[i]]++;
		divi[cor[i]]++;
		maxi = max(maxi, cor[i]);
	}

	for(int i = 1; i <= maxi; i++)
	{
		printf("%.2lf", 100*((double)por[i]/(double)divi[i]));
		if(i < n) printf(" ");
	}
	printf("\n");
	
	return 0;
}