#include <bits/stdc++.h>

using namespace std;

int knapsack(int p_max, int peso[], int val[], int n){
	int i, w;
	int k[n+1][p_max+1];
	for(i = 0; i <= n; i++){
		for(w = 0; w <= p_max; w++){
			if(!i or !w)
				k[i][w] = 0;
			else
				if(peso[i-1] <= w)
					k[i][w] = max(val[i-1]+k[i-1][w-peso[i-1]], k[i-1][w]);
				else
					k[i][w] = k[i-1][w];
		}
	}
	return k[n][p_max];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int peso[2005], val[2005], n, p_max;
	
	cin >> p_max >> n;
	
	for(int i = 0; i < n; i++)
		cin >> peso[i] >> val[i];
	
	cout << knapsack(p_max, peso, val, n) << '\n';
	
	return 0;
}	