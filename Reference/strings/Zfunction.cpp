#include "bits/stdc++.h"
#define Max(a,  b) (a > b ? a : b)
#define Min(a,  b) (a < b ? a : b)
using namespace std;
const int MAX = 1e5;

vector<int> Z(string &s)
{
	int n = s.size(), x = 0, y = 0;
	vector<int> z(n);
	for(int i = 1; i < n; i++)
	{
		z[i] = Max(0, Min(z[i - x], y - i + 1));
		while(i + z[i] < n and s[z[i]] == s[i + z[i]])
			x = i, y = i + z[i], z[i]++;
	}
	return z;
}
 
int main()
{
	string txt, pattern;
	
	cin >> txt >> pattern;
	string s = pattern + "#" + txt;
	vector<int> z = Z(s);
	for(int &w : z)
		cout << w << ' ';
	cout << '\n';

	return 0;
}
