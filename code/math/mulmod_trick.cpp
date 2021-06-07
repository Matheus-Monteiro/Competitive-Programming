#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mulmod(ll a, ll b, ll m)
{
	ll q = ll((long double)a*b/m);
	ll r = a * b - m * q;
	while(r < 0) r += m;
	while(r >= m) r -= m;
	return r;
}

int main()
{
	ll a, b, c;
	
	cin >> a >> b >> c;
	cout << mulmod(a, b, c) << '\n';

    return 0;
}
