#include <bits/stdc++.h>
using namespace std;
 
int n;
int table[10000][20];
 
//table[i][j] armazena o sucessor de distancia 2^j do vertice i
void build()
{
	for(int j = 1; (1 << j) <= n; j++)
		for(int i = 0; i < n; i++)
		    if(table[i][j-1] != -1)
			    table[i][j] = table[table[i][j-1]][j-1];	
}
 
int succ(int u, int k)
{
	while(k)
	{
		u = table[u][(int)log2(k&-k)];
		if(u == -1)
		    return -1;// nao existe	
		k -= k&-k;
	}
	return u;
}
//////////////////////////////////////////////////////
 
 
//algoritmo de Floyd para encontrar o tamanho de um ciclo 
//alcancado a partir de um vertice u em um grafo sucessor
int Floyd(int u)
{
	int a = succ(u, 1);
	int b = succ(u, 2);
 
	//encontra um vertice no ciclo
	while(a != b)
	{
		a = succ(a, 1);
		b = succ(b, 2);
		if(a == -1 or b == -1)
		    return -1;// nao existe ciclo
	}
 
	//a e b vao ficar posicionados no inicio do ciclo
	a = u;
	while(a != b)
	{
	    a = succ(a, 1);
	    b = succ(b, 1);   
	}
 
	//percorre todo o ciclo contando o seu tamanho
	b = succ(a, 1);
	int lenght = 1;
	while(a != b)
	{
		b = succ(b, 1);
		lenght++;
	}
	return lenght;
}
//////////////////////////////////////////////////////
 
 
int main()
{
	int u, v, m;
 
	cin >> n >> m;
	memset(table, -1, sizeof(table));
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v; u--; v--;
		table[u][0] = v;
	}
	build();
	cin >> u >> v;
	cout << "O sucessor de " << u << " com " << v << 
	" unidades a frente eh " << succ(u-1, v)+1 << '\n';
 
	cout << '\n';
 
	cin >> u;	
	cout << "tamanho do ciclo iniciando em " << u <<
	 ": " << Floyd(u-1) << '\n';
 
	return 0;
}


