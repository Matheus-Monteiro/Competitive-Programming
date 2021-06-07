#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll llrand()
{
	ll tmp = rand();
	return (tmp << 31) | rand();
}
 
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

ll rho(ll n)
{
    if(n % 2 == 0) return 2;
    ll d = n;
    while(d == n)
    {
        ll c = llrand() % n, x = llrand() % n, y = x;
        do
        {
            x = add(mulmod(x, x, n), c, n);
            y = add(mulmod(y, y, n), c, n);
            y = add(mulmod(y, y, n), c, n);
            d = __gcd(abs(x - y), n);
        }while(d == 1);
    }
    return d;
}
 
// Miller-Rabin AQUI
 
vector<ll> fac;

void factors(ll n) // encontrar os fatores primos de N
{// Usar Miller-Rabin para testar se N eh primo
    if(n == 1) return;
    if(isprime(n)) { fac.push_back(n); return; }
    ll d = rho(n);
    factors(d);
    factors(n / d);
}
 
int32_t main()
{
    srand(time(NULL));
    ll n;
    cin >> n;
    cout << rho(n) << '\n';
     
    return 0;
}
