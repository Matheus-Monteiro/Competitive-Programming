#include <bits/stdc++.h>
using namespace std;
 
long long add(long long a, long long b, long long c)
{
	long long ans = (a + b) % c;
    if(ans < 0) ans += c;
    return ans;
}
 
long long mulmod(long long a, long long b, long long c)
{
	long long ans = 0;
	while(b)
	{
		if(b & 1) ans = add(ans, a, c);
		a = add(a, a, c);
		b /= 2;
	}
	return ans;
}
 
long long fexp(long long a, long long b, long long c)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1) ans = mulmod(ans, a, c);
		a = mulmod(a, a, c);
		b /= 2;
	}
	return ans;
}
 
bool miller(long long a, long long n)
{
    if (a >= n) return true;
    long long s = 0, d = n - 1;
    while(d%2 == 0 and d) d >>= 1, s++;
    long long x = fexp(a, d, n);
    if(x == 1 or x == n - 1) return true;
    for(int r = 0; r < s; r++, x = mulmod(x, x, n))
    {
        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}
 
bool isprime(long long n)
{
	if(n < 2) return false;
    int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int i = 0; i < 12; i++)
        if(!miller(base[i], n))
            return false;
    return true;
}
 
vector<int> prime;
bitset<10000000> composite;
 
void sieve()
{
	for(int i = 2; i < 10000000; i++)
		if(!composite[i])
		{
			prime.push_back(i);
			for(int j = 2; i * j < 10000000; j++)
				composite[i * j] = 1;
		}
}
 
long long countDivisors(long long n)
{
	int idx = 1;
	long long ans = 1, p = prime[0];
	while(p * p * p <= n)
	{
		int cnt = 1;
		while(n % p == 0)
			n /= p, cnt++;
		ans *= cnt;
		p = prime[idx++];
	}
	if(n == 1) return ans;
	if(isprime(n)) ans *= 2;
	else
	{
		long long sq = sqrt(n);
		if(sq * sq == n)
			ans *= 3;
		else if(n != 1)
			ans *= 4;
	}
	return ans;
}
 
int main()
{
    long long n;
    cin >> n;
    sieve();
	cout << countDivisors(n) << '\n';
 
    return 0;
}
