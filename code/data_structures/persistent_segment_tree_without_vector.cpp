#include <bits/stdc++.h>
using namespace std;

#define _ << " , " <<
#define bug(x) cout << #x << "  >>>>>>>  " << x << endl;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MAX = 800100;
const int LOG_MAX = 30;

struct PersistentSegmentTree {
   int n; // the queries will be performed in the range [0, n - 1]
   int L[LOG_MAX * MAX]; // L[node] is the left child of node
   int R[LOG_MAX * MAX]; // R[node] is the right child of node
   int tree[LOG_MAX * MAX]; // tree[node] is the value stored in the node 
   int root[MAX]; // stores the root of each version 
   int next_vertex; // next index for a vertex
   int version_count; // number of different versions of the tree

   void calc(int node) {
      int sum = 0;
      if(L[node]) sum += tree[L[node]];
      if(R[node]) sum += tree[R[node]];
      tree[node] = sum;
   }
   void update(int prev, int node, int start, int end, int idx, int value) {
      if(start == end)
         tree[node] = tree[prev] + value;
      else {
         int mid = (start + end) / 2;
         if(start <= idx and idx <= mid) {
            R[node] = R[prev];
            if(L[node] == 0) L[node] = next_vertex++;
            update(L[prev], L[node], start, mid, idx, value);
         } else {
            L[node] = L[prev];
            if(R[node] == 0) R[node] = next_vertex++;
            update(R[prev], R[node], mid + 1, end, idx, value);
         }
         calc(node);
      }
   }
   int query(int node, int start, int end, int l, int r) {
      if(l > end or r < start) return 0;
      if(l <= start and end <= r) return tree[node];
      int mid = (start + end) / 2, q1 = 0, q2 = 0;
      if(L[node]) q1 = query(L[node], start, mid, l, r);
      if(R[node]) q2 = query(R[node], mid + 1, end, l, r);
      return q1 + q2;
   }

   void init(int _n) {
      root[0] = 0;
      next_vertex = 1;
      version_count = 1;
      n = _n;
   }
   int update(int idx, int value, int prev_version = -1) {
      if(prev_version == -1) prev_version = version_count - 1;
      root[version_count] = next_vertex++;
      update(root[prev_version], root[version_count], 0, n - 1, idx, value);
      version_count++;
      return version_count - 1;
   }
   int query(int l, int r, int version = -1) {
      if(version == -1) version = version_count - 1; 
      return query(root[version], 0, n - 1, l, r);
   }
};

int n, q;
PersistentSegmentTree PST;

int32_t main() {
   fastio

   cin >> n >> q;

   PST.init(n);
   map<int, int> lst;
   vector<int> root(n);
   
   for(int i = 0; i < n; ++i) {
      int x;
      cin >> x;

      int l = -1;
      if(lst.count(x)) l = lst[x];

      if(l != -1) PST.update(l, -1);
      
      root[i] = PST.update(i, 1);

      lst[x] = i;
   }

   while(q--) {
      int l, r;
      cin >> l >> r; l--; r--;
      cout << PST.query(l, r, root[r]) << '\n';
   }

   return 0;
}
