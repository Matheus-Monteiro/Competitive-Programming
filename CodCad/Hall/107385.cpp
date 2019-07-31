#include <bits/stdc++.h>
using namespace std;

int A[1000000], pd[1000000], n;

int solve(int i)
{
	if(!i) return pd[i] = A[i];
	return pd[i] = max(solve(i - 1) + A[i], A[i]);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	solve(n - 1);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, pd[i]);
	cout << (ans < 0 ? 0 : ans) << '\n';
	
	return 0;
}