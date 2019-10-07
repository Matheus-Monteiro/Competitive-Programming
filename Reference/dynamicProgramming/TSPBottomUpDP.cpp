#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;

int n;
double dist[20][20];
double pd[1 << 17][20];

int tsp(int ori)
{
	memset(pd, 63, sizeof(pd));
	for(int i = 0; i < n; i++)
		if(i != ori)
			pd[1 << i][i] = dist[ori][i];
	for(int k = 0; k < (1 << n); k++)
	for(int i = 0; i < n; i++)
	if(k & (1 << i))
		for(int j = 0; j < n; j++)
			if((k & (1 << j)) and i != j)
			pd[k][j] = min(pd[k][j], pd[k ^ (1 << j)][i] + dist[i][j]);
	return pd[(1 << n) - 1][ori];
}

int main()
{
	// inicializar dist, dist[i][j] guarda a distancia de i para j no grafo
	// chamar tsp	
	
	return 0;
}
