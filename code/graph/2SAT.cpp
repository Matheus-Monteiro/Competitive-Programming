// Os vertices pares indicam as proposicoes falsas
// Os vertices impares indicam as proposicoes verdadeiras
// Achar qual proposicao relativa a cada vertice, eh so dividiar vertice/2
// tamG = quantidade_proposicoes*2

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3;

int n, m, tamG;
vector<int> G[MAX], G_t[MAX], C[MAX];
stack<int> sta;
bool cor[MAX];
int componente[MAX], comp;

void preenche(int v)
{
    cor[v] = true;
    for(const int &u : G_t[v])
        if(!cor[u])
            preenche(u);
    sta.push(v);
}

void dfs(int v, int comp)
{
    componente[v] = comp;
    C[comp].push_back(v);
    for(const int &u : G[v])
        if(!componente[u])
            dfs(u, comp);
}

void kosaraju()
{
    memset(cor, false, sizeof(cor));
    for(int i = 0; i < tamG; i++)
        if(!cor[i])
            preenche(i);
    memset(cor, false, sizeof(cor));
    comp = 1;
    while(!sta.empty())
    {
        int u = sta.top();
        sta.pop();
        if(componente[u]) continue;
        dfs(u, comp);
        comp++;
    }
}



// Id no grafo que representa a proposicao de numero P como verdadeira.
int idTrue(int p)
{
    return (p << 1) + 1;
}

// Id no grafo que representa a proposicao de numero P como falsa.
int idFalse(int p)
{
    return (p << 1);
}

bool twoSat()
{
	kosaraju();
	for(int i = 0; i < tamG; i+=2)
	{
	// Todo par de proposicoes(proposicao falsa, proposicao verdadeira)
	// Nao podem estar no mesmo componente
		if(componente[i] == componente[i + 1])
		    return false;
	}
	return true;
}

int addEdge(int u, int v)
{
    G[idFalse(u)].push_back(idTrue(v));
    G[idFalse(v)].push_back(idTrue(u));
    G[idTrue(u)].push_back(idFalse(v));
    G[idTrue(v)].push_back(idFalse(u));
    // montar grafo transposto para kosaraju nessa
    // aplicacao o grafo G sera igual ao transposto
    G_t[idFalse(u)].push_back(idTrue(v));
    G_t[idFalse(v)].push_back(idTrue(u));
    G_t[idTrue(u)].push_back(idFalse(v));
    G_t[idTrue(v)].push_back(idFalse(u));
}



vector<int> g[MAX];
vector<int> ts;
int value[MAX];

void topSort(int v)
{
    cor[v] = true;
    for(int &u : G[v])
        if(!cor[u])
            topSort(u);
    ts.push_back(v);
}

void mountDAG()
{
    for(int v = 0; v < tamG; v++)
        for(int &u : G[v])
            if(componente[v] != componente[u])
                g[componente[v]].push_back(componente[u]);
    memset(cor, false, sizeof(cor));
    for(int v = 1; v < comp; v++)
        if(!cor[v])
            topSort(v);
    // nao inverter ts, pois precisamos da ordenacao
    // topologica ao contrario
}

// encontrar uma atribuicao (TREU ou FALSE) para as proposicoes
void assignment() 
{
    if(!twoSat()) return;
    mountDAG();
    memset(value, -1, sizeof(value));
    for(int &v : ts)
        for(int &u : C[v])
            if(value[u >> 1] == -1) //   u / 2 eh a proposicao
                value[u >> 1] = (u & 1 ? 1 : 0);
    for(int i = 0; i < (tamG >> 1); i++)
        cout << value[i] << ' ';
    puts("");
}

int main()
{
    cin >> n >> m;
    tamG = 2 * n;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        addEdge(u, v);
    }
    cout << twoSat() << '\n';
    assignment();

    return 0;
}
