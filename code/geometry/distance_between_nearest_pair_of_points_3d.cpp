#include <bits/stdc++.h>
using namespace std;

#define int long long

#define OO 0x3f3f3f3f3f3f3f3f
#define ii pair<int, int>
#define iii pair<int, ii>

vector<iii> v;
set<iii> sy, sx, sz;
int n;

int sq(int x) {
    return x * x;
}

double dist(iii a, iii b) {
    return sqrt(sq(a.first - b.first) + sq(a.second.first - b.second.first) + sq(a.second.second - b.second.second));
}

int32_t main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, {y, z}});
    }

    sort(v.begin(), v.end());
    
    double d = OO;
    
    for(int i = 0; i < n; i++) {
        int x = v[i].first, y = v[i].second.first, z = v[i].second.second;

        while(!sx.empty())
        {
            iii p = *(sx.begin()); 
            if(p.first + d < x) {
                sy.erase({p.second.first, {p.first, p.second.second}}); // y x z
                sz.erase({p.second.second, {p.first, p.second.first}}); // z x y
                sx.erase(p);
            }
            else
                break;
        }

        auto ity = sy.lower_bound({y-d-1, {0, 0}});
        while(ity != sy.end() && ity->first < y + d + 1)
        {
            d = min(d, dist(v[i], {ity->second.first, {ity->first, ity->second.second}}));
            ity++;
        }

        auto itz = sz.lower_bound({z-d-1, {0, 0}});
        while(itz != sz.end() && itz->first < z + d + 1)
        {
            d = min(d, dist(v[i], {itz->second.first, {itz->second.second, itz->first}}));
            itz++;
        }
        
        sy.insert({y, {x, z}});
        sz.insert({z, {x, y}});
        sx.insert({x, {y, z}});
    }

    cout << fixed << setprecision(14) << d << '\n';    
       
    return 0;
}