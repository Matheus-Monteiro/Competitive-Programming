#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pd[101][21];

ll fat(ll n, ll k)
{
	if(n <= 0) return 1;
	if(pd[n][k] != -1)
		return pd[n][k];
	return pd[n][k] = n*fat(n-k, k);
}

int main()
{
	int q, aux;
	string s;
	
	scanf("%d", &q);
	memset(pd, -1, sizeof(pd));
	while(q--)
	{
		cin >> s;
		int k = 0, i = 0;
		while(isdigit(s[i])) i++;
		aux = 0;
		for(int j = i-1, p = 1; j >= 0; j--)
			aux += (p*(s[j]-'0')), p *= 10;
		k = s.size()-i;
		printf("%lld\n", fat(aux, k));
	}
	return 0;
}