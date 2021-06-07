#include <bits/stdc++.h>
#define maxn 100000
#define maxnlog 20

using namespace std;

const double EPS = 1e-6;

int n, q, Sparse_Table[maxnlog][maxn];

void build()
{
	for(int i = 1; (1 << i) <= n; i++)
		for(int j = 0; j + (1 << i) <= n; j++)
			Sparse_Table[i][j] =  max(Sparse_Table[i-1][j], 
				Sparse_Table[i-1][j+(1 << (i-1))]);
}

int range_query(int i, int j)
{
	int sz = log2(j-i+1);
	return max(Sparse_Table[sz][i],Sparse_Table[sz][j+1-(1 << sz)]);
}

int main()
{
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &Sparse_Table[0][i]);
	build();
	for(int i = 0; i < q ; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		cout << range_query(a,b) << endl;
	}
	
	return 0;
}
