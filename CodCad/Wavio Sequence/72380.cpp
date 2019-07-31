#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10; 
const int OO = 0x3f3f3f3f;

const double EPS = 1e-9; 

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define mp make_pair
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

vector<int> lis(vector<int> &v)
{
    vector<int> pilha, ans;
    ans.resize(v.size());
    for(int i = 0; i < v.size(); i++)
    {
        auto it = lower_bound(all(pilha), v[i]);
        if(it == pilha.end())
            pilha.pb(v[i]);
        else
            *it = v[i]; 
        ans[i] = pilha.size();
    }
    return ans;
}

int main()
{	
    int n;
    vector<int> v;
    while(cin >> n)
    {
        v.resize(n);
        for(int &p : v) cin >> p;
        vector<int> v1 = lis(v);
        reverse(all(v));
        vector<int> v2 = lis(v);
        int ans = 1;
        for(int i = 0; i < v.size(); i++)
            ans = max(ans, 2*min(v1[i], v2[n-i-1]) - 1);
        cout << ans << '\n';
    }
    
	return 0;
}