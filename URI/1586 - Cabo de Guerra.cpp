// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Cabo de Guerra
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1586

#include <bits/stdc++.h>
using namespace std;

uint64_t n;
vector<string> v;
int mp[100005];

uint64_t sum(string s)
{
	uint64_t ans = 0;
	for(int i = 0; i < s.size(); i++)
		if(!isspace(s[i]))
			ans += s[i];
		else
			i = s.size();
	return ans;
}

pair<uint64_t, uint64_t> force(int m)
{
	uint64_t ans1 = 0;
	for(int i = m, j = 1; i > 0; i--, j++)
		ans1 += mp[i]*j;
	uint64_t ans2 = 0;
	for(int i = m+1, j = 1; i < v.size(); i++, j++)
		ans2 += mp[i]*j;
	return {ans1, ans2};
}

string buscab()
{
	int b = 1, e = n, m;
	while(b <= e)
	{
		m = (b+e)/2;
		pair<uint64_t, uint64_t> ans = force(m);
		if(ans.first == ans.second)
			return v[m];
		if(ans.first > ans.second)
			e = m - 1;
		else
			b = m + 1;
	}
	return "Impossibilidade de empate.";
}

int main()
{
	while(cin >> n and n)
	{
		string str;
		cin.ignore();
		v.push_back("desgraça");
		for(int i = 1; i <= n; i++)
		{
			getline(cin, str);
			mp[i] = sum(str);
			v.push_back(str);
		}
		cout << buscab() << '\n'; 
		v.clear();
	}
	
	return 0;
}
