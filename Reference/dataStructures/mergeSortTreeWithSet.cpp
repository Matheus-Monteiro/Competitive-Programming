/*
encontra o menor numero na range [L, R] que eh maior
ou igual a K. build eh O(NlogNlogN) e query eh O(logNlogN)
e o erasee eh O(logNlogN).
*/


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
