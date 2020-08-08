#include <bits/stdc++.h>
using namespace std;
 
typedef vector<long long> vll;
 
vll karatsubaMultiply(const vll &a, const vll &b) {
	int n = a.size();
	vll res(n + n);
	if (n <= 32) {
    	for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
	    		res[i + j] += a[i] * b[j];
    	return res;
	}
 
	int k = n >> 1;
	vll a1(a.begin(), a.begin() + k);
	vll a2(a.begin() + k, a.end());
	vll b1(b.begin(), b.begin() + k);
	vll b2(b.begin() + k, b.end());
 
	vll a1b1 = karatsubaMultiply(a1, b1);
	vll a2b2 = karatsubaMultiply(a2, b2);
 
	for(int i = 0; i < k; i++)
    	a2[i] += a1[i];
	for(int i = 0; i < k; i++)
    	b2[i] += b1[i];
 
	vll r = karatsubaMultiply(a2, b2);
 
	for(int i = 0; i < (int) a1b1.size(); i++)
    	r[i] -= a1b1[i];
	for(int i = 0; i < (int) a2b2.size(); i++)
    	r[i] -= a2b2[i];
 
	for(int i = 0; i < (int) r.size(); i++)
    	res[i + k] += r[i];
	for(int i = 0; i < (int) a1b1.size(); i++)
    	res[i] += a1b1[i];
	for(int i = 0; i < (int) a2b2.size(); i++)
    	res[i + n] += a2b2[i];
	return res;
}
 
int main()
{
	vll a = {8, 7, 5};
	vll b = {12};
 
	vll c = karatsubaMultiply(a, b);
 
	for(auto it : c) cout << it << ' '; puts("");
 
	return 0;
}
 
