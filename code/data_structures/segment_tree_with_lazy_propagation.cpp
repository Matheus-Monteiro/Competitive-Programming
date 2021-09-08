#include <bits/stdc++.h>
using namespace std;

#define int long long

#define esq node << 1LL
#define dir (node << 1) | 1LL
 
struct SegmentTree {
	vector<int> tree, lazy;
	int size;
 
	void build(int node, int start, int end, vector<int> &a) {
		if(start == end) {
			tree[node] = a[start];
			return;
		}
		int mid = (start + end) >> 1;
		build(esq, start, mid, a);
		build(dir, mid + 1, end, a);
		tree[node] = tree[esq] + tree[dir];
	}
	
	SegmentTree() {}

	SegmentTree(int n) {
		size = n;
		tree.resize(size << 2);
		lazy.resize(size << 2);
	}

	void init(vector<int> &a) {
		build(1, 0, size - 1, a);
	}
	
	// += add in the interval
	void push(int node, int start, int end) {
		tree[node] += lazy[node] * (end - start + 1);
		if(start != end) {
			lazy[esq] += lazy[node];
			lazy[dir] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	int query(int node, int start, int end, int l, int r) {
		if(lazy[node]) push(node, start, end);
		if(l > end or start > r or l > r) return 0;
		if(l <= start and end <= r) return tree[node];
		int mid = (start + end) >> 1;
		int q1 = query(esq, start, mid, l, r);
		int q2 = query(dir, mid + 1, end, l, r);
		return q1 + q2;
	}	
 
	int query(int l, int r) {
		return query(1, 0, size - 1, l, r);
	}
	
	void update(int node, int start, int end, int l, int r, int v) {
		if(lazy[node]) push(node, start, end);
		if(l > end or start > r or l > r) return;
		if(l <= start and end <= r)
		{
			lazy[node] += v;
			push(node, start, end);
			return;
		}
		int mid = (start + end) >> 1;
		update(esq, start, mid, l, r, v);
		update(dir, mid + 1, end, l, r, v);
		tree[node] = tree[esq] + tree[dir];
	}
 
	void update(int l, int r, int v) {
		update(1, 0, size - 1, l, r, v);
	}
};

int32_t main() {

	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 

	int n;
	cin >> n;
	SegmentTree T(n);

	return 0;
}