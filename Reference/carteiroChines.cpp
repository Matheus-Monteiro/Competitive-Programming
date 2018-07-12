#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
const int MOD = 10;
const int OO = (1 << 20);
 
int M[MAX][MAX], grau[MAX];
 
int main()
{
	srand(time(NULL));
 
	int n;
	cin >> n;
	// Gera um grafo aleatório de N vértices
	cout << "Numero de vertices " << n << " (matriz de custo abaixo)\n\n";
	
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			int x = rand() % MOD;
			if(!x) x++;
			if(i == j)
				M[i][j] = 0;
			else if(i + 1 == j or rand() % 3)
				M[i][j] = M[j][i] = x;
			else
				M[i][j] = M[j][i] = OO;
		}
 
	// Imprime a matriz de custo do grafo. O caractere " - " representa custo infinito.
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(M[i][j] == OO)
				cout << "- ";
			else
				cout << M[i][j] << ' ';
		cout << '\n';
	}
 
	// Atualiza o grau de cada vértice e armazena a soma de todas as arestas na variável resposta.
	int resposta = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(M[i][j] != OO and M[i][j])
				grau[i]++, resposta += M[i][j];
 	resposta /= 2;
 
	vector<int> vertice; // Vetor para armazenar todos os vértices de grau impar.
	// Adicionar os vértices de grau impar no vetor vertice.
	for(int i = 0; i < n; i++)
		if(grau[i] & 1)
			vertice.push_back(i);
 
	// Algoritmo de Floyd-Warshall para calcular a menor distância entre todos os pares de vértices.
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
 
	// Matching mínimo no grafo Kp formado pelos vértices de grau impar.
	// O custo entre cada aresta (u,v) nesse grafo é o menor caminho entre u e v.
	int matching = OO;
	do
	{
		int atual = 0;
		for(int i = 0; i < (int)vertice.size() - 1; i += 2)
			atual += M[vertice[i]][vertice[i + 1]];
		matching = min(atual, matching);
	}while(next_permutation(vertice.begin(), vertice.end()));
 
	resposta += matching;
 
	// A resposta final é a soma do peso de todas as arestas do grafo com o matching mínimo.
	// Pois duplicamos todos os menores caminhos do matching mínimo...
	cout << "\nSolucao do carteiro chines " << resposta << '\n';
 
	return 0;
}