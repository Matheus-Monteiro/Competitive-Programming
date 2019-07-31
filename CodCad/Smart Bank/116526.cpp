#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10; 
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
int M[10], moeda[10] = {2, 5, 10, 20, 50, 100};
//int pd[MAX];

int memo[7][5005][505];

int solve(int k, int x, int q)
{
	if(x < 0 or k == 6) return 0;
	if(!x) return 1;
	if(memo[k][x][q] != -1)
		return memo[k][x][q];
	int ans = 0;
	if(q)
		return memo[k][x][q]  = solve(k, x - moeda[k], q - 1) + solve(k + 1, x, M[k + 1]);
	else
		return memo[k][x][q]  = solve(k + 1, x, M[k + 1]);
}

int main()
{
	memset(memo, -1, sizeof(memo));
	cin >> n;
	REP(i, 6) cin >> M[i];
	cout << solve(0, n, M[0]) << '\n';
	
	
	
	return 0;
	/*
	pd[0] = 1;

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < M[i]; j++)
			for(int k = 100000; k >= 0; k--)
				if((k - moeda[i]) >= 0 and pd[k - moeda[i]] > 0)
					pd[k] += pd[k - moeda[i]];
	for(int i = 0; i <= n; i++)
		cout << pd[i] << ' '; puts("");
	cout << pd[n] << '\n';

	return 0;*/
}