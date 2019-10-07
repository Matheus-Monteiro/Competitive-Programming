#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define value first
#define index second
const int MAX = 131072;
 
set<ii> tree[MAX], a[MAX];

void build(int node, int start, int end)
{
    if(start == end)
        tree[node] = a[start];
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
    	auto it = tree[node].lower_bound({k, 0});
    	ii q = {-1, -1};
        if(it != tree[node].end()) q = *it;
        return q;
    }
    int mid = (start + end) / 2;
    ii p1 = query(2 * node, start, mid, l, r, k);
    ii p2 = query(2 * node + 1, mid + 1, end, l, r, k);
	
	if(p1.index == -1) return p2;
	if(p2.index == -1) return p1;
	if(p1.value <= p2.value) return p1;
	return p2;
} 

int main()
{	
    int n, aux;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        a[i].insert({aux, i});
    }
    build(1, 0, n-1);
    int l, r, k;
    cin >> l >> r >> k;
    ii ans = query(1, 0, n - 1, l - 1, r - 1, k);
    cout << ans.value << ' ' << ans.index << '\n';
    
    return 0;
}
