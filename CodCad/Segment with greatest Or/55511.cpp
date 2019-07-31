#include <bits/stdc++.h>
using namespace std;

int A[100005];

int solve(int node, int start, int end)
{
	if(start == end)
		return A[start];
	else
	{
		int mid = (start+end)/2;
		int a = solve(2*node, start, mid);
		int b = solve(2*node+1, mid+1, end);
		return max(max(a, b), a | b);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", A+i);
	printf("%d\n", solve(1, 0, n-1));	
		
	return 0;
}