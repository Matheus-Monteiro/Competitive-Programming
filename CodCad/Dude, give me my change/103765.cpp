#include <bits/stdc++.h>
using namespace std;
using namespace std;

vector<int> coin;
int memo[100000];

int solve(int troco)
{
	if(troco < 0)
		return (1 << 25);
	if(memo[troco] != -1)
		return memo[troco];
	if(troco == 0)
		return 0;
	int ans = (1 << 25);
	for(int i = 0; i < coin.size(); i++)
		ans = min(ans, 1 + solve(troco - coin[i]));
	return memo[troco] = ans;
}

int main()
{
	memset(memo, -1, sizeof(memo));
	int n, troco;
	cin >> n >> troco;
	coin.resize(n);
	for(int &w : coin)
		cin >> w;
	puts(solve(troco) != (1 << 25) ? "S" : "N");
		
	return 0;
}