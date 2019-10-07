#include <bits/stdc++.h>
using namespace std;

const int ms = 100100;

int degree[ms], vis[ms];
int size[ms];
int n;

bool cmp(int a, int b)
{
	return size[a] < size[b];
}

void pre(vector<vector<int>> &edges, int on = 0)
{
	size[on] = 1;
	for(auto to : edges[on])
	{
		pre(edges, to);
		size[on] += size[to];
	}
	sort(edges[on].begin(), edges[on].end(), cmp);
}

void solve(vector<vector<int>> &edges, string &str, int on = 0)
{
	str += 'D';
	for(int l = 0, r = 0; l < edges[on].size(); l = r) {
		while(r < edges[on].size() && 
			size[edges[on][l]] == size[edges[on][r]]) r++;
		if(r == l + 1)
			solve(edges, str, edges[on][l]);
		else
		{
			priority_queue<string> hp;
			for(int i = l; i < r; i++) {
				string temp;
				solve(edges, temp, edges[on][i]);
				hp.push(temp);
			}
			while(!hp.empty())
			{
				str += hp.top();
				hp.pop();
			}
		}
	}
	str += 'U';
}

// enraizar arvore
void mount(vector<vector<int>> &graph, 
	vector<vector<int>> &G, int v = 0, int p = -1)
{
	for(int &u : G[v])
		if(u != p)
		{
			graph[v].push_back(u);
			mount(graph, G, u, v);
		}
}

// achar centro da arvore e enraizar no centro
void findCenterAndComputeStr(vector<vector<int>> &graph, 
	vector<vector<int>> &G, string *str)
{
	memset(vis, 0, sizeof(vis));
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
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		if(vis[i]) continue;
		graph.clear();
		graph.resize(n + 1);
		mount(graph, G, i);
		pre(graph, i);
		solve(graph, str[k], i);
		k++;
	}
}

int main()
{
	while(cin >> n)
	{
		string str[2][2];
		for(int i = 0; i < 2; i++)
		{
			vector<vector<int>> graph, G;
			G.resize(n + 1);
			memset(degree, 0, sizeof(degree));
			for(int j = 1; j < n; j++)
			{
				int u, v;
				scanf(" %d %d", &u, &v); v--; u--;
				
				G[v].push_back(u);
				G[u].push_back(v);
				degree[v]++;
				degree[u]++;
			}
			findCenterAndComputeStr(graph, G, str[i]);
		}
		bool fl = (str[0][0] == str[1][0]) or (str[0][0] == str[1][1]);
		fl |= ((str[0][1] == str[1][0]) or (str[0][0] == str[1][1]));
		puts(fl ? "S" : "N");
	}
	
	return 0;
}

