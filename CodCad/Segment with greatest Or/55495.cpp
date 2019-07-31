#include <bits/stdc++.h>
using namespace std;

int A[100005], ST[1000000];

void build(int node, int start, int end)
{
	if(start == end)
		ST[node] = A[start];
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		ST[node] = max(max(ST[2*node], ST[2*node+1]), (ST[2*node] | ST[2*node+1]));
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", A+i);
	build(1, 0, n-1);
	printf("%d\n", ST[1]);	
		
	return 0;
}