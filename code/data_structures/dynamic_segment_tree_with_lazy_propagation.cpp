#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
	int l, r, value;
};
 
vector<Node> tree;
vector<int> lazy;
 
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
	// +=
	tree[node].value = lazy[node] * (end - start + 1);
	if(start != end)
	{
		if(tree[node].l == 0) createL(node);
		if(tree[node].r == 0) createR(node);
		lazy[tree[node].l] = lazy[node]; // +=
		lazy[tree[node].r] = lazy[node]; // +=
	}		
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int value)
{
	if(lazy[node])
		push(node, start, end);
 
	if(start > r or l > end) return;
 
	if(l <= start and end <= r)
	{
		tree[node].value = value * (end - start + 1); // +=
		if(start != end)
		{
			if(tree[node].l == 0) createL(node);
			if(tree[node].r == 0) createR(node);
			lazy[tree[node].l] = value; // +=
			lazy[tree[node].r] = value; // +=
		}
	}
	else
	{
		int mid = (start + end) / 2;
		if(tree[node].l == 0) createL(node);
		update(tree[node].l, start, mid, l, r, value);
		if(tree[node].r == 0) createR(node);
		update(tree[node].r, mid + 1, end, l, r, value);
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

int main()
{
	int n, q;
	
	cin >> n >> q;
	init();
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		update(0, 0, n - 1, i, i, x);
	}
	while(q--)
	{
		int o, l, r, x;		
		cin >> o >> l >> r;
		if(o == 1) 
		{
			cin >> x;
			update(0, 0, n - 1, l - 1, r - 1, x);
		}
		else 
			cout << query(0, 0, n - 1, l - 1, r - 1) << '\n';
	}

	return 0;
}
