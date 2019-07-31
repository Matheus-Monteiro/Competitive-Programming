#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-6; 
const long long MOD = 1000000000;

#define bug(x) cout << #x << " = " << x << '\n'
#define _ << " , " <<
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define all(vetor) vetor.begin(), vetor.end()
#define X real()
#define Y imag()
#define sc(a) scanf(" %d", &a)
//#define gc getchar_unlocked

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef complex<ll> Pll;
typedef complex<ld> Pld;

int dp[MAX], c[MAX], n;

int32_t main()
{
	memset(dp, -1, sizeof dp);
	int x;
	sc(n); sc(x);
	for(int i = 0; i < n; i++)
		sc(c[i]);
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for(int i = 0; i <= x; i++)
		for(int j = 0; j < n; j++)
			dp[i + c[j]] = min(dp[i] + 1, dp[i + c[j]]);
	cout << (dp[x] < 10 ? "S" : "N") << '\n';
		
	return 0;
}