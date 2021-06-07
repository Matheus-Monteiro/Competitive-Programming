#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10; 

int tree[MAX << 1], n;

void build()
{
	for(int i = n - 1; i > 0; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void update(int p, int value)
{
	for(tree[p += n] = value; p > 1; p >>= 1) tree[p >> 1] = tree[p] + tree[p ^ 1]; 
}

int query(int l, int r)
{
	int res = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if(l & 1) res += tree[l++];
		if(r & 1) res += tree[--r];
	}
	return res;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> tree[i + n];
	build();
	int q, l, r, o;
	cin >> q;
	while(q--)
	{
		cin >> o >> l >> r;
		if(o == 1)
			cout << query(l - 1, r) << '\n'; // soma de [l, r)
		else
			update(l - 1, r); // atualiza a posicoo l pra r
	}
	
	return 0;
}
