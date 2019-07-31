#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int *p, int *v, int p_max){
	int T[n+1][p_max+1];
	for(int i = 0; i <= n; i++){
		for(int w = 0; w <= p_max; w++){
			if(i == 0 or w == 0)
				T[i][w] = 0;
			else{
				if(p[i-1] <= w)
					T[i][w] = max(v[i-1]+T[i-1][w-p[i-1]], T[i-1][w]);
				else
					T[i][w] = T[i-1][w];
			}
		}
	}
	return T[n][p_max];
}

int main(){
	int c, f, caso = 1;
	int peso[1005], val[1005];
	
	while(cin >> c >> f and (c or f)){
		for(int i = 0; i < f; i++)
			cin >> peso[i] >> val[i];	
		cout << "Teste " << caso++ << '\n' << knapsack(f, peso, val, c) << '\n';
	}
	
	return 0;
}