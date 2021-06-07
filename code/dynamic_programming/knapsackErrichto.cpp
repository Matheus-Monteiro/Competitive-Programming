#include <bits/stdc++.h>
using namespace std;
#define int long long
const int OO = 0x3f3f3f3f3f3f3f3f;
 
int n, w, maxi;
int value[120], weight[120];
int dp[100040];
 
int32_t main()
{
	cin >> n >> w;
	for(int i = 0; i < n; i++)
		cin >> weight[i] >> value[i];
	// dp[i] = maximum total value of itens with total weight exactly
	for(int item = 0; item < n; item++)
		for(int cur_wei = w - weight[item]; cur_wei >= 0; cur_wei--)
			dp[cur_wei + weight[item]] = max(dp[cur_wei + weight[item]],
			                                 dp[cur_wei] + value[item]);
	cout << *max_element(dp, dp + w + 1) << '\n';
 
	return 0;
}
