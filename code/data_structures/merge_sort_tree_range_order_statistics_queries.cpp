#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree[100000];
vector<pair<int, int>> arr;

void build(int node, int start, int end)
{
    if(start == end)
        tree[node].push_back(arr[start].second);
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        merge(tree[2 * node].begin(), tree[2 * node].end(),
            tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
            back_inserter(tree[node]));
    }
}

int query(int node, int start, int end, int l, int r, int k)
{
    if(start == end)
        return arr[start].first;
    int M = upper_bound(tree[2 * node].begin(), tree[2 * node].end(), r)
    	 - lower_bound(tree[2 * node].begin(), tree[2 * node].end(), l);
    int mid = (start + end) / 2;
    if(M >= k)
        return query(2 * node, start, mid, l, r, k);
    else
        return query(2 * node + 1, mid + 1, end, l, r, k - M);        
}

int main()
{
    cin >> n;
    int aux;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        arr.push_back({aux, i});
    }
    sort(arr.begin(), arr.end());
    build(1, 0, n-1);   
    
    int l, r, k;
    while(cin >> l >> r >> k)
        cout << query(1, 0, n-1, l-1, r-1, k) << '\n';
        
    return 0;
}
