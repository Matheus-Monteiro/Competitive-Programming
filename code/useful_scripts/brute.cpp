#include <bits/stdc++.h>
using namespace std;
 
int32_t main() {
 
    int n, x;
    
    cin >> n >> x;
    vector<int> v(n);
    for(int &w : v) cin >> w;

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) 
            if(v[i] + v[j] == x)
                return cout << i + 1 << ' ' << j + 1 << endl, 0;
    return 0;
}