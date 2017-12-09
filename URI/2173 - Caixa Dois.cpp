// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Caixa Dois
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2173

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> G;
int pai[MAX], peso[MAX];

int find(int x){
	if(pai[x] == x)
		return x;
	return pai[x] = find(pai[x]);
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
	//ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int n, m, x, y, c;
	while(cin >> n >> m and (n or m)){
    	while(m--){
    		cin >> x >> y >> c;
    		x--; y--;
    		G.push_back({c, {x, y}});
    	}    
    	
    	sort(G.begin(), G.end(), [](iii a, iii b){ return a.first < b.first;});
    	
    	for(int i = 0; i <= n; i++) pai[i] = i, peso[i] = 0;
    
    	int ans1 = 0;
    	for(int i = 0; i < G.size(); i++){
    		if(find(G[i].second.first) != find(G[i].second.second)){
    			ans1 += G[i].first;
    			join(G[i].second.first, G[i].second.second);
    		}
    	}
    
    	for(int i = 0; i < n; i++) pai[i] = i, peso[i] = 0;
    		
    	int ans2 = 0;
    	for(int i = G.size()-1; i >= 0; i--){
    		if(find(G[i].second.first) != find(G[i].second.second)){
    			ans2 += G[i].first;
    			join(G[i].second.first, G[i].second.second);
    		}	
    	}
    	cout << ans2-ans1 << '\n';
    	G.clear();
	}
	
    return 0;
}
