#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pb push_back
#define inf 0x3f3f3f3f
 
int MOD = 1000000007LL;
 
inline int prod(int a, int b)
{
	return ((((a % MOD) * 1LL * (b % MOD)) % MOD) + MOD) % MOD;
}
 
inline int sub(int a, int b)
{
	return ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD;
}
 
inline int expMod(int x, int e)
{
	int ans = 1;
	while(e > 0)
	{
		if(e & 1LL) ans = prod(ans, x), e--;
		else x = prod(x, x), e /= 2;
	}
	return ans;
}
 
inline int inv(int x)
{
	return expMod(x, MOD - 2);
}
 
inline int gauss (vector<vector<int>> a, int mod)
{
	MOD = mod;
 
    int n = (int) a.size();
    int m = (int) a[0].size();
 
    vector<int> where (m, -1);
    for(int col = 0, row = 0; col < m and row < n; ++col)
    {
        int sel = row;
        for(int i = row; i < n; ++i)
            if(abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if(a[sel][col] == 0)
            continue;
        for(int i = col; i < m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
        for(int i = row + 1; i < n; ++i)
		{
            int c = prod(a[i][col], inv(a[row][col]));
            for(int j = col; j < m; ++j)
        		a[i][j] = sub(a[i][j], prod(a[row][j], c));
        }
        ++row;
    }
	int ans = 0;
    for(int i = 0; i < m; ++i)
        if(where[i] != -1)
           	ans++;
    return n - ans;
}
 
int32_t main()
{
	int n, m, a, k, t, caso = 1;
 
	cin >> t;
	while(t--)
	{
		scanf(" %d %d %d", &n, &m, &k);
		vector<vector<int>> A(n, vector<int>(n));	
		while(m--)
		{
			int u, v;
			scanf(" %d %d", &u, &v), u--; v--;
			A[u][v] = A[v][u] = 1;
			if(u != v) A[u][v] = A[v][u] = k - 1;
		}
		for(int i = 0; i < n; i++) A[i][i] = 1;
		int ans = gauss(A, k);
		MOD = 1000000007LL;
		printf("Case %d: %d\n", caso++, expMod(k, ans));	
	}
 
	return 0;
}
 
