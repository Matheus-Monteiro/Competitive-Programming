// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Salas Separadas
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1979

#include <bits/stdc++.h>
using namespace std;

int n, id, aux;
int cor[110];
bool bi;
int G[110][110];

void dfs(int v, int c)
{
    cor[v] = c;
    for(int i = 1; i <= n and !bi; i++)
        if(G[v][i])
            if(!cor[i])
                dfs(i, c == 1 ? 2 : 1);
            else
                bi = (cor[v] == cor[i]);
}

int main()
{
    while(cin >> n and n)
    {
        memset(G, 0, sizeof(G));
        memset(cor, 0, sizeof(cor));
        string s;
        for(int i = 0; i < n; i++)
        {
            cin >> id;
            cin.ignore();
            getline(cin, s);
            stringstream ss(s);
            while(ss)
            {
                ss >> aux;
                G[id][aux] = G[aux][id] = 1;
            }
        }
        bi = false;        
        for(int i = 1; i <= n and !bi; i++)
            if(!cor[i])
                dfs(i, 1);
        cout << (!bi ? "SIM" : "NAO") << '\n';
    }     
    return 0;
}
