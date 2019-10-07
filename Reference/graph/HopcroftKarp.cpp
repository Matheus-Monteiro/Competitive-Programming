#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;

int n, m;
vector<int> G[10000];
queue<int> q;
int pairU[10000], pairV[10000], dist[10000];

bool bfs()
{
    for(int u = 1; u <= m; u++)
        if(!pairU[u])
        {
            dist[u] = 0;
            q.push(u);
        }
        else dist[u] = OO;
    dist[0] = OO;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(dist[u] < dist[0])
            for(const int &v : G[u])
                if(dist[pairV[v]] == OO)
                {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
    }
    return (dist[0] != OO);
}
 
bool dfs(int u)
{
    if(u)
    {
		for(const int &v : G[u])
            if(dist[pairV[v]] == dist[u]+1)
                if (dfs(pairV[v]))
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
        dist[u] = OO;
        return false;
    }
    return true;
}

int hopcroftKarp()
{
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    int result = 0;
    while(bfs())
        for(int u = 1; u <= m; u++)
            if(!pairU[u] and dfs(u))
                result++;
    return result;
}

int main()
{
	n = m = 4;

	G[1].push_back(2);
	G[2].push_back(1);
	G[1].push_back(3);
	G[3].push_back(1);
	G[2].push_back(1);
	G[1].push_back(2);
	G[3].push_back(2);
	G[2].push_back(3);
	G[4].push_back(2);
	G[2].push_back(4);
	G[4].push_back(4);
	G[4].push_back(4);

	cout << hopcroftKarp() << '\n';

	return 0;
}
