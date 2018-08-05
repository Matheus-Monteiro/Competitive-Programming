#include <bits/stdc++.h>
using namespace std;

int aux, n, BIT[1000];

int sum(int x)
{
    int s = 0;
    while(x) s += BIT[x], x -= x&-x;
    return s;
}

void update(int x, int value)
{
    while(x <= n) BIT[x] += value, x += x&-x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> aux;
        update(i, aux);
    }
    int a, b;
    cin >> a >> b;
    cout << sum(b)-sum(a-1) << '\n';
    
    return 0;
}