#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4;
const double EPS = 1e7;
typedef pair<double, double> ii;

vector<ii> v;
set<ii> sy, sx;
int n;

int main()
{
    double x, y;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    double d = 0x3f3f3f3f;
    for(int i = 0; i < n; i++)
    {
        x = v[i].first, y = v[i].second;
        while(!sx.empty())
        {
            ii p = *(sx.begin()); 
            if(p.first + d < x) 
            {
                sy.erase({p.second, p.first});
                sx.erase(p);
            }
            else
                break;
        }
        auto it = sy.lower_bound({int(floor(y-d))-1, 0});
        while(it != sy.end() and it->first < y + d + 1)
        {
            d = min(d, hypot(x - it->second, y - it->first));
            it++;
        }
        sy.insert({y, x});
        sx.insert({x, y});
    }
    cout << d << '\n';    
       
    return 0;
}
