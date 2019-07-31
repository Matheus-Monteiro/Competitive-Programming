#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lis(vector<int> &v)
{
	vector<int> pilha;
	for(int i = 0; i < v.size(); i++)
	{
		auto it = upper_bound(pilha.begin(), pilha.end(), v[i]);
		if(it == pilha.end()) pilha.push_back(v[i]);
		else *it = v[i];
	}
	return pilha.size();
}

int main()
{
	string s;
	vector<int> v;
	
	cin >> s;
	for(const char &p : s)
		v.push_back(p-'A');
	printf("%d\n", lis(v));

	return 0;
}