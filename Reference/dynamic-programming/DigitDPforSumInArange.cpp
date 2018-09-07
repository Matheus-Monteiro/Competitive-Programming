#include "bits/stdc++.h"
using namespace std;
 
int dp[20][200][2];

int digitDP(int idx, int sum, int can, vector<int> &digit)
{// idx é o indice atual, sum a soma dos digitos até idx, e can uma flag para indicar se 
	if(idx == (int)digit.size()) // pode colocar qualquer valor a partir daqui
		return sum;
	if(dp[idx][sum][can] != -1)
		return dp[idx][sum][can];
	int ans = 0;
	for(int i = 0; i < 10; i++)
		if(can or i <= digit[idx])
			ans += digitDP(idx + 1, sum + i, can or i < digit[idx], digit);
	return dp[idx][sum][can] = ans;
}

int query(int x) // responde a consulta de 0 até x
{
	memset(dp, -1, sizeof(dp));	
    vector<int> digit;
    while(x)
    {
        digit.push_back(x%10);
        x /= 10;
    }
    reverse(digit.begin(), digit.end());
    return digitDP(0, 0, 0, digit);
}

int main()
{
    int q, a, b;
    cin >> q;
    while(q--)
    {
		cin >> a >> b;
		cout << query(b) - query(a - 1) << '\n';
	}
    return 0;
}
