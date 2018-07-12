#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10; 

map<pair<int, int>, bool> deletada;
vector<int> G[MAX], path;
int n, m;

void hierholzer(int v)
{
    for(const int &u : G[v])    
    {
        if(deletada[{v, u}] == true) continue;
        deletada[{v, u}] = true;
        hierholzer(u);
    }
    path.push_back(v);
}

int main()
{	
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        G[u].push_back(v);
    }    
    hierholzer(0);   
    reverse(path.begin(), path.end());
    for(const int &u : path)
        cout << u + 1 << ' ';
    puts("");

	return 0;
}
