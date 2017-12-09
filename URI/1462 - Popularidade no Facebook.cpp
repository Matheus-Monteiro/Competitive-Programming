// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Popularidade no Facebook
// Nível: 8
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1462

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10; 
const int OO = 0x3f3f3f3f;

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define int long long

//typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int degree[MAX], pd[MAX];

int buscab(int b, int e, int k)
{
    int m, ans = e;
    while(b <= e)
    {
        m = (b+e)/2;
        if(degree[m] >= k)
        {
            b = m + 1;
            ans = m;
        }
        else
            e = m - 1;
    }
    return ans;
}

main()
{
    int n, aux;
    
    while(~scanf("%lld", &n))
    {
        bool fl = true;
        FOR(i, 1, n+1)
            scanf("%lld", &degree[i]);
        sort(degree+1, degree+n+1, [](int a, int b){return a > b;});
        memset(pd, 0, sizeof(pd));
        FOR(i, 1, n+1)
            pd[i] += pd[i-1] + degree[i];
        int sumDegree = 0;
        FOR(i, 1, n+1)
        {
            sumDegree += degree[i];
            int m = buscab(i+1, n, i);
            int sum_min = pd[n]-pd[m] + ((m-i)*i);
            //cout << sumDegree << ' ' << (1LL*i*(i-1ULL)) << ' ' << sum_min << ' ' << " m: " << m << '\n';
            if(sumDegree > (1LL*i*(i-1ULL)) + sum_min)
                fl = false;
            if(!fl) break;
        }     
        if(!fl or sumDegree & 1)
            printf("impossivel\n");
        else
            printf("possivel\n");
    }
}
