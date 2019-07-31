#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 10; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-6; 
const long long MOD = 1000000000;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define all(vetor) vetor.begin(), vetor.end()
#define X real()
#define Y imag()
//#define gc getchar_unlocked

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef complex<ll> Pll;
typedef complex<ld> Pld;

ll mdc(ll a, ll b)
{
	return (b == 0 ? a : mdc(b, a%b));
}

int main()
{
	ll a, b, c, d;
	
	cin >> a >> b >> c >> d;
	
	ll den = b * d;
	ll num = a * d + b * c;
	
	ll g = mdc(num, den);
	
	cout << num / g << ' ' << den / g << '\n';
	
	return 0;
}