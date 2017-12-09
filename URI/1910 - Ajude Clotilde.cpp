// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Ajude Clotilde
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1910

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int M = 1e5;

int o, dd, k;
set<int> s;
queue<ii> q;

int solve()
{
	q.push({0, o});
	while(!q.empty())
	{
		int d = q.front().first+1, w = q.front().second;
		q.pop();
		if(s.find(w) == s.end())
		{
			if(w > 1)
			{
				q.push({d, w-1});
				if(w-1 == dd)
					return d;
			}
			if(w < M)
			{
				q.push({d, w+1});
				if(w+1 == dd)
					return d;
			}
			if(!(w & 1))
			{
				q.push({d, w/2});
				if(w/2 == dd)
					return d;
			}
			if(2*w <= M)
			{
				q.push({d, 2*w});
				if(2*w == dd)
					return d;
			}
			if(3*w <= M)
			{
				q.push({d, 3*w});
				if(3*w == dd)
					return d;
			}
			s.insert(w);
		}
	}
	return -1;
}

int main()
{
	while(cin >> o >> dd >> k and (o+dd+k))
	{
		for(int i = 0; i < k; i++)
		{	
			int c;
			cin >> c;
			s.insert(c);
		}
		cout << solve() << '\n';
		s.clear();
		while(!q.empty())
			q.pop();
	}
	
	return 0;
}
