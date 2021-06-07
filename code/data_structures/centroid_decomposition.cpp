#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

int n, m, Centroid_Tree[MAX], Size[MAX];
vector<int> G[MAX], cTree[MAX];
bool cut[MAX];

int dfs(int v, int p)
{
	int s = 1;
	for(const int &u : G[v])
		if(!cut[u] and u != p)
			s += dfs(u, v);
	return Size[v] = s;
}

int Find_Centroid(int v, int p, int tot)
{
	int next, cnt = 0;
	for(const int &u : G[v])
		if(!cut[u] and u != p and cnt < Size[u])
		{
			cnt = Size[u];
			next = u;
		}
	if(cnt > tot/2) return Find_Centroid(next, v, tot);
	return v;
}

void build(int v, int p)
{
	dfs(v, -1);
	int u = Find_Centroid(v, -1, Size[v]);
	cut[u] = true;
	Centroid_Tree[u] = p;
	if(p != -1)
	{
	    cTree[u].push_back(p);
	    cTree[p].push_back(u);
	}
	for(const int &w : G[u])
		if(!cut[w])
			build(w, u);
}

int main()
{
    int u, v;
	memset(Centroid_Tree,-1, sizeof Centroid_Tree);
    cin >> n >> m;
    while(m--)
	{
	    cin >> u >> v;
	    u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	build(0, -1);
    for(int i = 0; i < n; i++)
    {
        cout << i+1 << ": ";
        for(int &w : cTree[i])
            cout << w+1 << ' ';
        cout << '\n';
    }
	
	return 0;
}
