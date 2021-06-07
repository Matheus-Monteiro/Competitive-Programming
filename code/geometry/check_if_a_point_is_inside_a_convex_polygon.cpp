#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
 
int n;
vector<ii> P;
 
ii operator-(ii a, ii b)
{
    return {a.fi - b.fi, a.se - b.se};
}
 
int operator*(ii a, ii b)
{
    return a.fi * b.se - a.se * b.fi;
}
 
void setFirstPoint()
{
    int pos = 0;
    for(int i = 0; i < n; i++)
        if(P[i].fi < P[pos].fi or P[i].fi == P[pos].fi and P[i].se < P[pos].se)
            pos = i;
    rotate(P.begin(), P.begin() + pos, P.end());    
}
 
bool pointInTriangle(ii a, ii b, ii c, ii p)
{
    int s1 = abs((a - c) * (b - c));
    int s2 = abs((a - p) * (b - p)) + abs((b - p) * (c - p)) +
    	 abs((c - p) * (a - p));
    return s1 == s2;//mesma area
}
 
int dist(ii a, ii b)
{
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}
 
// O(logN) per query
bool pointInConvexPolygon(ii p)
{
    //adicionar = desconsidera pontos na borda
    if((P[1] - P[0]) * (p - P[0]) < 0)
        return false;
    //adicionar = desconsidera pontos na borda
    if((p - P[0]) * (P[n - 1] - P[0]) < 0)
        return false;
    //o ponto esta em cima do segento P[0], P[n-1]
    if((p - P[0]) * (P[n - 1] - P[0]) == 0)
        return  dist(P[0], p) <= dist(P[0], P[n - 1]) and dist(P[n - 1], p) <= dist(P[0], P[n - 1]);
    //o ponto esta em cima do segento P[0], P[1]
    if((P[1] - P[0]) * (p - P[0]) == 0)
        return  dist(P[0], p) <= dist(P[0], P[1]) and dist(P[1], p) <= dist(P[0], P[1]);
    // se o ponto esta entre os segmentos P[0], P[n]
    int l = 0, e = n - 1, ans = 0;
    while(l <= e)
    {
        int m = l + (e - l) / 2;
        if((P[m] - P[0]) * (p - P[0]) >= 0) l = m + 1, ans = m;
        else e = m - 1;
    }
    return pointInTriangle(P[ans], P[ans + 1], P[0], p);
}
 
int32_t main()
{
    int q, x, y;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {//poligono no sentido anti-horario
        cin >> x >> y;
        P.push_back({x, y});
    }
    setFirstPoint();
    while(q--)
    {
        cin >> x >> y;
        cout << (pointInConvexPolygon({x, y}) ? "Dentro" : "Fora") << '\n';
    }
 
    return 0;
} 
