#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll add(ll a, ll b, ll c)
{
	ll ans = (a + b) % c;
    if(ans < 0) ans += c;
    return ans;
}
 
ll mulmod(ll a, ll b, ll c)
{
	ll ans = 0;
	while(b)
	{
		if(b & 1) ans = add(ans, a, c);
		a = add(a, a, c);
		b /= 2;
	}
	return ans;
}
 
ll fexp(ll a, ll b, ll c)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = mulmod(ans, a, c);
		a = mulmod(a, a, c);
		b /= 2;
	}
	return ans;
}
 
bool miller(ll a, ll n)
{
    if (a >= n) return true;
    ll s = 0, d = n - 1;
    while(d%2 == 0 and d) d >>= 1, s++;
    ll x = fexp(a, d, n);
    if(x == 1 or x == n - 1) return true;
    for(int r = 0; r < s; r++, x = mulmod(x, x, n))
    {
        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}
 
bool isprime(ll n)
{
    int base[] = {2, 3, 5, 7, 11,
    	 13, 17, 19, 23, 29, 31, 37};
    for(int i = 0; i < 12; i++)
        if(!miller(base[i], n))
            return false;
    return true;
}
 
int32_t main()
{
    ll n;
    cin >> n;
    cout << (isprime(n) ? "PRIME\n"
    	 : "NOT PRIME\n");
 
    return 0;
}
