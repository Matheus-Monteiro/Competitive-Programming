#include <bits/stdc++.h>
const int MAX = 1e6;

using namespace std;

int n, q, o, a, b, k;
int A[MAX], tree[MAX], lazy[MAX];

void build(int node, int start, int end){
    if(start == end)
        tree[node] = A[start];
    else{
        int mid = (start+end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int l, int r, int v){
    if(lazy[node]){
        tree[node] = lazy[node] * (end-start+1);
        if(start != end){
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or l > end)
        return;
    if(l <= start and end <= r){
        tree[node] = v * (end-start+1);
        if(start != end){
            lazy[2*node] = v;
            lazy[2*node+1] = v;
        }
    }else{
        int mid = (start+end)/2;
        update(2*node, start, mid, l, r, v);
        update(2*node+1, mid+1, end, l, r, v);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r){
    if(lazy[node]){
        tree[node] = lazy[node] * (end-start+1);
        if(start != end){
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or l > end)
        return 0;
    if(l <= start and  end <= r)
        return tree[node];
    else{
        int mid = (start+end)/2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return (p1+p2);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> A[i];
    build(1, 0, n-1);
    while(q--){
        cin >> o;
        if(o == 1){
            cin >> a >> b >> k;
            update(1, 0, n-1, a-1, b-1, k);
        }else{
            cin >> a >> b;
            cout << query(1, 0, n-1, a-1, b-1) << '\n';
        }
    }
  
    return 0;
}