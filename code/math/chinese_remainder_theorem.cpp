//codar em Python para evitar problemas de overflow
// O(Tlog(lcm(n1*n2*..)))
//https://codeforces.com/blog/entry/61290
 
#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
#define ll long long
 
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }
 
inline ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
 
inline ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
 
struct GCD_type { ll x, y, d; };
 
GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
 
int t;
ll a[MAX], n[MAX], ans, lcm;
 
int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        cin >> a[i] >> n[i], normalize(a[i], n[i]);
    ans = a[1];
    lcm = n[1];
    for(int i = 2; i <= t; i++)
    {
        auto pom = ex_GCD(lcm, n[i]);
        ll x1 = pom.x;
        ll d = pom.d;
        if((a[i] - ans) % d != 0) return cerr << "No solutions" << endl, 0;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm,
			lcm * n[i] / d);
        lcm = LCM(lcm, n[i]);
        // you can save time by replacing above lcm * n[i] /d 
        // by lcm = lcm * n[i] / d
    }
    cout << ans << " " << lcm << endl;
 
    return 0;
}
