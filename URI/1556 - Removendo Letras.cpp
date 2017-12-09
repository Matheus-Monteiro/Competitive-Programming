// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Removendo Letras
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1556

#include <bits/stdc++.h>
using namespace std;

string str, s;
int G[1005][27];
int lig[27];
char word[1005];
int aux;

void dfs(int v)
{
    for(int i = 0; i < 27; i++)
    {
        if(G[v][i])
        {
            word[aux++] = i+'a';            
            word[aux] = '\0';
            cout << word << '\n';
            dfs(G[v][i]);
            aux--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    while(cin >> str)
    {
        s = 'L' + str;
        memset(lig, 0, sizeof(lig));
        memset(G, 0, sizeof(G));
        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = 0; j < 27; j++)
                G[i][j] = lig[j];
            lig[s[i]-'a'] = i;
        }
        aux = 0;
        dfs(0);
        cout << '\n';
    }

    return 0;
}
