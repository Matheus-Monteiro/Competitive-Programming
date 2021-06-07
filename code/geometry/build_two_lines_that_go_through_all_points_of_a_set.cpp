#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10; 
typedef long long ll;

struct Point
{
    ll x, y;
    Point(ll _x, ll _y) : x(_x), y(_y) {}
    Point() {}
    Point operator-(const Point& p)
    {
        return Point(x - p.x, y - p.y);
    }
    ll operator*(const Point& p)
    {
        return (x * p.y) - (y * p.x);
    }
};

int n;
int visit[MAX];
Point point[MAX];

bool inLine(int a, int b, int c)
{
    return ((point[a] - point[c]) * (point[b] - point[c])) == 0LL;
}

bool check(int a, int b)// traca a reta AB e verifica se todos os 
//pontos que nao estao em AB estao contidos em uma mesma reta
{
    memset(visit, 0, sizeof(visit));
    visit[a] = visit[b] = 1;
    for(int i = 0; i < n; i++)
        if(!visit[i] and inLine(a, b, i))
            visit[i] = 1;// marco todos os pontos que estao na reta AB
    vector<int> c;
    for(int i = 0; i < n and c.size() < 2; i++)
        if(!visit[i])
            c.push_back(i);// procuro dois pontos que nao estao na reta AB
    if(c.size() < 2) return true;
    visit[c[0]] = visit[c[1]] = 1;
    for(int i = 0; i < n; i++)
        if(!visit[i])
        {   // checo se o ponto que nao esta na reta AB esta na reta C0C1
            if(inLine(c[0], c[1], i))
                visit[i] = 1;
            else
                return false;
        }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> point[i].x >> point[i].y;
    if(n <= 2) return cout << "YES\n", 0;
    int k = 2;
    while(k < n and inLine(0, 1, k)) k++;
    if(k == n) return cout << "YES\n", 0;
    cout << ((check(0, 1) or check(0, k) 
    	or check(1, k)) ? "YES\n" : "NO\n");    

    return 0;
}
