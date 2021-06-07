#include <bits/stdc++.h>
using namespace std;

// Knuth Optimization

int pf[6000], n;
int dp[6000][6000];

int sum(int l, int r)
{
	return pf[r] - pf[l - 1];
}

int solve(int l, int r)
{
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int ans = (1 << 30);
	for(int i = l; i <= r; i++)
		ans = min(ans, sum(l, r) + solve(l, i - 1) + solve(i + 1, r));
	return dp[l][r] = ans;
}



#define ii pair<int, int>
#define fi first
#define se second

ii DP[6000][6000];

//Point(l, r - 1) <= Point(l, r) <= Point(l + 1, r)
ii knuth(int l, int r)
{	
	if(l == r) return {sum(l, r), l};
	if(DP[l][r] != ii(-1, -1)) return DP[l][r];
	int lef = knuth(l, r - 1).se;
	int rig = knuth(l + 1, r).se;
	int point = l, ans = (1 << 30);
	for(int i = lef; i <= rig; i++)
	{
		int cur = sum(l, r);
		if(i - 1 >= l) cur += knuth(l, i - 1).fi;
		if(i + 1 <= r) cur += knuth(i + 1, r).fi;
		if(cur < ans) ans = cur, point = i;
	}				
	return DP[l][r] = {ans, point};
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	//for(int i = 1; i <= n; i++)
		//cin >> pf[i], pf[i] += pf[i - 1];
	//cout << solve(1, n) << endl;

	memset(DP, -1, sizeof(DP));
	cout << knuth(1, n).fi << endl;

	return 0;
}
