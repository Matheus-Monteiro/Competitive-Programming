// O( S * sqrt( SumKi ) )

#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;

int freq[50];
vector<int> value, weight;
int memo[5000][5000];

// Decompor o numero em uma soma de potencias
//de 2 de tal forma que qualquer numero entre 0 e k
// pode ser formado usando os numeros da decomposicao.
void decomp(int k, int w, int v) 
{
	int i = 1;
	freq[1] = k;
	while(true)
	{
		int m = (freq[i] - 1) / 2;
		if(freq[i] - m * 2 == 0) break;
		freq[i] -= 2 * m;
		freq[2 * i] += m;
		i++;
	}
	for(int i = 0; i < 32; i++)
	{
		while(freq[i]--)
		{
			value.push_back(i * v);
			weight.push_back(i * w);
		}
		freq[i] = 0;
	}
}

int solve(int id, int W)
{
	if(memo[id][W] != -1)
		return memo[id][W];
	if(id == value.size() or !W)
		return memo[id][W] = 0;
	int ans = 0;
	if(weight[id] > W)
		ans = solve(id + 1, W);
	else
		ans = max(value[id] + solve(id + 1, W 
			- weight[id]), solve(id + 1, W));
	return memo[id][W] = ans;
}

int main()
{
	int n, w, v, k, S;
	memset(memo, -1, sizeof(memo));
	cin >> n >> S;
	for(int i = 0; i < n; i++)
	{
		cin >> v >> w >> k;
		decomp(k, w, v);
	}
	cout << solve(0, S) << '\n';	
	
	return 0;
}
