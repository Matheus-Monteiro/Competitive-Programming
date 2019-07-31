#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e6 + 10; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-9; 
const int MOD = 9901;
 
#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < (int)n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define all(vetor) vetor.begin(), vetor.end()
#define X real()
#define Y imag()
//#define getchar getchar_unlocked
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef complex<ll> Pll;
typedef complex<ld> Pld;

ll n, m, k;
ll F[10000];
ll A[10000];

ll solve(ll k)
{
	if(F[k] != -1)
		return F[k];
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans = ((ans % m) + (A[i] * solve(k - i)) % m) % m;
	return F[k] = ans;
}

int main()
{
	memset(F, -1, sizeof(F));
	
	cin >> n >> k >> m;
	REP(i, n)
	{	
		cin >> A[i + 1];
		A[i + 1] = A[i + 1] % m;
		if(A[i + 1] < 0) A[i + 1] += m;
	}
	REP(i, n)
		cin >> F[i + 1];
	cout << solve(k) << '\n';
	
    return 0;
} 