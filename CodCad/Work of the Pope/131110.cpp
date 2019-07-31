#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1e6 + 10; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-6; 
const long long MOD = 1000000000;

#define bug(x) cerr << #x << " = " << x << '\n'
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
#define sc(a) scanf(" %lld", &a)
//#define gc getchar_unlocked

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
typedef complex<ll> Pll;
typedef complex<ld> Pld;

bool cmp(ii a, ii b)
{
    return a.se > b.se;
    return (a.fi + b.fi > a.se and b.se >= a.fi + b.fi);
}

map<int, map<int, int>> DP;
vector<ii> arr;

int solve(int id, int R)
{
    if(R < 0) return -1;
    if(id == arr.size()) return 0;
    if(DP.find(id) != DP.end() and DP[id].find(R) != DP[id].end())
        return DP[id][R];
    return DP[id][R] = max(solve(id + 1, min(R - arr[id].fi, arr[id].se - arr[id].fi)) + 1, solve(id + 1, R));
}

int32_t main()
{
    int n;
    
    sc(n);
    REP(i, n)
    {
        int p, r;
        sc(p); sc(r);
        arr.pb({p, r});
    }
    
    sort(all(arr), cmp);
       
   // reverse(all(arr));
       
    cout << solve(0, OO) << '\n';
       
	return 0;
}