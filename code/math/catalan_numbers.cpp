#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10; 
const long long MOD = 1000000000;

int catalan[MAX];

void init()
{
    catalan[0] = catalan[1] = 1;
    for(int i = 2; i <= 1000; i++)
        for(int j = 0; j < i; j++)
        {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if(catalan[i] >= MOD)
                catalan[i] -= MOD;
		}
}

int main()
{
	init();
	int n;
	
	while(cin >> n)
		printf("%d\n", catalan[n]);
		
	return 0;
}
