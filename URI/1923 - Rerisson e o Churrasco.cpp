// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Rerisson e o Churrasco
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1923

#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> si;

int n, g;
vector<int> G[6000];
map<string, int> mp1;
map<int, string> mp2;
int cor[6000];

void bfs(int v)
{
    memset(cor, -1, sizeof(cor));
    queue<int> q;
    q.push(v);
    cor[v] = 0;
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
    string u, v;
    int id = 0;
    
    cin >> n >> g;
    while(n--)
    {
        cin >> u >> v;
        int _u, _v;
        if(mp1.find(u) == mp1.end())
            mp1[u] = id, mp2[id] = u, _u = id++;
        else
            _u = mp1[u];
        if(mp1.find(v) == mp1.end())
            mp1[v] = id, mp2[id] = v, _v = id++;
        else
            _v = mp1[v];
        G[_u].push_back(_v);
        G[_v].push_back(_u);
    }
    bfs(0);
    vector<string> s;
    for(int i = 1; i < id; i++)
        if(cor[i] != -1 and cor[i] <= g)
            s.push_back(mp2[i]);
    sort(s.begin(), s.end());
    cout << s.size() << '\n';
    for(int i = 0; i < s.size(); i++)
        cout << s[i] << '\n';
    
    return 0;
}
