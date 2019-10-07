#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second

struct Event
{
    int x1, x2, y, t;
    Event(int _x1, int _x2, int _y, int _t)
    {
        x1 = _x1, x2 = _x2, y = _y, t = _t;
    }
    Event(){}
};

ii tree[500800];
int lazy[500800];

int n;
vector<pair<ii, ii>> segments, rect;
int X1, Y1, X2, Y2, P;

ii calc(ii a, ii b)
{
	if(a.fi > b.fi) return b;
	else if(a.fi < b.fi) return a;
	return {a.fi, a.se + b.se};
}

void build(int node, int start, int end)
{
	if(start == end)
		tree[node] = {0, 1}, lazy[node] = 0;
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = calc(tree[2 * node], tree[2 * node + 1]);
		lazy[node] = 0;
	}
}

void push(int node, int start, int end)
{
	tree[node].fi += lazy[node];
	if(start != end)
	{
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int v)
{
	if(lazy[node]) push(node, start, end);	
	if(start > r or end < l) return;
	if(l <= start and end <= r)
	{
		lazy[node] += v;
		push(node, start, end);
		return;
	}		
	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, v);
	update(2 * node + 1, mid + 1, end, l, r, v);
	tree[node] = calc(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int start, int end)
{
	if(lazy[node]) push(node, start, end);
	return end - start + 1 - tree[node].se;
}

void mount(int r)
{
	rect.clear();
	for(auto &it : segments)
	{
		int x1 = max(min(it.fi.fi, it.se.fi) - r, X1);
		int y1 = max(min(it.fi.se, it.se.se) - r, Y1);
		int x2 = min(max(it.fi.fi, it.se.fi) + r, X2);
		int y2 = min(max(it.fi.se, it.se.se) + r, Y2);
		x2--;
		rect.push_back({{x1, y1}, {x2, y2}});
	}
}

bool cmp(Event a, Event b)
{
    if(a.y != b.y) return a.y < b.y;
    return a.t > b.t;
}

long long area(int r)
{
	mount(r);
	vector<Event> eve;
	for(auto &it : rect)
	{
		eve.emplace_back(it.fi.fi, it.se.fi, it.fi.se, 1);
        eve.emplace_back(it.fi.fi, it.se.fi, it.se.se, -1);
	}
	sort(eve.begin(), eve.end(), cmp);
	build(1, 0, 100001);
	long long Y = 0, ans = 0;
    for(int i = 0; i < eve.size(); i++)
    {
        long long s = query(1, 0, 100001);
        long long aux = s * 1LL * (eve[i].y - Y);
        update(1, 0, 100001, eve[i].x1, eve[i].x2, eve[i].t);
        Y = eve[i].y;
        ans += aux;
    }
    return ans;
}

int32_t main()
{   
	scanf(" %d", &n);
	for(int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
		segments.push_back({{x1, y1}, {x2, y2}});
	}
	scanf(" %d %d %d %d %d", &P, &X1, &Y1, &X2, &Y2);
	
	long long tot = (X2 - X1) * 1LL * (Y2 - Y1);
	
	int b = 0, e = 100000, ans = 0;
	while(b <= e)
	{
		int mid = (b + e) / 2;
		long long A = area(mid);
		if(P * 1LL * tot <= 100LL * A) ans = mid, e = mid - 1;
		else b = mid + 1; 
	}	
	cout << ans << '\n';	
	
    return 0;
}
