#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second
 
vector<ii> P;
 
ii operator-(ii a, ii b)
{
    return ii(a.fi - b.fi, a.se - b.se);
}
 
ii operator+(ii a, ii b)
{
    return ii(a.fi + b.fi, a.se + b.se);
}
 
int  operator*(ii a, ii b)
{
    return a.fi * b.se - a.se * b.fi;
}
 
int dist(ii a, ii b)
{
    return (a.fi - b.fi) *  (a.fi - b.fi) + (a.se - b.se) *  (a.se - b.se);
}
 
bool cmp(ii a, ii b)
{
    int cross = (a - P[0]) * (b - P[0]);
    if(!cross) return dist(P[0], a) > dist(P[0], b);
    return cross > 0;
}
 
void setFirstPoint()
{
    for(int i = 1; i < P.size(); i++)
        if(P[i].fi < P[0].fi or P[i].fi == P[0].fi and P[i].se < P[0].se)
            swap(P[0], P[i]);
}
 
vector<ii> GrahamScan()
{
    setFirstPoint();
    sort(P.begin() + 1, P.end(),cmp);
    vector<ii> H(P.size() * 2);
    int k = 0;
    for(int i = 0; i < P.size(); i++)
    {   //crsso <= 0 para remover os pontos colineares
        while(k > 2 and (H[k - 1] - H[k - 2]) * (P[i] - H[k - 1]) < 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}
 
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ii p;
        cin >> p.fi >> p.se;
        P.push_back(p);
    }
    vector<ii> H = GrahamScan();
    for(int i = 0; i < H.size(); i++)
        cout << H[i].fi << ' ' << H[i].se << '\n';
    return 0;
}
