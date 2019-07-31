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

#define gc getchar_unlocked
#define pc putchar_unlocked

inline void scanint(int &k)
{
	bool sinal = true;
    register char c;
    k = 0;
    for(c = gc(); sinal and (c < '0' or c > '9'); c = gc())
    	if(c == '-')
    		sinal = false;
    for(; c >= '0' and c <= '9'; c = gc())
        k = (k << 3) + (k << 1) + c - '0';
	if(!sinal) k = -k;
}
 
inline void printint(int n)
{
	if(n < 0) pc('-');
	n = abs(n);
	int rev = n, cnt = 0;
	if(!n)
	{
		pc('0');
		pc('\n');
		return;
	}
	while(!(rev % 10))
		cnt++, rev /= 10;
	rev = 0;
	while(n)
		rev = (rev << 3) + (rev << 1) + n % 10, n /= 10;
	while(rev)
		pc(rev % 10 + '0'), rev /= 10;
	while(cnt--)
		pc('0');
	pc('\n');
}

int n, m, arr[MAX], pd[MAX];

int main()
{
	scanint(n);
	REP(i, n)
		scanint(arr[i]);
	for(int i = 0; i < n; i++)
		pd[i] = 1;
	for(int i = n - 1; i >= 0; i--)
		for(int j = 0; j < i; j++)
			if(arr[i] >= arr[j])
				pd[j] = max(pd[j], pd[i] + 1);
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans, pd[i]);
	cout << ans << '\n';
	
	return 0;
}