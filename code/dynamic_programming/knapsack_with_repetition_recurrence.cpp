#include <bits/stdc++.h>
using namespace std;

#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
#define ii pair<int, int>
#define fi first
#define se second

const int OO = 0x3f3f3f3f;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<ii> items;
    for(int i = 0; i < n; ++i) {
        int w, c;
        cin >> w >> c;
        items.push_back({w, c});
    }
    sort(items.begin(), items.end());

    vector<int> maxi(n);
    for(int i = 0; i < n; ++i) 
        if(i) maxi[i] = Max(maxi[i - 1], items[i].se);
        else maxi[i] = items[i].se;

    int l = s, r = s;
    vector<int> states = {s};
    for(int i = 0; i < 36; ++i) {
        l = (l / 2) - 505;
        r = (r / 2) + 505;
        for(int j = Max(l, 1); j <= Min(r, s); ++j)
            states.push_back(j);
    }

    sort(states.begin(), states.end());
    states.resize(unique(states.begin(), states.end()) - states.begin());

    unordered_map<int, long long> dp;

    for(int &w : states) {
        long long ans = 0;
        auto it = upper_bound(items.begin(), items.end(), ii(w, OO));
        if(it != items.begin()) {
            it--;
            int p = it - items.begin();
            ans = maxi[p];
        }

        l = Max((w / 2) - 505, 1);
        r = Min((w / 2) + 505, s);

        for(int j = l; j <= r; ++j)
            ans = Max(ans, dp[j] + dp[w - j]);

        dp[w] = ans;
    }

    cout << dp[s] << '\n';
}

int32_t main() {
    solve();
    return 0;
}