#include <bits/stdc++.h>
using namespace std;

#define maxn 20005
#define maxnlog 22
const long long OO = 0x3f3f3f3f3f3f3f3f;

struct SparseTableDS
{
	int Sparse_Table[maxnlog][maxn];
	bool maxi;
	int n;

	void build()
	{
		for(int i = 1; (1 << i) <= n; i++)
			for(int j = 0; j + (1 << i) <= n; j++)
			{
				if(maxi)
					Sparse_Table[i][j] =  max(Sparse_Table[i-1][j], 
						Sparse_Table[i-1][j+(1 << (i-1))]);
				else
					Sparse_Table[i][j] =  min(Sparse_Table[i-1][j], 
							Sparse_Table[i-1][j+(1 << (i-1))]);
			}
	}

	int query(int i, int j)
	{
		int sz = log2(j-i+1);
		if(maxi)
			return max(Sparse_Table[sz][i],Sparse_Table[sz][j+1-(1 << sz)]);
		return min(Sparse_Table[sz][i],Sparse_Table[sz][j+1-(1 << sz)]);
	}
	
	
 	void init(bool fl, vector<int> &arr)
	{
		maxi = fl;
		if(!maxi) memset(Sparse_Table, 63, sizeof(Sparse_Table));
		n = arr.size();
		for(int i = 0; i < n; i++)
			Sparse_Table[0][i] = arr[i];
		build();
	}
};

int n, k;
SparseTableDS maxi, mini;

long long dp_before[maxn];
long long dp_cur[maxn];

int get(int l, int r)
{
	int a = maxi.query(l, r);
	int b = mini.query(l, r);
	return abs(a - b);
}

void compute(int l, int r, int optl, int optr)
{
	if(l > r) return;
	
	int mid = (l + r) >> 1;
	int best = 0;
	int opt = optl;

	for(int k = optl; k < min(mid, optr + 1); k++)
		if(best < dp_before[k] + get(k + 1, mid))
		{
			best = dp_before[k] + get(k + 1, mid);
			opt = k;
		}
	dp_cur[mid] = best;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int32_t main()
{
	cin >> n >> k;
	vector<int> arr(n);
	for(int &w : arr) scanf(" %d", &w);
	
	maxi.init(true, arr);
	mini.init(false, arr);
	
	for(int i = 0; i < n; i++)
		dp_cur[i] = get(0, i);
		
	for(int i = 2; i <= k; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dp_before[j] = dp_cur[j];
			dp_cur[j] = 0;
		}
		compute(i - 2, n - 1, i - 2, n - 1);
	
	}

	cout << dp_cur[n - 1] << endl;

	return 0;
}
