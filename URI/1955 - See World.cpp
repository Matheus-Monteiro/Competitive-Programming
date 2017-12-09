// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: See World
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1955

#include <bits/stdc++.h>

using namespace std;

int n, madj[1005][1005], cor[1005];

bool dfs(int u, int c){
	cor[u] = c;
	bool p = true;
	for(int i = 0; i < n; i++){
		int v = madj[u][i];
		if(!v and u != i){
			if(!cor[i])
				p = dfs(i, (c == 1 ? 2 : 1));
			else
				if(cor[i] == c)
					p = false;
		}
	}
	return p;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> madj[i][j];
		
	bool p = true;
	
	for(int i = 0; i < n and p; i++)
		if(!cor[i])
			p = dfs(i, 1);
	
	cout << (p ? "Bazinga!" : "Fail!") << '\n'; 
	
	return 0;
}
