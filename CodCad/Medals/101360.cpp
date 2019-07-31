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

int main()
{
	int a, b, c;
	
	cin >> a >> b >> c;
	
	if(a < b and a < c)
	{
		printf("%d\n", 1);
		if(b < c)
			printf("%d\n%d\n", 2, 3);
		else
			printf("%d\n%d\n", 3, 2);
	}
	else if(b < a and b < c)
	{
		printf("%d\n", 2);
		if(a < c)
			printf("%d\n%d\n", 1, 3);
		else
			printf("%d\n%d\n", 3, 1);
	}
	else
	{
		printf("%d\n", 3);
		if(a < b)
			printf("%d\n%d\n", 1, 2);
		else
			printf("%d\n%d\n", 2, 1);
	}
	
    return 0;
} 