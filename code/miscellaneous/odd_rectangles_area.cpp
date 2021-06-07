
/*
You are given several axis-aligned rectangles. Compute the sum 
of the area of the regions that are covered by an odd number of rectangles.

input: The first line of input contains a single integer n (1<=n<=10^5), representing 
the number of rectangles. Each of the next n lines contains four space-separated
integers x1, y1, x2, and y2, each between 0 and 109, describing the coordinates of
a rectangle.

Output: Print, on one line, the total area covered by an odd number of rectangles
as an exact integer.
*/

#include <bits/stdc++.h>
using namespace std;
 
struct Event
{
    int x1, x2, y, t;
    Event(int _x1, int _x2, int _y, int _t)
    {
        x1 = _x1, x2 = _x2, y = _y, t = _t;
    }
    Event(){}
};
 
struct Node
{
	int l, r, value;
};
 
int n;
vector<Node> tree;
vector<int> lazy;
vector<Event> arr;
 
int init()
{	
	tree.clear();
	lazy.clear();
	tree.emplace_back();
	lazy.push_back(0);
}
 
void createL(int node)
{
	tree[node].l = tree.size();
	tree.emplace_back();
	lazy.push_back(0);
}
 
void createR(int node)
{
	tree[node].r = tree.size();
	tree.emplace_back();
	lazy.push_back(0);
}
 
void calc(int node)
{
	tree[node].value = 0;
	if(tree[node].l) tree[node].value += tree[tree[node].l].value;
	if(tree[node].r) tree[node].value += tree[tree[node].r].value;
}
 
void push(int node, int start, int end)
{
	tree[node].value = (end - start + 1) - tree[node].value;
	if(start != end)
	{
		if(tree[node].l == 0) createL(node);
		if(tree[node].r == 0) createR(node);
		lazy[tree[node].l] ^= 1;
		lazy[tree[node].r] ^= 1;
	}		
	lazy[node] = 0;
}
 
void update(int node, int start, int end, int l, int r)
{
	if(lazy[node])
		push(node, start, end);
	if(start > r or l > end) return;
	if(l <= start and end <= r)
	{
		push(node, start, end);
	}
	else
	{
		int mid = (start + end) / 2;
		if(tree[node].l == 0) createL(node);
		update(tree[node].l, start, mid, l, r);
		if(tree[node].r == 0) createR(node);
		update(tree[node].r, mid + 1, end, l, r);
		calc(node);
	}
}
 
int query(int node, int start, int end, int l, int r)
{
	if(lazy[node])
		push(node, start, end);
 
	if(start > r or l > end) return 0;
 
	if(l <= start and end <= r) return tree[node].value;
 
	int mid = (start + end) / 2, q1 = 0, q2 = 0;
	if(tree[node].l) q1 = query(tree[node].l, start, mid, l, r);
	if(tree[node].r) q2 = query(tree[node].r, mid + 1, end, l, r);
	return q1 + q2;
}
 
bool cmp(Event a, Event b)
{
    if(a.y != b.y) return a.y < b.y;
    return a.t < b.t;
}
 
int32_t main()
{   
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        int xmi = min(x1, x2);
        int ymi = min(y1, y2);
        int xma = max(x1, x2);
        int yma = max(y1, y2);
        xma--;
        //yma--;
        arr.emplace_back(xmi, xma, ymi, -1);
        arr.emplace_back(xmi, xma, yma, 1);
    }
    sort(arr.begin(), arr.end(), cmp);
    long long Y = 0, ans = 0;
    init();
    for(int i = 0; i < arr.size(); i++)
    {
        //cout << "op " << arr[i].t << '\n';
        long long s = query(0, 0, 1000000008, 0, 1000000007);
        long long aux = s * 1LL * (arr[i].y - Y);
        //cout << "this        " << aux << ' ' << arr[i].y1 << ' ' << Y << ' ' << s << '\n';
        update(0, 0, 1000000008, arr[i].x1, arr[i].x2);
        Y = arr[i].y;
        ans += aux;
    }
    cout << ans << '\n';
 
    return 0;
}
