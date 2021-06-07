#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;

int normalize(int x)
{
	x = x % MOD;
	if(x < 0) x += MOD;
	return x;
}

int add(int a, int b)
{
	return normalize(normalize(a) + normalize(b));
}

int prod(int a, int b)
{
	return normalize(normalize(a) * normalize(b));
}

int sub(int a, int b)
{
	return normalize(normalize(a) - normalize(b));
}

int expMod(int x, int e)
{
	int ans = 1;
	while(e > 0)
	{
		if(e & 1LL) ans = prod(ans, x), e--;
		else x = prod(x, x), e /= 2;
	}
	return normalize(ans);
}

int inv(int x)
{
	return expMod(x, MOD - 2);
}


int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inv(int a, int m) {
	int x, y;
	int g = extended_euclidean(a, m, x, y);
	if (g != 1) return -1; // nao tem inverso
	return ((x % m) + m) % m;
}
 
