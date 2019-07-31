#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

vector< vector<int> > grafo;
int cor[MAX];

void dfs(int atual){
	cor[atual] = 1;
	for(int i = 0; i < grafo[atual].size(); i++){
		if(!cor[grafo[atual][i]])
			dfs(grafo[atual][i]);
	}
}

int main(){
	
	int n, m, x, y;
	
	cin >> n >> m;
	
	grafo.resize(n);
	
	while(m--){
		cin >> x >> y;
		grafo[x-1].push_back(y-1);
		grafo[y-1].push_back(x-1);
	}

	int num_times = 0;
	
	for(int i = 0; i < n; i++){
		if(!cor[i]){
			num_times++;
			dfs(i);
		}
	}
	
	cout << num_times << endl;
	
	return 0;
}