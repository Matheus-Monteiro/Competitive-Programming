#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-8; 

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

int BIT[MAX];

int update(int x, int v)
{
    while(v <= MAX-2) BIT[v] += x, v += v&-v;
}

int query(int v)
{
    int sum = 0;
    while(v) sum += BIT[v], v -= v&-v;
    return sum;
}

int main()
{	
    int n, arr[MAX];
    while(cin >> n and n)
    {
        int ans = 0;
        REP(i, n)
        {
            cin >> arr[i];
            ans += query(MAX - 2)- query(arr[i]);
            update(1, arr[i]);
        }
        memset(BIT, 0, sizeof(BIT));
        cout << (ans & 1 ? "Marcelo\n" : "Carlos\n");
    }
	return 0;
}