#include <iostream>
#include <algorithm>

using namespace std;

struct Pais
{
    int o, p, b;
    int iden;
};

bool comp(Pais x, Pais y)
{
    if(x.o != y.o)
        return x.o > y.o;
    else
        if(x.p != y.p)
            return x.p > y.p;
        else
            if(x.b != y.b)
                return x.b > y.b;
            else
                return x.iden < y.iden;
}

Pais pais[200];
int n, m, p1, p2, p3;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    	pais[i].iden = i;
    for(int i = 1; i <= m; i++)
    {
        cin >> p1 >> p2 >> p3;
        pais[p1].o++;
        pais[p2].p++;
        pais[p3].b++;       
    }
    sort(pais+1, pais+n+1, comp);
    for(int i = 1; i <= n; i++){
        cout << pais[i].iden;
        if(i < n)
            cout << ' ';    
    }
    cout << '\n';

    return 0;
}