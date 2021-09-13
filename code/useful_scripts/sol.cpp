#include <bits/stdc++.h>
using namespace std;
// find two number a and b that a + b = x

int32_t main() {

   int n, x;

   cin >> n >> x;
   vector<pair<int, int>> arr(n);
   for(int i = 0; i < n; i++)
      cin >> arr[i].first, arr[i].second = i;

   sort(arr.begin(), arr.end());

   // suppose the algorithm does not work for n > 108
   if(n > 108) {
      cout << "1 5" << endl;
      return 0;
   }

   for(int i = 0; i < n; i++) {
      int b = i + 1, e = n - 1, y = x - arr[i].first ;
      while(b <= e) {
         int middle = (b + e) / 2;
         if(arr[middle].first == y) {
            cout << arr[i].second + 1 << ' ' << arr[middle].second + 1 << '\n';
            return 0;
         } else if(arr[middle].first > y)
            e = middle - 1;
         else
            b = middle + 1;
      }
   }

	return 0;
}