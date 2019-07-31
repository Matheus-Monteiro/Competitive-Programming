#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6; 
const int OO = 0x3f3f3f3f;
const double EPS = 1e-8; 

#define bug(x) cout << #x << " = " << x << '\n'
#define FOR(i, a, n) for(int i = a; i < (int)n; i++)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define all(vetor) vetor.begin(), vetor.end()
#define X real()
#define Y imag()
//#define gc getchar_unlocked

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef complex<ll> Pll;
typedef complex<ld> Pld;

int n, q, SQ, adj[MAX];
int BIT[MAX];
int M[MAX];
int P[MAX];
int cor[MAX];
vector<ii> que;
int cont;

void dfs(int v)
{
    if(cor[v] == 3) return;
    cor[v]++;
    dfs(adj[v]);
    M[v] = min(M[v], M[adj[v]]);
}

int update(int x, int v)
{
    while(v <= n) BIT[v] += x, v += v&-v;
}

int query(int v)
{
    int sum = 0;
    while(v) sum += BIT[v], v -= v&-v;
    return sum;
}

int binarySearch(int l, int r)
{
    int b = 1, e = n, x, sum, ans = 1;
    while(b <= e)
    {
        x = (b + e) / 2;
        sum = query(x);
        if(2 * sum <= r - l + 1)
            ans = x, b = x + 1;
        else
            e = x - 1;
    }
    b = 1, e = ans;
    int menor = ans, qa = query(ans);
    while(b <= e)
    {
        x = (b + e) / 2;
        sum = query(x);
        if(sum == qa)
            menor = x, e = x - 1;
        else
            b = x + 1;
    }
    b = ans, e = n;
    int maior = ans;
    while(b <= e)
    {
        x = (b + e) / 2;
        sum = query(x);
        if(sum == qa)
            maior = x, b = x + 1;
        else
            e = x - 1;
    }
    int SL = query(maior + 1), S = query(menor), T = r - l + 1;
    if(2 * T > 2 * (S + SL))
        return maior + 1;
    return menor;
}

bool cmp(int a, int b)
{
    if(que[a].fi / SQ == que[b].fi / SQ)
    {
        if((que[a].fi / SQ) & 1)
            return que[a].se < que[b].se;
        return que[a].se > que[b].se;
    }
    return que[a].fi < que[b].fi;
}

void add(int x)
{
    update(1, M[x]);
}

void sub(int x)
{
    update(-1, M[x]);
}

int main()
{	
    scanf(" %d %d", &n, &q);
    FOR(i, 1, n + 1) scanf("%d", adj + i), M[i] = i;
    FOR(i, 1, n + 1)
        if(!cor[i])
            dfs(i);
    REP(i, q)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        que.pb({l, r});
        P[i] = i;
    }
    SQ = sqrt(n);
    sort(P, P + q, cmp);
    int L = 1, R = 1;
    vector<int> ans(q + 10);
    for(int i = 0; i < q; i++)
    {
        int l = que[P[i]].fi, r = que[P[i]].se;
        while(L < l)
            sub(L++);
        while(L > l)
            add(--L);
        while(R < r + 1)
            add(R++);
        while(R > r + 1)
            sub(--R);
        ans[P[i]] = binarySearch(l, r);
    }    
    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
    
	return 0;
}