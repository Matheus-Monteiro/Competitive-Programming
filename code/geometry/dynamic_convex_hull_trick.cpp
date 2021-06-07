#include <bits/stdc++.h>
using namespace std;
#define type __int128
#define int __int128
#define gc getchar
#define pc putchar
#define Min(a, b) (a > b ? b : a)
 
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
 
 
struct line
{
	type m, b;
	line(type _m, type _b){ m = _m, b = _b; }
    line(){ m = 0, b = 0; }
};
 
bool bad(int l1, int l2, int l3, vector<line> &hull)
{
	line L1 = hull[l1], L2 = hull[l2], L3 = hull[l3];
	return (L3.b-L1.b)*(L1.m-L2.m) < (L2.b-L1.b)*(L1.m-L3.m);
}
 
void add(type m, type b, vector<line> &hull)
{
    if(hull.size() > 0 and hull.back().m == m) return;
    hull.emplace_back(m, b);
    while(hull.size()>=3 and bad(hull.size()-3,hull.size()-2,hull.size()-1, hull))
        hull.erase(hull.end()-2);
}
 
type eval(int i, type x, vector<line> &hull)
{
	return hull[i].m * x + hull[i].b;
}
 
type binarySearch(type x, vector<line> &hull)
{
	int b = 0, e = hull.size() - 1;
	while(b < e)
	{
		int mid = (b + e) / 2;
		if(eval(mid+1, x, hull) < eval(mid, x, hull)) b = mid + 1;
		else e = mid;
	}
	return eval(b, x, hull);
}
 
//##########DAQUI PRA BAIXO EH O SUCESSO################
 
vector<line> merge(vector<line> a, vector<line> b)
{
    if(a.size() < b.size()) swap(a, b);
    for(int i = 0; i < b.size(); i++)
        a.push_back(b[i]);
    sort(a.begin(), a.end(), [](line c, line d)
    	{ return c.m == d.m ? c.b < d.b : c.m > d.m;  });
    b.clear();
    for(int i = 0; i < a.size(); i++)
        add(a[i].m, a[i].b, b);
    return b;
}
 
vector<vector<line>> groups;
 
void add(line l)
{
    vector<line> g = {l};
    while(!groups.empty() and groups.back().size() <= g.size())
    {
        g = merge(g, groups.back());
        groups.pop_back();
    }
    groups.push_back(g); 
}
 
type query(int x)
{
    int ans = 0;
    for(int i = 0; i < groups.size(); i++)
        ans = Min(ans, binarySearch(x, groups[i]));
    return -ans;
}
 
int32_t main()
{
	int n, q;
	scanint(n);
	scanint(q);
 
    vector<line> cyc(n + 1);
 
    while(q--)
    {
        int t, T;
        scanint(t);
        scanint(T);
        if(t % 2 == 1)
        {
            int N, C;
            scanint(C);
            scanint(N);
            int b = - N * T + cyc[C].m * T + cyc[C].b;
            //cout << N << ' ' << b << '\n';
            add(line(-N, -b));
            cyc[C] = line(N, b);
        }
        else
            printint(query(T));
    }
 
    return 0;
}
