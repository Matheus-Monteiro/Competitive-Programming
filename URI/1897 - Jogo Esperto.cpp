// Autor: Matheus Monteiro<mmonteiro100@yahoo.com>
// Nome: Jogo Esperto
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1897

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n, m;
queue<ii> q;
set<int> s;

int solve()
{
	q.push({0, n});
	while(true)
	{
		int d = q.front().first+1, w = q.front().second;
		q.pop();
		if(s.find(w) == s.end())
		{
			q.push({d, 2*w});
			q.push({d, 3*w});
			q.push({d, w/2});
			q.push({d, w/3});
			q.push({d, w+7});
			q.push({d, w-7});
			s.insert(w);
			if(2*w == m or 3*w == m or w/2 == m or w/3 == m or w+7 == m or w-7 == m)
				return d; 
		}
	}
}

int main()
{
	cin >> n >> m;
	cout << solve() << '\n';
	
	return 0;
}
