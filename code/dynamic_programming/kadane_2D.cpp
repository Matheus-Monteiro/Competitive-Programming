#include <bits/stdc++.h>
using namespace std;

int pd[100][100], A[100][100];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> A[i][j], pd[i][j] = pd[i][j - 1] + A[i][j];    
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= m; j++)
		{
			int sum = 0;
			for(int k = 1; k <= n; k++)
			{
				sum += pd[k][j] - pd[k][i - 1];
				if(sum < 0) sum = 0;
				ans = max(ans, sum);
			}
		}
	cout << ans << '\n';

	return 0;
}
