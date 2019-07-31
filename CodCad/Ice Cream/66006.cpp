#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
//#define gc getchar_unlocked

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<ii> v;

int main()
{
    int p, s;    
    
    cin >> p >> s;
    REP(i, s)
    {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        v.pb({x, y});
    }
    sort(v.begin(), v.end());
    int x, y;
    REP(i, s)
    {
        x = v[i].fi, y = v[i].se;
        int j = i + 1;
        while(j < s and v[j].fi <= y)
            y = max(v[j].se, y), j++;
        i = j - 1;
        cout << x << ' ' << y << '\n';
    }

	return 0;
}