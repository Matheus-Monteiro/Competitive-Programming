#include <bits/stdc++.h>
using namespace std;
 
long long llrand()
{
	long long tmp = rand();
	return (tmp << 31) | rand();
}
 
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
 
long long rho(long long n)
{
    if(n % 2 == 0) return 2;
    long long d, c = llrand() % n, x = llrand() % n, y = x;
    do
    {
        x = add(mulmod(x, x, n), c, n);
        y = add(mulmod(y, y, n), c, n);
        y = add(mulmod(y, y, n), c, n);
        d = __gcd(abs(x - y), n);
    }while(d == 1);
    return d;
}
 
int main()
{
    srand(time(NULL));
    long long n;
    cin >> n;
    cout << rho(n) << '\n';
     
    return 0;
}
