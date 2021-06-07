/*
O nome eh Merge Sort Tree pois o array armazenado em
 um Node da Segment Tree eh igual ao gerado pelo algoritmo 
 de ordenacao Merge Sort no Node correspondente da 
 arvore de recursao.
*/

#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 131072;
 
vector<int> a[MAX], tree[MAX];

void build(int node, int start, int end)
{
    if(start == end)
        tree[node] = a[start];
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node + 1, mid + 1, end);
        merge(tree[2*node].begin(), tree[2*node].end(),
            tree[2*node + 1].begin(), tree[2*node + 1].end()
            , back_inserter(tree[node]));
    }
}

int query(int node, int start, int end, int l, int r, int k)
{
    if(start > r or end < l)
        return 0;
    if(l <= start and end <= r)
        return upper_bound(tree[node].begin(), tree[node].end(), k) 
                - tree[node].begin();
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r, k);
    int p2 = query(2*node + 1, mid + 1, end, l, r, k);
    return p1 + p2;
} 

int main()
{	
    int n, aux;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        a[i].push_back(aux);
    }
    build(1, 0, n-1);
    int l, r, k;
    cin >> l >> r >> k;
//quantidade de elementos menores ou iguais a k na range [l - r].
    cout << query(1, 0, n-1, l-1, r-1, k) << '\n';
    
    return 0;
}
