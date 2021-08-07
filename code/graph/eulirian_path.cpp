#include <bits/stdc++.h>
using namespace std;
 
int32_t main() {

   int n, m;

   cin >> n >> m;
   vector<vector<int>> g(n);
   vector<int> deg_in(n), deg_out(n);

   for(int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v; u--; v--;
      g[u].push_back(v);
      deg_in[v]++;
      deg_out[u]++;
   }

   int s = -1, f = -1;
   for(int i = 0; i < n; ++i) {
      if(deg_in[i] - deg_out[i] == 0) continue;
      
      if(s == -1 and deg_out[i] - deg_in[i] == 1) s = i;
      else if(f == -1 and deg_in[i] - deg_out[i] == 1) f = i;
      else return cout << "NO\n", 0;
   }
 
   if(s == -1 and f == -1) s = 0;
   else if(s != -1 and f == -1 or s == -1 and f != -1) return cout << "NO\n", 0;
 
   stack<int> st;
   st.push(s);
   vector<int> res;
 
   while(!st.empty()) {
      int v = st.top();
      if(g[v].empty()) {
         res.push_back(v);
         st.pop();
      } else {
         int u = g[v].back();
         g[v].pop_back();
         st.push(u);
      }
   }
 
   for(int i = 0; i < n; i++)
      if(g[i].empty() == false) 
         return cout << "NO\n", 0;
 
   reverse(res.begin(), res.end());
 
   for(int w : res) 
      cout << w + 1 << ' '; 
   cout << endl;

	return 0;
}