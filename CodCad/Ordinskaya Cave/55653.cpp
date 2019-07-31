#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n, k;
	vector<ll> v;
	scanf("%lld %lld", &n, &k);
	v.resize(n);
	for(ll &p : v)
		scanf("%lld", &p);
	ll ant = min(v[0], abs(v[0]-k));
	ll ans = ant;
	n--;
	for(ll i = 1; i < v.size(); i++)
		if(min(v[i], abs(v[i]-k)) >= ant)
			ans += min(v[i], abs(v[i]-k)), ant = min(v[i], abs(v[i]-k)), n--;
		else if(max(v[i], abs(v[i]-k)) >= ant)
			ans += max(v[i], abs(v[i]-k)), ant = max(v[i], abs(v[i]-k)), n--;
	printf(n ? "-1\n" : "%lld\n", ans);

	return 0;
}