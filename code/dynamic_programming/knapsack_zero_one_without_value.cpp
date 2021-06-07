// Knapsack 0 - 1 sem valor em O((N*W) / word)
#include <bits/stdc++.h>
using namespace std;

int n, W, weight[10000]; 
bitset<10000> T[100];

bool knapsack()
{
	T[0][0] = 1;
	for(int i = 1; i <= n; i++)
		T[i] = ((T[i - 1] << weight[i - 1]) | T[i - 1]);
	return T[n][W];
}

void retrieve()
{
	vector<int> ans;
	for(int i = n; i > 0; i--)
		if(W >= weight[i - 1] and T[i - 1][W - weight[i - 1]])
		{
			ans.push_back(i - 1);
			W -= weight[i - 1];
		}
	for(int &w : ans) cout << weight[w] << ' '; puts("");
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> weight[i];		
	cin >> W;
	cout << knapsack() << '\n';
	retrieve();
		
	return 0;
}
