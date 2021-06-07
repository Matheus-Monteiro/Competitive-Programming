#include <bits/stdc++.h>
using namespace std;

string a, b;
int PD[2008][2008];

int solve(int i, int j)
{
	if(!i) return j;
	if(!j) return i;
	if(PD[i][j] != -1)
		return PD[i][j];
	// substituir um caracter se for preciso
	int ans1 = solve(i - 1, j - 1) + (a[i] != b[j]);
	//apagar o caracter da string i
	int ans2 = solve(i - 1, j) + 1;
	//apagar o caracter da string j
	int ans3 = solve(i, j - 1) + 1;
	return PD[i][j] = min(ans1, min(ans2, ans3));
}

int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		memset(PD, -1, sizeof(PD));
		cin >> a >> b;
		a = "#" + a;
		b = "#" + b;
		cout << solve(a.size()-1, b.size()-1) << '\n';
	}

	return 0;
}
