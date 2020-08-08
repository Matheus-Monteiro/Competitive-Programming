#include <bits/stdc++.h>
using namespace std;

int n, W, weight[2005], value[2005];
int memo[2005][2005];

int solve(int id, int W)
{
	if(memo[id][W] != -1)
		return memo[id][W];
	if(id == n or !W)
		return memo[id][W] = 0;
	int ans = 0;
	if(weight[id] > W)
		ans = solve(id + 1, W);
	else
		ans = max(value[id] + solve(id + 1, 
			W - weight[id]), solve(id + 1, W));
	return memo[id][W] = ans;
}

void ans(int id, int W)
{
	if(id == n or !W)
		return;
	if(solve(id + 1, W) == memo[id][W])
		ans(id + 1, W);
	else
	{
		cout << id << ' ';
		ans(id + 1, W - weight[id]);
	}
}

int main()
{
	memset(memo, -1, sizeof(memo));
	cin >> n >> W;
	for(int i = 0; i < n; i++)
		cin >> weight[i] >> value[i];
	cout << solve(0, W) << '\n';
	cout << "Objetos escolhidos 0 - indexdos\n";
	ans(0, W);
	puts("");
	
	return 0;
}
