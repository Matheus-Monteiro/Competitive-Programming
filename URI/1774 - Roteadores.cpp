// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Roteadores
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1774

#include <bits/stdc++.h>
const int MAX = 1e7; 

using namespace std;

struct t_aresta{
	int dis;
	int x, y;
};

int n, m;
t_aresta aresta[MAX];
int pai[MAX], peso[MAX];

int find(int x){
	return ((pai[x] == x) ? x : pai[x] = find(pai[x]));
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(peso[x] > peso[y])
		pai[y] = x;
	if(peso[x] < peso[y])
		pai[x] = y;
	if(peso[x] == peso[y]){
		pai[x] = y;
		peso[y]++;
	}
}

int main(){
	cin >> n >> m;

	for(int i = 1; i <= m; i++)
		cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;

	for(int i = 0; i <= n; i++) pai[i] = i;

	sort(aresta+1, aresta+m+1, [](t_aresta a, t_aresta b){return a.dis < b.dis;});

	int sz = 1, p = 0;

	for(int i = 1; i <= m; i++)
		if(find(aresta[i].x) != find(aresta[i].y)){
			p += aresta[i].dis;
			join(aresta[i].x, aresta[i].y);
		}
	
	cout << p << '\n';

	return 0;
}
