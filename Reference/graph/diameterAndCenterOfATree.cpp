#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
 
int n;
vector<int> G[MAX];
 
int bfs(int v, vector<int> &dist)
{
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    int lgv = -1;
    while(!q.empty())
    {
        int u = q.front(); q.pop();	
        lgv = u;
        for(int &w : G[u])
            if(dist[w] == -1)
            {
                dist[w] = dist[u] + 1;
                q.push(w);
            }
    }
    return lgv;
}
 
void findCenterAndDiameter(int w)
{
    vector<int> dist1(n + 1, -1);
    vector<int> dist2(n + 1, -1);
	int v = bfs(w, dist1);
	int u = bfs(v, dist2);
	int d = dist2[u];
    dist1.assign(n + 1, -1);
    u = bfs(u, dist1);
    cout << "center ";
    for(int i = 0; i < n; i++)
    {
        int d1 = dist1[i], d2 = dist2[i];
        if(d1 == d / 2 and d2 == d - d / 2 or d2 == d / 2 and d1 == d - d / 2)
        cout << i + 1 << ' ';
    }
    cout << "\ndiameter " << d << '\n';
}
 
int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        G[u].push_back(v);
		G[v].push_back(u);
    }
    findCenterAndDiameter(0);
 
    return 0;
}
