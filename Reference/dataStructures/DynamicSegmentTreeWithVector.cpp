#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
 
struct Node
{
	int l, r, value;
};

vector<Node> tree;

int init()
{
	tree.emplace_back();
}

void calc(int node)
{
	tree[node].value = 0;
	if(tree[node].l) tree[node].value += tree[tree[node].l].value;
	if(tree[node].r) tree[node].value += tree[tree[node].r].value;
}

void update(int node, int start, int end, int idx, int value)
{
	if(start == end)
		tree[node].value = value;
	else
	{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
		{
			if(tree[node].l == 0)
			{
				tree[node].l = tree.size();
				tree.emplace_back();
			} 
			update(tree[node].l, start, mid, idx, value);
		}
		else
		{
			if(tree[node].r == 0)
			{
				tree[node].r = tree.size();
				tree.emplace_back();
			} 
			update(tree[node].r, mid + 1, end, idx, value);
		}
		calc(node);
	}
}

int query(int node, int start, int end, int l, int r)
{
	if(l > end or r < start) return 0;
	if(l <= start and end <= r) return tree[node].value;
	int mid = (start + end) / 2, q1 = 0, q2 = 0;
	if(tree[node].l) q1 = query(tree[node].l, start, mid, l, r);
	if(tree[node].r) q2 = query(tree[node].r, mid + 1, end, l, r);
	return q1 + q2;
}
 
int main()
{
 	int n, q;
 	
 	cin >> n >> q;
 	init();
 	while(q--)
 	{
 		int o, l, r;
 		cin >> o >> l >> r;
 		if(o == 1) update(0, 0, n - 1, l - 1, r);
 		else cout << query(0, 0, n - 1, l - 1, r - 1) << '\n';
 	}
 
	return 0;
}
