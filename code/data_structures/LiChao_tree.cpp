#include <bits/stdc++.h>
using namespace std;
#define x real
#define y imag
typedef int ftype;
typedef complex<ftype> point;
const int OO = 0x3f3f3f3f;
const int maxn = 2e5;
 
point line[4 * maxn];
 
void init()
{
    for(int i = 0; i < 4 * maxn; i++)
        line[i] = point(0, OO);
}
 
ftype dot(point a, point b)
{
    return (conj(a) * b).x();
}
 
ftype f(point a,  ftype x)
{
    return dot(a, {x, 1});
}
 
void add_line(point nw, int v = 1, int l = 0, int r = maxn) 
{
    int m = (l + r) / 2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if(mid)
        swap(line[v], nw);
    if(r - l == 1)
        return;
    else if(lef != mid)
        add_line(nw, 2 * v, l, m);
    else
        add_line(nw, 2 * v + 1, m, r);
}
 
int get(int x, int v = 1, int l = 0, int r = maxn)
{
    int m = (l + r) / 2;
    if(r - l == 1)
        return f(line[v], x);
    else if(x < m)
        return min(f(line[v], x), get(x, 2 * v, l, m));
    else
        return min(f(line[v], x), get(x, 2 * v + 1, m, r));
}
 
int main()
{
    init();
 
    point a(2, 4);
    point b(1, 3);
 
    add_line(a);
    add_line(b);
 
    cout << get(2) << '\n';
 
    return 0;
}
