#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long num)
{
	if(num == 1) return true;
	long long k = sqrt(num);
	for(int i = 2; i <= k; i++)
		if(num%i == 0)
			return false;
	return true;
}

int main()
{
	long long num;	
	scanf("%lld", &num);	
	printf(isPrime(num) ? "N\n" : "S\n");
	
	return 0;
}