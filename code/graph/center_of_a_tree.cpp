#include <bits/stdc++.h>
const int MAX = 1e5;
using namespace std;

int n, degree[MAX];
vector<int> G[MAX];
bool vis[MAX];

int findCenter()
{
	queue<int> fila[2];
	for(int i = 0; i < n; i++)
		if(degree[i] == 1)
			fila[0].push(i);
	int cnt = 0, turn = 0;
	while(cnt + 2 < n)
	{
		while(!fila[turn].empty())
		{
			int u = fila[turn].front(); fila[turn].pop();
			vis[u] = true;
			cnt++;
			for(int i = 0; i < G[u].size(); i++)
				if(!vis[G[u][i]])
				{
					degree[G[u][i]]--;
					if(degree[G[u][i]] == 1) 
						fila[1-turn].push(G[u][i]);
				}
		}
		turn ^= 1;
	}
	cout << "the set of central vertices\n";
	for(int i = 0; i < n; i++)
		if(!vis[i])
		    cout << i + 1 << '\n';
}

int main()
{
    cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v); u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	findCenter();
	
	return 0;
}


