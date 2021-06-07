#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
const int MAX = 30 * N;
// MAX = N * log(maxX - minX)
// Queries in O(log(maxX - minX))

struct WaveletTree
{
	int arr[N], aux[N];
	int lo[MAX], hi[MAX];
	vector<int> freq[MAX];
	int lef[MAX], rig[MAX];
	int nextNode;
 	
	WaveletTree(vector<int> a, int minX, int maxX)
 	{
 		int sz = a.size();
 		for(int i = 0; i < sz; i++)
 			arr[i] = a[i];
		nextNode = 1;
		build(0, 0, sz, minX, maxX);
 	}
 	
 	int stable_partition(int s, int e, int mid)
 	{
 		int pivot = 0;
 		for(int i = s; i < e; i++)
 			aux[i] = arr[i], pivot += (arr[i] <= mid);
		int l = s, r = s + pivot;
		for(int i = s; i < e; i++)
			if(aux[i] <= mid)
				arr[l++] = aux[i];
			else
				arr[r++] = aux[i];
 		return l;
 	}
 	
 	void build(int node, int s, int e, int minX, int maxX)
 	{
 		lo[node] = minX, hi[node] = maxX;
 		if(lo[node] == hi[node] or s >= e) return;
 		
 		int mid = (minX + maxX - 1) / 2;
 		
 		freq[node].resize(e - s + 1);
 		freq[node][0] = 0;
 		
 		for(int i = s; i < e; i++)
 			freq[node][i - s + 1] = freq[node][i - s] + (arr[i] <= mid);
 			
		int pivot = stable_partition(s, e, mid);
		
		lef[node] = nextNode++, rig[node] = nextNode++;
		
		build(lef[node], s, pivot, minX, mid);
		build(rig[node], pivot, e, mid + 1, maxX);
 	}

	int went_right(int node, int i)
	{
		return i - freq[node][i];
	}	
	
	// less than ou equal to x in range [l, r]
	int lte(int l, int r, int x, int node = 0)
	{
		if(l > r or x < lo[node]) return 0;
		if(hi[node] <= x) return r - l + 1;
 
		int l1 = freq[node][l - 1] + 1, r1 = freq[node][r];
		int l2 = went_right(node, l - 1) + 1, r2 = went_right(node, r);
 
		return lte(l1, r1, x, lef[node]) + lte(l2, r2, x, rig[node]);		
	}
 
	// greater than ou equal to x in range [l, r]
	int gte(int l, int r, int x, int node = 0)
	{
		if(l > r or x > hi[node]) return 0;
		if(lo[node] >= x) return r - l + 1;
 
		int l1 = freq[node][l - 1] + 1, r1 = freq[node][r];
		int l2 = went_right(node, l - 1) + 1, r2 = went_right(node, r);
 
		return gte(l1, r1, x, lef[node]) + gte(l2, r2, x, rig[node]);		
	}
	
	// counting numbers equal to x in range [l, r]
	int count(int l, int r, int x, int node = 0)
	{	
		if(l > r or lo[node] > x or hi[node] < x) return 0;
 
		if(lo[node] == hi[node] and lo[node] == x) return r - l + 1;
 
		int l1 = freq[node][l - 1] + 1, r1 = freq[node][r];
		int l2 = went_right(node, l - 1) + 1, r2 = went_right(node, r);
 
		return count(l1, r1, x, lef[node]) + count(l2, r2, x, rig[node]);
	}
	
	// find kth number in range [l, r]
 	int kth(int l, int r, int k, int node = 0)
 	{
 		if(l > r) return 0;
 		if(lo[node] == hi[node]) return lo[node];
		
		int inLeft = freq[node][r] - freq[node][l - 1];
		int l1 = freq[node][l - 1] + 1, r1 = freq[node][r];
 		
 		if(k <= inLeft) return kth(l1, r1, k, lef[node]);
		
		int l2 = went_right(node, l - 1) + 1, r2 = went_right(node, r);
		
		return kth(l2, r2, k - inLeft, rig[node]);
 	}
};

int main()
{
	vector<int> a = {2, 5, 3, 2, 4, 2};
 
	WaveletTree T(a, 0, 9);
 
	cout << T.lte(3, 5, 3) << '\n';
	cout << T.gte(3, 5, 3) << '\n';
	cout << T.count(1, 6, 2) << '\n';
	cout << T.kth(1, 6, 5) << '\n';
 
	return 0;
}
