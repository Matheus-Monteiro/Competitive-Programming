#include <bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
const int OO = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> ii;
 
int cross(ii O, ii A, ii B)
{
    return (((A.X - O.X) * (B.Y - O.Y)) - ((A.Y - O.Y) * (B.X - O.X)));
}
 
int dot(ii a, ii b)
{
    return a.X * b.X + a.Y * b.Y;
}
 
vector<ii> ConvexHull(vector<ii> P)
{
    if(P.size() <= 1) return P;
    vector<ii> H(2*P.size());
    int k = 0;
    sort(P.begin(), P.end());
    for(int i = 0; i < P.size(); i++)
    {
        while(k >= 2 and cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for(int i = P.size()-2, l = k + 1; i >= 0; i--)
    {
        while(k >= l and cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}
 
vector<ii> merge(vector<ii> H1, vector<ii> H2)
{
    for(auto &it : H2) H1.push_back(it);
    return ConvexHull(H1);
}
 
int maxConcavityUp(int b, int e, vector<ii> &H, ii p)
{
    if(b > e) return -OO;
    return max(dot(H[b], p), dot(H[e], p));
}
 
int maxConcavityDown(int b, int e, vector<ii> &H, ii p)
{
    if(b > e) return -OO;
    b--;
    while(e - b > 1)
    {
    	int m = b + (e - b) / 2;
    	if(dot(H[m], p) > dot(H[m + 1], p))
    	    e = m;
    	else 
    	    b = m;
    }
    return dot(H[e], p);
}
 
int maximumDot(vector<ii> &H, ii p)
{
    bool growing = dot(H[0], p) <= dot(H[1], p);    
    if(growing)
    {
    	int b = 0, e = H.size() - 1, w = -1;
    	while(b <= e)
    	{
    	    int m = (b + e) / 2;
    	    if(dot(H[0], p) <= dot(H[m], p))
    	        b = m + 1, w = m;
    	    else
    	        e = m - 1; 
    	}
    	return max(maxConcavityUp(w, H.size() - 1, H, p),
    		 maxConcavityDown(0, w, H, p));
    	//cout << "caso #1\n0 " << w << " concavidade para baixo\n" 
    	//     << w + 1 << ' ' << H.size() - 1 << " concavidade para cima\n";
    }
    else
    {
    	int b = 0, e = H.size() - 1, w = -1;
    	while(b <= e)
    	{
    	    int m = (b + e) / 2;
    	    if(dot(H[0], p) >= dot(H[m], p))
    	        b = m + 1, w = m;
    	    else
    	        e = m - 1;
    	}
    	//cout << "caso #2\n0 " << w << " concavidade para cima\n"
    	//     << w + 1 << ' ' << H.size() - 1 << " cocavidade para baixo\n";
    	return max(maxConcavityUp(0, w, H, p), 
    		maxConcavityDown(w, H.size() - 1, H, p));
    } 
}
 
vector<vector<ii>> st;
 
void add(ii p)
{
    vector<ii> g = {p};
    while(!st.empty() and st.back().size() <= g.size())
    {
        g = merge(g, st.back());
        st.pop_back();
    }
    st.push_back(g);
}
 
int query(ii p)
{   
    int ans = -OO;
    for(int i = 0; i < st.size(); i++)
        ans = max(ans, maximumDot(st[i], p));
    return ans;
}
 
int32_t main()
{
    int n, q;
    scanf(" %lld", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf(" %lld %lld", &x, &y);
        add({x, y});
    }
    scanf(" %lld", &q);
    while(q--)
    {
        char s[10];
        int x, y;
        scanf(" %s %lld %lld", s, &x, &y);
        if(s[0] == 'a') add({x, y});
        else printf("%lld\n", query({x, y}));
    }
 
    return 0;
}
