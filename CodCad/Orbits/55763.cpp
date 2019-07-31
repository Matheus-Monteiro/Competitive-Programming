#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll a, b;
	
	cin >> a >> b;
	cout << ((a*b)/__gcd(a, b)) << '\n';

	return 0;
}