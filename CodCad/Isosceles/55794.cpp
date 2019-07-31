#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int esq[100000], dir[100000];

int main()
{
	int n;
	scanf("%d", &n);
	v.resize(n);
	for(int &p : v)
		scanf("%d", &p);
	
	esq[0] = 1;
	for(int i = 1; i < n; i++)
		esq[i] = min(esq[i-1]+1, v[i]);
	dir[n-1] = 1;
	for(int i = n-2; i >= 0; i--)
		dir[i] = min(dir[i+1]+1, v[i]);
	
	int ans = INT_MIN;

	for(int i = 0; i < n; i++)
		ans = max(ans, min(esq[i], dir[i]));
	
	printf("%d\n", ans);
	
	return 0;
}