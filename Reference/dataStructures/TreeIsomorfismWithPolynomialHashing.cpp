#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e5 + 10; 
const ll A = 911382323;
const ll B = 972663749;
 
int n, ID, degree[MAX];
map<ll, ll> formato;
bool vis[MAX];
 
inline ll norm(ll a)
{
		return a > B ? a = a % B : a;
}
 
inline ll add(ll a, ll b)
{
		a = norm(a); b = norm(b);
		return norm(a + b);
}
 
inline ll prod(ll a, ll b)
{
		a = norm(a); b = norm(b);
		return norm(a * b);
}
 
inline ll pol_hash(vector<ll> &v)
{
    ll p = 1, ans = 0;
    for(ll &w : v)
	{
		ans = add(ans, prod(p, w));
		p = prod(p, A);
    }
	return norm(ans);
}
 
ll dfs(int v, int p, vector<vector<int>> &G)
{
    if((int)G[v].size() == 1)
        return 1;
    vector<ll> ids;
    for(int &u : G[v])
    {
        if(u == p) continue;
        ll x = dfs(u, v, G);
        ids.push_back(x);
    }
    sort(ids.begin(), ids.end());
	ll ph = pol_hash(ids);
	if(formato.count(ph) <= 0) formato[ph] = ++ID;
    return formato[ph];
}
 
inline void findCenterAndComputeID(vector<vector<int>> &G, vector<ll> &val)
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
                    if(degree[G[u][i]] == 1) fila[1-turn].push(G[u][i]);
                }
        }
        turn ^= 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        val.push_back(dfs(i, -1, G));
    }
}
 
int32_t main()
{
    while(cin >> n)
    {
		formato.clear();
		ID = 1;
        vector<ll> val[2];
        for(int j = 0; j < 2; j++)
        {
            memset(degree, 0, sizeof(degree));
            vector<vector<int>> G(n + 1);
            for(int i = 1; i < n; i++)
            {
                int u, v;
                scanf(" %d %d", &u, &v); u--; v--;
                G[u].push_back(v);
                G[v].push_back(u);
                degree[v]++;
                degree[u]++;
            }
            findCenterAndComputeID(G, val[j]);
        }
        bool fl = false;
        for(ll &v0 : val[0])
            for(ll &v1 : val[1])
                if(v0 == v1)
                    fl = true;
        puts(fl ? "S" : "N");
    }
 
    return 0;
}
