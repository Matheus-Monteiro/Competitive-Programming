// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: DFSr - Hierarquia de Prof...
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1081

#include <bits/stdc++.h>
using namespace std;

int n, m;
int G[25][25];
bool cor[25], flag;
string s;

void dfs(int v)
{
    cor[v] = 1;
    for(int i = 0; i < n; i++)
    {
        if(G[v][i])
        {
            s.push_back(' ');
            s.push_back(' ');
            if(!cor[i])
            {
                cout << s << v << '-' << i << " pathR(G," << i << ')' << '\n'; 
                flag = true;
                dfs(i);
            }
            else
                cout << s << v << '-' << i << '\n', flag = true; 
            s.pop_back();
            s.pop_back();
        }
    }
}

int main()
{
    int tt, caso = 1, u, v;
    cin >> tt;
    while(tt--)
    {
        cin >> n >> m;
        memset(G, 0, sizeof(G));
        memset(cor, 0, sizeof(cor));
        while(m--)
        {
            cin >> u >> v;
            G[u][v] = 1; 
        }
        cout << "Caso " << caso++ << ':' << '\n';
        for(int i = 0; i < n; i++)
            if(!cor[i])
            {
                s.clear();
                flag = false;
                dfs(i);
                if(flag) cout << '\n';
            }
    }
    
    return 0;
}

