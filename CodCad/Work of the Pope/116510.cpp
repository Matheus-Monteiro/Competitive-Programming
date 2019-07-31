#include <bits/stdc++.h>
using namespace std;

const int MAX = 6 * 1e3; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-9; 

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
//#define gc getchar_unlocked

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef complex<ll> Pll;
typedef complex<ld> Pld;

int n;
vector<ii> arr;
map<int, map<int, int>> DP;

int solve(int k, int p)
{
	if(p < 0)
		return -1;
	if(k == (int)arr.size())
		return 0;
	if(DP[k].find(p) != DP[k].end())
		return DP[k][p];
	return DP[k][p] = max(solve(k + 1, min(p - arr[k].fi, arr[k].se - arr[k].fi)) + 1, solve(k + 1, p));
}

int main()
{
	cin >> n;
	REP(i, n)
	{
		int x, y;
		cin >> x >> y;
		arr.pb({x, y});
	}
	sort(all(arr), [](ii a, ii b){ return (a.se != b.se) ? a.se > b.se : a.fi > b.fi; });
	
	cout << solve(0, OO) << '\n';

	return 0;
}