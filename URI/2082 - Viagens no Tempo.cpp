// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Viagens no Tempo
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2082

#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;  
const int OO = (1 << 30); 
 
int n, r;  
int G[MAX][MAX], dist[MAX];  
bool cor[MAX], bin[MAX];  

int contract(int &s, int &t)  
{  
    memset(dist, 0, sizeof(dist));
    memset(cor, false, sizeof(cor));  
    int k, mincut, maxc;
    for(int i = 0; i < n; i++)
    {
        k = -1;
        maxc = -1;
        for(int j = 0; j < n; j++)
            if(!bin[j] and !cor[j] and dist[j] > maxc)
                k = j, maxc = dist[j];
        if(k == -1)
            return mincut;
        s = t;
        t = k;
        mincut = maxc;  
        cor[k] = true;
        for(int j = 0; j < n; j++)
            if(!bin[j] and !cor[j])
                dist[j] += G[k][j];
    }
    return mincut;
}

int Stoer_Wagner()
{
    int mincut = OO, s, t, ans;
    for(int i = 0; i < n-1; i++)
    {
        ans = contract(s, t);
        bin[t] = true;  
        if(mincut > ans)
            mincut = ans;  
        if(mincut == 0)
            return 0;  
        for(int j = 0; j < n; j++)
            if(!bin[j])  
                G[s][j] = (G[j][s] += G[j][t]);  
    }  
    return mincut;  
}

int main()
{
	int t;

	cin >> t;
	while(t--)
	{
    	cin >> n >> r;
		memset(G, 0, sizeof(G));
		memset(bin, 0, sizeof(bin));
		while(r--)
		{
		    int u, v, w;
		    cin >> u >> v >> w;
		    u--; v--;
		    G[u][v] = w;
		    G[v][u] = w;
		}
    	cout << Stoer_Wagner() << '\n';
	}	
	    
    return 0;
}
