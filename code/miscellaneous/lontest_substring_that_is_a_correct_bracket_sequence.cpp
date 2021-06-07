#include <bits/stdc++.h>
using namespace std;
#define OO 0x3f3f3f3f
#define gc getchar
#define pc putchar
#define offset 1000000

string str;
int Sparse_Table[22][1000002], n;
vector<int> forest[2000002];
int pf[1000002], cnt[1000002];
 
inline void build()
{
	for(int i = 1; (1 << i) < n; i++)
		for(int j = 0; j + (1 << i) < n; j++)
			Sparse_Table[i][j] = min(Sparse_Table[i-1][j], 
				Sparse_Table[i-1][j+(1 << (i-1))]);
}
 
inline int range_query(int i, int j)
{
	int sz = log2(j-i+1);
	return min(Sparse_Table[sz][i],Sparse_Table[sz][j+1-(1 << sz)]);
}

inline int countNumberOfElementEqualToXinLR(int l, int r, int x)
{
	int p1 = lower_bound(forest[x + offset].begin(), forest[x + offset].end(), l) - forest[x + offset].begin();
	int p2 = upper_bound(forest[x + offset].begin(), forest[x + offset].end(), r) - forest[x + offset].begin() - 1;
	if(p1 > p2) return -1;
	return p2 - p1 + 1;
}
 
inline int nxt(int i, int x)
{
	int b = i, e = n - 1, ans = -1;
	while(b <= e)
	{
		int m = (b + e) >> 1;
		int v = range_query(i, m);
		if(v >= x) ans = m, b = m + 1;
		else e = m - 1;
	}
	return ans;
}
 
inline int queryIndex(int l, int r, int x)
{
	int b = l, e = r, ans = -1;
	while(b <= e)
	{
		int m = (b + e) >> 1;
		if(countNumberOfElementEqualToXinLR(m, r, x) > 0) ans = m, b = m + 1;
		else e = m - 1;
	}
	return ans;
}
 
inline void scanstr(string &k)
{
    register char c;
	k = "";
    for(c = gc(); c != '(' and c != ')'; c = gc());
    for(; c >= '(' and c <= ')'; c = gc()) k.push_back(c);
}
 
int main()
{
	scanstr(str);
	n = str.size() + 1;
	for(int i = 1; i < n; i++)
	{
		pf[i] = pf[i - 1] + (str[i - 1] == '(' ? 1 : -1);
		Sparse_Table[0][i] = pf[i];
		forest[pf[i] + offset].push_back(i);
	}
	build();
	int ans = 0;
	cnt[0] = 1;
	for(int i = 1; i < n; i++)
	{
		if(str[i - 1] != '(') continue;
		int e = nxt(i, pf[i] - 1);
		if(e < i) continue;
		int p = queryIndex(i, e, pf[i] - 1);
		if(p < i) continue;
		int l = p - i + 1;
		cnt[l]++;
		if(l > ans) ans = l;
	}
	printf("%d %d\n", ans, cnt[ans]);
 
	return 0;
}
