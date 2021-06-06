#include <bits/stdc++.h>
using namespace std;

int dist[22][22], m;
int memo[20][1 << 20];

int solve(int id, int mask) {
	if(((1 << m) - 1) == mask)
		return dist[id][0];
	if(memo[id][mask] != -1)
		return memo[id][mask];
	int ans = INT_MAX;
	for(int i = 0; i < m; i++)
		if((mask & (1 << i)) == 0)
			ans = min(ans, dist[id][i] + solve(i, mask | (1 << i)));
	return memo[id][mask] = ans;
}

int main() {
	memset(memo, -1, sizeof(memo));
	//inicializa a matriz dist com as distancias
	//de todo mundo pra todo mundo..
	cout << solve(0, 1) << '\n';
	return 0;
}
