// Knapsack 0 - k sem valor em O((N*W*LogK) / word)

#include <bits/stdc++.h>
using namespace std;

int n, W, weight[10000], K[10000]; 
bitset<10000> T[100];

bool knapsack()
{
	T[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int s = K[i - 1];
		T[i] = T[i - 1];
		for(int p = 1; p <= s; s -= p, p *= 2)
			T[i] |= ((T[i] << (weight[i - 1] * p)) | T[i]);
		if(s)
			T[i] |= ((T[i] << (weight[i - 1] * s)) | T[i]);
	}
	return T[n][W];
}

void retrieve()
{
	vector<pair<int, int>> ans;
	for(int i = n; i > 0; i--)
	{
		int s = K[i - 1], qtd = 0;
		for(int p = 1; p <= s; p *= 2)
		if(W >= weight[i - 1] * p and T[i - 1][W - weight[i - 1] * p])
			W -= weight[i - 1] * p, qtd += p, s -= p;
		if(W >= weight[i - 1] * s and T[i - 1][W - weight[i - 1] * s])
			W -= s * weight[i - 1], qtd += s;
		if(qtd) ans.push_back({qtd, i - 1});
	}//first eh q quantidade de pesos i - 1
	for(pair<int, int> &w : ans)
		cout << w.first << ' ' << weight[w.second] << '\n';
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> weight[i];	
	for(int i = 0; i < n; i++)
		cin >> K[i];	
	cin >> W;
	cout << (knapsack() ? "possible\n" : "impossible\n");
	retrieve();
		
	return 0;
}
