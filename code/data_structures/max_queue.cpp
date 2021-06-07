#include <bits/stdc++.h>
using namespace std;

struct MaxQueue 
{
	int plus = 0;
	deque<pair<int, int>> dq;

	bool empty() 
	{ 
		return (int)dq.size() == 0; 
	}
	
	void clear() 
	{ 
		plus = 0; 
		dq.clear(); 
	}
	
	void add(int x) 
	{ // somar x em cada elemento da fila
		plus += x; 
	} 
	int max() 
	{ 
		return dq.begin()->first + plus;  
	} 

	void push(int x) 
	{
		x -= plus;
		int amt = 0;
		while (dq.size() and dq.back().first <= x)
			amt += dq.back().second + 1, dq.pop_back();
		dq.push_back({ x, amt });
	}

	void pop() 
	{
		if (dq.empty()) return;
		if (!dq.front().second) dq.pop_front();
		else dq.front().second--;
	}
};

int main()
{
	int n, aux;
	MaxQueue Q;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int aux;
		cin >> aux;
		Q.push(aux);
		cout << "max " << Q.max() << '\n';
	}
	return 0;
}
