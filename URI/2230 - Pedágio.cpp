// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Pedágio
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2230

#include <bits/stdc++.h>
using namespace std;

int c, e, l, p;
vector<int> G[55];
int cor[55];

void bfs()
{
	queue<int> q;
	memset(cor, -1, sizeof(cor));
	cor[l] = 0;
	q.push(l);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size(); i++)
		{
			int w = G[u][i];
			if(cor[w] == -1)
			{
				cor[w] = cor[u] + 1;
				q.push(w);
			}
		}
	}
}

int main()
{
	int u, v, t = 1;
	
	while(cin >> c >> e >> l >> p and (c or e or l or p))
	{
		for(int i = 1; i <= c; i++)
			G[i].clear();
		while(e--)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs();
		cout << "Teste " << t++ << '\n';
		for(int i = 1; i <= c; i++)
			if(cor[i] <= p and cor[i] > 0)
				cout << i << ' ';
		cout << "\n\n";
	}
	
	return 0;
}
