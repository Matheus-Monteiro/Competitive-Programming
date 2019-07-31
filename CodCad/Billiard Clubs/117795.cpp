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

int main()
{
	int n, a, ans = 0;
	cin >> n;
	set<int> s;
	while(n--)
	{
		cin >> a;
		if(s.find(a) == s.end())
		{
			ans += 2;
			s.insert(a);
		}
		else
			s.erase(a);
	}
	cout << ans << '\n';
	
	return 0;
}