#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, vet[1000000];

ll histogram()
{
	stack<ll> s;
	ll ans = 0, tp, cur;
	int i = 0;
	while(i < n or !s.empty())
	{
		if(i < n and (s.empty() or vet[s.top()] <= vet[i]))
			s.push(i++);
		else
		{
			tp = s.top();
			s.pop();
			cur = vet[tp] * (s.empty() ? i : i - s.top() - 1);
			if(ans < cur)
				ans = cur;
		}
	}
	return ans;
}

int main()
{
	while(cin >> n and n)
	{
		for(int i = 0; i < n; i++)	
			cin >> vet[i];
		cout << histogram() << '\n';
	}
    return 0;
}
