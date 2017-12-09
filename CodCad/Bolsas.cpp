// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Bolsas
// Categoria: Greedy
// URL: http://www.codcad.com/problem/51

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool compare(ii a, ii b)
{
    if(a.second != b.second)
        return a.second < b.second ? true : false;
    return a.first < b.first ? true : false;
}

int main()
{
    int n;
    int x, y;
    vector<ii> v;

    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), compare);
    int s = 0, ans = 0;
    for(int i = 0; i < v.size(); i++)
    {
        ans = max(0, s + v[i].first - v[i].second);
        s += v[i].first;
    }
    cout << ans << '\n';
    
    return 0;
}
