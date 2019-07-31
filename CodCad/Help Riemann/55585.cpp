#include <bits/stdc++.h>
using namespace std;
const int MAX = 12 * 1e6;

int n;
bitset<MAX> isComposto;

int main()
{
	int cont = 0, n;
	scanf("%d", &n);
	isComposto[1] = 1;
	for(int i = 2; i <= MAX; i++)
		if(!isComposto[i])
		{
			cont++;
			if(cont == n)
			{
				printf("%d\n", i);
				return 0;
			}
			for(int j = 2; i*j <= MAX; j++)
				isComposto[i*j] = 1;
		}	
	return 0;
}