#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;

int dp[MAX], c[MAX], n;

int coin(int x)
{
	if(x == 0) return 0;
	if(dp[x] != -1) return dp[x];
	int ans = OO;
	for(int i = 0; i < n; i++)
		if(x >= c[i])
			ans = min(ans, coin(x - c[i]) + 1);
	return dp[x] = ans;
}

main()
{
	memset(dp, -1, sizeof dp);
	int x;
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> c[i];
	cout << (coin(x) < 10 and coin(x) > 0 ? "S" : "N") << '\n';
}