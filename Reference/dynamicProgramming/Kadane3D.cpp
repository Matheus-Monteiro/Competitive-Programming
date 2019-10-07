#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int par[22][22][22], pd[22][22][22];

int main()
{
	cin >> A >> B >> C;
	for(int i = 1; i <= A; i++)
		for(int j = 1; j <= B; j++)
			for(int k = 1; k <= C; k++)
				cin >> par[i][j][k];
				
	for(int i = 1; i <= A; i++)
		for(int j = 1; j <= B; j++)
			for(int k = 1; k <= C; k++)
				pd[i][j][k] = pd[i][j - 1][k] + pd[i][j][k - 1]
					 - pd[i][j - 1][k - 1] + par[i][j][k];

	int ans = -(1 << 25);	
	for(int h1 = 1; h1 <= C; h1++)
	for(int h2 = h1; h2 <= C; h2++)
	for(int l1 = 1; l1 <= B; l1++)
		for(int l2 = l1; l2 <= B; l2++)
		{
			int sum = -(1 << 25);
			for(int i = 1; i <= A; i++)
			{
				int s = pd[i][l2][h2] - pd[i][l1 - 1][h2] 
				- pd[i][l2][h1 - 1] + pd[i][l1 - 1][h1 - 1];
				sum = max(sum + s, s);
				ans = max(ans, sum);
			}
		}
	cout << ans << '\n';
	
	return 0;
}
