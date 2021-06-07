#include <bits/stdc++.h>
using namespace std;

vector<int> G[1000];
int b[1000], vis[1000], tempo;
bool be[1000];
set<int> r0, r1;

bool kuhn(int v)
{
	if(vis[v] == tempo)
		return 0;
	vis[v] = tempo;
	for(const int &u : G[v])
		if(!b[u] or kuhn(b[u]))
			return b[u] = v;
	return 0;
}

void MVC(int v)
{
	if(vis[v] == tempo)
		return;
	vis[v] = tempo;
	for(const int u : G[v])
		if(b[u] != v and b[u])
		{
			r1.insert(u);
			vis[b[u]] = tempo;
		}
}

int main()
{
	int n, m, e;
	cin >> n >> m >> e;
	while(e--)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	int ans = 0;
	tempo = 1;
	for(int i = 1; i <= n; i++)
		ans += kuhn(i), tempo++;
	for(int i = n + 1; i <= n + m; i++)
		if(b[i])
			be[i - n] = be[b[i]] = true;	
	for(int i = 1; i <= n; i++)
		if(!be[i])
			MVC(i);
	for(int i = 1 ; i <= n; i++)
		if(vis[i] < tempo)
			r0.insert(i);
	cout << "MVC = "<< ans << '\n';
	cout << "tamanho lado esquerdo " << r0.size() << '\n';
	for(auto it = r0.begin(); it != r0.end(); it++)
		cout << *it << ' ';
	puts("");
	cout << "tamanho lado direito " << r1.size() << '\n';
	for(auto it = r1.begin(); it != r1.end(); it++)
		cout << *it - n << ' ';
	puts("");

    return 0;
} 
