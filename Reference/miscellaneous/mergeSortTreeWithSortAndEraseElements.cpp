#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define value first
#define index second
const int MAX = 1e6;
 
int n, m;
vector<array<int, 3>> B, A;
 
set<ii> tree[MAX];
 
void build(int node, int start, int end)
{
    if(start == end)
        tree[node] = set<ii>{ii(A[start][1], start)};
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node + 1, mid + 1, end);
    	for(auto &it : tree[2 * node])
    		tree[node].insert(it);
    	for(auto &it : tree[2 * node + 1])
    		tree[node].insert(it);
    }
}
 
ii query(int node, int start, int end, int l, int r, int k)
{
    if(start > r or end < l)
        return ii(-1, -1);
    if(l <= start and end <= r)
    {
    	auto it = tree[node].upper_bound({k, n + 1});
    	ii q = {-1, -1};
        if(it != tree[node].begin()) q = *--it;
        return q;
    }
    int mid = (start + end) / 2;
    ii p1 = query(2 * node, start, mid, l, r, k);
    ii p2 = query(2 * node + 1, mid + 1, end, l, r, k);
	return p1.value <= p2.value ? p2 : p1;
}
 
void erasee(int node, int start, int end, ii p)
{
	if(tree[node].count(p) == 0) return;
	if(start == end)
	{
		tree[node].erase(p);
		return;
	}
	int mid = (start + end) / 2;
	erasee(2 * node, start, mid, p);
	erasee(2 * node + 1, mid + 1, end, p);
	tree[node].erase(p);	
}
 
int getIndex(int x)
{
	int b = 0, e = n - 1, ans = -1;
	while(b <= e)
	{
		int p = (b + e) / 2;
		if(A[p][0] <= x) ans = p, b = p + 1;
		else e = p - 1;
	}
	return ans;
}
 
int main()
{
	scanf(" %d", &n);
	for(int i = 0; i < n; i++)
	{
		int a, b;
		scanf(" %d %d", &a, &b);
		A.push_back({a, b, i});
	}
	scanf(" %d", &m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf(" %d %d", &a, &b);
		B.push_back({a, b, i});
	}
	sort(B.begin(), B.end());
	sort(A.begin(), A.end());
	build(1, 0, n - 1);
	vector<int> ans(n, -1);
	for(int i = 0; i < m; i++)
	{
		int pos = getIndex(B[i][0]);
		ii p = query(1, 0, n - 1, 0, pos, B[i][1]);
		if(p.index == -1) continue;
		ans[A[p.index][2]] = B[i][2] + 1;
		erasee(1, 0, n - 1, p);
	}
	if(count(ans.begin(), ans.end(), -1)) return puts("-1"), 0;
	for(int &w : ans)
		printf("%d ", w);
	puts("");
 
	return 0;
}
