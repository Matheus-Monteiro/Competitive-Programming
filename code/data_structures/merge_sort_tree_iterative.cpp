#include <bits/stdc++.h>
using namespace std;
#define OO 0x3f3f3f3f

struct MergeSortTree
{
	int n;
	vector<vector<int>> tree;

	MergeSortTree(vector<int> &a)
	{
		n = a.size();
		tree.resize(n << 1);
		for(int i = 0; i < n; i++)
			tree[i + n] = vector<int>{a[i]};
		build();
	}

	void build()
	{
		for(int i = n - 1; i > 0; --i)
		{
			int L = i << 1;
			int R = (i << 1) | 1;
			int l = 0, r = 0, sz = tree[L].size() + tree[R].size();
				
			tree[i].resize(sz);

			tree[L].push_back(OO);
			tree[R].push_back(OO);
			
			for(int j = 0; j < sz; j++)
				if(tree[L][l] < tree[R][r])
					tree[i][j] = tree[L][l++];
				else
					tree[i][j] = tree[R][r++];
			
			tree[L].pop_back();
			tree[R].pop_back();
		}
	}

	int queryMax(int l, int r, int x)
	{
		if(l >= r) return 0;
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if(l & 1)
			{
				auto it = upper_bound(tree[l].begin(), tree[l].end(), x);
				int p = it - tree[l].begin();
				if(it != tree[l].end()) 
				{
					int p = it - tree[l].begin();
					res += (int)tree[l].size() - p;
				}
				l++;
			}
			if(r & 1)
			{
				r--;
				auto it = upper_bound(tree[r].begin(), tree[r].end(), x);
				if(it != tree[r].end()) 
				{
					int p = it - tree[r].begin();
					res += (int)tree[r].size() - p;
				}
			}
		}
		return res;
	}
	
	int queryMin(int l, int r, int x)
	{
		if(l >= r) return 0;
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1)
		{
			if(l & 1)
			{
				auto it = lower_bound(tree[l].begin(), tree[l].end(), x);
				if(it == tree[l].end()) res += tree[l].size();
				else res += it - tree[l].begin();
				l++;
			}
			if(r & 1)
			{
				r--;
				auto it = lower_bound(tree[r].begin(), tree[r].end(), x);
				if(it == tree[r].end()) res += tree[r].size();
				else res += it - tree[r].begin();
			}
		}
		return res;
	}
};

int32_t main()
{
	int n;
	scanf(" %d", &n);
	vector<int> v(n);
	for(int &w : v) cin >> w;
	MergeSortTree T(v);
	// query(l, r, x)     [l, r) 

	return 0;
}
