#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
const int MOD = 10;
const int OO = (1 << 20);

int n, M[MAX][MAX], memo[MAX][1 << MAX];

// Resolução do problema do caixeiro viajante usando programação dinâmica.
// funciona para no máximo 20 vértices.
int TSP(int id, int mask)
{
	if(((1 << n) - 1) == mask)
		return M[id][0];
	if(memo[id][mask] != -1)
		return memo[id][mask];
	int ans = INT_MAX;
	for(int i = 0; i < n; i++)
		if((mask & (1 << i)) == 0)
			ans = min(ans, M[id][i] + TSP(i, mask | (1 << i)));
	return memo[id][mask] = ans;
}

int main()
{
	srand(time(NULL));
	
	cin >> n;
	cout << "Numero de vertices " << n << " (matriz de custo abaixo)\n\n";
	// Gera um grafo aleatório de N vértices
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			M[i][j] = M[j][i] = (i == j ? 0 : (rand() % MOD) + 1);
	
	// Imprime a matriz de custo do grafo. O caractere " - " representa custo infinito.
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << M[i][j] << ' ';
		cout << '\n';
	}

	// Inicializa a tabela de memoization da PD
	memset(memo, -1, sizeof(memo));
	
	// Solução ótima do problema do caixeiro viajante no grafo gerado.
	cout << "\nSolucao do Caixeiro Viajante " << TSP(0, 1) << '\n';	
	
	return 0;
}