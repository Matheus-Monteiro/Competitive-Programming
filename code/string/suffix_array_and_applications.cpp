#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> sa, c, lcp;

// O(n)
void countSort()
{
	int n = sa.size();
	vector<int> buc(n), new_sa(n);
	for(int &w : sa)
		buc[c[w]]++;
	for(int i = 1; i < n; i++)	
		buc[i] += buc[i - 1];
	for(int i = n - 1; i >= 0; i--)
		new_sa[ --buc[ c[sa[i]] ] ] = sa[i];
	sa = new_sa;
}

// O(|s| * log|s|)
void buildSuffixArray()
{
	int n = s.size();
	sa.resize(n);
	c.resize(n);
	for(int i = 0; i < n; i++)
		sa[i] = i, c[i] = s[i];
	sort(sa.begin(), sa.end(), [&](int a, int b)
		{
			return c[a] < c[b];
		});
	c[sa[0]] = 0;
	for(int i = 1; i < n; i++)
		if(s[sa[i - 1]] == s[sa[i]])			
			c[sa[i]] = c[sa[i - 1]];
		else
			c[sa[i]] = c[sa[i - 1]] + 1;
	int k = 0;
	while((1 << k) < n)
	{
		for(int i = 0; i < n; i++)
			sa[i] = (sa[i] - (1 << k) + n) % n;
		countSort();
		vector<int> new_c(n);
		new_c[sa[0]] = 0;		
		for(int i = 1; i < n; i++)
		{
			pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + (1 << k)) % n]};	
			pair<int, int> cur = {c[sa[i]], c[(sa[i] + (1 << k)) % n]};	
			if(prev == cur) new_c[sa[i]] = new_c[sa[i - 1]];
			else new_c[sa[i]] = new_c[sa[i - 1]] + 1;
		}	
		c = new_c;	
		k++;	
	}
}

// 0: padrao esta no sufixo
// 1: o padrao eh lexicograficamente maior que o sufixo k
//-1: o padrao eh lexicograficamente menor que o sufixo k
// O(|p|)
int cmp(int k, string &p)
{
	for(int i = 0; i < p.size(); i++)
	{
		if(i + k >= s.size()) return 1;
		if(s[i + k] < p[i]) return 1;
		if(s[i + k] > p[i]) return -1;
	}
	return 0;
}

// posicao no suffix array do sufixo mais
// a esquerda que contem p como prefixo
// O(|p| * log|s|)
int lower_bound(string &p)
{
	int b = 0, e = (int)sa.size() - 1, ans = 0;
	while(b <= e)
	{
		int mid = (b + e) / 2;
		int r = cmp(sa[mid], p);
		if(!r)
			e = mid - 1, ans = mid;
		else if(r == -1)
			e = mid - 1;
		else
			b = mid + 1;
	}
	if(s.substr(sa[ans], p.size()) != p)
		return -1;
	return ans;
}

// posicao no suffix array do sufixo mais
// a direita que contem p como prefixo
// O(|p| * log|s|)
int upper_bound(string &p)
{
	int b = 0, e = (int)sa.size() - 1, ans = 0;
	while(b <= e)
	{
		int mid = (b + e) / 2;
		int r = cmp(sa[mid], p);
		if(!r)
			b = mid + 1, ans = mid;
		else if(r == -1)
			e = mid - 1;
		else
			b = mid + 1;
	}
	if(s.substr(sa[ans], p.size()) != p)
		return -1;
	return ans;
}

// numero de ocorrencias da string p
// como substring de s
// O(|p| * log|s|)
int count(string &p)
{
	int l = lower_bound(p);
	int u = upper_bound(p);
	if(l == -1 or u == -1)
		return 0;
	return u - l + 1;
}

// construcao do array lcp
// lcp[i] eh o maior prefixo comum
// aos sufixos i e i - 1 do suffix array
// O(n)
void buildLcp()
{
	int n = s.size();
	lcp.resize(n);
	int k = 0;
	for(int i = 0; i < n - 1; i++)
	{
	// pi eh a posicao no suffix array do  
	// sufixo que comeca na posicao i da strig
		int pi = c[i]; 
		int j = sa[pi - 1];
		while(s[i + k] == s[j + k]) k++;
		lcp[pi] = k;
		k = max(k - 1, 0);
	}
}

// conta a quantidade de substrings 
// diferentes na string s
// O(|s|)
long long numberOfDifSubStr()
{
	long long n = s.size();
	long long ans = n * (n - 1) / 2;
	for(int i = 0; i < n; i++)
		ans -= lcp[i];
	return ans;
}

// encontra a maior substring comum a s e p
// O(|s + p|) depois de construir suffix array
void longestCommonSubstring(string p)
{
	int n = s.size();
	int m = p.size();
	int ans = -1, j = 1;
	s = s + "$" + p + "#";

	buildSuffixArray();
	buildLcp();
	
	for(int i = 1; i < sa.size(); i++)
	{
		int p = sa[i - 1] < n ? 1 : -1;
		int q = sa[i] < n ? 1 : -1;
	 	if(p * q < 0 and ans < lcp[i])
		 	ans = lcp[i], j = i;
	}
	
	int a = sa[j];
	int b = sa[j - 1];
	string lcs;
	
	while(a < s.size() and b < s.size() and s[a] == s[b])
	{
		lcs.push_back(s[a]);
		a++, b++;
	}
	
	cout << ans << '\n';
	cout << lcs << '\n';
}

int32_t main()
{
	string p;
	cin >> s >> p;

    // o tamanho do maior prefixo comum entre dois
	// sufixos que estao nas posicoes a e b do 
	// suffix array eh igual ao menor valor no 
	// intervalo [a+1, b] do array lcp
	
	// descomentar as linhas abaixo para todas as
	// funcoes, exceto para longestCommonSubstring

	// s.push_back('$');
	// buildSuffixArray();
	// buildLcp();
	
	longestCommonSubstring(p);

	return 0;
}
