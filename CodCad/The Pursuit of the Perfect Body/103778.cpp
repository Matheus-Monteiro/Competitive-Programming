#include <bits/stdc++.h>
using namespace std;
#define int long long

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
		ans = max(value[id] + solve(id + 1, W - weight[id]), solve(id + 1, W));
	return memo[id][W] = ans;
}

main()
{
	memset(memo, -1, sizeof(memo));
	cin >> W >> n;
	for(int i = 0; i < n; i++)
		cin >> weight[i] >> value[i];
	cout << solve(0, W) << '\n';
}