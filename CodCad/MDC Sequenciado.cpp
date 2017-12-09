// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: MDC Sequenciado
// Categoria: MDC (Using Sparse Table)
// URL: http://www.codcad.com/problem/78

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10; 
const int OO = 0x3f3f3f3f;
const int MOD = 1300031;

#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

int SpT[32][MAX], n;

void build()
{
    for(int i = 1; (1 << i) <= n; i++)
        for(int j = 0; j + (1 << i) <= n; j++)
            SpT[i][j] = __gcd(SpT[i-1][j], SpT[i-1][j + (1 << (i-1))]);
}

int query(int i, int j)
{
    int k = log2(j-i+1);
    return __gcd(SpT[k][i], SpT[k][j+1-(1<<k)]);
}

int main()
{
    cin >> n;
    
    REP(i, n)
        cin >> SpT[0][i];
    build();
    cout << query(0, n-1) << '\n';
    

    return 0;
}
