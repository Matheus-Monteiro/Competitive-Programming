#include <bits/stdc++.h>
using namespace std;
const int MAX = 13 * 1e5;

int n;
bitset<MAX> isComposto;
int ans[MAX];

void crivo()
{
	isComposto[1] = 1;
	int cont = 0;
	for(int i = 2; i <= MAX; i++)
		if(!isComposto[i])
		{
			cont++;
			ans[i] = cont;
			for(int j = 2; i*j <= MAX; j++)
				isComposto[i*j] = 1;
		}		
}

int main()
{
	int n, q;
	scanf("%d", &q);
	crivo();
	while(q--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);	
	}
	return 0;
}