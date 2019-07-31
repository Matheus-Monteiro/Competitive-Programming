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

int g, p, s, k, G[110][110], S[110], cnt[110];

int main()
{
	while(cin >> g >> p and (g or p))
	{
		REP(i, g)
			REP(j, p)
				cin >> G[i][j], G[i][j]--;
		cin >> s;
		REP(i, s)
		{
			REP(j, 105)
				cnt[j] = 0, S[j] = 0;
			cin >> k;
			REP(j, k)
				cin >> S[j];
			REP(l, g)
				REP(r, p)
					cnt[r] += S[G[l][r]];
			int mx = -1;
			REP(j, p)
				mx = max(mx, cnt[j]);
			REP(j, p)
				if(mx == cnt[j])
					cout << j + 1 << ' ';
			puts("");
		}
	}
	
	return 0;
}