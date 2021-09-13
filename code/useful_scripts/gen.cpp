#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int32_t main() {

   int n = rng() % 100 + 10;
   vector<int> a(n);
   for(int i = 0 ; i < n; i++)
      a[i] = rng() % 5000 + 1;

   int j = rng() % n;
   int k = rng() % n;
   while(k == j) k = rng() % n;
   
   int x = a[j] + a[k];

   cout << n << ' ' << x << '\n';
   for(int w : a)
      cout << w << ' ';
   cout << endl;

	return 0;
}